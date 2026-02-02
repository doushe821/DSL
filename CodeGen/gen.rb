require_relative '../Generic/base'
require 'yaml'
require 'set'
require_relative 'map_tree'
require_relative 'decoder_tree'
require_relative 'jitgen'
require_relative 'gen_regstate'
require_relative 'codegen'

module SimGen
  class UltimateGenerator    
    BinInstr = Struct.new(:name, :bits, :fixed_mask)
    @@bin_instrs = []
    def initialize
      yaml = File.read('IR.yaml')
      @@parsed_full_descr = YAML.safe_load(yaml,
        permitted_classes: [SimInfra::FullDescription, SimInfra::Field, SimInfra::Scope, SimInfra::IrStmt,
        SimInfra::Var, SimInfra::XReg, SimInfra::ImmFieldPart, SimInfra::XImm, 
        Symbol, SimInfra::Scope::Type, SimInfra::Memory, SimInfra::Constant], aliases: true)
      @@parsed_ir = @@parsed_full_descr[:ISA]

      @@parsed_ir.each do |instr|
        binary_value = 0
        fixed_mask = 0
        instr[:fields].each do |field|
          num_bits = field.from - field.to + 1
          mask = (1 << num_bits) - 1
          if field.value.is_a?(Integer)
            masked_value = field.value & mask
            binary_value |= (masked_value << field.to)
          end
          if field.is_a?(SimInfra::Field)
            if field.fixed
              fixed_mask |= (mask << field.to)
            end
          end
        end
        @@bin_instrs.push(BinInstr.new(instr[:name], binary_value, fixed_mask))
      end


      root = DecoderTree::build_tree(@@bin_instrs)

      # debug
      treeFile = File.open('tree.dot', 'w')
      treeFile << DecoderTree::generate_dot(root)
      treeFile.close
      # debug

      SimGen::GenStateGenerator.new(@@parsed_full_descr[:Registers])
      # INterpreter
      generate_general_instruction_description
      emitter = SimInfra::CppEmitter.new
      all_execs = emitter.emit_all_instructions(@@parsed_ir)

      File.open('Sim/src/Executor.cpp', 'w') do |exec|
        exec << <<~CPP
        #include "Executor.hpp"
        namespace GeneralSim {
        using XReg = uint16_t;
        #{all_execs}
        void Executor::execute(const Instruction &Inst, ExecContext &Ctx) {
          std::visit([&](auto&& I) {
            using T = std::decay_t<decltype(I)>;
            #{emitter.emit_instructions_visit(@@parsed_ir)}
            }, Inst);
        }
        } // namespace GeneralSim
      CPP
      end

      # JIT 
      jimitter = SimInfra::CppJitEmitter.new
      all_jit_execs = jimitter.emit_all_instructions(@@parsed_ir)

      File.open('Sim/src/JITExecutor.cpp', 'w') do |exec|
        exec << <<~CPP
        #include "JIT.hpp"
        namespace SimJIT {
        using namespace asmjit;
        using namespace asmjit::x86;
        using XReg = uint16_t;
        #{all_jit_execs}
        void JIT::emitInstruction(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, Instruction Instr) {
          std::visit([&](auto&& I) {
            using T = std::decay_t<decltype(I)>;
            #{jimitter.emit_instructions_visit_JIT(@@parsed_ir)}
            }, Instr);
        }
        } // namespace GeneralSim
      CPP
      end

      # Tests
      # TODO make it toggleable for user (maybe they don't want any tests)
      File.open('Sim/include/ExecutorTestOnly.hpp', 'w') do |execto| 
        execto << <<~CPP
        #pragma once
        #include "ExecContext.hpp"
        namespace TestSim {
        using XReg = uint16_t;
        using ExecContext = GeneralSim::ExecContext;
        #{all_execs}
        } // namespace TestSim
        CPP
      end


      # Decoder
      File.open('Sim/src/Decoder.cpp', 'w') do |decode|
        decode << <<~CPP
        #include <stdexcept>

        #include "GeneralSimTypes.hpp"
        #include "Decoder.hpp"
        #include "Instructions.hpp"
        using XReg = uint16_t;
        namespace Decoder {
        #{emitter.emit_decoder_tree(root, @@parsed_ir)}
        } // namespace Decoder"
        CPP
      end

      File.open('Sim/include/Executor.hpp', 'w') do |exec_header|
        exec_header << <<~CPP
        #pragma once
        #include "ExecContext.hpp"
        #include "Instructions.hpp"
        
        namespace GeneralSim {
        class Executor {
        public:
          void execute(const Instruction &Inst, ExecContext &Ctx);
        };
        } // namespace GeneralSim
        CPP
      end
    end

    def cpp_type_for(field)
      case field.value
      when :reg
        "XReg"
      else
        raise "Malformed yaml probably"
      end
    end

    def generate_general_instruction_description # TODO namespace for descriptions
      structs = []
      variant_types = []

      opcode_infos = "inline constexpr OpcodeInfo OpcodeTable[] = {\n"

      @@parsed_ir.each do |instr|
        name   = instr[:name]
        fields = instr[:fields]
        opcode_infos = opcode_infos + "    {#{ instr[:control_flow] ? true : false }, 4 },\n"
        regs = fields.select { |f| f[:value] == :reg }

        variant_types << name

        body = regs.map do |f|
          "  #{cpp_type_for(f)} #{f.name};"
        end.join("\n")

        imm = fields.select { |f| f[:value] == :imm }
        imm_parts = fields.select { |f| f.is_a?(SimInfra::ImmFieldPart)}

        if !imm.empty? || !imm_parts.empty?
          body = body + "\n  GeneralSim::Immediate imm;\n"
        end
        body = body + "\n  static constexpr Opcode OP = Opcode::#{name};\n"
        structs << <<~CPP
          struct #{name} {
          #{body}
          };
        CPP
      end

      opcode_infos = opcode_infos + "};\n"
      output = <<~CPP
        #pragma once

        #include <variant>
        #include "GeneralSimTypes.hpp"
        using XReg = uint16_t;
        enum class Opcode : uint16_t {
          #{variant_types.join(",\n    ")}
        };

        #{structs.join("\n")}

        using Instruction = std::variant<
            #{variant_types.join(",\n    ")}
        >;
        struct OpcodeInfo {
          bool IsTerminator;
          uint8_t Size;
        };
        #{opcode_infos}
        static inline bool isTerminator(Opcode Op) {
            return OpcodeTable[static_cast<std::size_t>(Op)].IsTerminator;
        }

        static inline uint8_t instSize(Opcode Op) {
            return OpcodeTable[static_cast<std::size_t>(Op)].Size;
        }

        static inline Opcode getOpcode(const Instruction& Inst) {
            return std::visit([](auto&& I) {
                return std::decay_t<decltype(I)>::OP;
            }, Inst);
        }
      CPP
      

      File.write("Sim/include/Instructions.hpp", output)
    end
  end
end

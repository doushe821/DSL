require_relative '../Generic/base'
require 'yaml'
require 'set'
require_relative 'map_tree'
require_relative 'decoder_tree'
require_relative 'gen_regstate'
require_relative 'codegen'

module SimGen
  class UltimateGenerator    
    BinInstr = Struct.new(:name, :bits)
    @@bin_instrs = []
    def initialize
      yaml = File.read('IR.yaml')
      @@parsed_ir = YAML.safe_load(yaml,
        permitted_classes: [SimInfra::Field, SimInfra::Scope, SimInfra::IrStmt,
        SimInfra::Var, SimInfra::XReg, SimInfra::ImmFieldPart, SimInfra::XImm, 
        Symbol, SimInfra::Scope::Type, SimInfra::Memory, SimInfra::Constant], aliases: true)

      @@parsed_ir.each do |instr|
        binary_value = 0
        instr[:fields].each do |field|
          if field.value.is_a?(Integer)
            num_bits = field.from - field.to + 1
            mask = (1 << num_bits) - 1
            masked_value = field.value & mask
            binary_value |= (masked_value << field.to)
          end
        end
        @@bin_instrs.push(BinInstr.new(instr[:name], binary_value))
      end


      root = DecoderTree::build_tree(@@bin_instrs)

      # debug
      treeFile = File.open('tree.dot', 'w')
      treeFile << DecoderTree::generate_dot(root)
      treeFile.close
      # debug

      SimGen::GenStateGenerator.new

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

      File.open('Sim/src/Decoder.cpp', 'w') do |decode|
        decode << <<~CPP
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

      @@parsed_ir.each do |instr|
        name   = instr[:name]
        fields = instr[:fields]

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
        structs << <<~CPP
          struct #{name} {
          #{body}
          };
        CPP
      end

      output = <<~CPP
        #pragma once

        #include <variant>
        #include "GeneralSimTypes.hpp"
        using XReg = uint16_t;
        #{structs.join("\n")}

        using Instruction = std::variant<
            #{variant_types.join(",\n    ")}
        >;
      CPP

      File.write("Sim/include/Instructions.hpp", output)
    end
  end
end

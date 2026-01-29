# TODO: connect to other codegen modules
module SimGen
  class GenStateGenerator
    def initialize
      
      require 'yaml'
      
      regs = YAML.load_file("Regfile.yaml")
      
      names = regs.map { |r| r[:name] }
      raise "Duplicate register names!" if names.uniq.size != names.size

      regs.each_with_index do |reg, idx|
        reg[:index] = idx
      end

      const_regs = regs.map { |r| !r[:hv].nil? }
      const_vals = regs.map { |r| r[:hv] || 0 }

      header = <<~CPP
      #pragma once
      #include <cstdint>
      #include <cstddef>
      #include <array>
      #include <cassert>
      namespace GeneralSim {
      class RegState {
      public:
          using reg_t = uint32_t; // TODO Expand
          static constexpr size_t NUM_REGS = #{regs.size};

          RegState();
          
          reg_t read(unsigned Idx) const;
          void write(unsigned Idx, reg_t Value);

      private:
          alignas(32) reg_t Regs[NUM_REGS];

          // constant registers
          static constexpr bool IsConst[NUM_REGS] = {
      CPP

      const_regs.each { |c| header += "        #{c},\n" }

      header += <<~CPP
          };

          static constexpr reg_t const_value[NUM_REGS] = {
      CPP
      const_vals.each { |v| header += "        #{v},\n" }
      header += <<~CPP
          };
      };
      } // namespace GeneralSim
      CPP

      File.write("Sim/include/RegState.hpp", header)
      puts "Generated RegState.hpp"

      source = <<~CPP
      #include "RegState.hpp"
      namespace GeneralSim {
      RegState::RegState() {
      CPP

      regs.each do |r|
        init = r[:hv] || 0
        source += "    Regs[#{r[:index]}] = #{init};\n"
      end

      source += <<~CPP
      }

      RegState::reg_t RegState::read(unsigned Idx) const {
          assert(Idx < NUM_REGS);
          return Regs[Idx];
      }

      void RegState::write(unsigned Idx, reg_t Value) {
          assert(Idx < NUM_REGS);
          if (!IsConst[Idx]) {
              Regs[Idx] = Value;
          }
      }
      } // namespace GeneralSim
      CPP

      File.write("Sim/src/RegState.cpp", source)
      puts "Generated RegState.cpp"

      # Aliases
      enum_text = "enum eRegAliases : unsigned {\n"
      regs.each do |r|
        enum_text += "    #{r[:name]} = #{r[:index]},\n"
        r[:aliases].each { |a| enum_text += "    #{a} = #{r[:index]},\n" }
      end
      enum_text += "};\n"

      reg_aliases_file = <<~CPP
      #pragma once
      namespace RegAliases {
      #{enum_text}
    } // namespace RegAliases
      CPP
      File.write("Sim/include/RegAliases.hpp", reg_aliases_file)
      puts "Generated RegAliases.hpp"

    end
  end
end

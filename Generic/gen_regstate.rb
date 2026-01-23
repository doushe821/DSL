module SimInfra
  # AI generated(mostly)
  class RegStateGenerator
    INPUT_FILE = "ArchDesc.txt"

    PERM_USER = 0x1
    PERM_SYS  = 0x2

    def initialize(input_file = INPUT_FILE)
      @input_file = input_file
      @registers = []
      @reg_by_index = {}
      @reg_by_name = {}
    end

    def generate
      read_description
      emit_header
    end

    private

    def read_description
      lines = File.readlines(@input_file, chomp: true)
      raise "Empty #{@input_file}" if lines.empty?

      @arch_name = lines.shift.strip
      raise "Invalid architecture name" if @arch_name.empty?

      lines.each_with_index do |line, i|
        next if line.strip.empty?

        name, idx_str, perm = line.split
        raise "Invalid line format at #{i + 2}" unless name && idx_str && perm

        idx = Integer(idx_str)
        raise "Permission must be 'u' or 's' at line #{i + 2}" unless %w[u s].include?(perm)

        raise "Register index #{idx} defined multiple times" if @reg_by_index.key?(idx)
        raise "Register name #{name} defined multiple times" if @reg_by_name.key?(name)

        perm_mask =
          case perm
          when 'u' then PERM_USER
          when 's' then PERM_SYS
          end

        reg = {
          name: name,
          index: idx,
          perm: perm_mask
        }

        @registers << reg
        @reg_by_index[idx] = reg
        @reg_by_name[name] = reg
      end

      @registers.sort_by! { |r| r[:index] }
      @array_size = @registers.last[:index] + 1
    end

    def emit_header
      hpp_name = "#{@arch_name}RegState.hpp"

      File.open(hpp_name, "w") do |f|
        f.puts header_preamble
        f.puts register_init_list
        f.puts header_footer
      end

      puts "Generated #{hpp_name}"
    end

    def header_preamble
      <<~HDR
        #pragma once

        #include <array>
        #include <cassert>
        #include <cstdint>
        #include <stdexcept>

        #include "GeneralSim.hpp"

        namespace #{@arch_name}RegState {

        class #{@arch_name}RegState final : public GeneralSim::RegState {
        public:
          using XReg = uint16_t;

          static constexpr uint8_t PERM_USER = 1 << 0; // Expandable
          static constexpr uint8_t PERM_SYS  = 1 << 1;

          struct Register {
            uint64_t Value;
            uint8_t  Perm;
          };

          constexpr #{@arch_name}RegState() : Regs{{
      HDR
    end

    def register_init_list
      lines = Array.new(@array_size) { "{0, 0}" }

      @registers.each do |r|
        lines[r[:index]] = "{0, #{format_perm(r[:perm])}}"
      end

      lines.map { |l| "          #{l}," }.join("\n") + "\n"
    end

    def format_perm(mask)
      parts = []
      parts << "PERM_USER" if (mask & PERM_USER) != 0
      parts << "PERM_SYS"  if (mask & PERM_SYS)  != 0
      parts.join(" | ")
    end

    def header_footer
      <<~FTR
          }} {};

          virtual uint64_t getReg(XReg r) override {
            assert(r < #{@array_size});
            const Register& Reg = Regs[r];
            if (!(Reg.Perm & PERM_USER)) {
              assert(false && "Access to system register from user");
              // throw std::runtime_error("Register access violation");
            }
            return Reg.Value;
          }

          virtual void setReg(XReg r, uint64_t v) override {
            assert(r < #{@array_size});
            Register& Reg = Regs[r];
            if (!(Reg.Perm & PERM_USER)) {
              assert(false && "Write to system register from user");
              // throw std::runtime_error("Register access violation");
            }
            Reg.Value = v;
          }

          virtual uint64_t getRegSystem(XReg r) override {
            assert(r < #{@array_size});
            return Regs[r].Value;
          }

          virtual void setRegSystem(XReg r, uint64_t v) override {
            assert(r < #{@array_size});
            Regs[r].Value = v;
          }


        private:
          std::array<Register, #{@array_size}> Regs;
        };

        } // namespace #{@arch_name}RegState
      FTR
    end
  end



end
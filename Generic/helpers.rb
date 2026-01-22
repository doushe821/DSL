module SimInfra
  # AI generated
  class IRPrettyPrinter
    def initialize(instructions)
      @instructions = instructions
    end

    def run
      @instructions.each do |insn|
        print_instruction(insn)
        puts
      end
    end

    private

    def print_instruction(insn)
      name = insn[:name]
      args = insn[:args]

      puts "instruction #{name} (#{args.map(&:name).join(', ')})"

      scope = insn[:code]
      indent = "  "

      # Variable declarations
      scope.tree.each do |stmt|
        next unless stmt.name == :new_var
        v = stmt.oprnds.first
        puts "#{indent}#{v.name}:#{v.type}"
      end

      puts

      # Statements
      scope.tree.each do |stmt|
        case stmt.name
        when :new_var
          next

        when :getreg
          var_name, reg = stmt.oprnds
          puts "#{indent}#{var_name} = getreg #{reg.name}"

        when :setreg
          reg, _ = stmt.oprnds
          puts "#{indent}setreg #{reg.name}"

        when :let
          dst, src = stmt.oprnds
          puts "#{indent}#{dst.name} = #{src.name}"

        when :+
          dst, a, b = stmt.oprnds
          puts "#{indent}#{fmt(dst)} = add #{a.name}, #{b.name}"

        when :as_signed, :as_unsigned, :bitrev
          dst, src = stmt.oprnds
          puts "#{indent}#{fmt(dst)} = #{stmt.name} #{src.name}"

        when :sext, :zext
          dst, src = stmt.oprnds
          from = stmt.attrs[:from]
          to   = stmt.attrs[:to]
          puts "#{indent}#{fmt(dst)} = #{stmt.name} #{src.name} (#{from} → #{to})"

        else
          dst, *ops = stmt.oprnds
          puts "#{indent}#{fmt(dst)} = #{stmt.name} #{ops.map(&:name).join(', ')}"
        end
      end
    end

    def fmt(var)
      "#{var.name}:#{var.type}"
    end
  end
end

module SimInfra
  # AI generated
  class IRPrettyPrinter
    def initialize(instructions)
      @instructions = instructions
    end

    def run
      @instructions.each do |insn|
        dump_instruction(insn)
        puts
      end
    end

    private

    def dump_instruction(insn)
      puts "instruction #{insn[:name]} (#{insn[:args].map(&:name).join(', ')})"

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
        dump_stmt(stmt, indent)
      end
    end

    def dump_stmt(stmt, indent)
      op   = stmt.name
      ops  = stmt.oprnds
      attrs = stmt.attrs

      case op
      when :new_var
        return

      when :getreg
        var_sym, reg = ops
        puts "#{indent}#{var_sym} = getreg #{reg.name}"

      when :setreg
        reg, _ = ops
        puts "#{indent}setreg #{reg.name}"

      when :let
        dst, src = ops
        puts "#{indent}#{dst.name} = #{operand(src)}"

      when :load
        dst, addr = ops
        puts "#{indent}#{dst.name} = M[#{operand(addr)}]"

      when :store
        addr, value = ops
        puts "#{indent}M[#{operand(addr)}] = #{operand(value)}"

      else
        dump_generic_op(op, ops, attrs, indent)
      end
    end

    # generic fallback for all other operations (:+, :-, :sll, etc)
    def dump_generic_op(op, ops, attrs, indent)
      dst, *args = ops

      if dst.is_a?(Var)
        rhs = args.map { |a| operand(a) }.join(", ")
        extra = format_attrs(attrs)
        puts "#{indent}#{fmt(dst)} = #{op} #{rhs}#{extra}"
      else
        # side-effect op
        rhs = ops.map { |a| operand(a) }.join(", ")
        puts "#{indent}#{op} #{rhs}"
      end
    end

    def operand(o)
      case o
      when Var
        o.name.to_s
      when Constant
        o.value.to_s
      when Symbol
        o.to_s
      else
        o.respond_to?(:name) ? o.name.to_s : o.to_s
      end
    end

    def format_attrs(attrs)
      return "" unless attrs && !attrs.empty?
      " " + attrs.map { |k, v| "#{k}=#{v}" }.join(", ")
    end

    def fmt(var)
      "#{var.name}:#{var.type}"
    end
  end
end

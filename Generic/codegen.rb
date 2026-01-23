module SimInfra
  
  class CppEmitter
    def initialize
      @out = []
      @declared = {}
    end

    def emit(line = "")
      @out << line
    end

    def result
      @out.join("\n")
    end

    def ssa(var)
      raise "Expected Var" unless var.is_a?(SimInfra::Var)
      "v_#{var.name}"
    end

    def declare_ssa(var)
      name = ssa(var)
      raise "Double declaration: #{name.inspect}" if @declared[name]
      emit "uint64_t #{name} = 0;"
      @declared[name] = true
    end

    def operand(op)
      case op
      when SimInfra::Var
        ssa(op)
      when SimInfra::Constant
        op.value.to_s
      when SimInfra::XReg
        op.name.to_s
      when SimInfra::XImm
        op.name.to_s
      when Symbol
        op.to_s
      else
        raise "Unknown operand type: #{op.inspect}"
      end
    end

    def emit_exec_function(instr)
      decl = emit_exec_decl(instr)
      body = emit_instruction(instr)

      <<~CPP
      #{decl}
      #{body}
      CPP
    end

    def emit_instruction(instr)
      emitter = CppEmitter.new
      scope   = instr[:code]

      emitter.emit "// Instruction #{instr[:name]}"
      emitter.emit "{"

      scope[:tree][:each] do |stmt|
        emitter.emit_stmt(stmt)
      end

      emitter.emit "}"
      emitter.result
    end


    def emit_exec_decl(instr)
      name = instr[:name]
      args = instr[:args]

      params = ["GeneralSim::CPU& cpu"]

      args.each do |arg|
        case arg
        when SimInfra::XReg
          params << "XReg #{arg.name}"
        when SimInfra::XImm
          params << "GeneralSim::Immediate #{arg.name}"
        else
          raise "Unknown instruction argument: #{arg.inspect}"
        end
      end

      "void EXEC_#{name}(#{params.join(', ')})"
    end

    def emit_stmt(stmt)
      name = stmt.name
      ops  = stmt.oprnds
      attrs = stmt.attrs || {}

      case name
      when :new_var
        declare_ssa(ops[0])
      when :getreg
        var_ir, xreg = stmt[:oprnds]
        return "v_#{var_ir} = CPU.getReg(#{xreg});\n"
      when :let
        dst, src = ops
        emit "#{ssa(dst)} = #{operand(src)};"
      when :+, :-, :*, :&, :|, :^, :<<, :>>
        dst, a, b = ops
        declare_ssa(dst)
        emit "#{ssa(dst)} = #{operand(a)} #{name} #{operand(b)};"
      when :<, :==
        dst, a, b = ops
        declare_ssa(dst)
        emit "#{ssa(dst)} = (#{operand(a)} #{name} #{operand(b)});"
      when :~
        dst, a = ops
        declare_ssa(dst)
        emit "#{ssa(dst)} = #{name}#{operand(a)};"
      when :bitrev
        dst, src = ops
        declare_ssa(dst)
        emit "#{ssa(dst)} = CPU.bitrev(#{operand(src)});"
      when :as_signed
        dst, src = ops
        declare_ssa(dst)
        emit "#{ssa(dst)} = static_cast<int64_t>(#{operand(src)});"
      when :as_unsigned
        dst, src = ops
        declare_ssa(dst)
        emit "#{ssa(dst)} = static_cast<uint64_t>(#{operand(src)});"
      when :sext
        dst, src = ops
        from = attrs[:from]
        declare_ssa(dst)
        emit "#{ssa(dst)} = CPU.sext(#{operand(src)}, #{from});"
      when :zext
        dst, src = ops
        from = attrs[:from]
        declare_ssa(dst)
        emit "#{ssa(dst)} = CPU.zext(#{operand{src}}, #{from});"
      when :load
        dst, addr = ops
        declare_ssa(dst)
        bits = dst[:type][:bits]
        emit "#{ssa(dst)} = CPU.load(#{operand(addr)}, #{bits});"
      when :store
        addr, val = ops
        bits = val[:type][:bits]
        emit "CPU.store(#{operand(addr)}, #{operand(val)}, #{bits});"
      when :getreg
        var_sym, reg = ops
        var = @scope.vars[var_sym]
        declare_ssa(var)
        emit "#{ssa(var)} = CPU.getReg(#{reg.name});"
      when :setreg
        reg, var = ops
        emit "CPU.setReg(#{reg.name}, #{ssa(var)});"
      when :syscall
        num = ops.first
        emit "CPU.syscall(#{operand(num)});"
      when :cmp_eq
        a, b = emit_operand(ops[1]), emit_operand(ops[2])
        "auto #{dst} = (#{a} == #{b}) ? 1u : 0u;"
      when :cmp_ne
        a, b = emit_operand(ops[1]), emit_operand(ops[2])
        "auto #{dst} = (#{a} != #{b}) ? 1u : 0u;"
      when :cmp_lt
        a, b = emit_operand(ops[1]), emit_operand(ops[2])
        "auto #{dst} = (static_cast<int32_t>(#{a}) < static_cast<int32_t>(#{b})) ? 1u : 0u;"
      when :cmp_ge
        a, b = emit_operand(ops[1]), emit_operand(ops[2])
        "auto #{dst} = (static_cast<int32_t>(#{a}) >= static_cast<int32_t>(#{b})) ? 1u : 0u;"
      when :cmp_ltu
        a, b = emit_operand(ops[1]), emit_operand(ops[2])
        "auto #{dst} = (#{a} < #{b}) ? 1u : 0u;"
      when :cmp_geu
        a, b = emit_operand(ops[1]), emit_operand(ops[2])
        "auto #{dst} = (#{a} >= #{b}) ? 1u : 0u;"
      else
        raise "Unhandled IR operation: #{name}"
      end
      
    end

    def emit_all_instructions(instructions)
      instructions.map { |instr| emit_exec_function(instr) }.join("\n\n")
    end
  end
end

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
      emit "  " + "uint64_t #{name} = 0;"
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
      puts instr[:name]
      decl = emit_exec_decl(instr)
      puts instr[:name]
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

      puts instr[:name]
      puts 'hoot hoot'

      scope.tree.each do |stmt|
        emitter.emit_stmt(stmt)
      end

      emitter.emit "}"
      emitter.result
    end


    def emit_exec_decl(instr)

      name = instr[:name]
      args = instr[:args]

      params = ["GeneralSim::CPU& CPU"]

      args.each do |arg|
        case arg
        when SimInfra::XReg
          params << "GeneralSim::XReg #{arg.name}"
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
      puts "Current statement: #{stmt.name}"
      case name
      when :new_var
        declare_ssa(ops[0])
      when :new_const # FIXME
        nconst, value = ops
        declare_ssa(nconst)
        emit "  " + "#{ssa(nconst)} = #{value};"
      when :getreg
        var_ir, xreg = ops
        emit "  " + "v_#{var_ir} = CPU.getReg(#{xreg});\n"
      when :getimm
        var_ir, ximm = ops
        emit "  " + "v_#{var_ir} = #{ximm}.raw();\n"
      when :let
        dst, src = ops
        emit "  " + "#{ssa(dst)} = #{operand(src)};"
      when :+, :-, :*, :&, :|, :^, :<<, :>>, :/, :%
        dst, a, b = ops
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = #{operand(a)} #{name} #{operand(b)};"
      when :<, :== # Remove?
        dst, a, b = ops
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (#{operand(a)} #{name} #{operand(b)});"
      when :~
        dst, a = ops
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = #{name}#{operand(a)};"
      when :bitrev
        dst, src = ops
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = CPU.bitrev(#{operand(src)});"
      when :as_signed
        dst, src = ops
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = static_cast<int64_t>(#{operand(src)});"
      when :as_unsigned
        dst, src = ops
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = static_cast<uint64_t>(#{operand(src)});"
      when :sext
        dst, src = ops
        from = attrs[:from]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = CPU.sext(#{operand(src)}, #{from});"
      when :zext
        dst, src = ops
        from = attrs[:from]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = CPU.zext(#{operand(src)}, #{from});"
      when :load
        dst, addr = ops
        declare_ssa(dst)
        bits = dst.type[:bits]
        emit "  " + "#{ssa(dst)} = CPU.load(#{operand(addr)}, #{bits});"
      when :store
        addr, val = ops
        bits = val.type[:bits]
        emit "  " + "CPU.store(#{operand(addr)}, #{operand(val)}, #{bits});"
      when :setreg
        reg, var = ops
        emit "  " + "CPU.setReg(#{reg.name}, #{ssa(var)});"
      when :syscall
        code = ops.first
        declare_ssa(code)
        emit "  " + "CPU.syscall(#{operand(code)});"
      when :cmp_eq
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (#{a} == #{b});"
      when :cmp_ne
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (#{a} != #{b});"
      when :cmp_lt
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (static_cast<int32_t>(#{a}) < static_cast<int32_t>(#{b}));"
      when :cmp_ge
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (static_cast<int32_t>(#{a}) >= static_cast<int32_t>(#{b}));"
      when :cmp_ltu
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (#{a} < #{b});"
      when :cmp_geu
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit "  " + "#{ssa(dst)} = (#{a} >= #{b});"
      when :getpc
        var_ir = ops[0]
        declare_ssa(var_ir)
        emit "  " + "#{ssa(var_ir)} = CPU.getPC();"
      when :setpc
        var = ops[1]
        emit "  " + "CPU.setPC(#{ssa(var)});"
      else
        raise "Unhandled IR operation: #{name}"
      end
      
    end

    def emit_all_instructions(instructions)
      instructions.map { |instr| emit_exec_function(instr) }.join("\n\n")
    end
  end
end

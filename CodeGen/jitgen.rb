module SimInfra
  class CppJitEmitter
    Indent = "  "

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
      "v_#{var.name}"
    end

    def declare_ssa(var, signed = nil, width = 32)
      name = ssa(var)
      return if @declared[name]
      emit Indent + "asmjit::x86::Gp #{name} = CC.newUInt32();"
      @declared[name] = true
    end

    def operand(op)
      case op
      when SimInfra::Var
        ssa(op)
      when SimInfra::Constant
        op.value.to_s
      when SimInfra::XReg
        "CtxJIT->getRegWrapper(#{op.name})"
      when SimInfra::XImm
        "#{op.name}.raw()"
      when Symbol
        op.to_s
      else
        raise "Unknown operand type: #{op.inspect}"
      end
    end

    # --- Instruction emission ---
    def emit_exec_function(instr)
      decl = emit_exec_decl(instr)
      body = emit_instruction(instr)
      <<~CPP
      #{decl}
      #{body}
      CPP
    end

    def emit_instruction(instr)
      emitter = CppJitEmitter.new
      scope   = instr[:code]

      emitter.emit "// JIT Instruction #{instr[:name]}"
      emitter.emit "{"

      scope.tree.each do |stmt|
        emitter.emit_stmt(stmt)
      end

      emitter.emit "}"
      emitter.result
    end

    def emit_exec_decl(instr)
      name = instr[:name]
      args = instr[:args]

      params = ["asmjit::x86::Compiler& CC", "asmjit::x86::Gp CtxPtrReg"]

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
      when :new_var, :new_const
        declare_ssa(ops[0])
      when :getreg
        var, reg = ops
        emit Indent + "CC.mov(asmjit::x86::rcx,  CtxPtrReg);"
        emit Indent + "CC.mov(asmjit::x86::rdx, #{reg});"
        emit Indent + "CC.call(&GeneralSim::getRegWrapper);"
        emit Indent + "CC.mov(#{ssa(var)}, asmjit::x86::eax);"
      when :setreg
        reg, var = ops
        emit Indent + "CC.mov(asmjit::x86::rcx, CtxPtrReg);"
        emit Indent + "CC.mov(asmjit::x86::rdx, #{reg})"
        emit Indent + "CC.call(&GeneralSim::setRegWrapper)"
        emit Indent + "CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), #{reg.name}, #{ssa(var)});"
      when :getimm
        var_ir, ximm = ops
        emit Indent + "v_#{var_ir} = #{ximm}.raw();"
      when :let
        dst, src = ops
        emit Indent + "CC.mov(#{ssa(dst)}, #{operand(src)});"
      when :+, :-, :*, :&, :|, :^, :<<, :>>
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.#{name}(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :/
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "// Division not implemented in JIT, fallback or skip"
      when :%
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "// Modulo not implemented in JIT, fallback or skip"
      when :~
        dst, a = ops
        declare_ssa(dst)
        emit Indent + "CC.not(#{ssa(a)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :bitrev, :sext, :zext, :as_signed, :as_unsigned
        dst, src = ops
        declare_ssa(dst)
        emit Indent + "// #{name} not implemented in JIT, skip"
      when :load
        dst, addr = ops
        declare_ssa(dst)
        bits = dst.type[:bits]
        emit Indent + "#{ssa(dst)} = CC.call(asmjit::imm(&GeneralSim::read#{bits}), #{operand(addr)});"
      when :store
        addr, val = ops
        bits = val.type[:bits]
        emit Indent + "CC.call(asmjit::imm(&GeneralSim::write#{bits}), #{operand(addr)}, #{operand(val)});"
      when :cmp_eq
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.cmp_eq(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :cmp_ne
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.cmp_ne(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :cmp_lt
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.cmp_lt(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :cmp_ge
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.cmp_ge(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :cmp_ltu
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.cmp_ltu(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :cmp_geu
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "CC.cmp_geu(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :getpc
        var_ir = ops[0]
        declare_ssa(var_ir)
        emit Indent + "#{ssa(var_ir)} = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));"
      when :setpc
        var = ops[1]
        emit Indent + "CC.call(asmjit::imm(&GeneralSim::setPCWrapper), #{ssa(var)});"
      when :syscall
        emit Indent + "// Syscall skipped in JIT"
      else
        emit Indent + "// Unhandled IR operation: #{name}"
      end
    end

    def emit_all_instructions(instructions)
      instructions.map { |instr| emit_exec_function(instr) }.join("\n\n")
    end

    def emit_instructions_visit(instructions)
      instructions.map { |instr| emit_instruction_visit(instr) }.join(" else ")
    end

    def emit_instruction_visit(instr)
      name = instr[:name]
      args = instr[:args]

      params = ["Ctx", "CC"]
      args.each { |arg| params << "I.#{arg.name}" }

      <<~CPP
      if constexpr (std::is_same_v<T, #{name}>) {
        EXEC_#{name}(#{params.join(', ')});
      }
      CPP
    end
  end
end

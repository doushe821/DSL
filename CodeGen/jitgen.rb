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

    def declare_ssa(var, width = 32)
      name = ssa(var)
      return if @declared[name]
      emit Indent + "Gp #{name} = CC.newUInt#{width}();"
      @declared[name] = true
    end

    def operand(op)
      case op
      when SimInfra::Var
        ssa(op)
      when SimInfra::Constant
        op.value.to_s
      when SimInfra::XReg
        op
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
          params << "GeneralSim::Immediate #{arg.name.capitalize}"
        else
          raise "Unknown instruction argument: #{arg.inspect}"
        end
      end

      "void EXEC_#{name}(#{params.join(', ')})"
    end

    GetRegWrapperSign = "FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl)"
    SetRegWrapperSign = "FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl)"
    GetPCWrapperSign = "FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl)"
    SetPCWrapperSign = "FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl)"

    def get_read_sign (n)
      return "FuncSignatureT<uint#{n}_t, GeneralSim::ExecContext*, uintptr_t>(CallConvId::kCDecl)"
    end

    def get_write_sign (n)
      return "FuncSignatureT<void, GeneralSim::ExecContext*, uintptr_t, uint32_t>(CallConvId::kCDecl)"      
    end

    def emit_stmt(stmt)
      name = stmt.name
      ops  = stmt.oprnds
      attrs = stmt.attrs || {}

      case name
      when :new_var, :new_const
        declare_ssa(ops[0], ops[0].type.bits)

      when :getreg
        var, reg = ops
        emit Indent + 
        <<~CPP    
          // Get Register
            {
              InvokeNode* Node;
              CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), #{GetRegWrapperSign});
              Node->setArg(0, CtxPtrReg);
              Node->setArg(1, imm(#{reg}));
              Node->setRet(0, #{ssa(var)});
            }
        CPP

      when :setreg
        reg, var = ops
        emit Indent +
        <<~CPP
          // Set Register
            {
              InvokeNode* Node;
              CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), #{SetRegWrapperSign});
              Node->setArg(0, CtxPtrReg);
              Node->setArg(1, imm(#{reg}));
              Node->setArg(2, #{ssa(var)});
            }
        CPP

      when :getpc
        var = ops[0]
        declare_ssa(var, var.type.bits)
        emit Indent + 
        <<~CPP    
          // Get pc
            {
              InvokeNode* Node;
              CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), #{GetPCWrapperSign});
              Node->setArg(0, CtxPtrReg);
              Node->setRet(0, #{ssa(var)});
            }
        CPP

      when :setpc
        var = ops[1]
        emit Indent +
        <<~CPP
          // Set pc
            {
              InvokeNode* Node;
              CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), #{SetPCWrapperSign});
              Node->setArg(0, CtxPtrReg);
              Node->setArg(1, #{ssa(var)});
            }
        CPP


      when :getimm
        var_ir, ximm = ops
        emit Indent + <<~CPP
        // Get Immediate 
        CC.mov(v_#{var_ir}, #{ximm.name.capitalize}.raw()); 
        CPP
      when :let
        dst, src = ops
        emit Indent + <<~CPP     
        // Let
          CC.mov(#{ssa(dst)}, #{operand(src)});
        CPP

      when :&, :|, :^
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)
        emit Indent + "// #{op_to_jit_name(name)}"
        emit Indent + "CC.#{op_to_jit_name(name)}(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"

      when :<<
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)
        emit Indent + "// Left shift"
        emit Indent + "CC.shl(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"

      when :>>
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)
        emit Indent + "// Right shift"
        if a.type.signed or b.type.signed
          emit Indent + "// Signed"
          emit Indent + "CC.sar(#{ssa(a)}, #{ssa(b)});" 
        else
          emit Indent + "// Unsigned"
          emit Indent + "CC.shr(#{ssa(a)}, #{ssa(b)});"    
        end
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"

      when :+, :-
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)
        emit Indent + "// #{op_to_jit_name(name)}"
        emit Indent + "CC.#{op_to_jit_name(name)}(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"

      when :*
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)
        op_name = op_to_jit_name(name)
        op_name = "i" + op_name if a.type.signed or b.type.signed
        emit Indent + "// #{op_name}"
        emit Indent + "CC.#{op_name}(#{ssa(a)}, #{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)}});"

      when :/
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)

        emit Indent + "// Div prelude"
        emit Indent + "CC.mov(eax, #{ssa(a)});"
        if ((a.type.signed == nil) & (b.type.signed == nil))
          emit Indent + "CC.xor_(eax, eax);"
        elsif max_width == 32
          emit Indent + "CC.cdq();" 
        elsif  max_width == 64
          emit Indent + "CC.cqo();"
        end
        
        op_name = op_to_jit_name(name)
        op_name = "i" + op_name if a.type.signed or b.type.signed
        emit Indent + "// #{op_name}, #{max_width}-bit"
        emit Indent + "CC.#{op_name}(#{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, eax);"

      when :%
        dst, a, b = ops
        max_width = (a.type.bits > b.type.bits) ? a.type.bits : b.type.bits
        declare_ssa(dst, max_width)

        emit Indent + "// Div prelude"
        emit Indent + "CC.mov(eax, #{ssa(a)});"
        if ((a.type.signed == nil) & (b.type.signed == nil))
          emit Indent + "CC.xor_(edx, edx);"
        elsif max_width == 32
          emit Indent + "CC.cdq();" 
        elsif  max_width == 64
          emit Indent + "CC.cqo();"
        end
        
        op_name = op_to_jit_name(name)
        op_name = "i" + op_name if a.type.signed or b.type.signed
        emit Indent + "// #{op_name}, #{max_width}-bit"
        emit Indent + "CC.#{op_name}(#{ssa(b)});"
        emit Indent + "CC.mov(#{ssa(dst)}, edx);"

      when :~
        dst, a = ops
        declare_ssa(dst)
        emit Indent + "// Bitwise not"
        emit Indent + "CC.not_(#{ssa(dst)});"

      when :bitrev, :sext, :zext, :as_signed, :as_unsigned
        dst, a = ops
        emit Indent + "// Type clarification"
        declare_ssa(dst, a.type.bits)
        emit Indent + "CC.mov(#{ssa(dst)}, #{ssa(a)});"
      when :load
        dst, addr = ops
        declare_ssa(dst)
        bits = dst.type[:bits]
        emit Indent + 
        <<~CPP
          // Load #{bits}
            {
              InvokeNode* Node;
              CC.invoke(&Node, imm(&GeneralSim::read#{bits}), #{get_read_sign(bits)});
              Node->setArg(0, CtxPtrReg);
              Node->setArg(1, #{operand(addr)});
              Node->setRet(0, #{ssa(dst)});
            }
        CPP

      when :store
        addr, val = ops
        bits = val.type[:bits]
        emit Indent + 
        <<~CPP
          // Load #{bits}
            {
              InvokeNode* Node;
              CC.invoke(&Node, imm(&GeneralSim::write#{bits}), #{get_write_sign(bits)});
              Node->setArg(0, CtxPtrReg);
              Node->setArg(1, #{operand(addr)});
              Node->setArg(2, #{operand(val)});
            }
        CPP
        
      ## Under construction line
      when :cmp_eq
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "// Cmp eq"
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
      when :syscall
        emit Indent +
        <<~CPP
        // Syscall
          InvokeNode* call;
          cc.invoke(&call, CallConvId::kCDecl);
          call->setTarget(imm(&GeneralSim::syscall));
          call->setArg(0, ctx);
        CPP
      else
        raise "Uhandled IR operation: #{name}"
        emit Indent + "// Unhandled IR operation: #{name}"
      end
    end

    def op_to_jit_name(name)
      case name
      when :+
        "add"
      when :-
        "sub"
      when :/, :%
        "div"
      when :*
        "imul"
      when :>>
      when :<<
        "shl"
      when :&
        "and_"
      when :|
        "or_"
      when :^
        "xor_"

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

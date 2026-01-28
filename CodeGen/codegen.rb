module SimInfra
  
  class CppEmitter

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
      raise "Expected Var" unless var.is_a?(SimInfra::Var)
      "v_#{var.name}"
    end

    def declare_ssa(var)
      name = ssa(var)
      raise "Double declaration: #{name.inspect}" if @declared[name]
      emit Indent + "uint64_t #{name} = 0;"
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

      scope.tree.each do |stmt|
        emitter.emit_stmt(stmt)
      end

      emitter.emit "}"
      emitter.result
    end


    def emit_exec_decl(instr)

      name = instr[:name]
      args = instr[:args]

      params = ["ExecContext& Ctx"]

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
      when :new_const
        nconst, value = ops
        declare_ssa(nconst)
        emit Indent + "#{ssa(nconst)} = #{value};"
      when :getreg
        var_ir, xreg = ops
        emit Indent + "v_#{var_ir} = Ctx.getReg(#{xreg});\n"
      when :getimm
        var_ir, ximm = ops
        emit Indent + "v_#{var_ir} = #{ximm}.raw();\n"
      when :let
        dst, src = ops
        emit Indent + "#{ssa(dst)} = #{operand(src)};"
      when :+, :-, :*, :&, :|, :^, :<<, :>>, :/, :%
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = #{operand(a)} #{name} #{operand(b)};"
      when :<, :==, :>, :>=, :<=, :!= # Remove?
        dst, a, b = ops
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (#{operand(a)} #{name} #{operand(b)});"
      when :~
        dst, a = ops
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = #{name}#{operand(a)};"
      when :bitrev
        dst, src = ops
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = Ctx.bitrev(#{operand(src)});"
      when :as_signed
        dst, src = ops
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = static_cast<int64_t>(#{operand(src)});"
      when :as_unsigned
        dst, src = ops
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = static_cast<uint64_t>(#{operand(src)});"
      when :sext
        dst, src = ops
        from = attrs[:from]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = Ctx.sext(#{operand(src)}, #{from});"
      when :zext
        dst, src = ops
        from = attrs[:from]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = Ctx.zext(#{operand(src)}, #{from});"
      when :load
        dst, addr = ops
        declare_ssa(dst)
        bits = dst.type[:bits]
        emit Indent + "#{ssa(dst)} = Ctx.read#{bits}(#{operand(addr)});"
      when :store
        addr, val = ops
        bits = val.type[:bits]
        emit Indent + "Ctx.write#{bits}(#{operand(addr)}, #{operand(val)});"
      when :setreg
        reg, var = ops
        emit Indent + "Ctx.setReg(#{reg.name}, #{ssa(var)});"
      when :syscall
        code = ops.first
        declare_ssa(code)
        emit Indent + "Ctx.syscall(#{operand(code)});"
      when :cmp_eq
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (#{a} == #{b});"
      when :cmp_ne
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (#{a} != #{b});"
      when :cmp_lt
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (static_cast<int32_t>(#{a}) < static_cast<int32_t>(#{b}));"
      when :cmp_ge
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (static_cast<int32_t>(#{a}) >= static_cast<int32_t>(#{b}));"
      when :cmp_ltu
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (#{a} < #{b});"
      when :cmp_geu
        a, b = operand(ops[1]), operand(ops[2])
        dst = ops[0]
        declare_ssa(dst)
        emit Indent + "#{ssa(dst)} = (#{a} >= #{b});"
      when :getpc
        var_ir = ops[0]
        declare_ssa(var_ir)
        emit Indent + "#{ssa(var_ir)} = Ctx.getPC();"
      when :setpc
        var = ops[1]
        emit Indent + "Ctx.setPC(#{ssa(var)});"
      else
        raise "Unhandled IR operation: #{name}"
      end
      
    end

    def emit_all_instructions(instructions)
      instructions.map { |instr| emit_exec_function(instr) }.join("\n\n")
    end

    def emit_instructions_visit(instructions) 
      instructions.map {|instr| emit_instruction_visit(instr) }.join(" else ")
    end

    def emit_instruction_visit(instr)
      name = instr[:name]
      args = instr[:args]

      params = ["Ctx"]
      
      args.each do |arg|
        params << "I.#{arg.name}"
      end

      code = 
        "if constexpr (std::is_same_v<T, #{name}>) {
      EXEC_#{name}(#{params.join(", ")});
    }"
      code
    end

    def cpp_extract_bits(expr, from, to)
      width = to - from + 1
      "((#{expr} >> #{from}) & ((1u << #{width}) - 1))"
    end

    def assemble_scattered_imm(parts, instr_bits)
      imm = 0

      parts.each do |p|
        part_val = extract_bits(instr_bits, p.from, p.to)

        imm |= part_val << p.lo
      end

      imm
    end

    def emit_leaf(node, instr, indent)
      lines = []
      args  = []

      imm_parts = []

      instr[:fields].each do |field|
        case field
        when SimInfra::Field
          case field.value
          when :reg
            expr = cpp_extract_bits("Instr", field.to, field.from)
            lines << "#{indent}XReg #{field.name} = #{expr};"
            args << field.name.to_s
          when :imm
            expr = cpp_extract_bits("Instr", field.to, field.from)
            lines << "#{indent}auto Imm = GeneralSim::Immediate(#{expr}, 32, GeneralSim::ImmediateType::Unsigned);"
            args << "Imm"
          end

        when SimInfra::ImmFieldPart
          imm_parts << field
        end
      end

      if !imm_parts.empty?
        lines << "#{indent}uint32_t ImmRaw = 0;"
        imm_parts.each do |part|
          extract = cpp_extract_bits("Instr", part.to, part.from)
          lines << "#{indent}ImmRaw |= (#{extract} << #{part.lo});"
        end
        lines << "#{indent}auto Imm = GeneralSim::Immediate(ImmRaw, 32, GeneralSim::ImmediateType::Unsigned);"  # Double definition may cause error but this is intended. (also might change in future, in case there are ISAS with multiple imms per instruction)
        args << "Imm"
      end

      lines << "#{indent}return Instruction{ #{node.name}{ #{args.join(', ')} } };"
      lines.join("\n")
    end

    def emit_node(node, instructions, indent = "")
      return emit_leaf(node, instructions.find do |instr| instr[:name] == node.name end, indent) if node.leaf?

      from = node.bit_start
      to   = node.bit_end
      width = to - from + 1

      lines = []
      lines << "#{indent}switch ((Instr >> #{from}) & ((1u << #{width}) - 1)) {"

      node.children.each do |value, child|
        lines << "#{indent}#{Indent}case #{value}: {"
        lines << emit_node(child, instructions, indent + Indent * 2)
        lines << "#{indent}#{Indent}}"
      end

      lines << "#{indent}#{Indent}default:"
      lines << "#{indent}#{Indent * 2}assert(\"No such inst in ISA\");"
      lines << "#{indent}}"

      lines.join("\n")
    end

    def emit_decoder_tree(root, instructions)
      <<~CPP
      Instruction Decoder::decode(uint32_t Instr) {
      #{emit_node(root, instructions, Indent)}
      }
      CPP
    end

  end
end

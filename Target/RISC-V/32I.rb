require_relative "encoding"
require_relative "regtypes"
require_relative "../../Generic/base"

module RV32I
  extend SimInfra
  # R-Type
  # R-alu
  Instruction(:ADD, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:add, rd, rs1, rs2)
  asm { "ADD #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 + rs2
      
  }
  }

  Instruction(:SUB, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:sub, rd, rs1, rs2)
  asm { "SUB #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[]= rs1 - rs2
      
  }
  }

  Instruction(:SLL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:sll, rd, rs1, rs2)
  asm { "SLL #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 << (rs2 & 31)
      
  }
  }

  Instruction(:SLT, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_alu(:slt, rd, rs1, rs2)
    asm { "SLT #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = cmp_lt(rs1, rs2)
      
    }
  }

  Instruction(:SLTU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_alu(:sltu, rd, rs1, rs2)
    asm { "SLTU #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = cmp_ltu(rs1, rs2)
      
    }
  }


  Instruction(:XOR, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:xor, rd, rs1, rs2)
  asm { "XOR #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 ^ rs2
      
  }
  }

  Instruction(:SRL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:srl, rd, rs1, rs2)
  asm { "SRL #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = as_unsigned(rs1) >> (rs2 & 31)
      
  }
  }

  Instruction(:SRA, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:sra, rd, rs1, rs2)
  asm { "SRA #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = as_signed(rs1) >> (rs2 & 31)
      
  }
  }

  Instruction(:OR, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:or, rd, rs1, rs2)
  asm { "OR #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 | rs2
      
  }
  }

  Instruction(:AND, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:and, rd, rs1, rs2)
  asm { "AND #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 & rs2
      
  }
  }

  # I-type
  # I-alu
  Instruction(:ADDI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:addi, rd, rs1, imm)
    asm { "ADDI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 + sext(imm, from: 12, to: 32)
      
    }
  }

  Instruction(:SLTI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:slti, rd, rs1, imm)
    asm { "SLTI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = cmp_lt(rs1, imm)
      
    }
  }

  Instruction(:SLTIU, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:sltiu, rd, rs1, imm)
    asm { "SLTIU #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = cmp_lt(as_unsigned(rs1), as_unsigned(imm))
      
    }
  }

  Instruction(:XORI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:xori, rd, rs1, imm)
    asm { "XORI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 ^ imm
      
    }
  }

  Instruction(:ORI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:ori, rd, rs1, imm)
    asm { "ORI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 | imm
      
    }
  }

  Instruction(:ANDI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:andi, rd, rs1, imm)
    asm { "ANDI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 & imm
      
    }
  }
  # I-shift
  Instruction(:SLLI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu_shift(:slli, rd, rs1, imm)
    asm { "SLLI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 << imm
      
    }
  }

  Instruction(:SRLI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu_shift(:srli, rd, rs1, imm)
    asm { "SRLI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = as_unsigned(rs1) >> imm
      
    }
  }

  Instruction(:SRAI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu_shift(:srai, rd, rs1, imm)
    asm { "SRAI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = as_signed(rs1) >> imm
      
    }
  }
  # I-load
  Instruction(:LB, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lb, rd, rs1, imm)
    asm { "LB #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = sext(load(rs1 + sext(imm, from: 12, to: 32), 8), from: 8, to: 32)
      
    }
  }

  Instruction(:LH, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lh, rd, rs1, imm)
    asm { "LH #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = sext(load(rs1 + sext(imm, from: 12, to: 32), 16), from: 16, to: 32)
      
    }
  }

  Instruction(:LW, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lw, rd, rs1, imm)
    asm { "LW #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = load(rs1 + sext(imm, from: 12, to: 32), 32)
      
    }
  }

  Instruction(:LBU, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lbu, rd, rs1, imm)
    asm { "LBU #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = zext(load(rs1 + sext(imm, from: 12, to: 32), 8), from: 8, to: 32)
      
    }
  }

  Instruction(:LHU, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lhu, rd, rs1, imm)
    asm { "LHU #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = zext(load(rs1 + sext(imm, from: 12, to: 32), 16), from: 16, to: 32)
      
    }
  }

  # S-type
  Instruction(:SB, XReg(:rs2), XReg(:rs1), XImm(:imm)) {
    encoding *format_s_store(:sb, rs1, rs2, imm)
    asm { "SB #{rs2}, #{imm}(#{rs1})" }
    code {
      store(rs1 + sext(imm, from: 12, to: 32), zext(rs2, from: 8, to: 32))
    }
  }

  Instruction(:SH, XReg(:rs2), XReg(:rs1), XImm(:imm)) {
    encoding *format_s_store(:sh, rs1, rs2, imm)
    asm { "SH #{rs2}, #{imm}(#{rs1})" }
    code {
      store(rs1 + sext(imm, from: 12, to: 32), zext(rs2, from: 16, to: 32))
    }
  }

  Instruction(:SW, XReg(:rs2), XReg(:rs1), XImm(:imm)) {
    encoding *format_s_store(:sw, rs1, rs2, imm)
    asm { "SW #{rs2}, #{imm}(#{rs1})" }
    code {
      store(rs1 + sext(imm, from: 12, to: 32), rs2)
    }
  }

  # J-type
  Instruction(:JAL, XReg(:rd), XImm(:imm)) {
    encoding *format_j_(:jal, rd, imm)
    asm { "JAL #{rd}, #{imm}" }
    code {
      rd[] = pc + 4
      setpc pc + imm

    }
    control_flow :jump
  }

  Instruction(:JALR, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_jalr(:jalr, rd, rs1, imm)
    asm { "JALR #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = pc + 4
      setpc (rs1 + imm) & ~1
    }
    control_flow :jump
  }

  # U-type
  Instruction(:LUI, XReg(:rd), XImm(:imm)) {
    encoding *format_u_(:lui, rd, imm)
    asm { "LUI #{rd}, #{imm}" }
    code {
      rd[] = imm << 12
      
    }
    control_flow :jump
  }

  Instruction(:AUIPC, XReg(:rd), XImm(:imm)) {
    encoding *format_u_(:auipc, rd, imm)
    asm { "AUIPC #{rd}, #{imm}" }
    code {
      rd[] = pc + (imm << 12)
      
    }
    control_flow :jump
  }

  # B-type
  Instruction(:BEQ, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:beq, rs1, rs2, imm)
    asm { "BEQ #{rs1}, #{rs2}, #{imm}" }
    code {
      setpc pc + (cmp_eq(rs1, rs2) * sext(imm, from: 13, to: 32))
    }
    control_flow :branch
  }

  Instruction(:BNE, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:bne, rs1, rs2, imm)
    asm { "BNE #{rs1}, #{rs2}, #{imm}" }
    code {
      setpc pc + (cmp_ne(rs1, rs2) * sext(imm, from: 13, to: 32))
    }
    control_flow :branch
  }

  Instruction(:BLT, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:blt, rs1, rs2, imm)
    asm { "BLT #{rs1}, #{rs2}, #{imm}" }
    code {
      setpc pc + (cmp_lt(rs1, rs2) * sext(imm, from: 13, to: 32))
    }
    control_flow :branch
  }

  Instruction(:BGE, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:bge, rs1, rs2, imm)
    asm { "BGE #{rs1}, #{rs2}, #{imm}" }
    code {
      setpc pc + (cmp_ge(rs1, rs2) * sext(imm, from: 13, to: 32))
    }
    control_flow :branch
  }

  Instruction(:BGEU, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:bgeu, rs1, rs2, imm)
    asm { "BGEU #{rs1}, #{rs2}, #{imm}" }
    code {
      setpc pc + (cmp_geu(rs1, rs2) * sext(imm, from: 13, to: 32))
    }
    control_flow :branch
  }

  Instruction(:BLTU, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:bltu, rs1, rs2, imm)
    asm { "BLTU #{rs1}, #{rs2}, #{imm}" }
    code {
      setpc pc + (cmp_ltu(rs1, rs2) * sext(imm, from: 13, to: 32))
    }
    control_flow :branch
  }

  # System
  Instruction(:ECALL) {
    encoding *format_sys(:ecall)
    asm { "ECALL" }
    code {
      syscall
    }
    control_flow :call
  }
end
# TODO remove setreg, simplificate setpc

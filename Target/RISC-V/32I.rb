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
      setreg rd
  }
  }

  Instruction(:SUB, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:sub, rd, rs1, rs2)
  asm { "SUB #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[]= rs1 - rs2
      setreg rd
  }
  }

  Instruction(:SLL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:sll, rd, rs1, rs2)
  asm { "SLL #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 << (rs2 & 31)
      setreg rd
  }
  }

  Instruction(:SLT, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_alu(:slt, rd, rs1, rs2)
    asm { "SLT #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = cmp_lt(rs1, rs2)
      setreg rd
    }
  }

  Instruction(:SLTU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_alu(:sltu, rd, rs1, rs2)
    asm { "SLTU #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = cmp_ltu(rs1, rs2)
      setreg rd
    }
  }


  Instruction(:XOR, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:xor, rd, rs1, rs2)
  asm { "XOR #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 ^ rs2
      setreg rd
  }
  }

  Instruction(:SRL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:srl, rd, rs1, rs2)
  asm { "SRL #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = as_unsigned(rs1) >> (rs2 & 31)
      setreg rd
  }
  }

  Instruction(:SRA, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:sra, rd, rs1, rs2)
  asm { "SRA #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = as_signed(rs1) >> (rs2 & 31)
      setreg rd
  }
  }

  Instruction(:OR, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:or, rd, rs1, rs2)
  asm { "OR #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 | rs2
      setreg rd
  }
  }

  Instruction(:AND, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
  encoding *format_r_alu(:and, rd, rs1, rs2)
  asm { "AND #{rd}, #{rs1}, #{rs2}" }
  code {
      rd[] = rs1 & rs2
      setreg rd
  }
  }

  # TODO separate
  # R-mul
  Instruction(:MUL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:mul, rd, rs1, rs2)
    asm { "MUL #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = rs1 * rs2
      setreg rd
    }
  }

  Instruction(:DIV, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:div, rd, rs1, rs2)
    asm { "DIV #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = rs1 / rs2
      setreg rd
    }
  }

  Instruction(:REM, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:rem, rd, rs1, rs2)
    asm { "REM #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = rs1 % rs2
      setreg rd
    }
  }


  # I-type
  # I-alu
  Instruction(:ADDI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:addi, rd, rs1, imm)
    asm { "ADDI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 + sext(imm, from: 11, to: 32)
      setreg rd
    }
  }

  Instruction(:SLTI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:slti, rd, rs1, imm)
    asm { "SLTI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = cmp_lt(rs1, imm)
      setreg rd
    }
  }

  Instruction(:SLTIU, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:sltiu, rd, rs1, imm)
    asm { "SLTIU #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = cmp_lt(as_unsigned(rs1), as_unsigned(imm))
      setreg rd
    }
  }

  Instruction(:XORI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:xori, rd, rs1, imm)
    asm { "XORI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 ^ imm
      setreg rd
    }
  }

  Instruction(:ORI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:ori, rd, rs1, imm)
    asm { "ORI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 | imm
      setreg rd
    }
  }

  Instruction(:ANDI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu(:andi, rd, rs1, imm)
    asm { "ANDI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 & imm
      setreg rd
    }
  }
  # I-shift
  Instruction(:SLLI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu_shift(:slli, rd, rs1, imm)
    asm { "SLLI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = rs1 << imm
      setreg rd
    }
  }

  Instruction(:SRLI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu_shift(:srli, rd, rs1, imm)
    asm { "SRLI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = as_unsigned(rs1) >> imm
      setreg rd
    }
  }

  Instruction(:SRAI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_alu_shift(:srai, rd, rs1, imm)
    asm { "SRAI #{rd}, #{rs1}, #{imm}" }
    code {
      rd[] = as_signed(rs1) >> imm
      setreg rd
    }
  }
  # I-load
  Instruction(:LB, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lb, rd, rs1, imm)
    asm { "LB #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = sext(load(rs1 + imm, 8), from: 8, to: 32)
      setreg rd
    }
  }

  Instruction(:LH, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lh, rd, rs1, imm)
    asm { "LH #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = sext(load(rs1 + imm, 16), from: 16, to: 32)
      setreg rd
    }
  }

  Instruction(:LW, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lw, rd, rs1, imm)
    asm { "LW #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = load(rs1 + imm, 32)
      setreg rd
    }
  }

  Instruction(:LBU, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lbu, rd, rs1, imm)
    asm { "LBU #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = zext(load(rs1 + imm, 8), from: 8, to: 32)
      setreg rd
    }
  }

  Instruction(:LHU, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_load(:lhu, rd, rs1, imm)
    asm { "LHU #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = zext(load(rs1 + imm, 16), from: 16, to: 32)
      setreg rd
    }
  }

  # S-type
  Instruction(:SB, XReg(:rs2), XReg(:rs1), XImm(:imm)) {
    encoding *format_s_store(:sb, rs2, rs1, imm)
    asm { "SB #{rs2}, #{imm}(#{rs1})" }
    code {
      store(rs1 + imm, zext(rs2, from: 8, to: 32))
    }
  }

  Instruction(:SH, XReg(:rs2), XReg(:rs1), XImm(:imm)) {
    encoding *format_s_store(:sh, rs2, rs1, imm)
    asm { "SH #{rs2}, #{imm}(#{rs1})" }
    code {
      store(rs1 + imm, zext(rs2, from: 16, to: 32))
    }
  }

  Instruction(:SW, XReg(:rs2), XReg(:rs1), XImm(:imm)) {
    encoding *format_s_store(:sw, rs2, rs1, imm)
    asm { "SW #{rs2}, #{imm}(#{rs1})" }
    code {
      store(rs1 + imm, zext(rs2, from: 32, to: 32))
    }
  }

  # J-type
  Instruction(:JAL, XReg(:rd), XImm(:imm)) {
    encoding *format_j_(:jal, rd, imm)
    asm { "JAL #{rd}, #{imm}" }
    code {
      rd[] = pc + 4
      setreg rd
      setpc  = pc + imm

    }
  }

  Instruction(:JALR, XReg(:rd), XReg(:rs1), XImm(:imm)) {
    encoding *format_i_jalr(:jalr, rd, rs1, imm)
    asm { "JALR #{rd}, #{imm}(#{rs1})" }
    code {
      rd[] = pc + 4
      setreg rd
      newPC = (rs1 + imm) & ~1
      setpc newPC
    }
  }

  # U-type
  Instruction(:LUI, XReg(:rd), XImm(:imm)) {
    encoding *format_u_(:lui, rd, imm)
    asm { "LUI #{rd}, #{imm}" }
    code {
      rd[] = imm << 12
      setreg rd
    }
  }

  Instruction(:AUIPC, XReg(:rd), XImm(:imm)) {
    encoding *format_u_(:auipc, rd, imm)
    asm { "AUIPC #{rd}, #{imm}" }
    code {
      rd[] = pc + (imm << 12)
      setreg rd
    }
  }

  # B-type
  Instruction(:BEQ, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
    encoding *format_b_branch(:beq, rs1, rs2, imm)
    asm { "BEQ #{rs1}, #{rs2}, #{imm}" }
    code {
      newPC = pc + (cmp_eq(rs1, rs2) * imm)
      setpc newPC
    }
  }

  # System
  Instruction(:ECALL) {
    encoding *format_sys(:ecall)
    asm { "ECALL" }
    code {
      syscall
    }
  }
end
# TODO remove setreg, simplificate setpc

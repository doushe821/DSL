require_relative 'encoding'
require_relative 'regtypes'
require_relative "../../Generic/base"


module RV32M
  extend SimInfra  

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

  Instruction(:MULH, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:mulh, rd, rs1, rs2)
    asm { "MULH #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = as_signed(sext(rs1, from: 32, to: 64) * sext(rs2, from:32, to: 64)) >> 32
      setreg rd
    }
  }

  Instruction(:MULHSU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:mulhsu, rd, rs1, rs2)
    asm { "MULHSU #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = as_signed(sext(rs1, from: 32, to: 64) * zext(rs2, from: 32, to: 64)) >> 32
      setreg rd
    }
  }

  Instruction(:MULHU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:mulhu, rd, rs1, rs2)
    asm { "MULHU #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = zext(rs1, from: 32, to: 64) * zext(rs2, from:32, to: 64) >> 32
      setreg rd
    }
  }

  Instruction(:DIV, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:div, rd, rs1, rs2)
    asm { "DIV #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = as_signed(rs1) / as_signed(rs2)
      setreg rd
    }
  }

  Instruction(:DIVU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:divu, rd, rs1, rs2)
    asm { "DIVU #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = as_unsigned(rs1) / as_unsigned(rs2)
      setreg rd
    }
  }

  Instruction(:REM, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:rem, rd, rs1, rs2)
    asm { "REM #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = as_signed(rs1) % as_signed(rs2)
      setreg rd
    }
  }

  Instruction(:REMU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
    encoding *format_r_mul(:remu, rd, rs1, rs2)
    asm { "REMU #{rd}, #{rs1}, #{rs2}" }
    code {
      rd[] = as_unsigned(rs1) % as_unsigned(rs2)
      setreg rd
    }
  }

end

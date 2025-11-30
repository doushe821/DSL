require_relative "encoding"
require_relative "regfile"
require_relative "../../Generic/base"

module RV32I
    extend SimInfra
    Instruction(:ADD, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
        encoding *format_r_alu(:add, rd, rs1, rs2)
        asm { "ADD #{rd}, #{rs1}, #{rs2}" }
        code { rd[]= rs1 + rs2 }
    }

    Instruction(:SUB, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
        encoding *format_r_alu(:sub, rd, rs1, rs2)
        asm { "SUB #{rd}, #{rs1}, #{rs2}" }
        code { rd[]= rs1 - rs2 }
    }
#
#    Instruction(:SLL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#        encoding *format_r_alu(:sll, rd, rs1, rs2)
#        asm { "SLL #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 << rs2 }
#    }
#
#    Instruction(:SLT,  XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#        encoding *format_r_alu(:slt, rd, rs1, rs2)
#        asm { "SLT #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 << rs2 }
#    }
#
#    Instruction(:SLTU,  XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#        encoding *format_r_alu(:sltu, rd, rs1, rs2)
#        asm { "SLTU #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 >= rs2 }
#    }
#
#    Instruction(:XOR,  XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#        encoding *format_r_alu(:xor, rd, rs1, rs2)
#        asm { "XOR #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 ^ rs2 }
#    }
#
#
#    Instruction(:SRL,  XReg(:rd), XReg(:rs1), XReg(:rs2)) { # TODO dont be gay
#        encoding *format_r_alu(:srl, rd, rs1, rs2)
#        asm { "SRL #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 >> rs2 }
#    }
#
#
#    Instruction(:SRA,  XReg(:rd), XReg(:rs1), XReg(:rs2)) { # TODO dont be gay
#        encoding *format_r_alu(:sra, rd, rs1, rs2)
#        asm { "SRA #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 >> rs2 }
#    }
#
#
#    Instruction(:OR,  XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#        encoding *format_r_alu(:or, rd, rs1, rs2)
#        asm { "OR #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 | rs2 }
#    }
#
#
#    Instruction(:AND,  XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#        encoding *format_r_alu(:and, rd, rs1, rs2)
#        asm { "AND #{rd}, #{rs1}, #{rs2}" }
#        code { rd[] = rs1 & rs2 }
#    }
    
end

require_relative "../../Generic/base"

module SimInfra

    OPCODES = [[:R, 0b0110011]]

    def format_r(opcode, funct3, funct7, rd, rs1, rs2)
        return :R, [
            field(:opcode, 6, 0, opcode),
            field(:funct3, 14, 12, funct3),
            field(:funct7, 31, 25, funct7),
            field(rd.name, 11, 7, :reg),
            field(rs1.name, 19, 15, :reg),
            field(rs2.name, 24, 20, :reg),
        ]
    end

    def format_r_alu(name, rd, rs1, rs2)
        funct3, funct7 =
        {
            add: [0, 0],
            sub: [0, 0b0110000],
            sll: [0b001, 0],
            slt: [0b010, 0],
            sltu: [0b011, 0],
            xor: [0b100, 0],
            srl: [0b101, 0],
            sra: [0b101, 0b0100000],
            or: [0b110, 0],
            and: [0b111, 0]
        }[name]
        format_r(0b0110011, funct3, funct7, rd, rs1, rs2)
    end

    #def format_i(opcode, funct3, rd, rs1, imm11)
    #  return :I, [
    #    field(rd.name, 11, 7, :reg),
    #    field(rs1.name, 19, 15, :reg),
    #    field(:opcode, 6, 0, opcode),
    #    field(:funct3, 14, 12, funct3),
    #    immpart(:imm11, 31, 25, 11, 0)
    #  ]
    #end
    #def format_i_alu(name, rd, rs1, rs2, imm11)
    #  funct3 = 
    #  {
    #    addi: 0,
    #    slti: 0b010,
    #    sltiu: 0b011,
    #    xori: 0b100,
    #    ori: 0b110,
    #    andi: 0b111
    #  }[name]
    #  format_i(0010011, funct3, rd, rs1, imm11)
    #end
    # TODO define other formats
end

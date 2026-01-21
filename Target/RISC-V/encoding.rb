require_relative "../../Generic/base"

module SimInfra

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
            and: [0b111, 0],
            mul: [0b000, 0b0000001],
            mulh: [0b001, 0b0000001],
            mulhsu: [0b010, 0b0000001],
            mulhu: [0b011, 0b0000001],
            div: [0b100, 0b0000001],
            divu: [0b101, 0b0000001],
            rem: [0b110, 0b0000001],
            remu: [0b111, 0b0000001],

        }[name]
        format_r(0b0110011, funct3, funct7, rd, rs1, rs2)
    end

    def format_i(opcode, funct3, rd, rs1, imm11)
      return :I, [
        field(rd.name, 11, 7, :reg),
        field(rs1.name, 19, 15, :reg),
        field(:opcode, 6, 0, opcode),
        field(:funct3, 14, 12, funct3),
        immpart(:imm11, 31, 25, 11, 0)
      ]
    end

    def format_i_alu(name, rd, rs1, rs2, imm11)
      funct3 = 
      {
        addi: 0,
        slti: 0b010,
        sltiu: 0b011,
        xori: 0b100,
        ori: 0b110,
        andi: 0b111
      }[name]
      format_i(0010011, funct3, rd, rs1, imm11)
    end

    def format_s(opcode, funct3, rs1, rs2, imm5, imm7)
      return :S, [
        field(rs1.name, 19, 15, :reg),
        field(rs2.name, 24, 20, :reg),
        field(:opcode, 6, 0, opcode),
        field(:funct3, 14, 12, funct3),
        immpart(:imm5, 11, 7, 4, 0),
        immpart(:imm7, 31, 25, 11, 5)
      ]
    end

    def format_s_alu(name, rs1, rs2, imm5, imm7)
      funct3 =
      {
        sb: 0b000,
        sh: 0b001,
        sw: 0b010,
        jal: 
      }[name]
      format_i(0100011, funct3, rs1, rs2, imm5, imm7)
    end
    # TODO define other formats
end

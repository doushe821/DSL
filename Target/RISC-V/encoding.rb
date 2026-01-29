require_relative "../../Generic/base"

module SimInfra

  # R-type
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
        add: [0b000, 0b0000000],
        sub: [0b000, 0b0100000],
        sll: [0b001, 0b0000000],
        slt: [0b010, 0b0000000],
        sltu:[0b011, 0b0000000],
        xor: [0b100, 0b0000000],
        srl: [0b101, 0b0000000],
        sra: [0b101, 0b0100000],
        or:  [0b110, 0b0000000],
        and: [0b111, 0b0000000],
      }[name]
    format_r(0b0110011, funct3, funct7, rd, rs1, rs2)
  end

  # R-mul
  def format_r_mul(name, rd, rs1, rs2)
    funct3, funct7 =
      {
        mul:     [0b000, 0b0000001],
        mulh:    [0b001, 0b0000001],
        mulhsu:  [0b010, 0b0000001],
        mulhu:   [0b011, 0b0000001],
        div:     [0b100, 0b0000001],
        divu:    [0b101, 0b0000001],
        rem:     [0b110, 0b0000001],
        remu:    [0b111, 0b0000001]
      }[name]
    format_r(0b0110011, funct3, funct7, rd, rs1, rs2)
  end


  # I-type
  def format_i(opcode, funct3, rd, rs1, imm)
    return :I, [
      field(:opcode, 6, 0, opcode),
      field(:funct3, 14, 12, funct3),
      field(rd.name, 11, 7, :reg),
      field(rs1.name, 19, 15, :reg),
      field(imm.name, 31, 20, :imm)
    ]
  end

  def format_i_alu(name, rd, rs1, imm)
    funct3 =
      {
        addi:  0b000,
        slti:  0b010,
        sltiu: 0b011,
        xori:  0b100,
        ori:   0b110,
        andi:  0b111
      }[name]

    format_i(0b0010011, funct3, rd, rs1, imm)
  end

  # I- shift
  def format_i_shift(opcode, funct3, funct7, rd, rs1, imm)
    return :I_SHIFT, [
      field(:opcode, 6, 0, opcode),
      field(:funct3, 14, 12, funct3),
      field(rd.name, 11, 7, :reg),
      field(rs1.name, 19, 15, :reg),
      field(imm.name, 24, 20, :imm),
      field(:funct7, 31, 25, funct7)
    ]
  end

  def format_i_alu_shift(name, rd, rs1, imm)
    funct3 =
      {
        slli: 0b001,
        srli: 0b101,
        srai: 0b101
      }[name]

    funct7 = (name == :srai) ? 0b0100000 : 0b0000000

    format_i_shift(0b0010011, funct3, funct7, rd, rs1, imm)
  end

  # I-load
  def format_i_load(name, rd, rs1, imm)
    funct3 =
      {
        lb:  0b000,
        lh:  0b001,
        lw:  0b010,
        lbu: 0b100,
        lhu: 0b101
      }[name]
    format_i(0b0000011, funct3, rd, rs1, imm)
  end

  # I - jalr?
  
  def format_i_jalr(name, rd, rs1, imm)
    funct3 = 0b000
    opcode = 0b1100111
    format_i(opcode, funct3, rd, rs1, imm)
  end

  # S-type
  def format_s(opcode, funct3, rs1, rs2, imm)
    return :S, [
      field(:opcode, 6, 0, opcode),
      field(:funct3, 14, 12, funct3),
      field(rs1.name, 19, 15, :reg),
      field(rs2.name, 24, 20, :reg),

      immpart(:imm, 11, 7,  4, 0),
      immpart(:imm, 31, 25, 11, 5),
    ]
  end

  def format_s_store(name, rs1, rs2, imm)
    funct3 =
      {
        sb: 0b000,
        sh: 0b001,
        sw: 0b010
      }[name]
    format_s(0b0100011, funct3, rs1, rs2, imm)
  end

  # B-type
  def format_b(opcode, funct3, rs1, rs2, imm)
    return :B, [
      field(:opcode, 6, 0, opcode),
      field(:funct3, 14, 12, funct3),
      field(rs1.name, 19, 15, :reg),
      field(rs2.name, 24, 20, :reg),

    immpart(:imm1,  31, 31, 12, 12),
    immpart(:imm6,  30, 25, 10, 5),
    immpart(:imm4,  11, 8,  4, 1),
    immpart(:imm1,  7,  7,  11, 11),
    ]
  end

  def format_b_branch(name, rs1, rs2, imm)
    funct3 =
      {
        beq: 0b000,
        bne: 0b001,
        blt: 0b100,
        bge: 0b101,
        bltu:0b110,
        bgeu:0b111
      }[name]
    format_b(0b1100011, funct3, rs1, rs2, imm)
  end

  # U-type
  def format_u(opcode, rd, imm)
    return :U, [
      field(:opcode, 6, 0, opcode),
      field(rd.name, 11, 7, :reg),
      field(:imm_31_12, 31, 12, :imm)
    ]
  end

  def format_u_(name, rd, imm)
    opcode = {
      lui:   0b0110111,
      auipc: 0b0010111
    }[name]
    format_u(opcode, rd, imm)
  end

# J-type
def format_j(name, rd, imm)
  return :J, [
    field(:opcode, 6, 0, 0b1101111),
    field(rd.name, 11, 7, :reg),

    immpart(:imm1,  31, 31, 20, 20),
    immpart(:imm10, 30, 21, 10, 1),
    immpart(:imm1,  20, 20, 11, 11),
    immpart(:imm8,  19, 12, 19, 12),
  ]
end

  def format_j_(name, rd, imm)
    opcode = {
      jal: 0b1101111
    }[name]
    format_j(opcode, rd, imm)
  end

  # Sys
  def format_sys(opcode)
    return :SYS, [
      field(:opcode, 6, 0, opcode)
    ]
  end

  def format_sys_(name)
    opcode =
      {
        ecall:  0b1110011,
      }[name]

    format_sys(opcode)
  end


end

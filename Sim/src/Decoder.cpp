#include "Decoder.hpp"
#include "Instructions.hpp"
using XReg = uint16_t;
namespace Decoder {
Instruction decode(uint32_t Instr) {
  switch ((Instr >> 1) & ((1u << 6) - 1)) {
    case 25: {
      switch ((Instr >> 9) & ((1u << 6) - 1)) {
        case 0: {
          switch ((Instr >> 25) & ((1u << 6) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ ADD{ rd, rs1, rs2 } };
            }
            case 32: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ SUB{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ MUL{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
          }
        }
        case 8: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          return Instruction{ SLL{ rd, rs1, rs2 } };
        }
        case 16: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          return Instruction{ SLT{ rd, rs1, rs2 } };
        }
        case 24: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          return Instruction{ SLTU{ rd, rs1, rs2 } };
        }
        case 32: {
          switch ((Instr >> 20) & ((1u << 6) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ XOR{ rd, rs1, rs2 } };
            }
            case 32: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ DIV{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
          }
        }
        case 40: {
          switch ((Instr >> 25) & ((1u << 6) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ SRL{ rd, rs1, rs2 } };
            }
            case 32: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ SRA{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
          }
        }
        case 48: {
          switch ((Instr >> 20) & ((1u << 6) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ OR{ rd, rs1, rs2 } };
            }
            case 32: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ REM{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
          }
        }
        case 56: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          return Instruction{ AND{ rd, rs1, rs2 } };
        }
        default:
          assert("No such inst in ISA");
      }
    }
    case 9: {
      switch ((Instr >> 9) & ((1u << 6) - 1)) {
        case 0: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ ADDI{ rd, rs1, Imm } };
        }
        case 16: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ SLTI{ rd, rs1, Imm } };
        }
        case 24: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ SLTIU{ rd, rs1, Imm } };
        }
        case 32: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ XORI{ rd, rs1, Imm } };
        }
        case 48: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ ORI{ rd, rs1, Imm } };
        }
        case 56: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ ANDI{ rd, rs1, Imm } };
        }
        case 8: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          return Instruction{ SLLI{ rd, rs1 } };
        }
        case 40: {
          switch ((Instr >> 25) & ((1u << 6) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              return Instruction{ SRLI{ rd, rs1 } };
            }
            case 32: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              return Instruction{ SRAI{ rd, rs1 } };
            }
            default:
              assert("No such inst in ISA");
          }
        }
        default:
          assert("No such inst in ISA");
      }
    }
    case 1: {
      switch ((Instr >> 9) & ((1u << 6) - 1)) {
        case 0: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ LB{ rd, rs1, Imm } };
        }
        case 8: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ LH{ rd, rs1, Imm } };
        }
        case 16: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ LW{ rd, rs1, Imm } };
        }
        case 32: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ LBU{ rd, rs1, Imm } };
        }
        case 40: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ LHU{ rd, rs1, Imm } };
        }
        default:
          assert("No such inst in ISA");
      }
    }
    case 17: {
      switch ((Instr >> 8) & ((1u << 6) - 1)) {
        case 0: {
          XReg rs2 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 7) & ((1u << 5) - 1)) << 0);
          ImmRaw |= (((Instr >> 25) & ((1u << 7) - 1)) << 5);
          auto Imm = GeneralSim::Immediate(ImmRaw, 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ SB{ rs2, rs1, Imm } };
        }
        case 16: {
          XReg rs2 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 7) & ((1u << 5) - 1)) << 0);
          ImmRaw |= (((Instr >> 25) & ((1u << 7) - 1)) << 5);
          auto Imm = GeneralSim::Immediate(ImmRaw, 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ SH{ rs2, rs1, Imm } };
        }
        case 32: {
          XReg rs2 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 7) & ((1u << 5) - 1)) << 0);
          ImmRaw |= (((Instr >> 25) & ((1u << 7) - 1)) << 5);
          auto Imm = GeneralSim::Immediate(ImmRaw, 32, GeneralSim::ImmediateType::Unsigned);
          return Instruction{ SW{ rs2, rs1, Imm } };
        }
        default:
          assert("No such inst in ISA");
      }
    }
    case 55: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      uint32_t ImmRaw = 0;
      ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 20);
      ImmRaw |= (((Instr >> 21) & ((1u << 10) - 1)) << 1);
      ImmRaw |= (((Instr >> 20) & ((1u << 1) - 1)) << 11);
      ImmRaw |= (((Instr >> 12) & ((1u << 8) - 1)) << 12);
      auto Imm = GeneralSim::Immediate(ImmRaw, 32, GeneralSim::ImmediateType::Unsigned);
      return Instruction{ JAL{ rd, Imm } };
    }
    case 51: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
      auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
      return Instruction{ JALR{ rd, rs1, Imm } };
    }
    case 27: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      auto Imm = GeneralSim::Immediate(((Instr >> 12) & ((1u << 20) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
      return Instruction{ LUI{ rd, Imm } };
    }
    case 11: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      auto Imm = GeneralSim::Immediate(((Instr >> 12) & ((1u << 20) - 1)), 32, GeneralSim::ImmediateType::Unsigned);
      return Instruction{ AUIPC{ rd, Imm } };
    }
    case 49: {
      XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
      XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
      uint32_t ImmRaw = 0;
      ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
      ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
      ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
      ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
      auto Imm = GeneralSim::Immediate(ImmRaw, 32, GeneralSim::ImmediateType::Unsigned);
      return Instruction{ BEQ{ rs1, rs2, Imm } };
    }
    case 0: {
      return Instruction{ ECALL{  } };
    }
    default:
      assert("No such inst in ISA");
  }
}
} // namespace Decoder

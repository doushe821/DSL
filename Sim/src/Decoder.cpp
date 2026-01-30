#include <stdexcept>

#include "GeneralSimTypes.hpp"
#include "Decoder.hpp"
#include "Instructions.hpp"
using XReg = uint16_t;
namespace Decoder {
Instruction Decoder::decode(uint32_t Instr) {
  switch ((Instr >> 1) & ((1u << 6) - 1)) {
    case 25: {
      switch ((Instr >> 12) & ((1u << 3) - 1)) {
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
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 1: {
          switch ((Instr >> 25) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ SLL{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ MULH{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 2: {
          switch ((Instr >> 25) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ SLT{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ MULHSU{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 3: {
          switch ((Instr >> 25) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ SLTU{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ MULHU{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 4: {
          switch ((Instr >> 25) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ XOR{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ DIV{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 5: {
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
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ DIVU{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 6: {
          switch ((Instr >> 25) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ OR{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ REM{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        case 7: {
          switch ((Instr >> 25) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ AND{ rd, rs1, rs2 } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
              return Instruction{ REMU{ rd, rs1, rs2 } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        default:
          assert("No such inst in ISA");
          throw(std::runtime_error("Unsupported instruction"));
      }
    }
    case 9: {
      switch ((Instr >> 12) & ((1u << 3) - 1)) {
        case 0: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ ADDI{ rd, rs1, Imm } };
        }
        case 2: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ SLTI{ rd, rs1, Imm } };
        }
        case 3: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ SLTIU{ rd, rs1, Imm } };
        }
        case 4: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ XORI{ rd, rs1, Imm } };
        }
        case 6: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ ORI{ rd, rs1, Imm } };
        }
        case 7: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ ANDI{ rd, rs1, Imm } };
        }
        case 1: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 5) - 1)), 5);
          return Instruction{ SLLI{ rd, rs1, Imm } };
        }
        case 5: {
          switch ((Instr >> 30) & ((1u << 1) - 1)) {
            case 0: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 5) - 1)), 5);
              return Instruction{ SRLI{ rd, rs1, Imm } };
            }
            case 1: {
              XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
              XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
              auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 5) - 1)), 5);
              return Instruction{ SRAI{ rd, rs1, Imm } };
            }
            default:
              assert("No such inst in ISA");
              throw(std::runtime_error("Unsupported instruction"));
          }
        }
        default:
          assert("No such inst in ISA");
          throw(std::runtime_error("Unsupported instruction"));
      }
    }
    case 1: {
      switch ((Instr >> 12) & ((1u << 3) - 1)) {
        case 0: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ LB{ rd, rs1, Imm } };
        }
        case 1: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ LH{ rd, rs1, Imm } };
        }
        case 2: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ LW{ rd, rs1, Imm } };
        }
        case 4: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ LBU{ rd, rs1, Imm } };
        }
        case 5: {
          XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
          return Instruction{ LHU{ rd, rs1, Imm } };
        }
        default:
          assert("No such inst in ISA");
          throw(std::runtime_error("Unsupported instruction"));
      }
    }
    case 17: {
      switch ((Instr >> 12) & ((1u << 2) - 1)) {
        case 0: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 7) & ((1u << 5) - 1)) << 0);
          ImmRaw |= (((Instr >> 25) & ((1u << 7) - 1)) << 5);
          auto Imm = GeneralSim::Immediate(ImmRaw, 12);
          return Instruction{ SB{ rs1, rs2, Imm } };
        }
        case 1: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 7) & ((1u << 5) - 1)) << 0);
          ImmRaw |= (((Instr >> 25) & ((1u << 7) - 1)) << 5);
          auto Imm = GeneralSim::Immediate(ImmRaw, 12);
          return Instruction{ SH{ rs1, rs2, Imm } };
        }
        case 2: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 7) & ((1u << 5) - 1)) << 0);
          ImmRaw |= (((Instr >> 25) & ((1u << 7) - 1)) << 5);
          auto Imm = GeneralSim::Immediate(ImmRaw, 12);
          return Instruction{ SW{ rs1, rs2, Imm } };
        }
        default:
          assert("No such inst in ISA");
          throw(std::runtime_error("Unsupported instruction"));
      }
    }
    case 55: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      uint32_t ImmRaw = 0;
      ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 20);
      ImmRaw |= (((Instr >> 21) & ((1u << 10) - 1)) << 1);
      ImmRaw |= (((Instr >> 20) & ((1u << 1) - 1)) << 11);
      ImmRaw |= (((Instr >> 12) & ((1u << 8) - 1)) << 12);
      auto Imm = GeneralSim::Immediate(ImmRaw, 21);
      return Instruction{ JAL{ rd, Imm } };
    }
    case 51: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
      auto Imm = GeneralSim::Immediate(((Instr >> 20) & ((1u << 12) - 1)), 12);
      return Instruction{ JALR{ rd, rs1, Imm } };
    }
    case 27: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      auto Imm = GeneralSim::Immediate(((Instr >> 12) & ((1u << 20) - 1)), 20);
      return Instruction{ LUI{ rd, Imm } };
    }
    case 11: {
      XReg rd = ((Instr >> 7) & ((1u << 5) - 1));
      auto Imm = GeneralSim::Immediate(((Instr >> 12) & ((1u << 20) - 1)), 20);
      return Instruction{ AUIPC{ rd, Imm } };
    }
    case 49: {
      switch ((Instr >> 12) & ((1u << 3) - 1)) {
        case 0: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
          ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
          ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
          ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
          auto Imm = GeneralSim::Immediate(ImmRaw, 13);
          return Instruction{ BEQ{ rs1, rs2, Imm } };
        }
        case 1: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
          ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
          ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
          ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
          auto Imm = GeneralSim::Immediate(ImmRaw, 13);
          return Instruction{ BNE{ rs1, rs2, Imm } };
        }
        case 4: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
          ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
          ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
          ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
          auto Imm = GeneralSim::Immediate(ImmRaw, 13);
          return Instruction{ BLT{ rs1, rs2, Imm } };
        }
        case 5: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
          ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
          ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
          ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
          auto Imm = GeneralSim::Immediate(ImmRaw, 13);
          return Instruction{ BGE{ rs1, rs2, Imm } };
        }
        case 7: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
          ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
          ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
          ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
          auto Imm = GeneralSim::Immediate(ImmRaw, 13);
          return Instruction{ BGEU{ rs1, rs2, Imm } };
        }
        case 6: {
          XReg rs1 = ((Instr >> 15) & ((1u << 5) - 1));
          XReg rs2 = ((Instr >> 20) & ((1u << 5) - 1));
          uint32_t ImmRaw = 0;
          ImmRaw |= (((Instr >> 31) & ((1u << 1) - 1)) << 12);
          ImmRaw |= (((Instr >> 25) & ((1u << 6) - 1)) << 5);
          ImmRaw |= (((Instr >> 8) & ((1u << 4) - 1)) << 1);
          ImmRaw |= (((Instr >> 7) & ((1u << 1) - 1)) << 11);
          auto Imm = GeneralSim::Immediate(ImmRaw, 13);
          return Instruction{ BLTU{ rs1, rs2, Imm } };
        }
        default:
          assert("No such inst in ISA");
          throw(std::runtime_error("Unsupported instruction"));
      }
    }
    case 0: {
      return Instruction{ ECALL{  } };
    }
    default:
      assert("No such inst in ISA");
      throw(std::runtime_error("Unsupported instruction"));
  }
}

} // namespace Decoder"

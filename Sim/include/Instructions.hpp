#pragma once

#include <variant>
#include "GeneralSimTypes.hpp"
using XReg = uint16_t;
enum class Opcode : uint16_t {
  ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    ADDI,
    SLTI,
    SLTIU,
    XORI,
    ORI,
    ANDI,
    SLLI,
    SRLI,
    SRAI,
    LB,
    LH,
    LW,
    LBU,
    LHU,
    SB,
    SH,
    SW,
    JAL,
    JALR,
    LUI,
    AUIPC,
    BEQ,
    BNE,
    BLT,
    BGE,
    BGEU,
    BLTU,
    ECALL,
    MUL,
    MULH,
    MULHSU,
    MULHU,
    DIV,
    DIVU,
    REM,
    REMU
};

struct ADD {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::ADD;

};

struct SUB {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::SUB;

};

struct SLL {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::SLL;

};

struct SLT {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::SLT;

};

struct SLTU {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::SLTU;

};

struct XOR {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::XOR;

};

struct SRL {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::SRL;

};

struct SRA {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::SRA;

};

struct OR {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::OR;

};

struct AND {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::AND;

};

struct ADDI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::ADDI;

};

struct SLTI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SLTI;

};

struct SLTIU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SLTIU;

};

struct XORI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::XORI;

};

struct ORI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::ORI;

};

struct ANDI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::ANDI;

};

struct SLLI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SLLI;

};

struct SRLI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SRLI;

};

struct SRAI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SRAI;

};

struct LB {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::LB;

};

struct LH {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::LH;

};

struct LW {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::LW;

};

struct LBU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::LBU;

};

struct LHU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::LHU;

};

struct SB {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SB;

};

struct SH {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SH;

};

struct SW {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::SW;

};

struct JAL {
  XReg rd;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::JAL;

};

struct JALR {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::JALR;

};

struct LUI {
  XReg rd;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::LUI;

};

struct AUIPC {
  XReg rd;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::AUIPC;

};

struct BEQ {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::BEQ;

};

struct BNE {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::BNE;

};

struct BLT {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::BLT;

};

struct BGE {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::BGE;

};

struct BGEU {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::BGEU;

};

struct BLTU {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

  static constexpr Opcode OP = Opcode::BLTU;

};

struct ECALL {

  static constexpr Opcode OP = Opcode::ECALL;

};

struct MUL {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::MUL;

};

struct MULH {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::MULH;

};

struct MULHSU {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::MULHSU;

};

struct MULHU {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::MULHU;

};

struct DIV {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::DIV;

};

struct DIVU {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::DIVU;

};

struct REM {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::REM;

};

struct REMU {
  XReg rd;
  XReg rs1;
  XReg rs2;
  static constexpr Opcode OP = Opcode::REMU;

};


using Instruction = std::variant<
    ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    ADDI,
    SLTI,
    SLTIU,
    XORI,
    ORI,
    ANDI,
    SLLI,
    SRLI,
    SRAI,
    LB,
    LH,
    LW,
    LBU,
    LHU,
    SB,
    SH,
    SW,
    JAL,
    JALR,
    LUI,
    AUIPC,
    BEQ,
    BNE,
    BLT,
    BGE,
    BGEU,
    BLTU,
    ECALL,
    MUL,
    MULH,
    MULHSU,
    MULHU,
    DIV,
    DIVU,
    REM,
    REMU
>;
struct OpcodeInfo {
  bool IsTerminator;
  uint8_t Size;
};
inline constexpr OpcodeInfo OpcodeTable[] = {
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {true, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
    {false, 4 },
};

static inline bool isTerminator(Opcode Op) {
    return OpcodeTable[static_cast<std::size_t>(Op)].IsTerminator;
}

static inline uint8_t instSize(Opcode Op) {
    return OpcodeTable[static_cast<std::size_t>(Op)].Size;
}

static inline Opcode getOpcode(const Instruction& Inst) {
    return std::visit([](auto&& I) {
        return std::decay_t<decltype(I)>::OP;
    }, Inst);
}

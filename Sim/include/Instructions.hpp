#pragma once

#include <variant>
#include "GeneralSimTypes.hpp"
using XReg = uint16_t;
struct ADD {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct SUB {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct SLL {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct SLT {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct SLTU {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct XOR {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct SRL {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct SRA {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct OR {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct AND {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct ADDI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SLTI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SLTIU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct XORI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct ORI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct ANDI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SLLI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SRLI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SRAI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct LB {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct LH {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct LW {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct LBU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct LHU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SB {
  XReg rs2;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SH {
  XReg rs2;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct SW {
  XReg rs2;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct JAL {
  XReg rd;
  GeneralSim::Immediate imm;

};

struct JALR {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate imm;

};

struct LUI {
  XReg rd;
  GeneralSim::Immediate imm;

};

struct AUIPC {
  XReg rd;
  GeneralSim::Immediate imm;

};

struct BEQ {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate imm;

};

struct ECALL {

};

struct MUL {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct MULH {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct MULHSU {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct MULHU {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct DIV {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct DIVU {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct REM {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct REMU {
  XReg rd;
  XReg rs1;
  XReg rs2;
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

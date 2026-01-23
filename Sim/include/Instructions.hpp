#pragma once

#include <variant>
#include "GeneralSim.hpp"
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

struct MUL {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct DIV {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct REM {
  XReg rd;
  XReg rs1;
  XReg rs2;
};

struct ADDI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct SLTI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct SLTIU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct XORI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct ORI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct ANDI {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct SLLI {
  XReg rd;
  XReg rs1;
};

struct SRLI {
  XReg rd;
  XReg rs1;
};

struct SRAI {
  XReg rd;
  XReg rs1;
};

struct LB {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct LH {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct LW {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct LBU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct LHU {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct SB {
  XReg rs2;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct SH {
  XReg rs2;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct SW {
  XReg rs2;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct JAL {
  XReg rd;
  GeneralSim::Immediate Imm;

};

struct JALR {
  XReg rd;
  XReg rs1;
  GeneralSim::Immediate Imm;

};

struct LUI {
  XReg rd;
  GeneralSim::Immediate Imm;

};

struct AUIPC {
  XReg rd;
  GeneralSim::Immediate Imm;

};

struct BEQ {
  XReg rs1;
  XReg rs2;
  GeneralSim::Immediate Imm;

};

struct ECALL {

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
    MUL,
    DIV,
    REM,
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
    ECALL
>;

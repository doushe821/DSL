#pragma once

#include <variant>
#include "GeneralSim.hpp"

struct Add {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Sub {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Sll {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Slt {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Sltu {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Xor {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Srl {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Sra {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Or {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct And {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Mul {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Div {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Rem {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
};

struct Addi {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Slti {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Sltiu {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Xori {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Ori {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Andi {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Slli {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Srli {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Srai {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Lb {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Lh {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Lw {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Lbu {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Lhu {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Sb {
  GeneralSim::XReg rs2;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm_lo;
  GeneralSim::Immediate imm_hi;
};

struct Sh {
  GeneralSim::XReg rs2;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm_lo;
  GeneralSim::Immediate imm_hi;
};

struct Sw {
  GeneralSim::XReg rs2;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm_lo;
  GeneralSim::Immediate imm_hi;
};

struct Jal {
  GeneralSim::XReg rd;
  GeneralSim::Immediate imm_19_12;
  GeneralSim::Immediate imm_11;
  GeneralSim::Immediate imm_10_1;
  GeneralSim::Immediate imm_20;
};

struct Jalr {
  GeneralSim::XReg rd;
  GeneralSim::XReg rs1;
  GeneralSim::Immediate imm;
};

struct Lui {
  GeneralSim::XReg rd;
  GeneralSim::Immediate imm_31_12;
};

struct Auipc {
  GeneralSim::XReg rd;
  GeneralSim::Immediate imm_31_12;
};

struct Beq {
  GeneralSim::XReg rs1;
  GeneralSim::XReg rs2;
  GeneralSim::Immediate imm_11;
  GeneralSim::Immediate imm_4_1;
  GeneralSim::Immediate imm_10_5;
  GeneralSim::Immediate imm_12;
};

struct Ecall {
  GeneralSim::Immediate opcode;
};

struct Ebreak {
  GeneralSim::Immediate opcode;
};


using Instruction = std::variant<
    Add,
    Sub,
    Sll,
    Slt,
    Sltu,
    Xor,
    Srl,
    Sra,
    Or,
    And,
    Mul,
    Div,
    Rem,
    Addi,
    Slti,
    Sltiu,
    Xori,
    Ori,
    Andi,
    Slli,
    Srli,
    Srai,
    Lb,
    Lh,
    Lw,
    Lbu,
    Lhu,
    Sb,
    Sh,
    Sw,
    Jal,
    Jalr,
    Lui,
    Auipc,
    Beq,
    Ecall,
    Ebreak
>;

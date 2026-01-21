#pragma once

#include <variant>
#include "GeneralSim.hpp"
struct Add {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Sub {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Sll {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Slt {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Sltu {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Xor {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Srl {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Sra {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Or {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct And {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Addi {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Immediate imm11;
};

struct Slti {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Immediate imm11;
};

struct Sltiu {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Immediate imm11;
};

struct Xori {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Immediate imm11;
};

struct Ori {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Immediate imm11;
};

struct Andi {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Immediate imm11;
};

struct Mul {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Mulh {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Mulhsu {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Mulhu {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Div {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Divu {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Rem {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};

struct Remu {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
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
    Addi,
    Slti,
    Sltiu,
    Xori,
    Ori,
    Andi,
    Mul,
    Mulh,
    Mulhsu,
    Mulhu,
    Div,
    Divu,
    Rem,
    Remu
>;

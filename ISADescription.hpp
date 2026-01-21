#pragma once
#include <cstdint>
namespace ISA {
  enum class InstructionCodes {
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
    MUL,
    MULH,
    MULHSU,
    MULHU,
    DIV,
    DIVU,
    REM,
    REMU,
      INVALID
  };

  constexpr uint16_t RegisterCount = 32;

} // namespace ISA

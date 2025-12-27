// Generated code //
#include "decoder.hpp"
#include "ShortISADescription.hpp"
#include "GeneralSim.hpp"

ISA::InstructionCodes Decode(uint32_t /*replace with actual undecoded instruction type here*/ instr) {
  switch(instr & 0b1000010000000000111000000000010) {
    case 0: {
      return ISA::InstructionCodes::ADDI;
    }
    case 4: {
      return ISA::InstructionCodes::SLTI;
    }
    case 8: {
      return ISA::InstructionCodes::XORI;
    }
    case 12: {
      return ISA::InstructionCodes::ORI;
    }
    case 20: {
      return ISA::InstructionCodes::SLTIU;
    }
    case 28: {
      return ISA::InstructionCodes::ANDI;
    }
    case 32: {
      return ISA::InstructionCodes::ADD;
    }
    case 33: {
      return ISA::InstructionCodes::SUB;
    }
    case 34: {
      return ISA::InstructionCodes::MUL;
    }
    case 36: {
      return ISA::InstructionCodes::SLT;
    }
    case 38: {
      return ISA::InstructionCodes::MULHSU;
    }
    case 40: {
      return ISA::InstructionCodes::XOR;
    }
    case 42: {
      return ISA::InstructionCodes::DIV;
    }
    case 44: {
      return ISA::InstructionCodes::OR;
    }
    case 46: {
      return ISA::InstructionCodes::REM;
    }
    case 48: {
      return ISA::InstructionCodes::SLL;
    }
    case 50: {
      return ISA::InstructionCodes::MULH;
    }
    case 52: {
      return ISA::InstructionCodes::SLTU;
    }
    case 54: {
      return ISA::InstructionCodes::MULHU;
    }
    case 56: {
      return ISA::InstructionCodes::SRL;
    }
    case 57: {
      return ISA::InstructionCodes::SRA;
    }
    case 58: {
      return ISA::InstructionCodes::DIVU;
    }
    case 60: {
      return ISA::InstructionCodes::AND;
    }
    case 62: {
      return ISA::InstructionCodes::REMU;
    }
  }
}

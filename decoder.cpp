// Generated code //
#include "decoder.hpp"
#include "ShortISADescription.hpp"
#include "GeneralSim.hpp"

ISA::InstructionCodes Decode(int /*replace with actual undecoded instruction type here*/ instr) {
  switch(instr & 0b1000000000000000111000000000010) {
    case 0: {
      return ISA::InstructionCodes::ADDI;
    }
    case 2: {
      return ISA::InstructionCodes::SLTI;
    }
    case 4: {
      return ISA::InstructionCodes::XORI;
    }
    case 6: {
      return ISA::InstructionCodes::ORI;
    }
    case 10: {
      return ISA::InstructionCodes::SLTIU;
    }
    case 14: {
      return ISA::InstructionCodes::ANDI;
    }
    case 16: {
      return ISA::InstructionCodes::ADD;
    }
    case 17: {
      return ISA::InstructionCodes::SUB;
    }
    case 18: {
      return ISA::InstructionCodes::SLT;
    }
    case 20: {
      return ISA::InstructionCodes::XOR;
    }
    case 22: {
      return ISA::InstructionCodes::OR;
    }
    case 24: {
      return ISA::InstructionCodes::SLL;
    }
    case 26: {
      return ISA::InstructionCodes::SLTU;
    }
    case 28: {
      return ISA::InstructionCodes::SRL;
    }
    case 29: {
      return ISA::InstructionCodes::SRA;
    }
    case 30: {
      return ISA::InstructionCodes::AND;
    }
  }
}

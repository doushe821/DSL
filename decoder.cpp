// Generated code //
#include "decoder.hpp"
#include "ShortISADescription.hpp"
#include "GeneralSim.hpp"

ISA::InstructionCodes Decode(int /*replace with actual undecoded instruction type here*/ instr) {
  switch(GetMaskedValue(instr, [1, 12, 14, 13, 30])) {
    case 0: {
      return ADDI;
    }
    case 2: {
      return SLTI;
    }
    case 4: {
      return XORI;
    }
    case 6: {
      return ORI;
    }
    case 10: {
      return SLTIU;
    }
    case 14: {
      return ANDI;
    }
    case 16: {
      return ADD;
    }
    case 17: {
      return SUB;
    }
    case 18: {
      return SLT;
    }
    case 20: {
      return XOR;
    }
    case 22: {
      return OR;
    }
    case 24: {
      return SLL;
    }
    case 26: {
      return SLTU;
    }
    case 28: {
      return SRL;
    }
    case 29: {
      return SRA;
    }
    case 30: {
      return AND;
    }
  }
}

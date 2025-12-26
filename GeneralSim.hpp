#pragma once
#include <cstdint>
#include <vector>
#include <variant>

namespace GeneralSim {
// TODO: 
// Generate instruction Identity enum -> generate hash table with functions,
//  

enum InstructionIdentity { // Expected to be Encoding format + opcode inside the format
// GENERATED
}; // Might be in another header

class Operand;
struct Instruction {
  InstructionIdentity InstrId;
  std::vector<Operand> Operands;
};

namespace {
enum class ImmediateType {
  Unsigned,
  Signed
};

} // namespace

class Immediate {
private:
  unsigned Value;
  unsigned BitSize;
  ImmediateType Type;
public:
  void SignExtend() {

  }

  bool IsSigned() const {
    return Type == ImmediateType::Signed;
  }

  bool IsUnsigned() const {
    return Type == ImmediateType::Unsigned;
  }
};

class Register { // Questionable
private:
  unsigned Number;
public:
  unsigned GetNumber() { return Number; }
  void SetNumber(unsigned Number) { Register::Number = Number; }
};

struct Operand {
  std::variant<Immediate, Register> Value;
};

inline uint32_t getMaskedValue(uint32_t Value, int StartBit, int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}


} // namespace GeneralSim



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

  inline int32_t signExtend(uint32_t value, int bits) {
      return (int32_t)(value << (32 - bits)) >> (32 - bits);
  }


  bool isSigned() const {
    return Type == ImmediateType::Signed;
  }

  bool isUnsigned() const {
    return Type == ImmediateType::Unsigned;
  }
};

class Register { // Questionable
private:
  unsigned Number;
public:
  unsigned getNumber() { return Number; }
  void setNumber(unsigned Number) { Register::Number = Number; }
};


inline uint32_t getMaskedValue(uint32_t Value, int StartBit, int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}


} // namespace GeneralSim



#pragma once
#include <cstdint>
#include <cassert>
#include "ISADescription.hpp"

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
enum class ImmediateType : uint8_t {
  Unsigned,
  Signed
};

} // namespace

static inline int32_t signExtend(uint32_t value, int bits) {
    return (int32_t)(value << (32 - bits)) >> (32 - bits);
}
class Immediate {
private:
  unsigned RawValue = 0;
  unsigned BitSize = 0;
  ImmediateType Type = ImmediateType::Unsigned;
public:
  constexpr Immediate() = default;
  constexpr Immediate(uint32_t raw,
                      uint8_t bits,
                      ImmediateType type)
    : RawValue(raw), BitSize(bits), Type(type) {}

  constexpr uint32_t raw() const {
    return RawValue;
  }

  constexpr uint8_t bits() const {
    return BitSize;
  }

  constexpr bool isSigned() const {
    return Type == ImmediateType::Signed;
  }

  constexpr bool isUnsigned() const {
    return Type == ImmediateType::Unsigned;
  }

  constexpr int32_t asSigned() const {
    assert(isSigned());
    return signExtend(RawValue, BitSize);
  }

  constexpr uint32_t asUnsigned() const {
    assert(isUnsigned());
    return RawValue;
  }

  constexpr void set(uint32_t raw,
                     uint8_t bits,
                     ImmediateType type) {
    RawValue = raw;
    BitSize  = bits;
    Type     = type;
  }
};


// TODO add forbidden registers list and forbidden registers list checks.
class Register {
private:
  uint16_t Index = 0;
public:
  constexpr Register() = default;
  constexpr explicit Register(uint8_t _Index) { assert(ISA::RegisterCount < _Index); Index = _Index; }

  constexpr uint8_t getIndex() { return Index; }
  constexpr void setIndex(uint16_t NewIndex) { assert(ISA::RegisterCount < NewIndex); Index = NewIndex; }

};


inline uint32_t getMaskedValue(uint32_t Value, int StartBit, int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}


} // namespace GeneralSim



#pragma once
#include <cstdint>
#include <cassert>
namespace GeneralSim {

class CPU;

enum class ImmediateType : uint8_t { Unsigned, Signed };
using XReg = uint16_t;

class Immediate {
private:
  uint32_t RawValue = 0;
  uint16_t BitSize = 0;
  ImmediateType Type = ImmediateType::Unsigned;

  constexpr int32_t sext(int32_t Val, int N) const {
    if (Val & (1 << (N - 1))) {
      int Mask = ~((1 << N) - 1);
      Val |= Mask;
    }
    return Val;
  }

public:
  constexpr Immediate() = default;
  constexpr Immediate(uint32_t Raw, uint8_t Bits, ImmediateType Type)
      : RawValue(Raw), BitSize(Bits), Type(Type) {}

  constexpr uint32_t raw() const { return RawValue; }

  constexpr uint8_t bits() const { return BitSize; }

  constexpr bool isSigned() const { return Type == ImmediateType::Signed; }

  constexpr bool isUnsigned() const { return Type == ImmediateType::Unsigned; }

  constexpr int32_t asSigned() const {
    return sext(RawValue, BitSize);
  }

  constexpr uint32_t asUnsigned() const {
    return RawValue;
  }

  constexpr void set(uint32_t Raw, uint8_t Bits, ImmediateType Type_) {
    RawValue = Raw;
    BitSize = Bits;
    Type = Type_;
  
  }
};
};

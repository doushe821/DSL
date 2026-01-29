#pragma once
#include <cstdint>
#include <cassert>
namespace GeneralSim {

class CPU;

using XReg = uint16_t;

class Immediate {
private:
  uint32_t RawValue = 0;
  uint16_t BitSize = 0;

  constexpr int32_t sext(int32_t Val, int N) const {
    if (Val & (1 << (N - 1))) {
      int Mask = ~((1 << N) - 1);
      Val |= Mask;
    }
    return Val;
  }

public:
  constexpr Immediate() = default;
  constexpr Immediate(uint32_t Raw, uint8_t Bits)
      : RawValue(Raw), BitSize(Bits) {}

  constexpr uint32_t raw() const { return RawValue; }

  constexpr uint8_t bits() const { return BitSize; }

  constexpr int32_t asSigned() const {
    return sext(RawValue, BitSize);
  }

  constexpr uint32_t asUnsigned() const {
    return RawValue;
  }

  constexpr void set(uint32_t Raw, uint8_t Bits) {
    RawValue = Raw;
    BitSize = Bits;
  }
};
};

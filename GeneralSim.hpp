#pragma once
#include <cstdint>
#include <cassert>
#include "ISADescription.hpp"

#include <memory>
#include <vector>
#include <variant>

namespace GeneralSim {

enum class ImmediateType : uint8_t {
  Unsigned,
  Signed
};


class Immediate {
private:
  uint32_t RawValue = 0;
  uint16_t BitSize = 0;
  ImmediateType Type = ImmediateType::Unsigned;

  // I don't want to declare sext in the header for just
  // 2 uses of it, so I copied it here.
  constexpr uint64_t sext(uint64_t Val, int N) const {
    if (Val & (1 << (N - 1))) {
      int Mask = ~((1 << N) - 1);
      Val |= Mask;
    }
    return Val;
  }

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

  constexpr uint64_t asSigned() const {
    assert(isSigned());
    return sext(RawValue, BitSize);
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

using XReg = uint16_t;
class Register {
private:
  XReg Index = 0;
public:
  constexpr Register() = default;
  constexpr explicit Register(uint8_t _Index) { assert(ISA::RegisterCount < _Index); Index = _Index; }

  constexpr uint8_t getIndex() { return Index; }
  constexpr void setIndex(uint16_t NewIndex) { assert(ISA::RegisterCount < NewIndex); Index = NewIndex; }

};


inline uint32_t getMaskedValue(uint32_t Value, int StartBit, int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}

namespace {
class RegState { // interface
public:
  virtual ~RegState();
  virtual uint64_t getReg(XReg r) { assert("Not implemented\n"); };
  virtual void     setReg(XReg r, uint64_t v) { assert("Not implemented\n"); };
  virtual uint64_t getRegSystem(XReg r) { assert("Not implemented\n"); };
  virtual void     setRegSystem(XReg r, uint64_t v) { assert("Not implemented\n"); };
};
} // namespace

class CPU {
private:
  std::unique_ptr<RegState> RState;
  constexpr uint64_t getRegSystem(XReg r) { return RState->getRegSystem(r); }
  constexpr void     setRegSystem(XReg r, uint64_t v) { RState->setRegSystem(r, v); };
public:

  constexpr uint64_t getReg(XReg r) { return  RState->getReg(r); };
  constexpr void     setReg(XReg r, uint64_t v) { RState->setReg(r, v); };

  constexpr uint64_t load(uint64_t addr, int bits);
  constexpr void     store(uint64_t addr, uint64_t value, int bits);

  constexpr void syscall(int num);

  constexpr int bitrev(int Val, int NBits = 32) { // Does it in log(n)
    assert(NBits <= 64);
    uint64_t Mask = (NBits == 64) ? ~0ULL : ((1ULL << NBits) - 1);
    Val &= Mask;

    for (unsigned Step = 1; Step < NBits; Step <<= 1) {
        uint64_t M =
            ((1ULL << Step) - 1) |
            (((1ULL << Step) - 1) << (2 * Step));

        uint64_t Pattern = 0;
        for (unsigned I = 0; I < 64; I += 2 * Step)
            Pattern |= M << I;

        uint64_t A = (Val & Pattern);
        uint64_t B = (Val & (Pattern << Step));

        Val = (A << Step) | (B >> Step);
    }

    return Val & Mask;
  }

  constexpr uint64_t sext(uint64_t Val, int N) {
    if (Val & (1 << (N - 1))) {
      int Mask = ~((1 << N) - 1);
      Val |= Mask;
    }
    return Val;
  }

  constexpr uint64_t zext(uint64_t v, unsigned N)
  {
    assert(N <= 64);
    if (N == 64)
        return v;
    return v & ((1ULL << N) - 1);
  }

  constexpr int saturateUnsigned(unsigned Val, unsigned N) {
    unsigned Limit = (1 << N) - 1;
    if (Val > Limit) {
      Val = Limit;
    }
    return Val;
  }
};

class Memory {

};



} // namespace GeneralSim



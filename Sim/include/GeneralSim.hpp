#pragma once
#include <cstdint>
#include <cassert>

#include <memory>

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

  // I don't want to declare sext outside of the classes for just
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
  constexpr Immediate(uint32_t Raw,
                      uint8_t Bits,
                      ImmediateType Type)
    : RawValue(Raw), BitSize(Bits), Type(Type) {}

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

  constexpr void set(uint32_t Raw,
                     uint8_t Bits,
                     ImmediateType Type_) {
    RawValue = Raw;
    BitSize  = Bits;
    Type     = Type_;
  }
};

using XReg = uint16_t;


static inline uint32_t getMaskedValue(uint32_t Value, int StartBit, int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}

namespace {
class RegState { // interface for generated classes
public:
  virtual ~RegState();
  virtual uint64_t getReg(XReg R) { assert("Not implemented\n"); };
  virtual void     setReg(XReg R, uint64_t V) { assert("Not implemented\n"); };
  virtual uint64_t getRegSystem(XReg R) { assert("Not implemented\n"); };
  virtual void     setRegSystem(XReg R, uint64_t V) { assert("Not implemented\n"); };
};
} // namespace

class CPU {
private:
  uint64_t PC;
  bool Finished{false};
  std::unique_ptr<RegState> RState;
  constexpr uint64_t getRegSystem(XReg R) { return RState->getRegSystem(R); }
  constexpr void     setRegSystem(XReg R, uint64_t V) { RState->setRegSystem(R, V); };
public:

  constexpr uint64_t getPC() { return PC; };
  constexpr void setPC(uint64_t NewPC) { PC = NewPC; };

  constexpr uint64_t getReg(XReg R) { return  RState->getReg(R); };
  constexpr void     setReg(XReg R, uint64_t V) { RState->setReg(R, V); };

  constexpr uint64_t load(uint64_t Addr, int Bits);
  constexpr void     store(uint64_t Addr, uint64_t Value, int Bits);

  constexpr void syscall(int Code) { if (Code == 1) { Finished = true; } else { assert("Not implemented\n"); } };

  constexpr int bitrev(int Val, int NBits = 32) { // Does it in log(n)
    assert(NBits <= 64);
    uint64_t Mask = (NBits == 64) ? ~0ULL : ((1ULL << NBits) - 1);
    Val &= Mask;

    for (int Step = 1; Step < NBits; Step <<= 1) {
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

  constexpr uint64_t zext(uint64_t V, unsigned N)
  {
    assert(N <= 64);
    if (N == 64)
        return V;
    return V & ((1ULL << N) - 1);
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

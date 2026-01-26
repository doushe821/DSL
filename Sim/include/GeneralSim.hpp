#pragma once
#include <cstdint>
#include <cassert>
#include <cstring>

#include <memory>
#include <array>
#include <vector>


namespace GeneralSim {

static const size_t kMemorySize = UINT16_MAX; // TODO Make CLI-defined with defauly value

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
class RegState { // interface for generated classes make pimpl
public:
  virtual ~RegState();
  virtual uint64_t getReg(XReg R) { assert("Not implemented\n"); };
  virtual void     setReg(XReg R, uint64_t V) { assert("Not implemented\n"); };
  virtual uint64_t getRegSystem(XReg R) { assert("Not implemented\n"); };
  virtual void     setRegSystem(XReg R, uint64_t V) { assert("Not implemented\n"); };
};
} // namespace

class Memory { // TODO turn this into interface for Architecture-defined memory model
private:
  std::array<char, kMemorySize> RAM;

public:

  void write(const void* Source, unsigned N, unsigned DestinationAddress) {
    assert(Source && "Invalid source pointer\n");
    assert((DestinationAddress < kMemorySize && DestinationAddress + N < kMemorySize) && "Trying to write to unreachable address\n");
    memcpy(reinterpret_cast<char*>(RAM.data()) + DestinationAddress, Source, N);
  }

  void read(void* Destination, unsigned N, unsigned SourceAddress) const {
    assert(Destination && "Invalid destination pointer\n");
    assert((SourceAddress < kMemorySize && SourceAddress + N < kMemorySize) && "Trying to read from unreachable address\n");
    memcpy(Destination, reinterpret_cast<const char*>(RAM.data()) + SourceAddress, N);
  }
};

class CPU {
private:
  uint64_t PC = UINT64_MAX;
  bool Finished{false};
  std::unique_ptr<RegState> RState;
  Memory RAM;
  constexpr uint64_t getRegSystem(XReg R) { return RState->getRegSystem(R); }
  constexpr void     setRegSystem(XReg R, uint64_t V) { RState->setRegSystem(R, V); };
public:

  CPU(uint64_t EntryAddress, std::vector<uint8_t> RawElf) : PC(EntryAddress) { RAM.write(RawElf.data(), RawElf.size(), 0); }

  void execute() {
    assert(PC != UINT64_MAX);
    while(!Finished) {
      uint32_t RawInstr = 0;
      RAM.read(&RawInstr, sizeof(RawInstr), PC);
      
    }
  }

  constexpr uint64_t getPC() { return PC; };
  constexpr void setPC(uint64_t NewPC) { PC = NewPC; };

  constexpr uint64_t getReg(XReg R) { return  RState->getReg(R); };
  constexpr void     setReg(XReg R, uint64_t V) { RState->setReg(R, V); };

  constexpr uint64_t load(uint64_t Addr, int Bits) { return 0; };
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

} // namespace GeneralSim

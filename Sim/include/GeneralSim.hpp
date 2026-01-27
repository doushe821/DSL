#pragma once
#include <cassert>
#include <cstdint>
#include <cstring>

#include <array>
#include <memory>
#include <vector>

namespace GeneralSim {

static const size_t kMemorySize =
    UINT16_MAX; // TODO Make CLI-defined with defauly value

enum class ImmediateType : uint8_t { Unsigned, Signed };

class Immediate {
private:
  uint32_t RawValue = 0;
  uint16_t BitSize = 0;
  ImmediateType Type = ImmediateType::Unsigned;

  constexpr uint64_t sext(uint64_t Val, int N) const {
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

  constexpr uint64_t asSigned() const {
    assert(isSigned());
    return sext(RawValue, BitSize);
  }

  constexpr uint32_t asUnsigned() const {
    assert(isUnsigned());
    return RawValue;
  }

  constexpr void set(uint32_t Raw, uint8_t Bits, ImmediateType Type_) {
    RawValue = Raw;
    BitSize = Bits;
    Type = Type_;
  }
};

using XReg = uint16_t;

static inline uint32_t getMaskedValue(uint32_t Value, int StartBit,
                                      int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}

class RawMemory {
private:
  std::vector<uint8_t> RAM;

public:
  void write(const void *Source, unsigned N, unsigned DestinationAddress) {
    assert(Source && "Invalid source pointer\n");
    assert((DestinationAddress < kMemorySize &&
            DestinationAddress + N < kMemorySize) &&
           "Trying to write to unreachable address\n");
    memcpy(reinterpret_cast<char *>(RAM.data()) + DestinationAddress, Source,
           N);
  }

  void read(void *Destination, unsigned N, unsigned SourceAddress) const {
    assert(Destination && "Invalid destination pointer\n");
    assert((SourceAddress < kMemorySize && SourceAddress + N < kMemorySize) &&
           "Trying to read from unreachable address\n");
    memcpy(Destination,
           reinterpret_cast<const char *>(RAM.data()) + SourceAddress, N);
  }
};

class InterfaceMemory {
private:
  RawMemory Memory;
public:


};

class RegState;
class CPU {
private:
  uint64_t PC = UINT64_MAX;
  bool Finished{false};

  std::unique_ptr<RegState> RState;

public:
  CPU();
  ~CPU();

  uint32_t readReg(unsigned Idx) const;
  void writeReg(unsigned Idx, uint32_t Value);



  constexpr void syscall(int Code) {
    if (Code == 1) {
      Finished = true;
    } else {
      assert("Not implemented\n");
    }
  };

  constexpr int bitrev(int Val, int NBits = 32) { // Does it in log(n)
    assert(NBits <= 64);
    uint64_t Mask = (NBits == 64) ? ~0ULL : ((1ULL << NBits) - 1);
    Val &= Mask;

    for (int Step = 1; Step < NBits; Step <<= 1) {
      uint64_t M = ((1ULL << Step) - 1) | (((1ULL << Step) - 1) << (2 * Step));

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

  constexpr uint64_t zext(uint64_t V, unsigned N) {
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

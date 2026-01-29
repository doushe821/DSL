#pragma once
#include <cassert>
#include <catch2/internal/catch_clara.hpp>
#include <cstdint>
#include <cstring>
#include <memory>
#include <iostream>

#include "ExecContext.hpp"
#include "Memory.hpp"
#include "RegAliases.hpp"

namespace GeneralSim {

static inline uint32_t getMaskedValue(uint32_t Value, int StartBit,
                                      int FinishBit) {
  return (Value >> StartBit) & ((1 << (FinishBit - StartBit + 1)) - 1);
}

class RegState;
class CPU : ExecContext {
private:
  size_t MemoryLimit;
  size_t PC = UINT64_MAX;
  size_t OLD_PC = UINT64_MAX;
  bool PrettyMode{false};
  bool Finished{false};

  std::unique_ptr<RegState> RState;
  Memory Mem;

  size_t InstructionCounter = 0;

public:
  CPU(size_t MemoryLimit, bool IsPretty = false);
  ~CPU();

  void run() {
    setReg(RegAliases::sp, MemoryLimit);

    if (PrettyMode) {
      runPretty();
    } else {
      while (!Finished) {
        OLD_PC = PC;
        step();
        ++InstructionCounter;
      }
    }
    std::cout << "Finished!" << std::endl; // TODO add finish code or smth
  }

  void runPretty();
  void dumpState();
  
  void dumpPretty(Memory& PrevMem, std::unique_ptr<RegState>& PrevRegState);
  void stepPretty(Memory& PrevMem, std::unique_ptr<RegState>& PrevRegState);

  uint8_t  read8(uintptr_t Addr) override;
  uint16_t read16(uintptr_t Addr) override;
  uint32_t read32(uintptr_t Addr) override;
  uint64_t read64(uintptr_t Addr) override;

  void read128(uintptr_t Addr, uint8_t* Dest) override;
  void read256(uintptr_t Addr, uint8_t* Dest) override;

  void write8(uintptr_t Addr, uint8_t Value) override;
  void write16(uintptr_t Addr, uint16_t Value) override;
  void write32(uintptr_t Addr, uint32_t Value) override;
  void write64(uintptr_t Addr, uint64_t Value) override;

  void write128(uintptr_t Addr, const uint8_t* Src) override;
  void write256(uintptr_t Addr, const uint8_t* Src) override;

  uint32_t getPC() const override {
    return PC;
  }

  void setPC(uint32_t Value) override {
    PC = Value;
  }
  
  void step();

  // For loader only.
  // Yes, it is extremely unsafe.
  // So do not use it outside of loader.
  // Or use wisely.
  // But better don't.
  unsigned char* getRawMem() { return Mem.data(); }; // FIXME

  uint32_t getReg(XReg Idx) const override;
  void setReg(XReg Idx, uint32_t Value) override;

  void setEntry(size_t EntryPoint) { PC = EntryPoint; }

  constexpr void syscall() override {
    Finished = true;
  };

  constexpr int bitrev(int Val, int NBits = 32) override { // Does it in log(n)
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

  constexpr uint64_t sext(uint64_t Val, int64_t N) override {
      if (N <= 0 || N > 64) return Val;

      uint64_t top_bit = uint64_t(1) << (N - 1);
      
      if (Val & top_bit) {
          uint64_t mask = (N == 64) ? ~uint64_t(0) : ~((uint64_t(1) << N) - 1);
          Val |= mask;
      }
      return Val;
  }

  constexpr uint64_t zext(uint64_t V, int64_t N) override {
    assert(N <= 64);
    if (N == 64)
      return V;
    return V & ((1ULL << N) - 1);
  }

  constexpr int saturateUnsigned(unsigned Val, unsigned N) override {
    unsigned Limit = (1 << N) - 1;
    if (Val > Limit) {
      Val = Limit;
    }
    return Val;
  }
};

} // namespace GeneralSim

#pragma once
#include "ExecContext.hpp"
#include "GeneralSimTypes.hpp"
#include <cstdint>
#include <unordered_map>
namespace GeneralSim {
struct FakeExecContext : ExecContext {
    bool Finished{false};
    uint32_t regs[32]{};
    std::unordered_map<uint64_t,uint8_t> mem;
    uint64_t PC = 0;

    uint32_t getReg(XReg r) const override {
        if (r == 0) return 0; // x0 hardwired
        return regs[r];
    }

    void setReg(XReg r, uint32_t v) override {
        if (r == 0) return; // x0 ignored
        regs[r] = v;
    }

    uint32_t getPC() const override { return PC; }
    void setPC(uint32_t v) override { PC = v; }

    uint8_t  read8(uintptr_t addr) override { return mem[addr]; }
    uint16_t read16(uintptr_t addr) override { return mem[addr] | (mem[addr+1]<<8); }
    uint32_t read32(uintptr_t addr) override { return read16(addr) | (read16(addr+2)<<16); }
    uint64_t read64(uintptr_t addr) override { return uint64_t(read32(addr)) | (uint64_t(read32(addr+4))<<32); }
    void read128(uintptr_t Addr, uint8_t* Dest) override { for(int i=0;i<16;i++) Dest[i]=mem[Addr+i]; }
    void read256(uintptr_t Addr, uint8_t* Dest) override { for(int i=0;i<32;i++) Dest[i]=mem[Addr+i]; }

    void write8(uintptr_t addr, uint8_t v) override { mem[addr]=v; }
    void write16(uintptr_t addr, uint16_t v) override { write8(addr,v&0xFF); write8(addr+1,(v>>8)&0xFF); }
    void write32(uintptr_t addr, uint32_t v) override { write16(addr,v&0xFFFF); write16(addr+2,(v>>16)&0xFFFF); }
    void write64(uintptr_t addr, uint64_t v) override { write32(addr,v&0xFFFFFFFF); write32(addr+4,(v>>32)&0xFFFFFFFF); }
    void write128(uintptr_t Addr, const uint8_t* Src) override { for(int i=0;i<16;i++) mem[Addr+i]=Src[i]; }
    void write256(uintptr_t Addr, const uint8_t* Src) override { for(int i=0;i<32;i++) mem[Addr+i]=Src[i]; }


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
    return V & ((1ULL << N) - uint64_t(1));
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

#pragma once
#include <cstdint>
#include "GeneralSimTypes.hpp"
// TODO (big ) replace all uint32_t with reg size constant
// that should be generated somewhere.
namespace GeneralSim {

class ExecContext {
public:
  virtual ~ExecContext() = default;
  virtual uint8_t  read8(uintptr_t Addr) = 0;
  virtual uint16_t read16(uintptr_t Addr) = 0;
  virtual uint64_t read64(uintptr_t Addr) = 0;
  virtual uint32_t read32(uintptr_t Addr) = 0;
  virtual void read128(uintptr_t Addr, uint8_t* Dest) = 0;
  virtual void read256(uintptr_t Addr, uint8_t* Dest) = 0;

  virtual void write8(uintptr_t Addr, uint8_t Value) = 0;
  virtual void write16(uintptr_t Addr, uint16_t Value) = 0;
  virtual void write32(uintptr_t Addr, uint32_t Value) = 0;
  virtual void write64(uintptr_t Addr, uint64_t Value) = 0;
  virtual void write128(uintptr_t Addr, const uint8_t* Src) = 0;
  virtual void write256(uintptr_t Addr, const uint8_t* Src) = 0;
  
  virtual uint32_t getReg(XReg Idx) const = 0;
  virtual void setReg(XReg Idx, uint32_t Value) = 0;

  virtual uint32_t getPC() const = 0;
  virtual void setPC(uint32_t Value) = 0;

  virtual void syscall(int Code) = 0;

  virtual int bitrev(int Val, int NBits = 32) = 0;
  virtual constexpr uint64_t sext(uint64_t Val, int N) = 0;
  virtual constexpr uint64_t zext(uint64_t V, unsigned N) = 0;
  virtual constexpr int saturateUnsigned(unsigned Val, unsigned N) = 0;
};
} // namespace GeneralSim

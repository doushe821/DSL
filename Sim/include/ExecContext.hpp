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
  virtual uint32_t read32(uintptr_t Addr) = 0;
  virtual uint64_t read64(uintptr_t Addr) = 0;
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
  virtual bool isPCDirty() = 0;
  virtual void cleansePC() = 0;

  virtual uint32_t getPC() const = 0;
  virtual void setPC(uint32_t Value) = 0;

  virtual void syscall() = 0;

  virtual int bitrev(int Val, int NBits = 32) = 0;
  virtual constexpr uint64_t sext(uint64_t Val, int64_t N) = 0;
  virtual constexpr uint64_t zext(uint64_t V, int64_t N) = 0;
  virtual constexpr int saturateUnsigned(unsigned Val, unsigned N) = 0;
};

// Wrappers for JIT
// They are needed, because I don't want JIT to have Execution Context
// As it's meant to be owned by CPU only
// 
static inline uint32_t getPCWrapper(ExecContext* ctx) {
    return ctx->getPC();
}
static inline void setPCWrapper(ExecContext* ctx, uint32_t Val) {
    return ctx->setPC(Val);
}
static inline bool isPCDirtyWrapper(ExecContext *ctx) {
    return ctx->isPCDirty();
}
static inline void cleansePCWrapper(ExecContext *ctx) {
    ctx->cleansePC();
}
static inline uint32_t getRegWrapper(ExecContext* ctx, XReg Idx) {
    return ctx->getReg(Idx);
}
static inline void setRegWrapper(ExecContext* ctx, XReg Idx, uint32_t Val) {
    return ctx->setReg(Idx, Val);
}

static inline void write8(ExecContext* ctx, uintptr_t Addr, uint32_t Val) {
    return ctx->write8(Addr, Val);
}
static inline void write16(ExecContext* ctx, uintptr_t Addr, uint32_t Val) {
    return ctx->write16(Addr, Val);
}
static inline void write32(ExecContext* ctx, uintptr_t Addr, uint32_t Val) {
    return ctx->write32(Addr, Val);
}
static inline void write64(ExecContext* ctx, uintptr_t Addr, uint32_t Val) {
    return ctx->write64(Addr, Val);
}
static inline void write128(ExecContext* ctx, uintptr_t Addr, const uint8_t* Src) {
    return ctx->write128(Addr, Src);
}
static inline void write256(ExecContext* ctx, uintptr_t Addr, const uint8_t* Src) {
    return ctx->write256(Addr, Src);
}

static inline uint64_t sextWrapper(ExecContext* ctx, uint64_t Val, int64_t N) {
    return ctx->sext(Val, N);
}

static inline uint8_t read8(ExecContext* ctx, uintptr_t Addr) {
    return ctx->read8(Addr);
}
static inline uint16_t read16(ExecContext* ctx, uintptr_t Addr) {
    return ctx->read16(Addr);
}
static inline uint32_t read32(ExecContext* ctx, uintptr_t Addr) {
    return ctx->read32(Addr);
}
static inline uint64_t read64(ExecContext* ctx, uintptr_t Addr) {
    return ctx->read64(Addr);
}
static inline void read128(ExecContext* ctx, uintptr_t Addr,  uint8_t* Dest) {
    return ctx->read128(Addr, Dest);
}
static inline void read256(ExecContext* ctx, uintptr_t Addr,  uint8_t* Dest) {
    return ctx->read256(Addr, Dest);
}
static inline void syscall(ExecContext* Ctx) {
    return Ctx->syscall();
}

  

} // namespace GeneralSim

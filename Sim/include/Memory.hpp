#pragma once

#include <cinttypes>
#include <cstdint>
#include <memory>
#include <vector>

namespace GeneralSim {
class Memory {
public:
  Memory(size_t InitSize);
  ~Memory();

  uint8_t  read8(uintptr_t Addr) const;
  uint16_t read16(uintptr_t Addr) const;
  uint32_t read32(uintptr_t Addr) const;
  uint64_t read64(uintptr_t Addr) const;
  void read128(uintptr_t Addr, uint8_t* Dest) const;
  void read256(uintptr_t Addr, uint8_t* Dest) const;

  void write8(uintptr_t Addr, uint8_t Value);
  void write16(uintptr_t Addr, uint16_t Value);
  void write32(uintptr_t Addr, uint32_t Value);
  void write64(uintptr_t Addr, uint64_t Value);
  void write128(uintptr_t Addr, const uint8_t* Src);
  void write256(uintptr_t Addr, const uint8_t* Src);

    uint8_t* data();
    const uint8_t* data() const;

  size_t size() const;

private:
  struct Impl;
  std::unique_ptr<Impl> MemImpl;
};
} // namespace GeneralSim

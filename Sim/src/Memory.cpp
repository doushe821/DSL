#include "Memory.hpp"
#include <vector>
#include <cassert>
#include <cstring> // for memcpy

namespace GeneralSim {
GeneralSim::Memory::Memory(size_t size) : MemImpl(std::make_unique<Impl>(size)) {}
Memory::~Memory() = default;
struct Memory::Impl {
    explicit Impl(size_t sz) : Mem(sz, 0) {}
    std::vector<uint8_t> Mem;
};

// For loader only.
uint8_t* Memory::data() { return MemImpl->Mem.data(); }
const uint8_t* Memory::data() const { return MemImpl->Mem.data(); }

uint8_t Memory::read8(uintptr_t Addr) const {
    assert(Addr < MemImpl->Mem.size());
    return MemImpl->Mem[Addr];
}

uint16_t Memory::read16(uintptr_t Addr) const {
    assert(Addr + 1 < MemImpl->Mem.size());
    return MemImpl->Mem[Addr] | (MemImpl->Mem[Addr+1] << 8);
}

uint32_t Memory::read32(uintptr_t Addr) const {
    assert(Addr + 3 < MemImpl->Mem.size());
    return MemImpl->Mem[Addr] |
           (MemImpl->Mem[Addr+1] << 8) |
           (MemImpl->Mem[Addr+2] << 16) |
           (MemImpl->Mem[Addr+3] << 24);
}

uint64_t Memory::read64(uintptr_t Addr) const {
    assert(Addr + 7 < MemImpl->Mem.size());
    uint64_t lo = read32(Addr);
    uint64_t hi = read32(Addr + 4);
    return lo | (hi << 32);
}

void Memory::read128(uintptr_t Addr, uint8_t* dest) const {
    assert(Addr + 15 < MemImpl->Mem.size());
    std::memcpy(dest, &MemImpl->Mem[Addr], 16);
}

void Memory::read256(uintptr_t Addr, uint8_t* dest) const {
    assert(Addr + 31 < MemImpl->Mem.size());
    std::memcpy(dest, &MemImpl->Mem[Addr], 32);
}

void Memory::write8(uintptr_t Addr, uint8_t Value) {
    assert(Addr < MemImpl->Mem.size());
    MemImpl->Mem[Addr] = Value;
}

void Memory::write16(uintptr_t Addr, uint16_t Value) {
    assert(Addr + 1 < MemImpl->Mem.size());
    MemImpl->Mem[Addr]     = Value & 0xFF;
    MemImpl->Mem[Addr + 1] = (Value >> 8) & 0xFF;
}

void Memory::write32(uintptr_t Addr, uint32_t Value) {
    assert(Addr + 3 < MemImpl->Mem.size());
    MemImpl->Mem[Addr]     = Value & 0xFF;
    MemImpl->Mem[Addr + 1] = (Value >> 8) & 0xFF;
    MemImpl->Mem[Addr + 2] = (Value >> 16) & 0xFF;
    MemImpl->Mem[Addr + 3] = (Value >> 24) & 0xFF;
}

void Memory::write64(uintptr_t Addr, uint64_t Value) {
    assert(Addr + 7 < MemImpl->Mem.size());
    write32(Addr, static_cast<uint32_t>(Value & 0xFFFFFFFF));
    write32(Addr + 4, static_cast<uint32_t>(Value >> 32));
}

void Memory::write128(uintptr_t Addr, const uint8_t* Src) {
    assert(Addr + 15 < RawMemory.size());
    std::memcpy(&MemImpl->Mem[Addr], Src, 16);
}

void Memory::write256(uintptr_t Addr, const uint8_t* src) {
    assert(Addr + 31 < MemImpl->Mem.size());
    std::memcpy(&MemImpl->Mem[Addr], src, 32);
}

} // namespace GeneralSim

// cpu.cpp
#include <bit>
#include <iostream>
#include <memory>

#include "Decoder.hpp"
#include "Executor.hpp"
#include "GeneralSim.hpp"
#include "RegState.hpp"
namespace GeneralSim {

CPU::CPU(size_t MemoryLimit_)
    : MemoryLimit(MemoryLimit_), RState(std::make_unique<RegState>()),
      Mem(MemoryLimit) {}
CPU::~CPU() = default;

uint32_t CPU::getReg(XReg Idx) const { return RState->read(Idx); }

void CPU::setReg(XReg Idx, uint32_t Value) { RState->write(Idx, Value); }

void CPU::step() {
  if (Finished) {
    return;
  }
  Decoder::Decoder Dcdr;
  GeneralSim::Executor Extr;
  auto RawInstr = Mem.read32(PC);
  std::cout << "Fetched raw instruction: " << RawInstr << std::endl;
  auto DecodedInstr = Dcdr.decode(RawInstr);

  // Implicit upcast from CPU to ExecContext here.
  // std::cout << DecodedInstr.
  Extr.execute(DecodedInstr, *this);
  // If branch was taken, PC should not be changed
  // by CPU.
  if (OLD_PC == PC) {
    PC += 4;
    OLD_PC = PC;
  }
  dumpState();
}

uint8_t CPU::read8(uintptr_t Addr) { return Mem.read8(Addr); }

uint16_t CPU::read16(uintptr_t Addr) { return Mem.read16(Addr); }

uint32_t CPU::read32(uintptr_t Addr) { return Mem.read32(Addr); }

uint64_t CPU::read64(uintptr_t Addr) { return Mem.read64(Addr); }

void CPU::read128(uintptr_t Addr, uint8_t *Dest) { Mem.read128(Addr, Dest); }

void CPU::read256(uintptr_t Addr, uint8_t *Dest) { Mem.read256(Addr, Dest); }

void CPU::write8(uintptr_t Addr, uint8_t Value) { Mem.write8(Addr, Value); }
void CPU::write16(uintptr_t Addr, uint16_t Value) { Mem.write16(Addr, Value); }
void CPU::write32(uintptr_t Addr, uint32_t Value) { Mem.write32(Addr, Value); }
void CPU::write64(uintptr_t Addr, uint64_t Value) { Mem.write64(Addr, Value); }

void CPU::write128(uintptr_t Addr, const uint8_t *Src) {
  Mem.write128(Addr, Src);
}
void CPU::write256(uintptr_t Addr, const uint8_t *Src) {
  Mem.write256(Addr, Src);
}

void CPU::dumpState() {
  for (size_t I = 0; I < RState->NUM_REGS; ++I) {
    auto RegVal = RState->read(I);
    std::cout << "Reg" << I << " = " << RegVal
              << " (unsigned) : " << std::bit_cast<int32_t>(RegVal)
              << " (signed)" << std::endl;
  }
  std::cout << "PC = " << PC << std::endl;
}

} // namespace GeneralSim

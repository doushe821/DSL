// cpu.cpp
#include <bit>
#include <iostream>
#include <memory>

#include "Decoder.hpp"
#include "Executor.hpp"
#include "GeneralSim.hpp"
#include "Memory.hpp"
#include "RegState.hpp"
namespace GeneralSim {

CPU::CPU(size_t MemoryLimit_, bool IsPretty)
    : MemoryLimit(MemoryLimit_), PrettyMode(IsPretty),
      RState(std::make_unique<RegState>()), Mem(MemoryLimit) {}
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
  std::cout << "Fetched raw instruction: " << std::hex << RawInstr << std::endl;
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
  std::cout << "# " << InstructionCounter << ".\n";

  dumpState();
}

void CPU::runPretty() {
  auto PrevRegState(std::make_unique<RegState>());
  Memory PrevMemState(MemoryLimit);
  setReg(RegAliases::sp, MemoryLimit);
  PrevRegState->write(RegAliases::sp, MemoryLimit);
  OLD_PC = PC;

  while (!Finished) {
    stepPretty(PrevMemState, PrevRegState);
    ++InstructionCounter;
  }

  std::cout << "Finished!" << std::endl; // TODO add finish code or smth
  std::cout << "Return values: " << std::dec << RState->read(RegAliases::ret0)
            << ", " << std::dec << RState->read(RegAliases::ret1) << std::endl;
}

void CPU::stepPretty(Memory &PrevMem, std::unique_ptr<RegState> &PrevRegState) {
  if (Finished) {
    return;
  }

  Decoder::Decoder Dcdr;
  GeneralSim::Executor Extr;
  auto RawInstr = Mem.read32(PC);
  std::cout << "\n### " << std::dec << InstructionCounter << ".\n";
  std::cout << "### Fetched raw instruction: 0x" << std::hex << RawInstr
            << std::endl;
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

  dumpPretty(PrevMem, PrevRegState);
}

void CPU::dumpPretty(Memory &PrevMem, std::unique_ptr<RegState> &PrevRegState) {
  for (size_t I = 0; I < RState->NUM_REGS; ++I) {
    auto RegVal = RState->read(I);
    auto PrevRegVal = PrevRegState->read(I);
    if (RegVal != PrevRegVal) {
      std::cout << "# Reg" << std::dec << I << " changed: 0x" << std::hex
                << PrevRegVal << std::dec << " -> 0x" << std::hex << RegVal
                << std::endl;
      PrevRegState->write(I, RegVal);
    }
  }

  for (size_t I = 0; I < MemoryLimit / 4; I += 4) {
    auto NewMemWord = Mem.read32(I);
    auto OldMemWord = PrevMem.read32(I);
    if (NewMemWord != OldMemWord) {
      std::cout << "# Memory changed on address 0x" << I << ": 0x" << std::hex
                << OldMemWord << " -> 0x" << std::hex << NewMemWord
                << std::endl;
      PrevMem.write32(I, NewMemWord);
    }
  }
  std::cout << "## PC = " << PC << "\n\n";
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

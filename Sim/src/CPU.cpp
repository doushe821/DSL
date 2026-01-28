// cpu.cpp
#include "ExecContext.hpp"
#include "Executor.hpp"
#include "GeneralSim.hpp"
#include "RegState.hpp"
#include <memory>
namespace GeneralSim {

CPU::CPU(size_t MemoryLimit_)
    : MemoryLimit(MemoryLimit_), RState(std::make_unique<RegState>()),
      Mem(MemoryLimit) {}
CPU::~CPU() = default;

uint32_t CPU::readReg(unsigned Idx) const { return RState->read(Idx); }

void CPU::writeReg(unsigned Idx, uint32_t Value) { RState->write(Idx, Value); }



void CPU::step() {
  if(Finished) {
    return;
  }
  GeneralSim::Decoder Dcdr;
  GeneralSim::Executor Extr;
  auto RawInstr = Mem.read32(PC);
  auto DecodedInstr = Dcdr.decode(RawInstr);
  // Implicit upcast here
  Extr.execute(DecodedInstr, *this);
  // If branch was taken, PC should not be changed
  // by CPU.
  PC += 4 * (OLD_PC == PC);
}

} // namespace GeneralSim

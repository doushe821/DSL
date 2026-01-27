// cpu.cpp
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

} // namespace GeneralSim

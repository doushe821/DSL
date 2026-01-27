// cpu.cpp
#include "GeneralSim.hpp"
#include "RegState.hpp"

namespace GeneralSim {

CPU::CPU() : RState(std::make_unique<RegState>()) {}
CPU::~CPU() = default;

uint32_t CPU::readReg(unsigned Idx) const {
    return RState->read(Idx);
}

void CPU::writeReg(unsigned Idx, uint32_t Value) {
    RState->write(Idx, Value);
}

} // namespace GeneralSim

#include "RegState.hpp"
namespace GeneralSim {
RegState::RegState() {
    Regs[0] = 0;
    Regs[1] = 0;
    Regs[2] = 0;
    Regs[3] = 0;
    Regs[4] = 0;
    Regs[5] = 0;
    Regs[6] = 0;
    Regs[7] = 0;
    Regs[8] = 0;
    Regs[9] = 0;
    Regs[10] = 0;
    Regs[11] = 0;
    Regs[12] = 0;
    Regs[13] = 0;
    Regs[14] = 0;
    Regs[15] = 0;
    Regs[16] = 0;
    Regs[17] = 0;
    Regs[18] = 0;
    Regs[19] = 0;
    Regs[20] = 0;
    Regs[21] = 0;
    Regs[22] = 0;
    Regs[23] = 0;
    Regs[24] = 0;
    Regs[25] = 0;
    Regs[26] = 0;
    Regs[27] = 0;
    Regs[28] = 0;
    Regs[29] = 0;
    Regs[30] = 0;
    Regs[31] = 0;
}

RegState::reg_t RegState::read(unsigned Idx) const {
    assert(Idx < NUM_REGS);
    return Regs[Idx];
}

void RegState::write(unsigned Idx, reg_t Value) {
    assert(Idx < NUM_REGS);
    if (!IsConst[Idx]) {
        Regs[Idx] = Value;
    }
}
} // namespace GeneralSim

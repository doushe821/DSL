#pragma once
#include <cstdint>
#include <cassert>

namespace GeneralSim {
static constexpr uint64_t NUM_REGS = 32;
using reg_t = uint32_t;
class RegState { // TODO Check invariants
private:
    alignas(32) reg_t Regs[NUM_REGS];
public:
    using reg_t = uint32_t; // TODO Expand

    RegState();
    
    reg_t read(unsigned Idx) const;
    void write(unsigned Idx, reg_t Value);
    reg_t* raw() { return Regs; }
    // constant registers
    static constexpr bool IsConst[NUM_REGS] = {
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
};

static constexpr reg_t ConstValue[NUM_REGS] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
};
} // namespace GeneralSim

#pragma once
#include <cstdint>
#include <cstddef>
#include <array>
#include <cassert>
namespace GeneralSim {
class RegState {
public:
    using reg_t = uint32_t; // TODO Expand
    static constexpr size_t NUM_REGS = 32;

    RegState();
    
    reg_t read(unsigned Idx) const;
    void write(unsigned Idx, reg_t Value);

private:
    alignas(32) reg_t Regs[NUM_REGS];

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

static constexpr reg_t const_value[NUM_REGS] = {
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

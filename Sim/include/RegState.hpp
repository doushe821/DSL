#pragma once
#include <cstdint>
#include <cassert>

#include "RegLayout.hpp"
namespace GeneralSim {
class RegState : public RegLayout { // FIXME should not be public, debug only
public:
    using reg_t = uint32_t; // TODO Expand

    RegState();
    
    reg_t read(unsigned Idx) const;
    void write(unsigned Idx, reg_t Value);

private:
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

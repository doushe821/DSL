#pragma once 
#include <cstdint>
using reg_t = uint32_t;
namespace GeneralSim {
static constexpr uint64_t NUM_REGS = 32;
struct RegLayout {
  alignas(32) reg_t Regs[NUM_REGS];
};
} // namespace GeneralSim

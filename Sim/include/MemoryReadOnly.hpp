#pragma once
#include <cstdint>

namespace GeneralSim {
struct MemoryView {
    virtual uint32_t read32(uintptr_t addr) const = 0;
    virtual ~MemoryView() = default;
};

} // namespace GeneralSim

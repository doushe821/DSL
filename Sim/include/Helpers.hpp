#pragma once
#include <cstdint>
namespace GeneralSim::Helpers {

static inline uint32_t sext(uint32_t v, unsigned bits) {
    const uint32_t shift = 32 - bits;
    return (int32_t)(v << shift) >> shift;
}

static inline uint32_t zext(uint32_t v, unsigned bits) {
    return v & ((1u << bits) - 1);
}

}

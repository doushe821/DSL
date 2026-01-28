# pragma once

#include "Instructions.hpp"

namespace Decoder {
class Decoder {
public:
  Instruction decode(uint32_t Instr);

  uint8_t getInstSize(const Instruction& DecodedInstr) const {
    return 4; // For future.
  }
};

} // namespace Decoder

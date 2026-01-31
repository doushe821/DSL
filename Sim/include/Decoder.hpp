# pragma once

#include "Instructions.hpp"

namespace Decoder {
class Decoder {
public:
  Instruction decode(uint32_t Instr) const;
};

} // namespace Decoder

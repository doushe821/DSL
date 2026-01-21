#pragma once
#include "GeneralSim.hpp"

namespace RISC_V_Decoder {

  enum class InstructionFormats : uint64_t {
    R = 51,
  };

  const int OpCodeStartBit = 0;
  const int OpCodeFinishBit = 6;
  void decode(uint32_t BinInstruction);

} // namespace RISC_V_Decoder

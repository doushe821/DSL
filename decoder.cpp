#include "decoder.hpp"

namespace RISC_V_Decoder {

  void decode(uint32_t BinInstruction) {
    auto OpCode = GeneralSim::getMaskedValue(BinInstruction, OpCodeStartBit, OpCodeFinishBit);
    switch (static_cast<InstructionFormats>(OpCode)) {
      case InstructionFormats::R: {
        
      }
    }
  }
} // namespace RISC_V_Decoder

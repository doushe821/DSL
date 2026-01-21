require_relative "../../Generic/base"
require_relative "encoding"
require_relative "regfile"

module SimInfra

class DecoderGenerator
  def self.generate(filename)

    decoder_hpp =
"#pragma once
#include \"GeneralSim.hpp\"\n
namespace RISC_V_Decoder {\n
  enum class InstructionFormats : uint64_t {\n"
    OPCODES.each do |opcode|
      decoder_hpp += "    #{opcode[0].to_s} = #{opcode[1].to_s},\n"
    end
    decoder_hpp += "  };\n\n"
  decoder_hpp +=
"  const int OpCodeStartBit = 0;
  const int OpCodeFinishBit = 6;
  void decode(uint32_t BinInstruction);\n"

   decoder_cpp =
"#include \"decoder.hpp\"\n
namespace RISC_V_Decoder {\n
  void decode(uint32_t BinInstruction) {
    auto OpCode = GeneralSim::getMaskedValue(BinInstruction, OpCodeStartBit, OpCodeFinishBit);
    switch (static_cast<InstructionFormats>(OpCode)) {
      case InstructionFormats::R: {

      }
    }
  }"
    decoder_cpp += "\n} // namespace RISC_V_Decoder\n"

    decoder_hpp += "\n} // namespace RISC_V_Decoder\n"
    File.write("decoder.hpp", decoder_hpp)
    File.write("decoder.cpp", decoder_cpp)
  end
end
    # TODO: generate enum with all encoding formats somewhere
    # TODO: generate enum with all insturctions somerhewe
end

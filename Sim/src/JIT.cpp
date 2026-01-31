#include "JIT.hpp"
#include "Instructions.hpp"
#include <cstdint>
#include <vector>
namespace SimJIT {
  TranslatedBlock JIT::translate(size_t PC)  {
    TranslatedBlock TB;
    TB.StartPC = PC;
    std::vector<Instruction> Block; // FIXME fix namespaces pleaaasse
    // Translate block:
    while (true) {
      uint32_t Raw = Ctx.read32(PC);
      auto Inst = Decoder.decode(Raw);
      Block.push_back(Inst);
      
      auto OP = getOpcode(Inst);
      PC += instSize(OP);

      if (isTerminator(OP)) {
        break;
      }
    }

    // asmjit setup
    asmjit::CodeHolder Code;
    Code.init(Rt.environment());

    asmjit::x86::Compiler CC(&Code);

    // emition
    for (auto& Inst : Block) {
        emitInstruction(); // TODO
    }

    // return PCC

    
    
    // return PC
    CC.endFunc();
    CC.finalize();

    BlockFn Fn;
    Rt.add(&Fn, &Code);

    TB.EndPC =  PC;
    TB.Fn = Fn;
    return TB;
  }
} // namesace SimJIT

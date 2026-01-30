#include "JIT.hpp"
#include "Instructions.hpp"
#include <cstdint>
#include <vector>
namespace SimJIT {
  TranslatedBlock JIT::transalte(size_t PC, asmjit::x86::Gp  СtxReg)  {
    TranslatedBlock TB;
    TB.StartPC = PC;
    std::vector<Instruction> Block; // FIXME fix namespaces pleaaasse
    // Translate block:
    while (true) {
      uint32_t Raw = MV.read32(PC);
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
        emitInstruction(CC,  СtxReg, Inst);
    }

    // Pass PC as return value
    asmjit::x86::Gp PCReg = CC.newUInt32();
    emitGetPC(CC,  СtxReg, PCReg);
    CC.ret(PCReg);

    CC.endFunc();
    CC.finalize();

    BlockFn Fn;
    Rt.add(&Fn, &Code);

    TB.EndPC =  PC;
    TB.Fn = Fn;
    return TB;
  }
} // namesace SimJIT

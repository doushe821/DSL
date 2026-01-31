#include "JIT.hpp"
#include "ExecContext.hpp"
#include "Instructions.hpp"
#include <asmjit/core/compiler.h>
#include <asmjit/core/func.h>
#include <asmjit/x86/x86operand.h>
#include <cstdint>
#include <vector>
namespace SimJIT {
TranslatedBlock JIT::translate(size_t PC) {
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

  asmjit::FuncNode *Func =
      CC.addFunc(asmjit::FuncSignatureT<uint32_t, GeneralSim::ExecContext *>(
          asmjit::CallConvId::kCDecl));

  asmjit::x86::Gp CtxReg = CC.newIntPtr();
  Func->setArg(0, CtxReg);
  asmjit::x86::Gp PcReg = CC.newUInt32();

  emitGetPC(CC, CtxReg, PcReg);

  // emition
  for (auto &Inst : Block) {
    emitInstruction(); // TODO
  }
  
  // TOODOOO
  CC.ret(PcReg);
  CC.endFunc();
  CC.finalize();

  BlockFn Fn;
  Rt.add(&Fn, &Code);

  TB.EndPC = PC;
  TB.Fn = Fn;
  return TB;
}

void emitGetPC(asmjit::x86::Compiler &CC, asmjit::x86::Gp CtxReg,
               asmjit::x86::Gp DestReg) {

  asmjit::FuncSignatureT<uint32_t, GeneralSim::ExecContext *> Sig(
      asmjit::CallConvId::kCDecl);

  asmjit::InvokeNode *Invoke;
  CC.invoke(&Invoke, asmjit::imm(&GeneralSim::getPCWrapper), Sig);

  Invoke->setArg(0, CtxReg);
  Invoke->setRet(0, DestReg);
}
} // namespace SimJIT

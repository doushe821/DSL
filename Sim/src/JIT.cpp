#include <asmjit/core/compiler.h>
#include <asmjit/core/func.h>
#include <asmjit/x86/x86operand.h>
#include <cstdint>
#include <vector>

#include "ExecContext.hpp"
#include "Instructions.hpp"
#include "JIT.hpp"


// TODO direct reg access in JIT
// TODO local pco
extern "C" void debug_print1(const char *msg) { printf("[JIT] %s\n", msg); }
namespace SimJIT {
TranslatedBlock JIT::translate(size_t PC) {
  TranslatedBlock TB;
  TB.StartPC = PC;
  std::vector<Instruction> Block;
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

  // Block prelude:
  // Setting args for emitter function
  // Getting ptr to regstate for direct access.
  // Getting local copy of PC that will be used by exec functions

  asmjit::FuncNode *Func =
      CC.addFunc(asmjit::FuncSignatureT<void, GeneralSim::ExecContext *,
                                        GeneralSim::RegLayout *>(
          asmjit::CallConvId::kCDecl));

  asmjit::x86::Gp CtxReg = CC.newIntPtr();
  Func->setArg(0, CtxReg);

  asmjit::x86::Gp RegArrayPtr = CC.newIntPtr();
  Func->setArg(1, RegArrayPtr);

  // Initialize local PC
  asmjit::x86::Mem LocalPc = CC.newStack(4, 4);
  CC.mov(LocalPc, TB.StartPC);

  // Initialize local pc dirty
  asmjit::x86::Mem LocalPcDirty = CC.newStack(4, 4);
  CC.mov(LocalPcDirty, 0);

  // emition
  for (auto &Inst : Block) {
    emitInstruction(CC, CtxReg, RegArrayPtr, LocalPc, LocalPcDirty, Inst);
    CC.add(LocalPc, 4);
  }

  // Block epilogue:
  // Adjust PC according to LocalPcDirty

  asmjit::x86::Gp LocalPcReg = CC.newUInt32();
  CC.mov(LocalPcReg, LocalPc);

  asmjit::Label LDone = CC.newLabel();

  CC.cmp(LocalPcDirty, 0);
  CC.jz(LDone);

  CC.sub(LocalPcReg, 4); // 1 excessive PC incrementation if branch were taken.

  CC.bind(LDone);

  emitSetPC(CC, CtxReg,
            LocalPcReg); // Pc is already correct if no branches were taken

  CC.endFunc();
  CC.finalize();

  BlockFn Fn;
  Rt.add(&Fn, &Code);

  TB.EndPC = PC;
  TB.Fn = Fn;
  Cache[TB.StartPC] = TB;
  return TB;
}

void JIT::emitGetPC(asmjit::x86::Compiler &CC, asmjit::x86::Gp CtxReg,
                    asmjit::x86::Gp DestReg) {

  asmjit::InvokeNode *Invoke;
  CC.invoke(&Invoke, asmjit::imm(&GeneralSim::getPCWrapper),
            asmjit::FuncSignatureT<uint32_t, GeneralSim::ExecContext *>(
                asmjit::CallConvId::kCDecl));

  Invoke->setArg(0, CtxReg);
  Invoke->setRet(0, DestReg);
}

void JIT::emitSetPC(asmjit::x86::Compiler &CC, asmjit::x86::Gp CtxReg,
                    asmjit::x86::Gp SrcReg) {

  asmjit::InvokeNode *Invoke;
  CC.invoke(&Invoke, asmjit::imm(&GeneralSim::setPCWrapper),
            asmjit::FuncSignatureT<void, GeneralSim::ExecContext *, uint32_t>(
                asmjit::CallConvId::kCDecl));

  Invoke->setArg(0, CtxReg);
  Invoke->setArg(1, SrcReg);
}

} // namespace SimJIT

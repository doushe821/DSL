#include <asmjit/core/compiler.h>
#include <asmjit/core/func.h>
#include <asmjit/core/operand.h>
#include <asmjit/x86/x86operand.h>
#include <cstdint>
#include <vector>

#include "ExecContext.hpp"
#include "Instructions.hpp"
#include "JIT.hpp"
#include "RegState.hpp"

namespace SimJIT {
TranslatedBlock JIT::translate(size_t PC, const GeneralSim::RegState &RState) {
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
  asmjit::FuncNode *Func = CC.addFunc(
      asmjit::FuncSignatureT<void, GeneralSim::ExecContext *, reg_t *>(
          asmjit::CallConvId::kCDecl));

  asmjit::x86::Gp CtxReg = CC.newIntPtr();
  Func->setArg(0, CtxReg);

  asmjit::x86::Gp RegArrayPtr = CC.newIntPtr();
  Func->setArg(1, RegArrayPtr);

  // Initialize local PC
  asmjit::x86::Gp LocalPc = CC.newUInt32();

  CC.mov(LocalPc, asmjit::imm(uint32_t(TB.StartPC)));

  for (auto &Inst : Block) {
    emitInstruction(CC, CtxReg, RegArrayPtr, LocalPc, Inst, RState);
    auto OP = getOpcode(Inst);
    CC.add(LocalPc, asmjit::imm(instSize(OP)));
  }

  // Block epilogue:
  // Adjust PC according to LocalPcDirty
  asmjit::x86::Gp ExpectedPc = CC.newUInt32();
  CC.mov(ExpectedPc, PC);
  CC.sub(ExpectedPc, LocalPc);

  asmjit::Label LDone = CC.newLabel();
  CC.test(ExpectedPc, ExpectedPc);
  CC.jz(LDone);

  CC.sub(LocalPc,
         asmjit::imm(4)); // 1 excessive PC incrementation if branch were taken.

  CC.bind(LDone);

  emitSetPC(CC, CtxReg, LocalPc);

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

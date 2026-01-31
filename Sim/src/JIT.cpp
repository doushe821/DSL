#include "JIT.hpp"
#include "ExecContext.hpp"
#include "Instructions.hpp"
#include <asmjit/core/compiler.h>
#include <asmjit/core/func.h>
#include <asmjit/x86/x86operand.h>
#include <cstdint>
#include <vector>

extern "C" void debug_print1(const char *msg) { printf("[JIT] %s\n", msg); }
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
      CC.addFunc(asmjit::FuncSignatureT<void, GeneralSim::ExecContext *>(
          asmjit::CallConvId::kCDecl));

  asmjit::x86::Gp CtxReg = CC.newIntPtr();
  Func->setArg(0, CtxReg);

  // Block prelude:
  asmjit::x86::Gp LocalPc = CC.newUInt32();
  emitGetPC(CC, CtxReg, LocalPc);
  CC.add(LocalPc, PC - TB.StartPC - 4);
  emitSetPC(CC, CtxReg, LocalPc);

  asmjit::InvokeNode *ClearDirty;

  CC.invoke(&ClearDirty, asmjit::imm(&GeneralSim::cleansePCWrapper),
            asmjit::FuncSignatureT<void, GeneralSim::ExecContext *>(
                asmjit::CallConvId::kCDecl));
  ClearDirty->setArg(0, CtxReg);

  // asmjit::x86::Gp InitialPc;
  // emitGetPC(CC, CtxReg, InitialPc);

  // emition
  for (auto &Inst : Block) {
    emitInstruction(CC, CtxReg, Inst);
  }

  // Block epilogue:
  asmjit::x86::Gp PCDirty = CC.newUInt8();
  asmjit::InvokeNode *IsDirtyNode;
  CC.invoke(&IsDirtyNode, asmjit::imm(&GeneralSim::isPCDirtyWrapper),
            asmjit::FuncSignatureT<bool, GeneralSim::ExecContext *>(
                asmjit::CallConvId::kCDecl));
  IsDirtyNode->setArg(0, CtxReg);
  IsDirtyNode->setRet(0, PCDirty);

  asmjit::Label LDone = CC.newLabel();
  CC.test(PCDirty, PCDirty);
  CC.jnz(LDone);
  asmjit::x86::Gp Pc = CC.newUInt32();
  emitGetPC(CC, CtxReg, Pc);

  CC.add(Pc, 4); // increment if not dirty
  asmjit::InvokeNode *SetPC;
  CC.invoke(&SetPC, asmjit::imm(&GeneralSim::setPCWrapper),
            asmjit::FuncSignatureT<void, GeneralSim::ExecContext *, uint32_t>(
                asmjit::CallConvId::kCDecl));
  SetPC->setArg(0, CtxReg);
  SetPC->setArg(1, Pc);
  
  CC.bind(LDone);

  CC.endFunc();
  CC.finalize();

  BlockFn Fn;
  Rt.add(&Fn, &Code);

  TB.EndPC = PC;
  TB.Fn = Fn;
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

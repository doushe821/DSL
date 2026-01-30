#pragma once

#include <asmjit/asmjit.h>
#include <cstdint>
#include <unordered_map>

#include "Decoder.hpp"
#include "ExecContext.hpp"
#include "GeneralSimTypes.hpp"
#include "MemoryReadOnly.hpp"

namespace SimJIT {

using BlockFn = uint32_t (*)(GeneralSim::ExecContext *);
struct TranslatedBlock {
  BlockFn Fn;
  size_t StartPC;
  size_t EndPC;
};
class JIT {
public:
  explicit JIT(const Decoder::Decoder &Decoder_,
               const GeneralSim::MemoryView &MV);
  ~JIT() = default;

  bool hasBlock(size_t PC) const;
  const TranslatedBlock &getBlock(size_t PC) const;
  TranslatedBlock transalte(size_t PC, asmjit::x86::Gp  СtxReg);

  BlockFn compileBlock(uint32_t Pc);
  uint32_t executeBlock(uint32_t Pc, GeneralSim::ExecContext &Ctx);

private:
  void emitInstruction(asmjit::x86::Compiler &CC, asmjit::x86::Gp  СtxReg,
                       const Instruction &Inst);
  void emitGetPC(asmjit::x86::Compiler &CC, asmjit::x86::Gp  СtxReg,
                 asmjit::x86::Gp Dest) {
    CC.mov(asmjit::x86::rcx,  СtxReg);
    CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
    CC.mov(Dest, asmjit::x86::eax);
  }

  const Decoder::Decoder &Decoder;
  const GeneralSim::MemoryView &MV;
  std::unordered_map<uint32_t, BlockFn> Cache;
  asmjit::JitRuntime Rt;
};

} // namespace SimJIT

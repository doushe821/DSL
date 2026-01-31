#pragma once

#include <asmjit/asmjit.h>
#include <cstdint>
#include <unordered_map>

#include "Decoder.hpp"
#include "ExecContext.hpp"

namespace SimJIT {

using BlockFn = uint32_t (*)(GeneralSim::ExecContext *);
struct TranslatedBlock {
  BlockFn Fn;
  size_t StartPC;
  size_t EndPC;
};
class JIT {
public:
  explicit JIT(const Decoder::Decoder &Decoder_, GeneralSim::ExecContext &Ctx_)
      : Ctx(Ctx_), Decoder(Decoder_){};
  ~JIT() = default;

  bool hasBlock(size_t PC) const { return Cache.contains(PC); };
  const TranslatedBlock &getBlock(size_t PC) const { return Cache.at(PC); };
  TranslatedBlock translate(size_t PC);

private:
  void emitInstruction(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, Instruction Instr);
  void emitGetPC(asmjit::x86::Compiler &CC, asmjit::x86::Gp CtxReg,
                 asmjit::x86::Gp DestReg);
  GeneralSim::ExecContext &Ctx;
  const Decoder::Decoder &Decoder;
  std::unordered_map<uint32_t, TranslatedBlock> Cache;
  asmjit::JitRuntime Rt;
};

} // namespace SimJIT

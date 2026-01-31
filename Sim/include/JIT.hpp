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
  explicit JIT(const Decoder::Decoder &Decoder_, GeneralSim::ExecContext &Ctx_) : Ctx(Ctx_), Decoder(Decoder_) {};
  ~JIT() = default;

  bool hasBlock(size_t PC) const;
  const TranslatedBlock &getBlock(size_t PC) const;
  TranslatedBlock transalte(size_t PC);

  BlockFn compileBlock(uint32_t Pc);
  uint32_t executeBlock(uint32_t Pc, GeneralSim::ExecContext &Ctx);

private:
  void emitInstruction();

  GeneralSim::ExecContext &Ctx;
  const Decoder::Decoder& Decoder;
  std::unordered_map<uint32_t, BlockFn> Cache;
  asmjit::JitRuntime Rt;
};

} // namespace SimJIT

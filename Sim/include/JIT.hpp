#pragma once

#include <asmjit/asmjit.h>
#include <cstdint>
#include <unordered_map>

#include "ExecContext.hpp"
#include "GeneralSimTypes.hpp"

namespace SimJIT {
class JIT {
public:
  using BlockFn = uint32_t (*)(GeneralSim::ExecContext *);

  BlockFn compileBlock(uint32_t Pc);
  uint32_t executeBlock(uint32_t Pc, GeneralSim::ExecContext &Ctx);

private:
  std::unordered_map<uint32_t, BlockFn> Cache;
  asmjit::JitRuntime Rt;
};

} // namespace SimJIT

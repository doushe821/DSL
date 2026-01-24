#include "ElfLoader.hpp"
#include "Instructions.hpp"
#include "CLI11.hpp"

int main() {
  std::string ELFName = "test";

  std::vector<uint8_t> RawELF;
  auto EntryAddress = loadElf(ELFName, RawELF);

  GeneralSim::CPU SPU(EntryAddress, RawELF);

  

  return 0;
}
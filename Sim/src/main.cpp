#include "CLI11.hpp"
#include "ElfLoader.hpp"
#include "GeneralSim.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) {

  size_t MemorySize = 4 * UINT16_MAX; // Move to GeneralSim
  CLI::App CLIApp;
  std::string ElfName;
  CLIApp.add_option("-e,--elf", ElfName, "Name of the ELF file")->required();
  CLIApp.add_option("--memory-size", MemorySize, "Maximum size of the memory")
      ->default_val(4 * UINT16_MAX);
  
  CLI11_PARSE(CLIApp, argc, argv);

  GeneralSim::CPU SPU(MemorySize);

  size_t EntryPoint {0};
  try {
    loadElf(ElfName, SPU.getRawMem(), MemorySize, EntryPoint);
  } catch (std::runtime_error &E) {
    std::cerr << E.what() << std::endl;
  }

  SPU.setEntry(EntryPoint);

  SPU.run();

  return 0;
}

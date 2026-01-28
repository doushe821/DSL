#include "ElfLoader.hpp"
#include "elfio/elfio.hpp"
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <format>
#include <stdexcept>
#include <vector>

void loadElf(const std::string &ElfName, unsigned char *Memory,
             size_t MemoryLimit, size_t &EntryPoint) {
  ELFIO::elfio Reader;

  if (!Reader.load(ElfName)) {
    throw std::runtime_error("Could not open ELF file.");
  }
  size_t LoadSegmentCounter{0};
  for (auto &Pseg : Reader.segments) {
    if (Pseg->get_type() == ELFIO::PT_LOAD) {
      ++LoadSegmentCounter;
      // TODO load these to MMU, when MMU is added.
      auto VAddr = Pseg->get_virtual_address();
      auto MSize = Pseg->get_memory_size();
      auto FSize = Pseg->get_file_size();

      if (MemoryLimit < VAddr + MSize) {
        throw std::runtime_error(
            std::format("ELF requires at least {} of memory, while only {} is "
                        "allocated.",
                        VAddr + MSize, MemoryLimit));
      }

      if (!memcpy(Memory + VAddr, Pseg->get_data(), FSize)) {
        throw std::runtime_error("Failed to load segment.");
      }
    }
  }
  if (LoadSegmentCounter == 0) {
    throw std::runtime_error("ELF file without Load segments!");
  }
  EntryPoint = Reader.get_entry();
}

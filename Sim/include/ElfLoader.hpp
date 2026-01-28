#pragma once

#include <cinttypes>
#include <string>
#include <vector>

void loadElf(const std::string &ElfName, unsigned char* Memory, size_t MemoryLimit, size_t &EntryPoint);

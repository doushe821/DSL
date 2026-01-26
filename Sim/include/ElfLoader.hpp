#pragma once

#include <cinttypes>
#include <string>
#include <vector>

void loadElf(const std::string &ElfName, std::vector<uint8_t> &Memory);

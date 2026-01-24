#include <libelf.h>
#include <gelf.h>

#include <fcntl.h>
#include <unistd.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>

#include <cassert>


#include <iostream>
#include <fstream>
#include <vector>
#include <libelf.h>
#include <gelf.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cassert>

static inline void checkCompatability(Elf& ELF)
{
    GElf_Ehdr Ehdr;
    if (!gelf_getehdr(&ELF, &Ehdr)) {
        assert("gelf_getehdr failed" & 0);
    }
    if (Ehdr.e_machine != EM_RISCV) {
        assert("ELF is not RISC-V" & 0);
    }
    if (Ehdr.e_ident[EI_DATA] != ELFDATA2LSB) {
        assert("ELF is not little-endian" & 0);
    }
    if (Ehdr.e_type != ET_EXEC && Ehdr.e_type != ET_DYN) {
        assert("unsupported ELF type" & 0);
    }
}

static inline void checkRelocations(Elf& ELF)
{
    Elf_Scn *Scn = nullptr;
    while ((Scn = elf_nextscn(&ELF, Scn)) != nullptr) {
        GElf_Shdr Shdr;
        gelf_getshdr(Scn, &Shdr);
        if (Shdr.sh_type == SHT_RELA ||
            Shdr.sh_type == SHT_REL) {
            assert("ELF contains relocations (not supported)" & 0); // TODO 
        }
    }
}

static inline uint64_t loadElf(const std::string& ElfPath, std::vector<uint8_t>& Buf) {
    assert(elf_version(EV_CURRENT) != EV_NONE);

    int Fd = open(ElfPath.c_str(), O_RDONLY);
    assert(Fd >= 0);

    Elf* ElfFile = elf_begin(Fd, ELF_C_READ, nullptr);
    assert(ElfFile != nullptr);
    assert(elf_kind(ElfFile) == ELF_K_ELF);

    checkCompatability(*ElfFile);
    checkRelocations(*ElfFile);

    GElf_Ehdr Ehdr;
    uint64_t Entry = Ehdr.e_entry;
    elf_end(ElfFile); 
    close(Fd);
    

    std::ifstream In(ElfPath, std::ios::binary | std::ios::ate);
    assert(In.is_open());

    std::streamsize FileSize = In.tellg();
    assert(FileSize >= 0);
    In.seekg(0, std::ios::beg);

    Buf.reserve(FileSize);
    assert(In.read(reinterpret_cast<char*>(Buf.data()), FileSize));

    return Entry;
}

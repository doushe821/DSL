#include <libelf.h>
#include <gelf.h>

#include <fcntl.h>
#include <unistd.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <stdexcept>
#include <string>

static void loadToMemory(uint64_t addr,
                           const uint8_t *data,
                           size_t size)
{
    printf("Loading %zu bytes at VA 0x%lx\n", size, addr);
}

class ElfLoader {
public:
    explicit ElfLoader(const std::string &_path)
        : path(_path) {}

    uint64_t load()
    {
        initLibelf();
        openFile();
        readHeader();
        checkRelocations();
        loadExecSections();
        cleanup();
        return entry;
    }

private:
    std::string path;
    int fd = -1;
    Elf *elf = nullptr;
    uint64_t entry = 0;


    static void fail(const char *msg) // TODO move to separate helper file
    {
        throw std::runtime_error(msg);
    }

    static void failElf(const char *msg)
    {
        std::string err = msg;
        err += ": ";
        err += elf_errmsg(-1);
        throw std::runtime_error(err);
    }

    void initLibelf()
    {
        if (elf_version(EV_CURRENT) == EV_NONE)
            fail("libelf initialization failed");
    }

    void openFile()
    {
        fd = open(path.c_str(), O_RDONLY);
        if (fd < 0)
            fail("failed to open ELF file");

        elf = elf_begin(fd, ELF_C_READ, nullptr);
        if (!elf)
            failElf("elf_begin failed");
    }

    void readHeader()
    {
        GElf_Ehdr ehdr;
        if (!gelf_getehdr(elf, &ehdr))
            failElf("gelf_getehdr failed");

        // TODO Generate architecture specific checks?
        if (ehdr.e_machine != EM_RISCV)
            fail("ELF is not RISC-V");

        if (ehdr.e_ident[EI_DATA] != ELFDATA2LSB)
            fail("ELF is not little-endian");

        if (ehdr.e_type != ET_EXEC && ehdr.e_type != ET_DYN)
            fail("unsupported ELF type");

        entry = ehdr.e_entry;
    }

    void checkRelocations()
    {
        Elf_Scn *scn = nullptr;
        while ((scn = elf_nextscn(elf, scn)) != nullptr) {
            GElf_Shdr shdr;
            gelf_getshdr(scn, &shdr);

            if (shdr.sh_type == SHT_RELA ||
                shdr.sh_type == SHT_REL) {
                fail("ELF contains relocations (not supported)"); // TODO 
            }
        }
    }

    void loadExecSections()
    {
        Elf_Scn *scn = nullptr;

        while ((scn = elf_nextscn(elf, scn)) != nullptr) {
            GElf_Shdr shdr;
            gelf_getshdr(scn, &shdr);

            if (!(shdr.sh_flags & SHF_EXECINSTR)) {
                continue;
            }

            if (shdr.sh_size == 0) {
                continue;
            }

            Elf_Data *data = elf_getdata(scn, nullptr);
            if (!data || !data->d_buf)
                fail("failed to read section data");

            const uint8_t *bytes =
                static_cast<const uint8_t *>(data->d_buf);

            loadToMemory(shdr.sh_addr, bytes, data->d_size);
        }
    }

    void cleanup()
    {
        if (elf)
            elf_end(elf);
        if (fd >= 0)
            close(fd);
    }
};

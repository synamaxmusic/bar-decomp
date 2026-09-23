#include <libelf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <gelf.h>
#include <stdlib.h>
#include "stb_vc_vector.h"
#include "stb_log.h"
#include <assert.h>
#include "elf_parse.h"

static vc_vector *SectionsHeader;
static vc_vector *RelocTable;
static size_t SectionHeaderStringIndex;
static Elf *ElfFile;
static int ElfFileFd;

void ElfParse_InitSections(Elf *elf) {
    size_t sectionCount;

    if (elf_getshdrnum(elf, &sectionCount) != 0) {
        fprintf(stderr, "Failed to get section count\n");
        elf_end(elf);
        return;
    }

    SectionsHeader = vc_vector_create(0, sizeof(Section), NULL);

    if (SectionsHeader == NULL) {
        printf("Can't allocate memory for sections header\n");
        abort();
    }

    Elf_Scn *scn = NULL;
    while ((scn = elf_nextscn(elf, scn)) != NULL) {
        Section section;
        Elf32_Shdr *shdr = elf32_getshdr(scn);
        if (shdr == NULL) {
            printf("Couldn't get sec header..");
            continue;
        }

        char *sectionName = elf_strptr(ElfFile, SectionHeaderStringIndex, shdr->sh_name);
        //printf("sectionName: %s\n", sectionName);
        //printf("type: 0x%X\n", shdr->sh_type);
        //printf("Offset: %x\n", shdr->sh_offset);

        section.name = sectionName;
        section.size = shdr->sh_size;
        section.offset = shdr->sh_offset;
        section.type = shdr->sh_type;
        section.data = elf_getdata(scn, NULL);
        assert(vc_vector_push_back(SectionsHeader, &section));
    }
}

void ElfParse_PrintReloc(int relocType) {
    switch (relocType) {
        case R_MIPS_32:
            printf("R_MIPS_32\n");
            break;

        case R_MIPS_26:
            printf("R_MIPS_26\n");
            break;

        case R_MIPS_HI16:
            printf("R_MIPS_HI16\n");
            break;

        case R_MIPS_LO16:
            printf("R_MIPS_LO16\n");
            break;

        default:
            printf("Unknown relocation: %u\n", relocType);
            break;
    }
}

static void ElfParse_CreateRelocTable(Elf *elf) {
    size_t shstrndx;

    RelocTable = vc_vector_create(0, sizeof(RelocTableEntry), NULL);

    if (elf_getshdrstrndx(elf, &shstrndx) != 0) {
        fprintf(stderr, "Failed to get section string index\n");
        return;
    }
    GElf_Ehdr ehdr;
    if (gelf_getehdr(elf, &ehdr) == NULL) {
        fprintf(stderr, "gelf_getehdr() failed: %s\n", elf_errmsg(-1));
        elf_end(elf);
        return;
    }

    if (ehdr.e_type != ET_REL) {
        printf("Ony ELF Relocatable files are supported!\n");
        return;
    }

    Elf_Scn *scn = NULL;
    while ((scn = elf_nextscn(elf, scn)) != NULL) {
        GElf_Shdr shdr;
        if (gelf_getshdr(scn, &shdr) == NULL) {
            continue;
        }

        if (shdr.sh_type == SHT_DYNSYM) {
            printf("PIC files not supported!\n");
            break;
        }

        if (shdr.sh_type != SHT_REL && shdr.sh_type != SHT_RELA) {
            continue;
        }

        // Find the symbol table
        Elf_Scn *symTabSection = elf_getscn(elf, shdr.sh_link);
        GElf_Shdr symTabSectionHeader;
        gelf_getshdr(symTabSection, &symTabSectionHeader);
        Elf_Data *symtab_data = elf_getdata(symTabSection, NULL);

        // Read relocation data
        Elf_Data *reloc_data = elf_getdata(scn, NULL);
        size_t count = shdr.sh_size / shdr.sh_entsize;

        for (size_t i = 0; i < count; i++) {
            GElf_Addr offset;
            GElf_Xword info;
            GElf_Sxword addend = 0;

            if (shdr.sh_type == SHT_REL) {
                GElf_Rel rel;
                if (gelf_getrel(reloc_data, i, &rel) == NULL) {
                    continue;
                }

                offset = rel.r_offset;
                info = rel.r_info;

            } else {
                GElf_Rela rela;
                if (gelf_getrela(reloc_data, i, &rela) == NULL) {
                    continue;
                }

                offset = rela.r_offset;
                info = rela.r_info;
                addend = rela.r_addend;
            }

            size_t symIndex = GELF_R_SYM(info);
            unsigned int rel_type = GELF_R_TYPE(info);

            size_t targetIndex = shdr.sh_info;
            Elf_Scn *targetScn = elf_getscn(ElfFile, targetIndex);
            if (targetScn == NULL) {
                  printf("Couldn't get relocation target section\n");
                return;
            }

            GElf_Shdr targetShdr;
            if (gelf_getshdr(targetScn, &targetShdr) == NULL) {
                return;
            }

            char *targetName = elf_strptr(ElfFile, SectionHeaderStringIndex, targetShdr.sh_name);
            //printf("Target section: %s\n", targetName);

            GElf_Sym sym;
            if (gelf_getsym(symtab_data, symIndex, &sym) == NULL) {
                continue;
            }

            char *symbolName = elf_strptr(elf, symTabSectionHeader.sh_link, sym.st_name);

#if DEBUG_RELOC_TABLE
            printf("\n[%zu]\n", i);
            printf("  Offset: 0x%lx\n", offset);
            printf("  Type: ");
            ElfParse_PrintReloc(rel_type);
            printf("  Symbol index: %zu\n", symIndex);
            printf("  Symbol: %s\n", symbolName ? symbolName : "<unnamed>");
            printf("  Symbol value: 0x%lx\n", sym.st_value);
            printf("  Addend: %ld\n", addend);
#endif
            char *sectionName = "<unamed>";
            if (sym.st_shndx == SHN_UNDEF) {
               // printf("Undefined symbol\n");
            } else if (sym.st_shndx == SHN_ABS) {
                //printf("Absolute symbol\n");
            } else {
                Elf_Scn *scn = elf_getscn(ElfFile, sym.st_shndx);
                GElf_Shdr shdr;
                if (scn != NULL && gelf_getshdr(scn, &shdr) != NULL) {
                    sectionName = elf_strptr(ElfFile, SectionHeaderStringIndex, shdr.sh_name);
                }
            }

            RelocTableEntry relocEntry;
            relocEntry.symbol.index = symIndex;
            relocEntry.symbol.name = symbolName;
            relocEntry.symbol.value = sym.st_value;
            relocEntry.symbol.section = sym.st_shndx;
            relocEntry.symbol.sectionName = sectionName;
            relocEntry.symbol.type = GELF_ST_TYPE(sym.st_info);
            relocEntry.addend = addend;
            relocEntry.offset = offset;
            relocEntry.relocType = rel_type;
            relocEntry.targetSection = targetName;
            assert(vc_vector_push_back(RelocTable, &relocEntry));
        }
    }
}

Section *ElfParse_GetSection(const char *name) {
    for (void *i = vc_vector_begin(SectionsHeader); i != vc_vector_end(SectionsHeader);
         i = vc_vector_next(SectionsHeader, i)) {
        Section *section = i;
        if (strcmp(section->name, name) == 0) {
            return section;
        }
    }
    //log_info("Section %s not found\n", name);
    return NULL;
}

void ElfParse_Init(char *fileName) {
    ElfFileFd = open(fileName, O_RDONLY);
    if (ElfFileFd < 0) {
        perror("Failed to open file");
        abort();
    }

    if (elf_version(EV_CURRENT) == EV_NONE) {
        return;
    }

    ElfFile = elf_begin(ElfFileFd, ELF_C_READ, NULL);
    if (ElfFile == NULL) {
        return;
    }

    if (elf_getshdrstrndx(ElfFile, &SectionHeaderStringIndex) != 0) {
        fprintf(stderr, "Failed to get section string index\n");
        return;
    }

    Elf32_Ehdr *ehdr = elf32_getehdr(ElfFile);
    if (ehdr == NULL) {
        fprintf(stderr, "elf32_getehdr() failed: %s\n", elf_errmsg(-1));
        elf_end(ElfFile);
        return;
    }

    if (ehdr->e_type != ET_REL) {
        printf("Ony ELF REL files are supported\n");
        abort();
    }

    ElfParse_InitSections(ElfFile);
    // read_symbols(ElfFile);
    ElfParse_CreateRelocTable(ElfFile);
}

vc_vector *ElfParse_GetRelocTable(void) {
    return RelocTable;
}

vc_vector *ElfParse_GetSections(void) {
    return SectionsHeader;
}

void ElfParse_Destroy(void) {
    vc_vector_release(SectionsHeader);
    vc_vector_release(RelocTable);
    elf_end(ElfFile);
    close(ElfFileFd);
}

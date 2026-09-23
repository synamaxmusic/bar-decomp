#ifndef ELF_PARSE_H
#define ELF_PARSE_H
#include <libelf.h>


typedef struct Section {
    Elf_Data *data;
    char *name;
    uint32_t size;
    int32_t offset;
    int32_t type;
} Section;

typedef struct Symbol_s {
    char *name;
    char* sectionName;
    int32_t index;
    int32_t value;
    int32_t section;
    int32_t type;
} Symbol;

typedef struct RelocTableEntry_s {
    Symbol symbol;
    int32_t relocType;
    int32_t addend;
    int32_t offset;
    char* targetSection; // Reloc target section name
} RelocTableEntry;

void ElfParse_InitSections(Elf *elf);
void read_symbols(Elf *elf);
void ElfParse_Init(char *fileName);
vc_vector* ElfParse_GetRelocTable(void);
vc_vector* ElfParse_GetSections(void);
Section *ElfParse_GetSection(const char *name);
void ElfParse_Destroy(void);
#endif /* ELF_PARSE_H */

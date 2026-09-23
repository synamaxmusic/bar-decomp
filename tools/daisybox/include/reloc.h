#ifndef RELOC_H
#define RELOC_H
#include "elf_parse.h"

typedef struct MipsHi16_s {
    uint8_t *loc;
    uint32_t value;
} MipsHi16;

void Reloc_DoMipsHiLoRelocs(vc_vector *hi16Queue, int32_t relocType, uint8_t *loc, uint32_t symAddr, int32_t addend);
void Reloc_DoMips32Reloc(Section *section, RelocTableEntry *reloc);
void Reloc_DoMipsPc16Reloc(uint8_t *loc, int32_t offset, int32_t value, int32_t addend);
void Reloc_DoMips26Reloc(uint32_t *loc_orig, uint32_t *loc_new, int32_t offset);
#endif /* RELOC_H */

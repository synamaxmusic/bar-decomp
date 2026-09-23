#include "global.h"
#include "elf_parse.h"
#include "utils.h"

// Based on https://android.googlesource.com/kernel/common/+/450783747f42dfa3883920acfad4acdd93ce69af/arch/mips/kernel/module.c
void Reloc_DoMipsHiLoRelocs(vc_vector *hi16Queue, int32_t relocType, uint8_t *loc, uint32_t symAddr,
                            int32_t addend) {
    switch (relocType) {
        case R_MIPS_HI16:
            MipsHi16 hi16;

            hi16.value = symAddr + addend;
            hi16.loc = loc;
            vc_vector_push_back(hi16Queue, &hi16);
            break;
        case R_MIPS_LO16:
            int32_t val, vallo;
            uint32_t insnlo = Utils_ReadBe32(loc);

            vallo = ((insnlo & 0xffff) ^ 0x8000) - 0x8000;

            // Drain the accumulated HI16 list and patch those instructions

            if (!vc_vector_empty(hi16Queue)) {
                // log_info("Reloc_DoMipsHiLoRelocs: Processing HI16 entries\n");
                for (void *i = vc_vector_begin(hi16Queue); i != vc_vector_end(hi16Queue);
                     i = vc_vector_next(hi16Queue, i)) {
                    MipsHi16 *hi16 = i;
                    uint32_t insn;

                    /*
                     * The value for the HI16 had best be the same.
                     */
                    assert((symAddr + addend) == hi16->value);

                    insn = Utils_ReadBe32(hi16->loc);
                    val = ((insn & 0xffff) << 16) + vallo;
                    val += symAddr + addend;

                    /*
                     * Account for the sign extension that will happen in
                     * the low bits.
                     */
                    val = ((val >> 16) + ((val & 0x8000) != 0)) & 0xffff;
                    insn = (insn & ~0xffff) | val;
                    Utils_WriteBe32(hi16->loc, insn);
                }

                vc_vector_clear(hi16Queue);
            }

            val = (symAddr + addend) + vallo;
            insnlo = (insnlo & ~0xffff) | (val & 0xffff);
            Utils_WriteBe32(loc, insnlo);
            break;
    }
}

// Based on https://github.com/torvalds/linux/blob/master/arch/mips/kernel/relocate.c
void Reloc_DoMips26Reloc(uint32_t *loc_orig, uint32_t *loc_new, int32_t offset) {
    unsigned long target_addr = (Utils_ReadBe32((void *) loc_orig)) & 0x03ffffff;

    if (offset % 4) {
        log_error("Dangerous R_MIPS_26 REL relocation\n");
        return;
    }

    /* Original target address */
    target_addr <<= 2;
    target_addr += (unsigned long) loc_orig & 0xf0000000;

    /* Get the new target address */
    target_addr += offset;
    target_addr -= (unsigned long) loc_new & 0xf0000000;
    target_addr >>= 2;

    log_info("R_MIPS_26 -> %x",
             (Utils_ReadBe32((void *) loc_new) & ~0x03ffffff) | (target_addr & 0x03ffffff));
    Utils_WriteBe32((void *) loc_new,
                    (Utils_ReadBe32((void *) loc_new) & ~0x03ffffff) | (target_addr & 0x03ffffff));
}

void Reloc_DoMips32Reloc(Section *section, RelocTableEntry *reloc) {
    uint8_t *location = section->data->d_buf + reloc->offset;
    uint32_t addend = Utils_ReadBe32(location);
    Symbol *sym = &reloc->symbol;
    uint32_t symbol_value = sym->value;

    uint32_t result = symbol_value + addend;
    Utils_WriteBe32(location, result);
    log_info("R_MIPS_32: %-20s  section=%s  offset=0x%x -> %08X", sym->name, section->name,
             (unsigned int) reloc->offset, result);
}

void Reloc_DoMipsPc16Reloc(uint8_t *loc, int32_t offset, int32_t value, int32_t addend) {
    uint32_t instr = Utils_ReadBe32(loc);
    uint32_t instrAddr = offset;
    int32_t pcOffset = ((int32_t) value + (int32_t) addend - (int32_t) (instrAddr + 4)) / 4;

    // Check range
    if (pcOffset < -32768 || pcOffset > 32767) {
        log_error("PC16 branch out of range!");
        return;
    }

    uint32_t patchedInstr = (instr & 0xFFFF0000) | (pcOffset & 0xFFFF);
    Utils_WriteBe32(loc, patchedInstr);
    log_info("pc offset: %d", pcOffset);
}
// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"

/*
* D_uvpfxld_rom_004012EC = uvLoadModule('TSEQ');
* D_uvpfxld_rom_004012E8 = uvLoadModule('FMTX');
* D_uvpfxld_rom_004012F0 = uvLoadModule('FVEC');
* D_uvpfxld_rom_004012F4 = uvLoadModule('UPFX');
*/

extern UvTSeq_Exports* D_uvpfxld_rom_004012EC;
extern UvFMtx_Rom_Exports* D_uvpfxld_rom_004012E8;
extern UvFVec_Rom_Exports* D_uvpfxld_rom_004012F0;
extern UvPfx_Exports* D_uvpfxld_rom_004012F4;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/__entrypoint_func_uvpfxld_rom_400000.s")

void func_uvpfxld_rom_00400094(void) {
    uvUnloadModule('TSEQ');
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('UPFX');
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_004000DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_004002DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_00400994.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_00400B98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_00400BD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_00400CBC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvpfxld_rom/func_uvpfxld_rom_00400CD0.s")


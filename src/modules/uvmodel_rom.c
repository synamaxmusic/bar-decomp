// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

extern void* D_uvmodel_rom_00403160;

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/__entrypoint_func_uvmodel_rom_400000.s")

void func_uvmodel_rom_004002BC(void) {
    _uvMemFree(D_uvmodel_rom_00403160);
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('QERY');
    uvUnloadModule('ISCT');
    uvUnloadModule('MATH');
}

void func_uvmodel_rom_0040031C(s32 arg0) {

}

void func_uvmodel_rom_00400324(s32 arg0, s32 arg1) {

}


void func_uvmodel_rom_00400330(s32 arg0, s32 arg1, s32 arg2) {

}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00400340.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_004003A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_0040045C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00400608.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_004006B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_0040199C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_0040215C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402224.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_004022E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402AD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402AE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402AFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402B98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402BB8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402CEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_00402E50.s")


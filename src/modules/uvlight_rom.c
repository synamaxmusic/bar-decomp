// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct UnkStruct_uvlight_rom_00401760_s {
    char pad[0x24];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} UnkStruct_uvlight_rom_00401760;

extern s32 D_uvlight_rom_0040174C;
extern u8 D_uvlight_rom_00401754;
extern UnkStruct_uvlight_rom_00401760 D_uvlight_rom_00401760;
extern s32 D_uvlight_rom_00401798;
extern s32 D_uvlight_rom_00401738;
extern s32 D_uvlight_rom_0040173C;
extern s32 D_uvlight_rom_00401740;
extern s32 D_uvlight_rom_00401744;

extern UvGfxMgr_Exports* D_uvlight_rom_004017D0;

#define BAR_gSPLightColor(pkt, n, col)					\
{									\
	gMoveWd(pkt, G_MW_LIGHTCOL, n, col);			\
	gMoveWd(pkt, G_MW_LIGHTCOL, n+4, col);			\
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/__entrypoint_func_uvlight_rom_400000.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_004004D8.s")

void func_uvlight_rom_00400568(s32 arg0) {
    D_uvlight_rom_00401760.unk2C = D_uvlight_rom_00401760.unk28 = D_uvlight_rom_00401760.unk24 =
        D_uvlight_rom_00401798 = D_uvlight_rom_0040174C = -1;
    D_uvlight_rom_00401754 = 0;
}

void func_uvlight_rom_004005A8(s32 arg0) {
    s32 temp_t6;
    s32 temp_t7;

    temp_t6 = D_uvlight_rom_00401738;
    D_uvlight_rom_00401738 = D_uvlight_rom_0040173C;
    temp_t7 = D_uvlight_rom_00401740; 
    D_uvlight_rom_0040173C = temp_t6;
    D_uvlight_rom_00401740 = D_uvlight_rom_00401744;
    D_uvlight_rom_00401744 = temp_t7;
}

void func_uvlight_rom_004005F0(s32 n, u32 light) {
    Gfx** gdl;
    s32 temp_t3;

    gdl = D_uvlight_rom_004017D0->uvGetDisplayListHead();
    temp_t3 = n * 0x18;
    gDPPipeSync(gdl[0]++);
    BAR_gSPLightColor(gdl[0]++, temp_t3, light);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00400690.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_0040081C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_004008D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00400B64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00400C60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00400D90.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00400EDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00400FB8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_004011D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_0040120C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00401260.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_0040131C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00401340.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_00401624.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvlight_rom/func_uvlight_rom_0040167C.s")

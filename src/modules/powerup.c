// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkStruct_Powerup_004004D4_s {
    u8 unk0;
    u8 pad1[3];
    s32 unk4;
    u16 unk8;
    u8 unkA;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
} UnkStruct_Powerup_004004D4;

typedef struct UnkStruct_Powerup_004003C0_s{
    f32  unk0;
    f32  unk4;
    f32  red;
    f32  green;
    f32  blue;
} UnkStruct_Powerup_004003C0;

typedef struct UnkStruct_Powerup_00400368_s{
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 alpha;
} UnkStruct_Powerup_00400368;

UnkStruct_Powerup_004003C0 D_powerup_004003C0[];
UnkStruct_Powerup_004004D4* D_powerup_004004D4;
s32 D_powerup_004004E8;
void func_powerup_004000F0(void);
void func_powerup_00400180(s32, Vec3F*);
UnkStruct_Powerup_004003C0* func_powerup_00400330(s32);
void func_powerup_00400368(UnkStruct_Powerup_00400368*);

void __entrypoint_func_powerup_400000(Powerup_Exports* arg0) {
    s32 i;
    UnkStruct_Powerup_004004D4* var_v0;

    uvUpdateFileAllocPtr(arg0);
    arg0->func_powerup_004000F0 = &func_powerup_004000F0;
    arg0->func_powerup_00400180 = &func_powerup_00400180;
    arg0->func_powerup_00400330 = &func_powerup_00400330;
    D_powerup_004004D4 = _uvMemAllocAlign8(30 * sizeof(UnkStruct_Powerup_004004D4));
    D_powerup_004004E8 = 0;
    for (i = 0; i < 30; i++) {
        var_v0 = &D_powerup_004004D4[i];
        var_v0->unk0 = 0;
        var_v0->unk4 = -1;
    }

    uvLoadFile('UVMD', 0x34);
}

void func_powerup_004000F0(void) {
    s32 temp_a0;
    s32 i;

    for (i = 0; i < 30; i++) {
        temp_a0 = D_powerup_004004D4[i].unk4;
        if (temp_a0 >= 0) {
            gUvDobjExports->unk40(temp_a0);
        }
    }

    _uvMemFree(D_powerup_004004D4);
    uvUnloadFile('UVMD', 0x34);
}

void func_powerup_00400180(s32 arg0, Vec3F *arg1) {
    f32 unused[14];
    s32 i;
    s32 sp38;
    UnkStruct_Powerup_004004D4 *temp_s0;

    if (arg0 < 0) {
        return;
    } else if (arg0 >= 0xD) {
        return;
    }
    
    for (i = 0; i < 30; i++) {
        temp_s0 = &D_powerup_004004D4[i];
        if (temp_s0->unk0 == 0) {
            break;
        }
    }

    if (i == 30) {
        return;
    }

    temp_s0->unk4 = gUvDobjExports->unk3C();
    if (temp_s0->unk4 >= 0) {
        gUvDobjExports->unk14(temp_s0->unk4, D_powerup_004003C0[arg0].unk0);
        gUvDobjExports->unk1C(temp_s0->unk4, 4, &func_powerup_00400368, temp_s0, 0);
        gUvDobjExports->unk30(temp_s0->unk4, 2);
        gUvDobjExports->unk38(temp_s0->unk4, 1);
        gUvFmtxExports->func_00400B68(&sp38);
        unused[10] = arg1->x;
        unused[11] = arg1->y;
        unused[12] = arg1->z;
        gUvDobjExports->unk24(temp_s0->unk4, 0, &sp38);
        temp_s0->unk0 = 1;
        temp_s0->unk8 = arg0;
        temp_s0->unkC = 0.0f;
        temp_s0->unkA = 1;
        temp_s0->unk10 = arg1->x;
        temp_s0->unk14 = arg1->y;
        temp_s0->unk18 = arg1->z;
        temp_s0->unk1C = 0.0f;
        temp_s0->unk20 = 1.0f;
    }
}


UnkStruct_Powerup_004003C0* func_powerup_00400330(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 0xD)) {
        return &D_powerup_004003C0[0];
    }
    return &D_powerup_004003C0[arg0];
}

void func_powerup_00400368(UnkStruct_Powerup_00400368* arg0) {
    UnkStruct_Powerup_004003C0* temp_v0;

    temp_v0 = &D_powerup_004003C0[arg0->unk8];
    gUvGfxMgrExports->func_uvgfxmgr_rom_0040107C(temp_v0->red, temp_v0->green, temp_v0->blue, arg0->alpha);
}


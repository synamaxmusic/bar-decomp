// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"


// module functions
void __entrypoint_func_envsnd_400000(EnvSnd_Exports *exports);
void func_envsnd_00400054(void);
void func_envsnd_0040005C(s32 arg0, UnkStruct_envsnd_0040005C *arg1);
s32 func_envsnd_00400114(UnkStruct_envsnd_0040005C *arg0, Vec3F *arg1);
void func_envsnd_00400250(UnkStruct_envsnd_00400250 *arg0);
void func_envsnd_00400444(s32 arg0, s32 arg1);

// .data
s32 D_envsnd_00400460[] = {0x00100000, __entrypoint_func_envsnd_400000, 0, 0};

// .bss
s32 B_envsnd_00400470; // unreferenced padding
UnkStruct_envsnd_0040005C *D_envsnd_00400474;
s32 D_envsnd_00400478;
s32 B_envsnd_0040047C; // more padding
UnkStruct_004005C8 D_envsnd_00400480[94];
u8 D_envsnd_00400770[96];


void __entrypoint_func_envsnd_400000(EnvSnd_Exports* exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_envsnd_00400054 = func_envsnd_00400054;
    exports->func_envsnd_0040005C = func_envsnd_0040005C;
    exports->func_envsnd_00400250 = func_envsnd_00400250;
    exports->func_envsnd_00400444 = func_envsnd_00400444;
}

void func_envsnd_00400054(void) {
}

void func_envsnd_0040005C(s32 arg0, UnkStruct_envsnd_0040005C *arg1) {
    UnkStruct_envsnd_0040005C *s0;
    s32 i;

    D_envsnd_00400478 = arg0;
    D_envsnd_00400474 = arg1;

    // FAKE
    if (D_envsnd_00400478) {
    }
    for (i = 0; i < D_envsnd_00400478; i++) {
        gSndExports->func_snd_00402504(&D_envsnd_00400480[i]);
        arg1[i].unk20 = SQ(arg1[i].unk1C);
    }
}

s32 func_envsnd_00400114(UnkStruct_envsnd_0040005C *arg0, Vec3F *arg1) {
    Vec3F sp24;
    s32 ret;

    sp24.x = arg1->x - arg0->unkC.x;
    sp24.y = arg1->y - arg0->unkC.y;
    sp24.z = arg1->z - arg0->unkC.z;
    if ((gUvFvecExports->uvVec3FDot(&sp24, &sp24) < arg0->unk20)) {
        ret = TRUE;
        if ((arg0->unk0 == 0x18) && (arg1->z < 290.0f)) {
            ret = FALSE;
        }
        if ((gGameSettings->currentTrack == METRO_MADNESS)
            && ((arg0->unk0 == 0x48) || (arg0->unk0 == 0x49) || (arg0->unk0 == 0x4A)
                || (arg0->unk0 == 0x4B))
            && (((arg1->z > 28.7f)) || (arg1->z < 19.0f))) {
            ret = FALSE;
        }
    } else {
        ret = FALSE;
    }
    return ret;
}

void func_envsnd_00400250(UnkStruct_envsnd_00400250 *arg0) {
    UnkStruct_envsnd_0040005C *var_s0;
    s32 temp_s6;
    Vec3F sp64;
    s32 i;
    u8 temp_v0;
    temp_s6 = arg0->unk4->unkC;
    if (gGameSettings->pauseFlag) {
        return;
    }

    gSndExports->sndSetSfxVol(gGameSettings->optionsSfxVol);
    sp64.x = arg0->unk0->unk618.x;
    sp64.y = arg0->unk0->unk618.y;
    sp64.z = arg0->unk0->unk618.z;

    var_s0 = D_envsnd_00400474;
    for (i = 0; i < D_envsnd_00400478; i++, var_s0++) {
        if (temp_s6 == 0) {
            D_envsnd_00400770[i] = 0;
        }
        if (func_envsnd_00400114(var_s0, &sp64) != 0) {
            D_envsnd_00400770[i] = 1;
        }
        if ((temp_s6 + 1) == gGameSettings->numPlayers) {
            if (D_envsnd_00400770[i] != 0) {
                if (var_s0->unk24 == 0) {
                    temp_v0 = gSndExports->func_snd_00401914(
                        &D_envsnd_00400480[i], var_s0->unk0, 0x61A8,
                        gSndExports->func_snd_004014B4() * var_s0->unk4, var_s0->unk18, var_s0->unk1C,
                         &var_s0->unkC);

                    if (temp_v0 != 0xFF) {
                        var_s0->unk24 = 1;
                        var_s0->unk1 = temp_v0;
                    }
                }
            } else if (var_s0->unk24 != 0) {
                var_s0->unk24 = 0;
                gSndExports->func_snd_00401CDC(&D_envsnd_00400480[i]);
            }
        }
    }
}

void func_envsnd_00400444(s32 arg0, s32 arg1) {

}
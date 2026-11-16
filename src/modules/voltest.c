// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkCarAnimExports_s {
    char pad[0x40];
    s32 (*unk40)(s32 **);
} UnkCarAnimExports;



void func_voltest_0040006C(void);
void *func_voltest_00400074(s32 volLoadId);
void func_voltest_00400128(void);
s32 func_voltest_00400194(UnkStruct_voltest_00400594 *arg0, s32 arg1, s32 arg2);
void func_voltest_00400264(UnkStruct_voltest_00400594 *arg0, s32 arg1);
void func_voltest_004002FC(UnkStruct_voltest_00400594 *arg0, s32 arg1);
void func_voltest_00400394(UnkStruct_voltest_00400594 *arg0, s32 arg1);
s32 func_voltest_0040044C(ParsedUVVL *arg0, Vec3F *arg1);
void __entrypoint_func_voltest_400000(VolTest_Exports *exports);

// .bss
s32 B_voltest_00400590; // unreferenced padding
UnkStruct_voltest_00400594 *D_voltest_00400594;
UnkCarAnimExports *D_voltest_00400598;

// .data
s32 D_voltest_00400580[] = {0x00100000, __entrypoint_func_voltest_400000, 0};

void __entrypoint_func_voltest_400000(VolTest_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_voltest_0040006C = func_voltest_0040006C;
    exports->func_voltest_00400074 = func_voltest_00400074;
    exports->func_voltest_00400128 = func_voltest_00400128;
    exports->func_voltest_00400194 = func_voltest_00400194;
#ifdef __sgi
#line 1
#endif
    D_voltest_00400598 = uvLoadModule('cara');
    D_voltest_00400594 = NULL;
}

void func_voltest_0040006C(void) {
}

void *func_voltest_00400074(s32 volLoadId) {
    UnkStruct_voltest_00400594 *temp_v0;
    s32 i;

    temp_v0 = _uvMemAllocAlign8(sizeof(UnkStruct_voltest_00400594));
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_v0->unk14 = D_voltest_00400594;
    D_voltest_00400594 = temp_v0;
    temp_v0->uvvl = uvLoadFile('UVVL', volLoadId);
    for (i = 0; i < 4; i++) {
        temp_v0->unk3[i] = -1;
        temp_v0->unk7[i] = -1;
    }

    for (i = 0; i < 8; i++) {
        temp_v0->unk8[i] = -1;
    }
    return temp_v0;
}

void func_voltest_00400128(void) {
    UnkStruct_voltest_00400594 *var_v0;
    s32 i;

    for (var_v0 = D_voltest_00400594; var_v0 != NULL; var_v0 = var_v0->unk14) {
        for (i = 0; i < 4; i++) {
            var_v0->unk3[i] = -1;
            var_v0->unk7[i] = -1;
        }

        for (i = 0; i < 8; i++) {
            var_v0->unk8[i] = -1;
        }
    }
}

s32 func_voltest_00400194(UnkStruct_voltest_00400594 *arg0, s32 arg1, s32 arg2) {
    if (arg0 == 0) {
        return 0;
    }

    switch (arg1) {
        case 0:
            if (arg0->unk3[arg2] == -1) {
                func_voltest_00400264(arg0, arg2);
            }
            return arg0->unk3[arg2];
        case 1:
            if (arg0->unk7[arg2] == -1) {
                func_voltest_004002FC(arg0, arg2);
            }
            return arg0->unk7[arg2];
        case 2:
            if (arg0->unk8[arg2] == -1) {
                func_voltest_00400394(arg0, arg2);
            }
            return arg0->unk8[arg2];
        default:
            return 0;
    }
}

void func_voltest_00400264(UnkStruct_voltest_00400594 *arg0, s32 arg1) {
    s32 sp20[4];
    s32 v0;

    v0 = gScrnExports->unk14(sp20);
    if ((arg1 < 0) || (arg1 >= v0)) {
        arg0->unk3[arg1] = 0;
        return;
    }
    if (func_voltest_0040044C(arg0->uvvl, sp20[arg1] + 0x1D8) != 0) {
        arg0->unk3[arg1] = 1;
        return;
    }
    arg0->unk3[arg1] = 0;
}

void func_voltest_004002FC(UnkStruct_voltest_00400594 *arg0, s32 arg1) {
    s32 sp20[4];
    s32 v0;

    v0 = gScrnExports->unk14(sp20);
    if ((arg1 < 0) || (arg1 >= v0)) {
        arg0->unk7[arg1] = 0;
        return;
    }
    if (func_voltest_0040044C(arg0->uvvl, sp20[arg1] + 0x184) != 0) {
        arg0->unk7[arg1] = 1;
        return;
    }
    arg0->unk7[arg1] = 0;
}

void func_voltest_00400394(UnkStruct_voltest_00400594 *arg0, s32 arg1) {
    s32 *sp68[8];
    Mtx4F sp28;
    s32 v0;

    v0 = D_voltest_00400598->unk40(sp68);
    if ((arg1 < 0) || (arg1 >= v0)) {
        arg0->unk8[arg1] = 0;
        return;
    }
    // could be sp68[arg1]->unk8 too
    gUvDobjExports->uvDobjGetPosm(sp68[arg1][2], 0, &sp28);
    if (func_voltest_0040044C(arg0->uvvl, (s32) &sp28.m[3][0]) != 0) {
        arg0->unk8[arg1] = 1;
        return;
    }
    arg0->unk8[arg1] = 0;
}

s32 func_voltest_0040044C(ParsedUVVL *arg0, Vec3F *arg1) {
    ParsedUVVL_inner *var_a2;
    ParsedUVVL_inner_1 *var_t1;
    f32 temp_fa0;
    f32 temp_ft4;
    f32 temp_fv0;
    s32 found;
    s32 i;
    s32 j;

    for (i = 0; i < arg0->unk0; i++) {
        var_a2 = &arg0->unk4[i];

        temp_fv0 = arg1->x - var_a2->unk8.x;
        temp_fa0 = arg1->y - var_a2->unk8.y;
        temp_ft4 = arg1->z - var_a2->unk8.z;
        if (SQ(var_a2->unk14) < (SQ(temp_fv0) + SQ(temp_fa0) + SQ(temp_ft4))) {
            continue;
        }
        found = TRUE;
        for (j = 0; j < var_a2->unk0; j++) {
            f32 fv0;
            var_t1 = &var_a2->unk4[j];
            fv0 = (var_t1->unk0 * arg1->x) + (var_t1->unk4 * arg1->y) + (var_t1->unk8 * arg1->z)
                  + var_t1->unk18;
            if (fv0 > 0.0f) {
                found = FALSE;
                break;
            }
        }
        if (found) {
            return TRUE;
        }
    }
    return FALSE;
}

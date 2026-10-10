// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "gbi.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkTerraExports_s {
    char pad[0x14];
    void (*func_uvterra_rom_00400E70)(s32 arg0, u32 arg1, f32 arg2, f32 arg3, f32 *arg4, void *arg5);
    char pad18[0x10];
    u32 (*func_uvterra_rom_00401E64)(s32 arg0, f32 arg1, f32 arg2, s32 *arg3);
} UnkTerraExports;

void func_misc_00400390(void);
void func_misc_00400398(f32 arg0);
f32 func_misc_00400400(f32 arg0, f32 arg1, f32 arg2);
f32 func_misc_004004B8(f32 arg0, f32 arg1, f32 arg2);
void func_misc_004005A0(Vec3F *arg0, Vec3F *arg1, f32 arg2);
void func_misc_004006A0(Mtx4F *arg0, Mtx4F *arg1, f32 arg2);
void func_misc_0040070C(Vec3F *arg0, UnkStruct_misc_004006A0 *arg1);
void func_misc_00400844(Vec3F arg0, f32 *arg3, f32 *arg4, f32 *arg5);
void func_misc_00400884(f32 arg0, f32 arg1, f32 arg2, f32 *arg3);
void func_misc_004008B4(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
void func_misc_004009B0(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
f32 func_misc_00400A7C(f32 arg0);
f32 func_misc_00400AD0(f32 arg0);
f32 func_misc_00400BF0(f32 arg0);
void func_misc_00400CA8(Mtx4F *mtx, f32 x, f32 y, f32 z);
void func_misc_00400E38(UnkStruct_misc_004006A0 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6);
void func_misc_00400FB8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Mtx4F *arg6);
void miscTLBStoreFault(void);
void func_misc_00401080(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
s32 func_misc_004012A4(s32 arg0, s32 arg1, s32 arg2);
void func_misc_004012E4(Mtx4F *arg0, Mtx4F *arg1, Mtx4F *arg2, f32 arg3);
f32 func_misc_0040142C(f32 arg0, f32 arg1, f32 arg2);
f32 func_misc_0040146C(f32 ang);
f32 func_misc_00401528(f32 ang);
f32 func_misc_004015A0(f32 arg0);
f32 func_misc_00401614(f32 ang);
f32 func_misc_004016CC(f32 x, f32 y);
f32 func_misc_004017A8(Vec2F *arg0);
f32 miscVec2FLen(Vec2F *v);
void func_misc_004017FC(Vec2F *arg0, Vec2F *arg1);
void func_misc_0040187C(Vec2F *arg0, Vec2F *arg1, f32 arg2, Vec2F *arg3);
f32 miscVec2FDot(Vec2F *arg0, Vec2F *arg1);
void miscVec2FAdd(Vec2F *arg0, Vec2F *arg1, Vec2F *arg2);
void miscVec2FSub(Vec2F *arg0, Vec2F *arg1, Vec2F *arg2);
void miscVec2FMult(Vec2F *arg0, f32 arg1, Vec2F *arg2);
void func_misc_00401938(Vec2F *arg0, UnkStruct_misc_004006A0 *arg1);
void func_misc_0040197C(Vec2F *arg0, Vec2F *arg1);
void func_misc_00401990(Vec2F *arg0, Vec2F *arg1, Vec2F *arg2, f32 arg3);
s32 func_misc_004019FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 *arg8, Vec3F *arg9);
void miscVec3FAdd(Vec3F *arg0, Vec3F *arg1, Vec3F *arg2);
void miscVec3FSub(Vec3F *arg0, Vec3F *arg1, Vec3F *arg2);
void miscVec3FMult(Vec3F *arg0, f32 scale, Vec3F *arg2);
void func_misc_00401EA8(Vec3F *arg0, UnkStruct_misc_004006A0 *arg1);
void miscVec3FSet(Vec3F *arg0, Vec3F *arg1);
void func_misc_00401F48(Quat *arg0, Quat *arg1, f32 arg2, Quat *arg3);
void func_misc_00401FA0(f32 x, f32 y, f32 z, Quat *quat);
void func_misc_0040213C(Mtx4F *mP, f32 arg1, f32 arg2, f32 arg3);
void func_misc_0040234C(Quat *quat, Mtx4F *arg0);
void func_misc_00402528(Quat *arg0, Quat *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_misc_00402698(Mtx4F *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
f32 func_misc_00402730(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, f32 *arg6, f32 *arg7, f32 *arg8);
void func_misc_00402874(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5);
void func_misc_004029DC(s32 arg0, u8 *arg1, f32 arg2);
void func_misc_00402A5C(Mtx4F *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_misc_00402BFC(Vec3F *arg0, Vec3F *arg1, f32 arg2);
f32 func_misc_00402D48(f32 arg0);
void func_misc_00402E94(Vec3F *arg0, Vec3F *arg1, Vec3F *arg2, f32 arg3);
f32 func_misc_00402EFC(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_misc_00403000(Vec3F *arg0, Vec3F *arg1, f32 arg2, f32 arg3);
s32 func_misc_00403110(Mtx4F *arg0, s32 dobj, s32 arg2, s32 arg3);
void miscLoadFileRomModule(void);
void miscUnloadFileRomModule(void);
s32 func_misc_00403348(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 *arg7);
void func_misc_00403650(s32 arg0, s32 profiler, s32 y);
f32 func_misc_00403748(UnkStruct_misc_00403748 *arg0, Vec3F *arg1, Vec3F *arg2);
GuiMenuItem *func_misc_004038D8(GuiMenuOption *menuOption, u8 *label, s16 arg2, f32 arg3, f32 arg4, s32 *arg5, GuiSlider **arg6);
GuiMenuItem *func_misc_00403A5C(GuiMenuOption *arg0, u8 *arg1, u8 *arg2, u8 *arg3, UvGrphStruct *arg4, f32 *arg5, Inner30 **arg6);
GuiMenuItem *func_misc_00403BEC(GuiMenuOption *menuOption, u8 *itemName, UvGuiCallback callback);
void func_misc_00403CA4(Vec3F *arg0, Vec3F *arg1);
f32 func_misc_00403CD8(f32 arg0);
s32 func_misc_00403D8C(u8 *arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void miscSetRandSeed(u32 arg0);
f32 miscRandFLCG(void);
void __entrypoint_func_misc_400000(Misc_Exports *arg0);

// .data
u32 sRandSeed = 1;

// .bss
s32 B_misc_00404310[2]; // unreferenced padding
Mtx4F D_misc_00404318;

// extern
extern f32 D_80025D70;
extern UnkTerraExports* gUvTerraExports;


void __entrypoint_func_misc_400000(Misc_Exports* arg0) {
    uvUpdateFileAllocPtr(arg0);
    arg0->func_misc_00400398 = func_misc_00400398;
    arg0->func_misc_00400400 = func_misc_00400400;
    arg0->func_misc_004004B8 = func_misc_004004B8;
    arg0->func_misc_004005A0 = func_misc_004005A0;
    arg0->func_misc_004006A0 = func_misc_004006A0;
    arg0->func_misc_0040070C = func_misc_0040070C;
    arg0->func_misc_00400844 = func_misc_00400844;
    arg0->func_misc_00400884 = func_misc_00400884;
    arg0->func_misc_004008B4 = func_misc_004008B4;
    arg0->miscVec3FSub = miscVec3FSub;
    arg0->miscVec3FMult = miscVec3FMult;
    arg0->func_misc_00401EA8 = func_misc_00401EA8;
    arg0->miscVec3FSet = miscVec3FSet;
    arg0->func_misc_00401F48 = func_misc_00401F48;
    arg0->func_misc_00401FA0 = func_misc_00401FA0;
    arg0->func_misc_0040213C = func_misc_0040213C;
    arg0->func_misc_0040234C = func_misc_0040234C;
    arg0->func_misc_00402528 = func_misc_00402528;
    arg0->func_misc_00402698 = func_misc_00402698;
    arg0->func_misc_004009B0 = func_misc_004009B0;
    arg0->func_misc_00400A7C = func_misc_00400A7C;
    arg0->func_misc_00400AD0 = func_misc_00400AD0;
    arg0->func_misc_00400BF0 = func_misc_00400BF0;
    arg0->func_misc_00402730 = func_misc_00402730;
    arg0->func_misc_00400CA8 = func_misc_00400CA8;
    arg0->func_misc_00402874 = func_misc_00402874;
    arg0->func_misc_00400E38 = func_misc_00400E38;
    arg0->func_misc_004029DC = func_misc_004029DC;
    arg0->func_misc_00400FB8 = func_misc_00400FB8;
    arg0->func_misc_00402A5C = func_misc_00402A5C;
    arg0->miscTLBStoreFault = miscTLBStoreFault;
    arg0->func_misc_00402BFC = func_misc_00402BFC;
    arg0->func_misc_00401080 = func_misc_00401080;
    arg0->func_misc_00402D48 = func_misc_00402D48;
    arg0->func_misc_004012A4 = func_misc_004012A4;
    arg0->func_misc_00402E94 = func_misc_00402E94;
    arg0->func_misc_00402EFC = func_misc_00402EFC;
    arg0->func_misc_00403000 = func_misc_00403000;
    arg0->func_misc_00403110 = func_misc_00403110;
    arg0->func_misc_00400390 = func_misc_00400390;
    arg0->func_misc_004012E4 = func_misc_004012E4;
    arg0->func_misc_0040142C = func_misc_0040142C;
    arg0->func_misc_0040146C = func_misc_0040146C;
    arg0->func_misc_00401528 = func_misc_00401528;
    arg0->func_misc_004015A0 = func_misc_004015A0;
    arg0->miscLoadFileRomModule = miscLoadFileRomModule;
    arg0->func_misc_00401614 = func_misc_00401614;
    arg0->miscUnloadFileRomModule = miscUnloadFileRomModule;
    arg0->func_misc_004016CC = func_misc_004016CC;
    arg0->func_misc_00403348 = func_misc_00403348;
    arg0->func_misc_004017A8 = func_misc_004017A8;
    arg0->func_misc_00403650 = func_misc_00403650;
    arg0->miscVec2FLen = miscVec2FLen;
    arg0->func_misc_00403748 = func_misc_00403748;
    arg0->func_misc_004017FC = func_misc_004017FC;
    arg0->func_misc_004038D8 = func_misc_004038D8;
    arg0->func_misc_00403A5C = func_misc_00403A5C;
    arg0->func_misc_00403BEC = func_misc_00403BEC;
    arg0->func_misc_00403CA4 = func_misc_00403CA4;
    arg0->func_misc_00403CD8 = func_misc_00403CD8;
    arg0->func_misc_0040187C = func_misc_0040187C;
    arg0->miscVec2FDot = miscVec2FDot;
    arg0->miscVec2FAdd = miscVec2FAdd;
    arg0->miscVec2FSub = miscVec2FSub;
    arg0->func_misc_00403D8C = func_misc_00403D8C;
    arg0->miscVec2FMult = miscVec2FMult;
    arg0->miscSetRandSeed = miscSetRandSeed;
    arg0->func_misc_00401938 = func_misc_00401938;
    arg0->miscRandFLCG = miscRandFLCG;
    arg0->func_misc_0040197C = func_misc_0040197C;
    arg0->func_misc_00401990 = func_misc_00401990;
    arg0->func_misc_004019FC = func_misc_004019FC;
    arg0->miscVec3FAdd = miscVec3FAdd;
}

void func_misc_00400390(void) {

}

void func_misc_00400398(f32 arg0) {
    f64 sec;

    sec = uvClkGetSec(0) + arg0;
    while (uvClkGetSec(0) < sec) {

    }
}

f32 func_misc_00400400(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_ft4;
    f32 var_fa1;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    f32 var_fv1_2;

    if (arg1 < arg0) {
        var_fv0 = arg0 - arg1;
        var_fv1 = var_fv0;
    } else {
        var_fv0 = arg0 - arg1;
        var_fv1 = -var_fv0;
    }
    if (var_fv1 < 0.00001f) {
        return arg0;
    }
    temp_ft4 = arg2 * var_fv0 * D_80025D70;
    if (var_fv0 > 0.0f) {
        var_ft5 = var_fv0;
    } else {
        var_ft5 = -var_fv0;
    }
    if (temp_ft4 > 0.0f) {
        var_fv1 = temp_ft4;
    } else {
        var_fv1 = -temp_ft4;
    }
    if (var_ft5 < var_fv1) {
        arg1 = arg0;
    } else {
        arg1 = arg1 + temp_ft4;
    }
    return arg1;
}

f32 func_misc_004004B8(f32 arg0, f32 arg1, f32 arg2) {
    f32 var_fa1;
    f32 var_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    f32 var_fv1_2;

    if (arg1 < arg0) {
        var_fv0 = arg0 - arg1;
        var_fv1 = var_fv0;
    } else {
        var_fv0 = arg0 - arg1;
        var_fv1 = -var_fv0;
    }
    if (var_fv1 < 0.00001f) {
        return arg0;
    }
    if (var_fv0 > 0) {
        var_ft4 = arg2 * D_80025D70;
    } else {
        var_ft4 = -arg2 * D_80025D70;
    }
    if (var_fv0 > 0.0f) {
        var_ft5 = var_fv0;
    } else {
        var_ft5 = -var_fv0;
    }
    if (var_ft4 > 0.0f) {
        var_fv1 = var_ft4;
    } else {
        var_fv1 = -var_ft4;
    }
    if (var_ft5 < var_fv1) {
        arg1 = arg0;
    } else {
        arg1 = arg1 + var_ft4;
    }
    return arg1;
}

void func_misc_004005A0(Vec3F* arg0, Vec3F* arg1, f32 arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    temp_fv0 = gUvFvecExports->uvVec3FLen(arg1);
    if (temp_fv0 == 0.0f) {
        return;
    }

    arg1->x = func_misc_00400400(arg0->x, arg1->x, arg2);
    arg1->y = func_misc_00400400(arg0->y, arg1->y, arg2);
    arg1->z = func_misc_00400400(arg0->z, arg1->z, arg2);

    temp_fv0_2 = gUvFvecExports->uvVec3FLen(arg1);
    if (temp_fv0_2 == 0.0f) {
        return;
    }

    temp_fv1 = temp_fv0 / temp_fv0_2;
    arg1->x *= temp_fv1;
    arg1->y *= temp_fv1;
    arg1->z *= temp_fv1;
}


void func_misc_004006A0(Mtx4F* arg0, Mtx4F* arg1, f32 arg2) {
    arg1->m[3][0] = func_misc_00400400(arg0->m[3][0], arg1->m[3][0], arg2);
    arg1->m[3][1] = func_misc_00400400(arg0->m[3][1], arg1->m[3][1], arg2);
    arg1->m[3][2] = func_misc_00400400(arg0->m[3][2], arg1->m[3][2], arg2);
}

void func_misc_0040070C(Vec3F* arg0, UnkStruct_misc_004006A0* arg1) {
    Vec3F sp3C;
    Vec3F sp30;
    Vec3F sp24;

    gUvFvecExports->uvVec3FNormalize(arg0, arg0);
    gUvFvecExports->uvVec3FCopy(&sp3C, arg0);
    sp30.x = arg1->unk0;
    sp30.y = arg1->unk4;
    sp30.z = arg1->unk8;
    gUvFvecExports->uvVec3FCross(&sp24, &sp3C, (Vec3F* ) &sp30);
    gUvFvecExports->uvVec3FNormalize(&sp24, &sp24);
    gUvFvecExports->uvVec3FCross((Vec3F* ) &sp30, &sp24, &sp3C);
    gUvFvecExports->uvVec3FNormalize((Vec3F* ) &sp30, (Vec3F* ) &sp30);
    arg1->unk0 = sp30.x;
    arg1->unk4 = sp30.y;
    arg1->unk8 = sp30.z;
    arg1->unk10 = sp24.x;
    arg1->unk14 = sp24.y;
    arg1->unk18 = sp24.z;
    arg1->unk20 = sp3C.x;
    arg1->unk24 = sp3C.y;
    arg1->unk28 = sp3C.z;
    arg1->unkC = 0.0f;
    arg1->unk1C = 0.0f;
    arg1->unk2C = 0.0f;
}

void func_misc_00400844(Vec3F arg0, f32* arg3, f32* arg4, f32* arg5) {
    func_misc_004008B4(arg0.x, arg0.y, arg0.z, arg3, arg4, arg5);
}

void func_misc_00400884(f32 arg0, f32 arg1, f32 arg2, f32* arg3) {
    func_misc_004009B0(arg0, arg1, arg2, arg3, arg3 + 1, arg3 + 2);
}

void func_misc_004008B4(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 sp1C;
    f32 temp_fa0;
    s32 pad;
    f32 sp20;

    sp20 = gUvMathExports->uvSqrtf(SQ(arg0) + SQ(arg1));
    *arg3 = gUvMathExports->uvSqrtf(SQ(arg0) + SQ(arg1) + SQ(arg2));
    if (*arg3 == 0.0f) {
        *arg4 = 0.0f;
        *arg5 = 0.0f;
        return;
    }
    *arg4 = gUvMathExports->uvAtan2F(arg1 / *arg3, arg0 / *arg3);
    *arg5 = gUvMathExports->uvAtan2F(arg2 / *arg3, sp20 / *arg3);
}

void func_misc_004009B0(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 cosf;

    cosf =  gUvMathExports->uvCosF(arg2);
    *arg3 = gUvMathExports->uvCosF(arg1) * (arg0 * cosf);
    *arg4 = gUvMathExports->uvSinF(arg1) * (arg0 * cosf);
    *arg5 = gUvMathExports->uvSinF(arg2) * arg0;
}

f32 func_misc_00400A7C(f32 arg0) {
    s32 pad;
    f32 sp18;

    sp18 = gUvMathExports->uvSinF(arg0);
    return sp18 / gUvMathExports->uvCosF(arg0);
}

f32 func_misc_00400AD0(f32 arg0) {
    f32 temp_fv0_2;
    f32 var_fa0;
    f32 var_ft4;
    f32 var_fv1;
    f32 var_fv1_2;
    s32 var_v0;
    f32 fa1;
    f32 fv0;
    if (arg0 == 0.0f) {
        return 0.0f;
    }
    var_fa0 = gUvMathExports->uvSqrtf(1.0f / (SQ(arg0) + 1.0f));
    if (arg0 > 0.0f) {
        var_fv1_2 = arg0 * var_fa0;
    } else {
        var_fv1_2 = (-arg0) * var_fa0;
    }
    var_v0 = 0;
    if (var_fa0 < var_fv1_2) {
        fv0 = var_fa0;
        var_fa0 = var_fv1_2;
        var_fv1_2 = fv0;
        var_v0 = 1;
    }
    temp_fv0_2 = var_fv1_2 / var_fa0;
    fa1 = var_fv1_2 / var_fa0;
    var_ft4 = FABS(var_fv1_2 - var_fa0);

    var_fv1 = temp_fv0_2 * 0.7853982f + ((0.309f * var_ft4) * fa1);
    // FAKE 
    if (fa1) {

    }
    
    var_ft4 = 1.5707963f;
    if (var_v0) {
        var_fv1 = var_ft4 - var_fv1;
    }
    if (arg0 >= 0.0f) {
        return var_fv1;
    }
    return -var_fv1;
}

f32 func_misc_00400BF0(f32 arg0) {
    if (arg0 == 0.0f) {
        return 1.5707963f;
    }

    if (arg0 < -1.0f) {
        arg0 = -1.0f;
    } else if (arg0 > 1.0f) {
        arg0 = 1.0f;
    }

    return gUvMathExports->uvAtan2F(gUvMathExports->uvSqrtf(1 - SQ(arg0)), arg0);
}

void func_misc_00400CA8(Mtx4F* mtx, f32 x, f32 y, f32 z) {
    f32 temp_fs0;
    f32 temp_fs1;
    Vec3F sp34;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;

    temp_fs0 = gUvMathExports->uvSinF(z);
    temp_fs1 = gUvMathExports->uvCosF(z);
    sp34.z = gUvMathExports->uvSinF(y);
    sp34.y = gUvMathExports->uvCosF(y);
    sp34.x = gUvMathExports->uvSinF(x);
    temp_fv0 = gUvMathExports->uvCosF(x);
    temp_ft4 = sp34.z * sp34.x;
    mtx->m[0][0] = (temp_fs1 * temp_fv0) - (temp_fs0 * temp_ft4);
    temp_ft5 = sp34.z * temp_fv0;
    mtx->m[0][1] = (temp_fs1 * sp34.x) + (temp_fs0 * temp_ft5);
    mtx->m[0][3] = 0.0f;
    mtx->m[0][2] = -temp_fs0 * sp34.y;
    mtx->m[1][0] = -sp34.y * sp34.x;
    mtx->m[1][1] = sp34.y * temp_fv0;
    mtx->m[1][2] = sp34.z;
    mtx->m[2][0] = (temp_fs0 * temp_fv0) + (temp_fs1 * temp_ft4);
    mtx->m[2][1] = (temp_fs0 * sp34.x) - (temp_fs1 * temp_ft5);
    mtx->m[2][2] = temp_fs1 * sp34.y;
    mtx->m[3][3] = 1.0f;
    mtx->m[1][3] = 0.0f;
    mtx->m[2][3] = 0.0f;
    mtx->m[3][0] = 0.0f;
    mtx->m[3][1] = 0.0f;
    mtx->m[3][2] = 0.0f;
}

void func_misc_00400E38(UnkStruct_misc_004006A0* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6) {
    f32 len;
    f32 var_fv1;
    f32 sp2C;

    sp2C = arg0->unk18;
    len = gUvMathExports->uvSqrtf(SQ(arg0->unk14) + SQ(arg0->unk10));
    if (ABS_2(len) < 0.001f) {
        if (sp2C < 0.0f) {
            *arg5 = -1.5707963f;
        } else {
            *arg5 = 1.5707963f;
        }
        *arg4 = 0.0f;
        *arg6 = 0.0f;
    } else {
        f32 fa2;
        f32 fa1;

        *arg5 = gUvMathExports->uvAtan2F(sp2C, len);
        fa2 = arg0->unk14 / len;
        fa1 = -arg0->unk10 / len;
        *arg4 = gUvMathExports->uvAtan2F(fa1, fa2);
        fa2 = arg0->unk28 / len;
        fa1 = -arg0->unk8 / len;
        *arg6 = gUvMathExports->uvAtan2F(fa1, fa2);
    }
    *arg1 = arg0->unk30;
    *arg2 = arg0->unk34;
    *arg3 = arg0->unk38;
}

void func_misc_00400FB8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Mtx4F* arg6) {
    gUvFmtxExports->uvMat4SetIdentity(arg6);
    gUvFmtxExports->uvMat4RotateAxis(arg6, arg3, 0x7A);
    gUvFmtxExports->uvMat4RotateAxis(arg6, arg4, 0x78);
    gUvFmtxExports->uvMat4RotateAxis(arg6, arg5, 0x79);
    arg6->m[3][0] = arg0;
    arg6->m[3][1] = arg1;
    arg6->m[3][2] = arg2;
}

void miscTLBStoreFault(void) {
    PANIC;
}

void func_misc_00401080(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 temp_fa0;
    f32 var_fa0;
    f32 var_ft0;
    s32 temp_ft3;
    f32 one = 1.0f;
    
    if (arg1 <= 0.0001f) {
        *arg3 = arg2;
        *arg4 = arg2;
        *arg5 = arg2;
        return;
    }
    
    if (arg0 < 0) {        
        arg0 += 1.0f;
    }
    if (arg0 == 1.0f) {
        arg0 = 0.0f;
    }
    arg0 = arg0 * 6.0f;
    temp_ft3 = arg0;
    switch ((s32)arg0) {
    case 0:
        *arg3 = arg2;
        *arg4 = (1.0f - ((one - (arg0 - temp_ft3)) * arg1)) * arg2;
        *arg5 =  (1.0f - arg1) * arg2;
        break;
    case 1:
        *arg3 = (1.0f - ((0, arg1)  * (arg0 - temp_ft3))) * arg2;
        *arg4 = arg2;
        *arg5 = (1.0f - arg1) * arg2;
        break;
    case 2:
        *arg3 = (1.0f - arg1) * arg2;
        *arg4 = arg2;
        *arg5 = (1.0f - ((1.0f - (arg0 - temp_ft3)) * arg1)) * arg2;
        break;
    case 3:
        *arg3 = (1.0f - arg1) * arg2;
        *arg4 = (1.0f - ((0, arg1)  * (arg0 - temp_ft3))) * arg2;
        *arg5 = arg2;
        break;
    case 4:
        *arg3 = (1.0f - ((1.0f - (arg0 - temp_ft3)) * arg1)) * arg2;
        *arg4 = (1.0f - arg1) * arg2;
        *arg5 = arg2;
        break;
    case 5:
        *arg3 = arg2;
        *arg4 = (1.0f - arg1) * arg2;
        *arg5 =  (1.0f - ((0, arg1) * (arg0 - temp_ft3))) * arg2;
    default:
        break;
    }
}

s32 func_misc_004012A4(s32 arg0, s32 arg1, s32 arg2) {
    if ((arg1 & arg2) && !(arg0 & arg2)) {
        return 1;
    }
    if (!(arg1 & arg2) && (arg0 & arg2)) {
        return -1;
    }
    return 0;
}

void func_misc_004012E4(Mtx4F* arg0, Mtx4F* arg1, Mtx4F* arg2, f32 arg3) {
    f32 temp_fv0;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    Quat sp50;
    Quat sp40;
    Quat sp30;

    temp_fv0 = (1.0 - arg3);
    sp68 =  (temp_fv0 * arg1->m[3][0]) + (arg2->m[3][0] * arg3);
    sp64 = (temp_fv0 * arg1->m[3][1]) + (arg2->m[3][1] * arg3);
    sp60 = (temp_fv0 * arg1->m[3][2]) + (arg2->m[3][2] * arg3);
    gUvQuatExports->func_uvquat_rom_004000D8(&sp40, arg1);
    gUvQuatExports->func_uvquat_rom_004000D8(&sp30, arg2);
    gUvQuatExports->func_uvquat_rom_004009BC(&sp50, &sp40, &sp30, arg3);
    gUvFmtxExports->func_uvfmtx_rom_0040246C(arg0, sp50.x, sp50.y, sp50.z, sp50.w);
    arg0->m[0][3] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = sp68;
    arg0->m[3][1] = sp64;
    arg0->m[3][2] = sp60;
    arg0->m[3][3] = 1.0f;
}

f32 func_misc_0040142C(f32 arg0, f32 arg1, f32 arg2) {
    if (arg1 < arg0) {
        return arg1;
    }
    if (arg0 < arg2) {
        return arg2;
    }
    return arg0;
}

f32 func_misc_0040146C(f32 ang) {
    f32 clampedAng;

    clampedAng = ang;
    while (clampedAng > 180.0f) {
        clampedAng -= 360.0f;
    }
    while (clampedAng < -180.0f) {
        clampedAng += 360.0f;
    }
    if (clampedAng > 90.0f) {
        return 180.0f - clampedAng;
    }
    if (clampedAng < -90.0f) {
        return -180.0f - clampedAng;
    }
    return clampedAng;
}

f32 func_misc_00401528(f32 ang) {
    f32 clamped;

    clamped = ang;
    while (clamped > 180.0f) {
        clamped -= 360.0f;
    }
    while (clamped < -180.0f) {
        clamped += 360.0f;
    }
    return clamped;
}

f32 func_misc_004015A0(f32 arg0) {
    f32 var_fv1;

    var_fv1 = arg0;
    while (var_fv1 > 3.1415927f) {
        var_fv1 -= 6.2831855f;
    }
    while (var_fv1 < -3.1415927f) {
        var_fv1 += 6.2831855f;
    }
    return var_fv1;
}


f32 func_misc_00401614(f32 ang) {
    f32 clamped;

    clamped = ang;
    while (clamped > 3.1415927f) {
        clamped -= 6.2831855f;
    }
    while (clamped < -3.1415927f) {
        clamped += 6.2831855f;
    }
    
    if (1.5707964f < clamped) {
        return 3.1415927f - clamped;
    }
    if (clamped < -1.5707964f) {
        return -3.1415927f - clamped;
    }
    return clamped;
}

f32 func_misc_004016CC(f32 x, f32 y) {
    f32 mag;


    if (FABS(y) < 0.000001f) {
        if (FABS(x) < 0.000001f) {
            return 0;
        }
    }
    mag = 1.0f / gUvMathExports->uvSqrtf(SQ(y) + SQ(x));
    return gUvMathExports->uvAtan2F(x * mag, y * mag);
}


f32 func_misc_004017A8(Vec2F* arg0) {
    return SQ(arg0->y) + SQ(arg0->x);
}

f32 miscVec2FLen(Vec2F* v) {
    return gUvMathExports->uvSqrtf(func_misc_004017A8(v));
}

void func_misc_004017FC(Vec2F* arg0, Vec2F* arg1) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = miscVec2FLen(arg1);
    if (temp_fv0 < 0.000000001f) {
        arg0->x = 0.0f;
        arg0->y = 0.0f;
        return;
    }
    temp_fv1 = 1.0f / temp_fv0;
    arg0->x = arg1->x * temp_fv1;
    arg0->y = arg1->y * temp_fv1;
}

void func_misc_0040187C(Vec2F* arg0, Vec2F* arg1, f32 arg2, Vec2F* arg3) {
    arg0->x = (arg3->x * arg2) + arg1->x;
    arg0->y = (arg3->y * arg2) + arg1->y;
}

f32 miscVec2FDot(Vec2F* va, Vec2F* vb) {
    return (vb->y * va->y) + (va->x * vb->x);
}

void miscVec2FAdd(Vec2F* vd, Vec2F* va, Vec2F* vb) {
    vd->x = vb->x + va->x;
    vd->y = vb->y + va->y;
}

void miscVec2FSub(Vec2F* vd, Vec2F* va, Vec2F* vb) {
    vd->x = va->x - vb->x;
    vd->y = va->y - vb->y;
}

void miscVec2FMult(Vec2F* vd, f32 sb, Vec2F* arg2) {
    vd->x = arg2->x * sb;
    vd->y = arg2->y * sb;
}

void func_misc_00401938(Vec2F* arg0, UnkStruct_misc_004006A0* arg1) {
    f32 x;
    f32 y;

    x = arg0->x;
    y = arg0->y;
    arg0->x = (arg1->unk10 * y) + (x * arg1->unk0);
    arg0->y = (arg1->unk14 * y) + (x * arg1->unk4);
}

void func_misc_0040197C(Vec2F* arg0, Vec2F* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
}

void func_misc_00401990(Vec2F* arg0, Vec2F* arg1, Vec2F* arg2, f32 arg3) {
    Vec2F sp20;

    miscVec2FMult(&sp20, miscVec2FDot(arg1, arg2) * (1.0f + arg3), arg1);
    miscVec2FSub(arg0, arg2, &sp20);
}

s32 func_misc_004019FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                       f32 *arg8, Vec3F *arg9) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp24;
    f32 sp20;
    f32 sp5C;
    f32 sp58;
    f32 var_fv1;
    f32 var_fa0;
    f32 sp4C;
    f32 sp48;
    f32 temp_fv0_2;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 sp38;
    f32 sp34;
    f32 var_ft5;
    f32 var_fv1_2;
    s32 pad;

    // what?
    sp24 = arg3 - arg1;
    sp74 = sp6C = arg0;
    sp68 = arg1;
    sp70 = arg1;
    if (arg2 < arg0) {
        sp74 = arg2;
    } else {
        sp6C = arg2;
    }
    if (arg3 < arg1) {
        sp70 = arg3;
    } else {
        sp68 = arg3;
    }
    sp38 = arg7;
    if (((((arg5 < sp70) && (arg7 < sp70)) || ((sp68 < arg5) && (sp68 < sp38)))
         || ((arg4 < sp74) && (arg6 < sp74)))
        || ((sp6C < arg4) && (sp6C < arg6))) {
        return 0;
    }
    sp20 = arg2 - arg0;
    sp24 = arg3 - arg1;
    if (sp20 == 0.0) {
        sp34 = 2140143600.0f;
        var_fv1 = sp34;
    } else {
        sp34 = 2140143600.0f;
        var_fv1 = sp24 / sp20;
        sp4C = arg3 - (var_fv1 * arg2);
    }
    sp5C = arg7 - arg5;
    sp58 = arg6 - arg4;
    if (sp58 == 0.0) {
        var_fa0 = sp34;
    } else {
        var_fa0 = sp5C / sp58;
        sp48 = arg7 - (var_fa0 * arg6);
    }
    if (var_fv1 == sp34) {
        sp38 = arg0;
        sp34 = (var_fa0 * sp38) + sp48;
    } else if (var_fa0 == sp34) {
        sp38 = arg4;
        sp34 = (var_fv1 * sp38) + sp4C;
    } else {
        sp38 = (sp4C - sp48) / (var_fa0 - var_fv1);
        sp34 = (var_fv1 * sp38) + sp4C;
    }
    if ((((sp34 < sp70) || (sp68 < sp34)) || (sp38 < sp74)) || (sp6C < sp38)) {
        return 0;
    }
    temp_fv0_2 = gUvMathExports->uvSqrtf(SQ(sp5C) + SQ(sp58));
    if (((arg1 - arg5) * sp58) < ((arg0 - arg4) * sp5C)) {
        arg9->x = sp5C / temp_fv0_2;
        arg9->y = (-sp58) / temp_fv0_2;
        arg9->z = 0.0f;
    } else {
        arg9->x = (-sp5C) / temp_fv0_2;
        arg9->y = sp58 / temp_fv0_2;
        arg9->z = 0.0f;
    }
    temp_fa1 = ((sp38 - arg0) * arg9->x) + ((sp34 - arg1) * arg9->y);
    var_fa0 = ((arg2 - arg0) * arg9->x) + ((arg3 - arg1) * arg9->y);
    if (var_fa0 != 0.0) {
        var_fv1_2 = temp_fa1 / var_fa0;
    } else {
        return 0;
    }
    if (var_fv1_2 < 0) {
        var_fv1_2 = 0;
    } else if (var_fv1_2 > 1.0f) {
        var_fv1_2 = 1.0f;
    }
    *arg8 = var_fv1_2;
    return 1;
}

void miscVec3FAdd(Vec3F* vd, Vec3F* va, Vec3F* vb) {
    vd->x = vb->x + va->x;
    vd->y = vb->y + va->y;
    vd->z = vb->z + va->z;
}

void miscVec3FSub(Vec3F* arg0, Vec3F* arg1, Vec3F* arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;
}

void miscVec3FMult(Vec3F* vd, f32 sb, Vec3F* va) {
    vd->x = va->x * sb;
    vd->y = va->y * sb;
    vd->z = va->z * sb;
}

void func_misc_00401EA8(Vec3F* arg0, UnkStruct_misc_004006A0* arg1) {
    f32 z;
    f32 x;
    f32 y;

    x = arg0->x;
    y = arg0->y;
    z = arg0->z;
    arg0->x = (arg1->unk20 * z) + ((x * arg1->unk0) + (y * arg1->unk10));
    arg0->y = (arg1->unk24 * z) + ((x * arg1->unk4) + (y * arg1->unk14));
    arg0->z = (arg1->unk28 * z) + ((x * arg1->unk8) + (y * arg1->unk18));
}

void miscVec3FSet(Vec3F* arg0, Vec3F* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
}

void func_misc_00401F48(Quat* arg0, Quat* arg1, f32 arg2, Quat* arg3) {
    arg0->x = (arg3->x * arg2) + arg1->x;
    arg0->y = (arg3->y * arg2) + arg1->y;
    arg0->z = (arg3->z * arg2) + arg1->z;
    arg0->w = (arg3->w * arg2) + arg1->w;
}

void func_misc_00401FA0(f32 x, f32 y, f32 z, Quat *quat) {
    f32 temp_ft4;
    f32 sp58;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 sp4C;
    f32 sp48;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 pad;
    f32 temp_fa0;

    temp_fs0 = (x + 1.5707963f) * 0.5f;
    temp_fs1 = gUvMathExports->uvSinF(temp_fs0);
    temp_fs0 = gUvMathExports->uvCosF(temp_fs0);
    temp_fa0 = -y * 0.5f;
    sp4C = gUvMathExports->uvSinF(temp_fa0);
    sp58 = gUvMathExports->uvCosF(temp_fa0);

    sp48 = gUvMathExports->uvSinF(((z - 3.1415927f) * 0.5f));
    temp_fv0 = gUvMathExports->uvCosF(((z - 3.1415927f) * 0.5f));
    temp_fv1 = sp4C * sp48;
    temp_fa0 = sp4C * temp_fv0;
    temp_fa1 = sp58 * temp_fv0;
    temp_ft4 = sp58 * sp48;

    quat->x = (temp_fs0 * temp_fa1) + (temp_fs1 * temp_fv1);
    quat->y = (temp_fs0 * temp_ft4) - (temp_fs1 * temp_fa0);
    quat->z = (temp_fs0 * temp_fa0) + (temp_fs1 * temp_ft4);
    quat->w = (-temp_fs0 * temp_fv1) + (temp_fs1 * temp_fa1);
}

void func_misc_0040213C(Mtx4F *mP, f32 arg1, f32 arg2, f32 arg3) {
    f32 var_fa0;
    f32 var_ft4;
    f32 var_fa1;
    f32 var_fs1;
    f32 var_ft5;
    f32 var_fv1;
    f32 var_fs2;
    f32 var_fs3;

    if (arg1 == 0.0f) {
        var_fs2 = 1.0f;
        var_fs3 = 0.0f;
    } else {
        var_fs3 = gUvMathExports->uvSinF(arg1);
        var_fs2 = gUvMathExports->uvCosF(arg1);
    }
    if (arg2 == 0.0f) {
        var_fa1 = 1.0f;
        var_fs1 = 0.0f;
    } else {
        do {
            var_fs1 = gUvMathExports->uvSinF(arg2);
        } while (0); // FAKE
        var_fa1 = gUvMathExports->uvCosF(arg2);
    }
    if (arg3 == 0.0f) {
        var_fa0 = 1.0f;
        var_fv1 = 0.0f;
        var_ft4 = 0.0f;
        var_ft5 = var_fs1;
    } else {
        var_fv1 = gUvMathExports->uvSinF(arg3);
        var_fa0 = gUvMathExports->uvCosF(arg3);
        var_ft4 = var_fv1 * var_fs1;
        var_ft5 = var_fa0 * var_fs1;
    }
    mP->m[3][0] = 0.0f;
    mP->m[3][1] = 0.0f;
    mP->m[1][2] = var_fs1;
    mP->m[3][2] = 0.0f;
    mP->m[0][3] = 0.0f;
    mP->m[1][3] = 0.0f;
    mP->m[2][3] = 0.0f;
    mP->m[0][0] = (var_fa0 * var_fs2) - (var_ft4 * var_fs3);
    mP->m[1][0] = -var_fa1 * var_fs3;
    mP->m[2][0] = (var_fv1 * var_fs2) + (var_ft5 * var_fs3);
    mP->m[0][1] = (var_fa0 * var_fs3) + (var_ft4 * var_fs2);
    mP->m[1][1] = var_fa1 * var_fs2;
    mP->m[2][1] = (var_fv1 * var_fs3) - (var_ft5 * var_fs2);
    mP->m[0][2] = -var_fv1 * var_fa1;
    mP->m[2][2] = var_fa0 * var_fa1;
    mP->m[3][3] = 1.0f;
}

void func_misc_0040234C(Quat *quat, Mtx4F *arg0) {
    f32 sp44;
    f32 sp40;
    f32 temp_ft5;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    static s32 firstTime = FALSE;

    if (!firstTime) {
        firstTime = TRUE;
        func_misc_0040213C(&D_misc_00404318, -1.5707964f, 0.0f, 3.1415927f);
    }

    sp44 = SQ(quat->x);
    sp40 = SQ(quat->y);
    temp_ft5 = SQ(quat->z);
    sp38 = SQ(quat->w);
    sp30 = quat->y * quat->x;
    sp24 = quat->z * quat->x;
    sp34 = quat->w * quat->x;
    sp2C = quat->z * quat->y;
    sp28 = quat->w * quat->y;
    sp20 = quat->w * quat->z;

    arg0->m[0][0] = ((sp44 + sp40) - temp_ft5) - sp38;
    arg0->m[0][1] = 2.0f * (sp2C + sp34);
    arg0->m[0][2] = 2.0f * (sp28 - sp24);
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 2.0f * (sp2C - sp34);
    arg0->m[1][1] = ((sp44 - sp40) + temp_ft5) - sp38;
    arg0->m[1][2] = 2.0f * (sp20 + sp30);
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 2.0f * (sp24 + sp28);
    arg0->m[2][1] = 2.0f * (sp20 - sp30);
    arg0->m[2][2] = ((sp44 - sp40) - temp_ft5) + sp38;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
    gUvFmtxExports->uvMat4Mul(arg0, arg0, &D_misc_00404318);
}

void func_misc_00402528(Quat *arg0, Quat *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_ft4;

    temp_ft4 = (1.0f - (SQ(arg1->w) + (SQ(arg1->x) + SQ(arg1->y) + SQ(arg1->z)))) * (0.99f / arg5);
    arg0->x = (arg1->x * temp_ft4) + (-0.5f * ((arg1->y * arg4) + (arg1->z * arg3) + (arg1->w * arg2)));
    arg0->y =
        (arg1->y * temp_ft4) + (0.5f * (((arg1->x * arg4) - (arg1->w * arg3)) + (arg1->z * arg2)));
    arg0->z =
        (arg1->z * temp_ft4) + (0.5f * (((arg1->w * arg4) + (arg1->x * arg3)) - (arg1->y * arg2)));
    arg0->w = (arg1->w * temp_ft4) + (0.5f * ((-arg1->z * arg4) + (arg1->y * arg3) + (arg1->x * arg2)));
}

void func_misc_00402698(Mtx4F *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 temp_fa1;
    f32 temp_fv1;

    *arg1 = func_misc_004016CC(-arg0->m[1][0], arg0->m[1][1]);
    *arg2 =
        func_misc_004016CC(arg0->m[1][2], gUvMathExports->uvSqrtf(SQ(arg0->m[1][0]) + SQ(arg0->m[1][1])));
    *arg3 = func_misc_004016CC(-arg0->m[0][2], arg0->m[2][2]);
}

f32 func_misc_00402730(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    f32 sp2C;
    f32 temp_fa1_2;

    *arg6 = gUvMathExports->uvLength2D(arg4 - arg2, (arg5 - arg3));
    temp_fa1_2 = SQ(*arg6);
    if (0.000001f < temp_fa1_2) {
        sp2C = (((arg3 - arg1) * (arg3 - arg5)) - ((arg2 - arg0) * (arg4 - arg2))) / temp_fa1_2;
        *arg7 = (((arg3 - arg1) * (arg4 - arg2)) - ((arg2 - arg0) * (arg5 - arg3))) / temp_fa1_2;;
        if ((*arg7 * *arg6) > 0.0f) {
            *arg8 = *arg7 * *arg6;
        } else {
            *arg8 = -(*arg7 * *arg6);
        }
    } else {
        sp2C = 1.0f;
        *arg7 = 1.0f;
        *arg8 = 1.0f;
    }
    return sp2C;
}

void func_misc_00402874(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5) {
    char pad[0x8];
    s32* sp7C;
    s32 i;
    s32 temp_v0;
    s32 sp70;
    f32 sp6C;
    
    *arg4 = -1000000.0f;
    *arg5 = 1000000.0f;
    // TODO: Remove this cast
    temp_v0 = gUvTerraExports->func_uvterra_rom_00401E64(arg0, arg1, arg2, (void*)&sp7C);
    if (temp_v0 == 0) {
        return;
    }
    
    i = 0;
    if (temp_v0 > 0) {
        do {
            gUvTerraExports->func_uvterra_rom_00400E70(arg0, sp7C[i], arg1, arg2, &sp6C, &sp70);
            if (sp6C <= arg3) {
                if (*arg4 < sp6C) {
                    *arg4 = sp6C;
                } else if (sp6C < *arg5) {
                    *arg5 = sp6C;
                }
            }
        } while (++i != temp_v0);
    }
}

void func_misc_004029DC(s32 arg0, u8* arg1, f32 arg2) {
    f32* var_v1;
    ParsedUVTX* uvtr;

    uvtr = uvGetLoadedFile('UVTX', arg0);
    if (uvtr == NULL) {
        return;
    }
    if (arg1[1] == '1') {
        var_v1 = (void*) uvtr->unk4;
    } else {
        var_v1 = (void*) uvtr->size.as_s32;
    }
    if (var_v1 == NULL) {
        return;
    }
            
    if (arg1[0] == 'u') {
        var_v1[2] = arg2;
        return;
    }
    var_v1[3] = arg2;
}

void func_misc_00402A5C(Mtx4F* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 temp_fv0;
    temp_fs0 = gUvMathExports->uvSinF(arg6);
    temp_fs1 = gUvMathExports->uvCosF(arg6);
    sp3C = gUvMathExports->uvSinF(arg5);
    sp38 = gUvMathExports->uvCosF(arg5);
    sp34 = gUvMathExports->uvSinF(arg4);
    temp_fv0 = gUvMathExports->uvCosF(arg4);
    arg0->m[0][0] = (temp_fs1 * temp_fv0) - (temp_fs0 * (sp3C * sp34));
    arg0->m[0][1] = (temp_fs1 * sp34) + (temp_fs0 * (sp3C * temp_fv0));
    arg0->m[0][2] = -temp_fs0 * sp38;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = -sp38 * sp34;
    arg0->m[1][1] = sp38 * temp_fv0;
    arg0->m[1][2] = sp3C;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = (temp_fs0 * temp_fv0) + (temp_fs1 * (sp3C * sp34));
    arg0->m[2][1] = (temp_fs0 * sp34) - (temp_fs1 * (sp3C * temp_fv0));
    arg0->m[2][2] = temp_fs1 * sp38;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = arg1;
    arg0->m[3][1] = arg2;
    arg0->m[3][2] = arg3;
    arg0->m[3][3] = 1.0f;
}

void func_misc_00402BFC(Vec3F* arg0, Vec3F* arg1, f32 arg2) {
    f32 temp_fv0_3;
    Vec3F* ptr;
    f32 temp_fv0;
    f32 var_fv1;
    Vec3F sp2C;

    temp_fv0 = gUvFvecExports->uvVec3FLen(arg0);
    if ((temp_fv0 < 0.001f)) {
        return;
    }
    gUvFvecExports->uvVec3FNormalize(&sp2C, arg0);
    var_fv1 = gUvFvecExports->uvVec3FDot(&sp2C, arg1);
    if (var_fv1 > 0.0f) {
        var_fv1 = -var_fv1;
    }

    ptr = &sp2C;
    temp_fv0_3 = (-2.0f * var_fv1);
    arg0->x = ptr->x + (temp_fv0_3 * arg1->x);
    arg0->y = ptr->y + (temp_fv0_3 * arg1->y);
    arg0->z = ptr->z + (temp_fv0_3 * arg1->z);
    gUvFvecExports->uvVec3FNormalize(arg0, arg0);
    arg2 *= temp_fv0;
    arg0->x *= arg2;
    arg0->y *= arg2;
    arg0->z *= arg2;
}

f32 func_misc_00402D48(f32 arg0) {
    f32 temp_fv0;
    f32 var_fa1;
    f32 var_fv1;
    u16 i;

    if ((arg0 > 0.0f) || (arg0 < -5.0f)) {
        return 1.0f;
    }
    temp_fv0 = arg0 - (s32) arg0;
    var_fv1 = temp_fv0;
    var_fa1 = 1.0f + temp_fv0;
    if (!(temp_fv0 < 0.00001) || !(-0.00001 < temp_fv0)) {
        for (i = 2; i < 9; i++) {
            var_fv1 *= temp_fv0 / i;
            var_fa1 += var_fv1;
        }
    }
    switch ((s32) arg0) {
    case 0:
        break;
    case -1:
        var_fa1 *= 0.367879f;
        break;
    case -2:
        var_fa1 *= 0.135335f;
        break;
    case -3:
        var_fa1 *= 0.049787f;
        break;
    case -4:
        var_fa1 *= 0.018316f;
        break;
    }
    return var_fa1;
}

void func_misc_00402E94(Vec3F* arg0, Vec3F* arg1, Vec3F* arg2, f32 arg3) {
    f32 temp_fv0;

    temp_fv0 = 1.0f - arg3;
    arg0->x = (arg1->x * temp_fv0) + (arg3 * arg2->x);
    arg0->y = (arg1->y * temp_fv0) + (arg3 * arg2->y);
    arg0->z = (arg1->z * temp_fv0) + (arg3 * arg2->z);
}

f32 func_misc_00402EFC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 var_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;

    if (arg1 < arg0) {
        var_fv0 = arg0 - arg1;
        var_fv1 = var_fv0;
    } else {
        var_fv0 = arg0 - arg1;
        var_fv1 = -var_fv0;
    }
    if (var_fv1 < 0.00001f) {
        return arg0;
    }
    if (var_fv0 > 0.0f) {
        var_ft4 = var_fv0;
    } else {
        var_ft4 = -var_fv0;
    }
    if ((arg3 > 0) && (arg3 < var_ft4)) {
        var_ft4 = arg3;
    }
    var_ft4 *= ((arg2 * var_fv0) * D_80025D70);
    if (var_fv0 > 0.0f) {
        var_ft5 = var_fv0;
    } else {
        var_ft5 = -var_fv0;
    }
    
    if (var_ft4 > 0.0f) {
        var_fv1 = var_ft4;
    } else {
        var_fv1 = -var_ft4;
    }
    if (var_ft5 < var_fv1) {
        arg1 = arg0;
    } else {
        arg1 = arg1 + var_ft4;
    }
    return arg1;
}

void func_misc_00403000(Vec3F *arg0, Vec3F *arg1, f32 arg2, f32 arg3) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    temp_fv0 = gUvFvecExports->uvVec3FLen(arg1);
    if (temp_fv0 == 0.0f) {
        return;
    }

    arg1->x = func_misc_00402EFC(arg0->x, arg1->x, arg2, arg3);
    arg1->y = func_misc_00402EFC(arg0->y, arg1->y, arg2, arg3);
    arg1->z = func_misc_00402EFC(arg0->z, arg1->z, arg2, arg3);
    temp_fv0_2 = gUvFvecExports->uvVec3FLen(arg1);
    if (temp_fv0_2 == 0.0f) {
        return;
    }

    temp_fv1 = temp_fv0 / temp_fv0_2;
    arg1->x *= temp_fv1;
    arg1->y *= temp_fv1;
    arg1->z *= temp_fv1;
}

s32 func_misc_00403110(Mtx4F* arg0, s32 dobj, s32 arg2, s32 arg3) {
    s32 var_s5;
    s32 j;
    s32 var_s1;
    s32 model;
    s32 i;
    s32 sp98;
    s32 sp94;
    s32 var_s4;
    Mtx4F sp50;

    model = gUvDobjExports->uvDobjGetModel(dobj);
    gUvModelExports->uvModelGetProps(model, 4, &sp94, 0);
    gUvModelExports->func_uvmodel_rom_00402AD0();
    var_s5 = -1;
    var_s4 = 0;
    for (i = 0; i < sp94; i++) {
        gUvModelExports->uvModelGetProps(model, 7, i, &sp98, 0);
        if (var_s5 >= sp98) {
            var_s1 = (var_s5 - sp98) + 1;
        } else {
            var_s1 = 0;
        }
        var_s5 = sp98;
        for (j = 0; j < var_s1; j++) {
            gUvModelExports->func_uvmodel_rom_00402B98();
        }
        gUvDobjExports->uvDobjGetPosm(dobj, i, &sp50);
        gUvModelExports->func_uvmodel_rom_00402AFC(&sp50);
        
        if (i >= arg2) {
            if (var_s4 >= arg3) {
                return var_s4;
            }
            gUvFmtxExports->uvMat4FCopy((u32)arg0 + (var_s4 * sizeof(Mtx4F)), gUvModelExports->func_uvmodel_rom_00402AE0());
            var_s4++;
        }
    }
    return var_s4;
}

void miscLoadFileRomModule(void) {
    uvLoadModule('filr');
}

void miscUnloadFileRomModule(void) {
    uvUnloadModule('filr');
}

s32 func_misc_00403348(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                       f32 *arg7) {
    u8 sp4F;
    u8 sp4E;
    f32 temp_ft5;
    f32 sp44;
    f32 temp_fa0_3;
    f32 temp_fv1_5;
    f32 ft4;
    f32 temp_fv0;
    f32 sp30;
    f32 fa1;
    f32 tmp;
    
    sp4F = 0;
    sp4E = 0;
    temp_ft5 = 0;
    if (gUvMathExports->uvSqrtf(SQ(arg0 - arg4) + SQ(arg1 - arg5)) < arg6) {
        sp4F = 1;
    }

    if (gUvMathExports->uvSqrtf(SQ(arg2 - arg4) + SQ(arg3 - arg5)) < arg6) {
        sp4E = 1;
    }
    if (sp4F && sp4E) {
        *arg7 = 1.0f;
        return 1;
    }
    temp_ft5 = arg2 - arg0;
    sp44 = arg3 - arg1;
    fa1 = SQ(temp_ft5) + SQ(sp44);
    if (fa1 == 0) {
        *arg7 = 0;
        return 0;
    }
    tmp = ((arg0 - arg4) * temp_ft5) + (sp44 * (arg1 - arg5));
    ft4 = 2.0f * tmp;
    sp44 = (SQ(arg0 - arg4)) + (SQ(arg1 - arg5));
    sp30 = SQ(ft4) - ((4.0f * fa1) * (sp44 - (arg6 * arg6)));
    
    if (SQ(ft4) < ((4.0f * fa1) * (((SQ(arg0 - arg4)) + (SQ(arg1 - arg5))) - SQ(arg6)))) {
        *arg7 = 0.0f;
        return 0;
    }
    temp_fv0 = gUvMathExports->uvSqrtf(sp30);
    sp4F = 0;
    sp4E = 0;
    temp_fa0_3 = ((-ft4) - temp_fv0) / (2.0f * fa1);
    if ((temp_fa0_3 >= 0.0f) && (temp_fa0_3 <= 1.0f)) {
        sp4F = 1;
    }
    temp_fv1_5 = ((-ft4) + temp_fv0) / (2.0f * fa1);
    if ((temp_fv1_5 >= 0.0f) && (temp_fv1_5 <= 1.0f)) {
        sp4E = 1;
    }
    if (sp4F && sp4E) {
        if (temp_fv1_5 < temp_fa0_3) {
            *arg7 = temp_fa0_3 - temp_fv1_5;
        } else {
            *arg7 = temp_fv1_5 - temp_fa0_3;
        }
        return 1;
    }
    if (sp4F) {
        *arg7 = 1.0f - temp_fa0_3;
        return 1;
    }
    if (sp4E) {
        *arg7 = temp_fv1_5;
        return 1;
    }
    *arg7 = 0.0f;
    return 0;
}

void func_misc_00403650(s32 arg0, s32 profiler, s32 y) {
    f64 spA8;
    u8 buf[130];

    uvProfilerGetProps(profiler, 3, &spA8, 0);
    sprintf(buf, "%13.13s %5.2f", arg0, (f32)(f64)(spA8 * 1000.0));
    gUvFontExports->uvSetFont(3);
    gUvFontExports->uvFontColor(255, 0, 0, 255);
    gUvFontExports->uvFontScale(1.0, 1.0);
    gUvFontExports->uvFontPrintStr(160, y, buf);
    gUvFontExports->uvFontGenDList();
}

f32 func_misc_00403748(UnkStruct_misc_00403748* arg0, Vec3F* arg1, Vec3F* arg2) {
    Vec3F sp3C;
    Vec3F sp30;
    f32 temp_fa0;
    f32 sp28;
    s32 var_v0;
    s32 var_v1;

    gUvFvecExports->uvVec3FSub(&sp3C, &arg0->unk0, arg1);
    if (SQ(arg0->unk18) < gUvFvecExports->uvVec3FLenSquared(&sp3C)) {
        return 0.0f;
    }
    gUvFvecExports->uvVec3FSub(&sp30, &arg0->unk0, arg2);
    sp28 = gUvFvecExports->uvVec3FDot(&arg0->unkC, &sp3C);
    temp_fa0 = gUvFvecExports->uvVec3FDot(&arg0->unkC, &sp30);
    if (sp28 >= 0) {
        var_v1 = 1;
    } else {
        var_v1 = -1;
    }
    
    if (temp_fa0 >= 0) {
        var_v0 = 1;
    } else {
        var_v0 = -1;
    }
    if (var_v0 == var_v1) {
        return 0.0f;
    }
    if ((sp28 < 0.0f) && (arg0->unk1C == 0)) {
        return 0.0f;
    }
    if (sp28 >= 0) {
        var_v0 = 1;
    } else {
        var_v0 = -1;
    }
    return var_v0 * (temp_fa0 / (sp28 - temp_fa0));
}

GuiMenuItem* func_misc_004038D8(GuiMenuOption* menuOption, u8* label, s16 arg2, f32 arg3, f32 arg4, s32* arg5, GuiSlider** arg6) {
    GuiMenuItem* menuItem;
    GuiSlider* slider;
    f32 var_fv0;

    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, label);
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->func_uvgui_rom_004038D8(slider, arg2);
    if (arg5 != NULL) {
        if (slider->mode & 2) {
            var_fv0 = (f32) *arg5;
        } else {
            var_fv0 =  *(f32*)arg5;
        }
    } else {
        var_fv0 = 0.0f;
    }
    gUvGuiExports->func_uvgui_rom_004037E0(slider, arg3, arg4, var_fv0, arg5);
    gUvGuiExports->uvGuiSliderSetLabel(slider, label);
    gUvGuiExports->func_uvgui_rom_00402268(menuItem, slider);
    if (arg6 != NULL) {
        *arg6 = slider;
    }
    return menuItem;
}

GuiMenuItem* func_misc_00403A5C(GuiMenuOption* arg0, u8* arg1, u8* arg2, u8* arg3, UvGrphStruct* arg4, f32* arg5, Inner30** arg6) {
    GuiMenuItem* menuItem;
    Inner30* temp_v0_2;
    f32 sp2C;

    if (arg5 != NULL) {
        sp2C = *arg5;
    } else {
        sp2C = 0.0f;
    }
    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, arg1);
    gUvGuiExports->uvGuiAddMenuItem(arg0, menuItem);
    temp_v0_2 = gUvGuiExports->func_uvgui_rom_00403EE0(gUvGuiExports->func_uvgui_rom_00403E78());
    gUvGuiExports->func_uvgui_rom_004023A8(menuItem, temp_v0_2);
    gUvGuiExports->func_uvgui_rom_00403F2C(temp_v0_2, arg3, arg2);
    gUvGuiExports->uvGuiProps(temp_v0_2, 1, 0, 0);
    gUvGuiExports->func_uvgui_rom_00404010(temp_v0_2, arg4, arg4->arr->x, arg4->arr[arg4->count - 1].x, sp2C, arg5);
    if (arg6 != NULL) {
        *arg6 = temp_v0_2;
    }
    return menuItem;
}

GuiMenuItem* func_misc_00403BEC(GuiMenuOption* menuOption, u8* itemName, UvGuiCallback callback) {
    GuiMenuItem* menuItem;

    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, itemName);
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    gUvGuiExports->func_uvgui_rom_0040221C(menuItem, 3, callback);
    return menuItem;
}

void func_misc_00403CA4(Vec3F* arg0, Vec3F* arg1) {
    func_misc_00400BF0(gUvFvecExports->uvVec3FDot(arg0, arg1));
}

f32 func_misc_00403CD8(f32 arg0) {
    if (arg0 == 0) {
        return 0;
    }

    if (arg0 < -1.f) {
        arg0 = -1.f;
    } else if (arg0 > 1.f) {
        arg0 = 1.f;
    }

    return gUvMathExports->uvAtan2F(arg0, gUvMathExports->uvSqrtf(1 - SQ(arg0)));
}

s32 func_misc_00403D8C(u8* arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    s16 var_s2;
    s16 var_t4;
    s16 var_v0;
    s16 var_v1;
    s32 var_a1;
    s32 var_t0;
    s16 s0;
    u8* var_s1;
    u8* tmp;
     
    var_s2 = arg6 >> 1;
    var_v0 = arg6 - 1;
    var_v1 = arg7 - 1;
    if (((arg2 < 0) && (arg4 < 0)) || ((var_v0 < arg2) && (var_v0 < arg4))) {
        return 0;
    }
    if (((arg3 < 0) && (arg5 < 0)) || ((((var_v1 < arg3))) && (var_v1 < arg5))) {
        return 0;
    }
    var_a1 = 1;
    if (arg2 < 0) {
        arg2 = 0;
    } else if (var_v0 < arg2) {
        arg2 = var_v0;
    }
    var_t0 = 1;
    if (arg3 < 0) {
        arg3 = 0;
    } else if (var_v1 < arg3) {
        arg3 = var_v1;
    }
    if (arg4 < 0) {
        arg4 = 0;
    } else if (var_v0 < arg4) {
        arg4 = var_v0;
    }
    if (arg5 < 0) {
        arg5 = 0;
    } else if (var_v1 < arg5) {
        arg5 = var_v1;
    }
    var_v0 = arg4 - arg2;
    var_v1 = arg5 - arg3;
    var_s1 = (s16) ((arg3 * var_s2) + (arg2 >> 1)) + arg0;
    if (var_v0 < 0) {
        var_t0 = -1;
        var_v0 = var_v0 * -1;
    }
    if (var_v1 < 0) {
        var_a1 = -1;
        var_v1 = var_v1 * -1;
    }
    if (arg2 & 1) {
        *var_s1 = (*var_s1 & 0xF0) | (arg1 & 0xF);
    } else {
        *var_s1 = (*var_s1 & 0xF) | (arg1 & 0xF0);
    }
    if (var_v0 < var_v1) {
        var_t4 = (var_v0 * 2) - var_v1;
        s0 = (var_v0 - var_v1) * 2;
        while (var_v1--) {
            arg3 += var_a1;
            if (var_t4 > 0) {
                arg2 += var_t0;
                var_t4 += s0;
            } else {
                var_t4 += (s16)(var_v0 * 2);
            }
            if (arg2 & 1) {
                var_s1 = (s16) ((arg3 * var_s2) + (arg2 >> 1)) + arg0;
                *var_s1 = (*var_s1 & 0xF0) | (arg1 & 0xF);
            } else {
                var_s1 = (s16) ((arg3 * var_s2) + (arg2 >> 1)) + arg0;
                *var_s1 = (*var_s1 & 0xF) | (arg1 & 0xF0);
            }
        }
    } else {
        var_t4 = (var_v1 * 2) - var_v0;
        s0 = (var_v1 - var_v0) * 2;
        while (var_v0--) {
            // FAKE
            if (!var_a1) {}
            
            arg2 += var_t0;
            if (var_t4 > 0) {
                arg3 += var_a1;
                var_t4 += s0;
            } else {
                var_t4 += (s16)(var_v1 * 2);
            }
            if (arg2 & 1) {
                var_s1 = (s16) ((arg3 * var_s2) + (arg2 >> 1)) + arg0;
                *var_s1 = (*var_s1 & 0xF0) | (arg1 & 0xF);
            } else {
                var_s1 = (s16) ((arg3 * var_s2) + (arg2 >> 1)) + arg0;
                *var_s1 = (*var_s1 & 0xF) | (arg1 & 0xF0);
            }
        }
    }
    return 1;
}

void miscSetRandSeed(u32 seed) {
    sRandSeed = seed;
}

f32 miscRandFLCG(void) {
    u32 val;
    sRandSeed = (sRandSeed * 1103515245) + 12345;
    val = (sRandSeed >> 16) & 0x7FFF;
    return (f32)val / 0x7FFF;
}

// unused
s32 D_misc_00404308[] = {0x01240000, __entrypoint_func_misc_400000};

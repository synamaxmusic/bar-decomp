// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

static UvMath_Exports *sUvMathExports;
static UvFVec_Rom_Exports *sUvFvecExports;

void __entrypoint_func_uvintersect_rom_400000(UvIntersect_Exports *exports);
void func_uvintersect_rom_00400114(void);
s32 func_uvintersect_rom_00400144(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 *arg10);
s32 func_uvintersect_rom_00400460(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
s32 func_uvintersect_rom_004004C4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s32 func_uvintersect_rom_00400530(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10);
void func_uvintersect_rom_00400700(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, Vec3F *arg10);
s32 _uvSurfGetNorm(Vtx *arg0, s32 arg1, s32 arg2, s32 arg3, Vec3F *arg4, f32 arg5);
s32 func_uvintersect_rom_0040093C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, Vec3F *arg14, f32 *arg15);
s32 func_uvintersect_rom_00400E60(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
s32 func_uvintersect_rom_00400FA8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
s32 func_uvintersect_rom_004010F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14);
s32 func_uvintersect_rom_00401318(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32 *arg17, Vec3F *arg18);
s32 func_uvintersect_rom_0040191C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_uvintersect_rom_00401A2C(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_uvintersect_rom_00401CB0(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_uvintersect_rom_004020A0(Mtx4F *arg0, s16 arg1, Vec3F *arg2);
s32 func_uvintersect_rom_004021A0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 *arg15, Vec3F *arg16);

s32 D_uvintersect_rom_00402660[] = {0x00440000, __entrypoint_func_uvintersect_rom_400000, 0, 0};

void __entrypoint_func_uvintersect_rom_400000(UvIntersect_Exports* exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_uvintersect_rom_00400114 = func_uvintersect_rom_00400114;
    exports->func_uvintersect_rom_004010F0 = func_uvintersect_rom_004010F0;
    exports->func_uvintersect_rom_00400144 = func_uvintersect_rom_00400144;
    exports->func_uvintersect_rom_00401318 = func_uvintersect_rom_00401318;
    exports->func_uvintersect_rom_00400460 = func_uvintersect_rom_00400460;
    exports->func_uvintersect_rom_0040191C = func_uvintersect_rom_0040191C;
    exports->func_uvintersect_rom_004004C4 = func_uvintersect_rom_004004C4;
    exports->func_uvintersect_rom_00401A2C = func_uvintersect_rom_00401A2C;
    exports->func_uvintersect_rom_00400530 = func_uvintersect_rom_00400530;
    exports->func_uvintersect_rom_00401CB0 = func_uvintersect_rom_00401CB0;
    exports->func_uvintersect_rom_00400700 = func_uvintersect_rom_00400700;
    exports->func_uvintersect_rom_004020A0 = func_uvintersect_rom_004020A0;
    exports->_uvSurfGetNorm = _uvSurfGetNorm;
    exports->func_uvintersect_rom_004021A0 = func_uvintersect_rom_004021A0;
    exports->func_uvintersect_rom_0040093C = func_uvintersect_rom_0040093C;
    exports->func_uvintersect_rom_00400E60 = func_uvintersect_rom_00400E60;
    exports->func_uvintersect_rom_00400FA8 = func_uvintersect_rom_00400FA8;
    #ifdef __sgi
    #line 1
    #endif
    sUvMathExports = uvLoadModule('MATH');
    sUvFvecExports = uvLoadModule('FVEC');
}

void func_uvintersect_rom_00400114(void) {
    uvUnloadModule('MATH');
    uvUnloadModule('FVEC');
}

s32 func_uvintersect_rom_00400144(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                                  f32 arg7, f32 arg8, f32 arg9, f32 *arg10) {
    f32 temp_fv0;
    f32 sp68;
    f32 sp64;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa1;
    f32 temp_ft4;
    s32 ret;
    f32 temp_fv0_2;
    s32 var_v0_2;
    f32 temp_fv1_2;
    s32 var_v1;

    temp_fv0 = SQ(arg3 - arg0) + SQ(arg4 - arg1) + SQ(arg5 - arg2);
    if (temp_fv0 == 0.0f) {
        ret = func_uvintersect_rom_00400460(arg0, arg1, arg2, arg6, arg7, arg8, arg9);
        if (ret) {
            *arg10 = 0.0f;
        }
        return ret;
    }
    temp_fv0_2 = arg0 - arg6;
    temp_fv1_2 = arg1 - arg7;
    temp_fa0 = arg2 - arg8;
    sp68 = 2.0f
           * (((arg3 - arg0) * (arg0 - arg6)) + ((arg4 - arg1) * (arg1 - arg7))
              + ((arg5 - arg2) * (arg2 - arg8)));
    sp64 = (SQ(arg0 - arg6) + SQ(arg1 - arg7) + SQ(arg2 - arg8)) - SQ(arg9);
    var_v0_2 = 0;
    if (sUvMathExports->uvSqrtf(SQ(arg0 - arg6) + SQ(arg1 - arg7) + SQ(arg2 - arg8))
        < arg9) {
        var_v0_2 = 1;
    }
    temp_fv0_2 = arg3 - arg6;
    temp_fv1_2 = arg4 - arg7;
    temp_fa1 = arg5 - arg8;
    if ((sUvMathExports->uvSqrtf(SQ(temp_fv0_2) + SQ(temp_fv1_2) + SQ(temp_fa1)) < arg9)
        && (var_v0_2 != 0)) {
        *arg10 = 0.0f;
        return 1;
    }
    temp_fv0_2 = sp68 * sp68;
    temp_fv1_2 = 4.0f * temp_fv0 * sp64;
    if (temp_fv0_2 < temp_fv1_2) {
        return 0;
    }
    temp_fv0_2 = sUvMathExports->uvSqrtf(temp_fv0_2 - temp_fv1_2);
    temp_fa1 = ((-sp68) - temp_fv0_2) / (2.0f * temp_fv0);
    temp_ft4 = ((-sp68) + temp_fv0_2) / (2.0f * temp_fv0);
    var_v0_2 = 0;
    var_v1 = 0;

    if ((temp_fa1 >= 0.0f) && (temp_fa1 <= 1.0f)) {
        var_v0_2 = 1;
    }
    if ((temp_ft4 >= 0.0f) && (temp_ft4 <= 1.0f)) {
        var_v1 = 1;
    }
    if ((var_v0_2 != 0) && (var_v1 != 0)) {
        if (temp_fa1 < temp_ft4) {
            *arg10 = temp_fa1;
        } else {
            *arg10 = temp_ft4;
        }
        return 1;
    }
    if (var_v0_2 != 0) {
        *arg10 = temp_fa1;
        return 1;
    }
    if (var_v1 != 0) {
        *arg10 = temp_ft4;
        return TRUE;
    }
    return FALSE;
}

s32 func_uvintersect_rom_00400460(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                                  f32 arg6) {
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = arg0 - arg3;
    temp_fv1 = arg1 - arg4;
    temp_ft4 = arg2 - arg5;
    if ((SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_ft4)) <= SQ(arg6)) {
        return TRUE;
    }
    return FALSE;
}

s32 func_uvintersect_rom_004004C4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                                  f32 arg7) {
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = arg0 - arg4;
    temp_fv1 = arg1 - arg5;
    temp_ft4 = arg2 - arg6;
    temp_ft5 = arg7 + arg3;

    if ((SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_ft4)) <= SQ(temp_ft5)) {
        return TRUE;
    }
    return FALSE;
}

s32 func_uvintersect_rom_00400530(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                                  f32 arg7, f32 arg8, f32 arg9, f32 arg10) {
    f32 sp24;
    f32 sp50;
    f32 temp_fv0;
    Vec3F sp40;
    Vec3F sp34;
    Vec3F sp28;

    sp24 = SQ(arg3 + arg10);
    sp40.x = arg4 - arg0;
    sp40.y = arg5 - arg1;
    sp40.z = arg6 - arg2;
    sp50 = SQ(sp40.x) + SQ(sp40.y) + SQ(sp40.z);
    if (sp50 <= sp24) {
        return 1;
    }
    sp28.x = arg7 - arg4;
    sp28.y = arg8 - arg5;
    sp28.z = arg9 - arg6;

    temp_fv0 = sUvFvecExports->uvVec3FDot(&sp40, &sp28);
    sp50 *= 1.0f - SQ(temp_fv0);
    if (sp24 < sp50) {
        return 0;
    }
    sp34.x = arg7 - arg0;
    sp34.y = arg8 - arg1;
    sp34.z = arg9 - arg2;
    sp50 = SQ(sp34.x) + SQ(sp34.y) + SQ(sp34.z);
    if (sp50 <= sp24) {
        return 1;
    }
    if (temp_fv0 > 0.0f) {
        return 0;
    }
    if (sUvFvecExports->uvVec3FDot(&sp34, &sp28) < 0.0f) {
        return FALSE;
    }
    return TRUE;
}

void func_uvintersect_rom_00400700(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                                   f32 arg7, f32 arg8, f32 arg9, Vec3F *arg10) {
    f32 temp_fv0;
    f32 var_fa0;
    f32 sp2C;
    f32 var_fa1;

    temp_fv0 = sUvMathExports->uvSqrtf(SQ(((((arg3 - arg0) * arg6) + arg0) - arg7))
                                                   + SQ(((((arg4 - arg1) * arg6) + arg1) - arg8))
                                                   + SQ(((((arg5 - arg2) * arg6) + arg2) - arg9)));
    if (temp_fv0 != 0.0f) {
        var_fa0 = ((((arg3 - arg0) * arg6) + arg0) - arg7) / temp_fv0;
        var_fa1 = ((((arg4 - arg1) * arg6) + arg1) - arg8) / temp_fv0;
        sp2C = ((((arg5 - arg2) * arg6) + arg2) - arg9) / temp_fv0;
    } else {
        var_fa0 = 0.0f;
        sp2C = 1.0f;
        var_fa1 = 0.0f;
    }
    arg10->x = var_fa0;
    arg10->y = var_fa1;
    arg10->z = sp2C;
}

s32 _uvSurfGetNorm(Vtx *arg0, s32 arg1, s32 arg2, s32 arg3, Vec3F *arg4, f32 arg5) {
    Vec3F sp3C;
    Vec3F sp30;
    f32 temp_fa0;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = arg0[arg1].v.ob[0];
    temp_fv1 = arg0[arg1].v.ob[1];
    temp_fa0 = arg0[arg1].v.ob[2];
    sp3C.x = arg0[arg2].v.ob[0] - temp_fv0;
    sp3C.y = arg0[arg2].v.ob[1] - temp_fv1;
    sp3C.z = arg0[arg2].v.ob[2] - temp_fa0;
    sp30.x = arg0[arg3].v.ob[0] - temp_fv0;
    sp30.y = arg0[arg3].v.ob[1] - temp_fv1;
    sp30.z = arg0[arg3].v.ob[2] - temp_fa0;
    sp3C.z *= arg5;
    sp30.z *= arg5;
    sUvFvecExports->uvVec3FCross(arg4, &sp3C, &sp30);
    if (sUvFvecExports->uvVec3FNormalize(arg4, arg4) == 0) {
        return 0;
    }
    return 1;
}

s32 func_uvintersect_rom_0040093C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                                  f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12,
                                  f32 arg13, Vec3F *arg14, f32 *arg15) {
    Vec3F sp8C;
    Vec3F sp80;
    Vec3F sp74;
    Vec3F sp68;
    Vec3F sp5C;
    Vec3F sp50;
    Vec3F sp44;
    f32 sp40;
    f32 temp_fv0;
    f32 var_fv1_2;
    s32 ret;
    f32 sp30;

    sp74.x = arg8 - arg5;
    sp74.y = arg9 - arg6;
    sp74.z = arg10 - arg7;
    sp74.z *= arg4;
    sp80.x = arg11 - arg5;
    sp80.y = arg12 - arg6;
    sp80.z = arg13 - arg7;
    sp80.z *= arg4;
    sUvFvecExports->uvVec3FCross(&sp8C, &sp74, &sp80);
    if (sUvFvecExports->uvVec3FNormalize(&sp8C, &sp8C) == 0) {
        return 0;
    }
    sp68.x = arg0 - arg5;
    sp68.y = arg1 - arg6;
    sp68.z = arg2 - arg7;
    sp68.z = sp68.z * arg4;
    temp_fv0 = sUvFvecExports->uvVec3FDot((Vec3F *) &sp68, &sp8C);
    if (arg3 < FABS(temp_fv0)) {
        return 0;
    }

    sp40 = sUvMathExports->uvSqrtf(SQ(arg3) - SQ(temp_fv0));
    sp30 = 10000000000.0f;


    sUvFvecExports->uvVec3FCross(&sp5C, &sp8C, (Vec3F *) &sp74);
    sUvFvecExports->uvVec3FNormalize(&sp5C, &sp5C);
    var_fv1_2 = sUvFvecExports->uvVec3FDot((Vec3F *) &sp68, &sp5C);
    if (var_fv1_2 < 0) {
        sp30 = var_fv1_2;
        sUvFvecExports->uvVec3FCopy(&sp44, &sp5C);
    }
    if (var_fv1_2 < -sp40) {
        return 0;
    }

    sp50.x = arg11 - arg8;
    sp50.y = arg12 - arg9;
    sp50.z = arg13 - arg10;
    sp68.x = arg0 - arg8;
    sp68.y = arg1 - arg9;
    sp68.z = arg2 - arg10;
    sp68.z *= arg4;
    sp50.z *= arg4;
    sUvFvecExports->uvVec3FCross(&sp5C, &sp8C, (Vec3F *) &sp50);
    sUvFvecExports->uvVec3FNormalize(&sp5C, &sp5C);
    var_fv1_2 = sUvFvecExports->uvVec3FDot((Vec3F *) &sp68, &sp5C);
    if ((var_fv1_2 < sp30) && (var_fv1_2 < 0)) {
        sp30 = var_fv1_2;
        sUvFvecExports->uvVec3FCopy(&sp44, &sp5C);
    }
    if (var_fv1_2 < -sp40) {
        return 0;
    }
    sp50.x = arg5 - arg11;
    sp50.y = arg6 - arg12;
    sp50.z = arg7 - arg13;
    sp68.x = arg0 - arg11;
    sp68.y = arg1 - arg12;
    sp68.z = arg2 - arg13;
    sp68.z *= arg4;
    sp50.z *= arg4;

    sUvFvecExports->uvVec3FCross(&sp5C, &sp8C, &sp50);
    sUvFvecExports->uvVec3FNormalize(&sp5C, &sp5C);
    var_fv1_2 = sUvFvecExports->uvVec3FDot(&sp68, &sp5C);
    if ((var_fv1_2 < sp30) && (var_fv1_2 < 0)) {
        sp30 = var_fv1_2;
        sUvFvecExports->uvVec3FCopy(&sp44, &sp5C);
    }
    if (var_fv1_2 < -sp40) {
        return 0;
    }
    if (sp30 < 0) {
        *arg15 = sUvMathExports->uvSqrtf(SQ(temp_fv0) + SQ(sp30));
        ret = 2;
    } else {
        *arg15 = temp_fv0;
        ret = 1;
    }
    arg14->x = sp8C.x;
    arg14->y = sp8C.y;
    arg14->z = sp8C.z;
    return ret;
}

s32 func_uvintersect_rom_00400E60(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                                  f32 arg7, f32 arg8) {
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    s32 var_v0;

    if (arg8 != 1.0f) {
        temp_fv0 = 1.0f / arg8;
        arg2 *= temp_fv0;
        arg3 *= temp_fv0;
        arg4 *= temp_fv0;
        arg5 *= temp_fv0;
        arg6 *= temp_fv0;
        arg7 *= temp_fv0;
    }
    if (((arg1 - arg3) * (arg4 - arg2)) < ((arg0 - arg2) * (arg5 - arg3))) {
        return FALSE;
    }
    if (((arg1 - arg5) * (arg6 - arg4)) < ((arg0 - arg4) * (arg7 - arg5))) {
        return FALSE;
    }
    if (((arg1 - arg7) * (arg2 - arg6)) < ((arg0 - arg6) * (arg3 - arg7))) {
        return FALSE;
    }
    return TRUE;
}

s32 func_uvintersect_rom_00400FA8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 temp_fv0;

    if (arg8 != 1.0f) {
        temp_fv0 = 1.0f / arg8;
        arg2 *= temp_fv0;
        arg3 *= temp_fv0;
        arg4 *= temp_fv0;
        arg5 *= temp_fv0;
        arg6 *= temp_fv0;
        arg7 *= temp_fv0;
    }
    if (((arg0 - arg2) * (arg5 - arg3)) < ((arg1 - arg3) * (arg4 - arg2))) {
        return FALSE;
    }
    if (((arg0 - arg4) * (arg7 - arg5)) < ((arg1 - arg5) * (arg6 - arg4))) {
        return FALSE;
    }
    if (((arg0 - arg6) * (arg3 - arg7)) < ((arg1 - arg7) * (arg2 - arg6))) {
        return FALSE;
    }
    return TRUE;
}

s32 func_uvintersect_rom_004010F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12,
                  f32 arg13, f32 arg14) {
    s32 pad;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = arg0 - arg6;
    temp_fv1 = arg1 - arg7;
    temp_fa0 = arg2 - arg8;
    temp_fa1 = arg9 - arg6;
    temp_ft4 = arg10 - arg7;
    temp_ft5 = arg11 - arg8;
    if ((((((temp_fv1 * temp_ft5) - (temp_fa0 * temp_ft4)) * arg3) - (((temp_fv0 * temp_ft5) - (temp_fa0 * temp_fa1)) * arg4)) +
         (((temp_fv0 * temp_ft4) - (temp_fv1 * temp_fa1)) * arg5)) > 0.0f) {
        return 0;
    }

    temp_fv0 = arg0 - arg9;
    temp_fv1 = arg1 - arg10;
    temp_fa0 = arg2 - arg11;
    temp_fa1 = arg12 - arg9;
    temp_ft4 = arg13 - arg10;
    temp_ft5 = arg14 - arg11;
    if ((((((temp_fv1 * temp_ft5) - (temp_fa0 * temp_ft4)) * arg3) - (((temp_fv0 * temp_ft5) - (temp_fa0 * temp_fa1)) * arg4)) +
         (((temp_fv0 * temp_ft4) - (temp_fv1 * temp_fa1)) * arg5)) > 0.0f) {
        return 0;
    }

    temp_fv0 = arg0 - arg12;
    temp_fv1 = arg1 - arg13;
    temp_fa0 = arg2 - arg14;
    temp_fa1 = arg6 - arg12;
    temp_ft4 = arg7 - arg13;
    temp_ft5 = arg8 - arg14;
    if ((((((temp_fv1 * temp_ft5) - (temp_fa0 * temp_ft4)) * arg3) - (((temp_fv0 * temp_ft5) - (temp_fa0 * temp_fa1)) * arg4)) +
         (((temp_fv0 * temp_ft4) - (temp_fv1 * temp_fa1)) * arg5)) > 0.0f) {
        return 0;
    }

    return 1;
}

s32 func_uvintersect_rom_00401318(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32* arg17, Vec3F* arg18) {
    f32 temp_fa0;
    f32 temp_ft4_2;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fa1_2;
    f32 var_ft4;
    f32 var_ft5;
    Vec3F sp98;
    Vec3F sp8C;
    f32 var_fv0;
    f32 var_fv1;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 pad[2];

    if ((arg15 != 1.0f) || (arg16 != 1.0f)) {
        temp_fv0 = 1.0f / arg15;
        temp_fv1 = 1.0f / arg16;
        arg6 *= temp_fv0;
        arg7 *= temp_fv0;
        arg8 *= temp_fv1;
        arg9 *= temp_fv0;
        arg10 *= temp_fv0;
        arg11 *= temp_fv1;
        arg12 *= temp_fv0;
        arg13 *= temp_fv0;
        arg14 *= temp_fv1;
    }
    var_ft5 = arg0;
    var_fa1 = arg1;
    var_fv1 = arg2;
    var_ft4 = arg0;
    var_fa0 = arg1;
    var_fv0 = arg2;
    if (arg3 < var_ft4) {
        var_ft4 = arg3;
    } else {
        var_ft5 = arg3;
    }
    if (arg4 < arg1) {
        var_fa0 = arg4;
    } else {
        var_fa1 = arg4;
    }
    if (arg5 < arg2) {
        var_fv0 = arg5;
    } else {
        var_fv1 = arg5;
    }
    if (((arg8 < var_fv0) && (arg11 < var_fv0) && (arg14 < var_fv0)) || ((var_fv1 < arg8) && (var_fv1 < arg11) && (var_fv1 < arg14)) || ((arg7 < var_fa0) && (arg10 < var_fa0) && (arg13 < var_fa0)) || ((var_fa1 < arg7) && (var_fa1 < arg10) && (var_fa1 < arg13)) || ((arg6 < var_ft4) && (arg9 < var_ft4) && (arg12 < var_ft4)) || ((var_ft5 < arg6) && (var_ft5 < arg9) && (var_ft5 < arg12))) {
        return 0;
    }
    sp98.x = arg9 - arg6;
    sp8C.x = arg12 - arg6;
    sp98.y = arg10 - arg7;
    sp8C.y = arg13 - arg7;
    sp98.z = arg11 - arg8;
    sp8C.z = arg14 - arg8;
    sUvFvecExports->uvVec3FCross(arg18, &sp98, &sp8C);
    sUvFvecExports->uvVec3FNormalize(arg18, arg18);
    var_fa1_2 = ((arg6 - arg0) * arg18->x) + ((arg7 - arg1) * arg18->y) + ((arg8 - arg2) * arg18->z);
    temp_fa0 = ((arg3 - arg0) * arg18->x) + ((arg4 - arg1) * arg18->y) + ((arg5 - arg2) * arg18->z);
    if (temp_fa0 != 0.0f) {
        temp_fv0 = var_fa1_2 / temp_fa0;
    } else {
        return 0;
    }
    if ((temp_fv0 < 0.0f) || (temp_fv0 > 1.0f)) {
        return 0;
    }
    if (FABS(arg18->z) < 0.1f) {
        if (func_uvintersect_rom_004010F0(((arg3 - arg0) * temp_fv0) + arg0, 
                                          ((arg4 - arg1) * temp_fv0) + arg1, 
                                          ((arg5 - arg2) * temp_fv0) + arg2, 
                                          arg18->x, arg18->y, arg18->z, 
                                          arg6, arg7, arg8, arg9,
                                          arg10, arg11, arg12, arg13, arg14) != 0) {
            *arg17 = temp_fv0;
            return 1;
        }
        *arg17 = 0.0f;
        return 0;
    }
    if (arg18->z > 0.0f) {
        if (func_uvintersect_rom_00400E60(((arg3 - arg0) * temp_fv0) + arg0, ((arg4 - arg1) * temp_fv0) + arg1, 
                                          arg6, arg7, arg9, 
                                          arg10, arg12, arg13, 1.0f) != 0) {
            *arg17 = temp_fv0;
            return 1;
        }
        *arg17 = 0.0f;
        return 0;
    }
    if (func_uvintersect_rom_00400FA8(((arg3 - arg0) * temp_fv0) + arg0, ((arg4 - arg1) * temp_fv0) + arg1, 
                                      arg6, arg7, arg9, arg10,
                                      arg12, arg13, 1.0f) != 0) {
        *arg17 = temp_fv0;
        return 1;
    }
    *arg17 = 0.0f;
    return 0;
}


s32 func_uvintersect_rom_0040191C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    if (arg0 < arg2) {
        if (arg2 < arg4) {
            return FALSE;
        }
        if (arg5 < arg0) {
            return FALSE;
        }
    } else {
        if (arg0 < arg4) {
            return FALSE;
        }
        if (arg5 < arg2) {
            return FALSE;
        }
    }
    if (arg1 < arg3) {
        if (arg3 < arg6) {
            return FALSE;
        }
        if (arg7 < arg1) {
            return FALSE;
        }
    } else {
        if (arg1 < arg6) {
            return FALSE;
        }
        if (arg7 < arg3) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_uvintersect_rom_00401A2C(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_ft5;
    f32 sp10;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;

    var_fv0 = *arg0;
    var_fv1 = *arg1;
    var_fa0 = *arg2;
    var_fa1 = *arg3;
    if (var_fa0 == var_fv0) {
        if (var_fv0 < arg4) {
            var_fa0 = arg4;
            var_fv0 = arg4;
        } else if (arg5 < var_fv0) {
            var_fa0 = arg5;
            var_fv0 = arg5;
        }
        if (var_fv1 < arg6) {
            var_fv1 = arg6;
        } else if (arg7 < var_fv1) {
            var_fv1 = arg7;
        }
        if (var_fa1 < arg6) {
            var_fa1 = arg6;
        } else if (arg7 < var_fa1) {
            var_fa1 = arg7;
        }
        *arg0 = var_fv0;
        *arg1 = var_fv1;
        *arg2 = var_fa0;
        *arg3 = var_fa1;
    } else {
        temp_ft5 = (var_fa1 - var_fv1) / (var_fa0 - var_fv0);
        sp10 = var_fa1 - (temp_ft5 * var_fa0);
        if (var_fv0 < arg4) {
            var_fv1 = (temp_ft5 * arg4) + sp10;
            var_fv0 = arg4;
        } else if (arg5 < var_fv0) {
            var_fv1 = (temp_ft5 * arg5) + sp10;
            var_fv0 = arg5;
        }
        if (var_fv1 < arg6) {
            var_fv1 = arg6;
            if (temp_ft5 != 0.0f) {
                var_fv0 = (arg6 - sp10) / temp_ft5;
            }
        } else if (arg7 < var_fv1) {
            var_fv1 = arg7;
            if (temp_ft5 != 0.0f) {
                var_fv0 = (arg7 - sp10) / temp_ft5;
            }
        }
        if (var_fa0 < arg4) {
            var_fa0 = arg4;
            var_fa1 = (temp_ft5 * arg4) + sp10;
        } else if (arg5 < var_fa0) {
            var_fa0 = arg5;
            var_fa1 = (temp_ft5 * arg5) + sp10;
        }
        if (var_fa1 < arg6) {
            var_fa1 = arg6;
            if (temp_ft5 != 0.0f) {
                var_fa0 = (arg6 - sp10) / temp_ft5;
            }
        } else if (arg7 < var_fa1) {
            var_fa1 = arg7;
            if (temp_ft5 != 0.0f) {
                var_fa0 = (arg7 - sp10) / temp_ft5;
            }
        }
        *arg0 = var_fv0;
        *arg1 = var_fv1;
        *arg2 = var_fa0;
        *arg3 = var_fa1;
    }
}

void func_uvintersect_rom_00401CB0(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 temp_ft4;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs3;
    f32 var_fs2;
    f32 var_fs1;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;

    // clang-format off
    var_fs0 = *arg0; \
    var_fs2 = *arg1; \
    sp4C = *arg2;    \
    var_fs3 = *arg3; \
    var_fs1 = *arg4; \
    sp48 = *arg5;
    // clang-format on

    sp44 = var_fs3 - var_fs0;
    sp40 = var_fs1 - var_fs2;
    sp3C = sp48 - sp4C;

    if (var_fs3 == var_fs0) {
        if (var_fs0 < arg6) {
            var_fs3 = arg6;
            var_fs0 = arg6;
        } else if (arg7 < var_fs0) {
            var_fs3 = arg7;
            var_fs0 = arg7;
        }
        if (var_fs2 < arg8) {
            var_fs2 = arg8;
        } else if (arg9 < var_fs2) {
            var_fs2 = arg9;
        }
        if (var_fs1 < arg8) {
            var_fs1 = arg8;
        } else if (arg9 < var_fs1) {
            var_fs1 = arg9;
        }
        *arg0 = var_fs0;
        *arg1 = var_fs2;
        *arg3 = var_fs3;
        *arg4 = var_fs1;
    } else {
        temp_fv0 = (var_fs1 - var_fs2) / (var_fs3 - var_fs0);
        temp_ft4 = var_fs1 - (temp_fv0 * var_fs3);
        if (var_fs0 < arg6) {
            var_fs2 = (temp_fv0 * arg6) + temp_ft4;
            var_fs0 = arg6;
        } else if (arg7 < var_fs0) {
            var_fs2 = (temp_fv0 * arg7) + temp_ft4;
            var_fs0 = arg7;
        }
        if (var_fs2 < arg8) {
            var_fs2 = arg8;
            if (temp_fv0 != 0.0f) {
                var_fs0 = (arg8 - temp_ft4) / temp_fv0;
            }
        } else if (arg9 < var_fs2) {
            var_fs2 = arg9;
            if (temp_fv0 != 0.0f) {
                var_fs0 = (arg9 - temp_ft4) / temp_fv0;
            }
        }
        if (var_fs3 < arg6) {
            var_fs1 = (temp_fv0 * arg6) + temp_ft4;
            var_fs3 = arg6;
        } else if (arg7 < var_fs3) {
            var_fs1 = (temp_fv0 * arg7) + temp_ft4;
            var_fs3 = arg7;
        }
        if (var_fs1 < arg8) {
            var_fs1 = arg8;
            if (temp_fv0 != 0.0f) {
                var_fs3 = (arg8 - temp_ft4) / temp_fv0;
            }
        } else if (arg9 < var_fs1) {
            var_fs1 = arg9;
            if (temp_fv0 != 0.0f) {
                var_fs3 = (arg9 - temp_ft4) / temp_fv0;
            }
        }

        if ((var_fs0 != *arg0) && (sp44 != 0.0f)) {
            sp4C += sp3C * ((var_fs0 - *arg0) / sp44);
        } else if ((var_fs2 != *arg1) && (sp40 != 0.0f)) {
            sp4C += sp3C * ((var_fs2 - *arg1) / sp40);
        }
        if ((var_fs3 != *arg3) && (sp44 != 0.0f)) {
            sp48 += sp3C * ((var_fs3 - *arg3) / sp44);
        } else if ((var_fs1 != *arg4) && (sp40 != 0.0f)) {
            sp48 += sp3C * ((var_fs1 - *arg4) / sp40);
        }
        *arg0 = var_fs0;
        *arg1 = var_fs2;
        *arg2 = sp4C;
        *arg3 = var_fs3;
        *arg4 = var_fs1;
        *arg5 = sp48;
    }
}

void func_uvintersect_rom_004020A0(Mtx4F *arg0, s16 arg1, Vec3F *arg2) {
    s32 c = (s32) arg1;
    switch (c) {
        case -1:
            arg2->x = -arg0->m[0][0];
            arg2->y = -arg0->m[0][1];
            arg2->z = -arg0->m[0][2];
            break;

        case 1:
            arg2->x = arg0->m[0][0];
            arg2->y = arg0->m[0][1];
            arg2->z = arg0->m[0][2];
            break;

        case -2:
            arg1++; // FAKE
            arg1--;
            arg2->x = -arg0->m[1][0];
            arg2->y = -arg0->m[1][1];
            arg2->z = -arg0->m[1][2];
            break;

        case 2:
            arg2->x = arg0->m[1][0];
            arg2->y = arg0->m[1][1];
            arg2->z = arg0->m[1][2];
            break;

        case -3:
            arg2->x = -arg0->m[2][0];
            arg2->y = -arg0->m[2][1];
            arg2->z = -arg0->m[2][2];
            break;

        case 3:
            arg2->x = arg0->m[2][0];
            arg2->y = arg0->m[2][1];
            arg2->z = arg0->m[2][2];
            break;

        default:
            break;
    }
}

s32 func_uvintersect_rom_004021A0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32* arg15, Vec3F* arg16) {
    f32 temp_fa0;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv1;
    f32 var_fa1;
    s32 pad[7];
  
    if (arg0 < arg3) {
        var_fv0 = arg0;
        var_fv1 = arg3;
    } else {
        var_fv0 = arg3;
        var_fv1 = arg0;
    }
    if (((arg6 < var_fv0) && 
         (arg9 < var_fv0) && (arg12 < var_fv0)) ||
        ((var_fv1 < arg6) && (var_fv1 < arg9) && 
         (var_fv1 < arg12))) {
        return 0;
    }
    if (arg1 < arg4) {
        var_fv0 = arg1;
        var_fv1 = arg4;
    } else {
        var_fv0 = arg4;
        var_fv1 = arg1;
    }
    if (((arg7 < var_fv0) && (arg10 < var_fv0) &&
         (arg13 < var_fv0)) || ((var_fv1 < arg7) && 
        (var_fv1 < arg10) && (var_fv1 < arg13))) {
        return 0;
    }
    if (arg2 < arg5) {
        var_fv0 = arg2;
        var_fv1 = arg5;
    } else {
        var_fv0 = arg5;
        var_fv1 = arg2;
    }
    if (((arg8 < var_fv0) && (arg11 < var_fv0) && (arg14 < var_fv0)) || 
        ((var_fv1 < arg8) && (var_fv1 < arg11) && (var_fv1 < arg14))) {
        return 0;
    }

    var_fa1 = ((arg6 - arg0) * arg16->x) + ((arg7 - arg1) * arg16->y) + ((arg8 - arg2) * arg16->z);
    temp_fa0 = ((arg3 - arg0) * arg16->x) + ((arg4 - arg1) * arg16->y) + ((arg5 - arg2) * arg16->z);
    if (temp_fa0 == 0.0f) {
        return 0;
    }
    var_fv0_2 = var_fa1 / temp_fa0;
    *arg15 = var_fv0_2;

    if ((var_fv0_2 < 0.0f) || (var_fv0_2 > 1.0f)) {
        return 0;
    }

    if ((ABS_2(arg16->z) < 0.1f)) {
        if (func_uvintersect_rom_004010F0(((arg3 - arg0) * var_fv0_2) + arg0, ((arg4 - arg1) * var_fv0_2) + arg1, 
                                          ((arg5 - arg2) * var_fv0_2) + arg2, arg16->x, arg16->y, 
                                          arg16->z, arg6, arg7, arg8, arg9, arg10,
                                          arg11, arg12, arg13, arg14) != 0) {
            return 1;
        }
        return 0;
    }
    if (arg16->z > 0.0f) {
        if (func_uvintersect_rom_00400E60(((arg3 - arg0) * var_fv0_2) + arg0, ((arg4 - arg1) * var_fv0_2) + arg1, 
                                          arg6, arg7, arg9, arg10, arg12, arg13, 1.0f) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_uvintersect_rom_00400FA8(((arg3 - arg0) * var_fv0_2) + arg0, ((arg4 - arg1) * var_fv0_2) + arg1, arg6, 
                                      arg7, arg9, arg10, arg12, arg13, 1.0f) != 0) {
        return 1;
    }
    return 0;
}


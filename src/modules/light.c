// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkStruct_light_00400DC4_s {
    /* 0x00 */ f32 unk0;                                /* inferred */
    /* 0x04 */ f32 unk4;                                /* inferred */
    /* 0x08 */ f32 unk8;                                /* inferred */
    /* 0x0C */ f32 unkC;                                /* inferred */
    /* 0x10 */ f32 unk10;                               /* inferred */
    /* 0x14 */ f32 unk14;                               /* inferred */
    /* 0x18 */ f32 unk18;                               /* inferred */
    /* 0x1C */ f32 unk1C;                               /* inferred */
    /* 0x20 */ f32 unk20;                               /* inferred */
    /* 0x24 */ f32 unk24;                               /* inferred */
    /* 0x28 */ u8 unk28;                                /* inferred */
    /* 0x2C */ struct UnkStruct_light_00400DC4_s *next; /* inferred */
} UnkStruct_light_00400DC4;                             /* size = 0x30 */

typedef struct UnkStruct_light_00400DC8_s {
    /* 0x00 */ s32 unk0;                                /* inferred */
    /* 0x04 */ f32 unk4;                                /* inferred */
    /* 0x08 */ f32 unk8;                                /* inferred */
    /* 0x0C */ f32 unkC;                                /* inferred */
    /* 0x10 */ f32 unk10;                               /* inferred */
    /* 0x14 */ f32 unk14;                               /* inferred */
    /* 0x18 */ f32 unk18;                               /* inferred */
    /* 0x1C */ f32 unk1C;                               /* inferred */
    /* 0x20 */ f32 unk20;                               /* inferred */
    /* 0x24 */ f32 unk24;                               /* inferred */
    /* 0x28 */ struct UnkStruct_light_00400DC8_s *next; /* inferred */
} UnkStruct_light_00400DC8;                             /* size = 0x2C */

void func_light_00400090(void);
void func_light_00400098(UnkLightStruct *arg0, s32 arg1);
void func_light_00400120(UnkLightStruct *arg0, s32 arg1, ...);
void func_light_0040050C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                         f32 arg8, f32 arg9, u8 arg10);
void func_light_004008BC(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                         f32 arg8, f32 arg9);
void func_light_00400950(s32 arg0, s32 arg1, s32 arg2);
void func_light_00400BA8(s32 arg0, s32 arg1);
void __entrypoint_func_light_400000(Light_Exports *exports);
void func_light_004005AC(Vec3F *arg0, s32 arg1);

// .data
s32 D_light_00400DB0[] = {0x00200000, __entrypoint_func_light_400000, 0};

// .bss
s32 B_light_00400DC0; // unreferenced padding
UnkStruct_light_00400DC4 *D_light_00400DC4;
UnkStruct_light_00400DC8 *D_light_00400DC8;

void __entrypoint_func_light_400000(Light_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_light_00400090 = func_light_00400090;
    exports->func_light_00400098 = func_light_00400098;
    exports->func_light_00400120 = func_light_00400120;
    exports->func_light_0040050C = func_light_0040050C;
    exports->func_light_004005AC = func_light_004005AC;
    exports->func_light_004008BC = func_light_004008BC;
    exports->func_light_00400950 = func_light_00400950;
    exports->func_light_00400BA8 = func_light_00400BA8;
    D_light_00400DC4 = NULL;
    D_light_00400DC8 = NULL;
}

void func_light_00400090(void) {
}

void func_light_00400098(UnkLightStruct *arg0, s32 arg1) {
    arg0->unk0 = gUvLightExports->func_uvlight_rom_00400B64();
    if (arg0->unk0 == 0xFFFF) {
        return;
    }

    arg0->unk2 = arg1;
    arg0->unk4 = 0.0f;
    arg0->unk8 = 0.0f;
    arg0->unk10 = 0.0f;
    arg0->unk14 = 0.0f;
    arg0->unk24 = 0.0f;
    arg0->unk18 = 0.0f;
    arg0->unk1C = 0.0f;
    arg0->unk20 = 0.0f;
    arg0->unk28 = 0.0f;
    arg0->unkC = -1.0f;
}

void func_light_00400120(UnkLightStruct *arg0, s32 arg1, ...) {
    va_list args;
    s16 temp_v0;

    if (arg0 == NULL) {
        return;
    }

    va_start(args, arg1);
    if (arg1 < 0) {
        return;
    }

    while (TRUE) {
        temp_v0 = va_arg(args, s32);
        switch (temp_v0) {
            case 0:
                return;
            case 1:
                arg0->unk4 = va_arg(args, f64);
                arg0->unk8 = va_arg(args, f64);
                arg0->unkC = va_arg(args, f64);
                gUvLightExports->func_uvlight_rom_00400EDC(arg0->unk0, arg1, (Vec3F *) &arg0->unk4);
                break;
            case 2:
                arg0->unk1C = va_arg(args, f64);
                arg0->unk20 = va_arg(args, f64);
                arg0->unk24 = va_arg(args, f64);
                gUvLightExports->func_uvlight_rom_00400D90(arg0->unk0, arg1, arg0->unk1C, arg0->unk20,
                                                           arg0->unk24);
                break;
            case 3:
                arg0->unk28 = va_arg(args, f64);
                break;
            case 4:
                if (arg0->unk2 == 0) {
                    arg0->unk10 = va_arg(args, f64);
                    arg0->unk14 = va_arg(args, f64);
                    arg0->unk18 = va_arg(args, f64);
                    gUvLightExports->func_uvlight_rom_00400C60(arg1, arg0->unk10, arg0->unk14,
                                                               arg0->unk18);
                }
                break;
            default:
                return;
        }
    }
}

void func_light_0040050C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                         f32 arg8, f32 arg9, u8 arg10) {
    UnkStruct_light_00400DC4 *light;

    light = _uvMemAllocAlign8(sizeof(UnkStruct_light_00400DC4));
    light->unkC = arg0;
    light->unk10 = arg1;
    light->unk14 = arg2;
    light->unk18 = arg7;
    light->unk1C = arg8;
    light->unk20 = arg9;
    light->unk24 = SQ(arg3);
    light->unk0 = arg4;
    light->unk4 = arg5;
    light->unk8 = arg6;
    light->unk28 = arg10;
    light->next = D_light_00400DC4;
    D_light_00400DC4 = light;
}

void func_light_004005AC(Vec3F *arg0, s32 arg1) {
    char pad[0x8];
    UnkStruct_light_00400DC4 *var_s2;
    f32 temp_fa0;
    UnkStruct_light_00400DC4 *spDC[3];
    f32 temp_fa1;
    f32 temp_fv0;
    f32 spC8[3];
    f32 temp_fv1;
    s32 i;
    f32 fv1;
    s32 var_s7;
    s32 var_v0;

    var_s7 = 0;
    for (var_s2 = D_light_00400DC4; var_s2 != NULL; var_s2 = var_s2->next) {
        temp_fv0 = var_s2->unkC - arg0->x;
        temp_fv1 = var_s2->unk10 - arg0->y;
        temp_fa0 = var_s2->unk14 - arg0->z;
        temp_fa1 = SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa0);
        if ((var_s2->unk24 < temp_fa1)) {
            continue;
        }
        fv1 = spC8[0];
        if (var_s7 < 3) {
            spDC[var_s7] = var_s2;
            spC8[var_s7] = temp_fa1;
            var_s7++;
        } else {
            var_v0 = 0;
            for (i = 1; i < 3; i++) {
                if (fv1 < spC8[i]) {
                    fv1 = spC8[i];
                    var_v0 = i;
                }
            }
            if (temp_fa1 < spC8[var_v0]) {
                spDC[var_v0] = var_s2;
                spC8[var_v0] = temp_fa1;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        if (i < var_s7) {
            var_s2 = spDC[i];
            if (var_s2->unk28 == 0) {
                var_s2->unk18 = var_s2->unkC - arg0->x;
                var_s2->unk1C = var_s2->unk10 - arg0->y;
                var_s2->unk20 = var_s2->unk14 - arg0->z;
                gUvFvecExports->uvVec3FNormalize((Vec3F *) &var_s2->unk18, (Vec3F *) &var_s2->unk18);
            }
            temp_fv0 = 1.0f - (spC8[i] / var_s2->unk24);
            temp_fv1 = (var_s2->unk0 * temp_fv0);
            temp_fa0 = (var_s2->unk4 * temp_fv0);
            temp_fa1 = (var_s2->unk8 * temp_fv0);
            func_light_00400120(&gSceneExports->sCurrentScene->unk28[i + 1], arg1, 1, var_s2->unk18,
                                var_s2->unk1C, var_s2->unk20, 2, temp_fv1, temp_fa0, temp_fa1, 3,
                                temp_fv0, 0);
        } else {
            func_light_00400120(&gSceneExports->sCurrentScene->unk28[i + 1], arg1, 1, 0.0f, 0.0f, -1.0f,
                                2, 0.0f, 0.0f, 0.0f, 3, 0.0f, 0);
        }
    }
}

void func_light_004008BC(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                         f32 arg8, f32 arg9) {
    UnkStruct_light_00400DC8 *temp_v0;

    temp_v0 = _uvMemAllocAlign8(sizeof(UnkStruct_light_00400DC8));
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unk8 = arg2;
    temp_v0->unkC = arg3;
    temp_v0->unk10 = arg4;
    temp_v0->unk14 = arg5;
    temp_v0->unk18 = arg6;
    temp_v0->unk1C = arg7;
    temp_v0->unk20 = arg8;
    temp_v0->unk24 = arg9;
    temp_v0->next = D_light_00400DC8;
    D_light_00400DC8 = temp_v0;
}

void func_light_00400950(s32 arg0, s32 arg1, s32 arg2) {
    char pad[8];
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    UnkStruct_light_00400DC8 *var_s0;

    for (var_s0 = D_light_00400DC8; var_s0 != NULL; var_s0 = var_s0->next) {
        if (gVolTestExports->unkC(var_s0->unk0, 2, arg0) != 0) {
            func_light_00400120(gSceneExports->sCurrentScene->unk28, arg2, 1, var_s0->unk1C,
                                var_s0->unk20, var_s0->unk24, 2, var_s0->unk10, var_s0->unk14,
                                var_s0->unk18, 3, 1.0f, 4, var_s0->unk4, var_s0->unk8, var_s0->unkC, 0);
            return;
        }
    }
    gUvEnvExports->uvEnvGetProps(arg1, 6, &sp9C, &spA0, &spA4, 8, &spBC, &spB8, &spB4, 9, &spB0, &spAC,
                                 &spA8, 0);
    func_light_00400120(gSceneExports->sCurrentScene->unk28, arg2, 1, sp9C, spA0, spA4, 2, spB0, spAC,
                        spA8, 3, 1.0f, 4, spBC, spB8, spB4, 0);
}

void func_light_00400BA8(s32 arg0, s32 arg1) {
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    s32 i;

    gUvEnvExports->uvEnvGetProps(arg0, 6, &spC4, &spC8, &spCC, 8, &spE4, &spE0, &spDC, 9, &spD8, &spD4,
                                 &spD0, 0);
    func_light_00400120(gSceneExports->sCurrentScene->unk28, arg1, 1, spC4, spC8, spCC, 2, spD8, spD4,
                        spD0, 3, 1.0f, 4, spE4, spE0, spDC, 0);
    for (i = 0; i < 3; i++) {
        func_light_00400120(&gSceneExports->sCurrentScene->unk28[i + 1], arg1, 1, 0.0f, 0.0f, -1.0f, 2,
                            0.0f, 0.0f, 0.0f, 3, 0.0f, 0);
    }
}

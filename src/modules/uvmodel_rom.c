// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"

typedef struct UnkStruct_uvmodel_rom_00400608_s {
    Vec3F *unk0;
    u8 unk4;
} UnkStruct_uvmodel_rom_00400608;

extern f32 D_uvmodel_rom_00403124;
extern s32 D_uvmodel_rom_00403140;
extern s32 D_uvmodel_rom_00403130;
extern Mtx4F *D_uvmodel_rom_00403160;
extern UvFMtx_Rom_Exports *D_uvmodel_rom_00403164;
extern UvFVec_Rom_Exports *D_uvmodel_rom_00403168;
extern UvQuery_Exports *D_uvmodel_rom_0040316C;
extern UvIntersect_Exports *D_uvmodel_rom_00403170;
extern UvMath_Exports *D_uvmodel_rom_00403174;
extern UvGfxState_Rom_Exports *D_uvmodel_rom_00403178;

s32 func_uvmodel_rom_00402224(f32 arg0, f32 arg1, f32 arg2, uvModelLOD_inner *arg3);

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

s32 func_uvmodel_rom_00400340(s32 arg0) {
    ParsedUVMD *temp_v0;

    temp_v0 = uvGetLoadedFile('UVMD', arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    if (temp_v0->unk0->unk0->unk4 == 0) {
        return 0;
    }
    return &temp_v0->unk0->unk0->stateTable->state;
}

void func_uvmodel_rom_004003A4(s32 fileId, s32 arg1, Mtx4F *arg2) {
    ParsedUVMD *uvmd;

    uvmd = uvGetLoadedFile('UVMD', fileId);
    if ((uvmd == NULL) || (arg1 >= uvmd->unk0->unk8)) {
        return;
    }
    D_uvmodel_rom_00403164->uvMat4FCopy(arg2, &uvmd->unk8[arg1]);
    arg2->m[3][0] /= uvmd->unk10;
    arg2->m[3][1] /= uvmd->unk10;
    arg2->m[3][2] /= uvmd->unk10;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_0040045C.s")

u8 func_uvmodel_rom_00400608(UnkStruct_uvmodel_rom_00400608 *arg0, f32 arg1) {
    s32 var_a1;
    s32 var_v0;
    u8 temp_v0;
    Vec3F *temp_v1;
    u8 i;

    temp_v0 = arg0->unk4;
    temp_v1 = arg0->unk0;

    if (temp_v1->y == 0.0f) {
        return 0;
    }
    if (temp_v1[temp_v0 - 1].y <= arg1) {
        return 0xFF;
    }

    for (i = temp_v0; i > 0; i--) {
        if (temp_v1[i - 1].y < arg1) {
            return i;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_004006B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvmodel_rom/func_uvmodel_rom_0040199C.s")

s32 func_uvmodel_rom_0040215C(f32 x, f32 y, f32 z, Mtx4F* arg3, Vec3F* arg4) {
    Mtx4F mtx4F;
    Vec3F vec;

    if (D_uvmodel_rom_00403124 == arg4->z) {
        return -1;
    }

    vec.x = x;
    vec.y = y;
    vec.z = z;
    
    if (D_uvmodel_rom_00403164->func_00401790(&mtx4F, arg3) == 0) {
        return -1;
    }
    D_uvmodel_rom_00403164->func_00401D0C(&mtx4F, &vec, &vec);
    if (func_uvmodel_rom_00402224(vec.x, vec.y, vec.z, &arg4->z) != 0) {
        return 0;
    }
    return -1;
}

s32 func_uvmodel_rom_00402224(f32 arg0, f32 arg1, f32 arg2, uvModelLOD_inner *arg3) {
    if (arg0 < arg3->unk0) {
        return FALSE;
    }
    if (arg3->unkC < arg0) {
        return FALSE;
    }
    if (arg1 < arg3->unk4) {
        return FALSE;
    }
    if (arg3->unk10 < arg1) {
        return FALSE;
    }
    if (arg2 < arg3->unk8) {
        return FALSE;
    }
    if (arg3->unk14 < arg2) {
        return FALSE;
    }
    return TRUE;
}

u8 func_uvmodel_rom_004022E4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                             UnkUVMD_24_Unk4 *arg6, f32 *arg7, f32 *arg8, s16 *arg9, s16 *arg10) {
    s32 i;
    f32 *sp5C[2];
    s16 *sp54[2];
    s32 pad[2];
    f32 var_fa0;
    f32 sp44;
    f32 sp40;
    f32 var_fa1;
    f32 sp38;
    f32 sp34;
    f32 var_fv1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fa0;
    f32 temp_fa1;

    i = 0;

    sp5C[0] = arg7;
    sp5C[1] = arg8;
    sp54[0] = arg9;
    sp54[1] = arg10;
    if (arg3 < arg0) {
        sp44 = arg0;
        sp38 = arg3;
    } else {
        sp44 = arg3;
        sp38 = arg0;
    }
    if (arg4 < arg1) {
        sp40 = arg1;
        sp34 = arg4;
    } else {
        sp40 = arg4;
        sp34 = arg1;
    }
    if (arg5 < arg2) {
        var_fa1 = arg2;
        var_fv1 = arg5;
    } else {
        // clang-format off
        var_fa1 = arg5; \
        var_fv1 = arg2;
        // clang format on
    }

    if (sp44 < arg6->unk0) {
        *sp54[i] = -1;
        return 0;
    }

    if (arg6->unkC < sp38) {
        *sp54[i] = 1;
        return 0;
    }

    if (sp40 < arg6->unk4) {
        *sp54[i] = -2;
        return 0;
    }

    if (arg6->unk10 < sp34) {
        *sp54[i] = 2;
        return 0;
    }

    if (var_fa1 < arg6->unk8) {
        *sp54[i] = -3;
        return 0;
    }

    if (arg6->unk14 < var_fv1) {
        *sp54[i] = 3;
        return 0;
    }
    if ((sp44 <= arg6->unkC) && (arg6->unk0 <= sp38) && (sp40 <= arg6->unk10) && (arg6->unk4 <= sp34) && (var_fa1 <= arg6->unk14) && (arg6->unk8 <= var_fv1)) {
        *sp54[i] = -1;
        return 3;
    }

    temp_fa1 = arg3 - arg0;
    temp_fa0 = arg4 - arg1;
    temp_fv1 = arg5 - arg2;

    if (var_fv1 <= arg6->unk8) {
        if (temp_fv1 == 0.0f) {
            var_fa0 = 0.0f;
        } else {
            var_fa0 = (arg6->unk8 - arg2) / temp_fv1;
        }
        temp_fv0 = (var_fa0 * temp_fa1) + arg0;
        if ((arg6->unk0 <= temp_fv0) && (temp_fv0 <= arg6->unkC)) {
            temp_fv0 = (var_fa0 * temp_fa0) + arg1;
            if ((arg6->unk4 <= temp_fv0) && (temp_fv0 <= arg6->unk10)) {
                *sp5C[i] = var_fa0;
                *sp54[i] = -3;
                i++;
                if (i == 2) {
                    return 2;
                }
            }
        }
    }

    if (arg6->unk14 <= var_fa1) {
        if (temp_fv1 == 0.0f) {
            var_fa0 = 0.0f;
        } else {
            var_fa0 = (arg6->unk14 - arg2) / temp_fv1;
        }
        temp_fv0 = (var_fa0 * temp_fa1) + arg0;
        if ((arg6->unk0 <= temp_fv0) && (temp_fv0 <= arg6->unkC)) {
            temp_fv0 = (var_fa0 * temp_fa0) + arg1;
            if ((arg6->unk4 <= temp_fv0) && (temp_fv0 <= arg6->unk10)) {
                *sp5C[i] = var_fa0;
                *sp54[i] = 3;
                i++;
                if (i == 2) {
                    return 2;
                }
            }
        }
    }

    if (sp34 <= arg6->unk4) {
        if (temp_fa0 == 0.0f) {
            var_fa0 = 0.0f;
        } else {
            var_fa0 = (arg6->unk4 - arg1) / temp_fa0;
        }
        temp_fv0 = (var_fa0 * temp_fa1) + arg0;
        if ((arg6->unk0 <= temp_fv0) && (temp_fv0 <= arg6->unkC)) {
            temp_fv0 = (var_fa0 * temp_fv1) + arg2;
            if ((arg6->unk8 <= temp_fv0) && (temp_fv0 <= arg6->unk14)) {
                *sp5C[i] = var_fa0;
                *sp54[i] = -2;
                i++;
                if (i == 2) {
                    return 2;
                }
            }
        }
    }

    if (arg6->unk10 <= sp40) {
        if (temp_fa0 == 0.0f) {
            var_fa0 = 0.0f;
        } else {
            var_fa0 = (arg6->unk10 - arg1) / temp_fa0;
        }
        temp_fv0 = (var_fa0 * temp_fa1) + arg0;
        if ((arg6->unk0 <= temp_fv0) && (temp_fv0 <= arg6->unkC)) {
            temp_fv0 = (var_fa0 * temp_fv1) + arg2;
            if ((arg6->unk8 <= temp_fv0) && (temp_fv0 <= arg6->unk14)) {
                *sp5C[i] = var_fa0;
                *sp54[i] = 2;
                i++;
                if (i == 2) {
                    return 2;
                }
            }
        }
    }

    if (sp38 <= arg6->unk0) {
        if (temp_fa1 == 0.0f) {
            var_fa0 = 0.0f;
        } else {
            var_fa0 = (arg6->unk0 - arg0) / temp_fa1;
        }
        temp_fv0 = (var_fa0 * temp_fv1) + arg2;
        if ((arg6->unk8 <= temp_fv0) && (temp_fv0 <= arg6->unk14)) {
            temp_fv0 = (var_fa0 * temp_fa0) + arg1;
            if ((arg6->unk4 <= temp_fv0) && (temp_fv0 <= arg6->unk10)) {
                *sp5C[i] = var_fa0;
                *sp54[i] = -1;
                i++;
                if (i == 2) {
                    return 2;
                }
            }
        }
    }

    if (arg6->unkC <= sp44) {
        if (temp_fa1 == 0.0f) {
            var_fa0 = 0.0f;
        } else {
            var_fa0 = (arg6->unkC - arg0) / temp_fa1;
        }
        temp_fv0 = (var_fa0 * temp_fv1) + arg2;
        if ((arg6->unk8 <= temp_fv0) && (temp_fv0 <= arg6->unk14)) {
            temp_fv0 = (var_fa0 * temp_fa0) + arg1;
            if ((arg6->unk4 <= temp_fv0) && (temp_fv0 <= arg6->unk10)) {
                *sp5C[i] = var_fa0;
                *sp54[i] = 1;
                i++;
                if (i == 2) {
                    return 2;
                }
            }
        }
    }

    return i;
}

void func_uvmodel_rom_00402AD0(void) {
    D_uvmodel_rom_00403130 = -1;
}

Mtx4F* func_uvmodel_rom_00402AE0(void) {
    return &D_uvmodel_rom_00403160[D_uvmodel_rom_00403130];
}

void func_uvmodel_rom_00402AFC(Mtx4F* src) {
    Mtx4F* mtx4F;
    
    if (++D_uvmodel_rom_00403130 >= D_uvmodel_rom_00403140) {
        return;
    }
    if (D_uvmodel_rom_00403130 == 0) {
        mtx4F = (Mtx4F*)D_uvmodel_rom_00403160 + D_uvmodel_rom_00403130;
        D_uvmodel_rom_00403164->uvMat4FCopy(mtx4F, src);
    } else {
        mtx4F = (Mtx4F*)D_uvmodel_rom_00403160 + (D_uvmodel_rom_00403130);
        D_uvmodel_rom_00403164->func_00400BB8(mtx4F, mtx4F - 1, src);
    }
}

void func_uvmodel_rom_00402B98(void) {
    if (D_uvmodel_rom_00403130 >= 0) {
        D_uvmodel_rom_00403130--;
    }
}

void func_uvmodel_rom_00402BB8(ParsedUVMD* uvmd, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;
    s32 k;
    uvModelLOD* modelLod;
    ParsedUVMD_1* temp_fp;
    s32 pad;
    
    for (i = 0; i < uvmd->unk4; i++) {
        temp_fp = &uvmd->unk0[i];
        for (j = 0; j < temp_fp->unk8; j++) {
            modelLod = &temp_fp->unk0[j];
            for (k = 0; k < modelLod->unk4; k++) {
                D_uvmodel_rom_00403178->func_uvgfxstate_rom_00401418(&modelLod->stateTable[k], arg1, arg2);
            }
        }
    }
}

s32 func_uvmodel_rom_00402CEC(ParsedUVMD* uvmd, uvGfxState** stateTable, s32 arg2) {
    s32 i;
    s32 j;
    s32 k;
    s32 stateCount;
    ParsedUVMD_1* temp_t0;
    uvGfxState* state;
    uvModelLOD* modelLod;

    stateCount = 0;
    for (i = 0; i < uvmd->unk4; i++) {
        temp_t0 = &uvmd->unk0[i];
        for (j = 0; j < temp_t0->unk8; j++) {
            modelLod = &temp_t0->unk0[j];
            for (k = 0; k < modelLod->unk4; k++) {
                state = &modelLod->stateTable[k];
                if (D_uvmodel_rom_00403178->func_uvgfxstate_rom_0040143C(state, arg2) != 0) {
                    stateTable[stateCount++] = state;
                }
            }
        }
    }

    return stateCount;
}

void func_uvmodel_rom_00402E50(s32 id, s32 arg1) {
    ParsedUVMD* uvmd;

    uvmd = uvGetLoadedFile('UVMD', id);
    if (uvmd == NULL) {
        return;
    }
    if (uvmd->unk20 != NULL) {
        uvmd->unk20->unk38 = arg1;
    }
}

// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"
#include "stdarg.h"

typedef void (*DObjCallback)(s32 arg0);

typedef struct DObj_s {
    /* 0x00 */ u16 modelId;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5; /* inferred */
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ char pad18[2];
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ Mtx4F *unk1C;
    /* 0x20 */ DObjCallback unk20;
    /* 0x24 */ DObjCallback unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} DObj; /* size = 0x30 */

typedef struct DobjSettings {
    s32 dobjsCount;
    s32 unk4;
    s32 unk8;
} DobjSettings;

typedef struct UnkTerra_Exports_s {
    /* 0x00 */ char pad0[0xAC];
    /* 0xAC */ void (*func_uvterra_rom_0040D128)(s32, s32, f32, f32, s32 *, void *, f32); /* inferred */
} UnkTerra_Exports; /* size = 0xB0 */

void func_uvdobj_rom_00400544(s32 arg0, s32 arg1);
s32 func_uvdobj_rom_00400558(s32 arg0, s32 arg1, s32 arg2);
void func_uvdobj_rom_0040056C(s32 arg0);
void func_uvdobj_rom_004005C4(void);
void func_uvdobj_rom_00400704(s32 arg0, s32 arg1);
void uvDobjModel(s32 arg0, s32 arg1);
u16 uvDobjGetModel(s32 arg0);
void uvDobjProps(s32 arg0, ...);
void uvDobjGetProp(s32 arg0, ...);
void uvDobjPosm(s32 arg0, s32 arg1, Mtx4F *arg2);
void uvDobjGetPosm(s32 arg0, s32 arg1, Mtx4F *arg2);
void func_uvdobj_rom_00400FF0(s32 arg0, s32 arg1);
void func_uvdobj_rom_00401028(s32 arg0, s32 arg1);
u8 func_uvdobj_rom_00401074(s32 arg0);
void func_uvdobj_rom_004010B4(s32 arg0, s32 arg1);
s32 uvDobjCreate(void);
void func_uvdobj_rom_004011CC(s32 arg0);
void func_uvdobj_rom_00401210(s32 arg0);
void func_uvdobj_rom_00401240(s32 arg0, s32 arg1);
void func_uvdobj_rom_00401598(s32 arg0, f32 arg1);
void func_uvdobj_rom_004015C0(s32 arg0, DObj *arg1);
void func_uvdobj_rom_00401ABC(s32 arg0, DObj *arg1);
s32 func_uvdobj_rom_00401F14(f32 arg0, f32 arg1, f32 arg2);
s32 func_uvdobj_rom_00402138(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                             s32 *arg7);
s32 func_uvdobj_rom_00402420(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 **arg4, f32 **arg5,
                             Vec3F **arg6);
s32 func_uvdobj_rom_00402870(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 **arg6,
                             f32 **arg7, Vec3F **arg8);
s16 func_uvdobj_rom_00402D68(f32 arg0, f32 arg1, f32 arg2, f32 arg3, DObj *arg4);
s16 func_uvdobj_rom_00403054(f32 arg0, f32 arg1, f32 arg2, DObj *arg3);
s16 func_uvdobj_rom_004032DC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, DObj *arg6);
s32 func_uvdobj_rom_0040359C(s32 arg0, Quat *arg1, u8 *arg2);
void func_uvdobj_rom_0040368C(void);
void func_uvdobj_rom_004038C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u16 func_uvdobj_rom_00403954(s32 **arg0);
void __entrypoint_func_uvdobj_rom_400000(UvDobj_Exports *exports);

// .data
s32 D_uvdobj_rom_004039A0[] = { 0x00680000, __entrypoint_func_uvdobj_rom_400000, 0, 0 };

// .bss
s32 D_uvdobj_rom_004039B0;
DObj *sDObjs;
s32 *D_uvdobj_rom_004039B8;
u16 D_uvdobj_rom_004039BC;
s16 D_uvdobj_rom_004039BE;
s32 sDObjsCount;
s32 sUvDobjId;
s32 D_uvdobj_rom_004039C8;
s32 D_uvdobj_rom_004039CC;
f32 *D_uvdobj_rom_004039D0;
s32 *D_uvdobj_rom_004039D4;
Vec3F *D_uvdobj_rom_004039D8;
s32 *D_uvdobj_rom_004039DC;
s32 *D_uvdobj_rom_004039E0;
s32 *D_uvdobj_rom_004039E4;
f32 *D_uvdobj_rom_004039E8;
s32 D_uvdobj_rom_004039EC;
s32 D_uvdobj_rom_004039F0;
s32 D_uvdobj_rom_004039F4;
s32 *D_uvdobj_rom_004039F8;
static UvFMtx_Rom_Exports *sUvFMtxExports;
static UvQuat_Exports *sUvQuatExports;
static UvFVec_Rom_Exports *sUvFVecExports;
static UvImtx_Rom_Exports *sUvIMtxExports;
static UvGfxState_Rom_Exports *sUvGfxStateExports;
static UvGfxMgr_Exports *sUvGfxMgrExports;
static UvModel_Exports *sUvModelExports;
static UvMath_Exports *sUvMathExports;
static UvChannelExports *sUvChannelExports;
static UvCback_Exports *sUvCbackExports;
static UvQuery_Exports *sUvQueryExports;
static UvIntersect_Exports *sUvIntersectExports;
static UnkTerra_Exports *sUvTerraExports;
static UvLights_Exports *sUvLightExports;

void __entrypoint_func_uvdobj_rom_400000(UvDobj_Exports *exports) {
    DobjSettings *settings;
    s32 i;

    uvUpdateFileAllocPtr(exports);
    exports->func_uvdobj_rom_00400544 = func_uvdobj_rom_00400544;
    exports->func_uvdobj_rom_00400558 = func_uvdobj_rom_00400558;
    exports->func_uvdobj_rom_0040056C = func_uvdobj_rom_0040056C;
    exports->func_uvdobj_rom_00400704 = func_uvdobj_rom_00400704;
    exports->uvDobjModel = uvDobjModel;
    exports->uvDobjGetModel = uvDobjGetModel;
    exports->uvDobjProps = uvDobjProps;
    exports->uvDobjGetProp = uvDobjGetProp;
    exports->uvDobjPosm = uvDobjPosm;
    exports->func_uvdobj_rom_004005C4 = func_uvdobj_rom_004005C4;
    exports->uvDobjGetPosm = uvDobjGetPosm;
    exports->func_uvdobj_rom_00402420 = func_uvdobj_rom_00402420;
    exports->func_uvdobj_rom_00400FF0 = func_uvdobj_rom_00400FF0;
    exports->func_uvdobj_rom_00402870 = func_uvdobj_rom_00402870;
    exports->func_uvdobj_rom_00401028 = func_uvdobj_rom_00401028;
    exports->func_uvdobj_rom_0040359C = func_uvdobj_rom_0040359C;
    exports->func_uvdobj_rom_00401074 = func_uvdobj_rom_00401074;
    exports->func_uvdobj_rom_004038C4 = func_uvdobj_rom_004038C4;
    exports->func_uvdobj_rom_004010B4 = func_uvdobj_rom_004010B4;
    exports->func_uvdobj_rom_00403954 = func_uvdobj_rom_00403954;
    exports->uvDobjCreate = uvDobjCreate;
    exports->func_uvdobj_rom_004011CC = func_uvdobj_rom_004011CC;
    exports->func_uvdobj_rom_00401598 = func_uvdobj_rom_00401598;
    exports->func_uvdobj_rom_00401F14 = func_uvdobj_rom_00401F14;
    exports->func_uvdobj_rom_00402138 = func_uvdobj_rom_00402138;
    exports->D_uvdobj_rom_004039B0 = &D_uvdobj_rom_004039B0;
    settings = uvGetSystemProp(SYSTEM_PROPID_DOBJ_SETTINGS);
    if (settings == NULL) {
        sDObjsCount = 0x64;
        D_uvdobj_rom_004039C8 = 0x64;
        D_uvdobj_rom_004039CC = 0x12C;
    } else {
        if (settings->dobjsCount != 0) {
            sDObjsCount = settings->dobjsCount;
        } else {
            sDObjsCount = 0x64;
        }
        if (settings->unk4 != 0) {
            D_uvdobj_rom_004039C8 = settings->unk4;
        } else {
            D_uvdobj_rom_004039C8 = 0x64;
        }
        if (settings->unk8 != 0) {
            D_uvdobj_rom_004039CC = settings->unk8;
        } else {
            D_uvdobj_rom_004039CC = 0x12C;
        }
    }
    sUvIMtxExports = uvLoadModule('IMTX');
    sUvFMtxExports = uvLoadModule('FMTX');
    sUvQuatExports = uvLoadModule('QUAT');
    sUvFVecExports = uvLoadModule('FVEC');
    sUvGfxStateExports = uvLoadModule('STAT');
    sUvGfxMgrExports = uvLoadModule('GMGR');
    sUvMathExports = uvLoadModule('MATH');
    sUvModelExports = uvLoadModule('MODL');
    sUvChannelExports = uvLoadModule('CHAN');
    sUvCbackExports = uvLoadModule('CBCK');
    sUvQueryExports = uvLoadModule('QERY');
    sUvIntersectExports = uvLoadModule('ISCT');
    sUvTerraExports = uvLoadModule('TERR');
    sUvLightExports = uvLoadModule('LGHT');
    sUvChannelExports->func_uvchannel_rom_00400288(0, 0xD, &D_uvdobj_rom_004039F4, 0);
    D_uvdobj_rom_004039E8 = _uvMemAllocAlign8(D_uvdobj_rom_004039F4 * 4);
    for (i = 0; i < D_uvdobj_rom_004039F4; i++) {
        D_uvdobj_rom_004039E8[i] = 1.0f;
    }

    sDObjs = _uvMemAllocAlign8(sDObjsCount * sizeof(DObj));
    D_uvdobj_rom_004039B8 = _uvMemAllocAlign8(sDObjsCount * sizeof(s32));
    uvMemSet(sDObjs, 0, sDObjsCount * sizeof(DObj));
    uvMemSet(D_uvdobj_rom_004039B8, 0, sDObjsCount * sizeof(s32));
    for (i = 0; i < sDObjsCount; i++) {
        sDObjs[i].modelId = 0xFFFF;
    }

    D_uvdobj_rom_004039BE = 0;
    D_uvdobj_rom_004039D0 = sUvQueryExports->uvQueryGetFloatValues();
    D_uvdobj_rom_004039D4 = sUvQueryExports->uvQueryGetIntValues();
    D_uvdobj_rom_004039D8 = sUvQueryExports->uvQueryGetFloatVectors();
    D_uvdobj_rom_004039E4 = sUvQueryExports->func_uvquery_rom_00400270();
    D_uvdobj_rom_004039E0 = sUvQueryExports->func_uvquery_rom_0040027C();
    D_uvdobj_rom_004039DC = sUvQueryExports->func_uvquery_rom_00400288();
    D_uvdobj_rom_004039F8 = sUvQueryExports->func_uvquery_rom_004005F8();
    D_uvdobj_rom_004039EC = -1;
    D_uvdobj_rom_004039F0 = -1;
}

void func_uvdobj_rom_00400544(s32 arg0, s32 arg1) {
    D_uvdobj_rom_004039EC = arg0;
    D_uvdobj_rom_004039F0 = arg1;
}

s32 func_uvdobj_rom_00400558(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

void func_uvdobj_rom_0040056C(s32 arg0) {
    CallbackList *callbackList;

    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 6, &callbackList, 0);
    sUvCbackExports->uvAddCallback(callbackList, func_uvdobj_rom_00401210, 0, 0x3C);
}

void func_uvdobj_rom_004005C4(void) {
    Mtx4F *temp_a0;
    s32 i;

    for (i = 0; i < sDObjsCount; i++) {
        temp_a0 = sDObjs[i].unk1C;
        if (temp_a0 != 0) {
            _uvMemFree(temp_a0);
        }
    }

    _uvMemFree(sDObjs);
    _uvMemFree(D_uvdobj_rom_004039B8);
    uvUnloadModule('FMTX');
    uvUnloadModule('QUAT');
    uvUnloadModule('FVEC');
    uvUnloadModule('IMTX');
    uvUnloadModule('STAT');
    uvUnloadModule('GMGR');
    uvUnloadModule('MATH');
    uvUnloadModule('MODL');
    uvUnloadModule('CHAN');
    uvUnloadModule('CBCK');
    uvUnloadModule('QERY');
    uvUnloadModule('ISCT');
    uvUnloadModule('TERR');
    uvUnloadModule('LGHT');
}

void func_uvdobj_rom_00400704(s32 arg0, s32 arg1) {
    DObj *temp_v1;

    if ((arg1 == 0xFFFF) || (arg0 < 0)) {
        return;
    }

    temp_v1 = &sDObjs[arg0];
    if (arg1 != temp_v1->modelId) {
        if (uvGetLoadedFile('UVMD', arg1) != NULL) {
            temp_v1->modelId = arg1;
        }
    }
}

void uvDobjModel(s32 objId, s32 modelId) {
    f32 temp_fv0;
    u8 temp_v0_3;
    u8 var_s2;
    s32 i;
    ParsedUVMD *temp_v0_2;
    ParsedUVMD *var_s1;
    Mtx4F *sp38;
    DObj *temp_s5;

    temp_s5 = &sDObjs[objId];
    if (modelId == temp_s5->modelId) {
        return;
    }

    if (objId >= sUvDobjId) {
        return;
    }

    var_s1 = NULL;
    if (temp_s5->modelId != 0xFFFF) {
        var_s1 = uvGetLoadedFile('UVMD', temp_s5->modelId);
        if (var_s1 == NULL) {
            PANIC;
        } else {
            // FAKE
            if (var_s1 && var_s1 && var_s1)
                ;
        }
    }
    if (modelId == 0xFFFF) {
        temp_s5->modelId = 0xFFFF;
        if (temp_s5->unk1C != 0) {
            _uvMemFree((void *) temp_s5->unk1C);
            temp_s5->unk1C = 0;
            temp_s5->unk1A = 0;
        }
        return;
    }

    temp_v0_2 = uvGetLoadedFile('UVMD', modelId);
    if (temp_v0_2 == NULL) {
        return;
    }

    temp_s5->unk14 = 0;
    temp_s5->unk10 = temp_v0_2->unkC;
    if (temp_s5->modelId == 0xFFFF) {
        var_s2 = 0;
    } else if (var_s1 != NULL) {
        var_s2 = var_s1->unk6;
    } else {
        var_s2 = 0;
        if (temp_s5->unk1C != 0) {
            _uvMemFree((void *) temp_s5->unk1C);
            temp_s5->unk1C = 0;
            temp_s5->unk1A = 0;
        }
    }
    sp38 = temp_s5->unk1C;
    temp_v0_3 = temp_v0_2->unk6;
    temp_s5->unk1C = _uvMemAllocAlign8(temp_v0_3 << 6);
    temp_s5->unk1A = temp_v0_3;

    for (i = 0; i < var_s2; i++) {
        sUvFMtxExports->uvMat4FCopy((u32) temp_s5->unk1C + i * sizeof(Mtx4F),
                                    (u32) sp38 + i * sizeof(Mtx4F));
        _uvMemFree(sp38);
    }

    for (i = var_s2; i < temp_v0_3; i++) {
        Mtx4F *temp = (u32) temp_s5->unk1C + (i * sizeof(Mtx4F));
        Mtx4F *temp2 = (u32) temp_v0_2->unk8 + (i * sizeof(Mtx4F));
        sUvFMtxExports->uvMat4FCopy(temp, temp2);
    }
    if (var_s2 == 0) {
        if (temp_v0_2->unk10 != 1.0f) {
            temp_fv0 = 1.0f / temp_v0_2->unk10;
            sUvFMtxExports->uvMat4Scale((Mtx4F *) temp_s5->unk1C, temp_fv0, temp_fv0, temp_fv0);
        }
    }
    temp_s5->modelId = modelId;
    if (temp_v0_2->unk5 & 0x76) {
        func_uvdobj_rom_00400FF0(objId, 3);
    } else {
        func_uvdobj_rom_00400FF0(objId, 2);
    }
}

u16 uvDobjGetModel(s32 objId) {
    return sDObjs[objId].modelId;
}

void uvDobjProps(s32 objId, ...) {
    va_list args;
    DObj *temp_s1;
    f32 temp_fs0;
    ParsedUVMD *uvmd;
    s16 temp_v0;

    if (objId >= sDObjsCount) {
        return;
    }
    temp_s1 = &sDObjs[objId];
    va_start(args, objId);
    if (temp_s1->modelId == 0xFFFF) {
        PANIC;
        return;
    }
    while (TRUE) {
        temp_v0 = va_arg(args, s32);
        switch (temp_v0) {
            case 10:
                temp_s1->unk7 = va_arg(args, s32);
                break;
            case 1:
                temp_fs0 = va_arg(args, f64);
                uvmd = uvGetLoadedFile('UVMD', temp_s1->modelId);
                temp_s1->unk10 = uvmd->unkC * temp_fs0;
                break;
            case 7:
                temp_s1->unk10 = va_arg(args, f64);
                break;
            case 2:
                temp_s1->unk14 &= ~(1 << va_arg(args, s32));
                break;
            case 3:
                temp_s1->unk14 |= 1 << va_arg(args, s32);
                break;
            case 6:
                temp_s1->unk14 = va_arg(args, s32);
                break;
            case 4:
                temp_s1->unk20 = va_arg(args, s32);
                temp_s1->unk28 = va_arg(args, s32);
                break;
            case 5:
                temp_s1->unk24 = va_arg(args, s32);
                temp_s1->unk2C = va_arg(args, s32);
                break;
            default:
                PANIC;
                break;
            case 0:
                return;
        }
    }
    va_end(args);
}

void uvDobjGetProp(s32 objId, ...) {
    DObj *obj;
    s16 prop;
    va_list args;

    if (objId >= sUvDobjId) {
        return;
    }
    obj = &sDObjs[objId];
    va_start(args, objId);

    while (TRUE) {
        prop = va_arg(args, s32);
        if (prop == NULL) {
            return;
        }

        switch (prop) {
            case 7:
                *va_arg(args, f32 *) = obj->unk10;
                break;
            case 8:
                *va_arg(args, s32 *) = obj->modelId;
                break;
            case 6:
                *va_arg(args, s32 *) = obj->unk14;
                break;
        }
    }
    va_end(args);
}

void uvDobjPosm(s32 objId, s32 part, Mtx4F *dst) {
    DObj *obj;
    s32 pad;
    ParsedUVMD *temp_v0;

    if (sUvDobjId < objId) {
        return;
    }

    obj = &sDObjs[objId];
    if (obj->modelId == 0xFFFF) {
        return;
    }

    if (part < 0) {
        return;
    }

    sUvFMtxExports->uvMat4FCopy((u32) obj->unk1C + part * sizeof(Mtx4F), dst);

    temp_v0 = uvGetLoadedFile('UVMD', obj->modelId);
    if (temp_v0 == NULL) {
        return;
    }

    if (part >= temp_v0->unk0->unk8) {
        return;
    }

    if (part == 0) {
        if (temp_v0->unk10 != 1.0f) {
            sUvFMtxExports->uvMat4Scale((u32) obj->unk1C + part * sizeof(Mtx4F),
                                        1.0f / temp_v0->unk10, 1.0f / temp_v0->unk10,
                                        1.0f / temp_v0->unk10);
        }
    } else {
        obj->unk1C[part].m[3][0] *= temp_v0->unk10;
        obj->unk1C[part].m[3][1] *= temp_v0->unk10;
        obj->unk1C[part].m[3][2] *= temp_v0->unk10;
    }
}

void uvDobjGetPosm(s32 objId, s32 arg1, Mtx4F *dst) {
    DObj *temp_v0;
    ParsedUVMD *temp_v0_2;

    if (sUvDobjId < objId) {
        return;
    }

    temp_v0 = &sDObjs[objId];
    if (temp_v0->modelId == 0xFFFF) {
        return;
    }

    if (arg1 < 0) {
        return;
    }

    sUvFMtxExports->uvMat4FCopy(dst, (u32) temp_v0->unk1C + arg1 * sizeof(Mtx4F));

    temp_v0_2 = uvGetLoadedFile('UVMD', temp_v0->modelId);
    if (temp_v0_2 == NULL) {
        return;
    }

    if (arg1 == 0) {
        if (temp_v0_2->unk10 != 1.0f) {
            sUvFMtxExports->uvMat4Scale(dst, temp_v0_2->unk10, temp_v0_2->unk10, temp_v0_2->unk10);
        }
    } else {
        dst->m[3][0] /= temp_v0_2->unk10;
        dst->m[3][1] /= temp_v0_2->unk10;
        dst->m[3][2] /= temp_v0_2->unk10;
    }
}

void func_uvdobj_rom_00400FF0(s32 arg0, s32 arg1) {
    DObj *v0;
    if (sUvDobjId < arg0) {
        return;
    }

    v0 = &sDObjs[arg0];
    v0->unk4 = arg1;
}

void func_uvdobj_rom_00401028(s32 arg0, s32 arg1) {
    if (sUvDobjId < arg0) {
        return;
    }
    func_uvdobj_rom_00400FF0(arg0, sDObjs[arg0].unk4 | arg1);
}

u8 func_uvdobj_rom_00401074(s32 arg0) {
    if (sUvDobjId < arg0) {
        return 0U;
    }
    return sDObjs[arg0].unk4;
}

void func_uvdobj_rom_004010B4(s32 arg0, s32 arg1) {
    if (sUvDobjId < arg0) {
        return;
    }
    func_uvdobj_rom_00400FF0(arg0, sDObjs[arg0].unk4 & ~arg1);
}

s32 uvDobjCreate(void) {
    s32 i;

    for (i = 0; i < sDObjsCount; i++) {
        if (sDObjs[i].unk5 == 0) {
            sDObjs[i].unk5 = 1;
            sDObjs[i].unk2 = -1;
            sDObjs[i].unk7 = 0;
            sDObjs[i].unk20 = 0;
            sDObjs[i].unk24 = 0;
            sDObjs[i].unk1A = 0;
            sDObjs[i].unk1C = 0;
            if (sUvDobjId < i + 1) {
                sUvDobjId = i + 1;
            }
            return i;
        }
    }

    return 0xFFFF;
}

void func_uvdobj_rom_004011CC(s32 arg0) {
    uvDobjModel(arg0, 0xFFFF);
    sDObjs[arg0].unk5 = 0;
}

void func_uvdobj_rom_00401210(s32 arg0) {
    if (D_uvdobj_rom_004039B0 == 0) {
        func_uvdobj_rom_00401240(arg0, 0);
    }
}

void func_uvdobj_rom_00401240(s32 arg0, s32 arg1) {
    s32 var_a1;
    ParsedUVMD *temp_v0_2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 var_fv1;
    s32 i;
    u16 temp_a1;
    s32 temp_v0_4;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    void *var_v0;
    Vec3F spA8;
    DObj *temp_s0;
    float temp_fv0;

    D_uvdobj_rom_004039BC = 0;
    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 7, &spA8, 4, &spCC, &spC8, &spC4, &spC0, &spBC,
                                                   &spB8, 0);
    for (i = 0; i < sUvDobjId; i++) {
        temp_s0 = &sDObjs[i];
        if (temp_s0->modelId == 0xFFFF) {
            continue;
        }
        if (!(temp_s0->unk4 & 2)) {
            continue;
        }
        if (temp_s0->unk4 & 4) {
            continue;
        }
        temp_v0_2 = uvGetLoadedFile('UVMD', temp_s0->modelId);
        if (temp_v0_2 == NULL) {
            continue;
        }
        temp_fs4 = temp_s0->unk1C->m[3][0];
        temp_fs5 = temp_s0->unk1C->m[3][1];
        temp_fv0 = temp_s0->unk1C->m[3][2];
        temp_fs1 = temp_fs4 - spA8.x;
        temp_fs2 = temp_fs5 - spA8.y;
        temp_fs0 = temp_fv0 - spA8.z;
        if (!(temp_s0->unk4 & 0x40)
            && (sUvChannelExports->func_uvchannel_rom_004014E8(arg0, temp_fs1, temp_fs2, temp_fs0,
                                                               temp_s0->unk10)
                == 0)) {
            continue;
        }

        temp_fs3 = (SQ(temp_fs1) + SQ(temp_fs2) + SQ(temp_fs0));
        if (D_uvdobj_rom_004039E8[arg0] == 1.0f) {
            var_fv1 = temp_fs3;
        } else {
            var_fv1 = (temp_fs3 * D_uvdobj_rom_004039E8[arg0]) * D_uvdobj_rom_004039E8[arg0];
        }
        temp_v0_4 = sUvModelExports->func_uvmodel_rom_00400608(temp_v0_2, var_fv1);
        if (temp_v0_4 == 0xFF) {
            continue;
        }
        if ((temp_v0_2->unk5 & 1) || (((temp_v0_4 < temp_v0_2->unk7)))) {
            var_a1 = 1;
        } else {
            var_a1 = 0;
        }

        if (temp_v0_2->unk0[temp_v0_4].unk9) {
            var_v0 = func_uvdobj_rom_00401ABC;
        } else {
            var_v0 = func_uvdobj_rom_004015C0;
        }
        temp_s0->unk6 = temp_v0_4;
        temp_s0->unk8 = temp_fs1;
        temp_s0->unkC = temp_fs2;
        sUvTerraExports->func_uvterra_rom_0040D128(arg0, var_a1, temp_fs4, temp_fs5, var_v0, temp_s0,
                                                   temp_fs3);
    }
}

void func_uvdobj_rom_00401598(s32 arg0, f32 arg1) {
    D_uvdobj_rom_004039E8[arg0] = 1.0f / arg1;
}

void func_uvdobj_rom_0040368C(); /* */

void func_uvdobj_rom_004015C0(s32 arg0, DObj *arg1) {
    ParsedUVMD_1 *sp154;
    void (*temp_v0)(s32, void *);
    void (*temp_v0_6)(s32, void *);
    ParsedUVMD *temp_s0;
    s32 temp_s2_2;
    s32 var_s0;
    s32 j;
    s32 var_s5;
    s32 temp_s4;
    u32 sp130;
    s32 temp_s1;
    uvModelLOD *temp_s2;
    s32 var_fp;
    s32 sp120;
    s32 sp11C;
    s32 sp118;
    Mtx4F spD8;
    Mtx4F sp98;
    Mtx4F sp58;

    sp118 = 0;
    if (arg1->unk20 != NULL) {
        arg1->unk20(arg1->unk28);
    }
    if (!(arg1->unk4 & 2)) {
        return;
    }

    temp_s1 = arg1->unk6;
    temp_s0 = uvGetLoadedFile('UVMD', arg1->modelId);
    sUvLightExports->func_uvlight_rom_0040167C(arg1->unk2);
    D_uvdobj_rom_004039B8[D_uvdobj_rom_004039BC++] = (arg1 - sDObjs);
    if (arg1->unk4 & 8) {
        func_uvdobj_rom_0040368C();
    }
    sp154 = &temp_s0->unk0[temp_s1];
    var_s5 = 0;
    sp120 = arg1->unk4 & 0x80;
    if (sp120) {
        sp11C = 3;
    } else {
        sp11C = 1;
    }
    sp130 = ~arg1->unk14;
    for (var_fp = 0; var_fp < sp154->unk8; var_fp++) {
        temp_s2 = &sp154->unk0[var_fp];
        if (sp130 < (1 << var_fp)) {
            break;
        }
        if ((arg1->unk14 & (1 << var_fp)) || (((temp_s2->unk7 & 1)))) {
            var_s0 = FALSE;
        } else {
            var_s0 = TRUE;
        }

        if (!var_s0) {
            if (temp_s2->unk7 & 2) {
                var_s5++;
                temp_s2_2 = sp154->unk0[var_fp].unk6 - sp154->unk0[var_fp + 1].unk6;
                for (j = 0; j < temp_s2_2; j++) {
                    sUvFMtxExports->uvGfxMtxFViewPop();
                    var_s5--;
                }
                continue;
            }
        }
        if ((var_fp == 0) || (sp120)) {
            sUvFMtxExports->func_00400370(&spD8, (u32) arg1->unk1C + temp_s2->unk5 * sizeof(Mtx4F));
            sUvFMtxExports->uvGfxMtxViewLoad(&spD8, 3U);
        } else {
            sUvFMtxExports->uvGfxMtxViewLoad((u32) arg1->unk1C + temp_s2->unk5 * sizeof(Mtx4F),
                                             (u16) sp11C);
        }
        var_s5++;
        if (var_s0) {
            if ((temp_s2->unk20 != 0) && (arg1->unk7 == 0) && (sp118 != 1)) {
                sUvFMtxExports->func_00400370(&sp98, arg1->unk1C);
                sp118 = 1;
                sUvGfxStateExports->func_uvgfxstate_rom_0040049C(&sp98, 1);
            }
            if ((arg1->unk7 != 0) && (sp118 != 2)) {
                sUvFMtxExports->func_00400370(&sp58, arg1->unk1C);
                sp118 = 2;
                sUvGfxStateExports->func_uvgfxstate_rom_0040049C(&sp58, 0);
            }
            j = 0;
            temp_s4 = temp_s2->unk4;
            if (j < temp_s4) {
                do {
                    if ((arg1->unk4 & 0x20) && (var_fp == 0) && (j == 0)) {
                        int prev = temp_s2->stateTable[j].state;
                        temp_s2->stateTable[j].state |= 0x10000000;
                        sUvGfxStateExports->uvGfxStateDraw(&temp_s2->stateTable[j]);
                        temp_s2->stateTable[j].state = prev;
                        continue;
                    }
                    sUvGfxStateExports->uvGfxStateDraw(&temp_s2->stateTable[j]);
                } while (++j != temp_s4);
            }
        }
        if ((var_fp + 1) == sp154->unk8) {
            break;
        }
        temp_s2_2 = sp154->unk0[var_fp].unk6 - sp154->unk0[var_fp + 1].unk6;
        for (j = 0; j <= temp_s2_2; j++) {
            sUvFMtxExports->uvGfxMtxFViewPop();
            var_s5--;
        }
    }

    for (var_fp = 0; var_fp < var_s5; var_fp++) {
        sUvFMtxExports->uvGfxMtxFViewPop();
    }
    if (arg1->unk24 != NULL) {
        arg1->unk24(arg1->unk2C);
    }
}

void func_uvdobj_rom_00401ABC(s32 arg0, DObj *arg1) {
    ParsedUVMD_1 *spE4;
    s32 var_s7;
    s32 var_s3;
    s32 var_s0;
    s32 temp_s2;
    ParsedUVMD *temp_v0_2;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 var_fv1;
    Mtx4F *spC0;
    u8 temp_s0;
    s32 temp_s1;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    uvModelLOD *temp_s4;
    f32 sp9C;
    f32 sp98;
    s32 j;
    Mtx4F sp54;

    sp9C = arg1->unk8;
    sp98 = arg1->unkC;
    if (arg1->unk20 != NULL) {
        arg1->unk20(arg1->unk28);
    }
    temp_s0 = arg1->unk6;
    temp_v0_2 = uvGetLoadedFile('UVMD', arg1->modelId);
    spB4 = temp_v0_2->unk10;
    D_uvdobj_rom_004039B8[D_uvdobj_rom_004039BC++] = (arg1 - sDObjs);
    spE4 = &temp_v0_2->unk0[temp_s0];
    spC0 = arg1->unk1C;
    spB0 = spC0->m[0][0];
    spAC = spC0->m[0][1];
    spA8 = spC0->m[1][0];
    spA4 = spC0->m[1][1];

    var_fv1 = MAX(1.0f, sUvMathExports->uvSqrtf(SQ(sp9C) + SQ(sp98)));
    sp9C /= var_fv1;
    sp98 /= var_fv1;

    spC0->m[0][0] = -sp98 / spB4;
    spC0->m[1][1] = -sp98 / spB4;
    spC0->m[0][1] = sp9C / spB4;
    spC0->m[1][0] = -sp9C / spB4;
    var_s3 = 0;
    for (var_s7 = 0; var_s7 < spE4->unk8; var_s7++) {
        temp_s4 = &spE4->unk0[var_s7];
        if ((arg1->unk14 & (1 << var_s7)) || (((temp_s4->unk7 & 1) != 0))) {
            var_s0 = FALSE;
        } else {
            var_s0 = TRUE;
        }

        if (!var_s0) {
            if (temp_s4->unk7 & 2) {
                var_s3++;
                temp_s2 = spE4->unk0[var_s7].unk6 - spE4->unk0[var_s7 + 1].unk6;
                for (j = 0; j < temp_s2; j++) {
                    sUvFMtxExports->uvGfxMtxFViewPop();
                    var_s3--;
                }
                continue;
            }
        }
        if (var_s7 == 0) {
            sUvFMtxExports->func_00400370(&sp54, (u32) arg1->unk1C + var_s7 * sizeof(Mtx4F));
            sUvFMtxExports->uvGfxMtxViewLoad(&sp54, 3);
        } else {
            sUvFMtxExports->uvGfxMtxViewLoad((u32) arg1->unk1C + var_s7 * sizeof(Mtx4F), 1);
        }
        var_s3++;
        if (var_s0) {
            temp_s1 = temp_s4->unk4;
            j = 0;
            if (temp_s1 > 0) {
                do {
                    sUvGfxStateExports->uvGfxStateDraw(&temp_s4->stateTable[j]);
                } while (++j != temp_s1);
            }
        }

        if ((var_s7 + 1) == spE4->unk8) {
            break;
        }

        temp_s2 = spE4->unk0[var_s7].unk6 - spE4->unk0[var_s7 + 1].unk6;
        for (j = 0; j <= temp_s2; j++) {
            sUvFMtxExports->uvGfxMtxFViewPop();
            var_s3--;
        }
    }

    for (var_s7 = 0; var_s7 < var_s3; var_s7++) {
        sUvFMtxExports->uvGfxMtxFViewPop();
    }
    spC0->m[0][0] = spB0;
    spC0->m[0][1] = spAC;
    spC0->m[1][0] = spA8;
    spC0->m[1][1] = spA4;
    if (arg1->unk24 != NULL) {
        arg1->unk24(arg1->unk2C);
    }
}

s32 func_uvdobj_rom_00401F14(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 i;
    s32 var_s2;
    s32 var_s3;
    s32 var_v0;
    DObj *temp_s0;
    s32 temp;

    temp = D_uvdobj_rom_004039EC;
    if (temp == -1) {
        var_s3 = sUvDobjId;
        var_v0 = 0;
    } else {
        var_v0 = D_uvdobj_rom_004039EC;
        var_s3 = D_uvdobj_rom_004039EC + 1;
    }

    for (i = var_v0; i < var_s3; i++) {
        temp_s0 = &sDObjs[i];
        if ((temp_s0->modelId == 0xFFFF) || !(temp_s0->unk4 & 1)) {
            continue;
        }

        temp_fv0 = temp_s0->unk10;
        temp_fv1 = temp_s0->unk1C->m[3][0];
        temp_ft4 = temp_s0->unk1C->m[3][1];
        temp_ft5 = temp_s0->unk1C->m[3][2];
        if (!((arg0 + temp_fv0) < temp_fv1) && !(temp_fv1 < (arg0 - temp_fv0))
            && !((arg1 + temp_fv0) < temp_ft4) && !(temp_ft4 < (arg1 - temp_fv0))
            && !((arg2 + temp_fv0) < temp_ft5) && !(temp_ft5 < (arg2 - temp_fv0))
            && (sUvIntersectExports->func_uvintersect_rom_00400460(arg0, arg1, arg2, temp_fv1, temp_ft4,
                                                                   temp_ft5, temp_fv0)
                != 0)) {
            ParsedUVMD *v0 = uvGetLoadedFile('UVMD', temp_s0->modelId);
            if (!(v0->unk5 & 2)) {
                return i;
            }
            *D_uvdobj_rom_004039E0 = i;
            if (func_uvdobj_rom_00403054(arg0, arg1, arg2, temp_s0) >= 0) {
                return *D_uvdobj_rom_004039E0;
            }
            continue;
        }
    }
    return 0xFFFF;
}

s32 func_uvdobj_rom_00402138(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                             s32 *arg7) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv1;
    s32 i;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    DObj *temp_v1;

    *D_uvdobj_rom_004039E4 = 0;
    var_v1 = D_uvdobj_rom_004039EC;
    if (var_v1 == -1) {
        var_s3 = sUvDobjId;
        var_v0 = 0;
    } else {
        var_v0 = D_uvdobj_rom_004039EC;
        var_s3 = D_uvdobj_rom_004039EC + 1;
    }
    for (i = var_v0; i < var_s3; i++) {
        temp_v1 = &sDObjs[i];
        if ((temp_v1->modelId == 0xFFFF) || !(temp_v1->unk4 & 1)) {
            continue;
        }

        temp_fv1 = temp_v1->unk10;
        temp_fa0 = temp_v1->unk1C->m[3][0];
        temp_fa1 = temp_v1->unk1C->m[3][1];
        temp_ft4 = temp_v1->unk1C->m[3][2];
        if (((temp_fa0 + temp_fv1 + arg6) < MIN(arg0, arg3))) {
            continue;
        }
        if ((MAX(arg0, arg3) < ((temp_fa0 - temp_fv1) - arg6))) {
            continue;
        }
        if (((temp_fa1 + temp_fv1 + arg6) < MIN(arg1, arg4))) {
            continue;
        }

        if ((MAX(arg1, arg4) < ((temp_fa1 - temp_fv1) - arg6))) {
            continue;
        }

        if (((temp_ft4 + temp_fv1 + arg6) < MIN(arg2, arg5))) {
            continue;
        }

        if ((MAX(arg2, arg5) < ((temp_ft4 - temp_fv1) - arg6))
            || (sUvIntersectExports->func_uvintersect_rom_00400530(
                    temp_fa0, temp_fa1, temp_ft4, temp_fv1, arg0, arg1, arg2, arg3, arg4, arg5, arg6)
                == 0)) {
            continue;
        }

        D_uvdobj_rom_004039D4[*D_uvdobj_rom_004039E4] = i;
        *D_uvdobj_rom_004039E4 += 1;
        if (*D_uvdobj_rom_004039E4 >= sUvQueryExports->func_uvquery_rom_00400224()) {
            break;
        }
    }
    if (*D_uvdobj_rom_004039E4 != 0) {
        *arg7 = D_uvdobj_rom_004039D4;
    }
    return *D_uvdobj_rom_004039E4;
}

s32 func_uvdobj_rom_00402420(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 **arg4, f32 **arg5,
                             Vec3F **arg6) {
    char pad[0x14];
    Mtx4F *temp_s1;
    DObj *temp_s0;
    s32 sp78;
    Vec3F *temp_s0_2;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fv1_3;
    s32 var_s4;
    s32 var_v0;
    s32 var_v1;
    ParsedUVMD *temp_s2;
    ParsedUVMD *temp_v0;

    var_v1 = D_uvdobj_rom_004039EC;
    if (var_v1 == -1) {
        var_v0 = 0;
        sp78 = sUvDobjId;
    } else {
        sp78 = D_uvdobj_rom_004039EC + 1;
        var_v0 = D_uvdobj_rom_004039EC;
    }
    *D_uvdobj_rom_004039E4 = 0;
    *D_uvdobj_rom_004039F8 = 0;
    for (var_s4 = var_v0; var_s4 < sp78; var_s4++) {
        temp_s0 = &sDObjs[var_s4];
        if ((temp_s0->modelId == 0xFFFF) || !(temp_s0->unk4 & 1)) {
            continue;
        }
        temp_fv0 = temp_s0->unk10;
        temp_s1 = temp_s0->unk1C;
        temp_fv1 = temp_s1->m[3][0];
        temp_ft4 = temp_s1->m[3][1];
        temp_ft5 = temp_s1->m[3][2];

        if (((arg0 + arg3 + temp_fv0) < temp_fv1)) {
            continue;
        }

        if ((temp_fv1 < ((arg0 - arg3) - temp_fv0))) {
            continue;
        }
        if (((arg1 + arg3 + temp_fv0) < temp_ft4)) {
            continue;
        }

        if ((temp_ft4 < ((arg1 - arg3) - temp_fv0))) {
            continue;
        }

        if (((arg2 + arg3 + temp_fv0) < temp_ft5)) {
            continue;
        }

        if ((temp_ft5 < ((arg2 - arg3) - temp_fv0))
            || (sUvIntersectExports->func_uvintersect_rom_004004C4(arg0, arg1, arg2, arg3, temp_fv1,
                                                                   temp_ft4, temp_ft5, temp_fv0)
                == 0)) {
            continue;
        }

        temp_s2 = uvGetLoadedFile('UVMD', temp_s0->modelId);
        *D_uvdobj_rom_004039E0 = var_s4;
        if (temp_s2->unk5 & 0x76) {
            func_uvdobj_rom_00402D68(arg0, arg1, arg2, arg3, temp_s0);
            if (*D_uvdobj_rom_004039E4 >= sUvQueryExports->func_uvquery_rom_00400224()) {
                break;
            }
            continue;
        }

        D_uvdobj_rom_004039D4[*D_uvdobj_rom_004039E4] = *D_uvdobj_rom_004039E0;
        temp_s0_2 = &D_uvdobj_rom_004039D8[*D_uvdobj_rom_004039E4];
        temp_s0_2->x = arg0 - temp_s1->m[3][0];
        temp_s0_2->y = arg1 - temp_s1->m[3][1];
        temp_s0_2->z = arg2 - temp_s1->m[3][2];
        sUvFVecExports->uvVec3FNormalize(temp_s0_2, temp_s0_2);
        temp_fv1_3 = (temp_s2->unkC
                      - sUvMathExports->uvSqrtf(SQ(temp_s0_2->x) + SQ(temp_s0_2->y) + SQ(temp_s0_2->z)))
                     / arg3;
        if (temp_fv1_3 < 0.0f) {
            D_uvdobj_rom_004039D0[*D_uvdobj_rom_004039E4] = temp_fv1_3;
        } else {
            D_uvdobj_rom_004039D0[*D_uvdobj_rom_004039E4] = 0.0f;
        }
        D_uvdobj_rom_004039DC[*D_uvdobj_rom_004039E4] |= 1;
        *D_uvdobj_rom_004039E4 += 1;
        if (*D_uvdobj_rom_004039E4 >= sUvQueryExports->func_uvquery_rom_00400224()) {
            break;
        }
    }
    if (*D_uvdobj_rom_004039E4 != 0) {
        *arg4 = D_uvdobj_rom_004039D4;
        *arg5 = D_uvdobj_rom_004039D0;
        *arg6 = D_uvdobj_rom_004039D8;
    }
    return *D_uvdobj_rom_004039E4;
}

s32 func_uvdobj_rom_00402870(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 **arg6,
                             f32 **arg7, Vec3F **arg8) {
    DObj *temp_s0;
    f32 temp_fs0;
    f32 temp_fs1;
    ParsedUVMD *uvmd;
    f32 spBC;
    f32 temp_fs2;
    f32 temp_fs3;
    s32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    u16 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 sp88;

    *D_uvdobj_rom_004039E4 = 0;
    if ((arg0 == arg3) && (arg1 == arg4) && (arg2 == arg5)) {
        temp_v0 = func_uvdobj_rom_00401F14(arg0, arg1, arg2);
        if (temp_v0 == 0xFFFF) {
            *arg6 = NULL;
            *arg7 = NULL;
            *arg8 = NULL;
            return 0;
        }
        *D_uvdobj_rom_004039D4 = temp_v0;
        *D_uvdobj_rom_004039D0 = 0.0f;
        D_uvdobj_rom_004039D8->x = 0.0f;
        D_uvdobj_rom_004039D8->y = 0.0f;
        D_uvdobj_rom_004039D8->z = 1.0f;
        *arg6 = D_uvdobj_rom_004039D4;
        *arg7 = D_uvdobj_rom_004039D0;
        *arg8 = D_uvdobj_rom_004039D8;
        return 1;
    }
    if (D_uvdobj_rom_004039EC == -1) {
        var_s0 = 0;
        spB0 = sUvDobjId;
    } else {
        spB0 = D_uvdobj_rom_004039EC + 1;
        var_s0 = D_uvdobj_rom_004039EC;
    }
    sp88 = spB0 - var_s0;
    if (sp88 >= 6) {
        temp_fs0 = arg3 - arg0;
        temp_fs1 = arg4 - arg1;
        temp_fs2 = arg5 - arg2;
        spA0 = sUvMathExports->uvSqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2)) * 0.5f;
        spAC = (0.5f * temp_fs0) + arg0;
        spA8 = (0.5f * temp_fs1) + arg1;
        spA4 = (0.5f * temp_fs2) + arg2;
    }
    for (var_s1 = var_s0; var_s1 < spB0; var_s1++) {
        temp_s0 = &sDObjs[var_s1];
        if ((temp_s0->modelId == 0xFFFF) || !(temp_s0->unk4 & 1)) {
            continue;
        }

        temp_fs0 = temp_s0->unk10;
        temp_fs1 = temp_s0->unk1C->m[3][0];
        temp_fs2 = temp_s0->unk1C->m[3][1];
        temp_fs3 = temp_s0->unk1C->m[3][2];
        if (((temp_fs1 + temp_fs0) < MIN(arg0, arg3))) {
            continue;
        }

        if ((MAX(arg0, arg3) < (temp_fs1 - temp_fs0))) {
            continue;
        }

        if (((temp_fs2 + temp_fs0) < MIN(arg1, arg4))) {
            continue;
        }

        if ((MAX(arg1, arg4) < (temp_fs2 - temp_fs0))) {
            continue;
        }

        if (((temp_fs3 + temp_fs0) < MIN(arg2, arg5))) {
            continue;
        }

        if ((MAX(arg2, arg5) < (temp_fs3 - temp_fs0))) {
            continue;
        }
        if (((sp88 < 6)
             || (sUvIntersectExports->func_uvintersect_rom_004004C4(spAC, spA8, spA4, spA0, temp_fs1,
                                                                    temp_fs2, temp_fs3, temp_fs0)
                 != 0))) {
            if ((sUvIntersectExports->func_uvintersect_rom_00400144(
                     arg0, arg1, arg2, arg3, arg4, arg5, temp_fs1, temp_fs2, temp_fs3, temp_fs0, &spBC)
                 == 0)) {
                continue;
            }
            uvmd = uvGetLoadedFile('UVMD', temp_s0->modelId);
            if (!(uvmd->unk5 & 6)) {
                continue;
            }

            *D_uvdobj_rom_004039E0 = var_s1;
            func_uvdobj_rom_004032DC(arg0, arg1, arg2, arg3, arg4, arg5, temp_s0);
        }
    }
    *arg6 = D_uvdobj_rom_004039D4;
    *arg7 = D_uvdobj_rom_004039D0;
    *arg8 = D_uvdobj_rom_004039D8;
    sUvQueryExports->uvQueryDoSorting();
    return *D_uvdobj_rom_004039E4;
}

s16 func_uvdobj_rom_00402D68(f32 arg0, f32 arg1, f32 arg2, f32 arg3, DObj *arg4) {
    char pad[0x10];
    ParsedUVMD_1 *temp_s6;
    ParsedUVMD *sp60;
    s16 temp_s1;
    s16 j;
    s16 var_s2;
    s16 i;
    s32 var_s0;
    s32 temp_s7;
    uvModelLOD *temp_v1;
    s16 unused;

    sp60 = uvGetLoadedFile('UVMD', arg4->modelId);
    temp_s6 = sp60->unk0;
    unused = -1;
    temp_s7 = temp_s6->unk8;
    sUvModelExports->func_uvmodel_rom_00402AD0();
    var_s2 = 0;
    for (i = 0; i < temp_s7; i++) {
        if (*D_uvdobj_rom_004039E4 >= sUvQueryExports->func_uvquery_rom_00400224()) {
            return sUvQueryExports->func_uvquery_rom_00400224();
        }
        temp_v1 = &temp_s6->unk0[i];

        if ((arg4->unk14 & (1 << i)) || (temp_v1->unk7 & 1)
            || (((D_uvdobj_rom_004039F0 != -1)) && (i != D_uvdobj_rom_004039F0))) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }
        if ((var_s0 != 0) || !(temp_v1->unk7 & 2)) {
            sUvModelExports->func_uvmodel_rom_00402AFC((u32) arg4->unk1C + i * sizeof(Mtx4F));
            var_s2++;
            if (var_s0 != 0) {
                *D_uvdobj_rom_004039E0 = (*D_uvdobj_rom_004039E0 & 0xFFFFFF) | (i << 0x18);
                unused += sUvModelExports->func_uvmodel_rom_004006B4(
                    arg0, arg1, arg2, arg3, sUvModelExports->func_uvmodel_rom_00402AE0(),
                    &temp_s6->unk0[i], sp60);
            }
            if (i == (temp_s7 - 1)) {
                break;
            }

            temp_s1 = temp_s6->unk0[i].unk6 - temp_s6->unk0[i + 1].unk6;
            // clang-format off
            for (j = 0; j <= temp_s1; j++) { \
                sUvModelExports->func_uvmodel_rom_00402B98(); \
                var_s2 -= 1; \
            } // clang-format on
        }
    }
    for (i = 0; i < var_s2; i++) {
        sUvModelExports->func_uvmodel_rom_00402B98();
    }
    return -1;
}

s16 func_uvdobj_rom_00403054(f32 arg0, f32 arg1, f32 arg2, DObj *arg3) {
    s16 temp_s1;
    s16 temp_v0;
    s16 j;
    s16 var_s2;
    s16 i;
    s32 temp_s5;
    s32 var_s0;
    ParsedUVMD_1 *temp_s6;
    s32 temp_s7;
    void *temp_v0_2;
    uvModelLOD *temp_v1;
    ParsedUVMD *uvmd = uvGetLoadedFile('UVMD', arg3->modelId);

    temp_s6 = uvmd->unk0;
    temp_s7 = temp_s6->unk8;
    sUvModelExports->func_uvmodel_rom_00402AD0();
    var_s2 = 0;
    for (i = 0; i < temp_s7; i++) {
        temp_v1 = &temp_s6->unk0[i];
        if ((arg3->unk14 & (1 << i)) || (temp_v1->unk7 & 1)
            || (((D_uvdobj_rom_004039F0 != -1)) && (i != D_uvdobj_rom_004039F0))) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }
        if ((var_s0 != 0) || !(temp_v1->unk7 & 2)) {
            sUvModelExports->func_uvmodel_rom_00402AFC(&arg3->unk1C[i]);
            var_s2++;
            if (var_s0 != 0) {
                *D_uvdobj_rom_004039E0 = (*D_uvdobj_rom_004039E0 & 0xFFFFFF) | (i << 0x18);
                temp_v0 = sUvModelExports->func_uvmodel_rom_0040215C(
                    arg0, arg1, arg2, sUvModelExports->func_uvmodel_rom_00402AE0(), &temp_s6->unk0[i]);
                if (temp_v0 >= 0) {
                    return temp_v0;
                }
            }
            if ((i + 1) == temp_s7) {
                break;
            }
            temp_s1 = temp_s6->unk0[i].unk6 - temp_s6->unk0[i + 1].unk6;
            // clang-format off
            for (j = 0; j <= temp_s1; j++) { \
                sUvModelExports->func_uvmodel_rom_00402B98(); \
                var_s2--; \
            } // clang-format on
            continue;
        }
    }
    for (i = 0; i < var_s2; i++) {
        sUvModelExports->func_uvmodel_rom_00402B98();
    }
    return -1;
}

s16 func_uvdobj_rom_004032DC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, DObj *arg6) {
    char pad[0x10];
    ParsedUVMD *sp8C;
    ParsedUVMD *temp_v0;
    ParsedUVMD_1 *temp_s6;
    s16 temp_s1;
    s16 j;
    s16 var_s2;
    s16 i;
    s32 var_s0;
    s32 temp_s7;
    uvModelLOD *temp_v0_2;
    uvModelLOD *temp_v1;

    temp_v0 = uvGetLoadedFile('UVMD', arg6->modelId);
    sp8C = temp_v0;
    temp_s6 = temp_v0->unk0;
    temp_s7 = temp_s6->unk8;
    sUvModelExports->func_uvmodel_rom_00402AD0();
    var_s2 = 0;
    for (i = 0; i < temp_s7; i++) {
        temp_v1 = &temp_s6->unk0[i];
        if ((arg6->unk14 & (1 << i)) || (temp_v1->unk7 & 1)
            || (((D_uvdobj_rom_004039F0 != -1)) && (i != D_uvdobj_rom_004039F0))) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }
        if ((var_s0 != 0) || !(temp_v1->unk7 & 2)) {
            sUvModelExports->func_uvmodel_rom_00402AFC(&arg6->unk1C[i]);
            var_s2 += 1;
            if (var_s0 != 0) {
                *D_uvdobj_rom_004039E0 = (*D_uvdobj_rom_004039E0 & 0xFFFFFF) | (i << 0x18);
                sUvModelExports->func_uvmodel_rom_0040199C(arg0, arg1, arg2, arg3, arg4, arg5,
                                                           sUvModelExports->func_uvmodel_rom_00402AE0(),
                                                           &temp_s6->unk0[i], sp8C);
            }
            if (i == (temp_s7 - 1)) {
                break;
            }
            temp_s1 = temp_s6->unk0[i].unk6 - temp_s6->unk0[i + 1].unk6;

            // clang-format off
            for (j = 0; j <= temp_s1; j++) { \
                sUvModelExports->func_uvmodel_rom_00402B98(); \
                var_s2 -= 1; \
            }
            // clang-format on
        }
    }

    for (i = 0; i < var_s2; i++) {
        sUvModelExports->func_uvmodel_rom_00402B98();
    }
    return -1;
}

s32 func_uvdobj_rom_0040359C(s32 arg0, Quat *arg1, u8 *arg2) {
    DObj *temp_s6;
    s32 var_s5;
    s32 i;
    ParsedUVMD *uvmd;

    temp_s6 = &sDObjs[arg0];
    uvmd = uvGetLoadedFile('UVMD', uvDobjGetModel(arg0));
    if (uvmd->unk6 >= 2) {
        var_s5 = uvmd->unk6 - 1;
    } else {
        var_s5 = 0;
    }
    for (i = 0; i < var_s5; i++, arg1++) {
        sUvQuatExports->func_uvquat_rom_004000D8(arg1, (u32) temp_s6->unk1C + (i + 1) * sizeof(Mtx4F));
        arg2[i] = i + 1;
    }
    return var_s5;
}

void func_uvdobj_rom_0040368C(void) {
    Gfx **gdl;
    void *sp48;
    void *sp44;

    gdl = sUvGfxMgrExports->uvGetDisplayListHead();
    sp48 = sUvGfxMgrExports->func_uvgfxmgr_rom_0040204C();
    sp44 = sUvGfxMgrExports->func_uvgfxmgr_rom_00402058();
    sUvGfxStateExports->uvGfxSync();
    gDPSetRenderMode(gdl[0]++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    sUvGfxStateExports->uvGfxSync();
    gDPSetCycleType(gdl[0]++, G_CYC_FILL);
    sUvGfxStateExports->uvGfxSync();
    gDPSetFillColor(gdl[0]++, 0);
    sUvGfxStateExports->uvGfxSync();
    gDPSetColorImage(gdl[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sUvGfxMgrExports->uvGetScreenWidth(),
                     osVirtualToPhysical(sp48));
    sUvGfxStateExports->uvGfxSync();
    gDPFillRectangle(gdl[0]++, 2, 120, 310, 235);
    sUvGfxStateExports->uvGfxSync();
    sUvGfxStateExports->uvGfxSync();
    gDPSetCycleType(gdl[0]++, G_CYC_2CYCLE);
    sUvGfxStateExports->uvGfxSync();
    gDPSetColorImage(gdl[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sUvGfxMgrExports->uvGetScreenWidth(),
                     osVirtualToPhysical(sp44));
    sUvGfxStateExports->uvGfxSync();
}

void func_uvdobj_rom_004038C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    DObj *sp54;
    UnkStruct_uvlight_rom_00401758 sp20;

    sp20.unk2C = arg1;
    sp20.unk28 = arg2;
    sp20.unk24 = arg3;
    sp54 = &sDObjs[arg0];
    if (sp54->unk2 != -1) {
        sUvLightExports->func_uvlight_rom_00401624(sp54->unk2);
    }
    sp54->unk2 = sUvLightExports->func_uvlight_rom_00401340(&sp20);
}

u16 func_uvdobj_rom_00403954(s32 **arg0) {
    *arg0 = D_uvdobj_rom_004039B8;
    return D_uvdobj_rom_004039BC;
}

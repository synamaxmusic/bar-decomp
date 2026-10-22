// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"
#include "stdarg.h"

#define DEG_TO_RAD 0.0174533f
#define DEFAULT_BILLBOARD_COUNT 100

typedef struct UnkTerraExports_s {
    /* 0x00 */ char pad0[0xAC];
    /* 0xAC */ void (*unkAC)(s32, s32, f32, f32, void (*)(s32, void *), void *, f32);
} UnkTerraExports;

typedef struct BillBoard_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 allocated;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 active;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ char pad7[1];
    /* 0x08 */ u16 textureSeq; 
    /* 0x0A */ u16 texture; 
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 angle; // rot angle?
    /* 0x14 */ f32 scaleX;
    /* 0x18 */ f32 scaleY;
    /* 0x1C */ f32 scaleZ;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ u8 colorRed;
    /* 0x25 */ u8 colorGreen;
    /* 0x26 */ u8 colorBlue;
    /* 0x27 */ u8 colorAlpha;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ char pad2E[2];
    /* 0x30 */ Mtx4F trans;        
    /* 0x70 */ void (*unk70)(void);
    /* 0x74 */ void (*unk74)(void);
} BillBoard;    /* size = 0x78 */

void uvBillDestroy(void);
void uvBillDraw(s32 arg0, BillBoard *arg1);
void func_uvbill_rom_00400D9C(s32 arg0);
void func_uvbill_rom_00400DEC(s32 arg0);
s32 func_uvbill_rom_004010B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6,
                             s32 **arg7, f32 **arg8, Vec3F **arg9);
s32 func_uvbill_rom_00401388(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_uvbill_rom_00401418(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 **arg5);
void uvBillPosm(s32 arg0, Mtx4F *arg1);
void uvBillProps(s32 arg0, ...);
s32 uvBillFindFree(void);
void uvBillFreeId(s32 arg0);
void func_uvbill_rom_004002C0(s32 arg0);
void __entrypoint_func_uvbill_rom_400000(UvBill_Exports *exports);

// .data
BillBoard *sBillBoardPool = NULL;
s32 *D_uvbill_rom_00402004 = NULL;
Vec3F *D_uvbill_rom_00402008 = NULL;
f32 *D_uvbill_rom_0040200C = NULL;
s32 D_uvbill_rom_00402010[] = { 0x00240000, __entrypoint_func_uvbill_rom_400000, 0, 0 };

// .bss
s32 sBillBoardCount;
static UvGfxState_Rom_Exports *sUvGfxState;
static UvFMtx_Rom_Exports *sUvFmtxExports;
static UvChannel_Exports *sUvChannel_Exports;
static UvMath_Exports *sUvMathExports;
static UvIntersect_Exports *sUvIntersectExports;
static UvDGeom_Rom_Exports *sUvDGeomExports;
static UvGfxMgr_Exports *sUvGfxMgrExports;
static UvCback_Exports *sUvCbackExports;
static UvTSeq_Exports *sUvTSeqExports;
static UnkTerraExports *sUvTerraExports; // terra exports

void __entrypoint_func_uvbill_rom_400000(UvBill_Exports *exports) {
    s32 *billBoardCount;

    uvUpdateFileAllocPtr(exports);
    exports->uvBillDestroy = uvBillDestroy;
    exports->func_uvbill_rom_004002C0 = func_uvbill_rom_004002C0;
    exports->func_uvbill_rom_004010B8 = func_uvbill_rom_004010B8;
    exports->func_uvbill_rom_00401388 = func_uvbill_rom_00401388;
    exports->func_uvbill_rom_00401418 = func_uvbill_rom_00401418;
    exports->uvBillPosm = uvBillPosm;
    exports->uvBillProps = uvBillProps;
    exports->uvBillFindFree = uvBillFindFree;
    exports->uvBillFreeId = uvBillFreeId;
    billBoardCount = uvGetSystemProp(SYSTEM_PROPID_BILLBOARD_COUNT);
    if (billBoardCount == NULL) {
        sBillBoardCount = DEFAULT_BILLBOARD_COUNT;
    } else {
        if (*billBoardCount != 0) {
            sBillBoardCount = *billBoardCount;
        } else {
            sBillBoardCount = DEFAULT_BILLBOARD_COUNT;
        }
    }
    // FAKE
    do {
    } while (0);
    sBillBoardPool =
        _uvMemAllocAlign8(sBillBoardCount * sizeof(BillBoard));
    D_uvbill_rom_00402004 = _uvMemAllocAlign8(sBillBoardCount * sizeof(s32));
    D_uvbill_rom_00402008 = _uvMemAllocAlign8(sBillBoardCount * sizeof(Vec3F));
    D_uvbill_rom_0040200C = _uvMemAllocAlign8(sBillBoardCount * sizeof(f32));

    uvMemSet(sBillBoardPool, 0, sBillBoardCount * sizeof(BillBoard));
    uvMemSet(D_uvbill_rom_00402004, 0, sBillBoardCount * sizeof(s32));
    uvMemSet(D_uvbill_rom_00402008, 0, sBillBoardCount * sizeof(Vec3F));
    uvMemSet(D_uvbill_rom_0040200C, 0, sBillBoardCount * sizeof(f32));
    sUvGfxState = uvLoadModule('STAT');
    sUvChannel_Exports = uvLoadModule('CHAN');
    sUvFmtxExports = uvLoadModule('FMTX');
    sUvMathExports = uvLoadModule('MATH');
    sUvTSeqExports = uvLoadModule('TSEQ');
    sUvDGeomExports = uvLoadModule('DGEO');
    sUvGfxMgrExports = uvLoadModule('GMGR');
    sUvCbackExports = uvLoadModule('CBCK');
    sUvTerraExports = uvLoadModule('TERR');
    sUvCbackExports->uvAddCallback(sUvGfxMgrExports->func_uvgfxmgr_rom_00400AB8(1),
                                   func_uvbill_rom_00400D9C, 0, 0);
}

void func_uvbill_rom_004002C0(s32 arg0) {
    CallbackList *callbackList;

    sUvChannel_Exports->func_uvchannel_rom_00400288(arg0, 6, &callbackList, 0);
    sUvCbackExports->uvAddCallback(callbackList, func_uvbill_rom_00400DEC, 0, 0x32);
}

void uvBillDestroy(void) {
    _uvMemFree(D_uvbill_rom_0040200C);
    _uvMemFree(D_uvbill_rom_00402008);
    _uvMemFree(D_uvbill_rom_00402004);
    _uvMemFree(sBillBoardPool);
    uvUnloadModule('STAT');
    uvUnloadModule('CHAN');
    uvUnloadModule('FMTX');
    uvUnloadModule('MATH');
    uvUnloadModule('TSEQ');
    uvUnloadModule('DGEO');
    uvUnloadModule('CBCK');
}

void uvBillDraw(s32 arg0, BillBoard *arg1) {
    s32 texture;
    u16 spCA;
    u16 spC8;
    u16 spC6;
    u16 spC4;
    u16 spC2;
    u16 spC0;
    u16 spBE;
    u16 spBC;
    s16 pad;
    s16 spB8;
    s16 spB6;
    s32 var_v1;
    f32 temp_fv0;
    f32 spA8;
    f32 temp_fv1;
    f32 spA0;
    Mtx4F sp60;
    ParsedUVTX *uvtx;
    s32 var_v0;

    if (arg1->colorAlpha == 0) {
        return;
    }

    sUvGfxState->uvGfxStatePush();
    sUvGfxState->uvGfxStateSetFlags(0x04E20FFF);
    sUvGfxState->func_uvgfxstate_rom_00401354(0x99140000);
    if (arg1->unk70 != NULL) {
        arg1->unk70();
    }
    if (arg1->unk2 == 0) {
        if (arg1->unk74 != NULL) {
            arg1->unk74();
        }
        sUvGfxState->uvGfxStatePop();
        return;
    }
    if (arg1->textureSeq != 0xFF) {
        texture = sUvTSeqExports->uvTexSeqGetCurFrameTexture(arg1->textureSeq);
    } else {
        if (arg1->texture != 0xFFF) {
            texture = arg1->texture;
        } else {
            texture = 0xFFF;
        }
    }
    if (texture != 0xFFF) {
        uvtx = uvGetLoadedFile('UVTX', texture);
    } else {
        uvtx = NULL;
    }
    if ((texture != 0xFFF) && (uvtx != NULL)) {
        sUvGfxState->uvGfxStateBindTexture(texture);
        if (arg1->angle == 0.0f) {
            spCA = 0;
            spC8 = 0;
            var_v0 = uvtx->width << 5;
            spC2 = spC6 = var_v0;
            spC4 = 0;
            var_v1 = uvtx->height << 5;
            spBC = spC0 = var_v1;
            spBE = 0;
        } else {
            spA0 = arg1->angle * DEG_TO_RAD;
            spA8 = sUvMathExports->uvSinF(spA0);
            temp_fv0 = sUvMathExports->uvCosF(spA0);
            temp_fv1 = uvtx->width * 16.0f;
            spA0 = uvtx->height * 16.0f;
            spCA = ((-temp_fv1 * temp_fv0) + (spA0 * spA8) + temp_fv1);
            spC8 = (((-temp_fv1 * spA8) - (spA0 * temp_fv0)) + spA0);
            spC6 = ((temp_fv1 * temp_fv0) + (spA0 * spA8) + temp_fv1);
            spC4 = (((temp_fv1 * spA8) - (spA0 * temp_fv0)) + spA0);
            spC2 = (((temp_fv1 * temp_fv0) - (spA0 * spA8)) + temp_fv1);
            spC0 = ((temp_fv1 * spA8) + (spA0 * temp_fv0) + spA0);
            spBE = (((-temp_fv1 * temp_fv0) - (spA0 * spA8)) + temp_fv1);
            spBC = ((-temp_fv1 * spA8) + (spA0 * temp_fv0) + spA0);
        }
        if (arg1->unk5 != 0) {
            var_v0 = spCA;
            spCA = spC2;
            spC2 = var_v0;
            var_v0 = spC6;
            spC6 = spBE;
            spBE = var_v0;
        }
        if (arg1->unk6 != 0) {
            var_v0 = spC8;
            spC8 = spC0;
            spC0 = var_v0;
            var_v0 = spC4;
            spC4 = spBC;
            spBC = var_v0;
        }
    }
    if (arg1->colorAlpha < 0xFF) {
        sUvGfxState->uvGfxStateSetFlags(0x04800000);
    }
    sUvFmtxExports->uvMat4FCopy(&sp60, &arg1->trans);
    sUvFmtxExports->uvMat4Scale(&sp60, arg1->scaleX, arg1->scaleY, arg1->scaleZ);
    sUvFmtxExports->func_uvfmtx_rom_00402858(&sp60);
    sUvDGeomExports->uvVtxBeginPoly();
    if (arg1->unk4 != 0) {
        spB8 = -1;
        spB6 = 1;
    } else {
        spB8 = 0;
        spB6 = 2;
    }
    if (arg1->unk2C != 0) {
        sUvDGeomExports->uvVtxLoad(arg1->unk2C - 1, 4);
    } else {
        arg1->unk2C = sUvDGeomExports->uvVtx(-1, 0, spB8, spCA, spC8, arg1->colorRed, arg1->colorGreen,
                                             arg1->colorBlue, arg1->colorAlpha)
                      + 1;

        sUvDGeomExports->uvVtx(1, 0, spB8, spC6, spC4, arg1->colorRed, arg1->colorGreen, arg1->colorBlue,
                               arg1->colorAlpha);
        sUvDGeomExports->uvVtx(1, 0, spB6, spC2, spC0, arg1->colorRed, arg1->colorGreen, arg1->colorBlue,
                               arg1->colorAlpha);
        sUvDGeomExports->uvVtx(-1, 0, spB6, spBE, spBC, arg1->colorRed, arg1->colorGreen, arg1->colorBlue,
                               arg1->colorAlpha);
    }
    sUvDGeomExports->uvVtxEndPoly();
    sUvFmtxExports->uvGfxMtxFViewPop();
    if (arg1->unk74 != NULL) {
        arg1->unk74();
    }
    sUvGfxState->uvGfxStatePop();
}

void func_uvbill_rom_00400D9C(s32 arg0) {
    s32 i;

    for (i = 0; i < sBillBoardCount; i++) {
        BillBoard *a0 = &sBillBoardPool[i];
        a0->unk2C = 0;
    }
}

void func_uvbill_rom_00400DEC(s32 arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 var_fa0;
    s32 i;
    BillBoard *billBoard;
    Mtx4F sp9C;
    Vec3F sp90;

    for (i = 0; i < sBillBoardCount; i++) {
        billBoard = &sBillBoardPool[i];
        if (!billBoard->active) {
            continue;
        }
        sUvChannel_Exports->func_uvchannel_rom_00400288(arg0, 7, &sp90, 3, &sp9C, 0);
        temp_fs1 = billBoard->trans.m[3][0] - sp90.x;
        temp_fs2 = billBoard->trans.m[3][1] - sp90.y;
        temp_fs0 = billBoard->trans.m[3][2] - sp90.z;
        temp_fv0 = sUvMathExports->uvSqrtf(SQ(temp_fs1) + SQ(temp_fs2) + SQ(temp_fs0));
        if (billBoard->unk20 < temp_fv0) {
            continue;
        } else if (sUvChannel_Exports->func_uvchannel_rom_004014E8(arg0, temp_fs1, temp_fs2, temp_fs0,
                                                                  billBoard->unkC)
                   == 0) {
            continue;
        }

        if (billBoard->unk0 == 3) {
            sUvFmtxExports->func_uvfmtx_rom_00400588(&billBoard->trans, &sp9C);
        } else if (billBoard->unk0 == 2) {
            temp_fv0_2 = sUvMathExports->uvSqrtf(SQ(temp_fs1) + SQ(temp_fs2));
            if (temp_fv0_2 != 0.0f) {
                var_fa0 = 1.0f / temp_fv0_2;
            } else {
                var_fa0 = 1.0f;
            }
            temp_fv0_2 = temp_fs1 * var_fa0;
            temp_fv1 = temp_fs2 * var_fa0;
            billBoard->trans.m[0][2] = 0.0f;
            billBoard->trans.m[1][2] = 0.0f;
            billBoard->trans.m[2][0] = 0.0f;
            billBoard->trans.m[1][1] = temp_fv1;
            billBoard->trans.m[0][0] = (f32) -temp_fv1;
            billBoard->trans.m[0][1] = temp_fv0_2;
            billBoard->trans.m[1][0] = temp_fv0_2;
            billBoard->trans.m[2][1] = 0.0f;
            billBoard->trans.m[2][2] = 1.0f;
        }
        sUvTerraExports->unkAC(arg0, 1, billBoard->trans.m[3][0], billBoard->trans.m[3][1],
                               (void*)uvBillDraw, billBoard, temp_fv0);
    }
}

s32 func_uvbill_rom_004010B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6,
                             s32 **arg7, f32 **arg8, Vec3F **arg9) {
    f32 temp_fv0;
    s32 i;
    s32 var_s3;
    f32 spA8;
    s32 var_s4;
    BillBoard *temp_s0;

    *arg7 = D_uvbill_rom_00402004;
    *arg8 = D_uvbill_rom_0040200C;
    *arg9 = D_uvbill_rom_00402008;
    var_s4 = 0;

    if ((arg0 == arg3) && (arg1 == arg4) && (arg2 == arg5)) {
        var_s4 = func_uvbill_rom_00401418(arg0, arg1, arg2, 0.0f, arg6, arg7);
        if (var_s4 > 0) {
            *D_uvbill_rom_0040200C = 0.0f;
            temp_fv0 = *D_uvbill_rom_0040200C;
            D_uvbill_rom_00402008->z = temp_fv0;
            D_uvbill_rom_00402008->y = temp_fv0;
            D_uvbill_rom_00402008->x = temp_fv0;
            *arg8 = D_uvbill_rom_0040200C;
            *arg9 = D_uvbill_rom_00402008;
            return var_s4;
        }
    }
    for (i = 0; i < sBillBoardCount; i++) {
        temp_s0 = &sBillBoardPool[i];
        if ((temp_s0->active) && ((arg6 == 0) || (temp_s0->unk28 & arg6))) {
            //! @bug: sUvIntersectExports is uninitialized!
            if (sUvIntersectExports->func_uvintersect_rom_00400144(
                    arg0, arg1, arg2, arg3, arg4, arg5, temp_s0->trans.m[3][0], temp_s0->trans.m[3][1],
                    temp_s0->trans.m[3][2], temp_s0->unkC, &spA8)
                == 0) {
                continue;
            }
            sUvIntersectExports->func_uvintersect_rom_00400700(
                arg0, arg1, arg2, arg3, arg4, arg5, spA8, temp_s0->trans.m[3][0],
                temp_s0->trans.m[3][1], temp_s0->trans.m[3][2], &D_uvbill_rom_00402008[var_s4]);
            D_uvbill_rom_00402004[var_s4] = i;
            D_uvbill_rom_0040200C[var_s4] = spA8;
            var_s4++;
        }
    }
    return var_s4;
}

s32 func_uvbill_rom_00401388(s32 bill, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    BillBoard *temp_v0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_v0 = &sBillBoardPool[bill];
    temp_fv0 = arg1 - temp_v0->trans.m[3][0];
    temp_fv1 = arg2 - temp_v0->trans.m[3][1];
    temp_ft4 = arg3 - temp_v0->trans.m[3][2];
    temp_ft5 = temp_v0->unkC + arg4;
    if ((SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_ft4)) <= SQ(temp_ft5)) {
        return TRUE;
    }
    return FALSE;
}

s32 func_uvbill_rom_00401418(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 **arg5) {
    s32 i;
    s32 var_s2;
    BillBoard *temp_v0;

    var_s2 = 0;
    for (i = 0; i < sBillBoardCount; i++) {
        temp_v0 = &sBillBoardPool[i];
        if ((temp_v0->active != 0) && ((arg4 == 0) || (temp_v0->unk28 & arg4))) {
            if (func_uvbill_rom_00401388(i, arg0, arg1, arg2, arg3) == 0) {
                continue;
            }
            D_uvbill_rom_00402004[var_s2] = i;
            var_s2++;
        }
    }
    *arg5 = D_uvbill_rom_00402004;
    return var_s2;
}

void uvBillPosm(s32 id, Mtx4F *mtx) {
    BillBoard *a0;
    if ((id >= 0) && (id < sBillBoardCount)) {
        sUvFmtxExports->uvMat4FCopy(&GET_ITEM(BillBoard, sBillBoardPool, id)->trans, mtx);
    }
}

void uvBillProps(s32 id, ...) {
    BillBoard *temp_s0;
    f32 var_fv0;
    s32 prop;
    va_list args;
    f32 y = 10.0f;

    if ((id < 0) || (id >= sBillBoardCount)) {
        return;
    }
    temp_s0 = &sBillBoardPool[id];
    va_start(args, id);
    while (TRUE) {
        prop = va_arg(args, s32);
        // FAKE: Make IDO reserve ft4 for the literal and fa1 for y...
        if (y > 4) {
        }
        if (y > 4) {
        }
        if (y > 4) {
        }
        if (y > 4) {
        }
        if (y > 4) {
        }

        switch (prop) {
            case 0:
                return;
            case 1:
                temp_s0->trans.m[3][0] = va_arg(args, f64);
                temp_s0->trans.m[3][1] = va_arg(args, f64);
                temp_s0->trans.m[3][2] = va_arg(args, f64);
                break;
            case 2:
                temp_s0->active = va_arg(args, s32);
                break;
            case 3:
                prop = va_arg(args, s32);
                if (prop > 0 && prop < 4) {
                    temp_s0->unk0 = prop;
                }
                break;
            case 4:
                temp_s0->textureSeq = va_arg(args, s32);
                break;
            case 5:
                temp_s0->texture = va_arg(args, s32);
                break;
            case 6:
                temp_s0->unk4 = va_arg(args, s32);
                if (temp_s0->unk4 != 0) {
                    var_fv0 = temp_s0->scaleZ;
                } else {
                    var_fv0 = 2.0f * temp_s0->scaleZ;
                }
                temp_s0->unkC = sUvMathExports->uvSqrtf(SQ(temp_s0->scaleX) + SQ(var_fv0));
                break;
            case 7:
                temp_s0->scaleX = va_arg(args, f64);
                temp_s0->scaleY = va_arg(args, f64);
                temp_s0->scaleZ = va_arg(args, f64);
                if (temp_s0->unk4 != 0) {
                    var_fv0 = temp_s0->scaleZ;
                } else {
                    var_fv0 = 2.0f * temp_s0->scaleZ;
                }
                temp_s0->unkC = sUvMathExports->uvSqrtf(SQ(temp_s0->scaleX) + SQ(var_fv0));
                break;
            case 9:
                temp_s0->unk28 = va_arg(args, s32);
                break;
            case 8:
                var_fv0 = va_arg(args, f64);
                temp_s0->colorRed = var_fv0 * 255.0f;
                var_fv0 = va_arg(args, f64);
                temp_s0->colorGreen = var_fv0 * 255.0f;
                var_fv0 = va_arg(args, f64);
                temp_s0->colorBlue = var_fv0 * 255.0f;
                var_fv0 = va_arg(args, f64);
                temp_s0->colorAlpha = var_fv0 * 255.0f;
                break;
            case 10:
                temp_s0->unk20 = va_arg(args, f64);
                break;
            case 11:
                temp_s0->angle = va_arg(args, f64);
                break;
            case 12:
                var_fv0 = va_arg(args, f64);
                temp_s0->colorAlpha = var_fv0 * 255.0f;
                break;
            case 13:
                temp_s0->unk2 = va_arg(args, s32);
                break;
            case 14:
                temp_s0->unk5 = va_arg(args, s32);
                break;
            case 15:
                temp_s0->unk6 = va_arg(args, s32);
                break;
            default:
                return;
        }
    }
}

s32 uvBillFindFree(void) {
    s32 i;
    BillBoard *billBoard;

    for (i = 0; i < sBillBoardCount; i++) {
        billBoard = &sBillBoardPool[i];
        if (!billBoard->allocated) {
            billBoard->unk0 = 2;
            billBoard->allocated = TRUE;
            billBoard->active = TRUE;
            billBoard->texture = 0xFFF;
            billBoard->textureSeq = 0xFF;
            billBoard->colorAlpha = 0xFF;
            billBoard->colorBlue = 0xFF;
            billBoard->colorGreen = 0xFF;
            billBoard->colorRed = 0xFF;
            billBoard->unk4 = 0;
            billBoard->unk28 = 0;
            billBoard->scaleZ = 1.0f;
            billBoard->scaleY = 1.0f;
            billBoard->scaleX = 1.0f;
            billBoard->unkC = sUvMathExports->uvSqrtf(5.0f);
            billBoard->unk5 = 0;
            billBoard->unk6 = 0;
            billBoard->angle = 0.0f;
            billBoard->unk20 = 100000.0f;
            billBoard->unk2 = 1;
            billBoard->unk2C = 0;
            billBoard->unk74 = NULL;
            billBoard->unk70 = NULL;
            sUvFmtxExports->uvMat4SetIdentity(&billBoard->trans);
            return i;
        }
    }
    return 0xFFFF;
}

void uvBillFreeId(s32 id) {
    if ((id < 0) || (id >= sBillBoardCount)) {
        return;
    }

    if (!sBillBoardPool[id].allocated) {
        return;
    }
    sBillBoardPool[id].active = FALSE;
    sBillBoardPool[id].allocated = FALSE;
}

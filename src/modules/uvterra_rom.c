// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"
#include "stdarg.h"

typedef struct TerraSettings_s {
    s32 unk0;
    s32 unk4;
} TerraSettings;

typedef struct UnkStruct_uvterra_rom_004072EC_s {
    /* 0x00 */ uvGfxState unk0;
    /* 0x18 */ char pad18[6];
    /* 0x1E */ u16 unk1E;     /* inferred */
    /* 0x20 */ char pad20[4]; /* maybe part of unk1E[3]? */
    /* 0x24 */ f32 unk24;     /* inferred */
    /* 0x28 */ f32 unk28;     /* inferred */
    /* 0x2C */ f32 unk2C;     /* inferred */
    /* 0x30 */ f32 unk30;     /* inferred */
    /* 0x34 */ char pad34[4];
    /* 0x38 */ s32 unk38;         /* inferred */
} UnkStruct_uvterra_rom_004072EC; /* size = 0x48 */

typedef struct UnkStruct_uvterra_rom_0040FBE8_s {
    /* 0x00 */ uvUnkTileStruct* unk0;                            /* inferred */
    /* 0x04 */ u8 unk4;                             /* inferred */
    /* 0x05 */ char pad5[1];
    /* 0x06 */ u16 unk6;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ u8 unkC;
} UnkStruct_uvterra_rom_0040FBE8;                   /* size = 0x10 */

typedef struct UnkStruct_uvterra_rom_0040F774_inner_s {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
} UnkStruct_uvterra_rom_0040F774_inner;             /* size = 0x18 */


typedef struct UnkStruct_uvterra_rom_0040F774_s {
    /* 0x00 */ Vec3F unk0[6];
    /* 0x48 */ u8 unk48;                            /* inferred */
    /* 0x49 */ char pad49[3];                       /* maybe part of unk48[4]? */
    /* 0x4C */ UnkStruct_uvterra_rom_0040F774_inner unk4C;
} UnkStruct_uvterra_rom_0040F774;                   /* size = 0x64 */

void func_uvterra_rom_004005A4(void);
void func_uvterra_rom_00400640(s32 arg0);
void func_uvterra_rom_004006E0(s32 arg0, s32 arg1);
s32 func_uvterra_rom_00400774(s32 arg0);
void _uvTerraDraw(s32 arg0);
void uvTerraGetPlane(s32 arg0, u32 arg1, f32 arg2, f32 arg3, f32 *arg4, Vec3F *arg5);
void func_uvterra_rom_004010B4(s32 arg0, u32 arg1, Vec3F *arg2);
s32 uvTerraGetState(s32 arg0, u32 arg1);
s32 func_uvterra_rom_00401284(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 *arg5, s32 *arg6, s32 *arg7);
void *func_uvterra_rom_00401E28(s32 arg0);
u32 func_uvterra_rom_00401E64(s32 arg0, f32 arg1, f32 arg2, s32 **arg3);
s32 func_uvterra_rom_00402244(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 **arg7, f32 **arg8);
void func_uvterra_rom_00403270(s32 arg0, u32 arg1, s8 *arg2, s8 *arg3, s8 *arg4);
void func_uvterra_rom_00403464(s32 arg0, u32 arg1, Vec3F *arg2, Vec3F *arg3, Vec3F *arg4);
s32 func_uvterra_rom_00403630(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4);
s32 func_uvterra_rom_004037B8(s32 arg0, u32 arg1, f32 *arg2, f32 *arg3);
s32 uvSobjGetSeg(s32 terraId, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 **arg8, f32 **arg9, Vec3F **arg10, s32 **arg11);
s32 func_uvterra_rom_00404E14(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 **arg6, f32 **arg7, Vec3F **arg8, s32 **arg9);
s32 func_uvterra_rom_004060A4(s32 arg0, u32 arg1);
s32 func_uvterra_rom_00406160(s32 terraId, s32 texture, s32 **arg2);
s32 func_uvterra_rom_00406324(Vtx *arg0, Vtx *arg1, Vtx *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 arg6, f32 arg7);
void uvTerraGetColor(s32 terraId, u32 surfaceId, f32 arg2, f32 arg3, u8 *r, u8 *g, u8 *b, u8 *a);
void func_uvterra_rom_00406C60(s32 arg0, u32 arg1, f32 arg2, f32 arg3, u8 *r, u8 *g, u8 *b, u8 *a);
s32 func_uvterra_rom_004071A4(s32 arg0, f32 arg1, f32 arg2, f32 *arg3);
void func_uvterra_rom_004072BC(s32 arg0);
s32 func_uvterra_rom_004072C8(void);
void func_uvterra_rom_004072D4(s32 arg0);
s32 func_uvterra_rom_004072E0(void);
void uvTobjsDraw(s32 arg0, u16 arg1, Mtx4F *arg2, Unk80225FBC_0x28 *arg3, u16 arg4);
s32 uvSobjGetIds(s32 arg0, s32 modelId, s32 **arg2);
void func_uvterra_rom_00407680(s32 arg0, f32 arg1);
void uvSobjsDraw(s32 arg0, Mtx4F *arg1, u16 arg2, u16 arg3, UnkSobjDraw *arg4, u16 arg5);
s32 func_uvterra_rom_00407A80(s32 arg0, s32 arg1, s32 arg2);
void func_uvterra_rom_00407A94(s32 arg0, UnkSobjDraw *sobj);
void func_uvterra_rom_00407B0C(UNUSED s32 arg0, UnkSobjDraw *sobj);
void func_uvterra_rom_00407E5C(s32 arg0, UnkSobjDraw *sobj);
void func_uvterra_rom_00407ED4(s32 arg0, UnkSobjDraw *arg1);
void uvSobjPosm(s32 uvct, s32 arg1, Mtx4F *arg2);
void uvSobjProps(s32 uvct, ...);
void func_uvterra_rom_00408614(s32 contour, s32 arg1, Mtx4F *arg2);
u16 func_uvterra_rom_004087D8(s32 contour);
void uvSobjModel(s32 contour, s32 modelId);
s32 func_uvterra_rom_0040888C(s32 terraId, f32 arg1, f32 arg2, f32 arg3);
s32 func_uvterra_rom_00408AD8(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 **arg5, f32 **arg6, Vec3F **arg7);
s32 func_uvterra_rom_00409394(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 **arg7, f32 **arg8, Vec3F **arg9);
s16 func_uvterra_rom_0040A08C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, UnkSobjDraw *sobj);
s16 func_uvterra_rom_0040A43C(f32 arg0, f32 arg1, f32 arg2, UnkSobjDraw *sobj);
s32 func_uvterra_rom_0040A79C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, UnkSobjDraw *sobj);
void func_uvterra_rom_0040AB14(s32 contour, ...);
void func_uvterra_rom_0040ABB4(s32 contour, s32 arg1);
s32 func_uvterra_rom_0040ABE0(s32 contour);
UnkSobjDraw *func_uvterra_rom_0040AC14(s32 contour);
u8 func_uvterra_rom_0040AC8C(s32 arg0);
void func_uvterra_rom_0040AC9C(s32 arg0);
void func_uvterra_rom_0040AE4C(s32 arg0);
void func_uvterra_rom_0040AFD8(s32 arg0, uvUnkTileStruct *arg1, u16 arg2, u16 arg3);
u16 func_uvterra_rom_0040B0C4(s16 arg0, s16 arg1, u8 arg2);
void uvComputeLineEndP(s16 *arg0, s16 *arg1, u16 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u8 arg10, f32 arg11, f32 arg12);
s32 func_uvterra_rom_0040B8C0(ParsedUVTR *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6, u16 *arg7, u16 *arg8, u8 arg9);
u16 func_uvterra_rom_0040BBC0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
u16 func_uvterra_rom_0040BD38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, void *arg12);
u16 func_uvterra_rom_0040BF74(f32 arg0, f32 arg1, uvUnkTileStruct *arg2, f32 arg3, f32 arg4);
void func_uvterra_rom_0040C08C(void);
UnkStruct_uvterra_rom_0040F774_inner *func_uvterra_rom_0040C0F8(s32 arg0);
void func_uvterra_rom_0040C218(s32 arg0);
u16 func_uvterra_rom_0040C490(Vec3F *arg0, Vec3F *arg1, Vec3F *arg2, Vec3F *arg3);
void func_uvterra_rom_0040C50C(ParsedUVTR *arg0, Vec3F *arg1, Vec3F *arg2, Vec3F *arg3, Vec3F *arg4, Vec3F *arg5);
void func_uvterra_rom_0040C998(Vec3F *arg0, f32 arg1, Vec3F *arg2);
void func_uvterra_rom_0040CA64(Vec3F **arg0, u8 *arg1);
s32 func_uvterra_rom_0040CEA8(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 func_uvterra_rom_0040CF98(u8 *arg0, s32 arg1);
void func_uvterra_rom_0040D050(void);
void func_uvterra_rom_0040D128(s32 arg0, s32 arg1, f32 arg2, f32 arg3, void (*arg4 )(s32, UnkSobjDraw* ), s32 arg5, f32 arg6);
void __entrypoint_func_uvterra_rom_400000(UvTerra_Exports *exports);

s32 D_uvterra_rom_0040F740;
static UvFMtx_Rom_Exports *sUvFMtxExports;
static UvFVec_Rom_Exports *sUvFVecExports;
static UvImtx_Rom_Exports *sUvIMtxExports;
static UvGfxState_Rom_Exports *sUvGfxStateExports;
static UvGfxMgr_Exports* sUvGfxMgrExports;
static UvModel_Exports *sUvModelExports;
static UvMath_Exports *sUvMathExports;
static UvChannel_Exports *sUvChannelExports;
static UvCback_Exports *sUvCbackExports;
static UvIntersect_Exports *sUvIntersectExports;
static UvQuery_Exports *sUvQueryExports;
static UvSort_Exports *sUvSortExports;
UnkStruct_uvterra_rom_0040F774* D_uvterra_rom_0040F774;
s32 D_uvterra_rom_0040F778;
s32 *D_uvterra_rom_0040F77C;
f32 *D_uvterra_rom_0040F780;
s32 *D_uvterra_rom_0040F784;
Vec3F *D_uvterra_rom_0040F788;
s32 *D_uvterra_rom_0040F78C;
s32 *D_uvterra_rom_0040F790;
s32 *D_uvterra_rom_0040F794;
s32 *D_uvterra_rom_0040F798;
s32 D_uvterra_rom_0040F79C; // unreferenced padding
u8 D_uvterra_rom_0040F7A0[0x404];
f32 *D_uvterra_rom_0040FBA4;
f32 D_uvterra_rom_0040FBA8;
f32 D_uvterra_rom_0040FBAC;
f32 D_uvterra_rom_0040FBB0;
f32 D_uvterra_rom_0040FBB4;
f32 D_uvterra_rom_0040FBB8;
f32 D_uvterra_rom_0040FBBC;
f32 D_uvterra_rom_0040FBC0;
s32 D_uvterra_rom_0040FBC4;
s32 D_uvterra_rom_0040FBC8;
s32 D_uvterra_rom_0040FBCC;
s32 D_uvterra_rom_0040FBD0;
s32 D_uvterra_rom_0040FBD4;
s32 sNoSobjsFlag;
s32 sNoTobjsFlag;
s32 D_uvterra_rom_0040FBE0;
s32 D_uvterra_rom_0040FBE4;
UnkStruct_uvterra_rom_0040FBE8* D_uvterra_rom_0040FBE8;
s32 D_uvterra_rom_0040FBEC;
s32 D_uvterra_rom_0040FBF0;
s32 D_uvterra_rom_0040FBF4;
s32 D_uvterra_rom_0040FBF8;
s32 D_uvterra_rom_0040FBFC;
s32 D_uvterra_rom_0040FC00;
s32 D_uvterra_rom_0040FC04;
s32 D_uvterra_rom_0040FC08[130];

// external symbols
extern UnkSobjDraw *D_8002D1A0;
extern s32 D_8002D19C;
extern Unk80225FBC_0x28 *D_8002D198;


// .data
f32 D_uvterra_rom_0040D710 = -1.0f;

#define UV_COMPUTE_LINE_MACRO(cond, arg2, arg0)                                                        \
    if ((cond)) {                                                                                      \
        *(arg2) = 0;                                                                                   \
    }                                                                                                  \
    *(arg0) = -1;


void __entrypoint_func_uvterra_rom_400000(UvTerra_Exports* exports) {
    s32 i;
    TerraSettings* settings;

    uvUpdateFileAllocPtr(exports);
    exports->func_uvterra_rom_00400640 = func_uvterra_rom_00400640;
    exports->func_uvterra_rom_004006E0 = func_uvterra_rom_004006E0;
    exports->func_uvterra_rom_00400774 = func_uvterra_rom_00400774;
    exports->_uvTerraDraw = _uvTerraDraw;
    exports->uvTerraGetPlane = uvTerraGetPlane;
    exports->func_uvterra_rom_004010B4 = func_uvterra_rom_004010B4;
    exports->uvTerraGetState = uvTerraGetState;
    exports->func_uvterra_rom_00401284 = func_uvterra_rom_00401284;
    exports->func_uvterra_rom_00401E28 = func_uvterra_rom_00401E28;
    exports->func_uvterra_rom_004005A4 = func_uvterra_rom_004005A4;
    exports->uvTerraGetColor = uvTerraGetColor;
    exports->func_uvterra_rom_00406C60 = func_uvterra_rom_00406C60;
    exports->func_uvterra_rom_0040ABE0 = func_uvterra_rom_0040ABE0;
    exports->func_uvterra_rom_004071A4 = func_uvterra_rom_004071A4;
    exports->func_uvterra_rom_0040AC14 = func_uvterra_rom_0040AC14;
    exports->func_uvterra_rom_004072BC = func_uvterra_rom_004072BC;
    exports->func_uvterra_rom_0040AC8C = func_uvterra_rom_0040AC8C;
    exports->func_uvterra_rom_004072C8 = func_uvterra_rom_004072C8;
    exports->func_uvterra_rom_0040D128 = func_uvterra_rom_0040D128;
    exports->func_uvterra_rom_004072D4 = func_uvterra_rom_004072D4;
    exports->func_uvterra_rom_004072E0 = func_uvterra_rom_004072E0;
    exports->uvSobjGetIds = uvSobjGetIds;
    exports->func_uvterra_rom_00407680 = func_uvterra_rom_00407680;
    exports->func_uvterra_rom_00407A80 = func_uvterra_rom_00407A80;
    exports->func_uvterra_rom_00401E64 = func_uvterra_rom_00401E64;
    exports->func_uvterra_rom_00402244 = func_uvterra_rom_00402244;
    exports->func_uvterra_rom_00403270 = func_uvterra_rom_00403270;
    exports->uvSobjPosm = uvSobjPosm;
    exports->func_uvterra_rom_00403464 = func_uvterra_rom_00403464;
    exports->uvSobjProps = uvSobjProps;
    exports->func_uvterra_rom_00403630 = func_uvterra_rom_00403630;
    exports->func_uvterra_rom_00408614 = func_uvterra_rom_00408614;
    exports->func_uvterra_rom_004037B8 = func_uvterra_rom_004037B8;
    exports->func_uvterra_rom_004087D8 = func_uvterra_rom_004087D8;
    exports->uvSobjGetSeg = uvSobjGetSeg;
    exports->uvSobjModel = uvSobjModel;
    exports->func_uvterra_rom_00404E14 = func_uvterra_rom_00404E14;
    exports->func_uvterra_rom_0040888C = func_uvterra_rom_0040888C;
    exports->func_uvterra_rom_004060A4 = func_uvterra_rom_004060A4;
    exports->func_uvterra_rom_00408AD8 = func_uvterra_rom_00408AD8;
    exports->func_uvterra_rom_00406160 = func_uvterra_rom_00406160;
    exports->func_uvterra_rom_00409394 = func_uvterra_rom_00409394;
    exports->func_uvterra_rom_0040AB14 = func_uvterra_rom_0040AB14;
    exports->func_uvterra_rom_0040ABB4 = func_uvterra_rom_0040ABB4;
    exports->sNoSobjsFlag = &sNoSobjsFlag;
    exports->sNoTobjsFlag = &sNoTobjsFlag;
    exports->D_uvterra_rom_0040FBE0 = &D_uvterra_rom_0040FBE0;
#ifdef __sgi
    #line 1
#endif
    D_uvterra_rom_0040FBF8 = uvProfilerCreate("TERRAGETSPHALL");
    D_uvterra_rom_0040FBFC = uvProfilerCreate("TERRAGETSPHTOBJ");
    D_uvterra_rom_0040FC00 = uvProfilerCreate("TERRAGETSPHSOBJ");
    D_uvterra_rom_0040FC04 = uvProfilerCreate("AOI");
    sUvChannelExports = uvLoadModule('CHAN');
    sUvSortExports = uvLoadModule('SORT');
    func_uvterra_rom_0040D050();
    sUvIMtxExports = uvLoadModule('IMTX');
    sUvFMtxExports = uvLoadModule('FMTX');
    sUvFVecExports = uvLoadModule('FVEC');
    sUvGfxStateExports = uvLoadModule('STAT');
    sUvGfxMgrExports = uvLoadModule('GMGR');
    sUvMathExports = uvLoadModule('MATH');
    sUvModelExports = uvLoadModule('MODL');
    sUvCbackExports = uvLoadModule('CBCK');
    sUvIntersectExports = uvLoadModule('ISCT');
    sUvQueryExports = uvLoadModule('QERY');
    settings = uvGetSystemProp(17);
    if (settings == NULL) {
        D_uvterra_rom_0040FBE4 = 0x40;
        D_uvterra_rom_0040FBEC = 0;
    } else {

    if (settings->unk0 != 0) {
        D_uvterra_rom_0040FBE4 = settings->unk0;
    } else {
        D_uvterra_rom_0040FBE4 = 0x40;
    }
    if (settings->unk4 != 0) {
        D_uvterra_rom_0040FBEC = settings->unk4;
    } else {
        D_uvterra_rom_0040FBEC = 0;
    }
    }
        
    sUvChannelExports->func_uvchannel_rom_00400288(0, 0xD, &D_uvterra_rom_0040F778, 0);
    D_uvterra_rom_0040FBE8 = _uvMemAllocAlign8(D_uvterra_rom_0040FBE4 * 0x10);
    D_uvterra_rom_0040F77C = _uvMemAllocAlign8(D_uvterra_rom_0040F778 * 4);
    D_uvterra_rom_0040FBA4 = _uvMemAllocAlign8(D_uvterra_rom_0040F778 * 4);
    for (i = 0; i < D_uvterra_rom_0040F778; i++) {
        D_uvterra_rom_0040F77C[i] = 0xFFFF;
        D_uvterra_rom_0040FBA4[i] = 1.0f;
    }
    D_uvterra_rom_0040F780 = sUvQueryExports->uvQueryGetFloatValues();
    D_uvterra_rom_0040F784 = sUvQueryExports->uvQueryGetIntValues();
    D_uvterra_rom_0040F788 = sUvQueryExports->uvQueryGetFloatVectors();
    D_uvterra_rom_0040F790 = sUvQueryExports->func_uvquery_rom_00400270();
    D_uvterra_rom_0040F78C = sUvQueryExports->func_uvquery_rom_0040027C();
    D_uvterra_rom_0040F794 = sUvQueryExports->func_uvquery_rom_00400288();
    D_uvterra_rom_0040F798 = sUvQueryExports->func_uvquery_rom_004005F8();
    func_uvterra_rom_0040C08C();
}

void func_uvterra_rom_004005A4(void) {
    uvUnloadModule('IMTX');
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('STAT');
    uvUnloadModule('GMGR');
    uvUnloadModule('MATH');
    uvUnloadModule('MODL');
    uvUnloadModule('CHAN');
    uvUnloadModule('CBCK');
    uvUnloadModule('ISCT');
    uvUnloadModule('SORT');
}

void func_uvterra_rom_00400640(s32 arg0) {
    CallbackList* callbackList;

    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 6, &callbackList, 0);
    sUvCbackExports->uvAddCallback(callbackList, _uvTerraDraw, NULL, 0x28);
    sUvCbackExports->uvAddCallback(callbackList, func_uvterra_rom_0040AC9C, NULL, 0x2D);
    sUvCbackExports->uvAddCallback(callbackList, func_uvterra_rom_0040AE4C, NULL, 0x64);
}

void func_uvterra_rom_004006E0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) || (arg1 == -1)) {
        D_uvterra_rom_0040F77C[arg0] = 0xFFFF;
    } else if (uvGetLoadedFile('UVTR', arg1) == NULL) {
        D_uvterra_rom_0040F77C[arg0] = 0xFFFF;
    } else {
        D_uvterra_rom_0040F77C[arg0] = arg1;
    }
}

s32 func_uvterra_rom_00400774(s32 arg0) {
    return D_uvterra_rom_0040F77C[arg0];
}

void _uvTerraDraw(s32 arg0) {
    s32 var_v0;
    s32 sp1A8;
    s32 sp1A4;
    s32 var_v1;
    s32 sp19C;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t5;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 x;
    f32 y;
    f32 z;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fa0;
    f32 temp_fv1;
    f32 temp_fv0;
    Vec3F sp158;
    Vec3F sp14C;
    f32 temp_fs2_2;
    f32 temp_fs3_2;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fa1;
    f32 var_ft4;
    f32 var_fv0;
    u16 temp_s0;
    u16 temp_v0_6;
    u16 var_s6;
    u16 temp_v0;
    s32 temp_t0;
    f32 sp110[5];
    f32 spFC[5];
    f32 spE8[5];
    u8 spE0[5];
    u16 spDE;
    uvUnkTileStruct *temp_fp;
    UnkStruct_uvterra_rom_0040FBE8 *temp_s0_2;
    UnkStruct_uvterra_rom_0040F774_inner *temp_v0_2;
    s16 spCE;
    s16 spCC;
    ParsedUVTR *spC8;
    s32 i;
    f32 temp_ft0;
    UnkStruct_uvterra_rom_0040F774 *spBC;
    spBC = &D_uvterra_rom_0040F774[arg0];
    D_uvterra_rom_0040F740 = 0;
    if (D_uvterra_rom_0040F77C[arg0] == 0xFFFF) {
        return;
    }
    spC8 = uvGetLoadedFile('UVTR', D_uvterra_rom_0040F77C[arg0]);
    if (spC8 == 0) {
        return;
    }
    func_uvterra_rom_0040C218(arg0);
    temp_v0_2 = func_uvterra_rom_0040C0F8(arg0);
    temp_fs2 = spC8->unk1C;
    temp_fs3 = spC8->unk20;
    var_t2 = (s32) ((temp_v0_2->unk0 - spC8->unk0.unk0) / temp_fs2);
    var_t3 = (s32) ((temp_v0_2->unkC - spC8->unk0.unk0) / temp_fs2);
    var_t4 = (s32) ((temp_v0_2->unk4 - spC8->unk0.unk4) / temp_fs3);
    var_t5 = (s32) ((temp_v0_2->unk10 - spC8->unk0.unk4) / temp_fs3);
    if (var_t2 < 0) {
        var_t2 = 0;
    }
    if ((spC8->unk18 - 1) < var_t3) {
        var_t3 = spC8->unk18 - 1;
    }
    if (var_t4 < 0) {
        var_t4 = 0;
    }
    if ((spC8->unk19 - 1) < var_t5) {
        var_t5 = spC8->unk19 - 1;
    }
    for (i = 0; i < spBC->unk48; i++) {
        temp_fv1 = spBC->unk0[i].x;
        temp_fa1 = spBC->unk0[i].y;
        if (i < (spBC->unk48 - 1)) {
            var_fv0 = spBC->unk0[i + 1].x;
            var_ft4 = spBC->unk0[i + 1].y;
        } else {
            var_fv0 = spBC->unk0[0].x;
            var_ft4 = spBC->unk0[0].y;
        }
        temp_fa0 = var_fv0 - temp_fv1;
        temp_ft0 = var_ft4 - temp_fa1;
        if (temp_fa0 == 0.0f) {
            sp110[i] = 2140143600.0f;
            spE8[i] = 0.0f;
            spFC[i] = temp_fv1;
            if (temp_ft0 > 0.0f) {
                spE0[i] = 1;
            } else {
                spE0[i] = 0;
            }
        } else {
            temp_fv0 = (var_ft4 - temp_fa1) / temp_fa0;
            if (temp_fa0 > 0.0f) {
                spE0[i] = 1;
            } else {
                spE0[i] = 0;
            }
            sp110[i] = temp_fv0;
            spE8[i] = 1.0f / temp_fv0;
            spFC[i] = temp_fa1 - (temp_fv0 * temp_fv1);
        }
    }
    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 7, &sp158, 0);
    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 8, &sp14C, 0);
    for (sp1A8 = var_t2; sp1A8 <= var_t3; sp1A8++) {
        for (sp1A4 = var_t4; sp1A4 <= var_t5; sp1A4++) {
            if ((D_uvterra_rom_0040FBEC != 0) && (sp14C.x > 0.0f) ^ (D_uvterra_rom_0040FBEC == 2)) {
                var_v1 = (var_t3 - sp1A8) + var_t2;
            } else {
                var_v1 = sp1A8;
            }
            if ((D_uvterra_rom_0040FBEC != 0) && (sp14C.y > 0.0f) ^ (D_uvterra_rom_0040FBEC == 2)) {
                var_v0 = (var_t5 - sp1A4) + var_t4;
            } else {
                var_v0 = sp1A4;
            }
            sp19C = (spC8->unk18 * var_v0) + var_v1;
            temp_fp = spC8->unk28 + sp19C;
            if (temp_fp == 0) {
                continue;
            }
            if (temp_fp->unk40 == 0) {
                continue;
            }
            x = (temp_fp->unk0.m[3][0] + temp_fp->unk40->unk18);
            y = (temp_fp->unk0.m[3][1] + temp_fp->unk40->unk1C);
            z = (temp_fp->unk0.m[3][2] + temp_fp->unk40->unk20);
            if (!sUvChannelExports->func_uvchannel_rom_004014E8(arg0, x - sp158.x, y - sp158.y, z - sp158.z,
                                               temp_fp->unk40->unk24)) {
                continue;
            }
            temp_fs0 = 15.0f / temp_fs2;
            temp_fs1 = 15.0f / temp_fs3;
            temp_fs2_2 = temp_fp->unk0.m[3][0] - (0.5f * temp_fs2);
            temp_fs3_2 = temp_fp->unk0.m[3][0] + (0.5f * temp_fs2);
            temp_fs4 = temp_fp->unk0.m[3][1] + (0.5f * temp_fs3);
            temp_fs5 = temp_fp->unk0.m[3][1] - (0.5f * temp_fs3);
            var_s6 = 0;
            spDE = 0xFFFF;
            for (i = 0; i < spBC->unk48; i++) {
                uvComputeLineEndP(&spCE, &spCC, &spDE, temp_fs2_2, temp_fs3_2, temp_fs4,
                                          temp_fs5, spFC[i], sp110[i], spE8[i], (s32) spE0[i], temp_fs0,
                                          temp_fs1);
                if (spCE >= 0) {
                    temp_s0 = func_uvterra_rom_0040B0C4(spCE, spCC, 0);
                    temp_v0_6 = func_uvterra_rom_0040B0C4(spCE, spCC, 1);
                    var_s6 |= temp_s0 & temp_v0_6;
                    if (spE0[i] != 0) {
                        spDE &= temp_v0_6;
                    } else {
                        spDE &= temp_s0;
                    }
                }
                if (spDE == 0) {
                    break;
                }
            }
            temp_v0 = spDE & ~var_s6;
            if (spDE) {
                temp_s0_2 = &D_uvterra_rom_0040FBE8[D_uvterra_rom_0040F740];
                temp_s0_2->unk0 = temp_fp;
                temp_s0_2->unk6 = spDE;
                temp_s0_2->unk4 = temp_v0;
                temp_s0_2->unkC = sp19C;
                temp_s0_2->unk8 = sUvMathExports->uvSqrtf(
                    SQ(sp158.x - temp_fp->unk0.m[3][0])
                    + SQ(sp158.y - temp_fp->unk0.m[3][1]) + SQ(sp158.z - temp_fp->unk0.m[3][2]) );
                D_uvterra_rom_0040F740++;
            }
        }
    }
}

void uvTerraGetPlane(s32 arg0, u32 arg1, f32 arg2, f32 arg3, f32 *arg4, Vec3F *arg5) {
    f32 temp_ft5;
    uvUnkTileStruct *sp60;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28_UnkC *sp58;
    Vtx *sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    s16 sp46;
    s16 sp44;
    Unk80225FBC_0x28 *v1;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;

    if (arg1 == -1) {
        return;
    }

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return;
    }

    sp60 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    v1 = &sp60->unk40->unk8[(arg1 >> 0xC) & 0x3FF];
    sp58 = &v1->unk18[arg1 & 0xFFF];
    sp54 = sp60->unk40->vtxTable;

    func_uvterra_rom_0040B8C0(temp_v0, arg2, arg3, 0.0f, &sp50, &sp4C, &sp48, &sp46, &sp44, 0U);
    sp50 *= sp60->unk40->unk2C;
    sp4C *= sp60->unk40->unk2C;
    sp48 *= sp60->unk40->unk30;
    temp_fv0 = (sp60->unk40->unk2C / sp60->unk40->unk30);
    if (sUvIntersectExports->_uvSurfGetNorm(sp54, sp58->unk0, sp58->unk2, sp58->unk4,
                                                              arg5, temp_fv0)
        == 0) {
        arg5->x = 0.0f;
        arg5->y = 0.0f;
        arg5->z = 1.0f;
    }

    temp_ft5 = sp54[sp58->unk0].v.ob[0];
    temp_fa0 = sp54[sp58->unk0].v.ob[1];
    temp_fa1 = sp54[sp58->unk0].v.ob[2];
    if (arg5->z != 0.0f) {
        *arg4 = (((arg5->x * (temp_ft5 - sp50)) + (arg5->y * (temp_fa0 - sp4C))) / (arg5->z * temp_fv0))
                + temp_fa1;
        *arg4 /= sp60->unk40->unk30;
        *arg4 += sp60->unk0.m[3][2];
    }
}

void func_uvterra_rom_004010B4(s32 arg0, u32 arg1, Vec3F *arg2) {
    ParsedUVCT *temp_v0_2;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28 *t;
    uvUnkTileStruct *t2;
    Unk80225FBC_0x28_UnkC *temp_v1;

    if (arg1 == -1U) {
        return;
    }

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return;
    }

    t2 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    temp_v0_2 = t2->unk40;
    t = &temp_v0_2->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v1 = &t->unk18[arg1 & 0xFFF];

    if (sUvIntersectExports->_uvSurfGetNorm(temp_v0_2->vtxTable, temp_v1->unk0,
                                                              temp_v1->unk2, temp_v1->unk4, arg2,
                                                              temp_v0_2->unk2C / temp_v0_2->unk30)
        == 0) {
        arg2->x = 0.0f;
        arg2->y = 0.0f;
        arg2->z = 0.0f;
    }
}

s32 uvTerraGetState(s32 arg0, u32 arg1) {
    ParsedUVCT *temp_a1;
    ParsedUVTR *temp_v0;
    s32 temp_t6;
    uvUnkTileStruct *temp_a0;
    Unk80225FBC_0x28 *t;

    if (arg1 == -1U) {
        return 0xFFF;
    }
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return 0xFFF;
    }
    temp_t6 = (arg1 >> 0x16) & 0x3FF;
    if (temp_t6 >= (temp_v0->unk18 * temp_v0->unk19)) {
        return 0xFFF;
    }
    temp_a0 = &temp_v0->unk28[temp_t6];
    if (temp_a0 == NULL) {
        return 0xFFF;
    }
    temp_a1 = temp_a0->unk40;
    if (temp_a1 == NULL) {
        return 0xFFF;
    }
    t = &temp_a1->unk8[(arg1 >> 0xC) & 0x3FF];
    return t->unk0.state;
}

s32 func_uvterra_rom_00401284(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32* arg5, s32* arg6, s32* arg7) {
    s32 sp16C;
    s32 sp168;
    s32 sp164;
    s32 sp160;
    f32 temp_fs0;
    s32 sp158;
    s32 sp154;
    s32 sp150;
    s32 sp14C;
    s32 sp148;
    f32 temp_fs1;
    s32 sp140;
    f32 temp_fs3;
    ParsedUVTR* sp138;
    f32 temp_fs4;
    ParsedUVCT* sp130;
    Unk80225FBC_0x28* sp12C;
    s32 var_v1;
    s32 temp_v0_4;
    uvUnkTileStruct* temp_s7;
    Unk80225FBC_0x28_UnkC* temp_v1_2;
    query_78* temp_v1_3;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    s32 var_fp;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 temp_fs5;
    f32 spF0;
    Vtx* temp_s3;
    Vtx* temp_s4;
    f32 spE4;
    f32 spE0;
    Vtx* temp_s5;
    f32 spC8;
    u16 spBC;

    sp140 = 0;
    sp138 = uvGetLoadedFile('UVTR', arg0);
    if (sp138 == NULL) {
        return 0;
    }
    if ((arg1 + arg4) < sp138->unk0.unk0) {
        return 0;
    }
    if (sp138->unk0.unkC < (arg1 - arg4)) {
        return 0;
    }
    if ((arg2 + arg4) < sp138->unk0.unk4) {
        return 0;
    }
    if (sp138->unk0.unk10 < (arg2 - arg4)) {
        return 0;
    }
    sp158 = ((arg1 - arg4) - sp138->unk0.unk0) / sp138->unk1C;
    sp154 = ((arg1 + arg4) - sp138->unk0.unk0) / sp138->unk1C;
    sp150 = ((arg2 - arg4) - sp138->unk0.unk4) / sp138->unk20;
    sp14C = ((arg2 + arg4) - sp138->unk0.unk4) / sp138->unk20;
    if (sp158 < 0) {
        sp158 = 0;
    }
    if ((sp138->unk18 - 1) < sp154) {
        sp154 = sp138->unk18 - 1;
    }

    if (sp150 < 0) {
        sp150 = 0;
    }

    if ((sp138->unk19 - 1) < sp14C) {
        sp14C = sp138->unk19 - 1;
    }

    var_fp = 0;
    sp114 = sp138->unk0.unk0;
    sp110 = sp138->unk1C + sp114;
    for (sp16C = sp158; sp154 >= sp16C; sp16C++) {
        sp108 = sp138->unk0.unk4;
        sp10C = sp138->unk20 + sp108;
        for (sp168 = sp150; sp14C >= sp168; sp168++) {
            sp148 = (sp138->unk18 * sp168) + sp16C;
            temp_s7 = &sp138->unk28[sp148];
            if (temp_s7 == NULL) {
                continue;
            }
            sp130 = temp_s7->unk40;
            if (sp130 == NULL) {
                continue;
            }
            spC8 = arg3 - arg4;
            if ((temp_s7->unk48 < spC8)) {
                continue;
            }
            temp_fs3 = sp130->unk2C * arg4;
            spF0 = sp130->unk30 * arg4;
            sp100 = arg1 - temp_s7->unk0.m[3][0];
            spFC = arg2 - temp_s7->unk0.m[3][1];
            spF8 = arg3 - temp_s7->unk0.m[3][2];
            spBC = func_uvterra_rom_0040BBC0(sp100, spFC, arg4, sp114, sp110, sp108, sp10C);
            temp_fs4 = sp130->unk2C * sp100;
            temp_fs5 = sp130->unk2C * spFC;
            spE4 = sp130->unk30 * spF8;
            spE0 = sp130->unk2C / sp130->unk30;
            for (sp164 = 0; sp164 < sp130->unkC; sp164++) {
                sp12C = sp130->unk8 + sp164;
                if (!(sp12C->unk1E & spBC) || ((temp_s7->unk0.m[3][2] + sp12C->unk34) < spC8) || !((SQ(sp12C->unk30 + arg4) >= SQ(sp100 - sp12C->unk24) + SQ(spFC - sp12C->unk28) + SQ(spF8 - sp12C->unk2C)))) {
                    continue;
                }

                for (sp160 = 0; sp160 < sp12C->unk1C; sp160++) {
                    temp_v1_2 = &sp12C->unk18[sp160];
                    if (temp_v1_2->unk6 & spBC) {
                        temp_s3 = &sp130->vtxTable[temp_v1_2->unk0];
                        temp_s4 = &sp130->vtxTable[temp_v1_2->unk2];
                        temp_s5 = &sp130->vtxTable[temp_v1_2->unk4];

                        var_v1 = MIN(MIN(temp_s3->v.ob[0], temp_s4->v.ob[0]), temp_s5->v.ob[0]);
                        if (temp_fs3 < (var_v1 - temp_fs4)) {
                            continue;
                        }

                        var_v1 = MAX(MAX(temp_s3->v.ob[0], temp_s4->v.ob[0]), temp_s5->v.ob[0]);
                        if (temp_fs3 < (temp_fs4 - var_v1)) {
                            continue;
                        }

                        var_v1 = MIN(MIN(temp_s3->v.ob[1], temp_s4->v.ob[1]), temp_s5->v.ob[1]);
                        if (temp_fs3 < (var_v1 - temp_fs5)) {
                            continue;
                        }

                        var_v1 = MAX(MAX(temp_s3->v.ob[1], temp_s4->v.ob[1]), temp_s5->v.ob[1]);
                        if (temp_fs3 < (temp_fs5 - var_v1)) {
                            continue;
                        }

                        var_v1 = MIN(MIN(temp_s3->v.ob[2], temp_s4->v.ob[2]), temp_s5->v.ob[2]);
                        if (spF0 < (var_v1 - spE4)) {
                            continue;
                        }

                        var_v1 = MAX(MAX(temp_s3->v.ob[2], temp_s4->v.ob[2]), temp_s5->v.ob[2]);
                        if (spF0 < (spE4 - var_v1)) {
                            continue;
                        }

                        if (var_fp >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            break;
                        }

                        temp_v0_4 = sUvIntersectExports->func_uvintersect_rom_0040093C(
                            temp_fs4, temp_fs5, spE4, temp_fs3, spE0,
                            temp_s3->v.ob[0], temp_s3->v.ob[1], temp_s3->v.ob[2],
                            temp_s4->v.ob[0], temp_s4->v.ob[1], temp_s4->v.ob[2],
                            temp_s5->v.ob[0], temp_s5->v.ob[1], temp_s5->v.ob[2],
                            &D_uvterra_rom_0040F788[var_fp], &D_uvterra_rom_0040F780[var_fp]
                        );
                        if (temp_v0_4 == 0) {
                        } else {
                            if (temp_v0_4 == 1) {
                                D_uvterra_rom_0040F794[var_fp] |= 1;
                            } else {
                                D_uvterra_rom_0040F794[var_fp] &= ~1;
                            }
                            if (sp140 == 0) {
                                sUvQueryExports->uvQueryGetProps(0, 1, &sp140, 0);
                            }
                            if (sp140 != 0) {
                                temp_fs0 = 1.0f / sp130->unk2C;
                                temp_fs1 = 1.0f / sp130->unk30;
                                temp_v1_3 = sUvQueryExports->func_uvquery_rom_004004CC();
                                temp_v1_3[var_fp].unk0.x = (temp_fs0 * temp_s3->v.ob[0]) + temp_s7->unk0.m[3][0];
                                temp_v1_3[var_fp].unk0.y = (temp_fs0 * temp_s3->v.ob[1]) + temp_s7->unk0.m[3][1];
                                temp_v1_3[var_fp].unk0.z = (temp_fs1 * temp_s3->v.ob[2]) + temp_s7->unk0.m[3][2];
                                temp_v1_3[var_fp].unkC.x = (temp_fs0 * temp_s4->v.ob[0]) + temp_s7->unk0.m[3][0];
                                temp_v1_3[var_fp].unkC.y = (temp_fs0 * temp_s4->v.ob[1]) + temp_s7->unk0.m[3][1];
                                temp_v1_3[var_fp].unkC.z = (temp_fs1 * temp_s4->v.ob[2]) + temp_s7->unk0.m[3][2];
                                temp_v1_3[var_fp].unk18.x = (temp_fs0 * temp_s5->v.ob[0]) + temp_s7->unk0.m[3][0];
                                temp_v1_3[var_fp].unk18.y = (temp_fs0 * temp_s5->v.ob[1]) + temp_s7->unk0.m[3][1];
                                temp_v1_3[var_fp].unk18.z = (temp_fs1 * temp_s5->v.ob[2]) + temp_s7->unk0.m[3][2];
                                temp_v1_3[var_fp].unk24 = D_uvterra_rom_0040F788[var_fp];
                                temp_v1_3[var_fp].unk70 |= 1;
                                temp_v1_3[var_fp].unk74 = sp12C->unk0.state;
                            }
                            D_uvterra_rom_0040F780[var_fp] /= -arg4 * sp130->unk2C;

                            // 10 bits of sp148, 10 bits of sp164 and 12 bits of sp160 = 32 bits total
                            D_uvterra_rom_0040F784[var_fp] = ((sp148 & 0x3FF) << 0x16) + ((sp164 & 0x3FF) << 0xC) + (sp160 & 0xFFF);
                            var_fp++;
                        }
                    }
                }
            }

            if (sp14C >= sp168) {
                sp108 += sp138->unk20;
                sp10C += sp138->unk20;
            }
        }

        if (sp154 >= sp16C) {
            sp114 += sp138->unk1C;
            sp110 += sp138->unk20;
        }
    }
    *arg5 = D_uvterra_rom_0040F784;
    *arg6 = D_uvterra_rom_0040F780;
    *arg7 = D_uvterra_rom_0040F788;
    return var_fp;
}

void *func_uvterra_rom_00401E28(s32 arg0) {
    void *temp_v0;

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    return temp_v0;
}

u32 func_uvterra_rom_00401E64(s32 arg0, f32 arg1, f32 arg2, s32 **arg3) {
    f32 spC4;
    f32 spC0;
    f32 spBC;
    ParsedUVCT *temp_s4;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28 *temp_s1;
    Unk80225FBC_0x28_UnkC *temp_v1;
    Vtx *temp_a0;
    u16 spA6;
    Vtx *temp_a1;
    u16 sp9E;
    Vtx *temp_a2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    uvUnkTileStruct *v0;
    u16 j;
    u16 i;
    u32 var_s2;

    var_s2 = 0;
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (func_uvterra_rom_0040B8C0(temp_v0, arg1, arg2, 0.0f, &spC4, &spC0, &spBC, &sp9E, (s16 *) &spA6,
                                  0)
        == 0) {
        *arg3 = NULL;
        return 0U;
    }
    v0 = &temp_v0->unk28[sp9E];
    temp_s4 = v0->unk40;
    if (temp_s4 == NULL) {
        *arg3 = NULL;
        return 0U;
    }
    spC4 *= temp_s4->unk2C;
    spC0 *= temp_s4->unk2C;
    spBC *= temp_s4->unk30;
    for (i = 0; i < temp_s4->unkC; i++) {
        temp_s1 = &temp_s4->unk8[i];
        if (!(temp_s1->unk1E & spA6)) {
            continue;
        }

        for (j = 0; j < temp_s1->unk1C; j++) {
            temp_v1 = &temp_s1->unk18[j];
            if (!(temp_v1->unk6 & spA6)) {
                continue;
            }
            temp_a0 = (Vtx *) temp_s4->vtxTable + temp_v1->unk0;
            temp_ft5 = temp_a0->v.ob[0];
            temp_a1 = (Vtx *) temp_s4->vtxTable + temp_v1->unk2;
            temp_fs0 = temp_a1->v.ob[0];
            temp_a2 = (Vtx *) temp_s4->vtxTable + temp_v1->unk4;
            temp_fs1 = temp_a2->v.ob[0];

            if (((temp_ft5 < spC4)) && (temp_fs0 < spC4) && (temp_fs1 < spC4)) {
                continue;
            }

            if (((spC4 < temp_ft5) && (spC4 < temp_fs0) && (spC4 < temp_fs1))) {
                continue;
            }

            temp_fv0 = temp_a0->v.ob[1];
            temp_fv1 = temp_a1->v.ob[1];
            temp_ft4 = temp_a2->v.ob[1];

            if (((temp_fv0 < spC0)) && (temp_fv1 < spC0) && (temp_ft4 < spC0)) {
                continue;
            }

            if (((spC0 < temp_fv0) && (spC0 < temp_fv1) && (spC0 < temp_ft4))) {
                continue;
            }

            if (sUvIntersectExports->func_uvintersect_rom_00400E60(
                    spC4, spC0, temp_ft5, temp_fv0, temp_fs0, temp_fv1, temp_fs1, temp_ft4, 1.0f)
                == 0) {
                continue;
            }
            D_uvterra_rom_0040F784[var_s2++] = (sp9E << 12 << 10) + ((i & 0x3FF) << 0xC) + (j & 0xFFF);
            if (var_s2 >= sUvQueryExports->func_uvquery_rom_00400224()) {
                break;
            }
        }
    }
    *arg3 = D_uvterra_rom_0040F784;
    return var_s2;
}

s32 func_uvterra_rom_00402244(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              s32 **arg7, f32 **arg8) {
    ParsedUVTR *uvtr;
    uvUnkTileStruct *temp_s1;
    ParsedUVCT *uvct;
    Unk80225FBC_0x28 *temp_s1_2;
    Unk80225FBC_0x28_UnkC *temp_v0_2;
    Vtx *vtx1;
    Vtx *vtx2;
    Vtx *vtx3;
    Vec3F sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    u16 sp1AA;
    u16 sp1A8;
    u16 sp1A6;
    u16 sp1A4;
    u16 var_s0;
    u8 var_s3;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_ft4;
    s32 sp190;
    s32 sp18C;
    f32 var_ft5;
    s32 temp_s5;
    s32 var_v0;
    s32 var_v1;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_fs0;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp11C;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    f32 temp_fv0;
    f32 temp_fv1;
    u8 sp103;
    u8 sp102;
    u8 temp_s0;
    u8 temp_t3;

    var_s3 = 0;
    if ((arg1 == arg4) && (arg2 == arg5) && (arg3 == arg6)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        return 0;
    }

    sp178 = uvtr->unk1C;
    sp174 = uvtr->unk20;
    sp14C = arg1;
    sp148 = arg2;
    sp144 = arg4;
    sp140 = arg5;
    temp_fs2 = arg4 - arg1;
    temp_fs3 = arg5 - arg2;
    temp_fs0 = arg6 - arg3;
    sUvIntersectExports->func_uvintersect_rom_00401A2C(&arg1, &arg2, &arg4, &arg5, uvtr->unk0.unk0,
                                                          uvtr->unk0.unkC, uvtr->unk0.unk4,
                                                          uvtr->unk0.unk10);
    if (arg1 == uvtr->unk0.unkC) {
        arg1 -= 0.0001f * sp178;
    }
    if (arg4 == uvtr->unk0.unkC) {
        arg4 -= 0.0001f * sp178;
    }
    if (arg2 == uvtr->unk0.unk10) {
        arg2 -= 0.0001f * sp174;
    }
    if (arg5 == uvtr->unk0.unk10) {
        arg5 -= 0.0001f * sp174;
    }

    if ((sp14C != arg1) && (temp_fs2 != 0.0f)) {
        arg3 += temp_fs0 * ((arg1 - sp14C) / temp_fs2);
    } else if ((sp148 != arg2) && (temp_fs3 != 0.0f)) {
        arg3 += temp_fs0 * ((arg2 - sp148) / temp_fs3);
    }
    if ((sp144 != arg4) && (temp_fs2 != 0.0f)) {
        arg6 += temp_fs0 * ((arg4 - sp144) / temp_fs2);
    } else if ((sp140 != arg5) && (temp_fs3 != 0.0f)) {
        arg6 += temp_fs0 * ((arg5 - sp140) / temp_fs3);
    }
    temp1 = arg4 - arg1;
    temp2 = arg5 - arg2;
    temp3 = arg6 - arg3;
    if ((temp1 == 0.0f) && (temp2 == 0.0f) && (temp3 == 0.0f)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    temp_s0 =
        func_uvterra_rom_0040B8C0(uvtr, arg1, arg2, arg3, &sp1C0, &sp1BC, &sp1B8, &sp1AA, &sp1A6, 0);
    temp_t3 =
        func_uvterra_rom_0040B8C0(uvtr, arg4, arg5, arg6, &sp1B4, &sp1B0, &sp1AC, &sp1A8, &sp1A4, 0);
    if ((temp_s0 == 0) && (temp_t3 == 0)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    sp103 = FALSE;
    sp102 = FALSE;
    if (sp1AA == sp1A8) {
        sp103 = TRUE;
        if (sp1A6 == sp1A4) {
            sp102 = TRUE;
        }
    }
    if (sp103) {
        var_v1 = var_v0 = (s32) ((arg1 - uvtr->unk0.unk0) / sp178);
        sp190 = sp18C = (s32) ((arg2 - uvtr->unk0.unk4) / sp174);
    } else {
        if (arg4 < arg1) {
            var_ft4 = arg4;
            var_ft5 = arg1;
        } else {
            var_ft4 = arg1;
            var_ft5 = arg4;
        }
        if (arg5 < arg2) {
            var_fa0 = arg5;
            var_fa1 = arg2;
        } else {
            var_fa1 = arg5;
            var_fa0 = arg2;
        }

        var_v1 = (s32) ((var_ft4 - uvtr->unk0.unk0) / sp178);
        var_v0 = (s32) ((var_ft5 - uvtr->unk0.unk0) / sp178);
        sp190 = (s32) ((var_fa0 - uvtr->unk0.unk4) / sp174);
        sp18C = (s32) ((var_fa1 - uvtr->unk0.unk4) / sp174);
        if (var_v1 < 0) {
            var_v1 = 0;
        }

        if (var_v0 >= uvtr->unk18) {
            var_v0 = uvtr->unk18 - 1;
        }
        if (sp190 < 0) {
            sp190 = 0;
        }

        if (sp18C >= uvtr->unk19) {
            sp18C = uvtr->unk19 - 1;
        }
    }

    if (arg3 < arg6) {
        sp11C = arg3;
    } else {
        sp11C = arg6;
    }

    for (i = var_v1; i <= var_v0; i++) {
        for (j = sp190; j <= sp18C; j++) {
            temp_s5 = (uvtr->unk18 * j) + i;
            temp_s1 = &uvtr->unk28[temp_s5];
            if (temp_s1 == NULL) {
                continue;
            }
            if (temp_s1->unk48 < sp11C) {
                continue;
            }
            uvct = temp_s1->unk40;
            if (uvct != NULL) {
                sp15C = arg1;
                sp154 = arg2;
                sp158 = arg4;
                sp150 = arg5;
                sp13C = arg3 - temp_s1->unk0.m[3][2];
                sp138 = arg6 - temp_s1->unk0.m[3][2];

                sp16C = temp_s1->unk0.m[3][0] - (0.5f * sp178);
                sp168 = temp_s1->unk0.m[3][0] + (0.5f * sp178);
                sp160 = temp_s1->unk0.m[3][1] + (0.5f * sp174);
                sp164 = temp_s1->unk0.m[3][1] - (0.5f * sp174);
                if (sUvIntersectExports->func_uvintersect_rom_0040191C(arg1, arg2, arg4, arg5, sp16C,
                                                                          sp168, sp164, sp160)
                    == 0) {
                    continue;
                }
                if (!sp103) {
                    sUvIntersectExports->func_uvintersect_rom_00401CB0(
                        &sp15C, &sp154, &sp13C, &sp158, &sp150, &sp138, sp16C, sp168, sp164, sp160);
                    if ((sp15C == sp158) && (sp154 == sp150) && (sp13C == sp138)) {
                        continue;
                    }
                    var_s0 = 0;
                    if (sp15C == sp168) {
                        var_s0 |= 1;
                    }
                    if (sp154 == sp160) {
                        var_s0 |= 2;
                    }
                    func_uvterra_rom_0040B8C0(uvtr, sp15C, sp154, sp13C, &sp1C0, &sp1BC, &sp1B8, &sp1AA,
                                              &sp1A6, var_s0);
                    var_s0 = 0;
                    if (sp158 == sp168) {
                        var_s0 |= 1;
                    }
                    if (sp150 == sp160) {
                        var_s0 |= 2;
                    }
                    func_uvterra_rom_0040B8C0(uvtr, sp158, sp150, sp138, &sp1B4, &sp1B0, &sp1AC, &sp1A8,
                                              &sp1A4, var_s0);
                    if (sp1A6 != sp1A4) {
                        sp1A4 =
                            func_uvterra_rom_0040BD38(sp15C, sp154, sp158, sp150, sp1C0, sp1BC, sp1B4,
                                                      sp1B0, sp16C, sp168, sp160, sp164, temp_s1);
                    }
                }

                if (!sp102) {
                    sp1A4 = func_uvterra_rom_0040BD38(sp15C, sp154, sp158, sp150, sp1C0, sp1BC, sp1B4,
                                                      sp1B0, sp16C, sp168, sp160, sp164, temp_s1);
                }
                if (sp1A4 == 0) {
                    continue;
                }

                sp1C0 *= uvct->unk2C;
                sp1B4 *= uvct->unk2C;
                sp1BC *= uvct->unk2C;
                sp1B0 *= uvct->unk2C;
                sp1B8 *= uvct->unk30;
                sp1AC *= uvct->unk30;
                for (k = 0; k < uvct->unkC; k++) {
                    temp_s1_2 = &uvct->unk8[k];
                    if (!(temp_s1_2->unk1E & sp1A4)) {
                        continue;
                    }

                    if (temp_s1_2->unk34 + temp_s1->unk0.m[3][2] < sp11C) {
                        continue;
                    }

                    for (l = 0; l < temp_s1_2->unk1C; l++) {
                        temp_v0_2 = &temp_s1_2->unk18[l];
                        if (!(temp_v0_2->unk6 & sp1A4)) {
                            continue;
                        }

                        vtx1 = &uvct->vtxTable[temp_v0_2->unk0];
                        vtx2 = &uvct->vtxTable[temp_v0_2->unk2];
                        vtx3 = &uvct->vtxTable[temp_v0_2->unk4];

                        // clang-format on
                        if (MIN(MIN(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) > MAX(sp1C0, sp1B4)) { continue; } \
                        if (MAX(MAX(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) < MIN(sp1C0, sp1B4)) { continue; } \
                        if (MIN(MIN(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) > MAX(sp1BC, sp1B0)) { continue; } \
                        if (MAX(MAX(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) < MIN(sp1BC, sp1B0)) { continue; } \
                        if (MIN(MIN(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) > MAX(sp1B8, sp1AC)) { continue; } \
                        if (MAX(MAX(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) < MIN(sp1B8, sp1AC)) { continue; }
                        // clang-format off

                        if (sUvIntersectExports->func_uvintersect_rom_00401318(
                                sp1C0, sp1BC, sp1B8, sp1B4, sp1B0, sp1AC, vtx1->v.ob[0], vtx1->v.ob[1],
                                vtx1->v.ob[2], vtx2->v.ob[0], vtx2->v.ob[1], vtx2->v.ob[2],
                                vtx3->v.ob[0], vtx3->v.ob[1], vtx3->v.ob[2], 1.0f, 1.0f, &sp170, &sp1C4)
                            == 0) {
                            continue;
                        }
                        if (var_s0 != 0) {
                            if (temp_fs2 != 0.0f) {
                                sp170 = (((sp158 - sp15C) / temp_fs2) * sp170)
                                        + ((sp15C - sp14C) / temp_fs2);
                            } else if (temp_fs3 != 0.0f) {
                                sp170 = (((sp150 - sp154) / temp_fs3) * sp170)
                                        + ((sp154 - sp148) / temp_fs3);
                            }
                        }

                        if (sp170 < 0.0f) {
                            sp170 = 0.0f;
                        } else if (sp170 > 1.0f) {
                            sp170 = 1.0f;
                        }
                        if (var_s3 >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            break;
                        }
                        D_uvterra_rom_0040F784[var_s3] =
                            ((temp_s5 & 0x3FF) << 22) + ((k & 0x3FF) << 12) + (l & 0xFFF);
                        D_uvterra_rom_0040F780[var_s3] = sp170;
                        sUvFVecExports->uvVec3FCopy(&D_uvterra_rom_0040F788[var_s3], &sp1C4);
                        var_s3++;
                    }
                }
            }
        }
    }
    *arg7 = D_uvterra_rom_0040F784;
    *arg8 = D_uvterra_rom_0040F780;
    return var_s3;
}

void func_uvterra_rom_00403270(s32 arg0, u32 arg1, s8 *arg2, s8 *arg3, s8 *arg4) {
    ParsedUVCT *temp_a0;
    ParsedUVTR *uvtr;
    Unk80225FBC_0x28 *a1;
    Unk80225FBC_0x28_UnkC *temp_v0_2;
    Vtx *vtx;
    uvUnkTileStruct *temp_v1;

    if (arg1 == -1U) {
        return;
    }

    uvtr = uvGetLoadedFile('UVTR', arg0);
    if (uvtr == NULL) {
        return;
    }

    temp_v1 = &uvtr->unk28[(arg1 >> 0x16) & 0x3FF];
    if (temp_v1 == NULL) {
        return;
    }

    temp_a0 = temp_v1->unk40;
    if (temp_a0 == NULL) {
        return;
    }

    a1 = &temp_a0->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v0_2 = &a1->unk18[arg1 & 0xFFF];
    vtx = temp_a0->vtxTable;
    *arg2 = (vtx[temp_v0_2->unk0].v.cn[0] + vtx[temp_v0_2->unk2].v.cn[0] + vtx[temp_v0_2->unk4].v.cn[0])
            / 3;
    *arg3 = (vtx[temp_v0_2->unk0].v.cn[1] + vtx[temp_v0_2->unk2].v.cn[1] + vtx[temp_v0_2->unk4].v.cn[1])
            / 3;
    *arg4 = (vtx[temp_v0_2->unk0].v.cn[2] + vtx[temp_v0_2->unk2].v.cn[2] + vtx[temp_v0_2->unk4].v.cn[2])
            / 3;
}

void func_uvterra_rom_00403464(s32 arg0, u32 arg1, Vec3F *arg2, Vec3F *arg3, Vec3F *arg4) {
    ParsedUVCT *temp_a1;
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28_UnkC *temp_v1;
    uvUnkTileStruct *a2;
    Unk80225FBC_0x28 *a3;
    Vtx *temp_a0;
    Unk80225FBC_0x28_UnkC *tmp;

    if (arg1 == -1U) {
        return;
    }

    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return;
    }

    a2 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    temp_a1 = a2->unk40;
    a3 = &temp_a1->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v1 = &a3->unk18[arg1 & 0xFFF];
    temp_a0 = temp_a1->vtxTable;
    arg2->x = temp_a0[temp_v1->unk0].v.ob[0];
    arg2->y = temp_a0[temp_v1->unk0].v.ob[1];
    tmp = temp_v1;
    arg2->z = temp_a0[tmp->unk0].v.ob[2];
    arg3->x = temp_a0[tmp->unk2].v.ob[0];
    arg3->y = temp_a0[tmp->unk2].v.ob[1];
    arg3->z = temp_a0[tmp->unk2].v.ob[2];
    arg4->x = temp_a0[tmp->unk4].v.ob[0];
    arg4->y = temp_a0[tmp->unk4].v.ob[1];
    arg4->z = temp_a0[tmp->unk4].v.ob[2];
}

s32 func_uvterra_rom_00403630(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4) {
    ParsedUVTR *temp_v0;
    s32 temp_a2;
    s32 temp_lo;
    s32 temp_lo_2;

    *arg3 = arg1;
    *arg4 = arg2;
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_lo = (s32) (arg1 - temp_v0->unk0.unk0) / (s32) temp_v0->unk1C;
    temp_lo_2 = (s32) (arg2 - temp_v0->unk0.unk4) / (s32) temp_v0->unk20;
    if ((temp_lo >= (s32) temp_v0->unk18) || (temp_lo < 0) || (temp_lo_2 >= (s32) temp_v0->unk19)
        || (temp_lo_2 < 0)) {
        *arg3 = arg1;
        *arg4 = arg2;
        return 0;
    }
    temp_a2 = (temp_v0->unk18 * temp_lo_2) + temp_lo;
    *arg3 = temp_v0->unk28[temp_a2].unk0.m[3][0];
    *arg4 = temp_v0->unk28[temp_a2].unk0.m[3][1];
    return 1;
}

s32 func_uvterra_rom_004037B8(s32 arg0, u32 arg1, f32 *arg2, f32 *arg3) {
    ParsedUVTR *uvtr;

    *arg2 = 0.0f;
    *arg3 = 0.0f;
    uvtr = uvGetLoadedFile('UVTR', arg0);
    if (uvtr == NULL) {
        return FALSE;
    }
    *arg2 = uvtr->unk28[(arg1 >> 0x16) & 0x3FF].unk0.m[3][0];
    *arg3 = uvtr->unk28[(arg1 >> 0x16) & 0x3FF].unk0.m[3][1];
    return TRUE;
}

s32 uvSobjGetSeg(s32 terraId, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              f32 arg7, s32 **arg8, f32 **arg9, Vec3F **arg10, s32 **arg11) {
    ParsedUVTR *uvtr;
    uvUnkTileStruct *temp_s1;
    ParsedUVCT *uvct;
    Unk80225FBC_0x28 *temp_s1_2;
    Unk80225FBC_0x28_UnkC *temp_v0_2;
    struct UnkSobjDraw *sobj;
    Vtx *vtx1;
    Vtx *vtx2;
    Vtx *vtx3;
    f32 temp_fs0;
    Vec3F sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    u16 sp1BA;
    u16 sp1B8;
    u16 sp1B6;
    u16 sp1B4;
    u16 var_s0;
    f32 var_fa0;
    f32 var_fa1;
    s32 sp1A4;
    s32 sp1A0;
    f32 var_ft4;
    f32 var_ft5;
    f32 temp_fv0;
    s32 var_v0;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    s32 var_v1;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp130;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    f32 temp_fv1;
    s32 sp118;
    s32 temp_t0;
    ParsedUVMD *temp_v0_4;
    u8 sp10F;
    u8 sp10E;
    u8 temp_s0;
    u8 temp_t3;
    f32 ft4;
    f32 ft5;
    f32 fs2;
    f32 fv1;


    *D_uvterra_rom_0040F790 = 0;
    if ((arg2 == arg5) && (arg3 == arg6) && (arg4 == arg7)) {
        if (arg1 & 2) {
            if (arg7 != 0.0f) {
                arg7 *= 1.0001f;
            } else {
                arg7 += 0.0001f;
            }
        } else {
            return 0;
        }
    }
    uvtr = uvGetLoadedFile('UVTR', terraId);

    sp18C = uvtr->unk1C;
    sp188 = uvtr->unk20;
    sp160 = arg2;
    sp15C = arg3;
    sp158 = arg5;
    sp154 = arg6;
    temp_fs2 = arg5 - arg2;
    temp_fs3 = arg6 - arg3;
    temp_fs0 = arg7 - arg4;
    sUvIntersectExports->func_uvintersect_rom_00401A2C(&arg2, &arg3, &arg5, &arg6, uvtr->unk0.unk0,
                                                          uvtr->unk0.unkC, uvtr->unk0.unk4,
                                                          uvtr->unk0.unk10);
    if (arg2 == uvtr->unk0.unkC) {
        arg2 -= 0.0001f * sp18C;
    }
    if (arg5 == uvtr->unk0.unkC) {
        arg5 -= 0.0001f * sp18C;
    }
    if (arg3 == uvtr->unk0.unk10) {
        arg3 -= 0.0001f * sp188;
    }
    if (arg6 == uvtr->unk0.unk10) {
        arg6 -= 0.0001f * sp188;
    }

    if ((sp160 != arg2) && (temp_fs2 != 0.0f)) {
        arg4 += temp_fs0 * ((arg2 - sp160) / temp_fs2);
    } else if ((sp15C != arg3) && (temp_fs3 != 0.0f)) {
        arg4 += temp_fs0 * ((arg3 - sp15C) / temp_fs3);
    }
    if ((sp158 != arg5) && (temp_fs2 != 0.0f)) {
        arg7 += temp_fs0 * ((arg5 - sp158) / temp_fs2);
    } else if ((sp154 != arg6) && (temp_fs3 != 0.0f)) {
        arg7 += temp_fs0 * ((arg6 - sp154) / temp_fs3);
    }
    temp1 = arg5 - arg2;
    temp2 = arg6 - arg3;
    temp3 = arg7 - arg4;
    if ((temp1 == 0.0f) && (temp2 == 0.0f) && (temp3 == 0.0f)) {
        if (arg1 & 2) {
            i = func_uvterra_rom_0040888C(terraId, arg2, arg3, arg4);
            if (i == -1) {
                return 0;
            }
            *D_uvterra_rom_0040F784 = i;
            *D_uvterra_rom_0040F780 = 0.0f;
            *D_uvterra_rom_0040F794 |= 2;
            *D_uvterra_rom_0040F794 &= ~4;
            D_uvterra_rom_0040F788->x = 0.0f;
            D_uvterra_rom_0040F788->y = 0.0f;
            D_uvterra_rom_0040F788->z = 1.0f;
            *arg8 = D_uvterra_rom_0040F784;
            *arg9 = D_uvterra_rom_0040F780;
            *arg10 = D_uvterra_rom_0040F788;
            *arg11 = D_uvterra_rom_0040F794;
            return 1;
        }
        return 0;
    }
    temp_s0 =
        func_uvterra_rom_0040B8C0(uvtr, arg2, arg3, arg4, &sp1D0, &sp1CC, &sp1C8, &sp1BA, &sp1B6, 0);
    temp_t3 =
        func_uvterra_rom_0040B8C0(uvtr, arg5, arg6, arg7, &sp1C4, &sp1C0, &sp1BC, &sp1B8, &sp1B4, 0);
    if ((temp_s0 == 0) && (temp_t3 == 0)) {
        return 0;
    }
    if (sp1BA == sp1B8) {
        sp10F = TRUE;
        if (sp1B6 == sp1B4) {
            sp10E = TRUE;
        } else {
            sp10E = FALSE;
        }
    } else {
        sp10F = FALSE;
        sp10E = FALSE;
    }
    if (sp10F) {
        var_v1 = var_v0 = (s32) ((arg2 - uvtr->unk0.unk0) / sp18C);
        sp1A4 = sp1A0 = (s32) ((arg3 - uvtr->unk0.unk4) / sp188);
    } else {
        if (arg5 < arg2) {
            var_ft4 = arg5;
            var_ft5 = arg2;
        } else {
            var_ft4 = arg2;
            var_ft5 = arg5;
        }
        if (arg6 < arg3) {
            var_fa0 = arg6;
            var_fa1 = arg3;
        } else {
            var_fa1 = arg6;
            var_fa0 = arg3;
        }

        var_v1 = (s32) ((var_ft4 - uvtr->unk0.unk0) / sp18C);
        var_v0 = (s32) ((var_ft5 - uvtr->unk0.unk0) / sp18C);
        sp1A4 = (s32) ((var_fa0 - uvtr->unk0.unk4) / sp188);
        sp1A0 = (s32) ((var_fa1 - uvtr->unk0.unk4) / sp188);
        if (var_v1 < 0) {
            var_v1 = 0;
        }

        if (var_v0 >= uvtr->unk18) {
            var_v0 = uvtr->unk18 - 1;
        }
        if (sp1A4 < 0) {
            sp1A4 = 0;
        }

        if (sp1A0 >= uvtr->unk19) {
            sp1A0 = uvtr->unk19 - 1;
        }
    }

    if (arg4 < arg7) {
        sp130 = arg4;
    } else {
        sp130 = arg7;
    }

    for (i = var_v1; i <= var_v0; i++) {
        for (j = sp1A4; j <= sp1A0; j++) {
            sp118 = (uvtr->unk18 * j) + i;
            temp_s1 = &uvtr->unk28[sp118];
            if (temp_s1 == NULL) {
                continue;
            }
            if (temp_s1->unk48 < sp130) {
                continue;
            }
            uvct = temp_s1->unk40;
            if (uvct == NULL) {
                continue;
            }
            sp170 = arg2;
            sp168 = arg3;
            sp16C = arg5;
            sp164 = arg6;
            sp150 = arg4 - temp_s1->unk0.m[3][2];
            sp14C = arg7 - temp_s1->unk0.m[3][2];

            sp180 = temp_s1->unk0.m[3][0] - (0.5f * sp18C);
            sp17C = temp_s1->unk0.m[3][0] + (0.5f * sp18C);
            sp174 = temp_s1->unk0.m[3][1] + (0.5f * sp188);
            sp178 = temp_s1->unk0.m[3][1] - (0.5f * sp188);
            if (sUvIntersectExports->func_uvintersect_rom_0040191C(arg2, arg3, arg5, arg6, sp180,
                                                                      sp17C, sp178, sp174)
                == 0) {
                continue;
            }
            if (!sp10F) {
                sUvIntersectExports->func_uvintersect_rom_00401CB0(
                    &sp170, &sp168, &sp150, &sp16C, &sp164, &sp14C, sp180, sp17C, sp178, sp174);
                if ((sp170 == sp16C) && (sp168 == sp164) && (sp150 == sp14C)) {
                    continue;
                }
                var_s0 = 0;
                if (sp170 == sp17C) {
                    var_s0 |= 1;
                }
                if (sp168 == sp174) {
                    var_s0 |= 2;
                }
                func_uvterra_rom_0040B8C0(uvtr, sp170, sp168, sp150, &sp1D0, &sp1CC, &sp1C8, &sp1BA,
                                          &sp1B6, var_s0);
                var_s0 = 0;
                if (sp16C == sp17C) {
                    var_s0 |= 1;
                }
                if (sp164 == sp174) {
                    var_s0 |= 2;
                }
                func_uvterra_rom_0040B8C0(uvtr, sp16C, sp164, sp14C, &sp1C4, &sp1C0, &sp1BC, &sp1B8,
                                          &sp1B4, var_s0);
                if (sp1B6 != sp1B4) {
                    sp1B4 = func_uvterra_rom_0040BD38(sp170, sp168, sp16C, sp164, sp1D0, sp1CC, sp1C4,
                                                      sp1C0, sp180, sp17C, sp174, sp178, temp_s1);
                }
            }

            if (!sp10E) {
                sp1B4 = func_uvterra_rom_0040BD38(sp170, sp168, sp16C, sp164, sp1D0, sp1CC, sp1C4,
                                                  sp1C0, sp180, sp17C, sp174, sp178, temp_s1);
            }
            if (sp1B4 == 0) {
                continue;
            }

            sp1D0 *= uvct->unk2C;
            sp1C4 *= uvct->unk2C;
            sp1CC *= uvct->unk2C;
            sp1C0 *= uvct->unk2C;
            sp1C8 *= uvct->unk30;
            sp1BC *= uvct->unk30;

            if (arg1 & 2) {
                for (temp_t0 = 0; temp_t0 < temp_s1->unk40->unk14; temp_t0++) {
                    sobj = &temp_s1->unk40->unk10[temp_t0];
                    if (!(sp1B4 & sobj->unk18)) {
                        continue;
                    }
                    if ((sobj->unk3C + temp_s1->unk0.m[3][2]) < sp130) {
                        continue;
                    }

                    ft4 = sobj->unk8;
                    ft5 = sobj->unkC;
                    fs2 = sobj->unk10;
                    fv1 = sobj->unk14;

                    if (fv1 + ft4 < MIN(sp1D0, sp1C4)) {
                        continue;
                    }
                    if (fv1 - ft4 > MAX(sp1D0, sp1C4)) {
                        continue;
                    }
                    if (fv1 + ft5 < MIN(sp1CC, sp1C0)) {
                        continue;
                    }
                    if (fv1 - ft5 > MAX(sp1CC, sp1C0)) {
                        continue;
                    }
                    if (fv1 + fs2 < MIN(sp1C8, sp1BC)) {
                        continue;
                    }
                    if (fv1 - fs2 > MAX(sp1C8, sp1BC)) {
                        continue;
                    }

                    if (sUvIntersectExports->func_uvintersect_rom_00400144(
                            sp1D0, sp1CC, sp1C8, sp1C4, sp1C0, sp1BC, ft4, ft5, fs2, fv1, &sp184)
                        != 0) {
                        temp_v0_4 = uvGetLoadedFile('UVMD', sobj->modelId);
                        if (temp_v0_4 == NULL) {
                            continue;
                        }
                        *D_uvterra_rom_0040F78C = (temp_s1->unk44 << 0xC) | temp_t0;
                        if (!(temp_v0_4->unk5 & 6)) {
                            if (*D_uvterra_rom_0040F790
                                >= sUvQueryExports->func_uvquery_rom_00400224()) {
                                break;
                            }
                            D_uvterra_rom_0040F784[*D_uvterra_rom_0040F790] = *D_uvterra_rom_0040F78C;
                            D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = sp184;
                            sUvIntersectExports->func_uvintersect_rom_00400700(
                                arg2, arg3, arg4, arg5, arg6, arg7, sp184,
                                temp_s1->unk0.m[3][0] + sobj->unk8, temp_s1->unk0.m[3][1] + sobj->unkC,
                                temp_s1->unk0.m[3][2] + sobj->unk10,
                                &D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790]);
                            *D_uvterra_rom_0040F790 += 1;
                        } else {
                            func_uvterra_rom_0040A79C(sp1D0, sp1CC, sp1C8, sp1C4, sp1C0, sp1BC, sobj);
                        }
                    }
                }
            }
            for (temp_t0 = 0; temp_t0 < *D_uvterra_rom_0040F790; temp_t0++) {
                D_uvterra_rom_0040F794[temp_t0] |= 2;
                D_uvterra_rom_0040F794[temp_t0] &= ~4;
            }
            if (arg1 & 4) {
                for (k = 0; k < uvct->unkC; k++) {
                    temp_s1_2 = &uvct->unk8[k];
                    if (!(temp_s1_2->unk1E & sp1B4)) {
                        continue;
                    }

                    if (temp_s1_2->unk34 + temp_s1->unk0.m[3][2] < sp130) {
                        continue;
                    }

                    for (l = 0; l < temp_s1_2->unk1C; l++) {
                        temp_v0_2 = &temp_s1_2->unk18[l];
                        if (!(temp_v0_2->unk6 & sp1B4)) {
                            continue;
                        }

                        vtx1 = &uvct->vtxTable[temp_v0_2->unk0];
                        vtx2 = &uvct->vtxTable[temp_v0_2->unk2];
                        vtx3 = &uvct->vtxTable[temp_v0_2->unk4];

                         // clang-format off
                        if (MIN(MIN(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) > MAX(sp1D0, sp1C4)) { continue; } \
                        if (MAX(MAX(vtx1->v.ob[0], vtx2->v.ob[0]), vtx3->v.ob[0]) < MIN(sp1D0, sp1C4)) { continue; } \
                        if (MIN(MIN(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) > MAX(sp1CC, sp1C0)) { continue; } \
                        if (MAX(MAX(vtx1->v.ob[1], vtx2->v.ob[1]), vtx3->v.ob[1]) < MIN(sp1CC, sp1C0)) { continue; } \
                        if (MIN(MIN(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) > MAX(sp1C8, sp1BC)) { continue; } 
                        if (MAX(MAX(vtx1->v.ob[2], vtx2->v.ob[2]), vtx3->v.ob[2]) < MIN(sp1C8, sp1BC)) { continue; }  
                        // clang-format on

                        if (sUvIntersectExports->func_uvintersect_rom_00401318(
                                sp1D0, sp1CC, sp1C8, sp1C4, sp1C0, sp1BC, vtx1->v.ob[0], vtx1->v.ob[1],
                                vtx1->v.ob[2], vtx2->v.ob[0], vtx2->v.ob[1], vtx2->v.ob[2],
                                vtx3->v.ob[0], vtx3->v.ob[1], vtx3->v.ob[2], 1.0f, 1.0f, &sp184, &sp1D4)
                            == 0) {
                            continue;
                        }
                        if (var_s0 != 0) {
                            if (temp_fs2 != 0.0f) {
                                sp184 = (((sp16C - sp170) / temp_fs2) * sp184)
                                        + ((sp170 - sp160) / temp_fs2);
                            } else if (temp_fs3 != 0.0f) {
                                sp184 = (((sp164 - sp168) / temp_fs3) * sp184)
                                        + ((sp168 - sp15C) / temp_fs3);
                            }
                        }

                        if (sp184 < 0.0f) {
                            sp184 = 0.0f;
                        } else if (sp184 > 1.0f) {
                            sp184 = 1.0f;
                        }
                        if (*D_uvterra_rom_0040F790
                            >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            break;
                        }
                        temp_t0 = *D_uvterra_rom_0040F790;
                        D_uvterra_rom_0040F784[temp_t0] =
                            ((sp118 & 0x3FF) << 22) + ((k & 0x3FF) << 12) + (l & 0xFFF);
                        D_uvterra_rom_0040F780[temp_t0] = sp184;
                        D_uvterra_rom_0040F794[temp_t0] |= 4;
                        D_uvterra_rom_0040F794[temp_t0] &= ~2;
                        sUvFVecExports->uvVec3FCopy(&D_uvterra_rom_0040F788[temp_t0], &sp1D4);
                        (*D_uvterra_rom_0040F790)++;
                    }
                }
            }
        }
    }
    if (*D_uvterra_rom_0040F790 != 0) {
        *arg8 = D_uvterra_rom_0040F784;
        *arg9 = D_uvterra_rom_0040F780;
        *arg11 = D_uvterra_rom_0040F794;
        *arg10 = D_uvterra_rom_0040F788;
    }

    return *D_uvterra_rom_0040F790;
}

s32 func_uvterra_rom_00404E14(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 **arg6,
                              f32 **arg7, Vec3F **arg8, s32 **arg9) {
    s32 sp1BC;
    s32 sp1B8;
    s32 sp1B4;
    Vtx *temp_s2;
    Vtx *temp_s3;
    Vtx *temp_s4;
    s32 sp1A4;
    s32 sp1A0;
    s32 sp19C;
    s32 sp198;
    ParsedUVMD *temp_v0_3;
    s32 sp190;
    UnkSobjDraw *temp_s0;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    Vec3F *temp_s0_2;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 temp_fs0;
    f32 sp15C;
    f32 sp158;
    f32 temp_fs1;
    ParsedUVTR *sp150;
    f32 temp_fs2;
    ParsedUVCT *sp148;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fv0;
    f32 temp_fv1_4;
    u16 temp_fp;
    s32 temp_v0_8;
    s32 var_s0;
    query_28 *var_s0_3;
    s32 var_s3;
    s32 var_s4;
    s32 var_s7;
    s32 var_v0_2;
    uvUnkTileStruct *temp_s5;
    Mtx4F spD0;
    Unk80225FBC_0x28 *temp_fp_2;
    Unk80225FBC_0x28_UnkC *temp_v1_5;
    query_78 *var_s0_2;

    sp150 = uvGetLoadedFile('UVTR', arg0);
    if (sp150 == NULL) {
        return 0;
    }

    if ((arg2 + arg5) < sp150->unk0.unk0) {
        return 0;
    }

    if (sp150->unk0.unkC < (arg2 - arg5)) {
        return 0;
    }

    if ((arg3 + arg5) < sp150->unk0.unk4) {
        return 0;
    }

    if (sp150->unk0.unk10 < (arg3 - arg5)) {
        return 0;
    }
    func_80000CA4(D_uvterra_rom_0040FBF8);
    var_s0 = (s32) (((arg2 - arg5) - sp150->unk0.unk0) / sp150->unk1C);
    sp1A4 = (s32) (((arg2 + arg5) - sp150->unk0.unk0) / sp150->unk1C);
    sp1A0 = (s32) (((arg3 - arg5) - sp150->unk0.unk4) / sp150->unk20);
    sp19C = (s32) (((arg3 + arg5) - sp150->unk0.unk4) / sp150->unk20);
    if (var_s0 < 0) {
        var_s0 = 0;
    }
    if ((sp150->unk18 - 1) < sp1A4) {
        sp1A4 = (sp150->unk18 - 1);
    }
    if (sp1A0 < 0) {
        sp1A0 = 0;
    }
    if ((sp150->unk19 - 1) < sp19C) {
        sp19C = (sp150->unk19 - 1);
    }
    *D_uvterra_rom_0040F790 = 0;
    *D_uvterra_rom_0040F798 = 0;
    sp170 = sp150->unk0.unk0;
    sp16C = sp150->unk1C + sp170;
    sUvQueryExports->uvQueryGetProps(0, 1, &sp190, 0);
    for (sp1BC = var_s0; sp1BC <= sp1A4; sp1BC++) {
        sp164 = sp150->unk0.unk4;
        sp168 = sp150->unk20 + sp164;
        for (sp1B8 = sp1A0; sp1B8 <= sp19C; sp1B8++) {
            sp198 = (sp150->unk18 * sp1B8) + sp1BC;
            temp_s5 = &sp150->unk28[sp198];
            if (temp_s5 == NULL) {
                continue;
            }

            sp148 = temp_s5->unk40;
            if (sp148 == NULL) {
                continue;
            }

            temp_fs4 = sp148->unk2C * arg5;
            sp178 = sp148->unk30 * arg5;
            sp188 = arg2 - temp_s5->unk0.m[3][0];
            sp184 = arg3 - temp_s5->unk0.m[3][1];
            sp180 = arg4 - temp_s5->unk0.m[3][2];
            temp_fs5 = sp148->unk2C * sp188;
            sp15C = sp148->unk2C * sp184;
            sp158 = sp148->unk30 * sp180;
            sp174 = sp148->unk2C / sp148->unk30;
            temp_fp = func_uvterra_rom_0040BBC0(sp188, sp184, arg5, sp170, sp16C, sp164, sp168);
            func_80000CA4(D_uvterra_rom_0040FC00);
            if (arg1 & 2) {
                for (sp1B4 = 0; sp1B4 < sp148->unk14; sp1B4++) {
                    temp_s0 = &sp148->unk10[sp1B4];
                    if (!(temp_s0->unk40 & 1)) {
                        continue;
                    }

                    if (temp_s0->modelId == 0xFFFF) {
                        continue;
                    }

                    if (!((temp_s0->unk18 & temp_fp))) {
                        continue;
                    }
                    temp_fs0 = temp_s0->unk14;
                    temp_fs1 = temp_s0->unk8;
                    temp_fs2 = temp_s0->unkC;
                    temp_fs3 = temp_s0->unk10;

                    if (((sp188 + temp_fs0 + arg5) < temp_fs1)) {
                        continue;
                    }

                    if ((temp_fs1 < ((sp188 - temp_fs0) - arg5))) {
                        continue;
                    }

                    if (((sp184 + temp_fs0 + arg5) < temp_fs2)) {
                        continue;
                    }

                    if ((temp_fs2 < ((sp184 - temp_fs0) - arg5))) {
                        continue;
                    }

                    if (((sp180 + temp_fs0 + arg5) < temp_fs3)) {
                        continue;
                    }

                    if ((temp_fs3 < ((sp180 - temp_fs0) - arg5))) {
                        continue;
                    }

                    if (sUvIntersectExports->func_uvintersect_rom_004004C4(
                            sp188, sp184, sp180, arg5, temp_fs1, temp_fs2, temp_fs3, temp_fs0)
                        == 0) {
                        continue;
                    }
                    temp_v0_3 = uvGetLoadedFile('UVMD', (s32) temp_s0->modelId);
                    if (temp_v0_3 == NULL) {
                        continue;
                    }
                    *D_uvterra_rom_0040F78C = (temp_s5->unk44 << 0xC) | sp1B4;
                    if (temp_v0_3->unk5 & 0x76) {
                        var_s4 = *D_uvterra_rom_0040F798;
                        var_s3 = *D_uvterra_rom_0040F790;
                        func_uvterra_rom_0040A08C(sp188, sp184, sp180, arg5, temp_s0);
                        var_s0_2 = sUvQueryExports->func_uvquery_rom_004004CC() + var_s3;
                        while (var_s3 < *D_uvterra_rom_0040F790) {
                            if (sp190 != 0) {
                                if (var_s0_2->unk70 & 1) {
                                    var_s0_2->unk0.x += temp_s5->unk0.m[3][0];
                                    var_s0_2->unk0.y += temp_s5->unk0.m[3][1];
                                    var_s0_2->unk0.z += temp_s5->unk0.m[3][2];
                                    var_s0_2->unkC.x += temp_s5->unk0.m[3][0];
                                    var_s0_2->unkC.y += temp_s5->unk0.m[3][1];
                                    var_s0_2->unkC.z += temp_s5->unk0.m[3][2];
                                    var_s0_2->unk18.x += temp_s5->unk0.m[3][0];
                                    var_s0_2->unk18.y += temp_s5->unk0.m[3][1];
                                    var_s0_2->unk18.z += temp_s5->unk0.m[3][2];
                                } else {
                                    sUvFMtxExports->uvMat4Mul(&spD0, &var_s0_2->unk30,
                                                                      &temp_s5->unk4C);
                                    sUvFMtxExports->uvMat4FCopy(&var_s0_2->unk30, &spD0);
                                }
                                var_s0_2++;
                            }
                            D_uvterra_rom_0040F794[var_s3] |= 2;
                            D_uvterra_rom_0040F794[var_s3] &= ~4;
                            var_s3++;
                        }

                        if (sUvQueryExports->func_uvquery_rom_004005EC() != NULL) {
                            var_s0_3 = sUvQueryExports->func_uvquery_rom_004005EC() + var_s4;
                            while (var_s4 < *D_uvterra_rom_0040F798) {
                                sUvFVecExports->uvVec3FAdd(&var_s0_3->unk14, &var_s0_3->unk14,
                                                                   (Vec3F *) temp_s5->unk0.m[3]);

                                sUvFVecExports->uvVec3FAdd(&var_s0_3->unk8, &var_s0_3->unk8,
                                                                   (Vec3F *) temp_s5->unk0.m[3]);
                                var_s4++;
                                var_s0_3++;
                            }
                        }
                        if (*D_uvterra_rom_0040F790
                            >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            sp1B8 = sp19C + 1;
                            sp1BC = sp1A4 + 1;
                            break;
                        }
                    } else {
                        D_uvterra_rom_0040F784[*D_uvterra_rom_0040F790] = *D_uvterra_rom_0040F78C;
                        temp_s0_2 = &D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790];
                        temp_s0_2->x = sp188 - temp_fs1;
                        temp_s0_2->y = sp184 - temp_fs2;
                        temp_s0_2->z = sp180 - temp_fs3;
                        temp_fv1_4 = (arg5
                                      - (sUvMathExports->uvSqrtf(
                                             SQ(temp_s0_2->x) + SQ(temp_s0_2->y) + SQ(temp_s0_2->z))
                                         - temp_fs0))
                                     / arg5;
                        if (temp_fv1_4 < 0.0f) {
                            D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = temp_fv1_4;
                        } else {
                            D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = 0;
                        }
                        D_uvterra_rom_0040F794[*D_uvterra_rom_0040F790] |= 1;
                        sUvFVecExports->uvVec3FNormalize(temp_s0_2, temp_s0_2);
                        *D_uvterra_rom_0040F790 += 1;
                        if (*D_uvterra_rom_0040F790
                            >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            sp1B8 = sp19C + 1;
                            sp1BC = sp1A4 + 1;
                            break;
                        }
                    }
                }
            }

            func_80000D58(D_uvterra_rom_0040FC00);
            func_80000CA4(D_uvterra_rom_0040FBFC);
            if ((arg1 & 4)
                && (*D_uvterra_rom_0040F790 < sUvQueryExports->func_uvquery_rom_00400224())) {
                for (sp1B4 = 0; sp1B4 < sp148->unkC; sp1B4++) {
                    temp_fp_2 = &sp148->unk8[sp1B4];
                    if (!(temp_fp_2->unk1E & temp_fp)) {
                        continue;
                    }

                    var_v0_2 = ((SQ(temp_fp_2->unk30 + arg5)
                                 - (SQ(sp188 - temp_fp_2->unk24) + SQ(sp184 - temp_fp_2->unk28)
                                    + SQ(sp180 - temp_fp_2->unk2C)))
                                >= 0.0f);

                    if (var_v0_2 == 0) {
                        continue;
                    }
                    for (var_s7 = 0; var_s7 < temp_fp_2->unk1C; var_s7++) {
                        temp_v1_5 = &temp_fp_2->unk18[var_s7];
                        if (!(temp_v1_5->unk6 & temp_fp)) {
                            continue;
                        }

                        temp_s2 = &sp148->vtxTable[temp_v1_5->unk0];
                        temp_s3 = &sp148->vtxTable[temp_v1_5->unk2];
                        temp_s4 = &sp148->vtxTable[temp_v1_5->unk4];

                        if ((temp_fs4 < (MIN(MIN(temp_s2->v.ob[0], temp_s3->v.ob[0]), temp_s4->v.ob[0])
                                         - temp_fs5))) {
                            continue;
                        }
                        if ((temp_fs4
                             < (temp_fs5
                                - MAX(MAX(temp_s2->v.ob[0], temp_s3->v.ob[0]), temp_s4->v.ob[0])))) {
                            continue;
                        }
                        if ((temp_fs4 < (MIN(MIN(temp_s2->v.ob[1], temp_s3->v.ob[1]), temp_s4->v.ob[1])
                                         - sp15C))) {
                            continue;
                        }
                        if ((temp_fs4
                             < (sp15C
                                - MAX(MAX(temp_s2->v.ob[1], temp_s3->v.ob[1]), temp_s4->v.ob[1])))) {
                            continue;
                        }
                        if ((sp178 < (MIN(MIN(temp_s2->v.ob[2], temp_s3->v.ob[2]), temp_s4->v.ob[2])
                                      - sp158))) {
                            continue;
                        }
                        if ((sp178
                             < (sp158
                                - MAX(MAX(temp_s2->v.ob[2], temp_s3->v.ob[2]), temp_s4->v.ob[2])))) {
                            continue;
                        }

                        if (*D_uvterra_rom_0040F790
                            >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            break;
                        }

                        temp_v0_8 = sUvIntersectExports->func_uvintersect_rom_0040093C(
                            temp_fs5, sp15C, sp158, temp_fs4, sp174, temp_s2->v.ob[0], temp_s2->v.ob[1],
                            temp_s2->v.ob[2], temp_s3->v.ob[0], temp_s3->v.ob[1], temp_s3->v.ob[2],
                            temp_s4->v.ob[0], temp_s4->v.ob[1], temp_s4->v.ob[2],
                            &D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790],
                            &D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790]);

                        if (temp_v0_8 == 0) {
                            continue;
                        }
                        if (temp_v0_8 == 1) {
                            D_uvterra_rom_0040F794[*D_uvterra_rom_0040F790] |= 1;
                        } else {
                            D_uvterra_rom_0040F794[*D_uvterra_rom_0040F790] &= ~1;
                        }
                        D_uvterra_rom_0040F794[*D_uvterra_rom_0040F790] |= 4;
                        D_uvterra_rom_0040F794[*D_uvterra_rom_0040F790] &= ~2;
                        if (sp190 != 0) {
                            temp_fs0 = 1.0f / sp148->unk2C;
                            temp_fs1 = 1.0f / sp148->unk30;
                            var_s0_2 = sUvQueryExports->func_uvquery_rom_004004CC()
                                       + *D_uvterra_rom_0040F790;
                            var_s0_2->unk0.x = (temp_fs0 * temp_s2->v.ob[0]) + temp_s5->unk0.m[3][0];
                            var_s0_2->unk0.y = (temp_fs0 * temp_s2->v.ob[1]) + temp_s5->unk0.m[3][1];
                            var_s0_2->unk0.z = (temp_fs1 * temp_s2->v.ob[2]) + temp_s5->unk0.m[3][2];
                            var_s0_2->unkC.x = (temp_fs0 * temp_s3->v.ob[0]) + temp_s5->unk0.m[3][0];
                            var_s0_2->unkC.y = (temp_fs0 * temp_s3->v.ob[1]) + temp_s5->unk0.m[3][1];
                            var_s0_2->unkC.z = (temp_fs1 * temp_s3->v.ob[2]) + temp_s5->unk0.m[3][2];
                            var_s0_2->unk18.x = (temp_fs0 * temp_s4->v.ob[0]) + temp_s5->unk0.m[3][0];
                            var_s0_2->unk18.y = (temp_fs0 * temp_s4->v.ob[1]) + temp_s5->unk0.m[3][1];
                            var_s0_2->unk18.z = (temp_fs1 * temp_s4->v.ob[2]) + temp_s5->unk0.m[3][2];
                            var_s0_2->unk24 = D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790];
                            var_s0_2->unk70 |= 1;
                            var_s0_2->unk74 = temp_fp_2->unk0.state;
                        }
                        D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] /= -arg5 * sp148->unk2C;
                        D_uvterra_rom_0040F784[*D_uvterra_rom_0040F790] =
                            ((sp198 & 0x3FF) << 0x16) + ((sp1B4 & 0x3FF) << 0xC) + (var_s7 & 0xFFF);
                        *D_uvterra_rom_0040F790 += 1;
                    }
                }
            }
            func_80000D58(D_uvterra_rom_0040FBFC);
            if (sp19C >= sp1B8) {
                sp164 += sp150->unk20;
                sp168 += sp150->unk20;
            }
        }
        if (sp1A4 >= sp1BC) {
            sp170 += sp150->unk1C;
            sp16C += sp150->unk20;
        }
    }
    *arg6 = D_uvterra_rom_0040F784;
    *arg7 = D_uvterra_rom_0040F780;
    *arg8 = D_uvterra_rom_0040F788;
    *arg9 = D_uvterra_rom_0040F794;
    func_80000D58(D_uvterra_rom_0040FBF8);
    return *D_uvterra_rom_0040F790;
}

s32 func_uvterra_rom_004060A4(s32 arg0, u32 arg1) {
    ParsedUVCT *temp_a1;
    ParsedUVTR *temp_v0;
    uvUnkTileStruct *temp_v1;
    Unk80225FBC_0x28 *var_v1;
    s32 ret;

    if (arg1 == -1U) {
        return 0xFFF;
    }
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == NULL) {
        return 0xFFF;
    }
    temp_v1 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    if (temp_v1 == NULL) {
        return 0xFFF;
    }
    temp_a1 = temp_v1->unk40;
    if (temp_a1 == NULL) {
        return 0xFFF;
    }
    var_v1 = &temp_a1->unk8[(arg1 >> 0xC) & 0x3FF];
    ret = var_v1->unk0.state & 0xFFF;
    return ret;
}

s32 func_uvterra_rom_00406160(s32 terraId, s32 texture, s32 **arg2) {
    ParsedUVTR *uvtr;
    s32 temp_lo;
    s32 k;
    s32 i;
    s32 j;
    s32 var_t4;
    s32 *temp_s2;
    s32 temp_t0;
    u16 temp_t5;
    ParsedUVCT *uvct;
    Unk80225FBC_0x28 *temp_a0_2;
    s32 var_a3;
    uvUnkTileStruct *temp_ra;

    temp_s2 = D_uvterra_rom_0040F784;
    var_a3 = 0;
    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        *arg2 = NULL;
        return 0;
    }
    temp_lo = uvtr->unk18 * uvtr->unk19;
    for (i = 0; i < temp_lo; i++) {
        temp_ra = &uvtr->unk28[i];
        if (temp_ra == NULL) {
            continue;
        }
        uvct = temp_ra->unk40;
        if (uvct == NULL) {
            continue;
        }

        j = 0;
        temp_t5 = uvct->unkC;
        if (temp_t5 > 0) {
            do {
                temp_a0_2 = &temp_ra->unk40->unk8[j];
                temp_t0 = temp_a0_2->unk1C;
                if (temp_t0 == 0) {
                    continue;
                }
                var_t4 = (temp_a0_2->unk0.state & 0xFFF);
                if (var_t4 != texture) {
                    continue;
                }
                var_t4 = ((u16) i << 22);
                for (k = 0; k < temp_t0; k++) {
                    temp_s2[var_a3++] = (u32) var_t4 + ((j & 0x3FF) << 0xC) + (k & 0xFFF);
                }
            } while (++j != temp_t5);
        }
    }
    *arg2 = temp_s2;
    return var_a3;
}

s32 func_uvterra_rom_00406324(Vtx *arg0, Vtx *arg1, Vtx *arg2, f32 *arg3, f32 *arg4, f32 *arg5,
                              f32 arg6, f32 arg7) {
    Vtx *temp1;
    f32 *temp2;
    Vtx *sp34[3];
    s32 i;
    f32 *sp24[3];
    s32 var_v0;
    f32 temp_fa0;
    f32 temp_ft5;
    f32 var_fv0;

    *arg3 = *arg4 = *arg5 = 0.333f;
    sp34[0] = arg0;
    sp34[1] = arg1;
    sp34[2] = arg2;
    sp24[0] = arg3;
    sp24[1] = arg4;
    sp24[2] = arg5;
    var_v0 = 0;
    for (i = 0; i < 3; i++) {
        if (sp34[i]->v.ob[1] < arg7) {
            var_v0++;
        }
    }
    if ((var_v0 == 3) || (var_v0 == 0)) {
        return 0;
    }
    if (var_v0 == 1) {
        for (i = 1; i < 3; i++) {
            if (sp34[i]->v.ob[1] < arg7) {
                temp1 = sp34[i];
                temp2 = sp24[i];
                sp34[i] = arg0;
                sp24[i] = arg3;
                sp34[0] = temp1;
                sp24[0] = temp2;
                break;
            }
        }
    } else {
        for (i = 1; i < 3; i++) {
            if (sp34[i]->v.ob[1] > arg7) {
                temp1 = sp34[i];
                temp2 = sp24[i];
                sp34[i] = arg0;
                sp24[i] = arg3;
                sp34[0] = temp1;
                sp24[0] = temp2;
                break;
            }
        }
    }

    if (((sp34[1]->v.ob[1] - sp34[0]->v.ob[1]) == 0.0f)
        || ((f32) (sp34[2]->v.ob[1] - sp34[0]->v.ob[1]) == 0.0f)) {
        return 0;
    }
    *sp24[1] = (arg7 - sp34[0]->v.ob[1]) / (sp34[1]->v.ob[1] - sp34[0]->v.ob[1]);
    *sp24[2] = (arg7 - sp34[0]->v.ob[1]) / (sp34[2]->v.ob[1] - sp34[0]->v.ob[1]);
    temp_fa0 = (*sp24[1] * (sp34[1]->v.ob[0] - sp34[0]->v.ob[0])) + sp34[0]->v.ob[0];
    temp_ft5 = (*sp24[2] * (sp34[2]->v.ob[0] - sp34[0]->v.ob[0])) + sp34[0]->v.ob[0];
    if (temp_ft5 != temp_fa0) {
        var_fv0 = (arg6 - temp_fa0) / (temp_ft5 - temp_fa0);
    } else {
        var_fv0 = 0.0f;
    }
    if ((var_fv0 < 0.0f) || (var_fv0 > 1.0f)) {
        return 0;
    }
    *sp24[1] *= (1.0f - var_fv0);
    *sp24[2] *= var_fv0;
    *sp24[0] = (1.0f - *sp24[1]) - *sp24[2];
    return 1;
}

void uvTerraGetColor(s32 terraId, u32 surfaceId, f32 arg2, f32 arg3, u8 *r, u8 *g, u8 *b,
                               u8 *a) {
    Unk80225FBC_0x28 *temp_t2;
    uvUnkTileStruct *sp60;
    ParsedUVTR *uvtr;
    Vtx *vtx;
    Unk80225FBC_0x28_UnkC *sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    s16 sp3A;
    s16 sp38;
    ParsedUVCT *uvct;

    if (surfaceId == -1U) {
        return;
    }

    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        return;
    }

    sp60 = &uvtr->unk28[(surfaceId >> 0x16) & 0x3FF];
    if (sp60 == NULL) {
        return;
    }

    uvct = sp60->unk40;
    if (uvct == NULL) {
        return;
    }

    temp_t2 = &uvct->unk8[(surfaceId >> 0xC) & 0x3FF];
    sp54 = &temp_t2->unk18[surfaceId & 0xFFF];
    vtx = uvct->vtxTable;
    func_uvterra_rom_0040B8C0(uvtr, arg2, arg3, 0.0f, &sp50, &sp4C, &sp3C, &sp3A, &sp38, 0U);
    sp50 *= sp60->unk40->unk2C;
    sp4C *= sp60->unk40->unk2C;
    func_uvterra_rom_00406324(&vtx[sp54->unk0], &vtx[sp54->unk2], &vtx[sp54->unk4], &sp48, &sp44, &sp40,
                              sp50, sp4C);

    *r = ((vtx[sp54->unk0].v.cn[0] * sp48) + (vtx[sp54->unk2].v.cn[0] * sp44))
         + (vtx[sp54->unk4].v.cn[0] * sp40);
    *g = ((vtx[sp54->unk0].v.cn[1] * sp48) + (vtx[sp54->unk2].v.cn[1] * sp44))
         + (vtx[sp54->unk4].v.cn[1] * sp40);
    *b = ((vtx[sp54->unk0].v.cn[2] * sp48) + (vtx[sp54->unk2].v.cn[2] * sp44))
         + (vtx[sp54->unk4].v.cn[2] * sp40);
    *a = ((vtx[sp54->unk0].v.cn[3] * sp48) + (vtx[sp54->unk2].v.cn[3] * sp44))
         + (vtx[sp54->unk4].v.cn[3] * sp40);
}

void func_uvterra_rom_00406C60(s32 arg0, u32 arg1, f32 arg2, f32 arg3, u8 *r, u8 *g, u8 *b, u8 *a) {
    ParsedUVTR *sp84;
    uvUnkTileStruct *sp80;
    f32 var_fv0;
    ParsedUVTX *sp78;
    Vtx *sp74;
    Unk80225FBC_0x28_UnkC *sp70;
    f32 var_fv1;
    f32 sp68;
    f32 sp64;
    s32 temp_t8;
    s32 temp_v0_6;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 pad_sp4C;
    f32 sp48;
    s16 sp46;
    s16 sp44;

    *r = 0xFF;
    *g = 0xFF;
    *b = 0xFF;
    *a = 0xFF;

    if (arg1 == -1) {
        return;
    }

    sp84 = uvGetLoadedFile('UVTR', arg0);
    if (sp84 == NULL) {
        return;
    }

    sp80 = &sp84->unk28[(arg1 >> 22) & 0x3FF];
    if (sp80 == NULL || sp80->unk40 == NULL) {
        return;
    }

    sp70 = &sp80->unk40->unk8[(arg1 >> 12) & 0x3FF].unk18[arg1 & 0xFFF];
    temp_t8 = sp80->unk40->unk8[(arg1 >> 12) & 0x3FF].unk0.state & 0xFFF;
    if (temp_t8 == 0xFFF) {
        return;
    }

    sp78 = uvGetLoadedFile('UVTX', temp_t8);
    sp74 = sp80->unk40->vtxTable;
    func_uvterra_rom_0040B8C0(sp84, arg2, arg3, 0.0f, &sp68, &sp64, &sp48, &sp46, &sp44, 0U);
    sp68 *= sp80->unk40->unk2C;
    sp64 *= sp80->unk40->unk2C;
    func_uvterra_rom_00406324(&sp74[sp70->unk0], &sp74[sp70->unk2], &sp74[sp70->unk4], &sp58, &sp54,
                              &sp50, sp68, sp64);
    var_fv0 = ((sp74[sp70->unk0].v.tc[0] * sp58) + (sp74[sp70->unk2].v.tc[0] * sp54)
               + (sp74[sp70->unk4].v.tc[0] * sp50));
    var_fv1 = ((sp74[sp70->unk0].v.tc[1] * sp58) + (sp74[sp70->unk2].v.tc[1] * sp54)
               + (sp74[sp70->unk4].v.tc[1] * sp50));
    var_fv0 *= 0.03125f;
    var_fv1 *= 0.03125f;
    if (sp78->width < var_fv0) {
        var_fv0 -= 2.0f * sp78->width * (f32) (s32) (var_fv0 / sp78->width);
    }
    if (var_fv0 < -sp78->width) {
        var_fv0 += 2.0f * sp78->width * (f32) (s32) (-var_fv0 / sp78->width);
    }
    if (sp78->height < var_fv1) {
        var_fv1 -= 2.0f * sp78->height * (f32) (s32) (var_fv1 / sp78->height);
    }
    if (var_fv1 < -sp78->height) {
        var_fv1 += 2.0f * sp78->height * (f32) (s32) (-var_fv1 / sp78->height);
    }
    if (sp78->unk25 == 2) {
        if (!(var_fv0 > 0.0f)) {
            var_fv0 = -var_fv0;
        }
    } else if (var_fv0 < 0.0f) {
        var_fv0 += sp78->width;
    }
    if (sp78->unk26 == 2) {
        if (!(var_fv1 > 0.0f)) {
            var_fv1 = -var_fv1;
        }
    } else if (var_fv1 < 0.0f) {
        var_fv1 += sp78->height;
    }

    switch (sp78->unk21) {
        case 4:
            temp_v0_6 = (&((s16 *) sp78->data.pointer)[((s32) var_fv0)])[(s32) var_fv1 * sp78->width];
            *r = (temp_v0_6 >> 0xB) << 1 << 2;
            *g = (temp_v0_6 >> 6) << 1 << 2;
            *b = (temp_v0_6 >> 1) << 1 << 2;
            *a = temp_v0_6 << 1 << 6;
            break;
        case 2:
            temp_v0_6 = (&((u8 *) sp78->data.pointer)[(s32) var_fv0])[(s32) var_fv1 * sp78->width];
            *r = ((s32) temp_v0_6 >> 4) & 0xF;
            *g = ((s32) temp_v0_6 >> 4) & 0xF;
            *b = ((s32) temp_v0_6 >> 4) & 0xF;
            *a = temp_v0_6 & 0xF;
            break;
    }
}

s32 func_uvterra_rom_004071A4(s32 arg0, f32 arg1, f32 arg2, f32 *arg3) {
    s16 temp_v0;
    s32 *sp70;
    Vec3F sp64;
    s32 i;
    s32 var_s3;

    var_s3 = 0;
    temp_v0 = func_uvterra_rom_00401E64(arg0, arg1, arg2, &sp70);
    for (i = 0; i < temp_v0; i++) {
        uvTerraGetPlane(arg0, sp70[i], arg1, arg2, arg3, &sp64);
        if (sp64.z >= 0.34f) {
            arg3++;
            if (++var_s3 >= 10) {
                return var_s3;
            }
        }
    }
    return var_s3;
}

void func_uvterra_rom_004072BC(s32 arg0) {
    D_uvterra_rom_0040FBF0 = arg0;
}

s32 func_uvterra_rom_004072C8(void) {
    return D_uvterra_rom_0040FBF0;
}

void func_uvterra_rom_004072D4(s32 arg0) {
    D_uvterra_rom_0040FBF4 = arg0;
}

s32 func_uvterra_rom_004072E0(void) {
    return D_uvterra_rom_0040FBF4;
}

void uvTobjsDraw(s32 arg0, u16 arg1, Mtx4F *arg2, Unk80225FBC_0x28 *arg3, u16 arg4) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fa1;
    f32 fv0;
    f32 fv1;
    Vec3F sp78;
    f32 fa0;
    s32 i;
    s32 pad;
    Unk80225FBC_0x28 *s0;
    ParsedUVTR *sp64;

    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 7, &sp78, 0);
    sp64 = uvGetLoadedFile('UVTR', D_uvterra_rom_0040F77C[arg0]);
    i = 0;
    s0 = arg3;
    for (; i != arg4; i++, s0++) {
        if (!(arg1 & s0->unk1E)) {
            continue;
        }

        fv0 = sp78.x - arg2->m[3][0];
        fv1 = sp78.y - arg2->m[3][1];
        fa0 = sp78.z - arg2->m[3][2];
        temp_fs0 = s0->unk24 - fv0;
        temp_fs1 = s0->unk28 - fv1;
        temp_fa1 = s0->unk2C - fa0;
        if (sUvChannelExports->func_uvchannel_rom_004014E8(arg0, temp_fs0, temp_fs1, temp_fa1,
                                                                s0->unk30)
            == 0) {
            continue;
        }
        if ((sp64->unk2C != 0) && (D_uvterra_rom_0040FBF0 != 0)
            && (func_uvterra_rom_0040CEA8(s0->unk38, temp_fs0, temp_fs1,
                                          sUvMathExports->uvSqrtf(SQ(temp_fs0) + SQ(temp_fs1)))
                == 0)) {
            continue;
        }

        // clang-format off
        if (s0 == D_8002D198) { \
            D_8002D19C = 1; \
        } else { \
            D_8002D19C = 2; \
        }
        // clang-format on
        sUvGfxStateExports->uvGfxStateDraw(&s0->unk0);
    }
}

s32 uvSobjGetIds(s32 arg0, s32 modelId, s32 **arg2) {
    ParsedUVTR *uvtr;
    s32 i;
    s32 j;
    UnkSobjDraw *sobj;
    ParsedUVCT *uvct;
    s32 idx;
    uvUnkTileStruct *temp_a3;

    PRINTF("sobjgetids\n");
    idx = 0;
    uvtr = uvGetLoadedFile('UVTR', arg0);
    if (uvtr == NULL) {
        return 0;
    }

    *arg2 = D_uvterra_rom_0040FC08;
    for (i = 0; i < (uvtr->unk18 * uvtr->unk19); i++) {
        temp_a3 = &uvtr->unk28[i];
        if (temp_a3 == NULL) {
            continue;
        }
        uvct = temp_a3->unk40;
        if (uvct == NULL) {
            continue;
        }

        for (j = 0; j < uvct->unk14; j++) {
            sobj = &uvct->unk10[j];
            if (modelId != sobj->modelId) {
                continue;
            }
            D_uvterra_rom_0040FC08[idx++] = ((temp_a3->unk44 & 0xFFF) << 0xC) | (j & 0xFFF);
            if (idx >= 0x80) {
                return 0x80;
            }
            // redundant assignment
            uvct = temp_a3->unk40;
        }
    }
    return idx;
}

void func_uvterra_rom_00407680(s32 arg0, f32 arg1) {
    D_uvterra_rom_0040FBA4[arg0] = 1.0f / arg1;
}

void uvSobjsDraw(s32 arg0, Mtx4F *arg1, u16 arg2, u16 arg3, UnkSobjDraw *arg4, u16 arg5) {
    ParsedUVMD *temp_v0_2;
    UnkSobjDraw *sobj;
    ParsedUVTR *uvtr;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 var_fv1;
    s32 i;
    Vec3F sp88;
    u8 temp_v0_3;
    f32 sp6C;

    PRINTF("sobjsdraw\n");
    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 7, &sp88, 0);
    sp88.x -= arg1->m[3][0];
    sp88.y -= arg1->m[3][1];
    sp88.z -= arg1->m[3][2];
    for (i = 0, sobj = arg4; i < arg5; i++, sobj++) {
        if (sobj->modelId != 0xFFFF) {
            if (!(sobj->unk18 & arg2)) {
                PRINTF("check model %d\n", sobj->modelId);
                continue;
            }
            temp_fs0 = sobj->unk8 - sp88.x;
            temp_fs1 = sobj->unkC - sp88.y;
            temp_fs2 = sobj->unk10 - sp88.z;
            if (!(sobj->unk18 & arg3)
                && !(sUvChannelExports->func_uvchannel_rom_004014E8(arg0, temp_fs0, temp_fs1,
                                                                         temp_fs2, sobj->unk14)
                     & 0xFF)) {
                continue;
            }

            // FAKE
            temp_fv0 = temp_fs2;
            uvtr = uvGetLoadedFile('UVTR', D_uvterra_rom_0040F77C[arg0]);

            if ((uvtr->unk2C) && (D_uvterra_rom_0040FBF0)
                && !(func_uvterra_rom_0040CEA8(
                    sobj->unk48, temp_fs0, temp_fs1,
                    sUvMathExports->uvSqrtf(SQ(temp_fs0) + SQ(temp_fs1))))) {
                continue;
            }
            if ((func_uvterra_rom_004072E0() != 0) && (sobj != D_8002D1A0)) {
                continue;
            }

            // clang-format off
            if (sobj == D_8002D1A0) {  \
                D_8002D19C = 1; \
            } else { \
                D_8002D19C = 2; \
            }
            // clang-format on
            temp_v0_2 = uvGetLoadedFile('UVMD', sobj->modelId);
            if ((temp_v0_2 == NULL)) {
                continue;
            }
            if (((temp_v0_2->unk20 != NULL) && (D_uvterra_rom_0040FBE0 != 0))) {
                continue;
            }

            sp6C = (SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fv0));
            if (D_uvterra_rom_0040FBA4[arg0] == 1.0f) {
                var_fv1 = sp6C;
            } else {
                var_fv1 = (sp6C * D_uvterra_rom_0040FBA4[arg0]) * D_uvterra_rom_0040FBA4[arg0];
            }
            temp_v0_3 = sUvModelExports->func_uvmodel_rom_00400608(temp_v0_2, var_fv1);
            if (temp_v0_3 == 0xFF) {
                continue;
            }

            sobj->unk2C = temp_v0_3;
            sobj->unk20 = temp_fs0;
            sobj->unk24 = temp_fs1;
            sobj->unk28 = arg1;
            if ((temp_v0_2->unk5 & 1) || ((temp_v0_3 & 0xFF) < temp_v0_2->unk7)) {
                if (temp_v0_2->unk0[temp_v0_3].unk9 != 0) {
                    func_uvterra_rom_0040D128(arg0, 1, arg1->m[3][0], arg1->m[3][1],
                                              func_uvterra_rom_00407E5C, sobj, sp6C);
                } else {
                    func_uvterra_rom_0040D128(arg0, 1, arg1->m[3][0], arg1->m[3][1],
                                              func_uvterra_rom_00407A94, sobj, sp6C);
                }
            } else if (temp_v0_2->unk0[temp_v0_3].unk9 != 0) {
                func_uvterra_rom_00407ED4(arg0, sobj);
            } else {
                func_uvterra_rom_00407B0C(arg0, sobj);
            }
        }
        // FAKE
        if (sobj) {
        }
    }
}

static const char D_uvterra_rom_0040D3AC[] = "check model aoi pass %d\n";
static const char D_uvterra_rom_0040D3C8[] = " check cull sphere\n";
static const char D_uvterra_rom_0040D3DC[] = " cull sphere pass\n";
static const char D_uvterra_rom_0040D3F0[] = "Vmask pass\n";
static const char D_uvterra_rom_0040D3FC[] = "draw model %d\n";
static const char D_uvterra_rom_0040D40C[] = "draw lod %d %f\n";
static const char D_uvterra_rom_0040D41C[] = "draw sorted\n";
static const char D_uvterra_rom_0040D42C[] = "draw\n";
static const char D_uvterra_rom_0040D434[] = "_sobjdrawsorted\n";
static const char D_uvterra_rom_0040D448[] = "_sobjdraw\n";
static const char D_uvterra_rom_0040D454[] = "_sobjbilldraw\n";
static const char D_uvterra_rom_0040D464[] = "sobjposm\n";
static const char D_uvterra_rom_0040D470[] = "sobjprops\n";
static const char D_uvterra_rom_0040D47C[] = "sobjgetposm\n";
static const char D_uvterra_rom_0040D48C[] = "sobjgetmodel\n";
static const char D_uvterra_rom_0040D49C[] = "sobjmodel\n";
static const char D_uvterra_rom_0040D4A8[] = "sobjgetpt\n";
static const char D_uvterra_rom_0040D4B4[] = "sobjgetsph\n";
static const char D_uvterra_rom_0040D4C0[] = "checking tile %d,%d\n";
static const char D_uvterra_rom_0040D4D8[] = "  aoi = 0x%x\n";
static const char D_uvterra_rom_0040D4E8[] = "  sobj %d\n";
static const char D_uvterra_rom_0040D4F4[] = "     passed aoi\n";
static const char D_uvterra_rom_0040D508[] = "     passed box\n";
static const char D_uvterra_rom_0040D51C[] = "     checking sphere %.1f %.1f %.1f %f  with %.1f %.1f %.1f %.1f\n";
static const char D_uvterra_rom_0040D560[] = "     passed sphere\n";
static const char D_uvterra_rom_0040D574[] = "     has bboxs/surfs\n";
static const char D_uvterra_rom_0040D58C[] = "     has no surfaces/boxs\n";
static const char D_uvterra_rom_0040D5A8[] = "sobjgetseg\n";
static const char D_uvterra_rom_0040D5B4[] = "Tile box i:(%d %d) j:(%d %d)\n";
static const char D_uvterra_rom_0040D5D4[] = "   checking sobj %d\n";
static const char D_uvterra_rom_0040D5EC[] = "        passed sphere check\n";
static const char D_uvterra_rom_0040D60C[] = "           no surfs or boxs\n";
static const char D_uvterra_rom_0040D62C[] = "_seginsobjmboxs\n";
static const char D_uvterra_rom_0040D640[] = "           checking box for part %d\n";
static const char D_uvterra_rom_0040D668[] = "           passed visible check\n";
static const char D_uvterra_rom_0040D68C[] = "sobjgetprops\n";
static const char D_uvterra_rom_0040D69C[] = "_sobjvalid\n";
 

// uvSobjGetLODIndex?
s32 func_uvterra_rom_00407A80(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

void func_uvterra_rom_00407A94(s32 arg0, UnkSobjDraw *sobj) {
    s32 pad[2];
    Mtx4F mtx;

    sUvFMtxExports->func_uvfmtx_rom_00400370(&mtx, sobj->unk28);
    sUvFMtxExports->uvGfxMtxViewLoad(&mtx, G_MTX_PUSH | G_MTX_LOAD);
    func_uvterra_rom_00407B0C(arg0, sobj);
    sUvFMtxExports->uvGfxMtxFViewPop();
}

void func_uvterra_rom_00407B0C(UNUSED s32 arg0, UnkSobjDraw *sobj) {
    ParsedUVMD *uvmd;
    ParsedUVMD_1 *temp_fp;
    s32 temp_s2;
    s32 var_s0;
    s32 j;
    s32 var_s3;
    s32 i;
    s32 temp_s1;
    s32 v1;
    Mtx4F spDC;
    s32 padD4;
    uvModelLOD *modelLod;
    s32 padD0;
    Mtx4F *spCC;
    Mtx4F sp8C;

    uvmd = uvGetLoadedFile('UVMD', sobj->modelId);
    v1 = sobj->unk2C;
    spCC = sobj->unk28;
    if (sobj == D_8002D1A0) {
        D_8002D19C = 1;
    } else {
        D_8002D19C = 2;
    }
    var_s3 = 0;
    temp_fp = &uvmd->unk0[v1];
    for (i = 0; i < temp_fp->unk8; i++) {
        modelLod = &temp_fp->unk0[i];
        if ((sobj->unk1C & (1 << i)) || (((modelLod->unk7 & 1) != 0))) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }

        if (var_s0 == 0) {
            if (modelLod->unk7 & 2) {
                temp_s2 = temp_fp->unk0[i].unk6 - temp_fp->unk0[i + 1].unk6;
                for (j = 0; j < temp_s2; j++) {
                    sUvFMtxExports->uvGfxMtxFViewPop();
                    var_s3--;
                }
                continue;
            }
        }
        var_s3 += 1;
        sUvIMtxExports->func_uvimtx_rom_0040062C(&sobj->unk4[i], 1U);
        if (var_s0 != 0) {
            if (modelLod->unk20 != 0) {
                sUvFMtxExports->uvMat4CopyL2F(&spDC, *sobj->unk4);
                spDC.m[3][0] += spCC->m[3][0];
                spDC.m[3][1] += spCC->m[3][1];
                spDC.m[3][2] += spCC->m[3][2];
                sUvFMtxExports->func_uvfmtx_rom_00400370(&sp8C, &spDC);
                sUvGfxStateExports->func_uvgfxstate_rom_0040049C(&sp8C, 1);
            }
            temp_s1 = modelLod->unk4;
            j = 0;
            if (temp_s1 > 0) {
                do {
                    sUvGfxStateExports->uvGfxStateDraw(&modelLod->stateTable[j]);
                    j++;
                } while (j != temp_s1);
            }
            if ((i + 1) == temp_fp->unk8) {
                break;
            }

            temp_s2 = temp_fp->unk0[i].unk6 - temp_fp->unk0[i + 1].unk6;
            for (j = 0; j <= temp_s2; j++) {
                var_s3--;
                sUvFMtxExports->uvGfxMtxFViewPop();
            }
        }
    }

    for (i = 0; i < var_s3; i++) {
        sUvFMtxExports->uvGfxMtxFViewPop();
    }
}

void func_uvterra_rom_00407E5C(s32 arg0, UnkSobjDraw *sobj) {
    s32 pad[1];
    Mtx4F sp1C;

    sUvFMtxExports->func_uvfmtx_rom_00400370(&sp1C, sobj->unk28);
    sUvFMtxExports->uvGfxMtxViewLoad(&sp1C, 3U);
    func_uvterra_rom_00407ED4(arg0, sobj);
    sUvFMtxExports->uvGfxMtxFViewPop();
}

void func_uvterra_rom_00407ED4(s32 arg0, UnkSobjDraw *arg1) {
    uvModelLOD *temp_s4;
    ParsedUVMD_1 *spF8;
    s32 temp_s1;
    uvMtx *spF0;
    Mtx spB0;
    ParsedUVMD *temp_a0;
    f32 temp_fv0;
    s32 temp_s2;
    s32 var_fp;
    s32 var_s0;
    s32 j;
    s32 i;
    u8 a1;
    s32 temp;
    f32 sp88;
    s32 var_s3;
    f32 sp80;
    f32 sp7C;

    temp_a0 = uvGetLoadedFile('UVMD', arg1->modelId);
    a1 = arg1->unk2C;
    sp88 = temp_a0->unk10;
    sp80 = arg1->unk20;
    sp7C = arg1->unk24;
    if (arg1 == D_8002D1A0) {
        D_8002D19C = 1;
    } else {
        D_8002D19C = 2;
    }
    spF8 = &temp_a0->unk0[a1];
    spF0 = (uvMtx*)arg1->unk4;
    spB0.m[0][0] = spF0->m[0][0];
    spB0.m[0][2] = spF0->m[0][2];
    spB0.m[2][0] = spF0->m[2][0];
    spB0.m[2][2] = spF0->m[2][2];
    temp_fv0 = sUvMathExports->uvSqrtf(SQ(sp80) + SQ(sp7C));
    if (temp_fv0 != 0.0f) {
        sp80 /= temp_fv0;
        sp7C /= temp_fv0;
    }
    temp_fv0 = arg1->unk30;

    temp = ((((-sp7C * temp_fv0) / sp88) * 65536.0f) + 0.5f);
    spF0->u.i[0][0] = temp >> 0x10;
    spF0->u.i[1][1] = temp >> 0x10;
    spF0->u.f[0][0] = temp & 0xFFFF;
    spF0->u.f[1][1] = temp & 0xFFFF;
    temp = ((((sp80 * temp_fv0) / sp88) * 65536.0f) + 0.5f);
    spF0->u.i[0][1] = temp >> 0x10;
    spF0->u.f[0][1] = (temp & 0xFFFF);
    temp = ((((-sp80 * temp_fv0) / sp88) * 65536.0f) + 0.5f);
    spF0->u.i[1][0] = temp >> 0x10;
    spF0->u.f[1][0] = (temp & 0xFFFF);

    var_s3 = 0;
    for (i = 0; i < spF8->unk8; i++) {
        temp_s4 = &spF8->unk0[i];
        if ((arg1->unk1C & (1 << i)) || (((temp_s4->unk7 & 1) != 0))) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }

        if (var_s0 == 0) {
            if (temp_s4->unk7 & 2) {
                temp_s2 = spF8->unk0[i].unk6 - spF8->unk0[i + 1].unk6;
                for (j = 0; j < temp_s2; j++) {
                    sUvFMtxExports->uvGfxMtxFViewPop();
                    var_s3 -= 1;
                }
                continue;
            }
        }
        var_s3++;
        sUvIMtxExports->uvIMtxPush(arg1->unk4[i], 1U);
        if (var_s0 != 0) {
            temp_s1 = temp_s4->unk4;
            j = 0;
            if (temp_s1 > 0) {
                do {
                    sUvGfxStateExports->uvGfxStateDraw(temp_s4->stateTable + j);
                    j++;
                } while (j != temp_s1);
            }
        }
        if ((i + 1) == spF8->unk8) {
            break;
        }

        temp_s2 = spF8->unk0[i].unk6 - spF8->unk0[i + 1].unk6;
        for (j = 0; j <= temp_s2; j++) {
            sUvFMtxExports->uvGfxMtxFViewPop();
            var_s3--;
        }
    }
    for (i = 0; i < var_s3; i++) {
        sUvFMtxExports->uvGfxMtxFViewPop();
    }
    spF0->m[0][0] = spB0.m[0][0];
    spF0->m[0][2] = spB0.m[0][2];
    spF0->m[2][0] = spB0.m[2][0];
    spF0->m[2][2] = spB0.m[2][2];
}

void uvSobjPosm(s32 contour, s32 arg1, Mtx4F *arg2) {
    static s32 D_uvterra_rom_0040D714 = 0; // needs to be function static
    UnkSobjDraw *sobj;
    ParsedUVMD *uvmd;
    Mtx4F sp50;
    s32 pad[3];
    f32 sp40;
    f32 temp_fa0;
    f32 sp38;
    f32 temp_ft4;
    f32 temp_fa1;

    sobj = func_uvterra_rom_0040AC14(contour);
    if (sobj == NULL || sobj->modelId == 0xFFFF) {
        return;
    }

    sUvFMtxExports->uvMat4Mul(&sp50, &sobj->unk44->unk4C, arg2);
    if (arg1 == 0) {
        if (0.01f < ABS_DIFF(sobj->unk8, sp50.m[3][0])
            || 0.01f < ABS_DIFF(sobj->unkC, sp50.m[3][1])
            || 0.01f < ABS_DIFF(sobj->unk10, sp50.m[3][2])) {
            if (D_uvterra_rom_0040D714 == 0) {
                D_uvterra_rom_0040D714 += 1;
            }
        }
    }
    uvmd = uvGetLoadedFile('UVMD', sobj->modelId);
    if (uvmd == NULL) {
        return;
    }
    if (arg1 == 0) {
        temp_fa1 = sobj->unk30 / uvmd->unk10;
        temp_ft4 = sobj->unk34 / uvmd->unk10;
        sp40 = sobj->unk30;
        sp38 = sobj->unk34;
        if ((temp_fa1 != 1.0f) && (temp_ft4 != 1.0f)) {
            sUvFMtxExports->uvMat4Scale(&sp50, temp_fa1, temp_fa1, temp_ft4);
        }
    } else {
        sp40 = uvmd->unk10;
        sp38 = uvmd->unk10;
    }
    sp50.m[3][0] *= sp40;
    sp50.m[3][1] *= sp40;
    sp50.m[3][2] *= sp38;
    sUvFMtxExports->uvMat4CopyF2L(&sobj->unk4[arg1], &sp50);
}

#ifndef NO_VA_ARGS_FUNCTIONS
void uvSobjProps(s32 uvct, ...) {
    va_list args;
    UnkSobjDraw *sobj;
    s32 prop;

    sobj = func_uvterra_rom_0040AC14(uvct);
    va_start(args, uvct);
    if (sobj == NULL) {
        return;
    }

    while (TRUE) {
        prop = va_arg(args, s32);
        switch (prop) {
            case 0:
                return;
            case 2:
                sobj->unk1C &= ~(1 << va_arg(args, s32));
                break;
            case 3:
                sobj->unk1C |= 1 << va_arg(args, s32);
                break;
            case 1:
                sobj->unk1C = va_arg(args, s32);
                break;
        }
    }
}
#endif

void func_uvterra_rom_00408614(s32 contour, s32 arg1, Mtx4F *arg2) {
    f32 sp74;
    f32 temp_fa1;
    f32 sp6C;
    f32 sp68;
    ParsedUVMD *uvmd;
    UnkSobjDraw *sobj;
    uvUnkTileStruct *sp5C;

    sobj = func_uvterra_rom_0040AC14(contour);
    if (sobj == NULL) {
        return;
    }
    if (sobj->modelId == 0xFFFF) {
        return;
    }

    sp5C = sobj->unk44;
    sUvFMtxExports->uvMat4CopyL2F(arg2, sobj->unk4[arg1]);
    uvmd = uvGetLoadedFile('UVMD', sobj->modelId);
    if (uvmd == NULL) {
        return;
    }

    if (arg1 == 0) {
        temp_fa1 = uvmd->unk10 / sobj->unk30;
        sp68 = (uvmd->unk10 / sobj->unk34);
        sp74 = 1.0f / sobj->unk30;
        sp6C = 1.0f / sobj->unk34;
        if ((temp_fa1 != 1.0f) || (temp_fa1 != 1.0f)) {
            sUvFMtxExports->uvMat4Scale(arg2, temp_fa1, temp_fa1, sp68);
        }
    } else {
        sp74 = 1.0f / uvmd->unk10;
        sp6C = 1.0f / uvmd->unk10;
    }
    arg2->m[3][0] *= sp74;
    arg2->m[3][1] *= sp74;
    arg2->m[3][2] *= sp6C;
    arg2->m[3][0] += sp5C->unk0.m[3][0];
    arg2->m[3][1] += sp5C->unk0.m[3][1];
    arg2->m[3][2] += sp5C->unk0.m[3][2];
}

u16 func_uvterra_rom_004087D8(s32 contour) {
    UnkSobjDraw *sobj;

    sobj = func_uvterra_rom_0040AC14(contour);
    if (sobj == NULL) {
        return 0xFFFFU;
    }
    return sobj->modelId;
}

void uvSobjModel(s32 contour, s32 modelId) {
    ParsedUVMD *uvmd;
    s32 pad20;
    UnkSobjDraw *sobj;
    s32 pad18;

    sobj = func_uvterra_rom_0040AC14(contour);
    if (sobj == NULL) {
        return;
    }

    if (modelId == 0xFFFF) {
        sobj->modelId = 0xFFFF;
        return;
    }

    uvmd = uvGetLoadedFile('UVMD', modelId);
    if (uvmd == NULL) {
        return;
    }

    uvGetLoadedFile('UVMD', sobj->modelId);
    if (uvmd == NULL) {
        return;
    }

    sobj->modelId = modelId;
}

s32 func_uvterra_rom_0040888C(s32 terraId, f32 arg1, f32 arg2, f32 arg3) {
    s16 sp86;
    s16 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    u32 i;
    UnkSobjDraw *sobj;
    uvUnkTileStruct *temp_s3;
    ParsedUVTR *uvtr;
    ParsedUVCT *uvct;
    ParsedUVMD *uvmd;
    s32 v0;

    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        return -1;
    }
    if (func_uvterra_rom_0040B8C0(uvtr, arg1, arg2, arg3, &sp80, &sp7C, &sp78, &sp84, &sp86, 0U) == 0) {
        return -1;
    }
    temp_s3 = &uvtr->unk28[(u16) sp84];
    uvct = temp_s3->unk40;
    if (uvct == NULL) {
        return -1;
    }

    for (i = 0; i < uvct->unk14; i++) {
        sobj = &uvct->unk10[i];
        if (!(sobj->unk40 & 1)) {
            continue;
        }

        if ((sobj->modelId == 0xFFFF)) {
            continue;
        }

        if (!((u16) sp86 & sobj->unk18)) {
            continue;
        }

        if (sUvIntersectExports->func_uvintersect_rom_00400460(sp80, sp7C, sp78, sobj->unk8,
                                                                  sobj->unkC, sobj->unk10, sobj->unk14)
            != 0) {
            uvmd = uvGetLoadedFile('UVMD', (s32) sobj->modelId);
            if (uvmd == NULL) {
                // redundant statement
                uvct = temp_s3->unk40;
                continue;
            }
            *D_uvterra_rom_0040F78C = (temp_s3->unk44 << 0xC) | i;
            if (uvmd->unk5 & 2) {
                if (func_uvterra_rom_0040A43C(sp80, sp7C, sp78, sobj) >= 0) {
                    return ((temp_s3->unk44 & 0xFFF) << 0xC) | (i & 0xFFF);
                }
            } else {
                return ((temp_s3->unk44 & 0xFFF) << 0xC) | (i & 0xFFF);
            }
        }
        // redundant statement
        uvct = temp_s3->unk40;
    }
    return -1;
}

s32 func_uvterra_rom_00408AD8(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 **arg5,
                              f32 **arg6, Vec3F **arg7) {
    s32 sp114;
    s32 sp110;
    s32 var_v1;
    s32 var_s0;
    s32 sp104;
    s32 sp100;
    s32 spFC;
    uvUnkTileStruct *temp_s1;
    query_78 *var_v1_2;
    s32 spF0;
    f32 spEC;
    f32 spE8;
    UnkSobjDraw *sobj;
    ParsedUVMD *uvmd;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    u16 spCE;
    ParsedUVTR *uvtr;
    ParsedUVCT *uvct;
    f32 temp_fs2;
    f32 temp_fv1;
    f32 temp_fs3;
    Vec3F *temp_s0;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs4;
    s32 k;
    s32 pad;

    spF0 = 0;
    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        return 0;
    }
    if ((arg1 + arg4) < uvtr->unk0.unk0) {
        return 0;
    }
    if (uvtr->unk0.unkC < (arg1 - arg4)) {
        return 0;
    }
    if ((arg2 + arg4) < uvtr->unk0.unk4) {
        return 0;
    }
    if (uvtr->unk0.unk10 < (arg2 - arg4)) {
        return 0;
    }
    var_v1 = (s32) (((arg1 - arg4) - uvtr->unk0.unk0) / uvtr->unk1C);
    sp104 = (s32) (((arg1 + arg4) - uvtr->unk0.unk0) / uvtr->unk1C);
    sp100 = (s32) (((arg2 - arg4) - uvtr->unk0.unk4) / uvtr->unk20);
    spFC = (s32) (((arg2 + arg4) - uvtr->unk0.unk4) / uvtr->unk20);
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    if ((uvtr->unk18 - 1) < sp104) {
        sp104 = uvtr->unk18 - 1;
    }
    if (sp100 < 0) {
        sp100 = 0;
    }
    if ((uvtr->unk19 - 1) < spFC) {
        spFC = uvtr->unk19 - 1;
    }
    *D_uvterra_rom_0040F790 = 0;
    spD8 = uvtr->unk0.unk0;
    spDC = uvtr->unk1C + spD8;
    for (sp114 = var_v1; sp114 <= sp104; sp114++) {
        spD0 = uvtr->unk0.unk4;
        spD4 = uvtr->unk20 + spD0;
        for (sp110 = sp100; sp110 <= spFC; sp110++) {
            s32 v0 = (uvtr->unk18 * sp110) + sp114;
            temp_s1 = &uvtr->unk28[v0];
            if (temp_s1 == NULL) {
                continue;
            }

            uvct = temp_s1->unk40;
            if (uvct == NULL) {
                continue;
            }

            if ((temp_s1->unk48 < (arg3 - arg4))) {
                continue;
            }

            spEC = arg1 - temp_s1->unk0.m[3][0];
            spE8 = arg2 - temp_s1->unk0.m[3][1];
            temp_fs4 = arg3 - temp_s1->unk0.m[3][2];
            spCE = func_uvterra_rom_0040BBC0(spEC, spE8, arg4, spD8, spDC, spD0, spD4);

            for (k = 0; k < uvct->unk14; k++) {
                sobj = &uvct->unk10[k];

                if (!(sobj->unk40 & 1)) {
                    continue;
                }

                if (sobj->modelId == 0xFFFF) {
                    continue;
                }

                if (!(sobj->unk18 & spCE)) {
                    continue;
                }

                if (sobj->unk3C < (temp_fs4 - arg4)) {
                    continue;
                }
                temp_fs0 = sobj->unk14;
                temp_fs1 = sobj->unk8;
                temp_fs2 = sobj->unkC;
                temp_fs3 = sobj->unk10;

                if (((arg1 + arg4) + temp_fs0) < temp_fs1) {
                    continue;
                }

                if (temp_fs1 < ((arg1 - arg4) - temp_fs0)) {
                    continue;
                }

                if (((arg2 + arg4) + temp_fs0) < temp_fs2) {
                    continue;
                }

                if (temp_fs2 < ((arg2 - arg4) - temp_fs0)) {
                    continue;
                }

                if ((arg3 + arg4 + temp_fs0) < temp_fs3) {
                    continue;
                }

                if (temp_fs3 < ((arg3 - arg4) - temp_fs0)) {
                    continue;
                }

                if (sUvIntersectExports->func_uvintersect_rom_004004C4(
                        spEC, spE8, temp_fs4, arg4, temp_fs1, temp_fs2, temp_fs3, temp_fs0)
                    == 0) {
                    continue;
                }
                uvmd = uvGetLoadedFile('UVMD', sobj->modelId);
                if (uvmd == NULL) {
                    continue;
                }
                *D_uvterra_rom_0040F78C = k | (temp_s1->unk44 << 0xC);
                if (spF0 == 0) {
                    sUvQueryExports->uvQueryGetProps(0, 1, &spF0, 0);
                }
                if (uvmd->unk5 & 6) {
                    var_s0 = *D_uvterra_rom_0040F790;
                    func_uvterra_rom_0040A08C(spEC, spE8, temp_fs4, arg4, sobj);
                    var_v1_2 = sUvQueryExports->func_uvquery_rom_004004CC() + var_s0;
                    while (var_s0 < *D_uvterra_rom_0040F790) {
                        if (spF0 != 0) {
                            var_v1_2->unk0.x += temp_s1->unk0.m[3][0];
                            var_v1_2->unk0.y += temp_s1->unk0.m[3][1];
                            var_v1_2->unk0.z += temp_s1->unk0.m[3][2];
                            var_v1_2->unkC.y += temp_s1->unk0.m[3][0];
                            var_v1_2->unkC.x += temp_s1->unk0.m[3][1];
                            var_v1_2->unkC.z += temp_s1->unk0.m[3][2];
                            var_v1_2->unk18.x += temp_s1->unk0.m[3][0];
                            var_v1_2->unk18.y += temp_s1->unk0.m[3][1];
                            var_v1_2->unk18.z += temp_s1->unk0.m[3][2];
                            var_v1_2++;
                        }
                        var_s0++;
                    }
                    if (*D_uvterra_rom_0040F790
                        >= sUvQueryExports->func_uvquery_rom_00400224()) {
                        sp110 = spFC + 1;
                        sp114 = sp104 + 1;
                        break;
                    }
                } else {
                    D_uvterra_rom_0040F784[*D_uvterra_rom_0040F790] = *D_uvterra_rom_0040F78C;
                    temp_s0 = &D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790];
                    temp_s0->x = spEC - temp_fs1;
                    temp_s0->y = spE8 - temp_fs2;
                    temp_s0->z = temp_fs4 - temp_fs3;
                    temp_fv1 = (arg4
                                - (sUvMathExports->uvSqrtf(SQ(temp_s0->x) + SQ(temp_s0->y)
                                                                   + SQ(temp_s0->z))
                                   - temp_fs0))
                               / arg4;
                    if (temp_fv1 < 0.0f) {
                        D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = temp_fv1;
                    } else {
                        D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = 0.0f;
                    }
                    D_uvterra_rom_0040F794[*D_uvterra_rom_0040F790] |= 1;
                    sUvFVecExports->uvVec3FNormalize(temp_s0, temp_s0);
                    if (++*D_uvterra_rom_0040F790
                        >= sUvQueryExports->func_uvquery_rom_00400224()) {
                        sp110 = spFC + 1;
                        sp114 = sp104 + 1;
                        break;
                    }
                }
            }
            if (spFC >= sp110) {
                spD0 += uvtr->unk20;
                spD4 += uvtr->unk20;
            }
        }
        if (sp104 >= sp114) {
            spD8 += uvtr->unk1C;
            spDC += uvtr->unk20;
        }
    }
    *arg5 = D_uvterra_rom_0040F784;
    *arg6 = D_uvterra_rom_0040F780;
    *arg7 = D_uvterra_rom_0040F788;
    return *D_uvterra_rom_0040F790;
}
s32 func_uvterra_rom_00409394(s32 terraId, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              s32 **arg7, f32 **arg8, Vec3F **arg9) {
    u16 i;
    u16 j;
    uvUnkTileStruct *temp_s1;
    ParsedUVTR *uvtr;
    UnkSobjDraw *sobj;
    f32 var_fs1;
    f32 var_fs2;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    u16 sp1BA;
    u16 sp1B8;
    u16 sp1B6;
    u16 sp1B4;
    f32 var_fs3;
    f32 var_fs4;
    s32 var_v0;
    s32 sp1A4;
    s32 sp1A0;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_ft4;
    f32 var_ft5;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp150;
    f32 sp14C;
    s32 var_v1;
    f32 temp_fs2;
    f32 temp_fs3;
    ParsedUVMD *temp_v0_4;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    u16 temp_t0;
    u16 sp118;
    f32 temp_fs0;
    s32 temp;
    f32 sp130;
    u8 sp10F;
    u8 sp10E;
    u8 temp_s0;
    u8 temp_t3;
    f32 ft4;
    f32 ft5;
    f32 fs2;
    f32 fv1;
    s32 pad;

    *D_uvterra_rom_0040F790 = 0;
    uvtr = uvGetLoadedFile('UVTR', terraId);
    if (uvtr == NULL) {
        return 0;
    }
    if ((arg1 == arg4) && (arg2 == arg5) && (arg3 == arg6)) {
        if (arg6 != 0.0f) {
            arg6 *= 1.0001f;
        } else {
            arg6 += 0.0001f;
        }
    }

    sp18C = uvtr->unk1C;
    sp188 = uvtr->unk20;
    sp160 = arg1;
    sp15C = arg2;
    sp158 = arg4;
    sp154 = arg5;
    temp_fs2 = arg4 - arg1;
    temp_fs3 = arg5 - arg2;
    temp_fs0 = arg6 - arg3;
    sUvIntersectExports->func_uvintersect_rom_00401A2C(&arg1, &arg2, &arg4, &arg5, uvtr->unk0.unk0,
                                                          uvtr->unk0.unkC, uvtr->unk0.unk4,
                                                          uvtr->unk0.unk10);
    if (arg1 == uvtr->unk0.unkC) {
        arg1 -= 0.0001f * sp18C;
    }
    if (arg4 == uvtr->unk0.unkC) {
        arg4 -= 0.0001f * sp18C;
    }
    if (arg2 == uvtr->unk0.unk10) {
        arg2 -= 0.0001f * sp188;
    }
    if (arg5 == uvtr->unk0.unk10) {
        arg5 -= 0.0001f * sp188;
    }

    if ((sp160 != arg1) && (temp_fs2 != 0.0f)) {
        arg3 += temp_fs0 * ((arg1 - sp160) / temp_fs2);
    } else if ((sp15C != arg2) && (temp_fs3 != 0.0f)) {
        arg3 += temp_fs0 * ((arg2 - sp15C) / temp_fs3);
    }
    if ((sp158 != arg4) && (temp_fs2 != 0.0f)) {
        arg6 += temp_fs0 * ((arg4 - sp158) / temp_fs2);
    } else if ((sp154 != arg5) && (temp_fs3 != 0.0f)) {
        arg6 += temp_fs0 * ((arg5 - sp154) / temp_fs3);
    }

    if ((arg1 == arg4) && (arg2 == arg5) && (arg3 == arg6)) {
        temp = func_uvterra_rom_0040888C(terraId, arg1, arg2, arg3);
        if (temp == -1) {
            *arg7 = NULL;
            *arg8 = NULL;
            *arg9 = NULL;
            return 0;
        }
        *D_uvterra_rom_0040F784 = temp;
        *D_uvterra_rom_0040F780 = 0.0f;
        D_uvterra_rom_0040F788->x = 0.0f;
        D_uvterra_rom_0040F788->y = 0.0f;
        D_uvterra_rom_0040F788->z = 1.0f;
        *arg7 = D_uvterra_rom_0040F784;
        *arg8 = D_uvterra_rom_0040F780;
        *arg9 = D_uvterra_rom_0040F788;
    }
    temp_s0 =
        func_uvterra_rom_0040B8C0(uvtr, arg1, arg2, arg3, &sp1D0, &sp1CC, &sp1C8, &sp1BA, &sp1B6, 0);
    temp_t3 =
        func_uvterra_rom_0040B8C0(uvtr, arg4, arg5, arg6, &sp1C4, &sp1C0, &sp1BC, &sp1B8, &sp1B4, 0);
    if ((temp_s0 == 0) && (temp_t3 == 0)) {
        *arg7 = NULL;
        *arg8 = NULL;
        return 0;
    }
    if (sp1BA == sp1B8) {
        sp10F = TRUE;
        if (sp1B6 == sp1B4) {
            sp10E = TRUE;
        } else {
            sp10E = FALSE;
        }
    } else {
        sp10F = FALSE;
        sp10E = FALSE;
    }
    if (sp10F) {
        var_v1 = var_v0 = (s32) ((arg1 - uvtr->unk0.unk0) / sp18C);
        sp1A4 = sp1A0 = (s32) ((arg2 - uvtr->unk0.unk4) / sp188);
    } else {
        var_ft5 = arg1;
        var_ft4 = arg1;
        var_fa1 = arg2;
        var_fa0 = arg2;
        if (arg4 < arg1) {
            var_ft4 = arg4;
        } else {
            var_ft5 = arg4;
        }
        if (arg5 < arg2) {
            var_fa0 = arg5;
        } else {
            var_fa1 = arg5;
        }

        var_v1 = (s32) ((var_ft4 - uvtr->unk0.unk0) / sp18C);
        var_v0 = (s32) ((var_ft5 - uvtr->unk0.unk0) / sp18C);
        sp1A4 = (s32) ((var_fa0 - uvtr->unk0.unk4) / sp188);
        sp1A0 = (s32) ((var_fa1 - uvtr->unk0.unk4) / sp188);
        if (var_v1 < 0) {
            var_v1 = 0;
        }

        if (var_v0 > uvtr->unk18 - 1) {
            var_v0 = uvtr->unk18 - 1;
        }
        if (sp1A4 < 0) {
            sp1A4 = 0;
        }

        if (sp1A0 > uvtr->unk19 - 1) {
            sp1A0 = uvtr->unk19 - 1;
        }
    }

    if (arg3 < arg6) {
        sp130 = arg3;
    } else {
        sp130 = arg6;
    }

    for (i = var_v1; i <= var_v0; i++) {
        for (j = sp1A4; j <= sp1A0; j++) {
            sp118 = (j * uvtr->unk18) + i;
            temp_s1 = &uvtr->unk28[sp118];
            if (temp_s1 == NULL) {
                continue;
            }
            if (temp_s1->unk40 == NULL) {
                continue;
            }
            if (temp_s1->unk48 < sp130) {
                continue;
            }
            sp170 = arg1;
            sp168 = arg2;
            sp150 = arg3;
            sp16C = arg4;
            // clang-format off
            sp164 = arg5; \
            sp14C = arg6;
            // clang-format on

            sp180 = temp_s1->unk0.m[3][0] - (0.5f * sp18C);
            sp17C = temp_s1->unk0.m[3][0] + (0.5f * sp18C);
            sp174 = temp_s1->unk0.m[3][1] + (0.5f * sp188);
            sp178 = temp_s1->unk0.m[3][1] - (0.5f * sp188);

            if (!sp10F) {
                sUvIntersectExports->func_uvintersect_rom_00401CB0(
                    &sp170, &sp168, &sp150, &sp16C, &sp164, &sp14C, sp180, sp17C, sp178, sp174);
            }

            var_fs1 = sp170 - temp_s1->unk0.m[3][0];
            var_fs2 = sp16C - temp_s1->unk0.m[3][0];
            var_fs3 = sp168 - temp_s1->unk0.m[3][1];
            var_fs4 = sp164 - temp_s1->unk0.m[3][1];

            if ((sp170 == sp16C) && (sp168 == sp164) && (sp150 == sp14C)) {
                continue;
            }

            if (!sp10E) {
                sp1B4 = func_uvterra_rom_0040BD38(sp170, sp168, sp16C, sp164, sp1D0, sp1CC, sp1C4,
                                                  sp1C0, sp180, sp17C, sp174, sp178, temp_s1);
            }

            for (temp_t0 = 0; temp_t0 < temp_s1->unk40->unk14; temp_t0++) {
                sobj = &temp_s1->unk40->unk10[temp_t0];
                if (!(sobj->unk40 & 1)) {
                    continue;
                }
                if (sobj->modelId == 0xFFFF) {
                    continue;
                }
                if (!(sp1B4 & sobj->unk18)) {
                    continue;
                }
                if ((sobj->unk3C + temp_s1->unk0.m[3][2]) < sp130) {
                    continue;
                }

                ft4 = sobj->unk8;
                ft5 = sobj->unkC;
                fs2 = sobj->unk10;
                fv1 = sobj->unk14;

                if (ft4 + fv1 < MIN(var_fs1, var_fs2)) {
                    continue;
                }
                if (ft4 - fv1 > MAX(var_fs1, var_fs2)) {
                    continue;
                }
                if (ft5 + fv1 < MIN(var_fs3, var_fs4)) {
                    continue;
                }
                if (ft5 - fv1 > MAX(var_fs3, var_fs4)) {
                    continue;
                }
                if (fs2 + fv1 < MIN(sp150, sp14C)) {
                    continue;
                }
                if (fs2 - fv1 > MAX(sp150, sp14C)) {
                    continue;
                }

                if (sUvIntersectExports->func_uvintersect_rom_00400144(
                        var_fs1, var_fs3, sp150, var_fs2, var_fs4, sp14C, ft4, ft5, fs2, fv1, &sp184)
                    != 0) {
                    temp_v0_4 = uvGetLoadedFile('UVMD', sobj->modelId);
                    if (temp_v0_4 == NULL) {
                        continue;
                    }
                    if (temp_v0_4->unk5 & 0x70) {
                        continue;
                    }
                    *D_uvterra_rom_0040F78C = (temp_s1->unk44 << 0xC) | temp_t0;
                    if (!(temp_v0_4->unk5 & 6)) {
                        if (*D_uvterra_rom_0040F790
                            >= sUvQueryExports->func_uvquery_rom_00400224()) {
                            break;
                        }
                        D_uvterra_rom_0040F784[*D_uvterra_rom_0040F790] = *D_uvterra_rom_0040F78C;
                        D_uvterra_rom_0040F780[*D_uvterra_rom_0040F790] = sp184;
                        sUvIntersectExports->func_uvintersect_rom_00400700(
                            arg1, arg2, arg3, arg4, arg5, arg6, sp184,
                            temp_s1->unk0.m[3][0] + sobj->unk8, temp_s1->unk0.m[3][1] + sobj->unkC,
                            temp_s1->unk0.m[3][2] + sobj->unk10,
                            &D_uvterra_rom_0040F788[*D_uvterra_rom_0040F790]);
                        *D_uvterra_rom_0040F790 += 1;
                    } else {
                        func_uvterra_rom_0040A79C(var_fs1, var_fs3, sp150, var_fs2, var_fs4, sp14C,
                                                  sobj);
                    }
                }
            }
        }
    }

    *arg7 = D_uvterra_rom_0040F784;
    *arg8 = D_uvterra_rom_0040F780;
    *arg9 = D_uvterra_rom_0040F788;

    sUvQueryExports->uvQueryDoSorting();
    return *D_uvterra_rom_0040F790;
}

s16 func_uvterra_rom_0040A08C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, UnkSobjDraw* sobj) {
    s16 sp106;
    s16 sp104;
    ParsedUVMD_1* temp_fp;
    f32 temp_fs0;
    f32 temp_fs1;
    s16 temp_s1;
    ParsedUVMD* uvmd;
    s16 j;
    s16 var_s2;
    Mtx4F spAC;
    s16 i;
    s32 var_s0;
    uvModelLOD* modelLod;

    uvmd = uvGetLoadedFile('UVMD', sobj->modelId);
    temp_fp = uvmd->unk0;
    sp104 = temp_fp->unk8;
    sp106 = -1;
    sUvModelExports->uvModelMtxStackReset();
    var_s2 = 0;
    for (i = 0; i < sp104; i++) {
        if (*D_uvterra_rom_0040F790 >= sUvQueryExports->func_uvquery_rom_00400224()) {
            return sUvQueryExports->func_uvquery_rom_00400224();
        }
        modelLod = &temp_fp->unk0[i];
        if ((sobj->unk1C & (1 << i)) || (((modelLod->unk7 & 1) != 0))) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }
        
        if ((var_s0) || !(modelLod->unk7 & 2)) {
            sUvFMtxExports->uvMat4CopyL2F(&spAC, sobj->unk4[i]);
            if (i == 0) {
                temp_fs0 = 1.0f / sobj->unk30;
                temp_fs1 = 1.0f / sobj->unk34;
                sUvFMtxExports->uvMat4Scale(&spAC, temp_fs0, temp_fs0, temp_fs1);
                spAC.m[3][0] *= temp_fs0;
                spAC.m[3][1] *= temp_fs0;
                spAC.m[3][2] *= temp_fs1;
            }
            sUvModelExports->uvModelMtxStackPush(&spAC);
            var_s2++;
            if (var_s0) {
                *D_uvterra_rom_0040F78C = (*D_uvterra_rom_0040F78C & 0xFFFFFF) | (i << 0x18);
                sp106 += sUvModelExports->func_uvmodel_rom_004006B4(arg0, arg1, arg2, arg3, sUvModelExports->uvModelMtxStackTop(), &temp_fp->unk0[i], uvmd);
            }
            if (i == (sp104 - 1)) {
                break;
            }
            temp_s1 = temp_fp->unk0[i].unk6 - temp_fp->unk0[i + 1].unk6;
            // clang-format off
            for (j = 0; j <= temp_s1; j++) { \
                sUvModelExports->uvModelMtxStackPop(); \
                var_s2 -= 1; \
            }
            // clang-format on
            continue;
        }
    }
    for (i = 0; i < var_s2; i++) {
        sUvModelExports->uvModelMtxStackPop();
    }
    return sp106;
}

s16 func_uvterra_rom_0040A43C(f32 arg0, f32 arg1, f32 arg2, UnkSobjDraw *sobj) {
    s16 sp106;
    s16 sp104;
    f32 temp_fs0;
    f32 temp_fs1;
    s16 temp_s1;
    s16 j;
    s16 var_s2;
    s16 i;
    s32 temp_s5;
    s32 var_s0;
    Mtx4F spAC;
    ParsedUVMD_1 *temp_s7;
    uvModelLOD *modelLod;
    ParsedUVMD *uvmd;
    uvmd = uvGetLoadedFile('UVMD', sobj->modelId);
    temp_s7 = uvmd->unk0;
    sp106 = temp_s7->unk8;
    sUvModelExports->uvModelMtxStackReset();
    var_s2 = 0;
    for (i = 0; i < sp106; i++) {
        modelLod = &temp_s7->unk0[i];
        if ((sobj->unk1C & (1 << i)) || (modelLod->unk7 & 1)) {
            var_s0 = 0;
        } else {
            var_s0 = 1;
        }
        if ((var_s0 != 0) || (!(modelLod->unk7 & 2))) {
            sUvFMtxExports->uvMat4CopyL2F(&spAC, sobj->unk4[i]);
            if (i == 0) {
                temp_fs0 = 1.0f / sobj->unk30;
                temp_fs1 = 1.0f / sobj->unk34;
                sUvFMtxExports->uvMat4Scale(&spAC, temp_fs0, temp_fs0, temp_fs1);
                spAC.m[3][0] *= temp_fs0;
                spAC.m[3][1] *= temp_fs0;
                spAC.m[3][2] *= temp_fs1;
            }
            sUvModelExports->uvModelMtxStackPush(&spAC);
            var_s2 += 1;
            if (var_s0 != 0) {
                *D_uvterra_rom_0040F78C = ((*D_uvterra_rom_0040F78C) & 0xFFFFFF) | (i << 0x18);
                sp104 = sUvModelExports->func_uvmodel_rom_0040215C(
                    arg0, arg1, arg2, sUvModelExports->uvModelMtxStackTop(), temp_s7->unk0 + i);
            }
            if (sp104 >= 0) {
                return sp104;
            }
            if ((i + 1) == sp106) {
                break;
            }
            temp_s1 = temp_s7->unk0[i].unk6 - temp_s7->unk0[i + 1].unk6;
            // clang-format off
            for (j = 0; j <= temp_s1; j++) { \
                sUvModelExports->uvModelMtxStackPop(); \
                var_s2--; \
            } \
            // clang-format on
        }
        continue;  
    }

    for (i = 0; i < var_s2; i++) {
        sUvModelExports->uvModelMtxStackPop();
    }

    return -1;
}

s32 func_uvterra_rom_0040A79C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                              UnkSobjDraw *sobj) {
    s16 modelLodCount;
    ParsedUVMD_1 *temp_fp;
    f32 temp_fs1;
    f32 temp_fs0;
    ParsedUVMD *uvmd;
    s16 temp_s1;
    s16 j;
    Mtx4F spC0;
    s16 count;
    s16 i;
    s32 var_s0;
    uvModelLOD *modelLod;

    uvmd = uvGetLoadedFile('UVMD', (s32) sobj->modelId);
    temp_fp = uvmd->unk0;
    modelLodCount = temp_fp->unk8;
    sUvModelExports->uvModelMtxStackReset();
    count = 0;
    for (i = 0; i < modelLodCount; i++) {
        modelLod = &temp_fp->unk0[i];
        if ((sobj->unk1C & (1 << i)) || (((modelLod->unk7 & 1)))) {
            var_s0 = FALSE;
        } else {
            var_s0 = TRUE;
        }

        if ((!var_s0) && (modelLod->unk7 & 2)) {
            continue;
        }

        sUvFMtxExports->uvMat4CopyL2F(&spC0, sobj->unk4[i]);
        if (i == 0) {
            temp_fs0 = 1.0f / sobj->unk30;
            temp_fs1 = 1.0f / sobj->unk34;
            sUvFMtxExports->uvMat4Scale(&spC0, temp_fs0, temp_fs0, temp_fs1);
            spC0.m[3][0] *= temp_fs0;
            spC0.m[3][1] *= temp_fs0;
            spC0.m[3][2] *= temp_fs1;
        }
        sUvModelExports->uvModelMtxStackPush(&spC0);
        count++;
        if (var_s0 != 0) {
            *D_uvterra_rom_0040F78C = (*D_uvterra_rom_0040F78C & 0xFFFFFF) | (i << 0x18);
            sUvModelExports->_uvSegInMboxs(arg0, arg1, arg2, arg3, arg4, arg5,
                                                  sUvModelExports->uvModelMtxStackTop(),
                                                  &temp_fp->unk0[i], uvmd);
        }
        if (i == (modelLodCount - 1)) {
            break;
        }
        temp_s1 = temp_fp->unk0[i].unk6 - temp_fp->unk0[i + 1].unk6;
        // clang-format off
        for (j = 0; j <= temp_s1; j++) { \
            sUvModelExports->uvModelMtxStackPop();  \
            count--; \
        }
        // clang-format on
    }

    for (i = 0; i < count; i++) {
        sUvModelExports->uvModelMtxStackPop();
    }
    return -1;
}

#ifndef NO_VA_ARGS_FUNCTIONS
void func_uvterra_rom_0040AB14(s32 contour, ...) {
    va_list args;
    UnkSobjDraw *sobj;
    s32 temp_a0;

    sobj = func_uvterra_rom_0040AC14(contour);
    va_start(args, contour);
    if (sobj == NULL) {
        return;
    }

    while (TRUE) {
        temp_a0 = va_arg(args, s32);
        switch (temp_a0) {
            case 0:
                va_end(args);
                return;
            case 1:
                *va_arg(args, s32*) = sobj->unk1C;
                break;
            case 4:
                *va_arg(args, s32*) = sobj->modelId;
                break;
            default:
                va_end(args);
                return;
        }
    }
}
#endif

void func_uvterra_rom_0040ABB4(s32 contour, s32 arg1) {
    UnkSobjDraw* sobj;

    sobj = func_uvterra_rom_0040AC14(contour);
    if (sobj == NULL) {
        return;
    }
        
    sobj->unk40 = arg1;
}

s32 func_uvterra_rom_0040ABE0(s32 contour) {
    UnkSobjDraw* sobj;

    sobj = func_uvterra_rom_0040AC14(contour);
    if (sobj == NULL) {
        return 0;
    }
    return sobj->unk40;
}

// uvTerraSobjFromContour
UnkSobjDraw *func_uvterra_rom_0040AC14(s32 contour) {
    ParsedUVCT *uvct;
    UnkSobjDraw *sobj;

    uvct = uvGetLoadedFile('UVCT', (s32) ((u32) (contour & 0xFFF000) >> 0xC));
    if (uvct == NULL) {
        return NULL;
    }
    sobj = &uvct->unk10[contour & 0xFFF];
    if (sobj == NULL) {
        return NULL;
    }
    return sobj;
}

u8 func_uvterra_rom_0040AC8C(s32 arg0) {
    return D_uvterra_rom_0040F7A0[arg0];
}

void func_uvterra_rom_0040AC9C(s32 arg0) {
    ParsedUVTR* uvtr;
    UnkStruct_uvterra_rom_0040FBE8* temp_s0;
    s32 temp_a1;
    s32 i;

    temp_a1 = D_uvterra_rom_0040F77C[arg0];
    if (temp_a1 == 0xFFFF) {
        return;
    }
    uvtr = uvGetLoadedFile('UVTR', temp_a1);
    // FAKE
    if (1) {}
    D_uvterra_rom_0040FBA8 = 0.0f;
    
    for (i = 0; i < D_uvterra_rom_0040F740; i++) {
        temp_s0 = &D_uvterra_rom_0040FBE8[i];
        if (temp_s0->unk8 < D_uvterra_rom_0040FBA8) {
            D_uvterra_rom_0040F7A0[(s32) (temp_s0->unk0 - uvtr->unk28)] = 0;
        } else {
            func_uvterra_rom_0040AFD8(arg0, temp_s0->unk0, temp_s0->unk6, temp_s0->unk4);
            D_uvterra_rom_0040F7A0[(s32) (temp_s0->unk0 - uvtr->unk28)] = 1;
        }
        // FAKE: fix s8/s7 regalloc
        if (0) {}
    }
    D_uvterra_rom_0040D710 = D_uvterra_rom_0040FBA8 - uvtr->unk24;
}

void func_uvterra_rom_0040AE4C(s32 arg0) {
    UnkStruct_uvterra_rom_0040FBE8* temp_v0;
    s32 i;
    Mtx4F sp40;

    if (D_uvterra_rom_0040FBC4 != 0) {
        sUvGfxStateExports->func_uvgfxstate_rom_00401F54(0.0f, 0.0f);
        sUvGfxStateExports->func_uvgfxstate_rom_00401CE8();
        sUvGfxMgrExports->func_uvgfxmgr_rom_00401DC4();
        sUvChannelExports->func_uvchannel_rom_00400AFC(arg0, D_uvterra_rom_0040FBAC, D_uvterra_rom_0040FBB0, D_uvterra_rom_0040FBB4, D_uvterra_rom_0040FBB8, D_uvterra_rom_0040FBBC, D_uvterra_rom_0040FBC0);
        sUvChannelExports->func_uvchannel_rom_00400288(arg0, 1, &sp40, 0);
        sUvFMtxExports->uvGfxMtxProjPushF(&sp40);
        D_uvterra_rom_0040FBC4 = 0;
    }
    for (i = 0; i < D_uvterra_rom_0040F740; i++) {
        temp_v0 = &D_uvterra_rom_0040FBE8[i];
        if (!(D_uvterra_rom_0040FBA8 <= temp_v0->unk8)) {
            func_uvterra_rom_0040AFD8(arg0, (s32) temp_v0->unk0, temp_v0->unk6, temp_v0->unk4);
        }
    }
}

void func_uvterra_rom_0040AFD8(s32 arg0, uvUnkTileStruct* arg1, u16 arg2, u16 arg3) {
    Mtx4F sp28;

    if (arg1->unk40 == NULL) {
        return;
    }
        
    sUvFMtxExports->func_uvfmtx_rom_00400370(&sp28, &arg1->unk0);
    sUvFMtxExports->uvGfxMtxViewLoad(&sp28, 1U);
    if (!sNoTobjsFlag) {
        uvTobjsDraw(arg0, arg2, &arg1->unk0, arg1->unk40->unk8, (u16) (s32) arg1->unk40->unkC);
    }
    if (!sNoSobjsFlag) {
        uvSobjsDraw(arg0, &arg1->unk0, arg2, arg3, arg1->unk40->unk10, arg1->unk40->unk14);
    }
    sUvFMtxExports->uvGfxMtxFViewPop();
}


u16 D_uvterra_rom_0040D718[0x40][0x40] = {
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF,
        0xEFFF, 0xEFFF, 0xCFFF, 0xCFFF, 0xCFFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEEF,
        0xCCEF, 0x8CEF, 0x8CEF, 0x8CEE, 0x8CEE, 0x8CCE, 0x8CCE, 0x8CCC, 0x88CC, 0x88CC, 0x888C,
        0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8880, 0x8880, 0x8880,
        0x8880, 0x8800, 0x8800, 0x8800, 0x8800, 0x8000, 0x8000, 0x8000, 0x8000,
    },
    {
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xEFFF, 0xEFFF, 0xEFFF, 0xCFFF, 0xCFFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEEF,
        0xCEEF, 0xCCEF, 0xCCEF, 0xCCEE, 0x8CEE, 0x8CCE, 0x8CCE, 0x8CCC, 0x8CCC, 0x88CC, 0x888C,
        0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8880, 0x8880, 0x8880,
        0x8880, 0x8800, 0x8800, 0x8800, 0x8800, 0x8000, 0x8000, 0x8000, 0x8000,
    },
    {
        0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xCFFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF,
        0xCEEF, 0xCEEF, 0xCCEF, 0xCCEE, 0xCCEE, 0xCCCE, 0xCCCE, 0x8CCC, 0x8CCC, 0x8CCC, 0x88CC,
        0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8880, 0x8880, 0x8880,
        0x8880, 0x8800, 0x8800, 0x8800, 0x8800, 0x8000, 0x8000, 0x8000, 0x8000,
    },
    {
        0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xCFFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF,
        0xCEEF, 0xCEEF, 0xCEEF, 0xCCEE, 0xCCEE, 0xCCEE, 0xCCCE, 0xCCCC, 0xCCCC, 0xCCCC, 0x8CCC,
        0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8888, 0x8880, 0x8880, 0x8880,
        0x8880, 0x8800, 0x8800, 0x8800, 0x8800, 0x8000, 0x8000, 0x8000, 0x8000,
    },
    {
        0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF,
        0xCEFF, 0xCEEF, 0xCEEF, 0xCEEE, 0xCCEE, 0xCCEE, 0xCCCE, 0xCCCC, 0xCCCC, 0xCCCC, 0xCCCC,
        0xCCC8, 0xCC88, 0xC888, 0xC888, 0xC888, 0xC888, 0xC888, 0xC888, 0xC880, 0xC880, 0xC880,
        0xC880, 0xC800, 0xC800, 0xC800, 0xC800, 0xC000, 0xC000, 0xC000, 0xC000,
    },
    {
        0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEEFF, 0xEEFF, 0xEEFF, 0xEEFF,
        0xCEFF, 0xCEEF, 0xCEEF, 0xCEEE, 0xCEEE, 0xCCEE, 0xCCCE, 0xCCCC, 0xCCCC, 0xCCCC, 0xCCCC,
        0xCCCC, 0xCCC8, 0xCC88, 0xCC88, 0xCC88, 0xC888, 0xC888, 0xC888, 0xC880, 0xC880, 0xC880,
        0xC880, 0xC800, 0xC800, 0xC800, 0xC800, 0xC000, 0xC000, 0xC000, 0xC000,
    },
    {
        0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEEFF, 0xEEFF, 0xEEFF,
        0xEEFF, 0xEEEF, 0xEEEF, 0xCEEE, 0xCEEE, 0xCEEE, 0xCCEE, 0xCCCC, 0xCCCC, 0xCCCC, 0xCCCC,
        0xCCCC, 0xCCC8, 0xCCC8, 0xCC88, 0xCC88, 0xCC88, 0xCC88, 0xCC88, 0xCC80, 0xCC80, 0xC880,
        0xC880, 0xC800, 0xC800, 0xC800, 0xC800, 0xC000, 0xC000, 0xC000, 0xC000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEEFF, 0xEEFF,
        0xEEFF, 0xEEFF, 0xEEEF, 0xEEEE, 0xEEEE, 0xEEEE, 0xCEEE, 0xCCCC, 0xCCCC, 0xCCCC, 0xCCCC,
        0xCCCC, 0xCCC8, 0xCCC8, 0xCCC8, 0xCC88, 0xCC88, 0xCC88, 0xCC88, 0xCC80, 0xCC80, 0xCC80,
        0xC880, 0xC800, 0xC800, 0xC800, 0xC800, 0xC000, 0xC000, 0xC000, 0xC000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEEFF,
        0xEEFF, 0xEEFF, 0xEEEF, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEC, 0xEECC, 0xECCC, 0xECCC,
        0xECCC, 0xECCC, 0xECC8, 0xECC8, 0xECC8, 0xEC88, 0xEC88, 0xEC88, 0xEC80, 0xEC80, 0xEC80,
        0xEC80, 0xE800, 0xE800, 0xE800, 0xE800, 0xE000, 0xE000, 0xE000, 0xE000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF, 0xEFFF,
        0xEEFF, 0xEEFF, 0xEEEF, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEC, 0xEECC, 0xEECC,
        0xEECC, 0xECCC, 0xECC8, 0xECC8, 0xECC8, 0xECC8, 0xEC88, 0xEC88, 0xEC80, 0xEC80, 0xEC80,
        0xEC80, 0xEC00, 0xE800, 0xE800, 0xE800, 0xE000, 0xE000, 0xE000, 0xE000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF, 0xEFFF,
        0xEFFF, 0xEFFF, 0xEEFF, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEC, 0xEEEC, 0xEECC,
        0xEECC, 0xEECC, 0xEEC8, 0xEEC8, 0xECC8, 0xECC8, 0xECC8, 0xEC88, 0xEC80, 0xEC80, 0xEC80,
        0xEC80, 0xEC00, 0xEC00, 0xE800, 0xE800, 0xE000, 0xE000, 0xE000, 0xE000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xEFFF, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE, 0xEEEC, 0xEEEC, 0xEEEC,
        0xEECC, 0xEECC, 0xEECC, 0xEEC8, 0xEEC8, 0xEEC8, 0xEEC8, 0xECC8, 0xEC80, 0xEC80, 0xEC80,
        0xEC80, 0xEC00, 0xEC00, 0xE800, 0xE800, 0xE000, 0xE000, 0xE000, 0xE000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFEE, 0xFEEE, 0xFEEE, 0xFEEE, 0xFEEE, 0xFEEC, 0xFEEC,
        0xFEEC, 0xFECC, 0xFECC, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC8, 0xFE80, 0xFC80, 0xFC80,
        0xFC80, 0xFC00, 0xFC00, 0xF800, 0xF800, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFEE, 0xFFEE, 0xFFEE, 0xFEEE, 0xFEEC, 0xFEEC,
        0xFEEC, 0xFEEC, 0xFECC, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC0, 0xFE80, 0xFC80,
        0xFC80, 0xFC00, 0xFC00, 0xF800, 0xF800, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFEE, 0xFFEE, 0xFFEE, 0xFFEC, 0xFFEC,
        0xFEEC, 0xFEEC, 0xFEEC, 0xFECC, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC0, 0xFE80, 0xFE80,
        0xFC80, 0xFC00, 0xFC00, 0xF800, 0xF800, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFEE, 0xFFEE, 0xFFEE, 0xFFEC,
        0xFFEC, 0xFFEC, 0xFFEC, 0xFEEC, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC8, 0xFEC0, 0xFE80, 0xFE80,
        0xFE80, 0xFC00, 0xFC00, 0xFC00, 0xF800, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0xF000, 0xF000, 0xF000, 0xF000, 0x7000, 0x7000, 0x7000, 0x7000, 0x3000, 0x3000, 0x3000,
        0x3000, 0x1000, 0x1000, 0x1000, 0x1000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFEE, 0xFFEE, 0xFFEE, 0xFFEC,
        0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFE8, 0xFFC8, 0xFEC8, 0xFEC8, 0xFEC0, 0xFEC0, 0xFE80,
        0xFE80, 0xFE00, 0xFC00, 0xFC00, 0xF800, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0xF000, 0xF000, 0xF000, 0xF000, 0x7000, 0x7000, 0x7000, 0x7000, 0x3000, 0x3000, 0x3000,
        0x3000, 0x1000, 0x1000, 0x1000, 0x1000, 0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFEE, 0xFFEE, 0xFFEC,
        0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFE8, 0xFFC8, 0xFFC8, 0xFFC0, 0xFEC0, 0xFE80,
        0xFE80, 0xFE00, 0xFE00, 0xFC00, 0xF800, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0xF000, 0xF000, 0xF000, 0xF000, 0x7000, 0x7000, 0x7000, 0x7000, 0x3000, 0x3000, 0x3000,
        0x3000, 0x1000, 0x1000, 0x1000, 0x1000, 0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFEE, 0xFFEC,
        0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFE8, 0xFFE8, 0xFFC8, 0xFFC0, 0xFFC0, 0xFF80,
        0xFF80, 0xFE00, 0xFE00, 0xFE00, 0xFC00, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0xF000, 0xF000, 0xF000, 0xF000, 0x7000, 0x7000, 0x7000, 0x7000, 0x3000, 0x3000, 0x3000,
        0x3000, 0x1000, 0x1000, 0x1000, 0x1000, 0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFEE,
        0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFE8, 0xFFE8, 0xFFE8, 0xFFC0, 0xFFC0, 0xFFC0,
        0xFF80, 0xFF00, 0xFF00, 0xFF00, 0xFE00, 0xF000, 0xF000, 0xF000, 0xF000,
    },
    {
        0xF100, 0xF100, 0xF100, 0xF100, 0x7100, 0x7100, 0x7100, 0x7100, 0x3100, 0x3100, 0x3100,
        0x3100, 0x1100, 0x1100, 0x1100, 0x1100, 0,      0,      0,      0,      0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
        0xFFFC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFEC, 0xFFE8, 0xFFE8, 0xFFE0, 0xFFC0, 0xFFC0,
        0xFF80, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xF700, 0xF300, 0xF100, 0xF100,
    },
    {
        0xF300, 0xF100, 0xF100, 0xF100, 0x7100, 0x7100, 0x7100, 0x7100, 0x3100, 0x3100, 0x3100,
        0x3100, 0x1100, 0x1100, 0x1100, 0x1100, 0,      0,      0,      0,      0,      0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
        0xFFFE, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFEC, 0xFFE8, 0xFFE8, 0xFFE0, 0xFFE0, 0xFFC0,
        0xFF80, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xF700, 0xF300, 0xF300,
    },
    {
        0xF300, 0xF300, 0xF300, 0xF300, 0x7300, 0x7300, 0x7100, 0x7100, 0x3100, 0x3100, 0x3100,
        0x3100, 0x1100, 0x1100, 0x1100, 0x1100, 0,      0,      0,      0,      0,      0,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
        0xFFFE, 0xFFFE, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFF8, 0xFFF8, 0xFFE0, 0xFFE0, 0xFFE0,
        0xFFC0, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xF700, 0xF700, 0xF300,
    },
    {
        0xF300, 0xF300, 0xF300, 0xF300, 0x7300, 0x7300, 0x7300, 0x7100, 0x3100, 0x3100, 0x3100,
        0x3100, 0x1100, 0x1100, 0x1100, 0x1100, 0,      0,      0,      0,      0,      0,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
        0xFFFE, 0xFFFE, 0xFFFE, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFF8, 0xFFF0, 0xFFF0, 0xFFF0,
        0xFFE0, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xF700, 0xF700, 0xF700,
    },
    {
        0xF710, 0xF310, 0xF310, 0xF310, 0x7310, 0x7310, 0x7310, 0x7310, 0x3110, 0x3110, 0x3110,
        0x3110, 0x1110, 0x1110, 0x1110, 0x1110, 0,      0,      0,      0,      0,      0,
        0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE,
        0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFC, 0xFFFC, 0xFFF8, 0xFFF0, 0xFFF0, 0xFFF0,
        0xFFF0, 0xFF70, 0xFF30, 0xFF10, 0xFF10, 0xFF10, 0xFF10, 0xF710, 0xF710,
    },
    {
        0xF710, 0xF710, 0xF310, 0xF310, 0x7310, 0x7310, 0x7310, 0x7310, 0x3310, 0x3110, 0x3110,
        0x3110, 0x1110, 0x1110, 0x1110, 0x1110, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE,
        0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFC, 0xFFF8, 0xFFF0, 0xFFF0, 0xFFF0,
        0xFFF0, 0xFFF0, 0xFF70, 0xFF30, 0xFF30, 0xFF30, 0xFF10, 0xF710, 0xF710,
    },
    {
        0xF710, 0xF710, 0xF710, 0xF310, 0x7310, 0x7310, 0x7310, 0x7310, 0x3310, 0x3310, 0x3110,
        0x3110, 0x1110, 0x1110, 0x1110, 0x1110, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFC, 0xFFF0, 0xFFF0, 0xFFF0,
        0xFFF0, 0xFFF0, 0xFF70, 0xFF70, 0xFF30, 0xFF30, 0xFF30, 0xF730, 0xF730,
    },
    {
        0xF730, 0xF730, 0xF730, 0xF710, 0x7310, 0x7310, 0x7310, 0x7310, 0x3310, 0x3310, 0x3110,
        0x3110, 0x1110, 0x1110, 0x1110, 0x1110, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFF0, 0xFFF0, 0xFFF0,
        0xFFF0, 0xFFF0, 0xFF70, 0xFF70, 0xFF70, 0xFF30, 0xFF30, 0xFF30, 0xF730,
    },
    {
        0xF731, 0xF731, 0xF731, 0xF731, 0x7331, 0x7311, 0x7311, 0x7311, 0x3311, 0x3311, 0x3111,
        0x3111, 0x1111, 0x1111, 0x1111, 0x1111, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0xFFF3, 0xFFF1,
        0xFFF1, 0xFFF1, 0xFFF1, 0xFF71, 0xFF71, 0xFF71, 0xFF31, 0xFF31, 0xF731,
    },
    {
        0xF731, 0xF731, 0xF731, 0xF731, 0x7731, 0x7331, 0x7311, 0x7311, 0x3311, 0x3311, 0x3111,
        0x3111, 0x1111, 0x1111, 0x1111, 0x1111, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0xFFF3,
        0xFFF3, 0xFFF3, 0xFFF1, 0xFF71, 0xFF71, 0xFF71, 0xFF71, 0xFF31, 0xF731,
    },
    {
        0xF731, 0xF731, 0xF731, 0xF731, 0x7731, 0x7331, 0x7331, 0x7311, 0x3311, 0x3311, 0x3111,
        0x3111, 0x1111, 0x1111, 0x1111, 0x1111, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0xFFF7,
        0xFFF3, 0xFFF3, 0xFFF3, 0xFF73, 0xFF73, 0xFF71, 0xFF71, 0xFF71, 0xFF31,
    },
    {
        0xF731, 0xF731, 0xF731, 0xF731, 0x7731, 0x7331, 0x7331, 0x7331, 0x3311, 0x3311, 0x3311,
        0x3111, 0x1111, 0x1111, 0x1111, 0x1111, 0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0xFFF7,
        0xFFF7, 0xFFF3, 0xFFF3, 0xFFF3, 0xFF73, 0xFF73, 0xFF73, 0xFF73, 0xFF71,
    },
    {
        0xF733, 0xF733, 0xF731, 0xF731, 0x7731, 0x7331, 0x7331, 0x7331, 0x3331, 0x3311, 0x3311,
        0x3111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x111,  0x111,
        0x111,  0x111,  0x11,   0x11,   0x11,   0x11,   1,      1,      1,      1,      0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0xFFF7,
        0xFFF7, 0xFFF3, 0xFFF3, 0xFFF3, 0xFF73, 0xFF73, 0xFF73, 0xFF73, 0xFF73,
    },
    {
        0xF773, 0xF733, 0xF733, 0xF733, 0x7733, 0x7731, 0x7331, 0x7331, 0x3331, 0x3331, 0x3311,
        0x3111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x111,  0x111,
        0x111,  0x111,  0x11,   0x11,   0x11,   0x11,   1,      1,      1,      1,      0,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7,
        0xFFF7, 0xFFF7, 0xFFF3, 0xFFF3, 0xFF73, 0xFF73, 0xFF73, 0xFF73, 0xFF73,
    },
    {
        0xFF73, 0xF773, 0xF773, 0xF733, 0x7733, 0x7733, 0x7333, 0x7333, 0x3331, 0x3331, 0x3331,
        0x3311, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x111,  0x111,
        0x111,  0x111,  0x11,   0x11,   0x11,   0x11,   1,      1,      1,      1,      0,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7,
        0xFFF7, 0xFFF7, 0xFFF7, 0xFFF3, 0xFF73, 0xFF73, 0xFF73, 0xFF73, 0xFF73,
    },
    {
        0xFF73, 0xF773, 0xF773, 0xF733, 0x7733, 0x7733, 0x7333, 0x7333, 0x3333, 0x3333, 0x3333,
        0x3331, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x111,  0x111,
        0x111,  0x111,  0x11,   0x11,   0x11,   0x11,   1,      1,      1,      1,      0,
        0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7,
        0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF3, 0xFF73, 0xFF73, 0xFF73, 0xFF73,
    },
    {
        0xFF73, 0xFF73, 0xF773, 0xF773, 0x7773, 0x7733, 0x7733, 0x7333, 0x3333, 0x3333, 0x3333,
        0x3333, 0x1333, 0x1133, 0x1113, 0x1113, 0x1113, 0x1113, 0x1113, 0x1113, 0x113,  0x113,
        0x113,  0x113,  0x13,   0x13,   0x13,   0x13,   3,      3,      3,      3,      0,
        0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7,
        0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFF77, 0xFF73, 0xFF73, 0xFF73,
    },
    {
        0xFF73, 0xFF73, 0xF773, 0xF773, 0x7773, 0x7733, 0x7733, 0x7333, 0x3333, 0x3333, 0x3333,
        0x3333, 0x3333, 0x1333, 0x1133, 0x1133, 0x1133, 0x1113, 0x1113, 0x1113, 0x113,  0x113,
        0x113,  0x113,  0x13,   0x13,   0x13,   0x13,   3,      3,      3,      3,      0,
        0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7,
        0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFF77, 0xFF77, 0xFF77,
    },
    {
        0xFF77, 0xFF77, 0xF777, 0xF777, 0x7773, 0x7773, 0x7773, 0x7733, 0x3333, 0x3333, 0x3333,
        0x3333, 0x3333, 0x1333, 0x1333, 0x1133, 0x1133, 0x1133, 0x1133, 0x1133, 0x133,  0x133,
        0x113,  0x113,  0x13,   0x13,   0x13,   0x13,   3,      3,      3,      3,      0,
        0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFF77, 0xFF77,
    },
    {
        0xFF77, 0xFF77, 0xF777, 0xF777, 0x7777, 0x7777, 0x7777, 0x7773, 0x3333, 0x3333, 0x3333,
        0x3333, 0x3333, 0x1333, 0x1333, 0x1333, 0x1133, 0x1133, 0x1133, 0x1133, 0x133,  0x133,
        0x133,  0x113,  0x13,   0x13,   0x13,   0x13,   3,      3,      3,      3,      0,
        0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFF77,
    },
    {
        0xFF77, 0xFF77, 0xFF77, 0xF777, 0x7777, 0x7777, 0x7777, 0x7777, 0x3777, 0x3377, 0x3337,
        0x3337, 0x3337, 0x3337, 0x1337, 0x1337, 0x1337, 0x1137, 0x1137, 0x1137, 0x137,  0x137,
        0x137,  0x137,  0x17,   0x17,   0x17,   0x17,   7,      7,      7,      7,      0,
        0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7,
    },
    {
        0xFFF7, 0xFF77, 0xFF77, 0xF777, 0x7777, 0x7777, 0x7777, 0x7777, 0x7777, 0x3777, 0x3377,
        0x3377, 0x3337, 0x3337, 0x1337, 0x1337, 0x1337, 0x1337, 0x1137, 0x1137, 0x137,  0x137,
        0x137,  0x137,  0x37,   0x17,   0x17,   0x17,   7,      7,      7,      7,      0,
        0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7, 0xFFF7,
    },
    {
        0xFFF7, 0xFFF7, 0xFFF7, 0xFF77, 0x7777, 0x7777, 0x7777, 0x7777, 0x7777, 0x3777, 0x3777,
        0x3377, 0x3377, 0x3377, 0x1377, 0x1377, 0x1337, 0x1337, 0x1337, 0x1137, 0x137,  0x137,
        0x137,  0x137,  0x37,   0x37,   0x17,   0x17,   7,      7,      7,      7,      0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFF7, 0x7777, 0x7777, 0x7777, 0x7777, 0x7777, 0x3777, 0x3777,
        0x3777, 0x3377, 0x3377, 0x3377, 0x1377, 0x1377, 0x1377, 0x1377, 0x1337, 0x137,  0x137,
        0x137,  0x137,  0x37,   0x37,   0x17,   0x17,   7,      7,      7,      7,      0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x77FF, 0x777F, 0x777F, 0x777F, 0x777F, 0x377F,
        0x377F, 0x377F, 0x337F, 0x337F, 0x137F, 0x137F, 0x137F, 0x137F, 0x137F, 0x17F,  0x13F,
        0x13F,  0x13F,  0x3F,   0x3F,   0x1F,   0x1F,   0xF,    0xF,    0xF,    0xF,    0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x77FF, 0x77FF, 0x777F, 0x777F, 0x377F,
        0x377F, 0x377F, 0x377F, 0x337F, 0x137F, 0x137F, 0x137F, 0x137F, 0x137F, 0x37F,  0x17F,
        0x13F,  0x13F,  0x3F,   0x3F,   0x1F,   0x1F,   0xF,    0xF,    0xF,    0xF,    0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x77FF, 0x77FF, 0x77FF, 0x37FF,
        0x37FF, 0x377F, 0x377F, 0x377F, 0x337F, 0x137F, 0x137F, 0x137F, 0x137F, 0x37F,  0x17F,
        0x17F,  0x13F,  0x3F,   0x3F,   0x1F,   0x1F,   0xF,    0xF,    0xF,    0xF,    0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x77FF, 0x77FF, 0x77FF,
        0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x377F, 0x137F, 0x137F, 0x137F, 0x137F, 0x37F,  0x17F,
        0x17F,  0x17F,  0x3F,   0x3F,   0x3F,   0x1F,   0xF,    0xF,    0xF,    0xF,    0,
        0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x77FF, 0x77FF, 0x77FF,
        0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x17FF, 0x13FF, 0x137F, 0x137F, 0x37F,  0x37F,
        0x17F,  0x17F,  0x7F,   0x3F,   0x3F,   0x1F,   0xF,    0xF,    0xF,    0xF,    0xF,
        0xF,    0xF,    0xF,    0xE,    0xE,    0xE,    0xE,    0xC,    0xC,    0xC,    0xC,
        8,      8,      8,      8,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x77FF, 0x77FF,
        0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x17FF, 0x13FF, 0x13FF, 0x3FF,  0x37F,
        0x17F,  0x17F,  0x7F,   0x7F,   0x3F,   0x1F,   0xF,    0xF,    0xF,    0xF,    0xF,
        0xF,    0xF,    0xF,    0xE,    0xE,    0xE,    0xE,    0xC,    0xC,    0xC,    0xC,
        8,      8,      8,      8,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x77FF,
        0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x17FF, 0x17FF, 0x13FF, 0x3FF,  0x3FF,
        0x1FF,  0x1FF,  0x7F,   0x7F,   0x7F,   0x3F,   0xF,    0xF,    0xF,    0xF,    0xF,
        0xF,    0xF,    0xF,    0xE,    0xE,    0xE,    0xE,    0xC,    0xC,    0xC,    0xC,
        8,      8,      8,      8,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
        0x77FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x17FF, 0x17FF, 0x17FF, 0x3FF,  0x3FF,
        0x3FF,  0x1FF,  0xFF,   0xFF,   0xFF,   0x7F,   0xF,    0xF,    0xF,    0xF,    0xF,
        0xF,    0xF,    0xF,    0xE,    0xE,    0xE,    0xE,    0xC,    0xC,    0xC,    0xC,
        8,      8,      8,      8,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
        0x7FFF, 0x3FFF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x37FF, 0x17FF, 0x17FF, 0x7FF,  0x3FF,
        0x3FF,  0x1FF,  0xFF,   0xFF,   0xFF,   0xFF,   0xEF,   0xCF,   0x8F,   0x8F,   0x8F,
        0x8F,   0x8F,   0x8F,   0x8E,   0x8E,   0x8E,   0x8E,   0x8C,   0x8C,   0x8C,   0x8C,
        0x88,   0x88,   0x88,   0x88,   0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
        0x7FFF, 0x7FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x37FF, 0x17FF, 0x17FF, 0x7FF,  0x7FF,
        0x3FF,  0x1FF,  0xFF,   0xFF,   0xFF,   0xFF,   0xFF,   0xEF,   0xCF,   0xCF,   0xCF,
        0x8F,   0x8F,   0x8F,   0x8E,   0x8E,   0x8E,   0x8E,   0x8C,   0x8C,   0x8C,   0x8C,
        0x88,   0x88,   0x88,   0x88,   0,      0,      0,      0,      0,      0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
        0x7FFF, 0x7FFF, 0x7FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x1FFF, 0x1FFF, 0x7FF,  0x7FF,
        0x7FF,  0x3FF,  0xFF,   0xFF,   0xFF,   0xFF,   0xFF,   0xEF,   0xEF,   0xCF,   0xCF,
        0xCF,   0xCF,   0xCF,   0xCE,   0xCE,   0x8E,   0x8E,   0x8C,   0x8C,   0x8C,   0x8C,
        0x88,   0x88,   0x88,   0x88,   0,      0,      0,      0,      0,      0,      0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF,
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x1FFF, 0xFFF,  0xFFF,
        0xFFF,  0x7FF,  0xFF,   0xFF,   0xFF,   0xFF,   0xFF,   0xEF,   0xEF,   0xEF,   0xCF,
        0xCF,   0xCF,   0xCF,   0xCE,   0xCE,   0xCE,   0x8E,   0x8C,   0x8C,   0x8C,   0x8C,
        0x88,   0x88,   0x88,   0x88,   0,      0,      0,      0,      0,      0,      0,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF,
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x3FFF, 0x3FFF, 0x1FFF, 0xFFF,  0xFFF,
        0xFFF,  0xFFF,  0xEFF,  0xCFF,  0x8FF,  0x8FF,  0x8FF,  0x8FF,  0x8EF,  0x8EF,  0x8EF,
        0x8CF,  0x8CF,  0x8CF,  0x8CE,  0x8CE,  0x8CE,  0x8CE,  0x88C,  0x88C,  0x88C,  0x88C,
        0x888,  0x888,  0x888,  0x888,  0,      0,      0,      0,      0,      0,      0,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF,
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x3FFF, 0x1FFF, 0xFFF,  0xFFF,
        0xFFF,  0xFFF,  0xFFF,  0xEFF,  0xCFF,  0xCFF,  0xCFF,  0x8FF,  0x8EF,  0x8EF,  0x8EF,
        0x8EF,  0x8CF,  0x8CF,  0x8CE,  0x8CE,  0x8CE,  0x8CE,  0x8CC,  0x88C,  0x88C,  0x88C,
        0x888,  0x888,  0x888,  0x888,  0,      0,      0,      0,      0,      0,      0,
        0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x3FFF, 0xFFF,  0xFFF,
        0xFFF,  0xFFF,  0xFFF,  0xEFF,  0xEFF,  0xCFF,  0xCFF,  0xCFF,  0xCEF,  0xCEF,  0x8EF,
        0x8EF,  0x8EF,  0x8CF,  0x8CE,  0x8CE,  0x8CE,  0x8CE,  0x8CC,  0x8CC,  0x88C,  0x88C,
        0x888,  0x888,  0x888,  0x888,  0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7FFF, 0xFFF,  0xFFF,
        0xFFF,  0xFFF,  0xFFF,  0xEFF,  0xEFF,  0xEFF,  0xCFF,  0xCFF,  0xCFF,  0xCEF,  0xCEF,
        0xCEF,  0xCEF,  0x8EF,  0x8CE,  0x8CE,  0x8CE,  0x8CE,  0x8CC,  0x8CC,  0x88C,  0x88C,
        0x888,  0x888,  0x888,  0x888,  0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF, 0xCFFF,
        0x8FFF, 0x8FFF, 0x8FFF, 0x8FFF, 0x8EFF, 0x8EFF, 0x8EFF, 0x8CFF, 0x8CFF, 0x8CEF, 0x8CEF,
        0x8CEF, 0x8CEF, 0x8CEF, 0x8CCE, 0x88CE, 0x88CE, 0x88CE, 0x88CC, 0x88CC, 0x888C, 0x888C,
        0x8888, 0x8888, 0x8888, 0x8888, 0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF,
        0xCFFF, 0xCFFF, 0xCFFF, 0x8FFF, 0x8EFF, 0x8EFF, 0x8EFF, 0x8EFF, 0x8CFF, 0x8CEF, 0x8CEF,
        0x8CEF, 0x8CEF, 0x8CEF, 0x8CEE, 0x8CCE, 0x88CE, 0x88CE, 0x88CC, 0x88CC, 0x888C, 0x888C,
        0x8888, 0x8888, 0x8888, 0x8888, 0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF,
        0xEFFF, 0xCFFF, 0xCFFF, 0xCFFF, 0xCEFF, 0xCEFF, 0x8EFF, 0x8EFF, 0x8EFF, 0x8CFF, 0x8CEF,
        0x8CEF, 0x8CEF, 0x8CEF, 0x8CEE, 0x8CCE, 0x8CCE, 0x88CE, 0x88CC, 0x88CC, 0x888C, 0x888C,
        0x8888, 0x8888, 0x8888, 0x8888, 0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0,      0xFFFF, 0xFFFF,
    },
    {
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEFFF,
        0xEFFF, 0xEFFF, 0xCFFF, 0xCFFF, 0xCFFF, 0xCEFF, 0xCEFF, 0xCEFF, 0xCEFF, 0x8EFF, 0x8CEF,
        0x8CEF, 0x8CEF, 0x8CEF, 0x8CEE, 0x8CCE, 0x8CCE, 0x8CCE, 0x88CC, 0x88CC, 0x88CC, 0x888C,
        0x8888, 0x8888, 0x8888, 0x8888, 0,      0,      0,      0,      0,      0,      0,
        0,      0,      0,      0,      0,      0,      0,      0,      0xFFFF,
    },
};

u16 func_uvterra_rom_0040B0C4(s16 arg0, s16 arg1, u8 arg2) {
    s16 temp_v0;

    if (arg2) {
        temp_v0 = arg1 - arg0;
        if ((temp_v0 == 1) || (temp_v0 == 0) || ((temp_v0 == -0x3F))) {
            return 0xFFFFU;
        }
        arg0++;
        arg1--;
        if (arg0 >= 64) {
            arg0 -= 64;
        } else if (arg0 < 0) {
            arg0 += 64;
        }
        if (arg1 >= 64) {
            arg1 -= 64;
        } else if (arg1 < 0) {
            arg1 += 64;
        }
        return D_uvterra_rom_0040D718[arg0][arg1];
    }
    temp_v0 = arg1 - arg0;
    if ((temp_v0 == -1) || (temp_v0 == 0) || ((temp_v0 == 0x3F))) {
        return 0xFFFFU;
    }
    arg0--;
    arg1++;
    if (arg0 >= 64) {
        arg0 = arg0 - 64;
    } else if (arg0 < 0) {
        arg0 += 64;
    }
    if (arg1 >= 64) {
        arg1 -= 64;
    } else if (arg1 < 0) {
        arg1 += 64;
    }
    return D_uvterra_rom_0040D718[arg1][arg0];
}

void uvComputeLineEndP(s16 *arg0, s16 *arg1, u16 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                               f32 arg7, f32 arg8, f32 arg9, u8 arg10, f32 arg11, f32 arg12) {
    f32 temp_fa0;
    f32 temp_fv1;

    if (arg8 == 2.1401436e9f) {
        if (arg7 <= arg3) {
            UV_COMPUTE_LINE_MACRO(arg10, arg2, arg0);
        } else if (arg4 <= arg7) {
            UV_COMPUTE_LINE_MACRO(!arg10, arg2, arg0);
        } else {
            *arg0 = ROUNDF2((arg7 - arg3) * arg11);
            *arg1 = 47 - *arg0;
        }
    } else if (arg8 == 0.0f) {
        temp_fa0 = (arg8 * arg3) + arg7;
        if (temp_fa0 <= arg6) {
            UV_COMPUTE_LINE_MACRO(!arg10, arg2, arg0);
        } else if (arg5 <= temp_fa0) {
            UV_COMPUTE_LINE_MACRO(arg10, arg2, arg0);
        } else {
            *arg0 = ROUNDF2(63.0f - (temp_fa0 - arg6) * arg12);
            // FAKE
            if (1) {
            }
            *arg1 = ROUNDF2((temp_fa0 - arg6) * arg12 + 16.0f);
        }
    } else {
        temp_fa0 = (arg8 * arg3) + arg7;
        if (temp_fa0 < arg6) {
            temp_fv1 = (arg8 * arg4) + arg7;
            if (temp_fv1 <= arg6) {
                UV_COMPUTE_LINE_MACRO(!arg10, arg2, arg0);
            } else {
                *arg0 = ROUNDF2((arg6 - temp_fa0) * arg9 * arg11);
                if (temp_fv1 <= arg5) {
                    *arg1 = ROUNDF2((temp_fv1 - arg6) * arg12) + 16;
                } else if (arg5 < temp_fv1) {
                    *arg1 = 47 - ROUNDF2((arg5 - temp_fa0) * arg9 * arg11);
                }
            }

        } else if ((arg6 <= temp_fa0) && (temp_fa0 <= arg5)) {
            *arg0 = 63 - ROUNDF2((temp_fa0 - arg6) * arg12);
            temp_fv1 = (arg8 * arg4) + arg7;
            if (temp_fv1 < arg6) {
                *arg1 = ROUNDF2((arg6 - temp_fa0) * arg9 * arg11);
            } else if (temp_fv1 <= arg5) {
                *arg1 = ROUNDF2((temp_fv1 - arg6) * arg12) + 16;
            } else if (arg5 < temp_fv1) {
                *arg1 = 47 - ROUNDF2((arg5 - temp_fa0) * arg9 * arg11);
            }
        } else if (arg5 <= temp_fa0) {
            temp_fv1 = (arg8 * arg4) + arg7;
            if (arg5 <= temp_fv1) {
                UV_COMPUTE_LINE_MACRO(arg10, arg2, arg0);
            } else {
                *arg0 = 47 - ROUNDF2((arg5 - temp_fa0) * arg9 * arg11);
                if (arg6 <= temp_fv1) {
                    *arg1 = ROUNDF2((temp_fv1 - arg6) * arg12) + 16;
                } else if (temp_fv1 < arg6) {
                    *arg1 = ROUNDF2((arg6 - temp_fa0) * arg9 * arg11);
                }
            }
        }
    }
}

s32 func_uvterra_rom_0040B8C0(ParsedUVTR* arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6, u16* arg7, u16* arg8, u8 arg9) {
    f32 sp44;
    f32 sp40;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;
    u16 var_a2;
    u16 var_v0;
    u16 var_v0_3;
    u16 var_v1;
    u8 var_v0_2;

    *arg4 = arg1;
    *arg5 = arg2;
    *arg6 = arg3;
    sp44 = arg0->unk1C;
    sp40 = arg0->unk20;
    temp_fa0 = sp44 * 0.5f;
    temp_fa1 = sp40 * 0.5f;
    temp_ft4 = arg0->unk0.unk0;
    var_a2 = (s32) (arg1 - temp_ft4) / (s32) sp44;

    if (arg9 & 1) {
        var_a2 -= 1;
    }
    temp_fv0 = arg0->unk0.unk4;
    var_v0 = (s32) (arg2 - temp_fv0) / (s32) sp40;
    if (arg9 & 2) {
        var_v0 -= 1;
    }

    if ((var_a2 >= arg0->unk18) || (var_v0 >= arg0->unk19)) {
        return 0;
    }

    *arg7 = var_a2 + (var_v0 * arg0->unk18);

    *arg4 = ((arg1 - (var_a2 * sp44)) - temp_ft4) - temp_fa0;

    *arg5 = ((arg2 - (var_v0 * sp40)) - temp_fv0) - temp_fa1;

    if (*arg4 < -temp_fa0) {
        var_v0_2 = 1;
    } else if (temp_fa0 <= *arg4) {
        var_v0_2 = 1;
    } else if (*arg5 < -temp_fa1) {
        var_v0_2 = 1;
    } else if (temp_fa1 <= *arg5) {
        var_v0_2 = 1;
    } else {
        var_v0_2 = 0;
    }

    if (var_v0_2) {
        *arg8 = 0;
    } else {
        var_v0_3 = (s32) (((*arg4 + temp_fa0) * 4.0f) / sp44);
        var_v1 = (s32) (((*arg5 + temp_fa1) * 4.0f) / sp40);
        if (var_v0_3 == 4) {
            var_v0_3 = 3;
        }

        if (var_v1 == 4) {
            var_v1 = 3;
        }
        *arg8 = 0x8000 >> ((var_v1 * 4) + (var_v0_3 % 4));
    }
    return 1;
}

u16 func_uvterra_rom_0040BBC0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_fa0;
    f32 temp_fs1;
    f32 temp_ft4;
    f32 temp_ft5;
    u16 var_a0;
    s32 i;
    u16 var_v1;
    f32 var_fv1;
    f32 var_fv0;
    
    var_v1 = 0;
    var_a0 = 0;
    temp_ft4 = (arg4 - arg3) * 0.25f;
    temp_fs1 = 2.0f * temp_ft4;
    temp_ft5 = (arg6 - arg5) * 0.25f;
    var_fv0 = -temp_ft4;
    var_fv1 = -temp_ft5;
    for (i = 0; (var_fv0 <= temp_fs1) && (i < 4); i++) {
        if (((arg0 - arg2) <= var_fv0) && ((var_fv0 - temp_ft4) <= (arg0 + arg2))) {
            var_a0 |= 0x8888 >> i;
        }
        var_fv0 += temp_ft4;
    }

    temp_fa0 = 2.0f * temp_ft5;
    for (i = 0; (var_fv1 <= temp_fa0) && (i < 4); i++) {
        if (((arg1 - arg2) <= var_fv1) && ((var_fv1 - temp_ft5) <= (arg1 + arg2))) {
            var_v1 |= 0xF000 >> (i * 4);
        }
        var_fv1 += temp_ft5;
    }

    var_fv0 = -temp_ft4;
    return var_v1 & var_a0;
}

u16 func_uvterra_rom_0040BD38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                              f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, void *arg12) {
    f32 sp50;
    f32 sp4C;
    f32 sp40;
    f32 sp38;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_ft4;
    f32 var_ft5;
    s32 i;
    u16 sp5A;
    u16 sp58;
    u16 temp_v0;
    u16 temp_t4;

    sp5A = 0;
    sp58 = 0;
    sp50 = arg9 - arg8;
    sp4C = arg10 - arg11;

    if (arg4 < arg6) {
        var_ft5 = arg4;
        var_fs0 = arg6;
    } else {
        var_ft5 = arg6;
        var_fs0 = arg4;
    }

    if (arg5 < arg7) {
        var_fs1 = arg5;
        var_fs2 = arg7;
    } else {
        var_fs1 = arg7;
        var_fs2 = arg5;
    }

    temp_fa0 = 0.25f * sp50;
    var_ft4 = 2.0f * temp_fa0;
    sp38 = -temp_fa0;

    temp_fa1 = 0.25f * sp4C;
    sp40 = -temp_fa1;

    for (i = 0; (sp38 <= var_ft4) && (i < 4); i++) {
        if ((var_ft5 <= sp38) && ((sp38 - temp_fa0) <= var_fs0)) {
            sp58 |= 0x8888 >> i;
        }
        sp38 += temp_fa0;
    }
    temp_fv0 = 2.0f * temp_fa1;

    for (i = 0; (sp40 <= temp_fv0) && (i < 4); i++) {
        if ((var_fs1 <= sp40) && ((sp40 - temp_fa1) <= var_fs2)) {
            sp5A |= 0xF000 >> (i * 4);
        }
        sp40 += temp_fa1;
    }
    if (arg2 != arg0) {
        sp40 = (arg3 - arg1) / (arg2 - arg0);
        var_ft4 = arg3 - (sp40 * arg2);
    } else {
        sp40 = 2.1401436e9f;
        var_ft4 = arg2;
    }

    temp_t4 = sp5A & sp58;
    temp_v0 = func_uvterra_rom_0040BF74(sp50, sp4C, arg12, sp40, var_ft4);

    return temp_t4 & temp_v0;
}

u16 func_uvterra_rom_0040BF74(f32 arg0, f32 arg1, uvUnkTileStruct* arg2, f32 arg3, f32 arg4) {
    s32 pad[2];
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    s32 pad2;
    u16 sp52;
    s16 sp50;
    s16 sp4E;

    sp52 = -1;

    sp64 = arg2->unk0.m[3][0] - (0.5f * arg0);
    sp60 = arg2->unk0.m[3][0] + (0.5f * arg0);
    sp5C = arg2->unk0.m[3][1] + (0.5f * arg1);
    sp58 = arg2->unk0.m[3][1] - (0.5f * arg1);
    uvComputeLineEndP(&sp50, &sp4E, &sp52, sp64, sp60, sp5C, sp58, arg4, arg3, 1.0f / arg3, 0, 15.0f / arg0, 15.0f / arg1);
    if (sp50 >= 0) {
        sp52 &= func_uvterra_rom_0040B0C4(sp50, sp4E, 0);
        sp52 &= func_uvterra_rom_0040B0C4(sp50, sp4E, 1);
    }
    return sp52;
}


void func_uvterra_rom_0040C08C(void) {
    D_uvterra_rom_0040F774 = _uvMemAllocAlign8(D_uvterra_rom_0040F778 * sizeof(UnkStruct_uvterra_rom_0040F774));
    uvMemSet(D_uvterra_rom_0040F774, 0, D_uvterra_rom_0040F778 * sizeof(UnkStruct_uvterra_rom_0040F774));
}

UnkStruct_uvterra_rom_0040F774_inner* func_uvterra_rom_0040C0F8(s32 arg0) {
    UnkStruct_uvterra_rom_0040F774* temp_a1;
    UnkStruct_uvterra_rom_0040F774_inner* temp_v1;
    Vec3F* temp_v0;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    u16 i;
    u8 temp_t0;

    temp_v1 = &D_uvterra_rom_0040F774[arg0].unk4C;
    temp_a1 = &D_uvterra_rom_0040F774[arg0];
    temp_t0 = temp_a1->unk48;
    temp_v1->unk8 = 10000000000.0f;
    temp_v1->unk4 = 10000000000.0f;
    temp_v1->unk0 = 10000000000.0f;
    temp_v1->unk14 = -10000000000.0f;
    temp_v1->unk10 = -10000000000.0f;
    temp_v1->unkC = -10000000000.0f;
    for (i = 0; i < temp_t0; i++) {
        temp_v0 = &temp_a1->unk0[i];
        temp_fv0 = temp_v0->x;
        temp_fv1 = temp_v0->y;
        temp_fa0 = temp_v0->z;
        if (temp_fv0 < temp_v1->unk0) {
            temp_v1->unk0 = temp_fv0;
        }
        if (temp_v1->unkC < temp_fv0) {
            temp_v1->unkC = temp_fv0;
        }
        if (temp_fv1 < temp_v1->unk4) {
            temp_v1->unk4 = temp_fv1;
        }
        if (temp_v1->unk10 < temp_fv1) {
            temp_v1->unk10 = temp_fv1;
        }
        if (temp_fa0 < temp_v1->unk8) {
            temp_v1->unk8 = temp_fa0;
        }
        if (temp_v1->unk14 < temp_fa0) {
            temp_v1->unk14 = temp_fa0;
        }
    }
    return temp_v1;
}

void func_uvterra_rom_0040C218(s32 arg0) {
    Vec3F* spA4;
    f32 var_fv0;
    Vec3F* sp8C[5];
    u8 i;
    u8 sp8A;
    UnkStruct_uvterra_rom_0040F774 *sp84;
    Mtx4F sp44;
    ParsedUVTR *sp40;

    sp84 = &D_uvterra_rom_0040F774[arg0];
    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 10, &spA4, 0);
    if (D_uvterra_rom_0040F77C[arg0] == 0xFFFF) {
        return;
    }

    sp40 = uvGetLoadedFile('UVTR', D_uvterra_rom_0040F77C[arg0]);
    if (sp40 == NULL) {
        return;
    }

    sUvChannelExports->func_uvchannel_rom_00400288(arg0, 2, &sp44, 0);

    if (sp44.m[1][2] > 0.0f) {
        var_fv0 = sp44.m[1][2];
    } else {
        var_fv0 = -sp44.m[1][2];
    }

    if (var_fv0 <= 0.0001f) {
        // clang-format off
        switch (func_uvterra_rom_0040C490(&spA4[0], &spA4[1], &spA4[2], &spA4[3])) {
            case 0:
                sp8C[0] = &spA4[5]; \
                sp8C[1] = &spA4[1]; \
                sp8C[2] = &spA4[3];
                break;
            case 1:
                sp8C[0] = &spA4[5]; \
                sp8C[1] = &spA4[2]; \
                sp8C[2] = &spA4[0];
                break;
            case 2:
                sp8C[0] = &spA4[5]; \
                sp8C[1] = &spA4[3]; \
                sp8C[2] = &spA4[1];
                break;
            case 3:
                sp8C[0] = &spA4[5]; \
                sp8C[1] = &spA4[0]; \
                sp8C[2] = &spA4[2];
                break;
        }
        // clang-format on
        sp8A = 3;
    } else {
        sp8C[0] = &spA4[0];
        sp8C[1] = &spA4[1];
        sp8C[2] = &spA4[2];
        sp8C[3] = &spA4[3];
        sp8C[4] = &spA4[5];
        sp8A = 5;
        func_uvterra_rom_0040C50C(sp40, &spA4[5], &spA4[0], &spA4[1], &spA4[2], &spA4[3]);
        func_uvterra_rom_0040CA64(sp8C, &sp8A);
    }

    for (i = 0; i < sp8A; i++) {
        sp84->unk0[i].x = sp8C[i]->x;
        sp84->unk0[i].y = sp8C[i]->y;
    }
    sp84->unk48 = sp8A;
}

u16 func_uvterra_rom_0040C490(Vec3F* arg0, Vec3F* arg1, Vec3F* arg2, Vec3F* arg3) {
    f32 var_fv1;
    f32 var_fv0;
    u16 var_v1;

    var_fv0 = 1000000.0f;
    var_v1 = 0;

    var_fv1 = arg0->z;
    if (var_fv1 < var_fv0) {
        var_fv0 = var_fv1;
    }

    var_fv1 = arg1->z;
    if (var_fv1 < var_fv0) {
        var_fv0 = var_fv1;
        var_v1 = 1;
    }

    var_fv1 = arg2->z;
    if (var_fv1 < var_fv0) {
        var_fv0 = var_fv1;
        var_v1 = 2;
    }
    var_fv1 = arg3->z;
    if (var_fv1 < var_fv0) {
        var_v1 = 3;
    }
    return var_v1;
}

void func_uvterra_rom_0040C50C(ParsedUVTR* arg0, Vec3F* arg1, Vec3F* arg2, Vec3F* arg3, Vec3F* arg4, Vec3F* arg5) {
    s32 var_v0;
    s32 var_v1;
    f32 var_fv0;
    f32 var_fv1;

    var_fv0 = arg0->unk0.unk14;
    var_fv1 = arg0->unk0.unk8;
    var_v0 = 0;
    var_v1 = 0;
    if (var_fv0 <= arg2->z) {
        var_v1 = 1;
    } else if (arg2->z <= var_fv1) {
        var_v0 = 1;
    }
    if (var_fv0 <= arg3->z) {
        var_v1 += 1;
    } else if (arg3->z <= var_fv1) {
        var_v0 += 1;
    }
    if (var_fv0 <= arg4->z) {
        var_v1 += 1;
    } else if (arg4->z <= var_fv1) {
        var_v0 += 1;
    }
    if (var_fv0 <= arg5->z) {
        var_v1 += 1;
    } else if (arg5->z <= var_fv1) {
        var_v0 += 1;
    }
    if (var_fv0 < arg1->z) {
        if ((!(var_fv0 <= arg2->z) || !(var_fv0 <= arg3->z) || !(var_fv0 <= arg4->z) || !(var_fv0 <= arg5->z)) && (var_v0 == 4)) {
            if (arg2->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg2);
            }
            if (arg3->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg3);
            }
            if (arg4->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg4);
            }
            if (arg5->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg5);
            }
        }
    } else if (arg1->z < var_fv1) {
        if ((!(arg2->z <= var_fv1) || !(arg3->z <= var_fv1) || !(arg4->z <= var_fv1) || !(arg5->z <= var_fv1)) && (var_v1 == 4)) {
            if (var_fv0 <= arg2->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg2);
            }
            if (var_fv0 <= arg3->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg3);
            }
            if (var_fv0 <= arg4->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg4);
            }
            if (var_fv0 <= arg5->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg5);
            }
        }
    } else if ((var_v1 == 0) || (var_v0 == 0)) {
        if (var_v1 == 4) {
            if (var_fv0 <= arg2->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg2);
            }
            if (var_fv0 <= arg3->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg3);
            }
            if (var_fv0 <= arg4->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg4);
            }
            if (var_fv0 <= arg5->z) {
                func_uvterra_rom_0040C998(arg1, var_fv0, arg5);
            }
        } else if (var_v0 == 4) {
            if (arg2->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg2);
            }
            if (arg3->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg3);
            }
            if (arg4->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg4);
            }
            if (arg5->z <= var_fv1) {
                func_uvterra_rom_0040C998(arg1, var_fv1, arg5);
            }
        }
    }
}

void func_uvterra_rom_0040C998(Vec3F* arg0, f32 arg1, Vec3F* arg2) {
    f32 temp_fv0;
    Vec3F sp18;

    sp18.x = arg2->x - arg0->x;
    sp18.y = arg2->y - arg0->y;
    sp18.z = arg2->z - arg0->z;
    sUvFVecExports->uvVec3FNormalize(&sp18, &sp18);
    temp_fv0 = ((arg1 - arg0->z) / sp18.z);
    arg2->x = arg0->x + (sp18.x * temp_fv0);
    arg2->y = arg0->y + (sp18.y * temp_fv0);
    arg2->z = arg0->z + (sp18.z * temp_fv0);
}

void func_uvterra_rom_0040CA64(Vec3F **arg0, u8 *arg1) {
    Vec3F *sp104[5] = { NULL, NULL, NULL, NULL, NULL };
    Vec3F *temp_v0;
    Vec3F *var_s4;
    Vec3F spC0[5];
    Vec3F spB4;
    Vec3F spA8 = { 0 };
    s32 spA4;
    s32 var_s1;
    s32 var_fp;
    u8 sp9B;
    u8 temp_v1;
    f32 temp_fv0;
    f32 var_fs0;
    s32 sp7C[5];
    Vec3F* temp_v1_2;

    var_fp = 0;
    var_fs0 = 1000000.0f;
    temp_v1 = *arg1;
    sp7C[0] = sp7C[1] = sp7C[2] = sp7C[3] = 0;
    sp7C[4] = 0;

    for (spA4 = 0; spA4 < temp_v1; spA4++) {
        var_s4 = arg0[spA4];
        if (var_s4->x < var_fs0) {
            var_fs0 = var_s4->x;
            var_fp = spA4;
        }
    }

    var_s4 = arg0[var_fp];
    sp104[0] = var_s4;
    spB4.x = 0.0f;
    spB4.y = 1.0f;
    spB4.z = 0.0f;
    sp9B = 1;
    for (spA4 = 1; spA4 < temp_v1; spA4++) {
        var_fs0 = 1000000.0f;

        for (var_s1 = 0; var_s1 < temp_v1; var_s1++) {
            if (sp7C[var_s1] != 0) {
                continue;
            }
            temp_v0 = arg0[var_s1];
            spA8.x = temp_v0->x - var_s4->x;
            spA8.y = temp_v0->y - var_s4->y;
            spA8.z = 0.0f;
            if (sUvFVecExports->uvVec3FNormalize(&spC0[var_s1], &spA8) != 0) {
                temp_fv0 = sUvFVecExports->uvVec2FDot((Vec2F*)&spB4, (Vec2F*)&spC0[var_s1]);
                if (temp_fv0 < var_fs0) {
                    var_fs0 = temp_fv0;
                    var_fp = var_s1;
                }
            }
        }

        temp_v1_2 = arg0[var_fp];
        if (temp_v1_2 == sp104[0]) {
            break;
        }

        var_s4 = sp104[spA4] = temp_v1_2;
        sp7C[var_fp] = 1;


        spB4.x = -spC0[var_fp].x;
        spB4.y = -spC0[var_fp].y;
        spB4.z = 0.0f;
        sp9B++;
    }

    for (spA4 = 0; spA4 < sp9B; spA4++) {
        arg0[spA4] = sp104[spA4];
    }

    *arg1 = sp9B;
}

s32 func_uvterra_rom_0040CEA8(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 temp_ft2;
    s32 temp_v0;
    s32 var_a2;

    var_a2 = 0;
    if (arg0 == 0) {
        return 1;
    }
    temp_v0 = func_uvterra_rom_0040CF98(arg0, (s16) (s32) (((sUvMathExports->uvAtan2F(arg2 / arg3, arg1 / arg3) + 3.1415927f) * 57.29578f) / 5.625f));
    temp_ft2 = (s32) (arg3 / 15.625f);
    if ((s16) temp_ft2 >= 0x20) {
        if (temp_v0 == 0x1F) {
            var_a2 = 1;
        }
    } else {
        var_a2 = temp_v0 >= (s16) temp_ft2;
    }
    return var_a2;
}

s32 func_uvterra_rom_0040CF98(u8 *arg0, s32 arg1) {
    s32 a2;
    s32 temp_a3;
    s32 temp_lo;
    s32 temp_v1;
    u8 *temp_a1;
    s32 a0;
    temp_lo = arg1 * 5;
    temp_v1 = temp_lo % 8;
    // FAKE
    do {
        a0 = 8;
        temp_a3 = (a0 - temp_v1);
    } while (0);
    
    if (temp_v1 >= 4) {
        a2 = temp_lo / 8;
        temp_a1 = arg0 + a2;
        a0 = (temp_a1[0] & ((1 << (8 - temp_v1)) - 1)) << (5 - (8 - temp_v1));
        a0 |= (temp_a1[1] >> (8 - (5 - (8 - temp_v1))));
    } else {
        a2 = temp_lo / 8;
        a0 = ((s32) ((*(arg0 + a2)) & ((1 << temp_a3) - 1))) >> (temp_a3 + 0x1B);
    }
    return a0;
}

void func_uvterra_rom_0040D050(void) {
    D_uvterra_rom_0040FBCC = sUvSortExports->func_uvsort_rom_00400308(0x50U);
    D_uvterra_rom_0040FBC8 = sUvSortExports->func_uvsort_rom_00400308(0x55U);
    D_uvterra_rom_0040FBD4 = sUvSortExports->func_uvsort_rom_00400308(0x6EU);
    D_uvterra_rom_0040FBD0 = sUvSortExports->func_uvsort_rom_00400308(0x73U);
    sUvSortExports->func_uvsort_rom_00400B24(D_uvterra_rom_0040FBCC, 1, 1);
    sUvSortExports->func_uvsort_rom_00400B24(D_uvterra_rom_0040FBD4, 1, 1);
}

void func_uvterra_rom_0040D128(s32 arg0, s32 arg1, f32 arg2, f32 arg3, void (*arg4 )(s32, UnkSobjDraw* ),
                               s32 arg5, f32 arg6) {
    ParsedUVTR *var_v1;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    s32 var_v0;

    var_a1 = func_uvterra_rom_00400774(arg0);
    if (var_a1 != 0xFFFF) {
        var_v1 = uvGetLoadedFile('UVTR', var_a1);
    } else {
        var_v1 = NULL;
    }
    if (var_v1 != NULL) {
        if ((arg2 < var_v1->unk0.unk0) || (var_v1->unk0.unkC <= arg2) || ((arg3 < var_v1->unk0.unk4))
            || (var_v1->unk0.unk10 <= arg3)) {
            var_a1 = 0xFFFF;
        } else {
            var_v0 = ((s32) (arg2 - var_v1->unk0.unk0)) / ((s32) var_v1->unk1C);
            var_a0 = ((s32) (arg3 - var_v1->unk0.unk4) / (s32) var_v1->unk20);
            var_a1 = (var_v1->unk18 * var_a0) + var_v0;
        }
    } else {
        var_a1 = 0xFFFF;
    }
    if (var_a1 == 0xFFFF) {
        var_v0 = D_uvterra_rom_0040D710 < arg6;
    } else {
        var_v0 = 0;
        if (D_uvterra_rom_0040D710 != -1.0f) {
            var_v0 = D_uvterra_rom_0040F7A0[var_a1];
        } else {
            var_v0 = 0;
        }
    }

    if (var_v0 != 0) {
        if (arg1 != 0) {
            var_a0 = D_uvterra_rom_0040FBC8;
        } else {
            var_a0 = D_uvterra_rom_0040FBCC;
        }
    } else if (arg1 != 0) {
        var_a0 = D_uvterra_rom_0040FBD0;
    } else {
        var_a0 = D_uvterra_rom_0040FBD4;
    }
    sUvSortExports->func_uvsort_rom_00400834(var_a0, (void *(*)(s32, s32))arg4, arg5, arg6);
}

s32 D_uvterra_rom_0040F738[] = {0x00BC0000, __entrypoint_func_uvterra_rom_400000};
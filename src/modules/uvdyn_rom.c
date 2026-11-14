// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

/*
    D_uvdyn_rom_00411F70 = uvLoadModule('FMTX');
    D_uvdyn_rom_00411F74 = uvLoadModule('FVEC');
    D_uvdyn_rom_00411F78 = uvLoadModule('QUAT');
    D_uvdyn_rom_00411F80 = uvLoadModule('MATH');
    D_uvdyn_rom_00411F7C = uvLoadModule('isct');
    D_uvdyn_rom_00411F84 = uvLoadModule('DOBJ');
    D_uvdyn_rom_00411F88 = uvLoadModule('TERR');
    D_uvdyn_rom_00411F8C = uvLoadModule('ISCT');
    D_uvdyn_rom_00411F90 = uvLoadModule('MODL');
    D_uvdyn_rom_00411F94 = uvLoadModule('QERY');
*/

struct UnkStruct_uvdyn_rom_00411DC0_s;

typedef struct UnkStruct_uvdyn_rom_00411EC8_s {
    char pad[0xF7A0];
} UnkStruct_uvdyn_rom_00411EC8;

typedef struct UnkStruct_uvdyn_rom_00411EF0_s {
    char pad[0xF7A0];
} UnkStruct_uvdyn_rom_00411EF0;

typedef struct UnkStruct_uvdyn_rom_00403294_s {
    Vec3F unk0;
    f32 unkC;
} UnkStruct_uvdyn_rom_00403294;

typedef struct Unk1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Unk1; // uvBox?

typedef struct Unk2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Unk2;

typedef struct UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8_unk4_s {
    u8 pad0[0x18];
    s32 unk18;
} UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8_unk4;

typedef struct UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8_s {
    s32 unk0;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8_unk4 *unk4[5];
    s32 unk18;
} UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8;

typedef struct UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_s {
    s32 unk0;
    s32 unk4;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8 unk8;
} UnkStruct_uvdyn_rom_00409CE4_unkC_unk18;

typedef struct UnkStruct_uvdyn_rom_00409CE4_unkC_s {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ char pad10[8];                       /* maybe part of unkC[3]? */
    /* 0x18 */ UnkStruct_uvdyn_rom_00409CE4_unkC_unk18 *unk18;
} UnkStruct_uvdyn_rom_00409CE4_unkC;                /* size = 0x1C */

typedef struct UnkStruct_uvdyn_rom_00409CE4_s {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ struct UnkStruct_uvdyn_rom_00411DC0_s *unk8;  /* inferred */
    /* 0x0C */ UnkStruct_uvdyn_rom_00409CE4_unkC *unkC;
} UnkStruct_uvdyn_rom_00409CE4;                     /* size = 0x10 */

typedef struct UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA4_s {
    s32 unk0;
} UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA4;

typedef struct UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA8_s {
    char pad[0x78];
} UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA8;

typedef struct UnkStruct_uvdyn_rom_00411DC0_unk14_s {
    /* 0x0000 */ char pad0[0x10];
    /* 0x0010 */ s32 unk10;                         /* inferred */
    /* 0x0014 */ s32 unk14[30];                  /* maybe part of unk10[0x1F]s32 */
    /* 0x008C */ f32** unk8C;                       /* inferred */
    /* 0x0090 */ f32* unk90;                       /* inferred */
    /* 0x0094 */ s32 unk94;
    /* 0x0098 */ struct UnkStruct_uvdyn_rom_00411DC0_s* unk98[1];                       /* inferred */
    /* 0x009C */ char pad9C[0xBB18];                /* maybe part of unk98[0x2EC7]s32 */
    /* 0xBBB4 */ s32 unkBBB4[1];
    /* 0xBBB8 */ char padBBB8[0x74];                /* maybe part of unkBBB4[0x1E]? */
    /* 0xBC2C */ u16 unkBC2C[1];
    /* 0xBC2E */ char padBC2E[0x3A];                /* maybe part of unkBC2C[0x1E]? */
    /* 0xBC68 */ u16 unkBC68[1];
    /* 0xBC6A */ char padBC6A[0x3A];                /* maybe part of unkBC68[0x1E]? */
    /* 0xBCA4 */ UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA4 unkBCA4[1];
    /* 0xBCA8 */ char padBCA8[0x74];                /* maybe part of unkBCA4[0x1E]? */
    /* 0xBD1C */ UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA8 unkBD1C[1];
    /* 0xBD94 */ char padBD94[0x39A8];              /* maybe part of unkBD1C[0x7C]? */
    /* 0xF73C */ u16 unkF73C;                       /* inferred */
    /* 0xF73E */ u16 unkF73E;                       /* inferred */
    /* 0xF740 */ u16 unkF740;                       /* inferred */
    /* 0xF742 */ char padF742[2];
    /* 0xF744 */ u16 unkF744;                       /* inferred */
    /* 0xF746 */ char padF746[0x36];                /* maybe part of unkF744[0x1C]? */
} UnkStruct_uvdyn_rom_00411DC0_unk14;               /* size = 0xF77C */

typedef struct UnkStruct_uvdyn_rom_00411DC0_unk3AC_s {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x18];                    /* maybe part of unk4[7]? */
    /* 0x020 */ f32 unk20;                          /* inferred */
    /* 0x024 */ char pad24[0x14C];                  /* maybe part of unk20[0x54]? */
} UnkStruct_uvdyn_rom_00411DC0_unk3AC;              /* size = 0x170 */

typedef struct UnkStruct_uvdyn_rom_00411DC0_unk12A0_s {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 dobj;
    /* 0x10 */ char pad10[4];
    /* 0x14 */ Vec3F unk14;
    /* 0x20 */ char pad20[0xC];
    /* 0x2C */ f32 unk2C;                           /* inferred */
    /* 0x30 */ char pad30[4];
    /* 0x34 */ Vec3F unk34;
} UnkStruct_uvdyn_rom_00411DC0_unk12A0;             /* size = 0x40 */


typedef struct UnkStruct_uvdyn_rom_00411DC0_unk0_s {
    s32 unk0;
    s32 unk4;
    u16 unk8;
    u16 unkA;
} UnkStruct_uvdyn_rom_00411DC0_unk0;

typedef struct UnkStruct_uvdyn_rom_00411DC0_s {
    /* 0x0000 */ UnkStruct_uvdyn_rom_00411DC0_unk0 unk0;
    /* 0x000C */ char padC[4];
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ UnkStruct_uvdyn_rom_00411DC0_unk14* unk14;
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ UnkStruct_uvdyn_rom_00409CE4* unk1C[1];
    /* 0x0020 */ char pad20[4];
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ s32 unk2C;
    /* 0x0030 */ char pad30[8];                     /* maybe part of unk2C[3]? */
    /* 0x0038 */ s32 unk38;
    /* 0x003C */ char pad3C[0x370];                 /* maybe part of unk38[0xDD]? */
    /* 0x03AC */ UnkStruct_uvdyn_rom_00411DC0_unk3AC unk3AC[1];
    /* 0x051C */ char pad51C[0xCF0];                /* maybe part of unk3AC[0xA]? */
    /* 0x120C */ s32 unk120C;
    /* 0x1210 */ u16 unk1210;
    /* 0x1212 */ char pad1212[2];
    /* 0x1214 */ s32 unk1214[4];
    /* 0x1224 */ u16 unk1224[4];
    /* 0x122C */ s32 unk122C[4];
    /* 0x123C */ Vec3F unk123C[1];
    /* 0x1248 */ char pad1248[0x2C];                /* maybe part of unk123C[4]? */
    /* 0x1274 */ s32 unk1274;
    /* 0x1278 */ s32 unk1278[4];
    /* 0x1288 */ u16 unk1288[4];
    /* 0x1290 */ s32 unk1290[4];
    /* 0x12A0 */ UnkStruct_uvdyn_rom_00411DC0_unk12A0* unk12A0[4];
    /* 0x12B0 */ f32 unk12B0;
    /* 0x12B4 */ u16 unk12B4;
    /* 0x12B6 */ u16 unk12B6;
    /* 0x12B8 */ f32 unk12B8;
    /* 0x12BC */ f32 unk12BC;
    /* 0x12C0 */ Vec3F unk12C0;
    /* 0x12CC */ u16 unk12CC;                       /* inferred */
    /* 0x12CE */ u16 unk12CE;                       /* inferred */
    /* 0x12D0 */ u16 unk12D0;
    /* 0x12D2 */ u16 unk12D2;
    /* 0x12D4 */ u16 unk12D4;                       /* inferred */
    /* 0x12D6 */ s16 unk12D6;                       /* inferred */
    /* 0x12D8 */ u16 unk12D8;
    /* 0x12DA */ u16 unk12DA;
    /* 0x12DC */ Vec3F unk12DC;
    /* 0x12E8 */ f32 unk12E8;
    /* 0x12EC */ Mtx4F unk12EC;
    /* 0x132C */ Mtx4F unk132C;
    /* 0x136C */ Mtx4F unk136C;
    /* 0x13AC */ char pad13AC[0x40];
    /* 0x13EC */ Mtx4F unk13EC;
    /* 0x142C */ Mtx4F unk142C;
    /* 0x146C */ Vec3F unk146C;
    /* 0x1478 */ Vec3F unk1478;
    /* 0x1484 */ s32 unk1484;
    /* 0x1488 */ f32 unk1488;
    /* 0x148C */ f32 unk148C;
    /* 0x1490 */ Vec3F unk1490;
    /* 0x149C */ f32 unk149C;
    /* 0x14A0 */ char pad14A0[8];                   /* maybe part of unk149C[3]? */
    /* 0x14A8 */ s32 unk14A8;
    /* 0x14AC */ f32 unk14AC;
    /* 0x14B0 */ f32 unk14B0;
    /* 0x14B4 */ f32 unk14B4;                       /* inferred */
    /* 0x14B8 */ s32 unk14B8;
    /* 0x14BC */ Vec3F unk14BC;
    /* 0x14C8 */ Vec3F unk14C8;
    /* 0x14D4 */ char pad14D4[0xC];
    /* 0x14E0 */ Vec3F unk14E0;
    /* 0x14EC */ Vec3F unk14EC;
    /* 0x14F8 */ char pad14F8[0xC];
    /* 0x1504 */ Vec3F unk1504;
    /* 0x1510 */ Vec3F unk1510;
    /* 0x151C */ u16 unk151C;
    /* 0x151E */ u16 unk151E;
    /* 0x1520 */ f32 unk1520;
    /* 0x1524 */ f32 unk1524;
    /* 0x1528 */ f32 unk1528;
    /* 0x152C */ Vec3F unk152C;
    /* 0x1538 */ Vec3F unk1538;
    /* 0x1544 */ u16 unk1544;
    /* 0x1546 */ char pad1546[6];                   /* maybe part of unk1544[4]? */
    /* 0x154C */ u16 unk154C;
    /* 0x154E */ char pad154E[2];
    /* 0x1550 */ void (*unk1550[0xA])(UnkStruct_uvdyn_rom_00411DC0_unk0*, s32);
    /* 0x1578 */ s32 unk1578[0xA];
} UnkStruct_uvdyn_rom_00411DC0;                     /* size = 0x15A0 */

typedef struct UnkIsectExports1_s {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ void (*unk20)(UnkStruct_uvdyn_rom_00409CE4_unkC*, s32, Mtx4F*);
    /* 0x24 */ char pad24[0x14];                    /* maybe part of unk20[6]? */
    /* 0x38 */ void (*unk38)(UnkStruct_uvdyn_rom_00409CE4_unkC*, s32);
    /* 0x3C */ char pad3C[0x14];                    /* maybe part of unk38[6]? */
    /* 0x50 */ u16 (*unk50)(Vec3F*, s32, s32, s32, UnkStruct_uvdyn_rom_00411DC0_unk12A0*);
    /* 0x54 */ char pad54[0x10];                    /* maybe part of unk50[0xC]? */
    /* 0x64 */ void (*unk64)(s32);
    /* 0x68 */ char pad68[0x18];
    /* 0x80 */ void (*unk80)(f32);                     /* inferred */
    /* 0x84 */ s32 (*unk84)(s32, s32, s32);
    /* 0x88 */ char pad88[0xC];                     /* maybe part of unk84[4]? */
    /* 0x94 */ void (*unk94)(UnkStruct_uvdyn_rom_00411DC0_unk12A0*, Vec3F*, s32);
    /* 0x98 */ char pad98[0x10];                    /* maybe part of unk94[5]? */
    /* 0xA8 */ s32 (*unkA8)(Vec3F*, s32, s32, s32, s32*);
    /* 0xAC */ char padAC[0x20];                    /* maybe part of unkA8[9]? */
} UnkIsectExports1;                                  /* size = 0xCC */

// exports
extern UvFMtx_Rom_Exports *D_uvdyn_rom_00411F70;
extern UvFVec_Rom_Exports *D_uvdyn_rom_00411F74;
extern UvQuat_Exports *D_uvdyn_rom_00411F78;
extern UvMath_Exports *D_uvdyn_rom_00411F80;
extern UnkIsectExports1 *D_uvdyn_rom_00411F7C; // uvisect_rom exports
extern UvDobj_Exports *D_uvdyn_rom_00411F84;
extern UvTerra_Exports *D_uvdyn_rom_00411F88;
extern UvIntersect_Exports *D_uvdyn_rom_00411F8C;
extern UvModel_Exports *D_uvdyn_rom_00411F90;
extern UvQuery_Exports *D_uvdyn_rom_00411F94;
extern UnkStruct_uvdyn_rom_00411DC0 *D_uvdyn_rom_00411DC0[];
extern UnkStruct_uvdyn_rom_00411EC8 *D_uvdyn_rom_00411EC8[];
extern UnkStruct_uvdyn_rom_00411EF0 *D_uvdyn_rom_00411EF0[];
extern u16 D_uvdyn_rom_00411F18;
extern u16 D_uvdyn_rom_00411F1A;
extern f32 D_uvdyn_rom_00411DB4;
extern f32 *D_uvdyn_rom_00411DB8;
extern u16 D_uvdyn_rom_00411DE8;

void func_uvdyn_rom_0040BC48(UnkStruct_uvdyn_rom_00411EC8 *); /* extern */
void func_uvdyn_rom_0040BCE4(UnkStruct_uvdyn_rom_00411EF0 *);
s32 func_uvdyn_rom_00400E40(u16 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, f32 *arg5, f32 *arg6,
                            s32 *arg7, s32 *arg8, u16 *arg9);
void func_uvdyn_rom_004034C8(UnkStruct_uvdyn_rom_00403294 *arg0, Vec3F *arg1, Vec3F *arg2, f32 arg3);
void func_uvdyn_rom_00404538(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00411DC0_unk14* arg1);
void func_uvdyn_rom_00403860(UnkStruct_uvdyn_rom_00411DC0 *); /* extern */
void func_uvdyn_rom_00403A1C(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1, f32 arg2);
void func_uvdyn_rom_00403D90(UnkStruct_uvdyn_rom_00411DC0 *, s32, Vec3F); /* extern */
void func_uvdyn_rom_00407C04(UnkStruct_uvdyn_rom_00411DC0*); /* extern */
void func_uvdyn_rom_004094CC(UnkStruct_uvdyn_rom_00411DC0*); 
void func_uvdyn_rom_004041CC(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1, Mtx4F* arg2);
Mtx4F* func_uvdyn_rom_00404384(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1);
void func_uvdyn_rom_004044E4(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00403294* arg1);
void func_uvdyn_rom_00404674(UnkStruct_uvdyn_rom_00411DC0*, UnkStruct_uvdyn_rom_00409CE4*); 
void func_uvdyn_rom_004045B0(UnkStruct_uvdyn_rom_00411DC0 *arg0, UnkStruct_uvdyn_rom_00409CE4 *arg1);
s32 func_uvdyn_rom_0040F78C(UnkStruct_uvdyn_rom_00411DC0_unk14*, Vec3F*, s32, UnkStruct_uvdyn_rom_00411DC0_unk12A0*, s32, s32, s32, s32, s32); /* extern */
void func_uvdyn_rom_00410AEC(UnkStruct_uvdyn_rom_00411DC0_unk14*, u16, u16, u16, s32); /* extern */
u16 func_uvdyn_rom_00409010(UnkStruct_uvdyn_rom_00411DC0*); /* extern */
u16 func_uvdyn_rom_0040FC88(UnkStruct_uvdyn_rom_00411DC0_unk14*, f32*, f32*, s32, f32, Vec3F*); /* extern */
u16 func_uvdyn_rom_00410250(UnkStruct_uvdyn_rom_00411DC0_unk14*, s32, Vec3F*, s32, UnkStruct_uvdyn_rom_00411DC0*); /* extern */
u16 func_uvdyn_rom_004107FC(UnkStruct_uvdyn_rom_00411DC0_unk14*, s32, Vec3F*); /* extern */
void func_uvdyn_rom_00410A88(UnkStruct_uvdyn_rom_00411DC0_unk14*, u16, u16); /* extern */


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/__entrypoint_func_uvdyn_rom_400000.s")

void func_uvdyn_rom_00400564(void) {
    uvUnloadModule('FMTX');
    uvUnloadModule('FVEC');
    uvUnloadModule('QUAT');
    uvUnloadModule('MATH');
    uvUnloadModule('isct');
    uvUnloadModule('DOBJ');
    uvUnloadModule('TERR');
    uvUnloadModule('ISCT');
    uvUnloadModule('MODL');
    uvUnloadModule('QERY');
}

void func_uvdyn_rom_004005F4(void) {
    u16 i;

    for (i = 0; i < D_uvdyn_rom_00411F18; i++) {
        func_uvdyn_rom_0040BC48(D_uvdyn_rom_00411EC8[i]);
    }
}

void func_uvdyn_rom_00400664(void) {
    u16 i;

    for (i = 0; i < D_uvdyn_rom_00411F1A; i++) {
        func_uvdyn_rom_0040BCE4(D_uvdyn_rom_00411EF0[i]);
    }
}

void func_uvdyn_rom_004006D4(s32 arg0, f32 arg1) {
    if (arg0 == 0) {
        D_uvdyn_rom_00411DB4 = arg1;
    }
}

f32 func_uvdyn_rom_004006EC(s32 arg0) {
    if (arg0 == 0) {
        return D_uvdyn_rom_00411DB4;
    }
    return -1.0f;
}

f32 *func_uvdyn_rom_00400710(void) {
    return &D_uvdyn_rom_00411DB4;
}

// .rodata
extern f32 D_uvdyn_rom_00411A68;

void func_uvdyn_rom_0040071C(s32 arg0, Mtx4F *arg1, Mtx4F *arg2, Vec3F *arg3, Vec3F *arg4, Vec3F *arg5,
                             Vec3F *arg6, Vec3F *arg7, f32 arg8) {
    f32 spC4;
    f32 spC0;
    s32 pad;
    f32 spB8;
    Vec3F spAC;
    Mtx4F sp6C;
    Mtx4F sp2C;

    spC4 = 0.5f * arg8;
    spAC.x = (arg7->x + arg5->x) * 0.5f;
    spAC.y = (arg7->y + arg5->y) * 0.5f;
    spAC.z = (arg7->z + arg5->z) * 0.5f;
    spC0 = D_uvdyn_rom_00411F74->uvVec3FLen(&spAC);
    if (spC0 > D_uvdyn_rom_00411A68) { // 0.00001f
        D_uvdyn_rom_00411F74->uvVec3FScale(&spAC, &spAC, 1.0f / spC0);
        spC0 *= spC4;
        spB8 = D_uvdyn_rom_00411F80->uvCosF(spC0);
        spC0 = D_uvdyn_rom_00411F80->uvSinF(spC0);
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_0040246C(&sp2C, spC0 * spAC.x, spC0 * spAC.y,
                                                       spC0 * spAC.z, spB8);
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(&sp6C, &sp2C);
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_00403290(&sp6C, arg1, &sp6C);
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_00400588(arg1, &sp6C);
    }
    if (arg0 == 0) {
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg1, arg4, arg3);
    }
    arg1->m[3][0] += spC4 * (arg4->x + arg6->x);
    arg1->m[3][1] += spC4 * (arg4->y + arg6->y);
    arg1->m[3][2] += spC4 * (arg4->z + arg6->z);
    D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(arg2, arg1);
    if (arg0 == 1) {
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg2, arg3, arg4);
    }
}

void func_uvdyn_rom_004009BC(Mtx4F *arg0, Mtx4F *arg1, Mtx4F *arg2) {
    D_uvdyn_rom_00411F70->uvMat4InvertTranslationRotation(arg0, arg2);
    D_uvdyn_rom_00411F70->uvMat4Mul(arg0, arg1, arg0);
}

// .rodata
extern f32 D_uvdyn_rom_00411A6C;
extern f32 D_uvdyn_rom_00411A70;

void func_uvdyn_rom_00400A14(Mtx4F *arg0, Mtx4F *arg1, Vec3F *arg2, Vec3F *arg3, Vec3F *arg4,
                             UNUSED s32 arg5, UNUSED s32 arg6, f32 arg7) {
    f32 temp;
    f32 pad;
    f32 temp_fv0;
    Mtx4F sp7C;
    Mtx4F sp3C;
    Quat sp2C;
    Vec3F sp20;

    D_uvdyn_rom_00411F74->uvVec3FSub(&sp20, arg0->m[3], arg1->m[3]);
    if (D_uvdyn_rom_00411A6C < D_uvdyn_rom_00411F74->uvVec3FLen(&sp20)) {
        D_uvdyn_rom_00411F74->uvVec3FScale(arg3, &sp20, 1.0f / arg7);
    } else {
        arg3->x = 0.0f;
        arg3->y = 0.0f;
        arg3->z = 0.0f;
    }
    D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(&sp7C, arg0);
    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(&sp7C, arg2, arg3);
    D_uvdyn_rom_00411F70->func_uvfmtx_rom_00403290(&sp3C, &sp7C, arg1);
    D_uvdyn_rom_00411F78->func_uvquat_rom_004000D8(&sp2C, &sp3C);
    temp_fv0 = D_uvdyn_rom_00411F74->uvVec3FLen((Vec3F *) &sp2C);
    if (D_uvdyn_rom_00411A70 < temp_fv0) {
        temp = D_uvdyn_rom_00411F80->uvAtan2F(temp_fv0, sp2C.w) / (0.5f * arg7) / temp_fv0;
        D_uvdyn_rom_00411F74->uvVec3FScale(arg4, (Vec3F *) &sp2C, temp);
        return;
    }
    arg4->x = 0.0f;
    arg4->y = 0.0f;
    arg4->z = 0.0f;
}

s32 func_uvdyn_rom_00400C08(s32 arg0, s32 arg1, f32 *arg2, Vec3F *arg3, Vec3F *arg4, u16 arg5) {
    u16 i;
    u16 spBC;
    f32 var_fa0;
    f32 var_fv1;
    f32 spA8[3];
    Vec3F sp9C;
    Vec3F sp90;
    s32 sp84[3];
    s32 sp78[3];
    f32 temp_fv0;

    spBC = 0;
    if (arg5 == 0) {
        return 0;
    }

    D_uvdyn_rom_00411F74->uvVec3FCopy(&sp90, arg4);
    for (i = 1; i < arg5; i++) {
        D_uvdyn_rom_00411F74->uvVec3FAdd(&sp90, &sp90, &arg4[i]);
    }

    if (D_uvdyn_rom_00411F74->uvVec3FNormalize(&sp90, &sp90) == 0) {
        sp90.x = 0.0f;
        sp90.y = 0.0f;
        sp90.z = 1.0f;
    }

    for (i = 0; i < arg5; i++) {
        temp_fv0 = D_uvdyn_rom_00411F74->uvVec3FDot(&sp90, &arg4[i]);
        if (temp_fv0 == 0) {
            var_fv1 = arg2[i];
            var_fa0 = 1.0f;
        } else {
            var_fv1 = arg2[i];
            var_fa0 = var_fv1 / temp_fv0;
        }
        func_uvdyn_rom_00400E40(0, var_fa0, var_fv1, &arg3[i], &arg4[i], sp9C.f, spA8, sp84, sp78,
                                &spBC);
    }
    return func_uvdyn_rom_00401014(0, arg0, arg1, &sp90, &sp9C, spA8, sp84, sp78, spBC, 0);
}

s32 func_uvdyn_rom_00400E40(u16 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, f32 *arg5, f32 *arg6,
                            s32 *arg7, s32 *arg8, u16 *arg9) {
    u16 i;
    s32 var_v1;
    u16 j;
    u16 var_a1;

    var_v1 = -1;
    var_a1 = *arg9;
    for (i = 0; i < var_a1; i++) {
        if (arg5[i] < arg1) {
            if (var_a1 < (3 - arg0)) {
                var_a1++;
            }
            for (j = var_a1 - 1; j > i; j--) {
                u16 prev = j - 1;
                arg5[j] = arg5[prev];
                arg6[j] = arg6[prev];
                arg7[j] = arg7[prev];
                arg8[j] = arg8[prev];
            }
            arg5[i] = arg1;
            arg6[i] = arg2;
            arg7[i] = arg3;
            arg8[i] = arg4;
            var_v1 = i;
            break;
        }
    }

    if (i >= var_a1) {
        if (var_a1 < (3 - arg0)) {
            arg5[var_a1] = arg1;
            arg6[var_a1] = arg2;
            arg7[var_a1] = arg3;
            arg8[var_a1] = arg4;
            var_v1 = var_a1;
            var_a1++;
        }
    }
    *arg9 = var_a1;
    return var_v1;
}

#ifdef NEEDS_RODATA
s32 func_uvdyn_rom_00401014(u16 arg0, Mtx4F *arg1, Mtx4F *arg2, Vec3F *arg3, f32 *arg4, f32 *arg5,
                            Vec3F **arg6, Vec3F **arg7, u16 arg8, u16 arg9) {
    Vec3F sp104;
    Vec3F spF8;
    Vec3F spEC;
    s32 pad;
    Vec3F spDC;
    Vec3F spD0;
    f32 spCC;
    s32 tempStackPad[2];
    f32 spC0;
    f32 var_fa0;
    f32 spB8;
    f32 spB4;
    f32 var_fs0;
    f32 var_fs1;
    f32 spA8;
    u16 spA6;
    u16 i; // spA4
    u16 j;
    u16 spA0;

    spA0 = 0;
    spA6 = arg0 + arg8;
    spB4 = 0;
    for (i = arg0; i < spA6; i++) {
        switch (i) {
            case 0:
                if (!((arg5[spA6 - 1] < 0.00001) && (-0.00001 < arg5[spA6 - 1]))) {
                    if (arg9 != 0) {
                        D_uvdyn_rom_00411F74->uvVec3FScale(&spF8, arg7[spA6 - 1], arg4[spA6 - 1]);
                    } else {
                        D_uvdyn_rom_00411F74->uvVec3FScale(&spF8, arg3, arg4[spA6 - 1]);
                    }
                    D_uvdyn_rom_00411F74->uvVec3FAdd((Vec3F *) arg1->m[3], (Vec3F *) arg1->m[3], &spF8);
                }
                if ((spA6 == 1) || (arg9 != 0)) {
                    return 1;
                }
                if (!((arg5[spA6 - 1] < 0.00001) && (-0.00001 < arg5[spA6 - 1]))) {
                    for (j = 0; j < spA6; j++) {
                        arg5[j] -= D_uvdyn_rom_00411F74->uvVec3FDot(&spF8, arg7[j]);
                    }
                }
                break;
            case 1:
                if (!((arg5[spA6 - 2] < 0.00001) && (-0.00001 < arg5[spA6 - 2]))) {
                    var_fs1 = 1.0f - D_uvdyn_rom_00411F74->uvVec3FDot(arg7[spA6 - 2], arg7[spA6 - 1]);
                    D_uvdyn_rom_00411F74->uvVec3FSub(&spEC, arg6[spA6 - 2], arg6[spA6 - 1]);
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg1, &spEC, &spEC);
                    var_fs0 = D_uvdyn_rom_00411F74->uvVec3FDot(&spEC, arg7[spA6 - 2]);
                    spA8 = D_uvdyn_rom_00411F74->uvVec3FLen(&spEC);
                    D_uvdyn_rom_00411F74->uvVec3FScale(&spEC, &spEC, 1.0f / spA8);
                    D_uvdyn_rom_00411F74->uvVec3FCross(&spDC, &spEC, arg3);
                    D_uvdyn_rom_00411F74->uvVec3FNormalize(&spDC, &spDC);
                    if (0.00001f < ABS_2(var_fs0)) {
                        if (0.00001f < var_fs1) {
                            spB4 = (arg5[spA6 - 2] / var_fs0) + 1.0f;
                        } else {
                            spB4 = 0;
                        }
                        D_uvdyn_rom_00411F74->uvVec3FCross(&spD0, arg7[spA6 - 2], &spDC);
                        D_uvdyn_rom_00411F74->uvVec3FNormalize(&spD0, &spD0);
                        var_fs0 = ABS_2(D_uvdyn_rom_00411F74->uvVec3FDot(&spEC, &spD0));

                        if (spB4 < 0) {
                            var_fs0 = -var_fs0;
                        }
                        if (var_fs0 < -1.0f) {
                            var_fs0 = -1.0f;
                        } else if (var_fs0 > 1.0f) {
                            var_fs0 = 1.0f;
                        }
                        spC0 = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(var_fs0));
                        if (var_fs1 < 0.00001f) {
                            var_fs1 = spC0;
                            spA0 = 1;
                            spCC = ABS_2(var_fs0);
                        } else {
                            spB8 = spC0 * spB4;
                            if (spB8 < -1.0f) {
                                spB8 = -1.0f;
                            } else if (spB8 > 1.0f) {
                                spB8 = 1.0f;
                            }
                            var_fa0 = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(spB8));
                            if (spB4 > 0) {
                                var_fa0 = -var_fa0;
                            }
                            var_fs1 = (spC0 * var_fa0) + (var_fs0 * spB8);
                            if ((ABS_2(var_fs1) - 1.0f) < 0.00001f) {
                                spA0 = 1;
                                if (var_fs1 < -1.0f) {
                                    var_fs1 = -1.0f;
                                } else if (var_fs1 > 1.0f) {
                                    var_fs1 = 1.0f;
                                }
                            } else {
                                return 0;
                            }
                            spCC = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(var_fs1));
                        }

                        if (arg5[spA6 - 2] < 0.0f) {
                            var_fs1 = -var_fs1;
                        }
                    } else {
                        spA0 = 1;
                        if (!((spA8 < 0.00001) && (-0.00001 < spA8))) {
                            var_fs1 = arg5[spA6 - 2] / spA8;
                            if (var_fs1 < -1.0f) {
                                var_fs1 = -1.0f;
                            } else if (var_fs1 > 1.0f) {
                                var_fs1 = 1.0f;
                            }
                            spCC = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(var_fs1));
                        } else {
                            var_fs1 = 0.0f;
                            spCC = 1.0f;
                        }
                    }
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg2, &spDC, &spDC);
                    if (spA6 == 3) {
                        D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(arg1, &spEC, arg6[0]);
                    }
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_00403568(arg1, arg6[spA6 - 1],
                                                                   (Mtx4F *) &spDC, var_fs1, spCC);
                    if (spA6 == 2) {
                        D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(arg2, arg1);
                    }
                }

                if (spA6 == 2) {
                    return 1;
                }

                if (spA0) {
                    D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(arg1, &spF8, arg6[0]);
                    D_uvdyn_rom_00411F74->uvVec3FSub(&spF8, &spF8, &spEC);
                    *arg5 -= D_uvdyn_rom_00411F74->uvVec3FDot(&spF8, *arg7);
                }
                break;
            case 2:
                if (!((*arg5 < 0.00001) && (-0.00001 < *arg5))) {
                    var_fs1 = 1.0f - D_uvdyn_rom_00411F74->uvVec3FDot(arg3, *arg7);
                    D_uvdyn_rom_00411F74->uvVec3FSub(&spDC, arg6[1], arg6[2]);
                    D_uvdyn_rom_00411F74->uvVec3FNormalize(&spDC, &spDC);
                    D_uvdyn_rom_00411F74->uvVec3FSub(&spEC, arg6[0], arg6[2]);
                    D_uvdyn_rom_00411F74->uvVec3FScale(&sp104, &spDC,
                                                       D_uvdyn_rom_00411F74->uvVec3FDot(&spEC, &spDC));
                    D_uvdyn_rom_00411F74->uvVec3FAdd(&sp104, &sp104, arg6[2]);
                    D_uvdyn_rom_00411F74->uvVec3FCross(&spD0, &spDC, &spEC);
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg1, &spD0, &spD0);
                    if (D_uvdyn_rom_00411F74->uvVec3FDot(&spD0, *arg7) < 0.0f) {
                        D_uvdyn_rom_00411F74->uvVec3FScale(&spDC, &spDC, -1.0f);
                    }
                    D_uvdyn_rom_00411F74->uvVec3FSub(&spEC, arg6[0], &sp104);
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg1, &spEC, &spEC);
                    if (0.00001f < var_fs1) {
                        spB4 = (*arg5 / D_uvdyn_rom_00411F74->uvVec3FDot(&spEC, *arg7)) + 1.0f;
                    }
                    D_uvdyn_rom_00411F74->uvVec3FNormalize(&spEC, &spEC);
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg1, &spDC, &spDC);
                    D_uvdyn_rom_00411F74->uvVec3FCross(&spD0, *arg7, &spDC);
                    D_uvdyn_rom_00411F74->uvVec3FNormalize(&spD0, &spD0);
                    var_fs0 = ABS_2(D_uvdyn_rom_00411F74->uvVec3FDot(&spEC, &spD0));
                    if (spB4 < 0.0f) {
                        var_fs0 = -var_fs0;
                    }
                    if (var_fs0 < -1.0f) {
                        var_fs0 = -1.0f;
                    } else if (var_fs0 > 1.0f) {
                        var_fs0 = 1.0f;
                    }
                    spC0 = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(var_fs0));
                    if (var_fs1 < 0.00001f) {
                        var_fs1 = spC0;
                        spCC = ABS_2(var_fs0);
                    } else {
                        var_fa0 = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(spC0));
                        ;
                        if (spB4 > 0.0f) {
                            var_fa0 = -var_fa0;
                        }
                        var_fs1 = (spC0 * var_fa0) + (var_fs0 * (spC0 * spB4));
                        if ((FABS(var_fs1) - 1.0f) < 0.00001f) {
                            if (var_fs1 < -1.0f) {
                                var_fs1 = -1.0f;
                            } else if (var_fs1 > 1.0f) {
                                var_fs1 = 1.0f;
                            }
                        } else {
                            return 0;
                        }
                        spCC = D_uvdyn_rom_00411F80->uvSqrtf(1.0f - SQ(var_fs1));
                    }
                    if (*arg5 < 0.0f) {
                        var_fs1 = -var_fs1;
                    }
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(arg2, &spDC, &spDC);
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_00403568(arg1, &sp104, (Mtx4F *) &spDC,
                                                                   var_fs1, spCC);
                    D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(arg2, arg1);
                }
                break;
            default:
                break;
        }
    }

    return 1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00401014.s")
#endif

#ifdef NEEDS_RODATA

s32 func_uvdyn_rom_00401D54(Mtx4F *arg0, Mtx4F *arg1, Mtx4F *arg2, Vec3F *arg3, f32 *arg4, f32 *arg5,
                            Vec3F **arg6, Vec3F **arg7, u16 arg8, u16 arg9) {
    Vec3F sp19C;
    s32 pad;
    Vec3F sp18C;
    Vec3F sp180;
    Vec3F sp174;
    Vec3F sp168;
    Mtx4F sp128;
    Mtx4F spE8;
    f32 temp_fa0_2;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs2_2;
    f32 temp_fs3;
    f32 spC8;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 var_fv0_2;
    s32 pad2;
    u16 spAA;
    u16 i;

    spAA = arg8;
    for (i = 0; i < spAA; i++) {
        switch (i) {
            case 0:
                if (!((arg5[spAA - 1] < 0.00001) && (-0.00001 < arg5[spAA - 1]))) {
                    if (arg9 != 0) {
                        D_uvdyn_rom_00411F74->uvVec3FScale(&sp19C, arg7[spAA - 1], arg4[spAA - 1]);
                    } else {
                        D_uvdyn_rom_00411F74->uvVec3FScale(&sp19C, arg3, arg4[spAA - 1]);
                    }
                    D_uvdyn_rom_00411F74->uvVec3FAdd((Vec3F *) arg1->m[3], (Vec3F *) arg1->m[3],
                                                     &sp19C);
                }
                if ((spAA == 1) || (arg9 != 0)) {
                    return 1;
                }
                *arg5 -= D_uvdyn_rom_00411F74->uvVec3FDot(&sp19C, *arg7);
                break;
            case 1:
                if ((arg5[spAA - 2] < 0.00001) && (-0.00001 < arg5[spAA - 2])) {
                    continue;
                }
                D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(arg1, &sp180, arg6[0]);
                D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(arg1, &sp174, arg6[1]);
                D_uvdyn_rom_00411F74->uvVec3FSub(&sp18C, &sp180, &sp174);
                temp_fv0_2 = D_uvdyn_rom_00411F74->uvVec3FLenSquared(&sp18C);
                temp_fs0 = D_uvdyn_rom_00411F80->uvSqrtf(temp_fv0_2);
                temp_fs2 = D_uvdyn_rom_00411F74->uvVec3FDot(&sp18C, (Vec3F *) arg0->m[0]) / temp_fs0;
                spC8 = (1.0f - SQ(temp_fs2)) * temp_fv0_2;
                temp_fs5 = D_uvdyn_rom_00411F80->uvSqrtf(spC8);
                D_uvdyn_rom_00411F74->uvVec3FScale((Vec3F *) &sp128.m[3], (Vec3F *) arg0->m[0],
                                                   temp_fs0 * temp_fs2);
                D_uvdyn_rom_00411F74->uvVec3FAdd((Vec3F *) &sp128.m[3], (Vec3F *) &sp128.m[3], &sp174);
                D_uvdyn_rom_00411F74->uvVec3FCopy((Vec3F *) &sp128.m[2], (Vec3F *) arg0->m[0]);
                D_uvdyn_rom_00411F74->uvVec3FSub((Vec3F *) &sp128.m[1], &sp180, (Vec3F *) &sp128.m[3]);
                D_uvdyn_rom_00411F74->uvVec3FNormalize((Vec3F *) &sp128.m[1], (Vec3F *) &sp128.m[1]);
                D_uvdyn_rom_00411F74->uvVec3FCross((Vec3F *) &sp128.m[0], (Vec3F *) &sp128.m[1],
                                                   (Vec3F *) arg0->m[0]);
                D_uvdyn_rom_00411F74->uvVec3FNormalize((Vec3F *) &sp128.m[0], (Vec3F *) &sp128.m[0]);
                sp128.m[3][3] = 1.0f;
                sp128.m[0][3] = 0.0f;
                sp128.m[1][3] = 0.0f;
                sp128.m[2][3] = 0.0f;
                D_uvdyn_rom_00411F70->uvMat4InvertTranslationRotation(&spE8, (Mtx4F *) &sp128);
                D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(&spE8, &sp168, *arg7);
                if ((ABS_2(sp168.x) < 0.00001f)) {
                    continue;
                }
                D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(&spE8, &sp180, &sp180);
                temp_fs0_2 = ((sp168.y * (sp180.y + (*arg5 * sp168.y)))
                              - (((*arg5 * sp168.x) + sp180.x) * sp168.x));
                temp_fs3 = sp168.y / sp168.x;
                temp_fs4 = temp_fs0_2 / sp168.x;
                temp_fs1 = 2.0f * ((temp_fs3 * temp_fs3) + 1.0f);
                temp_fs2_2 = -2.0f * temp_fs3 * temp_fs4;
                temp_fs0_2 = SQ(temp_fs2_2) - (2.0f * temp_fs1 * (SQ(temp_fs4) - spC8));
                if (temp_fs0_2 < 0.0f) {
                    continue;
                }
                temp_fv0_3 = D_uvdyn_rom_00411F80->uvSqrtf(temp_fs0_2);
                temp_fv1 = (temp_fv0_3 - temp_fs2_2) / temp_fs1;
                temp_fa0_2 = (-temp_fs2_2 - temp_fv0_3) / temp_fs1;
                if (temp_fa0_2 < temp_fv1) {
                    var_fv0_2 = temp_fv1;
                } else {
                    var_fv0_2 = temp_fa0_2;
                }
                D_uvdyn_rom_00411F70->func_uvfmtx_rom_00403568(
                    arg1, arg6[spAA - 1], arg0, -(temp_fs4 - (var_fv0_2 * temp_fs3)) / temp_fs5,
                    var_fv0_2 / temp_fs5);
                D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(arg2, arg1);
                break;
            default:
                break;
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00401D54.s")
#endif

#ifdef NEEDS_RODATA

void func_uvdyn_rom_0040232C(f32 **arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    f32 var_fa0;
    s32 var_s3;
    f32 var_fv0;
    s32 temp_a2;
    s32 var_a0;
    s32 var_t4;
    s32 var_t5;
    static s32 D_uvdyn_rom_00411D98 = 1;
    static f32 *D_uvdyn_rom_00411FA4;

    if (D_uvdyn_rom_00411D98 != 0) {
        D_uvdyn_rom_00411D98 = 0;
        D_uvdyn_rom_00411FA4 = _uvMemAllocAlign8(0x50);
    }
    var_t4 = 0;
    *arg3 = 1.0f;
    for (var_t4 = 0; var_t4 < arg1; var_t4++) {
        var_fa0 = 0.0f;
        for (var_t5 = 0; var_t5 < arg1; var_t5++) {
            var_fv0 = var_fv0 = FABS(arg0[var_t4][var_t5]);
            if (var_fa0 < var_fv0) {
                var_fa0 = var_fv0;
            }
        }
        if (var_fa0 == 0.0) {
            return;
        }
        D_uvdyn_rom_00411FA4[var_t4] = (1.0 / var_fa0);
    }

    for (var_t5 = 0; var_t5 < arg1; var_t5++) {
        for (var_t4 = 0, var_fa0 = 0.0f; var_t4 < var_t5; var_t4++) {
            var_fv0 = arg0[var_t4][var_t5];
            for (var_a0 = 0; var_a0 < var_t4; var_a0++) {
                var_fv0 -= arg0[var_t4][var_a0] * arg0[var_a0][var_t5];
            }
            arg0[var_t4][var_t5] = var_fv0;
        }

        for (var_t4 = var_t5; var_t4 < arg1; var_t4++) {
            var_fv0 = arg0[var_t4][var_t5];
            for (var_a0 = 0; var_a0 < var_t5; var_a0++) {
                var_fv0 -= arg0[var_t4][var_a0] * arg0[var_a0][var_t5];
            }
            arg0[var_t4][var_t5] = var_fv0;
            var_fv0 = D_uvdyn_rom_00411FA4[var_t4] * FABS(var_fv0);
            if (var_fa0 <= var_fv0) {
                var_fa0 = var_fv0;
                var_s3 = var_t4;
            }
        }

        if (var_t5 != var_s3) {
            for (var_a0 = 0; var_a0 < arg1; var_a0++) {
                var_fv0 = arg0[var_s3][var_a0];
                arg0[var_s3][var_a0] = arg0[var_t5][var_a0];
                arg0[var_t5][var_a0] = var_fv0;
            }

            *arg3 = -*arg3;
            D_uvdyn_rom_00411FA4[var_s3] = D_uvdyn_rom_00411FA4[var_t5];
        }

        arg2[var_t5] = var_s3;
        if (arg0[var_t5][var_t5] == 0.0) {
            arg0[var_t5][var_t5] = D_uvdyn_rom_00411ACC;
        }
        temp_a2 = var_t5 + 1;
        if (arg1 != temp_a2) {
            var_fv0 = 1.0 / arg0[var_t5][var_t5];
            for (var_t4 = temp_a2; var_t4 < arg1; var_t4++) {
                arg0[var_t4][var_t5] *= var_fv0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040232C.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00402BD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00402E38.s")

// .rodata
extern f32 D_uvdyn_rom_00411ADC;
s32 func_uvdyn_rom_00403294(UnkStruct_uvdyn_rom_00403294 *arg0, UnkStruct_uvdyn_rom_00403294 *arg1) {
    f32 temp_fv0_2;
    f32 sp40;
    f32 temp_fv0_3;
    Vec3F sp30;
    f32 temp_fv1;

    temp_fv0_2 =
        D_uvdyn_rom_00411F80->uvSqrtf(SQ(arg0->unk0.x - arg1->unk0.x) + SQ(arg0->unk0.y - arg1->unk0.y)
                                      + SQ(arg0->unk0.z - arg1->unk0.z));
    if ((arg0->unkC + temp_fv0_2) <= arg1->unkC) {
        return 0;
    }
    sp40 = (arg1->unkC + arg0->unkC + temp_fv0_2) * 0.5f;
    D_uvdyn_rom_00411F74->uvVec3FSub(&sp30, &arg0->unk0, &arg1->unk0);
    temp_fv0_3 = D_uvdyn_rom_00411F74->uvVec3FLen(&sp30);
    if (D_uvdyn_rom_00411ADC /*0.00001f*/ < temp_fv0_3) {
        D_uvdyn_rom_00411F74->uvVec3FScale(&sp30, &sp30, (sp40 - arg1->unkC) / temp_fv0_3);
        D_uvdyn_rom_00411F74->uvVec3FAdd(&arg1->unk0, &arg1->unk0, &sp30);
    }
    arg1->unkC = sp40;
    return 1;
}

s32 func_uvdyn_rom_004033F4(Unk1 *arg0, Unk2 *arg1) {
    f32 temp_fv0;
    f32 temp_fa0;

    temp_fv0 = SQ(arg1->unkC);
    temp_fa0 =
        (SQ(arg0->unk0 - arg1->unk0) + SQ(arg0->unk4 - arg1->unk4) + SQ(arg0->unk8 - arg1->unk8));
    if (temp_fa0 > temp_fv0) {
        return 0;
    }

    temp_fa0 =
        (SQ(arg0->unkC - arg1->unk0) + SQ(arg0->unk10 - arg1->unk4) + SQ(arg0->unk14 - arg1->unk8));
    if (temp_fa0 > temp_fv0) {
        return 0;
    }
    return 1;
}

void func_uvdyn_rom_004034C8(UnkStruct_uvdyn_rom_00403294 *arg0, Vec3F *arg1, Vec3F *arg2, f32 arg3) {
    D_uvdyn_rom_00411F74->uvVec3FSub(&arg0->unk0, arg2, arg1);
    D_uvdyn_rom_00411F74->uvVec3FScale(&arg0->unk0, &arg0->unk0, 0.5f);
    arg0->unkC = D_uvdyn_rom_00411F74->uvVec3FLen(&arg0->unk0) + arg3;
    D_uvdyn_rom_00411F74->uvVec3FAdd(&arg0->unk0, arg1, &arg0->unk0);
}

void func_uvdyn_rom_00403574(void) {
    D_uvdyn_rom_00411DB8 = func_uvdyn_rom_00400710();
    D_uvdyn_rom_00411DE8 = 0;
}

UnkStruct_uvdyn_rom_00411DC0 *func_uvdyn_rom_004035A0(void) {
    UnkStruct_uvdyn_rom_00411DC0 *temp_v0;
    Vec3F sp30;

    temp_v0 = _uvMemAllocAlign8(sizeof(UnkStruct_uvdyn_rom_00411DC0));
    uvMemSet(temp_v0, 0, sizeof(UnkStruct_uvdyn_rom_00411DC0));
    D_uvdyn_rom_00411DC0[D_uvdyn_rom_00411DE8] = temp_v0;
    temp_v0->unk0.unk0 = D_uvdyn_rom_00411DE8;
    D_uvdyn_rom_00411DE8 = D_uvdyn_rom_00411DE8 + 1;
    func_uvdyn_rom_00403A1C(temp_v0, 2, 1.0f);
    func_uvdyn_rom_00403A1C(temp_v0, 0xA, 0.02f);
    sp30.x = 1.0f;
    sp30.y = 1.0f;
    sp30.z = 1.0f;
    func_uvdyn_rom_00403D90(temp_v0, 5, sp30);
    sp30.x = 0.0f;
    sp30.y = 0.0f;
    sp30.z = 0.0f;
    func_uvdyn_rom_00403D90(temp_v0, 4, sp30);
    D_uvdyn_rom_00411F70->uvMat4SetIdentity(&temp_v0->unk12EC);
    D_uvdyn_rom_00411F70->uvMat4SetIdentity(&temp_v0->unk13EC);
    D_uvdyn_rom_00411F70->uvMat4SetIdentity(&temp_v0->unk142C);
    temp_v0->unk12B6 = 0;
    temp_v0->unk154C = 0;
    temp_v0->unk1210 = 1;
    temp_v0->unk0.unk4 = -1;
    temp_v0->unk1488 = 0.0f;
    func_uvdyn_rom_00403A1C(temp_v0, 0xE, -1.0f);
    temp_v0->unk14B8 = 0;
    return temp_v0;
}

void func_uvdyn_rom_00403724(UnkStruct_uvdyn_rom_00411DC0 *arg0) {
    u16 i;
    u16 j;

    func_uvdyn_rom_00404538(arg0, 0);
    for (i = 0; i < D_uvdyn_rom_00411DE8; i++) {
        if (arg0 == D_uvdyn_rom_00411DC0[i]) {
            break;
        }
    }

    if (i == D_uvdyn_rom_00411DE8) {
        return;
    }

    D_uvdyn_rom_00411DE8--;

    for (j = i; j < D_uvdyn_rom_00411DE8; j++) {
        D_uvdyn_rom_00411DC0[j] = D_uvdyn_rom_00411DC0[j + 1];
        D_uvdyn_rom_00411DC0[j]->unk0.unk0 = j;
    }
}

void func_uvdyn_rom_004037F0(void) {
    u16 i;

    for (i = 0; i < D_uvdyn_rom_00411DE8; i++) {
        func_uvdyn_rom_00403860(D_uvdyn_rom_00411DC0[i]);
    }
}

void func_uvdyn_rom_00409CE4(void *); /* extern */
void func_uvdyn_rom_00403860(UnkStruct_uvdyn_rom_00411DC0 *arg0) {
    u16 i;
    u16 j;
    UnkStruct_uvdyn_rom_00409CE4 *temp_s0;
    UnkStruct_uvdyn_rom_00409CE4_unkC *temp_a0;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18 *temp_s1;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8 *temp_a0_2;

    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk1478, &arg0->unk146C);
    D_uvdyn_rom_00411F70->uvMat4FCopy(&arg0->unk132C, &arg0->unk12EC);
    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14C8, &arg0->unk14BC);
    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14EC, &arg0->unk14E0);
    if (arg0->unk1544 != 1) {
        arg0->unk1484 |= 1;
    }
    for (i = 0; i < arg0->unk18; i++) {
        temp_s0 = arg0->unk1C[i];
        if (temp_s0 == NULL) {
            continue;
        }

        temp_a0 = temp_s0->unkC;
        if (temp_a0 == NULL) {
            continue;
        }

        temp_s1 = temp_a0->unk18;
        D_uvdyn_rom_00411F7C->unk20(temp_a0, 3, &arg0->unk12EC);
        func_uvdyn_rom_00409CE4(temp_s0);
        if (arg0->unk1544 == 1) {
            continue;
        }
        temp_a0_2 = &temp_s1->unk8;
        if ((temp_s1->unk4 == 0) && (temp_s1->unk8.unk0 != 0)) {
            for (j = 0; j < temp_a0_2->unk0; j++) {
                temp_a0_2->unk4[j]->unk18 |= 1;
            }
        }
    }
    arg0->unk1544 = 1;
}

#ifdef NEEDS_RODATA
void func_uvdyn_rom_00403A1C(UnkStruct_uvdyn_rom_00411DC0 *arg0, s32 arg1, f32 arg2) {
    u16 i;

    if (arg0 == NULL) {
        return;
    }

    switch (arg1) {
        case 2:
            arg0->unk1528 = arg2;
            arg0->unk1524 = arg2;
            arg0->unk1520 = arg2;
            return;
        case 0:
            arg0->unk24 = arg2;
            if (arg0->unk24 == 0) {
                for (i = 0; i < arg0->unk18; i++) {
                    UnkStruct_uvdyn_rom_00409CE4 *v0 = arg0->unk1C[i];
                    if (v0->unkC != NULL) {
                        D_uvdyn_rom_00411F7C->unk38(v0->unkC, arg0->unk28);
                    }
                }
            }
            break;
        case 9:
            arg0->unk14AC = arg2;
            return;
        case 11:
            arg0->unk154C = arg2;
            return;
        case 10:
            arg0->unk12B0 = arg2;
            return;
        case 12:
            arg0->unk1210 = arg2;
            return;
        case 13:
            arg0->unk4 = arg2;
            return;
        case 14:
            arg0->unk10 = arg2;
            break;
        default:
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00403A1C.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00403C38.s")

#ifdef NEEDS_RODATA
void func_uvdyn_rom_00403D90(UnkStruct_uvdyn_rom_00411DC0 *arg0, s32 arg1, Vec3F arg2) {

    if (arg0 == NULL) {
        return;
    }

    switch (arg1) {
        case 3:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk152C, (Vec3F *) &arg2);
            arg0->unk1488 = D_uvdyn_rom_00411F74->uvVec3FLen(&arg0->unk152C);
            D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(&arg0->unk12EC, &arg0->unk146C, &arg0->unk152C);
            return;
        case 2:
            D_uvdyn_rom_00411F74->uvVec3FCopy((Vec3F *) &arg0->unk1520, (Vec3F *) &arg2);
            return;
        case 5:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk1538, (Vec3F *) &arg2);
            return;
        case 6:
            D_uvdyn_rom_00411F74->uvVec3FCopy((Vec3F *) arg0->unk12EC.m[3], (Vec3F *) &arg2);
            func_uvdyn_rom_00407C04(arg0);
            return;
        case 17:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14BC, (Vec3F *) &arg2);
            return;
        case 19:
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(&arg0->unk142C, &arg0->unk14BC,
                                                           (Vec3F *) &arg2);
            return;
        case 18:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14E0, (Vec3F *) &arg2);
            return;
        case 20:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14C8, (Vec3F *) &arg2);
            return;
        case 21:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14EC, (Vec3F *) &arg2);
            return;
        case 4:
            D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk1490, (Vec3F *) &arg2);
            break;
        default:
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00403D90.s")
#endif

#ifdef NEEDS_RODATA
Vec3F* func_uvdyn_rom_00403F98(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    Vec3F* ret;

    if (arg0 == NULL) {
        return NULL;
    }
    switch (arg1) {
    case 2:
    case 3:
    case 5:
        return NULL;
    case 6:
        ret = (Vec3F*)arg0->unk12EC.m[3];
        break;
    case 7:
        ret = &arg0->unk149C;
        break;
    case 17:
        ret = &arg0->unk14BC;
        break;
    case 18:
        ret = &arg0->unk14E0;
        break;
    case 4:
        ret = &arg0->unk1490;
        break;
    default:
        break;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00403F98.s")
#endif

#ifdef NEEDS_RODATA
void func_uvdyn_rom_00404018(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1, Vec3F* arg2) {
    if (arg0 == NULL) {
        return;
    } 
        
        switch (arg1) {
        case 3:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk152C);
            return;
        case 5:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk1538);
            return;
        case 6:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, (Vec3F* ) arg0->unk12EC.m[3]);
            return;
        case 7:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, (Vec3F* ) &arg0->unk149C);
            return;
        case 17:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk14BC);
            return;
        case 19:
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_004030FC(&arg0->unk12EC, arg2, &arg0->unk14BC);
            return;
        case 18:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk14E0);
            return;
        case 20:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk14C8);
            return;
        case 21:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk14EC);
            return;
        case 4:
            D_uvdyn_rom_00411F74->uvVec3FCopy(arg2, &arg0->unk1490);
            break;
        default:
            break;
        }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00404018.s")
#endif

void func_uvdyn_rom_004041CC(UnkStruct_uvdyn_rom_00411DC0 *arg0, s32 arg1, Mtx4F *arg2) {
    if (arg0 == NULL) {
        return;
    }

    switch (arg1) { /* irregular */
        case 6:
            D_uvdyn_rom_00411F70->uvMat4FCopy(&arg0->unk12EC, arg2);
            func_uvdyn_rom_00407C04(arg0);
            D_uvdyn_rom_00411F70->uvMat4FCopy(&arg0->unk13EC, arg2);
            arg0->unk13EC.m[3][0] = 0.0f;
            arg0->unk13EC.m[3][1] = 0.0f;
            arg0->unk13EC.m[3][2] = 0.0f;
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(&arg0->unk142C, &arg0->unk13EC);
            func_uvdyn_rom_004009BC(&arg0->unk136C, &arg0->unk12EC, &arg0->unk132C);
            func_uvdyn_rom_004094CC(arg0);
            return;
        case 16:
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00400588(&arg0->unk142C, arg2);
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(&arg0->unk13EC, &arg0->unk142C);
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00400588(&arg0->unk12EC, &arg0->unk13EC);
            func_uvdyn_rom_00407C04(arg0);
            return;
        case 15:
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00400588(&arg0->unk13EC, arg2);
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(&arg0->unk142C, arg2);
            D_uvdyn_rom_00411F70->func_uvfmtx_rom_00400588(&arg0->unk12EC, arg2);
            func_uvdyn_rom_00407C04(arg0);
            break;
    }
}

Mtx4F* func_uvdyn_rom_00404384(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    Mtx4F* sp4;

    if (arg0 == NULL) {
        return NULL;
    }
    switch (arg1) {                                 /* irregular */
    case 6:
        sp4 = &arg0->unk12EC;
        break;
    case 16:
        sp4 = &arg0->unk142C;
        break;
    case 15:
        sp4 = &arg0->unk13EC;
        break;
    }
    return sp4;
}

#ifdef NEEDS_RODATA
void func_uvdyn_rom_004043E0(UnkStruct_uvdyn_rom_00411DC0 *arg0, s32 arg1, Mtx4F *arg2) {
    if (arg0 == NULL) {
        return;
    }

    switch (arg1) {
        case 6:
            D_uvdyn_rom_00411F70->uvMat4FCopy(arg2, &arg0->unk12EC);
            return;
        case 16:
            D_uvdyn_rom_00411F70->uvMat4FCopy(arg2, &arg0->unk142C);
            return;
        case 15:
            D_uvdyn_rom_00411F70->uvMat4FCopy(arg2, &arg0->unk13EC);
            return;
        case 22:
            D_uvdyn_rom_00411F70->uvMat4FCopy(arg2, &arg0->unk132C);
            return;
        case 25:
            D_uvdyn_rom_00411F70->uvMat4FCopy(arg2, &arg0->unk136C);
            break;
        default:
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004043E0.s")
#endif

void func_uvdyn_rom_004044D0(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    if (arg0 != NULL) {
        arg0->unk14B8 = arg1;
    }
}


void func_uvdyn_rom_004044E4(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00403294* arg1) {
    if (arg0 != NULL) {
        D_uvdyn_rom_00411F74->uvVec3FCopy(&arg1->unk0, &arg0->unk12DC);
        arg1->unkC = arg0->unk12E8;
    }
}

void func_uvdyn_rom_00404538(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00411DC0_unk14* arg1) {
    if ((arg1 != NULL) && (arg1->unk94 == 0xA)) {
        return;
    }
        
    if (arg0->unk14 != NULL) {
        if (arg1 != arg0->unk14) {
            func_uvdyn_rom_0040C100(arg0->unk14, arg0);
            goto assign;
        }
        return;
    } 
    assign:
    arg0->unk14 = arg1;
    if (arg1 != NULL) {
        func_uvdyn_rom_0040C064(arg1, arg0);
    }
}

s32 func_uvdyn_rom_004045A8(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    return arg0->unk14;
}

void func_uvdyn_rom_004045B0(UnkStruct_uvdyn_rom_00411DC0 *arg0, UnkStruct_uvdyn_rom_00409CE4 *arg1) {
    u16 i;

    if (arg1 == NULL) {
        return;
    }

    for (i = 0; i < arg0->unk18; i++) {
        if (arg1 == arg0->unk1C[i]) {
            return;
        }
    }

    if (arg0->unk18 == 2) {
        return;
    }

    arg0->unk1C[arg0->unk18] = arg1;
    arg0->unk18++;
    if (arg1->unk8 != NULL) {
        func_uvdyn_rom_00404674(arg1->unk8, arg1);
    }
    arg1->unk8 = arg0;
    if ((arg1->unkC != NULL) && (arg0->unk24 == 0)) {
        D_uvdyn_rom_00411F7C->unk38(arg1->unkC, arg0->unk28);
    }
}

void func_uvdyn_rom_00404674(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00409CE4* arg1) {
    u16 i;

    if (arg0 == NULL) {
        return;
    }

    for (i = 0; i < arg0->unk18; i++) {
        if (arg1 == arg0->unk1C[i]) {
            break;
        }
    }
}

s32 func_uvdyn_rom_004046B4(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    if (arg0->unk18 < arg1) {
        return 0;
    }
    return arg0->unk1C[arg1];
}

s32 func_uvdyn_rom_004046E0(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk18;
}


void* func_uvdyn_rom_004046FC(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    if (arg0->unk38 < arg1) {
        return NULL;
    }
    return &arg0->unk3AC[arg1];
}

s32 func_uvdyn_rom_00404734(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk38;
}

void func_uvdyn_rom_00404750(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    UnkStruct_uvdyn_rom_00409CE4_unkC* temp_a0;
    u16 i;

    arg0->unk28 = arg1;
    if (arg0->unk24 != 0) {
        return;
    }
        
    D_uvdyn_rom_00411F84->uvDobjGetProp(arg1, 7, &arg0->unk14AC, 0);
    arg0->unk14B0 = arg0->unk14AC;
    for (i = 0; i < arg0->unk18; i++) {
        UnkStruct_uvdyn_rom_00409CE4* v0 = arg0->unk1C[i];
        if (v0->unkC != NULL) {
            D_uvdyn_rom_00411F7C->unk38(v0->unkC, arg1);
        }
    }
}

s32 func_uvdyn_rom_0040481C(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    return arg0->unk28;
}

void func_uvdyn_rom_00404824(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    arg0->unk2C = arg1;
}

s32 func_uvdyn_rom_0040482C(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    return arg0->unk2C;
}

void func_uvdyn_rom_00404834(UnkStruct_uvdyn_rom_00411DC0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    UnkStruct_uvdyn_rom_00409CE4 *temp_a2;
    UnkStruct_uvdyn_rom_00409CE4_unkC *temp_a3;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18 *temp_a2_2;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8 *temp_a3_2;
    UnkStruct_uvdyn_rom_00409CE4_unkC_unk18_unk8_unk4 *temp_v0;
    s32 v0;
    u16 j;
    u16 i;

    if (arg0 == NULL) {
        return;
    }

    if ((arg1 == 5) && (arg0->unk1550[arg1] == 0)) {
        v0 = arg0->unk18;
        arg0->unk1484 |= 2;
        for (i = 0; i < arg0->unk18; i++) {
            temp_a2 = arg0->unk1C[i];
            if (temp_a2 == NULL) {
                continue;
            }

            temp_a3 = temp_a2->unkC;
            if (temp_a3 == NULL) {
                continue;
            }

            temp_a2_2 = temp_a3->unk18;
            if (temp_a2_2->unk4 != 0) {
                continue;
            }

            temp_a3_2 = &temp_a2_2->unk8;
            if (temp_a2_2->unk8.unk0 != 0) {
                for (j = 0; j < temp_a3_2->unk0; j++) {
                    temp_v0 = temp_a3_2->unk4[j];
                    temp_v0->unk18 |= 2;
                }
            }
        }
    }
    arg0->unk1550[arg1] = arg2;
    arg0->unk1578[arg1] = arg3;
}

void func_uvdyn_rom_0040492C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

s32 func_uvdyn_rom_00404940(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk120C;
}

void func_uvdyn_rom_0040495C(UnkStruct_uvdyn_rom_00411DC0* arg0, u16 arg1, s32* arg2, s32* arg3, u16* arg4, Vec3F* arg5) {
    if (arg0 == NULL) {
        return;
    }
    
    if (arg1 >= arg0->unk120C) {
        return;
    }
        
    *arg2 = arg0->unk122C[arg1];
    *arg3 = arg0->unk1214[arg1];
    *arg4 = arg0->unk1224[arg1];
    D_uvdyn_rom_00411F74->uvVec3FCopy(arg5, &arg0->unk123C[arg1]);
}

void func_uvdyn_rom_004049F8(UnkStruct_uvdyn_rom_00411DC0* arg0, Vec3F* arg1, f32 arg2, f32 arg3) {
    arg0->unk12B6 = 1;
    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk12C0, arg1);
    arg0->unk12B8 = arg2;
    arg0->unk12BC = arg3;
}

u16 func_uvdyn_rom_00404A58(UnkStruct_uvdyn_rom_00411DC0* arg0, Vec3F* arg1, f32* arg2, f32* arg3) {
    if (arg0->unk12B6 != 0) {
        D_uvdyn_rom_00411F74->uvVec3FCopy(arg1, &arg0->unk12C0);
        *arg2 = arg0->unk12B8;
        *arg3 = arg0->unk12BC;
    }
    return arg0->unk12B6;
}

void func_uvdyn_rom_00404ACC(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    arg0->unk12B6 = 0;
}

s32 func_uvdyn_rom_00404AD4(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk1274;
}

void func_uvdyn_rom_00404AF0(UnkStruct_uvdyn_rom_00411DC0* arg0, u16 arg1, s32* arg2, s32* arg3, u16* arg4, Vec3F* arg5, s32* arg6, s32* arg7) {
    if (arg0 == NULL) {
        return;
    }
    if (arg1 >= arg0->unk1274) {
        return;
    }
        
    *arg2 = arg0->unk1290[arg1];
    *arg3 = arg0->unk1278[arg1];
    *arg4 = arg0->unk1288[arg1];
    D_uvdyn_rom_00411F74->uvVec3FCopy(arg5, &arg0->unk12A0[arg1]->unk34);
    *arg6 = arg0->unk12A0[arg1]->unk8;
    *arg7 = arg0->unk12A0[arg1]->dobj;
}

u16 func_uvdyn_rom_00404BA4(UnkStruct_uvdyn_rom_00411DC0 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk12DA;
}

s32 func_uvdyn_rom_00404BC0(UnkStruct_uvdyn_rom_00411DC0* arg0, u16 arg1, s32* arg2, u16* arg3, UnkStruct_uvdyn_rom_00411DC0_unk14_unkBCA4* arg4) {
    UnkStruct_uvdyn_rom_00411DC0_unk14* temp_a2;
    u16 temp_t9;

    if (arg0 == NULL) {
        return 0;
    }
    if (arg1 >= arg0->unk12DA) {
        return 0;
    }
    temp_t9 = arg0->unk12D2 + arg1;
    temp_a2 = arg0->unk14;
    *arg2 = temp_a2->unkBBB4[temp_t9];
    *arg3 = temp_a2->unkBC68[temp_t9];
    *arg4 = temp_a2->unkBCA4[temp_t9];
    return 1;
}

s32 func_uvdyn_rom_00404C60(UnkStruct_uvdyn_rom_00411DC0* arg0, u16 arg1) {
    u16 var_v1;

    if (arg0 == NULL) {
        return 0;
    }
    if ((arg1 == 0) && (arg0->unk12D2 == 0)) {
        var_v1 = arg0->unk14->unkBC2C[0] + 1;
    } else {
        var_v1 = arg0->unk14->unkBC2C[arg0->unk12D2 + arg1] - arg0->unk14->unkBC2C[arg0->unk12D2 + arg1 - 1];
    }
    return var_v1;
}

s32 func_uvdyn_rom_00404CE8(UnkStruct_uvdyn_rom_00411DC0* arg0, u16 arg1, u16 arg2) {
    UnkStruct_uvdyn_rom_00411DC0_unk14* temp_v1;
    u16 temp_a0;
    u16 var_a2;

    temp_v1 = arg0->unk14;
    if (arg0 == NULL) {
        return 0;
    }
    if (arg1 >= arg0->unk12DA) {
        return 0;
    }
    if ((arg1 == 0) && (arg0->unk12D2 == 0)) {
        var_a2 = 0;
    } else {
        var_a2 = temp_v1->unkBC2C[arg0->unk12D2 + arg1 - 1];
    }
    temp_a0 = temp_v1->unkBC2C[arg0->unk12D2 + arg1] - 1;
    if (temp_a0 < var_a2) {
        return 0;
    }
    if ((temp_a0 - var_a2) < arg2) {
        PANIC;
        return 0;
    }
    return &temp_v1->unkBD1C[var_a2 + arg2];
}

// .rodata
extern f32 D_uvdyn_rom_00411CBC;
void func_uvdyn_rom_00404DE0(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    u16 i;

    if (arg0->unk1550[1] != NULL) {
        arg0->unk1550[1](&arg0->unk0, arg0->unk1578[1]);
    }
    arg0->unk120C = 0;
    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14EC, &arg0->unk14E0);
    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk14C8, &arg0->unk14BC);
    for (i = 0; i < arg0->unk18; i++) {
        D_uvdyn_rom_00411F7C->unk20(arg0->unk1C[i]->unkC, 3, &arg0->unk12EC);
    }
    D_uvdyn_rom_00411F70->uvMat4FCopy(&arg0->unk132C, &arg0->unk12EC);
    D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk1478, &arg0->unk146C);
    arg0->unk148C = D_uvdyn_rom_00411CBC;
    arg0->unk14A8 = -1;
}

void func_uvdyn_rom_00404F08(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0->unk1550[9] != NULL) {
        arg0->unk1550[9](&arg0->unk0, arg0->unk1578[9]);
    }
}

void func_uvdyn_rom_00404F34(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0->unk1550[2] != NULL) {
        arg0->unk1550[2](&arg0->unk0, arg0->unk1578[2]);
    }
}

void func_uvdyn_rom_00404F60(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0->unk1550[6] != NULL) {
        arg0->unk1550[6](&arg0->unk0, arg0->unk1578[6]);
    }
}

u16 func_uvdyn_rom_00404F8C(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1) {
    void (*routine)(UnkStruct_uvdyn_rom_00411DC0_unk0*, s32);
    UnkStruct_uvdyn_rom_00411DC0_unk0 sp18;

    routine = arg0->unk1550[7];
    if (routine != NULL) {
        sp18.unkA = 1;
        sp18.unk0 = arg1;
        sp18.unk4 = -1;
        sp18.unk8 = 0;
        routine(&sp18, arg0->unk1578[7]);
        return sp18.unkA;
    }
    return 1;
}

void func_uvdyn_rom_00404FE0(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (arg0->unk1550[4] != NULL) {
        arg0->unk1550[4](&arg0->unk0, arg0->unk1578[4]);
    }
}

void func_uvdyn_rom_0040500C(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00411DC0_unk0* arg1) {
    if (arg0->unk1550[8] != NULL) {
        arg0->unk1550[8](arg1, arg0->unk1578[8]);
    }
}

void func_uvdyn_rom_00405040(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    D_uvdyn_rom_00411F74->uvVec3FAdd(&arg0->unk14BC, &arg0->unk14BC, &arg0->unk1504);
    D_uvdyn_rom_00411F74->uvVec3FAdd(&arg0->unk14E0, &arg0->unk14E0, &arg0->unk1510);
    D_uvdyn_rom_00411F74->uvVec3FScale(&arg0->unk1504, &arg0->unk1504, 0.0f);
    D_uvdyn_rom_00411F74->uvVec3FScale(&arg0->unk1510, &arg0->unk1510, 0.0f);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004050EC.s")

s32 func_uvdyn_rom_00407594(UnkStruct_uvdyn_rom_00411DC0 *arg0,
                            UnkStruct_uvdyn_rom_00411DC0_unk12A0 *arg1) {
    f32 dotProduct;
    f32 y;
    s32 var_s1;

    var_s1 = 0;
    if (arg0->unk12B6 != 0) {
        if ((arg1->unk8 == 2)) {
            ParsedUVMD *uvmd =
                uvGetLoadedFile('UVMD', D_uvdyn_rom_00411F84->uvDobjGetModel(arg1->dobj & 0xFFFFFF));
            if (!(uvmd->unk5 & 4)) {
                var_s1 = 2;
            }
        }
        if (var_s1 == 0) {
            dotProduct = D_uvdyn_rom_00411F74->uvVec3FDot(&arg1->unk34, &arg0->unk12C0);
            y = arg1->unk34.z;
            if (((y < arg0->unk12C0.z) && (dotProduct < arg0->unk12B8))
                || ((arg0->unk12C0.z <= y) && (dotProduct < arg0->unk12BC))) {
                var_s1 = 1;
            }
        }
    }
    if (var_s1 != 0) {
        D_uvdyn_rom_00411F74->uvVec3FCross(&arg1->unk34, &arg0->unk12C0, &arg1->unk34);
        D_uvdyn_rom_00411F74->uvVec3FCross(&arg1->unk34, &arg1->unk34, &arg0->unk12C0);
        D_uvdyn_rom_00411F74->uvVec3FNormalize(&arg1->unk34, &arg1->unk34);
    }
    return var_s1;
}

s32 func_uvdyn_rom_00408ACC(UnkStruct_uvdyn_rom_00411DC0*, UnkStruct_uvdyn_rom_00411DC0_unk12A0*); /* extern */
s32 func_uvdyn_rom_00408DC8(UnkStruct_uvdyn_rom_00411DC0*); /* extern */

#ifdef NEEDS_RODATA
s32 func_uvdyn_rom_0040771C(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00411DC0_unk12A0* arg1) {
    f32 spE4;
    Vec3F spD8;
    s32 spCC[3];
    Vec3F spC0;
    Vec3F spB4;
    f32 sp5C[22];
    Vec3F sp50;
    Vec3F sp44;
    u16 sp42;

    D_uvdyn_rom_00411F7C->unk94(arg1, &arg0->unk1478, arg0->unk1C[0]->unkC->unkC);
    D_uvdyn_rom_00411F74->uvVec3FSub(&spD8, &arg1->unk14, &arg0->unk146C);
    spE4 = D_uvdyn_rom_00411F74->uvVec3FDot(&spD8, &arg1->unk34);
    if (spE4 > 0.0f) {
        sp42 = 1;
        spCC[0] = 1;
        D_uvdyn_rom_00411F74->uvVec3FScale(&sp50, &arg1->unk34, spE4);
        D_uvdyn_rom_00411F74->uvVec3FSub(&sp44, &spD8, &sp50);
        spE4 += (0.0875f * D_uvdyn_rom_00411F74->uvVec3FLen(&sp44));
        D_uvdyn_rom_00411F74->uvVec3FScale(&sp50, &arg1->unk34, spE4);
        D_uvdyn_rom_00411F74->uvVec3FCopy(&spC0, &arg0->unk146C);
        D_uvdyn_rom_00411F74->uvVec3FAdd(&spB4, &spC0, &sp50);
        if (D_uvdyn_rom_00411F7C->unkA8(&spB4, arg1->unk8, arg0->unk1C[0]->unkC->unkC, arg0->unk28, &sp5C) != 0) {
            D_uvdyn_rom_00411F74->uvVec3FScale(&sp50, &arg1->unk34, (sp5C[11] * spE4) + 0.1f);
            sp42 = 0;
        } else {
            D_uvdyn_rom_00411F74->uvVec3FScale(&sp50, &arg1->unk34, 0.1f);
            D_uvdyn_rom_00411F74->uvVec3FAdd(&sp50, &spD8, &sp50);
        }
        D_uvdyn_rom_00411F74->uvVec3FAdd((Vec3F* ) arg0->unk12EC.m[3], (Vec3F* ) arg0->unk12EC.m[3], &sp50);
        D_uvdyn_rom_00411F74->uvVec3FAdd(&arg0->unk146C, &arg0->unk146C, &sp50);
        if (sp42 == 0) {
            func_uvdyn_rom_00408DC8(arg0);
            return func_uvdyn_rom_00408ACC(arg0, arg1);
        }
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040771C.s")
#endif


u8 func_uvdyn_rom_004079B8(UnkStruct_uvdyn_rom_00411DC0* arg0, u16 arg1, f32 arg2, UnkStruct_uvdyn_rom_00411DC0_unk12A0* arg3) {
    u16 sp46;
    s32 sp40;

    sp40 = arg0->unk1C[0]->unkC->unkC;
    sp46 = func_uvdyn_rom_0040F78C(arg0->unk14, &arg0->unk146C, arg0->unk28, arg3, arg0->unk12D2, arg0->unk12DA, arg0->unk12D0, arg0->unk12D8, 0);
    if (arg0->unk0.unk4 == -1) {
        if (!(sp46)) {
            sp46 = D_uvdyn_rom_00411F7C->unk50(&arg0->unk146C, 8, arg0->unk28, sp40, arg3);
        }
        if (D_uvdyn_rom_00411F7C->unk50(&arg0->unk146C, 1, arg0->unk28, sp40, arg3) != 0) {
            if ((arg3->unk8 == 4) || ((arg3->unk8 == 1) && (D_uvdyn_rom_00411F7C->unk84(sp40, arg3->dobj, 4) != 0))) {
                arg3->unk8 = 4;
                if (arg1 != 0) {
                    arg0->unk148C = ((1.0f - arg2) * arg3->unk2C) + arg2;
                } else {
                    arg0->unk148C = arg3->unk2C;
                }
                D_uvdyn_rom_00411F74->uvVec3FCopy((Vec3F* ) &arg0->unk149C, &arg3->unk14);
                func_uvdyn_rom_00404FE0(arg0);
            } else {
                sp46 = 1;
            }
        }
    }
    if (sp46 != 0) {
        sp46 = func_uvdyn_rom_00404F8C(arg0, (s32) arg3);
    }
    if (sp46) {
        if (arg0->unk12B6 != 0) {
            D_uvdyn_rom_00411F74->uvVec3FCross(&arg3->unk34, &arg0->unk12C0, &arg3->unk34);
            D_uvdyn_rom_00411F74->uvVec3FCross(&arg3->unk34, &arg3->unk34, &arg0->unk12C0);
            D_uvdyn_rom_00411F74->uvVec3FNormalize(&arg3->unk34, &arg3->unk34);
        }
    }
    func_uvdyn_rom_00410AEC(arg0->unk14, arg0->unk12D0, arg0->unk12D8, arg0->unk12D2, (s32) arg0->unk12DA);
    return sp46;
}

#ifdef NEEDS_RODATA
void func_uvdyn_rom_00407C04(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    if (!(arg0->unk1488 < 0.00001) || !(-0.00001 < arg0->unk1488)) {
        D_uvdyn_rom_00411F70->uvMat4FLocalToWorld(&arg0->unk12EC, &arg0->unk146C, &arg0->unk152C);
    } else {
        D_uvdyn_rom_00411F74->uvVec3FCopy(&arg0->unk146C, (Vec3F* ) arg0->unk12EC.m[3]);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00407C04.s")
#endif

u16 func_uvdyn_rom_004050EC(UnkStruct_uvdyn_rom_00411DC0*, s32, s32, s32, s32, f32, s32); /* extern */

void func_uvdyn_rom_00407C98(UnkStruct_uvdyn_rom_00411DC0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    s32 pad;

    D_uvdyn_rom_00411F7C->unk80(D_uvdyn_rom_00411F74->uvVec3FLen(&arg0->unk14BC));
    arg0->unk12B4 = func_uvdyn_rom_004050EC(arg0, arg1, arg2, arg3, arg4, 0.0f, (s32) arg5);
    D_uvdyn_rom_00411F7C->unk80(-1.0f);
    if (arg0->unk12B4 == 2) {
        D_uvdyn_rom_00411F70->uvMat4FCopy(&arg0->unk12EC, &arg0->unk132C);
        func_uvdyn_rom_00407C04(arg0);
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_00400588(&arg0->unk13EC, &arg0->unk12EC);
        D_uvdyn_rom_00411F70->func_uvfmtx_rom_00401B88(&arg0->unk142C, &arg0->unk13EC);
        D_uvdyn_rom_00411F70->uvMat4SetIdentity(&arg0->unk136C);
        arg0->unk12B4 = 3;
        if (arg0->unk1550[3] != NULL) {
            arg0->unk1550[3](&arg0->unk0, arg0->unk1578[3]);
        }
    }
}

void func_uvdyn_rom_00407DF0(UnkStruct_uvdyn_rom_00411DC0* arg0);

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00407DF0.s")


void func_uvdyn_rom_004088EC(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00403294* arg1, u8 arg2) {
    UnkStruct_uvdyn_rom_00411DC0_unk14* sp2C;

    sp2C = arg0->unk14;
    if (func_uvdyn_rom_00403294(arg1, (UnkStruct_uvdyn_rom_00403294* ) &arg0->unk12DC) != 0) {
        if (arg0->unk0.unk4 == -1) {
            arg0->unk12D2 = sp2C->unkF744;
            arg0->unk12DA = func_uvdyn_rom_00410250(arg0->unk14, arg0->unk28,  &arg0->unk12DC, 1, arg0);
            arg0->unk12D0 = sp2C->unkF740;
            arg0->unk12D8 = func_uvdyn_rom_0040FC88(arg0->unk14, arg0->unk132C.m[3], arg0->unk12EC.m[3], arg0->unk28, arg0->unk14B4, &arg0->unk12DC);
            arg0->unk12CC = sp2C->unkF73C;
            arg0->unk12CE = sp2C->unkF73E;
            arg0->unk12D4 = func_uvdyn_rom_004107FC(arg0->unk14, arg0->unk1C[0]->unkC->unkC,  &arg0->unk12DC);
            arg0->unk12D6 = sp2C->unkF73E - arg0->unk12CE;
        } else {
            arg0->unk12D2 = sp2C->unkF744;
            if ( arg0->unk0.unk4 != 0) {
                arg0->unk12DA = func_uvdyn_rom_00409010(arg0);
            } else {
                arg0->unk12DA = 0;
            }
            arg0->unk12D0 = sp2C->unkF740;
            arg0->unk12D8 = 0;
            arg0->unk12CC = sp2C->unkF73C;
            arg0->unk12D4 = 0;
            arg0->unk12CE = sp2C->unkF73E;
            arg0->unk12D6 = 0;
        }
    } else {
        func_uvdyn_rom_00410A88(sp2C, arg0->unk12CC, arg0->unk12D4);
        if (arg2 != 0) {
            if (arg0->unk0.unk4 == -1) {
                arg0->unk12D2 = sp2C->unkF744;
                arg0->unk12DA = func_uvdyn_rom_00410250(arg0->unk14, arg0->unk28, &arg0->unk12DC, 1, arg0);
            } else {
                arg0->unk12D2 = sp2C->unkF744;
                if (arg0->unk0.unk4 != 0) {
                    arg0->unk12DA = func_uvdyn_rom_00409010(arg0);
                } else {
                    arg0->unk12DA = 0;
                }
            }
        }
    }
    func_uvdyn_rom_00410AEC(arg0->unk14, arg0->unk12D0, arg0->unk12D8, arg0->unk12D2, (s32) arg0->unk12DA);
}

s32 func_uvdyn_rom_00408ACC(UnkStruct_uvdyn_rom_00411DC0* arg0, UnkStruct_uvdyn_rom_00411DC0_unk12A0* arg1) {
    u16 var_v1;
    s32 sp68;
    Vec3F sp5C;
    Vec3F sp50;
    s32 pad[2];

    sp68 = arg0->unk1C[0]->unkC->unkC;
    var_v1 = func_uvdyn_rom_0040F78C(arg0->unk14, &arg0->unk146C, arg0->unk28, arg1, arg0->unk12D2, arg0->unk12DA, arg0->unk12D0, arg0->unk12D8, 0);;
    if (arg0->unk0.unk4 == -1) {
        if (!(var_v1)) {
            var_v1 = D_uvdyn_rom_00411F7C->unk50(&arg0->unk146C, 8, arg0->unk28, sp68, arg1) ;
        }
        if (D_uvdyn_rom_00411F7C->unk50(&arg0->unk146C, 1, arg0->unk28, sp68, arg1) != 0) {
            if ((arg1->unk8 == 4) || ((arg1->unk8 == 1) && ((D_uvdyn_rom_00411F7C->unk84(sp68, arg1->dobj, 4) != 0)))) {
                arg1->unk8 = 4;
                arg0->unk148C = 1.0f;
                D_uvdyn_rom_00411F74->uvVec3FCopy((Vec3F* ) &arg0->unk149C, &arg1->unk14);
                func_uvdyn_rom_00404FE0(arg0);
            } else {
                var_v1 = 1;
            }
        }
    }
    if (var_v1 != 0) {
        var_v1 = func_uvdyn_rom_00404F8C(arg0, arg1);
    }
    func_uvdyn_rom_00410AEC(arg0->unk14, arg0->unk12D0, arg0->unk12D8, arg0->unk12D2, arg0->unk12DA);
    if (var_v1) {
        D_uvdyn_rom_00411F7C->unk94(arg1, &arg0->unk1478, sp68);
        if (arg0->unk12B6 != 0) {
            D_uvdyn_rom_00411F74->uvVec3FCross(&arg1->unk34,  &arg0->unk12C0, &arg1->unk34);
            D_uvdyn_rom_00411F74->uvVec3FCross(&arg1->unk34, &arg1->unk34,  &arg0->unk12C0);
            D_uvdyn_rom_00411F74->uvVec3FNormalize(&arg1->unk34, &arg1->unk34);
        }
        D_uvdyn_rom_00411F74->uvVec3FSub(&sp5C, &arg1->unk14, &arg0->unk146C);
        D_uvdyn_rom_00411F74->uvVec3FScale(&sp50, &arg1->unk34, 0.1f);
        D_uvdyn_rom_00411F74->uvVec3FAdd(&sp50, &sp5C, &sp50);
        D_uvdyn_rom_00411F74->uvVec3FAdd((Vec3F* ) arg0->unk12EC.m[3], (Vec3F* ) arg0->unk12EC.m[3], &sp50);
        D_uvdyn_rom_00411F74->uvVec3FAdd(&arg0->unk146C, &arg0->unk146C, &sp50);
        return TRUE;
    }
    return FALSE;
}

#ifdef NEEDS_RODATA
s32 func_uvdyn_rom_00408DC8(UnkStruct_uvdyn_rom_00411DC0* arg0) {
    Vec3F sp64;
    Vec3F sp58;
    f32 sp54;
    f32 sp50;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 sp44;
    f32 temp_fv0;
    f32 var_fv0;
    f32 ft5;

    D_uvdyn_rom_00411F74->uvVec3FSub(&sp64, &arg0->unk146C, &arg0->unk12DC);
    sp44 = arg0->unk12E8 - 0.1f;
    if (D_uvdyn_rom_00411F74->uvVec3FLen(&sp64) < sp44) {
        return FALSE;
    }
    D_uvdyn_rom_00411F74->uvVec3FSub(&sp58, &arg0->unk146C, &arg0->unk1478);
    D_uvdyn_rom_00411F74->uvVec3FSub(&sp64, &arg0->unk1478, &arg0->unk12DC);
    sp54 = D_uvdyn_rom_00411F74->uvVec3FLenSquared(&sp58);
    sp50 = 2.0f * D_uvdyn_rom_00411F74->uvVec3FDot(&sp58, &sp64);
    ft5 = D_uvdyn_rom_00411F74->uvVec3FLenSquared(&sp64) - SQ(sp44);
    temp_fv0 = D_uvdyn_rom_00411F80->uvSqrtf(SQ(sp50) - ((4.0f * sp54) * ft5));
    temp_fa0 = ((-sp50 + temp_fv0) * 0.5f) / sp54;
    temp_fa1 = ((-sp50 - temp_fv0) * 0.5f) / sp54;
    if (temp_fa1 < temp_fa0) {
        var_fv0 = temp_fa0;
    } else {
        var_fv0 = temp_fa1;
    }
    if ((var_fv0 > 1.0f) || (var_fv0 < 0.0f)) {
        PANIC;
    }
    D_uvdyn_rom_00411F74->uvVec3FScale(&sp64, &sp58, var_fv0);
    D_uvdyn_rom_00411F74->uvVec3FAdd(&arg0->unk146C, &arg0->unk1478, &sp64);
    D_uvdyn_rom_00411F74->uvVec3FCopy((Vec3F* ) arg0->unk12EC.m[3], &arg0->unk146C);
    func_uvdyn_rom_004009BC(&arg0->unk136C, &arg0->unk12EC, &arg0->unk132C);
    func_uvdyn_rom_004094CC(arg0);
    return TRUE;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00408DC8.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409010.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409318.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004094CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040954C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040981C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409960.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409A40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409A48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409A68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409A7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409AF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409BC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409BCC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409BD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409CE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00409E18.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040A05C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040A0D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040A180.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040A188.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040AFAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040AFD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040B00C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040B070.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040B08C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040B75C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040B838.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BAA0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BAD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BB5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BC48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BCE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BD14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040BFD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C064.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C100.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C1A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C20C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C2C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C3B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C464.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040C570.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040E4E8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040E8E8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040F78C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0040FC88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410250.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004107FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410A88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410AEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410C40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410D54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410D80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410E24.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410EF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00410F60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411014.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004110D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411148.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411300.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_0041138C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411454.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411644.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004116A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411744.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004117B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004117C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004118C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_004118D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/uvdyn_rom/func_uvdyn_rom_00411954.s")

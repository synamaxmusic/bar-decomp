#ifndef UVASSET_TYPES_H
#define UVASSET_TYPES_H
#include "uvgfxstate_rom.h"

typedef struct UnkSobjDraw {
    u16 modelId;
    Mtx *unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u16 unk14;
    u16 unk16;
} UnkSobjDraw;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk80225FBC_0x28_UnkC; // size = 0x10

typedef struct {
    uvGfxState unk0;
    Unk80225FBC_0x28_UnkC *unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    char pad[0x14];
} Unk80225FBC_0x28;

typedef struct {
    Vtx *vtxTable;
    u16 vtxCount;
    u16 pad6;
    Unk80225FBC_0x28 *unk8;
    u16 unkC;
    u16 padE;
    struct UnkSobjDraw *unk10;
    u16 unk14;
    u16 pad16;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} ParsedUVCT; // size = 0x28

typedef struct uvUnkTileStruct {
    /* 0x00 */ Mtx4F unk0;
    /* 0x40 */ ParsedUVCT *unk40;
    /* 0x44 */ u16 unk44;        /* inferred */
    /* 0x46 */ char pad46[0x46]; /* maybe part of unk44[0x24]? */
} uvUnkTileStruct;               /* size = 0x8C */

typedef struct uvUnkTeraStruct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} uvUnkTeraStruct; // size = 0x18

typedef struct ParsedUVTR {
    uvUnkTeraStruct unk0;
    u8 unk18;
    u8 unk19;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    uvUnkTileStruct *unk28;
} ParsedUVTR; // size = 0x2C

typedef struct UnkUVMD_6 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} UnkUVMD_6; // size = 0x6

typedef struct UnkUVMD_24_Unk4 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} UnkUVMD_24_Unk4;

typedef struct UnkUVMD_24 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x1];
    UnkUVMD_24_Unk4 unk4;
    u16 unk1C;
    UnkUVMD_6 *unk20;
} UnkUVMD_24;

typedef struct uvModelPart {
    void *stateTable;
    u8 stateCount;
    u8 unk5;
    u8 unk6;
    UnkUVMD_24 *unk8;
    u8 unkC;
    u8 lighting;
} uvModelPart; // size = 0x10

#define UVMD_ATTR_TRANSPARENT 1
#define UVMD_ATTR_UNKNOWN 2

typedef struct ParsedUVMD_3_s {
    char pad[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0xC];
} ParsedUVMD_3;

typedef struct ParsedUVMD_2_s {
    ParsedUVMD_3 *unk0;
    u8 unk4;
    char pad[0x24];
} ParsedUVMD_2;

typedef struct uvModelLOD_inner_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} uvModelLOD_inner;

typedef struct uvModelLOD_s {
    uvGfxState *stateTable;
    u8 unk4;
    uvModelLOD_inner unk8;
    char pad[0xC];
} uvModelLOD;

typedef struct ParsedUVMD_1_s {
    uvModelLOD *unk0;
    u8 unk4;
    u8 pad[3];
    u8 unk8;
} ParsedUVMD_1;

typedef struct ParsedUVMD_20_s {
    /* 0x0 */ char pad[0x38];
    /* 0x38 */ s32 unk38;
} ParsedUVMD_20;

typedef struct ParsedUVMD {
    /* 0x00 */ ParsedUVMD_1 *unk0; /* inferred */
    /* 0x04 */ u8 unk4;            /* inferred */
    /* 0x08 */ Mtx4F* unk8;
               s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ Vtx *vtxTable;
    /* 0x1C */ u16 vtxCount;
    /* 0x20 */ ParsedUVMD_20* unk20;
} ParsedUVMD; /* size = 0x20 */

typedef struct UnkUVTX_1C {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} UnkUVTX_1C;

typedef struct ParsedUVTX {
    /* 0x00 */ void *unk0;
    /* 0x04 */ Gfx *unk4;
    /* 0x08 */ union {
        u16 as_u16;
        s32 as_s32;
    } size;
    /* 0x0C */ union {
        void *pointer;
        u8 bytes[4];
    } data;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ union {
        s32 unk14;
        u16 as_u16;
        struct {
            s32 unk14_20 : 12;
            s32 unk14_19 : 1;
            s32 pad14_0  : 19;
        };
    };
    /* 0x18 */ u16 pad18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u16 width;
    /* 0x1E */ u16 height;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 *unk2C;
} ParsedUVTX; /* size = 0x30 */

typedef struct ParsedUVTS_inner_s {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ char pad2[2];
    /* 0x4 */ f32 unk4;
} ParsedUVTS_inner; /* size = 0x8 */

typedef struct ParsedUVTS_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ char pad3[1];
    /* 0x04 */ ParsedUVTS_inner *unk4;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ char padA[2];
    /* 0x0C */ f32 unkC;
} ParsedUVTS; /* size = 0x10 */

typedef struct ParsedUVTT_s {
    s32 unk0;
    s32 unk4;
    void *unk8;
    void *unkC;
} ParsedUVTT;

typedef struct {
    u16 count;
    u16 unk2;
    u16 *unk4;
    u16 *unk8;
} ParsedUVTP;

typedef struct uvEnvModel_s {
    u16 modelId;
    u8 flag;
} uvEnvModel;

typedef struct ParsedUVEN_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC; /* inferred */
    /* 0x0D */ u8 unkD; /* inferred */
    /* 0x0E */ u8 unkE; /* inferred */
    /* 0x0F */ u8 unkF; /* inferred */
    /* 0x10 */ u8 unk10;
    u8 unk11;
    /* 0x14 */ char pad14[10]; /* maybe part of unk10[3]? */
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ char pad1E[0x10]; /* maybe part of unk1D[0x11]? */
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ char pad2F[1];
    /* 0x30 */ uvEnvModel *modelTable;
    /* 0x34 */ u8 modelCount;
    /* 0x35 */ char pad35[3]; /* maybe part of modelCount[4]? */
    /* 0x38 */ void (*unk38)(void);
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ void *unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ u8 unk58;
    /* 0x59 */ char pad59[3]; /* maybe part of unk58[4]? */
    /* 0x5C */ void (*unk5C)(void);
} ParsedUVEN; /* size = 0x60 */


typedef struct {
    u8 pad0[0x2];
    s16 bmfmt;
    s16 bitdepth;
    s16 width;
    s16 height;
    s16 unkA;
    s16 texelHeight;
    s16 nbitmaps;
    void *buf;
    Bitmap *bitmap;
} ParsedUVBT;

#endif /* UVASSET_TYPES_H */

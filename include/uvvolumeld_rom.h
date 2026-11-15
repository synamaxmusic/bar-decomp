// SPDX-License-Identifier: AGPL-3.0-or-later
#ifndef UVVOLUMELD_ROM_H
#define UVVOLUMELD_ROM_H
typedef struct ParsedUVVL_inner_1_s {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ char padC[0xC];                      /* maybe part of unk8[4]? */
    /* 0x18 */ f32 unk18;                           /* inferred */
} ParsedUVVL_inner_1;                               /* size = 0x1C */

typedef struct ParsedUVVL_inner_s {
    s32 unk0;
    ParsedUVVL_inner_1* unk4;
    Vec3F unk8;
    f32 unk14;
} ParsedUVVL_inner;

typedef struct ParsedUVVL_s {
    s32 unk0; // Count of unk4 to follow
    ParsedUVVL_inner* unk4;
} ParsedUVVL;


typedef struct UvVolumeLd_Rom_Exports_s {
    void (*func_uvvolumeld_rom_00400048)(void);
    void* (*uvParseUVVL)(u8* arg0);
    void (*func_uvvolumeld_rom_004001F8)(ParsedUVVL* arg0);
} UvVolumeLd_Rom_Exports;
#endif /* UVVOLUMELD_ROM_H */

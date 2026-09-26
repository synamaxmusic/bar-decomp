#ifndef UVMODEL_ROM_H
#define UVMODEL_ROM_H

typedef struct UnkStruct_uvmodel_rom_00400608_s {
    Vec3F *unk0;
    u8 unk4;
} UnkStruct_uvmodel_rom_00400608;


typedef struct Arg6_Struct_s {
    /* 0x00 */ char pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ char pad6[0x12]; /* maybe part of unk5[0x13]? */
    /* 0x1C */ Vtx *unk18;
} Arg6_Struct; /* size = 0x20 */


typedef struct UvModel_Exports_s {
    /* 0x00 */ void (*func_uvmodel_rom_004002BC)(void);                      /* inferred */
    /* 0x04 */ void (*func_uvmodel_rom_0040031C)(s32);                   /* inferred */
    /* 0x08 */ void (*func_uvmodel_rom_00400324)(s32, s32);              /* inferred */
    /* 0x0C */ void (*func_uvmodel_rom_00400330)(s32, s32, s32);         /* inferred */
    /* 0x10 */ s32 (*func_uvmodel_rom_00400340)(s32);                   /* inferred */
    /* 0x14 */ void (*func_uvmodel_rom_004003A4)(s32, s32, Mtx4F *);    /* inferred */
    /* 0x18 */ void (*func_uvmodel_rom_0040045C)(s32, ...);             /* inferred */
    /* 0x1C */ u8 (*func_uvmodel_rom_00400608)(UnkStruct_uvmodel_rom_00400608 *, f32); /* inferred */
    /* 0x20 */ s16 (*func_uvmodel_rom_004006B4)(f32, f32, f32, f32, Mtx4F *, uvModelLOD *, ParsedUVMD *); /* inferred */
    /* 0x24 */ s16 (*func_uvmodel_rom_0040199C)(f32, f32, f32, f32, f32, f32, Mtx4F *, uvModelLOD *, ParsedUVMD *); /* inferred */
    /* 0x28 */ s16 (*func_uvmodel_rom_0040215C)(f32, f32, f32, Mtx4F *, Vec3F *); /* inferred */
    /* 0x2C */ s32 (*func_uvmodel_rom_00402224)(f32, f32, f32, uvModelLOD_inner *); /* inferred */
    /* 0x30 */ u8 (*func_uvmodel_rom_004022E4)(f32, f32, f32, f32, f32, f32, UnkUVMD_24_Unk4 *, f32 *, f32 *, s16 *, s16 *); /* inferred */
    /* 0x34 */ void (*func_uvmodel_rom_00402AD0)(void);                     /* inferred */
    /* 0x38 */ Mtx4F *(*func_uvmodel_rom_00402AE0)(void);                   /* inferred */
    /* 0x3C */ void (*func_uvmodel_rom_00402AFC)(Mtx4F *);              /* inferred */
    /* 0x40 */ void (*func_uvmodel_rom_00402B98)(void);                     /* inferred */
    /* 0x44 */ void (*func_uvmodel_rom_00402BB8)(ParsedUVMD *, s32, s32); /* inferred */
    /* 0x48 */ s32 (*func_uvmodel_rom_00402CEC)(ParsedUVMD *, uvGfxState **, s32); /* inferred */
    /* 0x4C */ void (*func_uvmodel_rom_00402E50)(s32, s32);             /* inferred */
} UvModel_Exports;                                  /* size = 0x50 */

#endif /* UVMODEL_ROM_H */

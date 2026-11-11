#ifndef UVINTERSECT_ROM_H
#define UVINTERSECT_ROM_H


typedef struct UvIntersect_Exports_s {
    /* 0x00 */ void (*func_uvintersect_rom_00400114)();                      /* inferred */
    /* 0x04 */ s32 (*func_uvintersect_rom_00400144)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *); /* inferred */
    /* 0x08 */ s32 (*func_uvintersect_rom_00400460)(f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x0C */ s32 (*func_uvintersect_rom_004004C4)(f32, f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x10 */ s32 (*func_uvintersect_rom_00400530)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x14 */ void (*func_uvintersect_rom_00400700)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, Vec3F *); /* inferred */
    /* 0x18 */ s32 (*_uvSurfGetNorm)(Vtx *, s32, s32, s32, Vec3F *, f32); /* inferred */
    /* 0x1C */ s32 (*func_uvintersect_rom_0040093C)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, Vec3F *, f32 *); /* inferred */
    /* 0x20 */ s32 (*func_uvintersect_rom_00400E60)(f32, f32, f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x24 */ s32 (*func_uvintersect_rom_00400FA8)(f32, f32, f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x28 */ s32 (*func_uvintersect_rom_004010F0)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x2C */ s32 (*func_uvintersect_rom_00401318)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, Vec3F *); /* inferred */
    /* 0x30 */ s32 (*func_uvintersect_rom_0040191C)(f32, f32, f32, f32, f32, f32, f32, f32); /* inferred */
    /* 0x34 */ void (*func_uvintersect_rom_00401A2C)(f32 *, f32 *, f32 *, f32 *, f32, f32, f32, f32); /* inferred */
    /* 0x38 */ void (*func_uvintersect_rom_00401CB0)(f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32, f32, f32, f32); /* inferred */
    /* 0x3C */ void (*func_uvintersect_rom_004020A0)(Mtx4F *, s16, Vec3F *); /* inferred */
    /* 0x40 */ s32 (*func_uvintersect_rom_004021A0)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, Vec3F *); /* inferred */
} UvIntersect_Exports;                              /* size = 0x44 */


#endif /* UVINTERSECT_ROM_H */

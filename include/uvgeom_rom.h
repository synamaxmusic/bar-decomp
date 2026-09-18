#ifndef UVGEOM_ROM_H
#define UVGEOM_ROM_H

typedef struct UvGeom_Rom_0040019C_s {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ s32 unk4;  /* inferred */
    /* 0x08 */ Gfx *unk8; /* inferred */
    /* 0x0C */ s16 unkC;  /* inferred */
    /* 0x0E */ s16 unkE;  /* inferred */
    /* 0x10 */ s16 unk10; /* inferred */
    /* 0x12 */ s16 unk12; /* inferred */
} UvGeom_Rom_0040019C;    /* size = 0x14 */

typedef struct UvGeom_Exports_s {
    /* 0x00 */ void (*func_uvgeom_rom_00400124)(void);                      /* inferred */
    /* 0x04 */ void (*uvEndTmesh)(s32, s32, UvGeom_Rom_0040019C *, Gfx **); /* inferred */
    /* 0x08 */ void (*uvEndGrid)(s32, s32, s32, s32, s32, s32, UvGeom_Rom_0040019C *, Gfx **); /* inferred */
    /* 0x0C */ void (*uvSetFillColor)(f32, f32, f32, f32);    /* inferred */
    /* 0x10 */ void (*uvVtxRect)(s16, s32, s32, s32);   /* inferred */
    /* 0x14 */ void (*uvVtxEndPolyInternal)(s32, s32, UvGeom_Rom_0040019C *, Gfx **); /* inferred */
} UvGeom_Exports;                                   /* size = 0x18 */

#endif /* UVGEOM_ROM_H */

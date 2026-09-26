#ifndef UVDOBJ_ROM_H
#define UVDOBJ_ROM_H
typedef struct UvDobj_Exports_s {
    /* 0x00 */ void (*func_uvdobj_rom_004005C4)(void);                                    /* inferred */
    /* 0x04 */ void (*func_uvdobj_rom_00400544)(s32, s32);                                /* inferred */
    /* 0x08 */ s32 (*func_uvdobj_rom_00400558)(s32, s32, s32);                            /* inferred */
    /* 0x0C */ void (*func_uvdobj_rom_0040056C)(s32);                                     /* inferred */
    /* 0x10 */ void (*func_uvdobj_rom_00400704)(s32, s32);                                /* inferred */
    /* 0x14 */ void (*uvDobjModel)(s32, s32);                                /* inferred */
    /* 0x18 */ u16 (*uvDobjGetModel)(s32);                                      /* inferred */
    /* 0x1C */ void (*uvDobjProps)(s32, ...);                                /* inferred */
    /* 0x20 */ void (*uvDobjGetProp)(s32, ...);                                /* inferred */
    /* 0x24 */ void (*uvDobjPosm)(s32, s32, Mtx4F *);                       /* inferred */
    /* 0x28 */ void (*uvDobjGetPosm)(s32, s32, Mtx4F *);                       /* inferred */
    /* 0x2C */ void (*func_uvdobj_rom_00400FF0)(s32, s32);                                /* inferred */
    /* 0x30 */ void (*func_uvdobj_rom_00401028)(s32, s32);                                /* inferred */
    /* 0x34 */ u8 (*func_uvdobj_rom_00401074)(s32);                                       /* inferred */
    /* 0x38 */ void (*func_uvdobj_rom_004010B4)(s32, s32);                                /* inferred */
    /* 0x3C */ s32 (*uvDobjCreate)(void);                                     /* inferred */
    /* 0x40 */ void (*func_uvdobj_rom_004011CC)(s32);                                     /* inferred */
    /* 0x44 */ void (*func_uvdobj_rom_00401598)(s32, f32);                                /* inferred */
    /* 0x48 */ s32 (*func_uvdobj_rom_00401F14)(f32, f32, f32);                            /* inferred */
    /* 0x4C */ s32 (*func_uvdobj_rom_00402138)(f32, f32, f32, f32, f32, f32, f32, s32 *); /* inferred */
    /* 0x50 */ s32 (*func_uvdobj_rom_00402420)(f32, f32, f32, f32, s32 **, f32 **,
                                               Vec3F **); /* inferred */
    /* 0x54 */ s32 (*func_uvdobj_rom_00402870)(f32, f32, f32, f32, f32, f32, s32 **, f32 **,
                                               Vec3F **);            /* inferred */
    /* 0x58 */ s32 (*func_uvdobj_rom_0040359C)(s32, Quat *, u8 *);   /* inferred */
    /* 0x5C */ void (*func_uvdobj_rom_004038C4)(s32, s32, s32, s32); /* inferred */
    /* 0x60 */ u16 (*func_uvdobj_rom_00403954)(s32 **);              /* inferred */
    /* 0x64 */ s32 *D_uvdobj_rom_004039B0;                           /* inferred */
} UvDobj_Exports;                                                    /* size = 0x68 */
#endif /* UVDOBJ_ROM_H */

#ifndef MISC_H
#define MISC_H

typedef struct UnkStruct_misc_00403748_s {
    Vec3F unk0;
    Vec3F unkC;
    f32 unk18;
    s32 unk1C;
} UnkStruct_misc_00403748;

typedef struct UnkStruct_misc_004006A0_s {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ f32 unk1C;                           /* inferred */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ f32 unk24;                           /* inferred */
    /* 0x28 */ f32 unk28;                           /* inferred */
    /* 0x2C */ f32 unk2C;                           /* inferred */
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} UnkStruct_misc_004006A0;                          /* size = 0x3C */


typedef struct Misc_Exports_s {
    /* 0x000 */ void (*func_misc_00400390)(void);
    /* 0x004 */ void (*func_misc_00400398)(f32);
    /* 0x008 */ f32 (*func_misc_00400400)(f32, f32, f32);
    /* 0x00C */ f32 (*func_misc_004004B8)(f32, f32, f32);
    /* 0x010 */ void (*func_misc_004005A0)(Vec3F *, Vec3F *, f32);
    /* 0x014 */ void (*func_misc_004006A0)(Mtx4F *, Mtx4F *, f32);
    /* 0x018 */ void (*func_misc_0040070C)(Vec3F *, UnkStruct_misc_004006A0 *);
    /* 0x01C */ void (*func_misc_00400844)(Vec3F, f32 *, f32 *, f32 *);
    /* 0x020 */ void (*func_misc_00400884)(f32, f32, f32, f32 *);
    /* 0x024 */ void (*func_misc_004008B4)(f32, f32, f32, f32 *, f32 *, f32 *);
    /* 0x028 */ void (*func_misc_004009B0)(f32, f32, f32, f32 *, f32 *, f32 *);
    /* 0x02C */ f32 (*func_misc_00400A7C)(f32);
    /* 0x030 */ f32 (*func_misc_00400AD0)(f32);
    /* 0x034 */ f32 (*func_misc_00400BF0)(f32);
    /* 0x038 */ void (*func_misc_00400CA8)(Mtx4F *, f32, f32, f32);
    /* 0x03C */ void (*func_misc_00400E38)(UnkStruct_misc_004006A0 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
    /* 0x040 */ void (*func_misc_00400FB8)(f32, f32, f32, f32, f32, f32, Mtx4F *);
    /* 0x044 */ void (*miscTLBStoreFault)(void);
    /* 0x048 */ void (*func_misc_00401080)(f32, f32, f32, f32 *, f32 *, f32 *);
    /* 0x04C */ s32 (*func_misc_004012A4)(s32, s32, s32);
    /* 0x050 */ void (*func_misc_004012E4)(Mtx4F *, Mtx4F *, Mtx4F *, f32);
    /* 0x054 */ f32 (*func_misc_0040142C)(f32, f32, f32);
    /* 0x058 */ f32 (*func_misc_0040146C)(f32);
    /* 0x05C */ f32 (*func_misc_00401528)(f32);
    /* 0x060 */ f32 (*func_misc_004015A0)(f32);
    /* 0x064 */ f32 (*func_misc_00401614)(f32);
    /* 0x068 */ f32 (*func_misc_004016CC)(f32, f32);
    /* 0x06C */ f32 (*func_misc_004017A8)(Vec2F *);
    /* 0x070 */ f32 (*miscVec2FLen)(Vec2F *);
    /* 0x074 */ void (*func_misc_004017FC)(Vec2F *, Vec2F *);
    /* 0x078 */ void (*func_misc_0040187C)(Vec2F *, Vec2F *, f32, Vec2F *);
    /* 0x07C */ f32 (*miscVec2FDot)(Vec2F *, Vec2F *);
    /* 0x080 */ void (*miscVec2FAdd)(Vec2F *, Vec2F *, Vec2F *);
    /* 0x084 */ void (*miscVec2FSub)(Vec2F *, Vec2F *, Vec2F *);
    /* 0x088 */ void (*miscVec2FMult)(Vec2F *, f32, Vec2F *);
    /* 0x08C */ void (*func_misc_00401938)(Vec2F *, UnkStruct_misc_004006A0 *);
    /* 0x090 */ void (*func_misc_0040197C)(Vec2F *, Vec2F *);
    /* 0x094 */ void (*func_misc_00401990)(Vec2F *, Vec2F *, Vec2F *, f32);
    /* 0x098 */ s32 (*func_misc_004019FC)(f32, f32, f32, f32, f32, f32, f32, f32, f32 *, Vec3F *);
    /* 0x09C */ void (*miscVec3FAdd)(Vec3F *, Vec3F *, Vec3F *);
    /* 0x0A0 */ void (*miscVec3FSub)(Vec3F *, Vec3F *, Vec3F *);
    /* 0x0A4 */ void (*miscVec3FMult)(Vec3F *, f32, Vec3F *);
    /* 0x0A8 */ void (*func_misc_00401EA8)(Vec3F *, UnkStruct_misc_004006A0 *);
    /* 0x0AC */ void (*miscVec3FSet)(Vec3F *, Vec3F *);
    /* 0x0B0 */ void (*func_misc_00401F48)(Quat *, Quat *, f32, Quat *);
    /* 0x0B4 */ void (*func_misc_00401FA0)(f32, f32, f32, Quat *);
    /* 0x0B8 */ void (*func_misc_0040213C)(Mtx4F *, f32, f32, f32);
    /* 0x0BC */ void (*func_misc_0040234C)(Quat *, Mtx4F *);
    /* 0x0C0 */ void (*func_misc_00402528)(Quat *, Quat *, f32, f32, f32, f32);
    /* 0x0C4 */ void (*func_misc_00402698)(Mtx4F *, f32 *, f32 *, f32 *);
    /* 0x0C8 */ f32 (*func_misc_00402730)(f32, f32, f32, f32, f32, s32, f32 *, f32 *, f32 *);
    /* 0x0CC */ void (*func_misc_00402874)(s32, f32, f32, f32, f32 *, f32 *);
    /* 0x0D0 */ void (*func_misc_004029DC)(s32, u8 *, f32);
    /* 0x0D4 */ void (*func_misc_00402A5C)(Mtx4F *, f32, f32, f32, f32, f32, f32);
    /* 0x0D8 */ void (*func_misc_00402BFC)(Vec3F *, Vec3F *, f32);
    /* 0x0DC */ f32 (*func_misc_00402D48)(f32);
    /* 0x0E0 */ void (*func_misc_00402E94)(Vec3F *, Vec3F *, Vec3F *, f32);
    /* 0x0E4 */ f32 (*func_misc_00402EFC)(f32, f32, f32, f32);
    /* 0x0E8 */ void (*func_misc_00403000)(Vec3F *, Vec3F *, f32, f32);
    /* 0x0EC */ s32 (*func_misc_00403110)(Mtx4F *, s32, s32, s32);
    /* 0x0F0 */ void (*miscLoadFileRomModule)(void);
    /* 0x0F4 */ void (*miscUnloadFileRomModule)(void);
    /* 0x0F8 */ s32 (*func_misc_00403348)(f32, f32, f32, f32, f32, f32, f32, f32 *);
    /* 0x0FC */ void (*func_misc_00403650)(s32, s32, s32);
    /* 0x100 */ f32 (*func_misc_00403748)(UnkStruct_misc_00403748 *, Vec3F *, Vec3F *);
    /* 0x104 */ GuiMenuItem *(*func_misc_004038D8)(GuiMenuOption *, u8 *, s16, f32, f32, s32 *, GuiSlider **);
    /* 0x108 */ GuiMenuItem *(*func_misc_00403A5C)(GuiMenuOption *, u8 *, u8 *, u8 *, UvGrphStruct *, f32 *, Inner30 **);
    /* 0x10C */ GuiMenuItem *(*func_misc_00403BEC)(GuiMenuOption *, u8 *, void (*)(void *));
    /* 0x110 */ void (*func_misc_00403CA4)(Vec3F *, Vec3F *);
    /* 0x114 */ f32 (*func_misc_00403CD8)(f32);
    /* 0x118 */ s32 (*func_misc_00403D8C)(u8 *, u8, s16, s16, s16, s16, s16, s16);
    /* 0x11C */ void (*miscSetRandSeed)(u32);
    /* 0x120 */ f32 (*miscRandFLCG)(void);
} Misc_Exports;                              


#endif /* MISC_H */

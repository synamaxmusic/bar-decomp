#ifndef SCRN_H
#define SCRN_H

typedef struct UnkStruct_scrn_004006C8_s {
    s32 unk0[4];
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} UnkStruct_scrn_004006C8;

typedef struct Scrn_Exports_s {
    /* 0x00 */ void (*func_scrn_00400094)(void);                      /* inferred */
    /* 0x04 */ void (*func_scrn_0040009C)(s32, s32 *);            /* inferred */
    /* 0x08 */ void (*func_scrn_004001DC)(void);                      /* inferred */
    /* 0x0C */ void (*func_scrn_0040027C)(void);                      /* inferred */
    /* 0x10 */ void (*func_scrn_00400398)(void);                     /* inferred */
    /* 0x14 */ s16 (*func_scrn_00400474)(s32 *);                 /* inferred */
    /* 0x18 */ UnkStruct_scrn_004006C8 *D_scrn_004006C8;      /* inferred */
    /* 0x1C */ s32 *D_scrn_004006E8;                          /* inferred */
} Scrn_Exports;                                     /* size = 0x20 */

#endif /* SCRN_H */

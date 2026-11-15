#ifndef VOLTEST_H
#define VOLTEST_H

typedef struct UnkStruct_voltest_00400594_s {
    ParsedUVVL *uvvl;
    s8 unk3[4];
    s8 unk7[4];
    s8 unk8[8];
    struct UnkStruct_voltest_00400594_s *unk14;
} UnkStruct_voltest_00400594;

typedef struct VolTest_Exports_s {
    /* 0x00 */ void (*func_voltest_0040006C)(void);
    /* 0x04 */ void *(*func_voltest_00400074)(s32);
    /* 0x08 */ void (*func_voltest_00400128)(void);
    /* 0x0C */ s32 (*func_voltest_00400194)(UnkStruct_voltest_00400594 *, s32, s32);
} VolTest_Exports;
#endif /* VOLTEST_H */

#ifndef UVBILL_ROM_H
#define UVBILL_ROM_H
typedef struct UvBill_Exports_s {
    /* 0x0 */ void (*uvBillDestroy)(void);
    /* 0x4 */ void (*func_uvbill_rom_004002C0)(s32);
    /* 0x8 */ s32 (*func_uvbill_rom_004010B8)(f32, f32, f32, f32, f32, f32, s32, s32 **, f32 **,
                                              Vec3F **);
    /* 0xC */ s32 (*func_uvbill_rom_00401388)(s32, f32, f32, f32, f32);
    /* 0x10 */ s32 (*func_uvbill_rom_00401418)(f32, f32, f32, f32, s32, s32 **);
    /* 0x14 */ void (*uvBillPosm)(s32, Mtx4F *);
    /* 0x18 */ void (*uvBillProps)(s32, ...);
    /* 0x1C */ s32 (*uvBillFindFree)(void);
    /* 0x20 */ void (*uvBillFreeId)(s32);
} UvBill_Exports;

#endif /* UVBILL_ROM_H*/

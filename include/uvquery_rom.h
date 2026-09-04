#ifndef UVQUERY_ROM_H
#define UVQUERY_ROM_H
typedef struct UvQuery_Exports_s {
    /* 0x00 */ void (*func_uvquery_rom_004001AC)(void);            
    /* 0x04 */ f32* (*uvQueryGetFloatValues)(void);             
    /* 0x08 */ s32* (*uvQueryGetIntValues)(void);             
    /* 0x0C */ Vec3F* (*uvQueryGetFloatVectors)(void);             
    /* 0x10 */ s32 (*func_uvquery_rom_00400224)(void);            
    /* 0x14 */ s32* (*func_uvquery_rom_00400270)(void);           
    /* 0x18 */ s32* (*func_uvquery_rom_0040027C)(void);           
    /* 0x1C */ s32 (*func_uvquery_rom_00400288)(void);            
    /* 0x20 */ void (*uvQueryDoSorting)(void);           
    /* 0x24 */ void* (*func_uvquery_rom_004004CC)(void);            
    /* 0x28 */ void (*func_uvquery_rom_004004F4)(s32, ...);   
    /* 0x2C */ void (*func_uvquery_rom_00400558)(s32, ...);   
    /* 0x30 */ void (*func_uvquery_rom_004005C0)(f32*, s32);  
    /* 0x34 */ void (*func_uvquery_rom_004005D4)(s32, u16);   
    /* 0x38 */ s32 (*func_uvquery_rom_004005EC)(void);            
    /* 0x3C */ s32* (*func_uvquery_rom_004005F8)(void);           
    /* 0x40 */ s32 (*func_uvquery_rom_00400604)(void);            
    /* 0x44 */ u16 (*func_uvquery_rom_00400610)(void);            
} UvQuery_Exports;                                   /* size = 0x48 */

#endif /* UVQUERY_ROM_H*/

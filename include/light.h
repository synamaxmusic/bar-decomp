#ifndef LIGHT_H
#define LIGHT_H

typedef struct Light_Exports_s {
    /* 0x00 */ void (*func_light_00400090)(void);
    /* 0x04 */ void (*func_light_00400098)(UnkLightStruct *, s32);
    /* 0x08 */ void (*func_light_00400120)(UnkLightStruct *, s32, ...);
    /* 0x0C */ void (*func_light_0040050C)(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, u8);
    /* 0x10 */ void (*func_light_004005AC)(Vec3F *, s32);
    /* 0x14 */ void (*func_light_004008BC)(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
    /* 0x18 */ void (*func_light_00400950)(s32, s32, s32);
    /* 0x1C */ void (*func_light_00400BA8)(s32, s32);
} Light_Exports; /* size = 0x20 */

#endif /* LIGHT_H */

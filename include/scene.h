#ifndef SCENE_H
#define SCENE_H


typedef enum SceneFogType_e {
    /* 0 */ FOG_TYPE_NONE,
    /* 1 */ FOG_TYPE_HARDWARE,
    /* 2 */ FOG_TYPE_SOFTWARE
} SceneFogType;

typedef struct UnkLightStruct_s {
    char pad[0x2C];
} UnkLightStruct;

typedef struct Scene_s {
    /* 0x00 */ s32 unk0;     /* inferred */
    /* 0x04 */ s32 unk4;     /* inferred */
    /* 0x08 */ s8 terrain;      /* inferred */
    /* 0x09 */ s8 environment;      /* inferred */
    /* 0x0A */ char padA[2]; /* maybe part of environment[3]? */
    /* 0x0C */ s32 unkC;     /* inferred */
    /* 0x10 */ char pad10[2];
    /* 0x12 */ u8 unk12;                /* inferred */
    /* 0x13 */ s8 unk13;                /* inferred */
    /* 0x14 */ char pad14[0x10];        /* maybe part of unk13[0x11]? */
    /* 0x24 */ s32 *unk24;              /* inferred */
    /* 0x28 */ UnkLightStruct unk28[4]; /* maybe part of unk24[0x2D]? */
    /* 0xD8 */ s32 fogType;               /* inferred */
    /* 0xDC */ f32 fogRed;               /* inferred */
    /* 0xE0 */ f32 fogGreen;               /* inferred */
    /* 0xE4 */ f32 fogBlue;               /* inferred */
    /* 0xE8 */ f32 fogStart;               /* inferred */
    /* 0xEC */ f32 fogMax;               /* inferred */
    /* 0xF0 */ f32 farPlane;               /* inferred */
    /* 0xF4 */ f32 unkF4;               /* inferred */
} Scene; /* size = 0xF8 */

typedef struct UnkStruct_scene_004013F4_s {
    /* 0x00 */ s32 unk0;    /* inferred */
    /* 0x04 */ f32 unk4;    /* inferred */
    /* 0x08 */ f32 unk8;    /* inferred */
    /* 0x0C */ f32 unkC;    /* inferred */
    /* 0x10 */ f32 unk10;   /* inferred */
    /* 0x14 */ f32 unk14;   /* inferred */
    /* 0x18 */ f32 unk18;   /* inferred */
    /* 0x1C */ f32 unk1C;   /* inferred */
} UnkStruct_scene_004013F4; /* size = 0x20 */

typedef struct Scene_Exports_s {
    /* 0x00 */ void (*func_scene_00400EC0)(void);      /* inferred */
    /* 0x04 */ s32 (*func_scene_00400000)(s32);        /* inferred */
    /* 0x08 */ s32 (*func_scene_00400030)(s32);        /* inferred */
    /* 0x0C */ s32 (*func_scene_00400060)(s32);        /* inferred */
    /* 0x10 */ s32 (*func_scene_004000FC)(s32);        /* inferred */
    /* 0x14 */ void (*func_scene_004003F4)(s32);       /* inferred */
    /* 0x18 */ void (*func_scene_00400C58)(void);      /* inferred */
    /* 0x1C */ void (*func_scene_00400C60)(void);      /* inferred */
    /* 0x20 */ void (*func_scene_00400EC8)(GuiMenu *); /* inferred */
    /* 0x24 */ void (*func_scene_004013F4)(UnkStruct_scene_004013F4 *,
                                           UnkStruct_scene_004013F4 *); /* inferred */
    /* 0x28 */ void (*func_scene_00401438)(UnkStruct_scene_004013F4 *, UnkStruct_scene_004013F4 *,
                                           UnkStruct_scene_004013F4 *, f32); /* inferred */
    /* 0x2C */ Scene *sCurrentScene;                   /* inferred */
} Scene_Exports;                                                             /* size = 0x30 */
#endif /* SCENE_H */

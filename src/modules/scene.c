// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"


typedef struct GenericExports_s {
    char pad0[0x4];
    void (*unk4)(void);
} GenericExports;

typedef struct UnkLightExports_s {
    char pad[0x4];
    void (*unk4)(UnkLightStruct *, s32);
} UnkLightExports;

typedef struct SceneTrackInfo_s {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 trackModel;
    /* 0x04 */ s32 trackId;
    /* 0x08 */ u8 *trackName;
    /* 0x0C */ s32 trackTag;
    /* 0x10 */ s16 musicId;
    /* 0x12 */ u8 enableGlare;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ f32 unk1C[32];
} SceneTrackInfo; /* size = 0x9C */

s32 func_scene_00400000(s32 arg0);
s32 func_scene_00400030(s32 arg0);
s32 func_scene_00400060(s32 arg0);
s32 func_scene_004000FC(s32 arg0);
void func_scene_00400188(s32 arg0);
void func_scene_004002A8(void);
void func_scene_004002F0(void);
void func_scene_00400374(void);
void func_scene_004003F4(s32 arg0);
void func_scene_00400C58(void);
void func_scene_00400C60(void);
void func_scene_00400CB8(void);
void func_scene_00400EC0(void);
void func_scene_00400EC8(GuiMenu *menu);
void func_scene_00401254(s32 arg0);
void func_scene_004012B0(s32 arg0);
void func_scene_004012B8(GuiSlider *slider);
void func_scene_00401324(GuiSlider *slider);
void func_scene_004013F4(UnkStruct_scene_004013F4 *arg0, UnkStruct_scene_004013F4 *arg1);
void func_scene_00401438(UnkStruct_scene_004013F4 *arg0, UnkStruct_scene_004013F4 *arg1,
                         UnkStruct_scene_004013F4 *arg2, f32 arg3);

void __entrypoint_func_scene_400e0c(Scene_Exports *exports);

// .data
SceneTrackInfo SceneTracks[] = {
    {
        -1,
        -1,
        0,
        "NONE",
        'NONE',
        -1,
        0,
        0,
        0xFF,
        -1,
        {
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        0x12,
        0x16,
        0,
        "TEST ROAD",
        'TEST',
        -1,
        1,
        0,
        0xFF,
        -1,
        {
            -834.0f, -1498.0f, 0.0f,     -1.6f, -834.0f, -1502.0f, 0.0f, -1.6f, -846.0f, -1498.0f, 0.0f,
            -1.6f,   -846.0f,  -1502.0f, 0.0f,  -1.6f,   0.0f,     0.0f, 0.0f,  0.0f,    0.0f,     0.0f,
            0.0f,    0.0f,     0.0f,     0.0f,  0.0f,    0.0f,     0.0f, 0.0f,  0.0f,    0.0f,
        },
    },
    {
        0x11,
        0x16,
        'lev1',
        "TEST GRID",
        'GRID',
        -1,
        1,
        0,
        0xFF,
        -1,
        {
            10.0f, 0.0f, 0.0f,   0.0f, 0.0f, 10.0f, 0.0f, 1.6f, -10.0f, 0.0f, 0.0f,
            3.1f,  0.0f, -10.0f, 0.0f, 4.7f, 0.0f,  0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
            0.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f,   0.0f,
        },
    },
    {
        0,
        0xC,
        0,
        "CHECKER BOARD",
        'CHCK',
        -1,
        1,
        0,
        0xFF,
        -1,
        {
            0.0f, 250.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        0x10,
        0xC,
        0,
        "ROUND TRACK",
        'ROND',
        -1,
        1,
        0,
        0xFF,
        -1,
        {
            -1000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,     0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,     0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        0x13,
        0xE,
        'tk01',
        "Coventry Cove",
        'ENGL',
        9,
        1,
        1,
        3,
        0,
        {
            -0.2f, 5.0f, 0.0f,  0.0f,  0.2f, 15.0f, 0.0f,  0.0f,  -0.2f, 25.0f, 0.0f,
            0.0f,  0.2f, 35.0f, 0.0f,  0.0f, -0.2f, 45.0f, 0.0f,  0.0f,  0.2f,  55.0f,
            0.0f,  0.0f, -0.2f, 65.0f, 0.0f, 0.0f,  0.2f,  75.0f, 0.0f,  0.0f,
        },
    },
    {
        0x17,
        0xF,
        'tk02',
        "Wicked Woods",
        'WKWD',
        4,
        0,
        1,
        0xFF,
        5,
        {
            -0.2f, 85.0f, 0.0f,   0.0f,   0.2f, 95.0f, 0.0f,   0.0f,   -0.2f, 105.0f, 0.0f,
            0.0f,  0.2f,  115.0f, 0.0f,   0.0f, -0.2f, 125.0f, 0.0f,   0.0f,  0.2f,   135.0f,
            0.0f,  0.0f,  -0.2f,  145.0f, 0.0f, 0.0f,  0.2f,   155.0f, 0.0f,  0.0f,
        },
    },
    {
        0x22,
        0x10,
        'tk03',
        "Mount Mayhem",
        'ALPS',
        2,
        0,
        1,
        0,
        1,
        {
            -0.2f, 35.0f, 0.0f,  0.0f,  0.2f, 45.0f, 0.0f,  0.0f,   -0.2f, 55.0f, 0.0f,
            0.0f,  0.2f,  65.0f, 0.0f,  0.0f, -0.2f, 75.0f, 0.0f,   0.0f,  0.2f,  85.0f,
            0.0f,  0.0f,  -0.2f, 95.0f, 0.0f, 0.0f,  0.2f,  105.0f, 0.0f,  0.0f,
        },
    },
    {
        0x14,
        0x11,
        'tk04',
        "Sunset Sands",
        'DSRT',
        1,
        1,
        1,
        2,
        3,
        {
            -0.2f, 10.0f, 0.0f,  0.0f,  0.2f, 20.0f, 0.0f,  0.0f,  -0.2f, 30.0f, 0.0f,
            0.0f,  0.2f,  40.0f, 0.0f,  0.0f, -0.2f, 50.0f, 0.0f,  0.0f,  0.2f,  60.0f,
            0.0f,  0.0f,  -0.2f, 70.0f, 0.0f, 0.0f,  0.2f,  80.0f, 0.0f,  0.0f,
        },
    },
    {
        0x16,
        0x12,
        'tk05',
        "Inferno Isle",
        'JUNG',
        5,
        1,
        1,
        4,
        2,
        {
            -0.2f, 5.0f, 0.0f,  0.0f,  0.2f, 15.0f, 0.0f,  0.0f,  -0.2f, 25.0f, 0.0f,
            0.0f,  0.2f, 35.0f, 0.0f,  0.0f, -0.2f, 45.0f, 0.0f,  0.0f,  0.2f,  55.0f,
            0.0f,  0.0f, -0.2f, 65.0f, 0.0f, 0.0f,  0.2f,  75.0f, 0.0f,  0.0f,
        },
    },
    {
        0x23,
        0x13,
        'tk06',
        "Metro Madness",
        'TRK6',
        3,
        0,
        1,
        1,
        4,
        {
            -0.2f, 5.0f, 0.0f,  0.0f,  0.2f, 15.0f, 0.0f,  0.0f,  -0.2f, 25.0f, 0.0f,
            0.0f,  0.2f, 35.0f, 0.0f,  0.0f, -0.2f, 45.0f, 0.0f,  0.0f,  0.2f,  55.0f,
            0.0f,  0.0f, -0.2f, 65.0f, 0.0f, 0.0f,  0.2f,  75.0f, 0.0f,  0.0f,
        },
    },
    {
        0x24,
        3,
        'tk07',
        "Stunt O Rama",
        'TRK7',
        6,
        0,
        0,
        0xFF,
        -1,
        {
            -977.7f, -149.9f, 144.2f, 3.33f, -977.7f, -149.9f, 144.2f, 3.33f,
            -977.7f, -149.9f, 144.2f, 3.33f, -977.7f, -149.9f, 144.2f, 3.33f,
            0.0f,    0.0f,    69.0f,  0.0f,  0.0f,    0.0f,    69.0f,  0.0f,
            0.0f,    0.0f,    69.0f,  0.0f,  0.0f,    0.0f,    69.0f,  0.0f,
        },
    },
    {
        0x13,
        0xA,
        0,
        "TRACK 8",
        'TRK8',
        7,
        0,
        0,
        0xFF,
        -1,
        {
            -954.3f, -1445.8f, -94.5f, -0.65f, -959.5f, -1442.0f, -94.5f, -0.65f,
            -963.4f, -1439.6f, -94.5f, -0.65f, -951.1f, -1448.2f, -94.5f, -0.65f,
            0.0f,    0.0f,     69.0f,  0.0f,   0.0f,    0.0f,     69.0f,  0.0f,
            0.0f,    0.0f,     69.0f,  0.0f,   0.0f,    0.0f,     69.0f,  0.0f,
        },
    },
    {
        0x13,
        0xA,
        0,
        "TRACK 9",
        'TRK9',
        -1,
        0,
        0,
        0xFF,
        -1,
        {
            -954.3f, -1445.8f, -94.5f, -0.65f, -959.5f, -1442.0f, -94.5f, -0.65f,
            -963.4f, -1439.6f, -94.5f, -0.65f, -951.1f, -1448.2f, -94.5f, -0.65f,
            0.0f,    0.0f,     69.0f,  0.0f,   0.0f,    0.0f,     69.0f,  0.0f,
            0.0f,    0.0f,     69.0f,  0.0f,   0.0f,    0.0f,     69.0f,  0.0f,
        },
    },
    {
        0x13,
        0xA,
        0,
        "TRACK 10",
        'TR10',
        -1,
        0,
        0,
        0xFF,
        -1,
        {
            -954.3f, -1445.8f, -94.5f, -0.65f, -959.5f, -1442.0f, -94.5f, -0.65f,
            -963.4f, -1439.6f, -94.5f, -0.65f, -951.1f, -1448.2f, -94.5f, -0.65f,
            0.0f,    0.0f,     69.0f,  0.0f,   0.0f,    0.0f,     69.0f,  0.0f,
            0.0f,    0.0f,     69.0f,  0.0f,   0.0f,    0.0f,     69.0f,  0.0f,
        },
    },
    {
        0xE,
        0xD,
        0,
        "DRAGSTRIP",
        'DRAG',
        -1,
        0,
        0,
        0xFF,
        -1,
        {
            0.0f, 1950.0f, 0.0f,    3.14f,   0.0f, 1960.0f, 0.0f,    0.0f,    0.0f, 1970.0f, 0.0f,
            0.0f, 0.0f,    1980.0f, 0.0f,    0.0f, 0.0f,    1990.0f, 0.0f,    0.0f, 0.0f,    2000.0f,
            0.0f, 0.0f,    0.0f,    2010.0f, 0.0f, 0.0f,    0.0f,    2020.0f, 0.0f, 0.0f,
        },
    },
    {
        0xC,
        3,
        0,
        "DERBY",
        'DRBY',
        -1,
        0,
        0,
        0xFF,
        -1,
        {
            25.0f, 1350.0f, 0.0f,    0.0f,    35.0f, 1350.0f, 0.0f,    0.0f,    45.0f, 1350.0f, 0.0f,
            0.0f,  55.0f,   1350.0f, 0.0f,    0.0f,  65.0f,   1350.0f, 0.0f,    0.0f,  75.0f,   1350.0f,
            0.0f,  0.0f,    85.0f,   1350.0f, 0.0f,  0.0f,    95.0f,   1350.0f, 0.0f,  0.0f,
        },
    },
    {
        0x18,
        3,
        'mp01',
        "MULT 1",
        'MLT1',
        0,
        0,
        0,
        0xFF,
        -1,
        {
            -120.0f, 70.0f, 0.0f,   -2.355f, 120.0f, 70.0f, 0.0f, 2.355f, -70.0f, -50.0f, 0.0f,
            -0.785f, 70.0f, -50.0f, 0.0f,    0.785f, 0.0f,  0.0f, 0.0f,   0.0f,   0.0f,   0.0f,
            0.0f,    0.0f,  0.0f,   0.0f,    0.0f,   0.0f,  0.0f, 0.0f,   0.0f,   0.0f,
        },
    },
    {
        0x1A,
        2,
        'mp02',
        "MULT 2",
        'MLT2',
        1,
        0,
        0,
        0xFF,
        -1,
        {
            -80.0f,  80.0f, 0.0f,   -2.355f, 80.0f,  80.0f, 0.0f, 2.355f, -80.0f, -80.0f, 0.0f,
            -0.785f, 80.0f, -80.0f, 0.0f,    0.785f, 0.0f,  0.0f, 0.0f,   0.0f,   0.0f,   0.0f,
            0.0f,    0.0f,  0.0f,   0.0f,    0.0f,   0.0f,  0.0f, 0.0f,   0.0f,   0.0f,
        },
    },
    {
        0x1B,
        2,
        'mp03',
        "MULT 3",
        'MLT3',
        5,
        0,
        0,
        0xFF,
        -1,
        {
            96.0f, 0.0f,   35.0f, 3.2f,  102.0f, 0.0f, 35.0f, 3.2f, 108.0f, 0.0f, 35.0f,
            3.2f,  114.0f, 0.0f,  35.0f, 3.2f,   0.0f, 0.0f,  0.0f, 0.0f,   0.0f, 0.0f,
            0.0f,  0.0f,   0.0f,  0.0f,  0.0f,   0.0f, 0.0f,  0.0f, 0.0f,   0.0f,
        },
    },
    {
        0x1C,
        2,
        'mp04',
        "MULT 4",
        'MLT4',
        6,
        0,
        0,
        0xFF,
        -1,
        {
            -140.0f, 60.0f,  1.3f,   -2.355f, 150.0f, 60.0f, 1.3f, 2.355f, -140.0f, -60.0f, 1.3f,
            -0.785f, 150.0f, -60.0f, 1.3f,    0.785f, 0.0f,  0.0f, 0.0f,   0.0f,    0.0f,   0.0f,
            0.0f,    0.0f,   0.0f,   0.0f,    0.0f,   0.0f,  0.0f, 0.0f,   0.0f,    0.0f,
        },
    },
    {
        0x1D,
        3,
        'mp05',
        "MULT 5",
        'MLT5',
        7,
        0,
        0,
        0xFF,
        -1,
        {
            0.0f, 30.0f,  0.0f, 0.0f, 0.0f, -30.0f, 0.0f, 3.33f, 30.0f, 0.0f, 0.0f,
            5.0f, -30.0f, 0.0f, 0.0f, 1.7f, 0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f,
            0.0f, 0.0f,   0.0f, 0.0f, 0.0f, 0.0f,   0.0f, 0.0f,  0.0f,  0.0f,
        },
    },
    {
        0x1E,
        2,
        'mp06',
        "MULT 6",
        'MLT6',
        9,
        0,
        0,
        0xFF,
        -1,
        {
            70.0f, 70.0f, 80.0f,  3.15f, -70.0f, -70.0f, 80.0f, 0.0f, -70.0f, 70.0f, 80.0f,
            3.15f, 70.0f, -70.0f, 80.0f, 0.0f,   0.0f,   0.0f,  0.0f, 0.0f,   0.0f,  0.0f,
            0.0f,  0.0f,  0.0f,   0.0f,  0.0f,   0.0f,   0.0f,  0.0f, 0.0f,   0.0f,
        },
    },
    {
        0x1F,
        0x18,
        'mp07',
        "MULT 7",
        'MLT7',
        0,
        0,
        0,
        0xFF,
        -1,
        {
            -210.0f, 17.5f,   15.0f, 5.0f,  -210.0f, 12.5f, 15.0f, 5.0f, -210.0f, 7.5f, 15.0f,
            5.0f,    -210.0f, 2.5f,  15.0f, 5.0f,    0.0f,  0.0f,  0.0f, 0.0f,    0.0f, 0.0f,
            0.0f,    0.0f,    0.0f,  0.0f,  0.0f,    0.0f,  0.0f,  0.0f, 0.0f,    0.0f,
        },
    },
    {
        0x20,
        3,
        'mp08',
        "MULT 8",
        'MLT8',
        1,
        0,
        0,
        0xFF,
        -1,
        {
            239.6f, -7.77f, 4.86f,   1.67f, 239.6f, -12.77f, 4.86f, 1.67f, 239.6f, -2.77f, 4.86f,
            1.67f,  239.6f, -17.77f, 4.86f, 1.67f,  0.0f,    0.0f,  0.0f,  0.0f,   0.0f,   0.0f,
            0.0f,   0.0f,   0.0f,    0.0f,  0.0f,   0.0f,    0.0f,  0.0f,  0.0f,   0.0f,
        },
    },
    {
        0x21,
        2,
        'mp09',
        "MULT 9",
        'MLT9',
        5,
        0,
        0,
        0xFF,
        -1,
        {
            -67.37f, 64.46f, 10.09f,  -2.48f, 67.05f, 64.46f, 10.09f, 2.48f, -67.14f, -64.72f, 10.75f,
            -0.85f,  66.81f, -64.72f, 10.75f, 0.85f,  0.0f,   0.0f,   0.0f,  0.0f,    0.0f,    0.0f,
            0.0f,    0.0f,   0.0f,    0.0f,   0.0f,   0.0f,   0.0f,   0.0f,  0.0f,    0.0f,
        },
    },
    {
        0x19,
        3,
        0,
        "MULT 10",
        'MLT4', // MLT4?
        6,
        0,
        0,
        0xFF,
        -1,
        {
            80.0f, 0.0f, 0.0f,   1.57f, -80.0f, 0.0f, 0.0f, -1.57f, 0.0f, 80.0f, 0.0f,
            3.14f, 0.0f, -80.0f, 0.0f,  0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,  0.0f,
            0.0f,  0.0f, 0.0f,   0.0f,  0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        },
    },
    {
        0x26,
        0xE,
        'tk01',
        "INTRO1",
        'ENGL',
        -1,
        1,
        1,
        3,
        -1,
        {
            0.0f, 1540.0f, 55.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f,    0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f,    0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        0x27,
        0xF,
        'tk02',
        "INTRO2",
        'WKWD',
        -1,
        0,
        1,
        0xFF,
        -1,
        {
            27.71f, 765.87f, 82.0f, 1.679f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,    0.0f,  0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,    0.0f,  0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        4,
        0x10,
        'tk03',
        "INTRO3",
        'ALPS',
        -1,
        0,
        1,
        0,
        -1,
        {
            0.0f, 2525.0f, 230.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f,    0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f,    0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        5,
        0x11,
        'tk04',
        "INTRO4",
        'DSRT',
        -1,
        1,
        1,
        2,
        -1,
        {
            -10.7f, 2446.25f, 93.0f, 0.052f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,     0.0f,  0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,     0.0f,  0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        6,
        0x12,
        'tk05',
        "INTRO5",
        'JUNG',
        -1,
        1,
        1,
        4,
        -1,
        {
            62.14f, 1886.93f, 50.0f, -0.335f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,     0.0f,  0.0f,    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,     0.0f,  0.0f,    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        7,
        0x13,
        'tk06',
        "INTRO6",
        'TRK6',
        -1,
        0,
        1,
        1,
        -1,
        {
            -1.72f, 3561.33f, 17.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,     0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f,   0.0f,     0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
    {
        0x25,
        0x17,
        0,
        "FINISH",
        'FINI',
        -1,
        0,
        0,
        0xFF,
        -1,
        {
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        },
    },
};

s32 D_scene_00402CF8[] = { TRACK_COVENTRY_COVE, TRACK_MOUNT_MAYHEM,  TRACK_INFERNO_ISLE,
                           TRACK_SUNSET_SANDS,  TRACK_METRO_MADNESS, TRACK_WICKED_WOODS };

s32 D_scene_00402D10[] = { 17, 24, 19, 18, 23, 20, 21, 22, 25 };

s32 D_scene_00402D34[] = { 11, 61, 50 };

s32 D_scene_00402D40[][4] = { { 1, 1, 0, 0 }, { 1, 1, 1, 1 }, { 1, 1, 0, 0 },
                              { 1, 1, 1, 1 }, { 1, 1, 0, 0 }, { 1, 0, 0, 0 } };

s32 D_scene_00402DA0[] = { 0, 1, 5, 6, 7, 9 };

s32 D_scene_00402DB8[] = { 0, 1, 2, 3, 4, 6, 7, 9 };

// .bss
s32 B_scene_00402DF0[2]; // unreferenced padding
Scene sCurrentScene;
GenericExports *D_scene_00402EF0;

void func_scene_004013F4(UnkStruct_scene_004013F4 *, UnkStruct_scene_004013F4 *); /* extern */
extern UnkLightExports *gLightExports;

s32 func_scene_00400000(s32 arg0) {
    if (arg0 >= 6) {
        arg0 = 5;
    } else if (arg0 < 0) {
        arg0 = 0;
    }
    return D_scene_00402CF8[arg0];
}

s32 func_scene_00400030(s32 arg0) {
    if (arg0 >= 9) {
        arg0 = 8;
    } else if (arg0 < 0) {
        arg0 = 0;
    }
    return D_scene_00402D10[arg0];
}

s32 func_scene_00400060(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (arg0 == D_scene_00402CF8[i]) {
            return i;
        }
    }
    return 0;
}

s32 func_scene_004000FC(s32 arg0) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (arg0 == D_scene_00402D10[i]) {
            return i;
        }
    }
    return 0;
}

void func_scene_00400188(s32 arg0) {
    s32 temp_v0_2;
    s32 i;
    s32 *sp3C;
    DobjSettings *settings;

    settings = uvGetSystemProp(SYSTEM_PROPID_DOBJ_SETTINGS);
    if (sCurrentScene.terrain == -1) {
        return;
    }

    for (i = 0; i < settings->dobjsCount; i++) {
        temp_v0_2 = gUvDobjExports->uvDobjGetModel(i);
        // FAKE
        if (1) {
        }

        if (temp_v0_2 == arg0) {
            gUvDobjExports->func_uvdobj_rom_004011CC(i);
        }
    }

    temp_v0_2 = gUvTerraExports->uvSobjGetIds(sCurrentScene.terrain, arg0, &sp3C);
    for (i = 0; i < temp_v0_2; i++) {
        gUvTerraExports->uvSobjProps(sp3C[i], 1, -1, 0);
    }
}

void func_scene_004002A8(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_scene_00400188(D_scene_00402D34[i]);
    }
}

void func_scene_004002F0(void) {
    s32 modelsCount;
    s32 i;
    ParsedUVMD *uvmd;

    modelsCount = uvGetFilesCount('UVMD');
    for (i = 0; i < modelsCount; i++) {
        uvmd = uvGetLoadedFile('UVMD', i);
        if ((uvmd != NULL) && (uvmd->unk5 & 0x70)) {
            func_scene_00400188(i);
        }
    }
}

void func_scene_00400374(void) {
    s32 modelsCount;
    s32 i;
    ParsedUVMD *uvmd;

    modelsCount = uvGetFilesCount('UVMD');
    for (i = 0; i < modelsCount; i++) {
        uvmd = uvGetLoadedFile('UVMD', i);
        if ((uvmd != NULL) && (uvmd->unk20 != 0)) {
            func_scene_00400188(i);
        }
    }
}

void func_scene_004003F4(s32 track) {
    s32 var_v0;
    s32 var_v0_2;
    s32 terrain;
    s32 *temp_t4;
    s32 i;
    SceneTrackInfo *sceneTrack;
    char pad[0x4];

    sceneTrack = &SceneTracks[track];
    temp_t4 = sceneTrack->unk1C;
    sCurrentScene.unk0 = sceneTrack->trackId;
    sCurrentScene.unk4 = sceneTrack->trackTag;
    sCurrentScene.terrain = sceneTrack->unk0;
    sCurrentScene.environment = sceneTrack->trackModel;
    sCurrentScene.unkC = sceneTrack->unk18;
    sCurrentScene.unk24 = temp_t4;

    sCurrentScene.unk12 = sceneTrack->unk13;

    gGameSettings->unkF0 = sceneTrack->trackName;
    if ((track >= TRACK_COVENTRY_COVE) && (track < TRACK_STUNT_O_RAMA)) {
        if (gGameSettings->numAiCars >= 3) {
            var_v0 = 2;
        } else if (gGameSettings->numAiCars == 1) {
            var_v0 = 1;
        } else {
            if (gGameSettings->numPlayers == 2) {
                var_v0 = 3;
            } else {
                var_v0 = 0;
            }
        }
        if (gGameSettings->currentGameState == GAME_STATE_DEMO) {
            D_8002D1A8 = 0;
        } else {
            D_8002D1A8 = D_scene_00402D40[track - TRACK_COVENTRY_COVE][var_v0];
        }
    }
    if (sceneTrack->unk14 != 0xFF) {
        uvLoadFile('UVDS', sceneTrack->unk14);
    }
    if (sCurrentScene.environment != -1) {
        uvLoadFile('UVEN', sCurrentScene.environment);
    }
    if (sCurrentScene.terrain != -1) {
        uvLoadFile('UVTR', sCurrentScene.terrain);
    }
    if (sCurrentScene.terrain == 0x22) {
        gGameSettings->dbgTrackWeather = TRACK_WEATHER_RAIN;
    } else {
        gGameSettings->dbgTrackWeather = TRACK_WEATHER_CLEAR;
    }
    if (gGameSettings->dbgTrackWeather == TRACK_WEATHER_RAIN) {
        gRainExports = uvLoadModule('rain');
    } else {
        gRainExports = NULL;
    }
    if (sceneTrack->enableGlare) {
        gGlareExports = uvLoadModule('glar');
        if (sCurrentScene.terrain == 0x14) {
            gGlareExports->unk8(3, sCurrentScene.terrain, -4721.0f, -1116.0f, 505.5f, 0);
        } else if (sCurrentScene.terrain == 0x16) {
            gGlareExports->unk8(3, sCurrentScene.terrain, -1200.0f, 1645.0f, 850.0f, 0);
        } else if (sCurrentScene.terrain == 0x13) {
            gGlareExports->unk8(3, sCurrentScene.terrain, 1700.0f, -3000.0f, 2000.0f, 0);
        }
    } else {
        gGlareExports = NULL;
    }
    func_scene_00400CB8();
    sCurrentScene.unk13 = 0;
    if (sCurrentScene.unk0 != 0) {
        D_scene_00402EF0 = uvLoadModule(sCurrentScene.unk0);
    } else {
        D_scene_00402EF0 = NULL;
    }
    gUvIsectExports->unk64(0x275);
    if (((gGameSettings->numAiCars <= 0) && (gGameSettings->currentGameState == GAME_STATE_RACE)
         && (gGameSettings->unk6FA4 == 0))
        || (gGameSettings->currentGameState == GAME_STATE_INTRO)) {
        func_scene_004002A8();
        if ((u32) temp_t4 == (u32) SceneTracks[8].unk1C) {
            terrain = sCurrentScene.terrain;
            sCurrentScene.terrain = 0x15;
            uvLoadFile('UVTR', 0x15);
            func_scene_004002A8();
            sCurrentScene.terrain = terrain;
        }
    }
    if ((gGameSettings->currentGameState == GAME_STATE_RACE) && (gGameSettings->unk6F74 != 2)) {
        // clang-format off
        switch (gGameSettings->unk6FA5) {
            case 1: func_scene_00400374(); break;
            case 2: *gUvTerraExports->D_uvterra_rom_0040FBE0 = 1; break;
        }
        // clang-format on
        if (gGameSettings->numPlayers == 2) {
            func_scene_00400374();
            func_scene_004002F0();
        }
    }
    if (sCurrentScene.environment != -1) {
        gUvEnvExports->uvEnvGetProps(sCurrentScene.environment, 7, &sCurrentScene.farPlane, 1,
                                     &sCurrentScene.fogRed, &sCurrentScene.fogGreen,
                                     &sCurrentScene.fogBlue, 2, &sCurrentScene.fogStart,
                                     &sCurrentScene.fogMax, 0);
        if ((sCurrentScene.fogStart == 0.0f) || (sCurrentScene.fogStart == 1.0f)) {
            gUvEnvExports->uvEnvGetProps(sCurrentScene.environment, 3, &sCurrentScene.fogStart,
                                         &sCurrentScene.fogMax, 0);
            if ((sCurrentScene.fogStart == 0.0f) || (sCurrentScene.fogStart == 1.0f)) {
                sCurrentScene.fogType = FOG_TYPE_NONE;
            } else {
                sCurrentScene.fogType = FOG_TYPE_SOFTWARE;
            }
        } else {
            sCurrentScene.fogType = FOG_TYPE_HARDWARE;
        }
        sCurrentScene.unkF4 = 0.0f;
    } else {
        sCurrentScene.fogType = FOG_TYPE_NONE;
        sCurrentScene.fogRed = 1.0f;
        sCurrentScene.fogGreen = 1.0f;
        sCurrentScene.fogBlue = 1.0f;
        sCurrentScene.fogStart = 0.0f;
        sCurrentScene.fogMax = 0.0f;
        sCurrentScene.unkF4 = 0.0f;
        sCurrentScene.farPlane = 300.0f;
    }
    if (sceneTrack->musicId == -1) {
        return;
    }

    gSndExports->sndSetMusicVol(gGameSettings->optionsMusicVol);
    gUvCmidiExports->uvaSeqStop();
    if (gGameSettings->currentGameState == GAME_STATE_CREDITS) {
        sceneTrack->musicId = -1;
    } else if ((D_8002CB8C != 4) && (D_8002CB8C != 5) && (D_8002CB8C != 6) && (D_8002CB8C != 7)
               && (D_8002CB8C != 8)) {
        if (gGameSettings->currentGameState == GAME_STATE_BATTLE) {
            for (i = 0; i < 6; i++) {
                if (sceneTrack->musicId == D_scene_00402DA0[i]) {
                    var_v0_2 = (s32) (gUvMathExports->func_uvmath_rom_004008E4() * 6.0f);
                    if (var_v0_2 < 0) {
                        var_v0_2 = 0;
                    } else if (var_v0_2 >= 6) {
                        var_v0_2 = 5;
                    }
                    sceneTrack->musicId = D_scene_00402DA0[var_v0_2];
                }
            }
        }
        if (gCheatTrackMusic != 0) {
            if (D_8002CC64 != 2) {
                for (i = 0; i < 8; i++) {
                    if (sceneTrack->musicId == D_scene_00402DB8[i]) {
                        var_v0_2 = (gUvMathExports->func_uvmath_rom_004008E4() * 8.0f);
                        if (var_v0_2 < 0) {
                            var_v0_2 = 0;
                        } else if (var_v0_2 >= 8) {
                            var_v0_2 = 7;
                        }
                        sceneTrack->musicId = D_scene_00402DB8[var_v0_2];
                    }
                }
            }
        }
        gSndExports->sndSetMusic(sceneTrack->musicId);
    } else {
        gSndExports->sndSetMusic(8);
    }
    if (sceneTrack->musicId != -1) {
        gSndExports->sndSetMusicState(0);
    }
}

void func_scene_00400C58(void) {
}

void func_scene_00400C60(void) {
    if (D_scene_00402EF0 != NULL) {
        D_scene_00402EF0->unk4();
    }
    if (sCurrentScene.fogType == FOG_TYPE_NONE) {
        sCurrentScene.fogStart = 0.0f;
        sCurrentScene.fogMax = 0.0f;
    }
}

void func_scene_00400CB8(void) {
    f32 sp74[3];
    f32 sp68[3];
    Vec3F sp5C;
    s32 i;

    sp5C.x = 0.0f;
    sp5C.y = 0.0f;
    sp5C.z = 1.0f;

    sp74[0] = sp74[1] = sp74[2] = 0.3f;
    sp68[0] = sp68[1] = sp68[2] = 0.0f;

    if (sCurrentScene.environment != -1) {
        gUvEnvExports->uvEnvGetProps(sCurrentScene.environment, 6, &sp5C.x, &sp5C.y, &sp5C.z, 8,
                                     &sp74[0], &sp74[1], &sp74[2], 9, &sp68[0], &sp68[1], &sp68[2], 0);
    }
    gUvLightExports->func_uvlight_rom_00400FB8(&sp5C, sp68, sp74);
    gLightExports->unk4(sCurrentScene.unk28, 0);
    for (i = 0; i < 3; i++) {
        gLightExports->unk4(&sCurrentScene.unk28[i + 1], 1);
    }
}

void __entrypoint_func_scene_400e0c(Scene_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_scene_00400EC0 = func_scene_00400EC0;
    exports->func_scene_00401438 = func_scene_00401438;
    exports->func_scene_00400000 = func_scene_00400000;
    exports->func_scene_00400030 = func_scene_00400030;
    exports->func_scene_00400060 = func_scene_00400060;
    exports->func_scene_004000FC = func_scene_004000FC;
    exports->func_scene_004003F4 = func_scene_004003F4;
    exports->func_scene_00400C58 = func_scene_00400C58;
    exports->func_scene_00400C60 = func_scene_00400C60;
    exports->func_scene_00400EC8 = func_scene_00400EC8;
    exports->func_scene_004013F4 = func_scene_004013F4;
    exports->sCurrentScene = &sCurrentScene;
}

void func_scene_00400EC0(void) {
}

void func_scene_00400EC8(GuiMenu *menu) {
    GuiMenuOption *menuOption;
    GuiSlider *slider;

    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, "scene");
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    gMiscExports->func_misc_004038D8(menuOption, "track", 2, 0.0f, 33.0f, &gGameSettings->currentTrack, &slider);
    gUvGuiExports->uvGuiSliderSetCallback(slider, func_scene_004012B8);
    func_scene_004012B8(slider);
    gMiscExports->func_misc_004038D8(menuOption, "weather", 2, 0.0f, 3.0f, &gTrackWeather, &slider);
    gUvGuiExports->uvGuiSliderSetCallback(slider, func_scene_004012B8);
    gUvGuiExports->uvGuiSliderSetCallback(slider, func_scene_00401324);
    func_scene_00401324(slider);
    gMiscExports->func_misc_00403BEC(menuOption, "edit env", (void (*)(void *)) func_scene_00401254);
    gMiscExports->func_misc_00403BEC(menuOption, "print env", (void (*)(void *)) func_scene_004012B0);
    {
        static const char *sFogTypeValues[3] = { "NONE", "HARDWARE", "SOFTWARE" };
        gMiscExports->func_misc_004038D8(menuOption, "fogtype", 0x12, 0.0f, 2.0f,
                                         &sCurrentScene.fogType, &slider);
        gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) sFogTypeValues);
        gMiscExports->func_misc_004038D8(menuOption, "fogstart", 0x11, 0.0f, 1.0f,
                                         &sCurrentScene.fogStart, &slider);
        gMiscExports->func_misc_004038D8(menuOption, "fogmax", 0x11, 0.0f, 1.0f, &sCurrentScene.fogMax,
                                         &slider);
        gMiscExports->func_misc_004038D8(menuOption, "farplane", 0x11, 10.0f, 3000.0f,
                                         &sCurrentScene.farPlane, &slider);
        gMiscExports->func_misc_004038D8(menuOption, "fog red", 0x11, 0, 1.0f, &sCurrentScene.fogRed,
                                         &slider);
        gMiscExports->func_misc_004038D8(menuOption, "fog green", 0x11, 0, 1.0f,
                                         &sCurrentScene.fogGreen, &slider);
        gMiscExports->func_misc_004038D8(menuOption, "fog blue", 0x11, 0, 1.0f, &sCurrentScene.fogBlue,
                                         &slider);
    }
}

void func_scene_00401254(s32 arg0) {
    s32 i;
    UnkScrnExports_unk18_unk0 *temp_a0;

    for (i = 0; i < gScrnExports->unk18->unk10; i++) {
        temp_a0 = gScrnExports->unk18->unk0[i];
        temp_a0->unk21C = 1;
    }
}

void func_scene_004012B0(s32 arg0) {
}

void func_scene_004012B8(GuiSlider *slider) {
    SceneTrackInfo *sceneTrack;

    gGameSettings->currentTrack = slider->unk24;
    sceneTrack = &SceneTracks[gGameSettings->currentTrack];
    gUvGuiExports->uvGuiSliderSetLabel(slider, sceneTrack->trackName);
}

void func_scene_00401324(GuiSlider *slider) {
    char label[16];

    gGameSettings->dbgTrackWeather = slider->unk24;
    switch (gGameSettings->dbgTrackWeather) { /* irregular */
        case TRACK_WEATHER_CLEAR:
            sprintf(label, "CLEAR");
            break;
        case TRACK_WEATHER_SNOW:
            sprintf(label, "SNOW");
            break;
        case TRACK_WEATHER_RAIN:
            sprintf(label, "RAIN");
            break;
        case TRACK_WEATHER_NONE:
            sprintf(label, "NOT SUPPORTED");
            break;
    }
    gUvGuiExports->uvGuiSliderSetLabel(slider, label);
}

void func_scene_004013F4(UnkStruct_scene_004013F4 *arg0, UnkStruct_scene_004013F4 *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    arg0->unk8 = arg1->unk8;
    arg0->unkC = arg1->unkC;
    arg0->unk10 = arg1->unk10;
    arg0->unk14 = arg1->unk14;
    arg0->unk18 = arg1->unk18;
    arg0->unk1C = arg1->unk1C;
}

void func_scene_00401438(UnkStruct_scene_004013F4 *arg0, UnkStruct_scene_004013F4 *arg1,
                         UnkStruct_scene_004013F4 *arg2, f32 arg3) {
    f32 temp_fv0;

    if (arg3 <= 0.0f) {
        func_scene_004013F4(arg0, arg1);
        return;
    }
    if (arg3 >= 1.0f) {
        func_scene_004013F4(arg0, arg2);
        return;
    }
    temp_fv0 = 1.0f - arg3;
    arg0->unk4 = (arg1->unk4 * temp_fv0) + (arg2->unk4 * arg3);
    arg0->unk8 = (arg1->unk8 * temp_fv0) + (arg2->unk8 * arg3);
    arg0->unkC = (arg1->unkC * temp_fv0) + (arg2->unkC * arg3);
    arg0->unk10 = (arg1->unk10 * temp_fv0) + (arg2->unk10 * arg3);
    arg0->unk14 = (arg1->unk14 * temp_fv0) + (arg2->unk14 * arg3);
    arg0->unk18 = (arg1->unk18 * temp_fv0) + (arg2->unk18 * arg3);
    arg0->unk1C = (arg1->unk1C * temp_fv0) + (arg2->unk1C * arg3);
    if ((arg0->unk10 == 0.0f) || (arg0->unk10 == 1.0f)) {
        arg0->unk0 = 0;
        return;
    }

    if (arg1->unk0 != 0 && arg2->unk0 != 0) {
        if (arg3 > 0.5f) {
            arg0->unk0 = arg2->unk0;
            return;
        }
        arg0->unk0 = arg1->unk0;
    } else if (arg1->unk0 == 0) {
        arg0->unk0 = arg2->unk0;
    } else {
        arg0->unk0 = arg1->unk0;
    }
}

s32 D_scene_00402DE4[] = { 0x00300000, __entrypoint_func_scene_400e0c, 0 };
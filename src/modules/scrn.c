// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct VtxRect_s {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
} VtxRect;

typedef struct UnkStruct_scrn_004004C0_s {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ VtxRect unk6[4];
    /* 0x26 */ VtxRect unk26[4];
} UnkStruct_scrn_004004C0; /* size = 0x46 */

typedef struct UnkCamExports_s {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ void (*unkC)(s32);  /* inferred */
    /* 0x10 */ char pad10[8];      /* maybe part of unkC[3]? */
    /* 0x18 */ void (*unk18)(s32); /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ void (*unk20)(s32, ...);
} UnkCamExports; /* size = 0x24 */

void func_scrn_00400094(void);
void func_scrn_0040009C(s32 arg0, s32 *arg1);
void func_scrn_004001DC(void);
void func_scrn_004001E8(UnkStruct_scrn_004004C0 *arg0);
void func_scrn_0040027C(void);
void func_scrn_00400398(void);
s16 func_scrn_00400474(s32 *arg0);
void __entrypoint_func_scrn_400000(Scrn_Exports *exports);

// .data
UnkStruct_scrn_004004C0 D_scrn_004004C0[7] = {
    {
        0,
        4,
        0,
        { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
        {
            { 0, 0x13F, 0, 0xF },
            { 0, 0x13F, 0xDE, 0xEF },
            { 0, 0x15, 0x10, 0xDE },
            { 0x128, 0x13F, 0x10, 0xDE },
        },
    },
    {
        1,
        0,
        1,
        { { 0x16, 0x129, 0x10, 0xDF }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
        { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    },
    {
        2,
        1,
        1,
        {
            { 0x16, 0x129, 0x77, 0xDF },
            { 0x16, 0x129, 0x10, 0x78 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        { { 0x16, 0x129, 0x77, 0x78 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    },
    {
        3,
        3,
        1,
        {
            { 0x16, 0xA0, 0x77, 0xDF },
            { 0x9F, 0x129, 0x77, 0xDF },
            { 0x16, 0xA0, 0x10, 0x78 },
            { 0, 0, 0, 0 },
        },
        {
            { 0x16, 0x129, 0x77, 0x78 },
            { 0x9F, 0xA0, 0x10, 0xDF },
            { 0x9F, 0x129, 0x10, 0x77 },
            { 0, 0, 0, 0 },
        },
    },
    {
        4,
        2,
        1,
        {
            { 0x16, 0xA0, 0x77, 0xDF },
            { 0x9F, 0x129, 0x77, 0xDF },
            { 0x16, 0xA0, 0x10, 0x78 },
            { 0x9F, 0x129, 0x10, 0x78 },
        },
        {
            { 0x16, 0x129, 0x77, 0x78 },
            { 0x9F, 0xA0, 0x10, 0xDF },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
    {
        1,
        1,
        0,
        { { 0x16, 0x129, 0x77, 0xDF }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
        { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    },
    {
        1,
        4,
        1,
        { { 0x16, 0x129, 0x2E, 0xC1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
        {
            { 0, 0x13F, 0, 0x2D },
            { 0, 0x13F, 0xC0, 0xEF },
            { 0, 0x15, 0, 0xEF },
            { 0x128, 0x13F, 0, 0xEF },
        },
    },
};

s32 D_scrn_004006AC[] = {0x00200000, __entrypoint_func_scrn_400000, 0};

// .bss
s32 B_scrn_004006C0[2]; // unreferenced padding
UnkStruct_scrn_004006C8 D_scrn_004006C8;
s32 D_scrn_004006E8;

// external variables
extern UnkCamExports *gCamExports;

void __entrypoint_func_scrn_400000(Scrn_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_scrn_00400474 = func_scrn_00400474;
    exports->func_scrn_00400094 = func_scrn_00400094;
    exports->func_scrn_0040009C = func_scrn_0040009C;
    exports->func_scrn_004001DC = func_scrn_004001DC;
    exports->func_scrn_0040027C = func_scrn_0040027C;
    exports->func_scrn_00400398 = func_scrn_00400398;
    exports->D_scrn_004006C8 = &D_scrn_004006C8;
    exports->D_scrn_004006E8 = &D_scrn_004006E8;
    D_scrn_004006C8.unk12 = 0;
    D_scrn_004006C8.unk14 = 0.0f;
    D_scrn_004006C8.unk18 = 0.0f;
    D_scrn_004006C8.unk1C = 0.0f;
}

void func_scrn_00400094(void) {
}

void func_scrn_0040009C(s32 arg0, s32 *arg1) {
    UnkStruct_scrn_004004C0 *temp_s1;
    s32 i;
    s32 var_v1;

    D_scrn_004006C8.unk12 = arg0;
    temp_s1 = &D_scrn_004004C0[D_scrn_004006C8.unk12];
    D_scrn_004006C8.unk10 = 0;

    for (i = 0; i < temp_s1->unk0; i++) {
        arg0 = arg1[i];
        D_scrn_004006C8.unk0[i] = arg0;
        if (arg0 == 0) {
            break;
        }

        if (temp_s1->unk0 >= 2) {
            var_v1 = TRUE;
        } else {
            var_v1 = FALSE;
        }
        gCamExports->unk20(arg0, 2, temp_s1->unk6[i].x0, 3, temp_s1->unk6[i].y0, 5, temp_s1->unk6[i].x1,
                           4, temp_s1->unk6[i].y1, 1, var_v1, 0);
        D_scrn_004006C8.unk10++;
    }
}

void func_scrn_004001DC(void) {
    D_scrn_004006C8.unk12 = 0;
}

void func_scrn_004001E8(UnkStruct_scrn_004004C0 *arg0) {
    s32 i;

    if (D_scrn_004006E8 != 0) {
        return;
    }

    for (i = 0; i < arg0->unk2; i++) {
        gUvGeomExports->uvVtxRect(arg0->unk26[i].x0, arg0->unk26[i].x1, arg0->unk26[i].y0,
                                  arg0->unk26[i].y1);
    }
}

void func_scrn_0040027C(void) {
    s32 i;
    s32 *temp = D_scrn_004006C8.unk0;

    for (i = 0; i < D_scrn_004006C8.unk10; i++) {
        gCamExports->unkC(temp[i]);
        if (gGameSettings->dbgOptsDrawingOff != 0) {
            gUvGeomExports->uvSetFillColor(1.0f, 1.0f, 1.0f, 1.0f);
            gUvGeomExports->uvVtxRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        } else {
            gCamExports->unk18(temp[i]);
        }
    }
}

void func_scrn_00400398(void) {
    UnkStruct_scrn_004004C0 *sp24;

    sp24 = &D_scrn_004004C0[D_scrn_004006C8.unk12];
    gUvGeomExports->uvSetFillColor(D_scrn_004006C8.unk14, D_scrn_004006C8.unk18, D_scrn_004006C8.unk1C,
                                   1.0f);
    gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, gUvGfxMgrExports->uvGetScreenWidth(), 0,
                                                 gUvGfxMgrExports->uvGetScreenHeight());
    if (sp24->unk4 != 0) {
        func_scrn_004001E8(D_scrn_004004C0);
    }
    func_scrn_004001E8(sp24);
}

s16 func_scrn_00400474(s32 *arg0) {
    s32 i;

    for (i = 0; i < D_scrn_004006C8.unk10; i++) {
        arg0[i] = D_scrn_004006C8.unk0[i];
    }
    return D_scrn_004006C8.unk10;
}

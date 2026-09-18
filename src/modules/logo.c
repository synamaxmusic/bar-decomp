// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct Logo_Exports_s {
    void (*func_logo_00400174)(void);
    void (*func_logo_0040017C)(void);
    void (*unusedLogoRender)(void);
} Logo_Exports;

//extern UnkGameGuiExports* gGameGuiExports;
//extern UnkScrnExports* gScrnExports;

void __entrypoint_func_logo_400000(Logo_Exports* arg0) ;
void func_logo_00400174(void);
void func_logo_0040017C(void);
void unusedLogoRender(void);

s32 D_logo_004002E0[2]; //padding?
s32 D_logo_004002E8[2];
s32 D_logo_004002D0[] = {0x01000000, 0x000C0000, __entrypoint_func_logo_400000, 0};

void __entrypoint_func_logo_400000(Logo_Exports* exports) {
    uvUpdateFileAllocPtr(exports);

    exports->func_logo_00400174 = func_logo_00400174;
    exports->func_logo_0040017C = func_logo_0040017C;
    exports->unusedLogoRender = unusedLogoRender;

    D_logo_004002E8[0] = gUvSprtExports->func_uvsprt_rom_004001EC();
    D_logo_004002E8[1] = 0;

    uvLoadFile('UVBT', 40);

    gUvSprtExports->uvSprtProps(
        D_logo_004002E8[0], 9, 40, 2,
        0, 0, 3, 1,
        7, 0, 0, 0,
        0xFF, 0
    );

    gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(
        0,
        gUvGfxMgrExports->uvGetScreenWidth(),
        0,
        gUvGfxMgrExports->uvGetScreenHeight()
    );

    gGameGuiExports->unk10(0);
    gGameGuiExports->unk1C(gGameGuiExports->unk4);

    gScrnExports->unk4(0, 0);
}

void func_logo_00400174(void) {

}

void func_logo_0040017C(void) {

}

void unusedLogoRender(void) {
    s32 sp28;
    s32 var_a2;

    if (D_logo_004002E8[1] < 0x5A) {
        var_a2 = (s32) ( gUvMathExports->uvSinF((++D_logo_004002E8[1] * 1.5707963f) / 90.0f) * (0,255.0f));
    } else {
        var_a2 = 0xFF;
    }
    gUvGfxStateExports->uvGfxStatePush();
    gUvGfxStateExports->uvGfxStateSetFlags(0x04800000);
    gUvGfxStateExports->func_uvgfxstate_rom_00401354(0x600000);
    gUvSprtExports->uvSprtProps(D_logo_004002E8[0], 7, var_a2, var_a2, var_a2, 0xFF, 0);
    gUvSprtExports->uvSpriteRender(D_logo_004002E8[0]);
    gUvGfxStateExports->uvGfxStatePop();
}

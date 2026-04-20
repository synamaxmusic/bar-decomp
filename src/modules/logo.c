// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct LogoModule_Exports_s {
    void* func_logo_00400174;
    void* func_logo_0040017C;
    void* func_logo_00400184;
} LogoModule_Exports;

void __entrypoint_func_logo_400000(LogoModule_Exports* arg0) ;
//void uvSetFileDirOvlPtr(void*);
extern void func_logo_00400174(void);
extern void func_logo_0040017C(void);
extern void func_logo_00400184(void);

extern s32 D_logo_004002E0[2]; //padding?
extern s32 D_logo_004002E8[2];
extern s32 D_logo_004002D0[];

void __entrypoint_func_logo_400000(LogoModule_Exports* exports) {
    uvSetFileDirOvlPtr(exports);

    exports->func_logo_00400174 = func_logo_00400174;
    exports->func_logo_0040017C = func_logo_0040017C;
    exports->func_logo_00400184 = func_logo_00400184;

    D_logo_004002E8[0] = gUvSprtExports->unk4();
    D_logo_004002E8[1] = 0;

    func_800019B8('UVBT', 0x28);

    gUvSprtExports->unk1C(
        D_logo_004002E8[0], 9, 0x28, 2,
        0, 0, 3, 1,
        7, 0, 0, 0,
        0xFF, 0
    );

    gUvGfxMgrExports->unk58(
        0,
        gUvGfxMgrExports->unk88(),
        0,
        gUvGfxMgrExports->unk84()
    );

    gGameGuiExports->unk10(0);
    gGameGuiExports->unk1C(gGameGuiExports->unk4);

    gScrnExports->unk4(0, 0);
}

void func_logo_00400174(void) {

}

void func_logo_0040017C(void) {

}

void func_logo_00400184(void) {
    s32 sp28;
    s32 var_a2;

    if (D_logo_004002E8[1] < 0x5A) {
        var_a2 = (s32) ( gUvMathExports->unk8((++D_logo_004002E8[1] * 1.5707963f) / 90.0f) * (0,255.0f));
    } else {
        var_a2 = 0xFF;
    }
    gUvGfxStateExports->unk50();
    gUvGfxStateExports->unkC(0x04800000);
    gUvGfxStateExports->unk10(0x600000);
    gUvSprtExports->unk1C(D_logo_004002E8[0], 7, var_a2, var_a2, var_a2, 0xFF, 0);
    gUvSprtExports->unk10(D_logo_004002E8[0]);
    gUvGfxStateExports->unk54();
}

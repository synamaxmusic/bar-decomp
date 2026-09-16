// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

extern f32 D_cbars_00400510;
extern f32 D_cbars_00400530;
extern f32 D_cbars_00400534;
extern f32 D_cbars_00400538;
extern f32 D_cbars_00400558;
extern f32 D_cbars_0040055C;
extern f32 D_cbars_00400560;

void func_cbars_004000E4(void);
void func_cbars_004000EC(void);
void func_cbars_004000F4(void);

void __entrypoint_func_cbars_400000(Cbars_Exports* exports) {
    s32 i; // unused??
    s32 sp18;

    uvUpdateFileAllocPtr(exports);
    exports->func_cbars_004000E4 = &func_cbars_004000E4;
    exports->func_cbars_004000EC = &func_cbars_004000EC;
    exports->func_cbars_004000F4 = &func_cbars_004000F4;
    sp18 = gUvGfxMgrExports->uvGetScreenHeight(exports);
    gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, sp18, 0, gUvGfxMgrExports->uvGetScreenHeight());
    gGameGuiExports->unk10(0);
    gGameGuiExports->unk1C(gGameGuiExports->unk4);
    gScrnExports->unk4(0, 0);
}

void func_cbars_004000E4(void) {
}

void func_cbars_004000EC(void) {
}

void func_cbars_004000F4(void) {
    func_cbars_00400114();
}

void func_cbars_00400114(void) {
    f32 temp_fa0;
    f32 var_fs2;
    f32 var_fs3;
    f32 var_fs4;
    f32 var_fs5;
    f32 temp_s2;
    f32 temp_s4;
    f32 temp_s3;
    s32 i;
    temp_fa0 = 67;
    gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0x16, 0x129, 0x10, 0xDF);
    var_fs5 = 22.0f;
    temp_s2 = 223.0f;
    temp_s4 = 1.11f;
    for (i = 0; i < 7; i++) {
        switch (i) {
            case 0:
                var_fs2 = 1.0f;
                var_fs3 = 1.0f;
                var_fs4 = 1.0f;
                break;

            case 1:
                var_fs2 = 1.0f;
                var_fs3 = 1.0f;
                var_fs4 = 0.0f;
                break;

            case 2:
                var_fs2 = 0.0f;
                var_fs3 = 1.0f;
                var_fs4 = 1.0f;
                break;

            case 3:
                var_fs2 = 0.0f;
                var_fs3 = 1.0f;
                var_fs4 = 0.0f;
                break;

            case 4:
                var_fs2 = 1.0f;
                var_fs3 = 0.0f;
                var_fs4 = 1.0f;
                break;

            case 5:
                var_fs2 = 1.0f;
                var_fs3 = 0.0f;
                var_fs4 = 0.0f;
                break;

            case 6:
                var_fs2 = 0.0f;
                var_fs3 = 0.0f;
                var_fs4 = 1.0f;
                break;
        }

        gUvGeomExports->uvSetFillColor(var_fs2, var_fs3, var_fs4, 1.0f);
        gUvGeomExports->uvVtxRect(var_fs5, (s16) temp_s4, ((s16) var_fs5) + 1.33f, (s16) temp_s2);
        var_fs5 += 1.22f;
    }

    
    var_fs5 = 22.0f;
    temp_s4 = D_cbars_00400538;
    temp_s2 = 67.0f;
    for (i = 0; i < 7; i++) {
        switch (i) {
            case 0:
                var_fs2 = 0.0f;
                var_fs3 = 0.0f;
                var_fs4 = 1.0f;
                break;

            case 1:
                var_fs2 = 0.0f;
                var_fs3 = 0.0f;
                var_fs4 = 0.0f;
                break;

            case 2:
                var_fs2 = 1.0f;
                var_fs3 = 0.0f;
                var_fs4 = 1.0f;
                break;

            case 3:
                var_fs2 = 0.0f;
                var_fs3 = 0.0f;
                var_fs4 = 0.0f;
                break;

            case 4:
                var_fs2 = 0.0f;
                var_fs3 = 1.0f;
                var_fs4 = 1.0f;
                break;

            case 5:
                var_fs2 = 0.0f;
                var_fs3 = 0.0f;
                var_fs4 = 0.0f;
                break;

            case 6:
                var_fs2 = 1.0f;
                var_fs3 = 1.0f;
                var_fs4 = 1.0f;
                break;
        }

        gUvGeomExports->uvSetFillColor(var_fs2, var_fs3, var_fs4, 1.0f);
        gUvGeomExports->uvVtxRect(var_fs5, (s16) temp_s2, ((s16) var_fs5) + 1.55f, (s16) temp_s4);
        var_fs5 += 1.66f;
    }
    
    temp_s2 = 16.0f;
    temp_s4 = temp_fa0;
    var_fs5 = 22.0f;
    
    for (i = 0; i < 0x1C; i++) {
        temp_fa0 = i / 27.0f;
        gUvGeomExports->uvSetFillColor(temp_fa0, temp_fa0, temp_fa0, 1.0f);
        gUvGeomExports->uvVtxRect(var_fs5, (s16) temp_s2, ((s16) var_fs5) + 1.77f, (s16) temp_s4);
        var_fs5 += 1.77f;
    }
}

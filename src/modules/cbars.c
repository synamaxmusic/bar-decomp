// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void __entrypoint_func_cbars_400000(Cbars_Exports* exports);
void func_cbars_004000E4(void);
void func_cbars_004000EC(void);
void func_cbars_004000F4(void);
void func_cbars_00400114(void);

// .bss
s32 B_cbars_00400580[4]; // unreferenced padding

void __entrypoint_func_cbars_400000(Cbars_Exports* exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_cbars_004000E4 = &func_cbars_004000E4;
    exports->func_cbars_004000EC = &func_cbars_004000EC;
    exports->func_cbars_004000F4 = &func_cbars_004000F4;
    gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, gUvGfxMgrExports->uvGetScreenWidth(), 0, gUvGfxMgrExports->uvGetScreenHeight());
    gGameGuiExports->func_gamegui_00401AD8(0);
    gGameGuiExports->func_gamegui_00402030(gGameGuiExports->func_gamegui_004000B0);
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
    s32 i;

    temp_fa0 = 78.100006f;
    gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0x16, 0x129, 0x10, 0xDF);
    var_fs5 = 22.0f;
    temp_s2 = 223.0f;
    temp_s4 = 78.100006f;
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
        gUvGeomExports->uvVtxRect(((s16)var_fs5), (s16) temp_s4, ((s16)var_fs5) + 39.42857f, (s16) temp_s2);
        var_fs5 += 39.42857f;
    }

    var_fs5 = 22.0f;
    temp_s4 = temp_fa0;
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
        gUvGeomExports->uvVtxRect(((s16)var_fs5), (s16) temp_s2, ((s16)var_fs5) + 39.42857f, (s16) temp_s4);
        var_fs5 += 39.42857f;
        temp_fa0 = 67;
    }

    temp_s2 = 16.0f;
    temp_s4 = temp_fa0;
    var_fs5 = 22.0f;
    for (i = 0; i < 0x1C; i++) {
        temp_fa0 = i / 27.0f;
        gUvGeomExports->uvSetFillColor(temp_fa0, temp_fa0, temp_fa0, 1.0f);
        gUvGeomExports->uvVtxRect(((s16)var_fs5), (s16) temp_s2, ((s16)var_fs5) + 9.857142f, (s16) temp_s4);
        var_fs5 += 9.857142f;
    }
}

// .data
s32 D_cbars_00400570[] = {0x000C0000, __entrypoint_func_cbars_400000, 0, 0};

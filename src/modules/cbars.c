// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkStruct_80025C08_V2_s {
    s32 pad0;
    void (*unk4)(void);
    char pad8[0x18];
    void (*unk20)(void);
    char padC[0x2C];
    void (*unk50)(s32, s32, s32);
    char pad54[0x4];
    void (*unk58)(s32, s32, s32, s32);
    char pad5C[0x18];
    void (*unk74)();
    char pad78[0xC];
    s32 (*unk84)(void);
    s32 (*unk88)(s32); // or s32 (*unk88)(Cbars_Exports*);
} UnkStruct_80025C08_V2;

typedef struct UvGeom_Exports_s {
        void (*unk0)(void);
        void (*unk4)(void);
        void (*unk8)(void);
        void (*unkC)(f32, f32, f32, f32);
        void (*unk10)(s16, s32, s32, s32);
} UvGeom_Exports;

extern f32 D_cbars_00400510;
extern f32 D_cbars_00400530;
extern f32 D_cbars_00400534;
extern f32 D_cbars_00400538;
extern f32 D_cbars_00400558;
extern f32 D_cbars_0040055C;
extern f32 D_cbars_00400560;
extern UvGeom_Exports* gUvGeomExports;
extern UvGfxMgr_Exports* gUvGfxMgrExports;

void func_cbars_004000E4(void);
void func_cbars_004000EC(void);
void func_cbars_004000F4(void);

extern UnkScrnExports* gScrnExports;
extern UnkStruct_80025C08_V2* gUvGfxMgrExports;

void __entrypoint_func_cbars_400000(Cbars_Exports* exports) {
    s32 i; // unused??
    s32 sp18;

    uvUpdateFileAllocPtr(exports);
    exports->func_cbars_004000E4 = &func_cbars_004000E4;
    exports->func_cbars_004000EC = &func_cbars_004000EC;
    exports->func_cbars_004000F4 = &func_cbars_004000F4;
    sp18 = gUvGfxMgrExports->unk88(exports);
    gUvGfxMgrExports->unk58(0, sp18, 0, gUvGfxMgrExports->unk84());
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

        gUvGeomExports->unkC(var_fs2, var_fs3, var_fs4, 1.0f);
        gUvGeomExports->unk10(var_fs5, (s16) temp_s4, ((s16) var_fs5) + 1.33f, (s16) temp_s2);
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

        gUvGeomExports->unkC(var_fs2, var_fs3, var_fs4, 1.0f);
        gUvGeomExports->unk10(var_fs5, (s16) temp_s2, ((s16) var_fs5) + 1.55f, (s16) temp_s4);
        var_fs5 += 1.66f;
    }
    
    temp_s2 = 16.0f;
    temp_s4 = temp_fa0;
    var_fs5 = 22.0f;
    
    for (i = 0; i < 0x1C; i++) {
        temp_fa0 = i / 27.0f;
        gUvGeomExports->unkC(temp_fa0, temp_fa0, temp_fa0, 1.0f);
        gUvGeomExports->unk10(var_fs5, (s16) temp_s2, ((s16) var_fs5) + 1.77f, (s16) temp_s4);
        var_fs5 += 1.77f;
    }
}

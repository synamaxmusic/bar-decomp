// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

typedef struct GeometrySettings_s {
    s32 unk0;
    s32 unk4;
} GeometrySettings;

void __entrypoint_func_uvgeom_rom_400000(UvGeom_Exports *exports);
void func_uvgeom_rom_00400124(void);
void func_uvgeom_rom_00400168(s32 arg0, Gfx **gdlh);
s32 func_uvgeom_rom_0040019C(s32 arg0, s32 arg1, UvGeom_Rom_0040019C *arg2, Gfx **arg3);
void uvEndTmesh(s32 arg0, s32 arg1, UvGeom_Rom_0040019C *arg2, Gfx **arg3);
void uvEndGridWide(s16 arg0, s16 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5, UvGeom_Rom_0040019C *arg6,
                   Gfx **gdl);
void uvEndGrid(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, UvGeom_Rom_0040019C *arg6,
               Gfx **gdl);
void uvSetFillColor(f32 red, f32 green, f32 blue, f32 alpha);
void uvVtxRect(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void uvVtxEndPolyInternal(s32 arg0, s32 arg1, UvGeom_Rom_0040019C *arg2, Gfx **gdl);

// .bss
s32 D_uvgeom_rom_00401750;
UvGfxMgr_Exports *D_uvgeom_rom_00401754;
UvGfxMgr_Exports *D_uvgeom_rom_00401758;
Gfx *D_uvgeom_rom_0040175C;
u16 D_uvgeom_rom_00401760;

// .data
s32 D_uvgeom_rom_00401740[] = { 0x00180000, __entrypoint_func_uvgeom_rom_400000, 0, 0 };

void __entrypoint_func_uvgeom_rom_400000(UvGeom_Exports *exports) {
    GeometrySettings *settings;

    uvUpdateFileAllocPtr(exports);
    exports->uvVtxEndPolyInternal = uvVtxEndPolyInternal;
    exports->func_uvgeom_rom_00400124 = func_uvgeom_rom_00400124;
    exports->uvEndTmesh = uvEndTmesh;
    exports->uvEndGrid = uvEndGrid;
    exports->uvSetFillColor = uvSetFillColor;
    exports->uvVtxRect = uvVtxRect;
    settings = uvGetSystemProp(SYSTEM_PROPID_GEOMETRY_SETTINGS);
    if (settings == NULL) {
        D_uvgeom_rom_00401750 = 0x3E8;
        D_uvgeom_rom_00401754 = NULL;
    } else {
        if (settings->unk0 != 0) {
            D_uvgeom_rom_00401750 = settings->unk0;
        } else {
            D_uvgeom_rom_00401750 = 0x3E8;
        }
        D_uvgeom_rom_00401754 = settings->unk4;
    }
    if (D_uvgeom_rom_00401754 == NULL) {
        D_uvgeom_rom_00401754 = _uvMemAlloc(D_uvgeom_rom_00401750 * 8, 0x10U);
        D_uvgeom_rom_00401760 |= 1;
    }
    D_uvgeom_rom_0040175C = (Gfx *) D_uvgeom_rom_00401754;
    D_uvgeom_rom_00401758 = uvLoadModule('GMGR');
}

void func_uvgeom_rom_00400124(void) {
    uvUnloadModule('GMGR');
    if (D_uvgeom_rom_00401760 & 1) {
        _uvMemFree(D_uvgeom_rom_00401754);
    }
}

void func_uvgeom_rom_00400168(s32 arg0, Gfx **gdlh) {
    if (arg0 == 0) {
        gSPEndDisplayList(gdlh[0]++);
        D_uvgeom_rom_0040175C = *gdlh;
    }
}

s32 func_uvgeom_rom_0040019C(s32 arg0, s32 arg1, UvGeom_Rom_0040019C *arg2, Gfx **arg3) {
    s32 var_v1;

    if (*arg3 == NULL) {
        *arg3 = D_uvgeom_rom_0040175C;
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    arg2->unk4 = 0x160FFF;
    arg2->unk10 = 0;
    arg2->unk12 = 0;
    arg2->unkC = -1;
    arg2->unkE = arg0;
    arg2->unk0 = arg1;
    arg2->unk8 = *arg3;
    return var_v1;
}

void uvEndTmesh(s32 arg0, s32 arg1, UvGeom_Rom_0040019C *arg2, Gfx **arg3) {
    s16 var_a2;
    s16 i;
    s16 var_t0;
    s16 sp20;
    Vtx *var_t2;

    if (arg0 < 3) {
        return;
    }

    var_t0 = FALSE;
    sp20 = func_uvgeom_rom_0040019C(arg0, arg1, arg2, arg3);
    var_t2 = arg2->unk0;
    while (arg0 >= 3) {
        if (arg0 < 16) {
            var_a2 = arg0;
        } else {
            var_a2 = 16;
        }

        arg2->unk10 += var_a2;

        gSPVertex(arg3[0]++, OS_PHYSICAL_TO_K0(var_t2), var_a2, 0);
        var_a2 -= 2;
        arg0 -= var_a2;
        var_t2 += var_a2;

        for (i = 0; i < var_a2; i++) {
            arg2->unk12++;
            if (var_t0) {
                gSP1Triangle(arg3[0]++, i, i + 2, i + 1, 0);
            } else {
                gSP1Triangle(arg3[0]++, i, i + 1, i + 2, 0);
            }
            var_t0 ^= TRUE;
        }
    }
    func_uvgeom_rom_00400168((s32) sp20, arg3);
}

void uvEndGridWide(s16 arg0, s16 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5, UvGeom_Rom_0040019C *arg6,
                   Gfx **gdl) {
    s32 temp_a2;
    s32 temp_v1;
    s32 var_t2;
    s32 j;
    Vtx *var_s0;
    Vtx *var_s1;
    Vtx *var_s6;
    s32 i;
    s32 var_t3;
    s32 var_t1;
    s32 var_t0;
    s32 sp40;

    var_t0 = 0;
    var_t1 = 0;
    var_t2 = 0;
    sp40 = func_uvgeom_rom_0040019C(arg4, arg5, arg6, gdl);
    var_s6 = var_s1 = arg6->unk0;

    for (i = 0; i < (arg1 + arg3) - 1; i++) {
        var_t3 = 1;
        if (arg1 == i + 1) {
            var_s0 = var_s6;
        } else {
            var_s0 = arg0 + var_s1;
        }

        for (j = 0; j < arg0 * 2; j++) {
            if (var_t3) {
                temp_a2 = var_t1;
                var_t1 = var_t0;
                var_t0 = var_t2 % 16;

                gSPVertex(gdl[0]++, (j / 2) + (Vtx *) OS_PHYSICAL_TO_K0(var_s1), 1, var_t0);
                var_t2++;
                if (j >= 2) {
                    gSP1Triangle(gdl[0]++, temp_a2, var_t1, var_t0, 0);
                }
            } else {
                temp_a2 = var_t1;
                var_t1 = var_t0;
                var_t0 = var_t2 % 16;
                gSPVertex(gdl[0]++, (j / 2) + (Vtx *) OS_PHYSICAL_TO_K0(var_s0), 1, var_t0);
                var_t2++;
                if (j >= 2) {
                    gSP1Triangle(gdl[0]++, temp_a2, var_t0, var_t1, 0);
                }
            }
            var_t3 ^= 1;
        }
        if (arg2) {
            temp_a2 = var_t1;
            var_t1 = var_t0;
            var_t0 = var_t2 % 16;
            gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_s1), 1, var_t0);
            var_t2++;
            gSP1Triangle(gdl[0]++, temp_a2, var_t1, var_t0, 0);

            temp_a2 = var_t1;
            var_t1 = var_t0;
            var_t0 = var_t2 % 16;
            gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_s0), 1, var_t0);
            var_t2++;
            gSP1Triangle(gdl[0]++, temp_a2, var_t0, var_t1, 0);
        }
        var_s1 += arg0;
    }
    func_uvgeom_rom_00400168(sp40, gdl);
}

void uvEndGrid(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, UvGeom_Rom_0040019C *arg6,
               Gfx **gdl) {
    s32 spCC;
    s32 spC8;
    s16 spC6;
    s16 spC7;
    s16 spC5;
    s16 spC4;
    s16 spC3;
    Vtx *var_s1;
    Vtx *var_s6;
    s16 spBC[2];
    s16 sp40;
    s32 pad;

    // clang-format off
    if (arg1 < arg0) {
        spC7 = arg1;\
        spC6 = arg0;\
        spC5 = arg3;\
        spC4 = arg2;
    } else {
        spC7 = arg0;\
        spC6 = arg1;\
        spC5 = arg2;\
        spC4 = arg3;
    }
    // clang-format on

    if (spC7 >= 9) {
        uvEndGridWide(spC7, spC6, spC4, spC5, arg4, arg5, arg6, gdl);
        return;
    }

    if (spC6 < 2) {
        return;
    }

    sp40 = func_uvgeom_rom_0040019C(arg4, arg5, arg6, gdl);
    var_s1 = arg6->unk0;
    spBC[0] = 0;
    spBC[1] = spC7;

    gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_s1), spC7, spBC[0]);

    var_s6 = (Vtx *) var_s1 + spC7;

    spC3 = 1;
    for (spCC = 1; spCC < spC6; spCC++) {
        gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_s6), spC7, spBC[spC3]);

        if (spC3) {
            for (spC8 = 0; spC8 < spC7 - 1; spC8++) {
                gSP1Triangle(gdl[0]++, spC8, spC8 + spC7, spC8 + spC7 + 1, 0);
                gSP1Triangle(gdl[0]++, spC8, spC8 + spC7 + 1, spC8 + 1, 0);
            }

            if (spC5) {
                gSP1Triangle(gdl[0]++, spC8, spC8 + spC7, spC7, 0);
                gSP1Triangle(gdl[0]++, spC8, spC7, 0, 0);
            }
        } else {
            for (spC8 = 0; spC8 < spC7 - 1; spC8++) {
                gSP1Triangle(gdl[0]++, spC8 + spC7, spC8, spC8 + 1, 0);
                gSP1Triangle(gdl[0]++, spC8 + spC7, spC8 + 1, spC8 + spC7 + 1, 0);
            }
            if (spC5) {
                gSP1Triangle(gdl[0]++, spC8 + spC7, 0, spC7, 0);
                gSP1Triangle(gdl[0]++, spC8 + spC7, spC8, 0, 0);
            }
        }
        var_s6 += spC7;
        spC3 ^= 1;
    }

    if (spC4) {
        gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_s1), spC7, spBC[0]);

        for (spC8 = 0; spC8 < spC7 - 1; spC8++) {
            gSP1Triangle(gdl[0]++, spC8 + spC7, spC8, spC8 + 1, 0);
            gSP1Triangle(gdl[0]++, spC8 + spC7, spC8 + 1, spC8 + spC7 + 1, 0);
        }

        if (spC5) {
            gSP1Triangle(gdl[0]++, spC8 + spC7, 0, spC7, 0);
            gSP1Triangle(gdl[0]++, spC8 + spC7, spC8, 0, 0);
        }
    }
    func_uvgeom_rom_00400168(sp40, gdl);
}

void uvSetFillColor(f32 red, f32 green, f32 blue, f32 alpha) {
    Gfx **gdl;
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    r = red * 255.0f;
    g = green * 255.0f;
    b = blue * 255.0f;
    a = alpha * 255.0f;
    gdl = D_uvgeom_rom_00401758->uvGetDisplayListHead();
    gDPPipeSync(gdl[0]++);
    gDPSetPrimColor(gdl[0]++, 0, 0, r, g, b, a);
    gDPSetFillColor(gdl[0]++, GPACK_RGBA5551(r, g, b, a) << 16 | GPACK_RGBA5551(r, g, b, a));
}

void uvVtxRect(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx **gdl;

    gdl = D_uvgeom_rom_00401758->uvGetDisplayListHead();
    arg3 = (D_uvgeom_rom_00401758->uvGetScreenHeight() - arg3) - 1;
    arg1 = (D_uvgeom_rom_00401758->uvGetScreenHeight() - arg1) - 1;
    if (arg0 < 0) {
        arg0 = 0;
    } else if (arg0 >= D_uvgeom_rom_00401758->uvGetScreenWidth()) {
        arg0 = D_uvgeom_rom_00401758->uvGetScreenWidth() - 1;
    }
    if (arg2 < 0) {
        arg2 = 0;
    } else if (arg2 >= D_uvgeom_rom_00401758->uvGetScreenWidth()) {
        arg2 = D_uvgeom_rom_00401758->uvGetScreenWidth() - 1;
    }
    if (arg3 < 0) {
        arg3 = 0;
    } else if (arg3 >= D_uvgeom_rom_00401758->uvGetScreenHeight()) {
        arg3 = D_uvgeom_rom_00401758->uvGetScreenHeight() - 1;
    }
    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 >= D_uvgeom_rom_00401758->uvGetScreenHeight()) {
        arg1 = D_uvgeom_rom_00401758->uvGetScreenHeight() - 1;
    }
    gDPPipeSync(gdl[0]++);
    gDPSetCycleType(gdl[0]++, G_CYC_FILL);
    gDPSetRenderMode(gdl[0]++, G_RM_PASS, G_RM_NOOP2);
    gDPPipeSync(gdl[0]++);
    gDPFillRectangle(gdl[0]++, arg0, arg3, arg2, arg1);
    gDPPipeSync(gdl[0]++);
    gDPSetCycleType(gdl[0]++, G_CYC_2CYCLE);
}

void uvVtxEndPolyInternal(s32 arg0, s32 arg1, UvGeom_Rom_0040019C *arg2, Gfx **gdl) {
    s16 var_a2;
    s16 sp34;
    s16 var_v0;
    s16 i;
    s16 var_ra;
    Vtx *var_t2;

    var_ra = TRUE;
    if (arg0 < 3) {
        return;
    }
    sp34 = func_uvgeom_rom_0040019C(arg0, arg1, arg2, gdl);
    var_t2 = arg2->unk0;
    while (arg0 > 0) {
        if (var_ra) {
            var_ra = FALSE;
            if (arg0 < 16) {
                var_v0 = arg0;
            } else {
                var_v0 = 16;
            }
            gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_t2), var_v0, 0);
            var_a2 = var_v0 - 2;
        } else {
            if (arg0 >= 15) {
                var_v0 = 15;
                gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_t2), 14, 1);
                gSP1Triangle(gdl[0]++, 0, 15, 1, 0);
                gSPVertex(gdl[0]++, (((u32) (var_t2) + 0x80000000)) + 14 * sizeof(Vtx), 1, 15);
            } else {
                var_v0 = arg0;
                gSPVertex(gdl[0]++, OS_PHYSICAL_TO_K0(var_t2), var_v0, 1);
                gSP1Triangle(gdl[0]++, 0, 15, 1, 0);
            }
            var_a2 = var_v0 - 1;
        }
        var_t2 += var_v0;
        arg0 -= var_v0;
        for (i = 0; i < var_a2; i++) {
            gSP1Triangle(gdl[0]++, 0, i + 1, i + 2, 0);
        }
    }
    func_uvgeom_rom_00400168((s32) sp34, gdl);
}
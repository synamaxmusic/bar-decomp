// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "stdarg.h"
#include "module.h"
#include "uvasset_types.h"

#define	G_F3DEX_IMMFIRST		-65
#define G_F3DEX_ENDDL			(G_F3DEX_IMMFIRST-7)
#define G_F3DEX_VTX 4

static UvTexture_Exports *sUvTextureExports;

void func_uvvattr_rom_00400070(void);
void func_uvvattr_rom_00400094(u32 arg0, u32 arg1, ...);
void func_uvvattr_rom_00400314(u32 arg0, s32 arg1, ...);
s32 func_uvvattr_rom_0040093C(Vtx_t *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_uvvattr_rom_00400CA8(ParsedUVMD *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_uvvattr_rom_00400F40(ParsedUVCT *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_uvvattr_rom_00401138(s32 arg0, Gfx* gdl);
void func_uvvattr_rom_004011B4(s32 arg0, u32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
s32 func_uvvattr_rom_00400514(s32 arg0, s32 *arg1, s32 arg2, ...);
void __entrypoint_func_uvvattr_rom_400000(UvVAttr_Exports *exports);

s32 D_uvvattr_rom_00401290[] = {0x00140000, __entrypoint_func_uvvattr_rom_400000, 0};

void __entrypoint_func_uvvattr_rom_400000(UvVAttr_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_uvvattr_rom_00400070 = func_uvvattr_rom_00400070;
    exports->func_uvvattr_rom_00400094 = func_uvvattr_rom_00400094;
    exports->func_uvvattr_rom_00400314 = func_uvvattr_rom_00400314;
    exports->func_uvvattr_rom_00400514 = func_uvvattr_rom_00400514;
    exports->func_uvvattr_rom_004011B4 = func_uvvattr_rom_004011B4;
    #ifdef __sgi
    #line 25
    #endif
    sUvTextureExports = uvLoadModule('TEXT');
}

void func_uvvattr_rom_00400070(void) {
    uvUnloadModule('TEXT');
}

void func_uvvattr_rom_00400094(u32 arg0, u32 arg1, ...) {
    Vtx_t sp30;
    ParsedUVCT *temp;
    ParsedUVMD *temp2;
    va_list args;
    s32 pad;

    va_start(args, arg1);

    if (arg0 & 0x80000000) {
        temp = uvGetLoadedFile('UVCT', (arg0 & 0x7FFF0000) >> 16);
        sp30 = temp->vtxTable[arg0 & 0xFFFF].v;
    } else {
        temp2 = uvGetLoadedFile('UVMD', (arg0 & 0x7FFF0000) >> 16);
        sp30 = temp2->vtxTable[arg0 & 0xFFFF].v;
    }

    if (arg1 & 0x001) {
        *va_arg(args, s16 *) = sp30.ob[0];
    }
    if (arg1 & 0x002) {
        *va_arg(args, s16 *) = sp30.ob[1];
    }
    if (arg1 & 0x004) {
        *va_arg(args, s16 *) = sp30.ob[2];
    }
    if (arg1 & 0x008) {
        *va_arg(args, s16 *) = sp30.tc[0];
    }
    if (arg1 & 0x010) {
        *va_arg(args, s16 *) = sp30.tc[1];
    }
    if (arg1 & 0x020) {
        *va_arg(args, s8 *) = sp30.cn[0];
    }
    if (arg1 & 0x040) {
        *va_arg(args, s8 *) = sp30.cn[1];
    }
    if (arg1 & 0x080) {
        *va_arg(args, s8 *) = sp30.cn[2];
    }
    if (arg1 & 0x100) {
        *va_arg(args, u8 *) = sp30.cn[3];
    }

    va_end(args);
}

void func_uvvattr_rom_00400314(u32 arg0, s32 arg1, ...) {
    ParsedUVCT *temp;
    Vtx_t *var_a0;
    ParsedUVMD *temp2;
    va_list args;

    va_start(args, arg1);
    if (arg0 & 0x80000000) {
        temp = uvGetLoadedFile('UVCT', (arg0 & 0x7FFF0000) >> 16);
        var_a0 = &temp->vtxTable[arg0 & 0xFFFF].v;
    } else {
        temp2 = uvGetLoadedFile('UVMD', (arg0 & 0x7FFF0000) >> 16);
        var_a0 = &temp2->vtxTable[arg0 & 0xFFFF].v;
    }
    if (arg1 & 1) {
        var_a0->ob[0] = va_arg(args, s32);
    }
    if (arg1 & 2) {
        var_a0->ob[1] = va_arg(args, s32);
    }
    if (arg1 & 4) {
        var_a0->ob[2] = va_arg(args, s32);
    }
    if (arg1 & 8) {
        var_a0->tc[0] = va_arg(args, s32);
    }
    if (arg1 & 0x10) {
        var_a0->tc[1] = va_arg(args, s32);
    }
    if (arg1 & 0x20) {
        var_a0->cn[0] = va_arg(args, s32);
    }
    if (arg1 & 0x40) {
        var_a0->cn[1] = va_arg(args, s32);
    }
    if (arg1 & 0x80) {
        var_a0->cn[2] = va_arg(args, s32);
    }
    if (arg1 & 0x100) {
        var_a0->cn[3] = va_arg(args, s32);
    }
}

s32 func_uvvattr_rom_00400514(s32 arg0, s32* arg1, s32 arg2, ...) {
    s32 i;
    s32 j;
    s32 k;
    s32 sp208;
    s32 var_fp;
    s32 var_s3;
    s32 sp1FC;
    s32 var_v0;
    s32 var_v1;
    s32 sp174[32];
    s32 spF4[32];
    s32 sp74[32];
    Vtx* vtx;
    ParsedUVCT* temp_s7;
    ParsedUVMD* temp_s7_2;
    va_list args;

    va_start(args, arg2);
    sp1FC = 0;
    var_fp = 0;
    sp208 = 0xFFFF;

    if (arg2 & 0xC) {
        sp208 = va_arg(args, s32);
    }


    while (TRUE) {
        i = va_arg(args, s32);
        if (i == 0) {
            break;
        }
        j = va_arg(args, s32);
        k = va_arg(args, s32);
        sp174[var_fp] = i;
        spF4[var_fp] = j;
        sp74[var_fp] = k;

        var_fp++;
        if (var_fp >= 32) {
            var_fp--;
        }
    }
    if (arg2 & 4) {
        var_v1 = var_v0 = sp208;
    } else {
        if (arg2 & 1) {
            var_v0 = 0;
            var_v1 = uvGetFilesCount('UVCT') - 1;
        } else {
            var_v0 = 0;
            var_v1 = -1;
        }
    }

    for (i = var_v0; i <= var_v1; i++) {
        temp_s7 = uvGetLoadedFile('UVCT', i);
        if (temp_s7 == NULL) {
            continue;
        }
        for (j = 0; j < temp_s7->vtxCount; j++) {
            var_s3 = 0;
            vtx = &temp_s7->vtxTable[j];
            FOR_START(k, 0, var_fp);
                if (sp174[k] & 0x600) {
                    var_s3 += func_uvvattr_rom_00400F40(temp_s7, vtx, sp174[k], spF4[k], sp74[k]);
                } else {
                    var_s3 += func_uvvattr_rom_0040093C(vtx, sp174[k], spF4[k], sp74[k]);
                }
            FOR_END(k, var_fp);
            if (var_s3 == var_fp) {
                if (sp1FC >= arg0) {
                    sp1FC--;
                }
                arg1[sp1FC] = (i << 0x10) | 0x80000000 | j;
                sp1FC++;
            }
        }
    }
    if (arg2 & 8) {
        var_v1 = var_v0 = sp208;
    } else {
        var_v0 = 0;
        if (arg2 & 2) {
            var_v1 = uvGetFilesCount('UVMD') - 1;
        } else {
            var_v1 = -1;
        }
    }

    for (i = var_v0; i <= var_v1; i++) {
        temp_s7_2 = uvGetLoadedFile('UVMD', i);
        if (temp_s7_2 == NULL) {
            continue;
        }
        for (j = 0; j < temp_s7_2->vtxCount; j++) {
            var_s3 = 0;
            vtx = &temp_s7_2->vtxTable[j];
            FOR_START(k, 0, var_fp);
                if (sp174[k] & 0x600) {
                    var_s3 += func_uvvattr_rom_00400CA8(temp_s7_2, vtx, sp174[k], spF4[k], sp74[k]);
                } else {
                    var_s3 += func_uvvattr_rom_0040093C(vtx, sp174[k], spF4[k], sp74[k]);
                }
            FOR_END(k, var_fp);
            if (var_s3 == var_fp) {
                if (sp1FC >= arg0) {
                    sp1FC--;
                }
                arg1[sp1FC] = (i << 0x10) | j;
                sp1FC++;
            }
        }
    }
    return sp1FC;
}

s32 func_uvvattr_rom_0040093C(Vtx_t *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_v0;

    if (arg1 & 1) {
        temp_v0 = arg0->ob[0];
        if ((arg2 & 2) && (temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 2) {
        temp_v0 = arg0->ob[1];
        if ((arg2 & 2) && (temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 4) {
        temp_v0 = arg0->ob[2];
        if ((arg2 & 2) && (temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 8) {
        temp_v0 = arg0->tc[0];
        if ((arg2 & 2) && (temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 0x10) {
        temp_v0 = arg0->tc[1];
        if ((arg2 & 2) && (temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 0x20) {
        temp_v0 = arg0->cn[0];
        if ((arg2 & 2) && ((s32) temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < (s32) temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 0x40) {
        temp_v0 = arg0->cn[1];
        if ((arg2 & 2) && ((s32) temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < (s32) temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 0x80) {
        temp_v0 = arg0->cn[2];
        if ((arg2 & 2) && ((s32) temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < (s32) temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    if (arg1 & 0x100) {
        temp_v0 = arg0->cn[3];
        if ((arg2 & 2) && ((s32) temp_v0 < arg3)) {
            return 1;
        }
        if ((arg2 & 4) && (arg3 < (s32) temp_v0)) {
            return 1;
        }
        if ((arg2 & 1) && (temp_v0 == arg3)) {
            return 1;
        }
    }
    return 0;
}

s32 func_uvvattr_rom_00400CA8(ParsedUVMD *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 j;
    s32 k;
    s32 temp_t5;
    s32 temp_v0;
    ParsedUVMD_1 *sp50;
    uvModelLOD *temp_s1;
    uvGfxState *temp_s3;

    for (i = 0; i < arg0->unk4; i++) {
        sp50 = &arg0->unk0[i];
        for (j = 0; j < sp50->unk8; j++) {
            temp_s1 = &sp50->unk0[j];
            for (k = 0; k < temp_s1->unk4; k++) {
                temp_s3 = &temp_s1->stateTable[k];
                temp_t5 = temp_s3->state & 0xFFF;
                if (arg2 & 0x200) {
                    if (temp_t5 == 0xFFF) {
                        continue;
                    }
                    temp_v0 = sUvTextureExports->func_uvtexture_rom_00400164(temp_t5);
                    if ((arg3 & 1) && (temp_v0 != arg4)) {
                        continue;
                    }
                    if ((arg3 & 2) && (arg4 < temp_v0)) {
                        continue;
                    }
                    if ((arg3 & 4) && (temp_v0 < arg4)) {
                        continue;
                    }
                }
                if (arg2 & 0x400) {
                    if ((arg3 & 1) && (temp_t5 != arg4)) {
                        continue;
                    }
                    if ((arg3 & 2) && (arg4 < temp_t5)) {
                        continue;
                    }
                    if ((arg3 & 4) && (temp_t5 < arg4)) {
                        continue;
                    }
                }
                if (func_uvvattr_rom_00401138(arg1, temp_s3->displayList) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 func_uvvattr_rom_00400F40(ParsedUVCT *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_t7;
    s32 temp_v0;
    s32 i;
    s32 var_v1;
    u16 var_v0;
    Unk80225FBC_0x28 *temp_s5;

    for (i = 0; i < arg0->unkC; i++) {
        temp_s5 = &arg0->unk8[i];
        temp_t7 = temp_s5->unk0.state & 0xFFF;
        if (arg2 & 0x200) {
            if (temp_t7 == 0xFFF) {
                continue;
            }
            temp_v0 = sUvTextureExports->func_uvtexture_rom_00400164(temp_t7);
            if ((arg3 & 1) && (temp_v0 != arg4)) {
                continue;
            }
            if ((arg3 & 2) && (arg4 < temp_v0)) {
                continue;
            }
            if ((arg3 & 4) && (temp_v0 < arg4)) {
                continue;
            }
        }
        if (arg2 & 0x400) {
            if ((arg3 & 1) && (temp_t7 != arg4)) {
                continue;
            }
            if ((arg3 & 2) && (arg4 < temp_t7)) {
                continue;
            }
            if ((arg3 & 4) && (temp_t7 < arg4)) {
                continue;
            }
        }
        if (func_uvvattr_rom_00401138(arg1, temp_s5->unk0.displayList) != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_uvvattr_rom_00401138(s32 arg0, Gfx* gdl) {
    Gfx* var_a1;
    u32 vtxAddr;
    u32 cmd;
    u32 addr;
    u32 var_v1;

    addr = (arg0 & 0x7FFFFFFF);
    cmd = (u32) (gdl->words.w0 & 0xFF000000) >> 0x18;
    while (cmd != (u8)G_F3DEX_ENDDL) {
        var_v1 = gdl->words.w0;
        vtxAddr = gdl->words.w1;
        gdl++;
        if (cmd == G_F3DEX_VTX) {
            if ((addr >= vtxAddr) && (addr < (vtxAddr + (var_v1 & 0xFFFF)))) {
                return 1;
            }
        }
        cmd = (u32) (gdl->words.w0 & 0xFF000000) >> 0x18;
    }

    return 0;
}

void func_uvvattr_rom_004011B4(s32 arg0, u32 arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    ParsedUVTR *temp_v0;
    Unk80225FBC_0x28_UnkC *temp_v1;
    s32 new_var;
    Unk80225FBC_0x28 *new_var6;
    uvUnkTileStruct *temp_a1;

    if (arg1 == (-1U)) {
        return;
    }
    temp_v0 = uvGetLoadedFile('UVTR', arg0);
    if (temp_v0 == 0) {
        return;
    }
    temp_a1 = &temp_v0->unk28[(arg1 >> 0x16) & 0x3FF];
    new_var6 = &temp_a1->unk40->unk8[(arg1 >> 0xC) & 0x3FF];
    temp_v1 = &new_var6->unk18[arg1 & 0xFFF];
    new_var = temp_a1->unk44;
    *arg2 = (new_var << 0x10) | 0x80000000 | temp_v1->unk0;
    *arg3 = (new_var << 0x10) | 0x80000000 | temp_v1->unk2;
    *arg4 = (new_var << 0x10) | 0x80000000 | temp_v1->unk4;
}

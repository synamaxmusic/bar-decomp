// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"

void func_uvvolumeld_rom_00400048(void);
void* uvParseUVVL(u8* arg0);
void func_uvvolumeld_rom_004001F8(ParsedUVVL *arg0);
void __entrypoint_func_uvvolumeld_rom_400000(UvVolumeLd_Rom_Exports* exports);

s32 D_uvvolumeld_rom_00400270[] = {0x000C0000, __entrypoint_func_uvvolumeld_rom_400000, 0};

void __entrypoint_func_uvvolumeld_rom_400000(UvVolumeLd_Rom_Exports* exports) {
    uvUpdateFileAllocPtr(exports);
    exports->uvParseUVVL = uvParseUVVL;
    exports->func_uvvolumeld_rom_00400048 = func_uvvolumeld_rom_00400048;
    exports->func_uvvolumeld_rom_004001F8 = func_uvvolumeld_rom_004001F8;
}

void func_uvvolumeld_rom_00400048(void) {

}

void* uvParseUVVL(u8* arg0) {
    s32 fileId;
    u32 sp60;
    void* sp5C;
    ParsedUVVL_inner* temp_s0;
    ParsedUVVL* uvvl;
    u32 var_v0;
    void* sp4C;
    void* temp_s6;
    s32 i; // var_s2

    uvvl = _uvMemAllocAlign8(8);
    uvvl->unk0 = 0;
    uvvl->unk4 = NULL;
    fileId = uvFileReadHeader(arg0);
    while ((var_v0 = uvFileReadBlock(fileId, &sp60, &sp5C, 1)) != 0) {
        switch (var_v0) {
        case 'VOBJ':
            sp4C = temp_s6 = sp5C;
            uvConsumeBytes(&uvvl->unk0, (u8** ) &sp4C, sizeof(uvvl->unk0));
            uvvl->unk4 = _uvMemAllocAlign8(uvvl->unk0 * sizeof(uvvl->unk4[0]));

            for (i = 0; i < uvvl->unk0; i++) {
                temp_s0 = &uvvl->unk4[i];
                uvConsumeBytes(&temp_s0->unk0, (u8** ) &sp4C, sizeof(temp_s0->unk0));
                temp_s0->unk4 = _uvMemAllocAlign8(temp_s0->unk0 * sizeof(temp_s0->unk4[0]));
                uvConsumeBytes(temp_s0->unk4, (u8** ) &sp4C, temp_s0->unk0 * sizeof(temp_s0->unk4[0]));
                uvConsumeBytes(&temp_s0->unk8, (u8** ) &sp4C, sizeof(temp_s0->unk8));
                uvConsumeBytes(&temp_s0->unk14, (u8** ) &sp4C, sizeof(temp_s0->unk14));
            }

            _uvMemFree(temp_s6);
            break;
        default:
            break;
        }
    }
    uvFileFree(fileId);
    return uvvl;
}

void func_uvvolumeld_rom_004001F8(ParsedUVVL* uvvl) {
    s32 i;

    for (i = 0; i < uvvl->unk0; i++) {
        _uvMemFree(uvvl->unk4[i].unk4);
    }
    _uvMemFree(uvvl->unk4);
    _uvMemFree(uvvl);
}

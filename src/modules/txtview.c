// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct Unkstruct_txtview_00400CB8_s {
    /* 0x00 */ s32 texture;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
} Unkstruct_txtview_00400CB8;

void __entrypoint_func_txtview_400000(TxtView_Exports *exports);
void func_txtview_004000EC(void);
void func_txtview_00400118(void);
void func_txtview_00400148(void);
void func_txtview_00400238(s32 arg0);
void func_txtview_00400298(GuiSlider *slider);
void txtviewCreateMenu(void);

// .data
s32 D_txtview_00400C80[] = { 0x00100000, __entrypoint_func_txtview_400000, 0 };

// .bss
s32 B_txtview_00400C90;
s32 D_txtview_00400C94;
s32 D_txtview_00400C98;
f32 D_txtview_00400C9C;
f32 D_txtview_00400CA0;
f32 D_txtview_00400CA4;
f32 D_txtview_00400CA8;
f32 D_txtview_00400CAC;
f32 D_txtview_00400CB0;
Unkstruct_txtview_00400CB8 D_txtview_00400CB8;

void __entrypoint_func_txtview_400000(TxtView_Exports *exports) {
    s32 temp;
    uvUpdateFileAllocPtr(exports);
    exports->func_txtview_004000EC = func_txtview_004000EC;
    exports->func_txtview_00400118 = func_txtview_00400118;
    exports->func_txtview_00400148 = func_txtview_00400148;
    exports->func_txtview_00400238 = func_txtview_00400238;
#ifdef __sgi
#line 37
#endif
    D_txtview_00400C94 = 0;
    D_txtview_00400C98 = 0;
    D_txtview_00400C9C = D_txtview_00400CA0 = 1.0f;
    D_txtview_00400CA4 = D_txtview_00400CA8 = D_txtview_00400CAC = D_txtview_00400CB0 = 1.0f;
    D_txtview_00400CB8.texture = temp = D_txtview_00400CB8.unk4 = temp = D_txtview_00400CB8.unk8 =
        temp = D_txtview_00400CB8.unkC = -1;
    uvLoadFile('UVTX', D_txtview_00400C94);
}

void func_txtview_004000EC(void) {
    uvUnloadFile('UVTX', D_txtview_00400C94);
}

void func_txtview_00400118(void) {
    if (D_txtview_00400C98 == 0) {
        func_txtview_00400238(0);
    }
}

void func_txtview_00400148(void) {
    if (D_txtview_00400C94 >= 0) {
        gUvGeomExports->uvSetFillColor(D_txtview_00400CA4, D_txtview_00400CA8, D_txtview_00400CAC,
                                       D_txtview_00400CB0);
        gUvGeomExports->uvVtxRect(0, 0, 319, 239);
        gUvGfxStateExports->func_uvgfxstate_rom_00401354(0x1A240000);
        gUvGfxStateExports->uvGfxStateBindTexture(D_txtview_00400C94);
        gUvGfxStateExports->func_uvgfxstate_rom_00402350(0x14, 0xC8, 0x14, 0xC8, 0.0f,
                                                         D_txtview_00400C9C, 0.0f, D_txtview_00400CA0);
    }
}

void func_txtview_00400238(s32 arg0) {
    gGameGuiExports->func_gamegui_00402030(txtviewCreateMenu);
#ifndef NON_MATCHING
    gGameGuiExports->func_gamegui_00401AD8(1); //! @bug: This will make the game crash
#else
    gGameGuiExports->func_gamegui_00401AD8(0);
#endif
    D_txtview_00400C98 += 1;
}

void func_txtview_00400298(GuiSlider *slider) {
    s32 temp_v1;
    s32 fileId;
    char label[4];

    fileId = slider->roundedValue;
    if (D_txtview_00400C94 >= 0) {
        if (D_txtview_00400CB8.texture > 0) {
            uvUnloadFile('UVTX', D_txtview_00400CB8.texture);
        }
        D_txtview_00400CB8.texture = D_txtview_00400CB8.unk4;
        D_txtview_00400CB8.unk4 = D_txtview_00400CB8.unk8;
        D_txtview_00400CB8.unk8 = D_txtview_00400CB8.unkC;
        D_txtview_00400CB8.unkC = D_txtview_00400C94;
    }
    if (D_txtview_00400C94 < fileId) {
        while (uvLoadFile('UVTX', fileId) == NULL) {
            fileId++;
        }
    } else {
        while (uvLoadFile('UVTX', fileId) == NULL) {
            fileId--;
        }
    }

    D_txtview_00400C94 = fileId;
    sprintf(label, "%d", D_txtview_00400C94);

    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, (uvGetFilesCount('UVTX') - 1),
                                           D_txtview_00400C94, NULL);
    gUvGuiExports->uvGuiSliderSetLabel(slider, label);
}

void txtviewCreateMenu(void) {
    GuiMenuItem *menuItem;
    GuiSlider *slider;
    GuiMenuOption *menuOption;
    GuiMenu *menu;
    s32 fileCount;
    uvGui *gui;

    gui = &gGameGuiExports->D_gamegui_00402C68->gui;
    gGameGuiExports->func_gamegui_00401E7C();
    menu = gUvGuiExports->uvGuiGetMenu(gUvGuiExports->uvGuiNewMenu());
    gUvGuiExports->uvGuiSetMenuTitle(menu, "texture viewer");
    gUvGuiExports->uvGuiAddMenu(gui, menu);
    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, "texture viewer");
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);

    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "texture id");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    fileCount = uvGetFilesCount('UVTX') - 1;
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 2);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, fileCount, 0.0f, NULL);
    gUvGuiExports->uvGuiSliderSetCallback(slider, func_txtview_00400298);
    gUvGuiExports->uvGuiSliderSetLabel(slider, "0");
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);

    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "U coordinate");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 0x11);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, 2.0f, 0.0f, (s32 *) &D_txtview_00400C9C);
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);
    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "V coordinate");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 0x11);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, 2.0f, 0.0f, (s32 *) &D_txtview_00400CA0);
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);
    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "red");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 0x11);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, 1.0f, 0.0f, (s32 *) &D_txtview_00400CA4);
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);
    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "green");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 0x11);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, 1.0f, 0.0f, (s32 *) &D_txtview_00400CA8);
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);
    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "blue");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 0x11);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, 1.0f, 0.0f, (s32 *) &D_txtview_00400CAC);
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);
    menuItem = gUvGuiExports->uvGuiGetMenuItem(gUvGuiExports->uvGuiNewMenuItem());
    gUvGuiExports->uvGuiSetMenuItemName(menuItem, "alpha");
    gUvGuiExports->uvGuiAddMenuItem(menuOption, menuItem);
    slider = gUvGuiExports->uvGuiGetSlider(gUvGuiExports->uvGuiSliderNew());
    gUvGuiExports->uvGuiSliderSetMode(slider, 0x11);
    gUvGuiExports->uvGuiSliderSetValues(slider, 0.0f, 1.0f, 0.0f, (s32 *) &D_txtview_00400CB0);
    gUvGuiExports->uvGuiAddSlider(menuItem, slider);
}

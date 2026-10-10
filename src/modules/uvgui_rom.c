// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "uvasset_types.h"

void uvGuiDestroy(void);
void uvGuiInit(uvGui *arg0);
void uvGuiAddMenu(uvGui *arg0, GuiMenu *arg1);
void uvGuiRender(uvGui *arg0);
void uvGuiDrawRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6,
                             u8 arg7, u8 arg8);
void uvGuiPrintCentered(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4, u8 arg5, u8 arg6,
                             u8 arg7, u8 arg8);
void uvGuiDrawCursor(s16 arg0, s16 arg1);
void func_uvgui_rom_0040126C(uvGui *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
s32 func_uvgui_rom_00401290(uvGui *arg0);
void func_uvgui_rom_004015B8(uvGui *arg0, s16 arg1, s32 arg2);
void func_uvgui_rom_00401614(uvGui *arg0, s16 uvds, s16 font);
void func_uvgui_rom_004016A0(uvGui *arg0, s8 arg1);
void func_uvgui_rom_004016AC(uvGui *arg0, s16 arg1, s16 arg2);
void func_uvgui_rom_004016E0(s16 arg0);
void func_uvgui_rom_004016F0(uvGui *arg0);
void uvGuiInitializeMenuItems(void);
s16 uvGuiNewMenuItem(void);
GuiMenuItem *uvGuiGetMenuItem(s16 arg0);
void uvGuiSetMenuItemName(GuiMenuItem *arg0, u8 *arg1);
void func_uvgui_rom_00401D74(GuiMenuItem *arg0, s16 arg1);
void func_uvgui_rom_00401D80(GuiMenuItem *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_uvgui_rom_00401DC4(GuiMenuItem *arg0);
s32 func_uvgui_rom_004020A0(GuiMenuItem *arg0, u8 arg1, s16 arg2, s16 arg3, s32 arg4,
                            f32 arg5, f32 arg6);
void func_uvgui_rom_0040221C(GuiMenuItem *arg0, s16 arg1, UvGuiCallback routine);
void func_uvgui_rom_00402268(GuiMenuItem *arg0, GuiSlider *arg1);
void func_uvgui_rom_00402308(GuiMenuItem *arg0, Inner2C *arg1);
void func_uvgui_rom_004023A8(GuiMenuItem *arg0, Inner30 *arg1);
void uvGuiInitMenus(void);
s16 uvGuiNewMenu(void);
GuiMenu *uvGuiGetMenu(s16 arg0);
void uvGuiSetMenuTitle(GuiMenu *menu, u8 *title);
void func_uvgui_rom_0040277C(GuiMenu *arg0, s16 arg1);
void uvGuiSetMenuPosition(GuiMenu *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void uvGuiAddMenuOption(GuiMenu *arg0, GuiMenuOption *arg1);
void uvGuiRenderMenu(GuiMenu *arg0);
s32 func_uvgui_rom_0040293C(GuiMenu *arg0, u8 arg1, s16 arg2, s16 arg3, s32 arg4, f32 arg5,
                            f32 arg6);
void uvGuiInitMenuOptions(void);
s16 uvGuiNewMenuOption(void);
GuiMenuOption *uvGuiGetMenuOption(s16 arg0);
void uvGuiSetMenuOptionName(GuiMenuOption *arg0, u8 *arg1);
void func_uvgui_rom_00402C34(GuiMenuOption *arg0, s16 arg1);
void uvGuiSetMenuOptionPosition(GuiMenuOption *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void uvGuiAddMenuItem(GuiMenuOption *arg0, GuiMenuItem *arg1);
void uvGuiRenderMenuOption(GuiMenuOption *arg0);
s32 func_uvgui_rom_00402E48(GuiMenuOption *arg0, u8 arg1, s16 arg2, s16 arg3, s32 arg4, f32 arg5,
                            f32 arg6);
void uvGuiSliderInit(void);
s16 uvGuiSliderNew(void);
void uvGuiSliderFree(s16 arg0);
GuiSlider *uvGuiGetSlider(s16 arg0);
void uvGuiSliderSetLabel(GuiSlider *arg0, u8 *arg1);
void uvGuiSliderSetRect(GuiSlider *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void uvGuiDrawSlider(GuiSlider *arg0);
void func_uvgui_rom_004037D8(GuiSlider *arg0, s32 arg1);
void func_uvgui_rom_004037E0(GuiSlider *arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4);
void func_uvgui_rom_004038D8(GuiSlider *arg0, s16 arg1);
void func_uvgui_rom_004038E4(GuiSlider *arg0, u8 arg1, f32 arg2);
void func_uvgui_rom_00403C50(GuiSlider *arg0, s16 arg1);
void func_uvgui_rom_00403CA4(GuiSlider *arg0, s32 arg1);
void func_uvgui_rom_00403CAC(void);
s16 func_uvgui_rom_00403E78(void);
void func_uvgui_rom_00403EB8(s16 arg0);
Inner30 *func_uvgui_rom_00403EE0(s16 arg0);
void func_uvgui_rom_00403F08(Inner30 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_uvgui_rom_00403F2C(Inner30 *arg0, u8 *arg1, u8 *arg2);
void func_uvgui_rom_00404010(Inner30 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5);
void func_uvgui_rom_0040404C(Inner30 *arg0, s32 arg1);
void func_uvgui_rom_00404054(Inner30 *arg0, u8 button, f32 arg2);
void func_uvgui_rom_004046B4(Inner30 *arg0);
void func_uvgui_rom_00405CEC(Inner30 *arg0, s16 arg1);
void uvGuiProps(Inner30 *arg0, ...);
void func_uvgui_rom_00405D78(void);
s16 func_uvgui_rom_00405F20(void);
void func_uvgui_rom_00405F60(s16 arg0);
Inner2C *func_uvgui_rom_00405F90(s16 arg0);
void func_uvgui_rom_00405FC0(Inner2C *arg0, u8 *arg1);
void func_uvgui_rom_00406024(Inner2C *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_uvgui_rom_00406048(Inner2C *arg0);
void func_uvgui_rom_00406B00(Inner2C *arg0, s32 arg1);
void func_uvgui_rom_00406B08(Inner2C *arg0, f32 arg1, f32 arg2, Vec3F *arg3, Vec3F *arg4);
void func_uvgui_rom_00406B7C(Inner2C *arg0, s16 arg1);
void func_uvgui_rom_00406B88(Inner2C *arg0, u8 arg1, f32 arg2);
void func_uvgui_rom_00406E28(Inner2C *arg0, s16 arg1);
void __entrypoint_func_uvgui_rom_400000(UvGui_Exports *exports);

// exports
Inner2C D_uvgui_rom_00406F20[10];
static UvFMtx_Rom_Exports *sUvFMtxExports;
static UvFont_Exports *sUvFontExports;
static UvGfxMgr_Exports *sUvGfxMgrExports;
static UvGfxState_Rom_Exports *sUvGfxStateExports;
static UvDGeom_Rom_Exports *sUvDGeomExports;
static UvGrph_Exports *sUvGrphExports;
static UvCont_Exports *sUvContExports;
static UvString_Exports *sUvStringExports;
GuiMenuItem sGuiMenuItems[120];
GuiMenu sGuiMenus[8];
GuiMenuOption sGuiMenuOptions[50];
GuiSlider sGuiSliders[135];
Inner30 D_uvgui_rom_0040FB50[20];

// .data
s16 D_uvgui_rom_00406F00 = 0;

void __entrypoint_func_uvgui_rom_400000(UvGui_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_uvgui_rom_00406048 = func_uvgui_rom_00406048;
    exports->func_uvgui_rom_00406B00 = func_uvgui_rom_00406B00;
    exports->func_uvgui_rom_00406B08 = func_uvgui_rom_00406B08;
    exports->func_uvgui_rom_00406B7C = func_uvgui_rom_00406B7C;
    exports->uvGuiInit = uvGuiInit;
    exports->uvGuiAddMenu = uvGuiAddMenu;
    exports->uvGuiRender = uvGuiRender;
    exports->uvGuiDrawRect = uvGuiDrawRect;
    exports->uvGuiPrintCentered = uvGuiPrintCentered;
    exports->uvGuiDrawCursor = uvGuiDrawCursor;
    exports->func_uvgui_rom_0040126C = func_uvgui_rom_0040126C;
    exports->func_uvgui_rom_00401290 = func_uvgui_rom_00401290;
    exports->func_uvgui_rom_004015B8 = func_uvgui_rom_004015B8;
    exports->func_uvgui_rom_00402C34 = func_uvgui_rom_00402C34;
    exports->uvGuiSetMenuOptionPosition = uvGuiSetMenuOptionPosition;
    exports->uvGuiAddMenuItem = (void (*)(GuiMenuOption *, GuiMenuItem *)) uvGuiAddMenuItem;
    exports->uvGuiRenderMenuOption = uvGuiRenderMenuOption;
    exports->func_uvgui_rom_00406B88 = func_uvgui_rom_00406B88;
    exports->func_uvgui_rom_00402E48 = func_uvgui_rom_00402E48;
    exports->func_uvgui_rom_00406E28 = func_uvgui_rom_00406E28;
    exports->uvGuiSliderInit = uvGuiSliderInit;
    exports->uvGuiSliderNew = uvGuiSliderNew;
    exports->uvGuiSliderFree = uvGuiSliderFree;
    exports->uvGuiGetSlider = uvGuiGetSlider;
    exports->uvGuiSliderSetLabel = uvGuiSliderSetLabel;
    exports->func_uvgui_rom_00401614 = func_uvgui_rom_00401614;
    exports->func_uvgui_rom_004016A0 = func_uvgui_rom_004016A0;
    exports->func_uvgui_rom_004016AC = func_uvgui_rom_004016AC;
    exports->func_uvgui_rom_004016E0 = func_uvgui_rom_004016E0;
    exports->uvGuiSliderSetRect = uvGuiSliderSetRect;
    exports->func_uvgui_rom_004016F0 = func_uvgui_rom_004016F0;
    exports->uvGuiDrawSlider = uvGuiDrawSlider;
    exports->uvGuiInitializeMenuItems = uvGuiInitializeMenuItems;
    exports->func_uvgui_rom_004037D8 = func_uvgui_rom_004037D8;
    exports->uvGuiNewMenuItem = uvGuiNewMenuItem;
    exports->func_uvgui_rom_004037E0 = func_uvgui_rom_004037E0;
    exports->uvGuiGetMenuItem = uvGuiGetMenuItem;
    exports->func_uvgui_rom_004038D8 = func_uvgui_rom_004038D8;
    exports->uvGuiSetMenuItemName = uvGuiSetMenuItemName;
    exports->func_uvgui_rom_004038E4 = func_uvgui_rom_004038E4;
    exports->func_uvgui_rom_00401D74 = func_uvgui_rom_00401D74;
    exports->func_uvgui_rom_00403C50 = func_uvgui_rom_00403C50;
    exports->func_uvgui_rom_00403CA4 = func_uvgui_rom_00403CA4;
    exports->func_uvgui_rom_00403CAC = func_uvgui_rom_00403CAC;
    exports->func_uvgui_rom_00403E78 = func_uvgui_rom_00403E78;
    exports->uvGuiDestroy = uvGuiDestroy;
    exports->func_uvgui_rom_00401D80 = func_uvgui_rom_00401D80;
    exports->func_uvgui_rom_00401DC4 = func_uvgui_rom_00401DC4;
    exports->func_uvgui_rom_004020A0 = func_uvgui_rom_004020A0;
    exports->func_uvgui_rom_0040221C = func_uvgui_rom_0040221C;
    exports->func_uvgui_rom_00402268 = func_uvgui_rom_00402268;
    exports->func_uvgui_rom_00403EB8 = func_uvgui_rom_00403EB8;
    exports->func_uvgui_rom_00402308 = func_uvgui_rom_00402308;
    exports->func_uvgui_rom_00403EE0 = func_uvgui_rom_00403EE0;
    exports->func_uvgui_rom_004023A8 = func_uvgui_rom_004023A8;
    exports->func_uvgui_rom_00403F08 = func_uvgui_rom_00403F08;
    exports->uvGuiInitMenus = uvGuiInitMenus;
    exports->func_uvgui_rom_00403F2C = func_uvgui_rom_00403F2C;
    exports->uvGuiNewMenu = uvGuiNewMenu;
    exports->func_uvgui_rom_00404010 = func_uvgui_rom_00404010;
    exports->uvGuiGetMenu = uvGuiGetMenu;
    exports->func_uvgui_rom_0040404C = func_uvgui_rom_0040404C;
    exports->func_uvgui_rom_00404054 = func_uvgui_rom_00404054;
    exports->func_uvgui_rom_004046B4 = func_uvgui_rom_004046B4;
    exports->func_uvgui_rom_00405CEC = func_uvgui_rom_00405CEC;
    exports->uvGuiProps = uvGuiProps;
    exports->uvGuiSetMenuTitle = uvGuiSetMenuTitle;
    exports->func_uvgui_rom_0040277C = func_uvgui_rom_0040277C;
    exports->uvGuiSetMenuPosition = uvGuiSetMenuPosition;
    exports->uvGuiAddMenuOption = uvGuiAddMenuOption;
    exports->func_uvgui_rom_00405D78 = func_uvgui_rom_00405D78;
    exports->uvGuiRenderMenu = uvGuiRenderMenu;
    exports->func_uvgui_rom_00405F20 = func_uvgui_rom_00405F20;
    exports->func_uvgui_rom_0040293C = func_uvgui_rom_0040293C;
    exports->func_uvgui_rom_00405F60 = func_uvgui_rom_00405F60;
    exports->uvGuiInitMenuOptions = uvGuiInitMenuOptions;
    exports->func_uvgui_rom_00405F90 = func_uvgui_rom_00405F90;
    exports->uvGuiNewMenuOption = uvGuiNewMenuOption;
    exports->func_uvgui_rom_00405FC0 = func_uvgui_rom_00405FC0;
    exports->uvGuiGetMenuOption = uvGuiGetMenuOption;
    exports->func_uvgui_rom_00406024 = func_uvgui_rom_00406024;
    exports->uvGuiSetMenuOptionName = uvGuiSetMenuOptionName;
#ifdef __sgi
#line 1
#endif
    sUvFMtxExports = uvLoadModule('FMTX');
    sUvFontExports = uvLoadModule('FONT');
    sUvGfxMgrExports = uvLoadModule('GMGR');
    sUvGfxStateExports = uvLoadModule('STAT');
    sUvDGeomExports = uvLoadModule('DGEO');
    sUvGrphExports = uvLoadModule('grph');
    sUvStringExports = uvLoadModule('STRG');
    sUvContExports = uvLoadModule('CONT');
}

void uvGuiDestroy(void) {
    uvUnloadModule('FMTX');
    uvUnloadModule('FONT');
    uvUnloadModule('GMGR');
    uvUnloadModule('STAT');
    uvUnloadModule('DGEO');
    uvUnloadModule('grph');
    uvUnloadModule('CONT');
    uvUnloadModule('STRG');
}

void uvGuiInit(uvGui *gui) {
    s32 i;

    uvGuiInitializeMenuItems();
    uvGuiInitMenuOptions();
    uvGuiInitMenus();
    func_uvgui_rom_00403CAC();
    uvGuiSliderInit();
    func_uvgui_rom_00405D78();
    gui->activeMenuCount = 0;

    // clang-format off
    for (i = 0; i < 20; i++) { gui->menus[i] = NULL; }
    // clang-format on

    gui->unk54 = 0;
    gui->unk56 = sUvGfxMgrExports->uvGetScreenWidth() - 1;
    gui->unk58 = 0;
    gui->unk5A = sUvGfxMgrExports->uvGetScreenHeight() - 1;
    gui->cursorX = (s16) (sUvGfxMgrExports->uvGetScreenWidth() / 2);
    gui->cursorY = (s16) (sUvGfxMgrExports->uvGetScreenHeight() / 2);
    gui->unk68 = gui->cursorX;
    gui->unk6C = gui->cursorY;
    gui->unk74 = 0x8000;
    gui->unk78 = 0x4000;
    gui->unk7C = 0;
    gui->unk80 = 1;
    gui->unk5C = 0;
    gui->fontId = -1;
    gui->unk8A = 1;
    gui->unk8B = 1;
    gui->unk60 = 0.0f;
    gui->unk64 = 0.0f;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (!sUvContExports->uvControllerPlugged(i)) {
            break;
        }
    }
    gui->contNo = i - 1;
}

void uvGuiAddMenu(uvGui *gui, GuiMenu *menu) {
    s16 temp_a3;
    s32 i;

    for (i = 0; i < 20; i++) {
        if (gui->menus[i] == NULL) {
            break;
        }
    }

    if (i == 20) {
        return;
    }

    gui->menus[i] = menu;
    gui->activeMenuCount++;
    temp_a3 = (gui->unk5A - (i * 0xC)) - 0xC;
    uvGuiSetMenuPosition(menu, gui->unk54, gui->unk56, temp_a3, temp_a3 + 0xC);
}

void uvGuiRender(uvGui *gui) {
    s32 i;
    Mtx4F sp7C;
    Mtx4F sp3C;

    sUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, sUvGfxMgrExports->uvGetScreenWidth() - 1, 0,
                                                 sUvGfxMgrExports->uvGetScreenHeight() - 1);
    sUvFMtxExports->uvMat4SetOrtho(&sp7C, -0.5f, (f32) sUvGfxMgrExports->uvGetScreenWidth() + 0.5f,
                                   -0.5f, (f32) sUvGfxMgrExports->uvGetScreenHeight() + 0.5f);
    sUvFMtxExports->uvGfxMtxProjPushF(&sp7C);
    sUvFMtxExports->uvMat4SetIdentity(&sp3C);
    sUvFMtxExports->func_uvfmtx_rom_004029DC(&sp3C);
    sUvGfxStateExports->uvGfxStatePush();
    sUvGfxStateExports->func_uvgfxstate_rom_00401F54(0.0f, 0.0f);
    sUvGfxStateExports->uvGfxStateSetFlags(0x04800FFF);
    sUvGfxStateExports->func_uvgfxstate_rom_00401354(0x9A640000);
    if (gui->fontId >= 0) {
        sUvFontExports->uvSetFont(gui->fontId);
    }

    for (i = 0; i < gui->activeMenuCount; i++) {
        uvGuiRenderMenu(gui->menus[i]);
    }
    sUvFontExports->uvFontGenDList();
    if (((u8) gui->unk8A != 0) && (D_uvgui_rom_00406F00 == 0)) {
        uvGuiDrawCursor(gui->cursorX, gui->cursorY);
    }
    sUvGfxStateExports->uvGfxStatePop();
}

void uvGuiDrawRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 r, u8 g, u8 b, u8 a) {
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(arg0 + arg4, arg2 + arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1 - arg4, arg2 + arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1 - arg4, arg3 - arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0 + arg4, arg3 - arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtxEndPoly();
    if (r >= 0x15) {
        r = (r - 0x14);
    }
    if (g >= 0x15) {
        g = (g - 0x14);
    }
    if (b >= 0x15) {
        b = (b - 0x14);
    }
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(arg1, arg3, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0, arg3, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0 + arg4, arg3 - arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1 - arg4, arg3 - arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtxEndPoly();
    if (r >= 0x15) {
        r = (r - 0x14);
    }
    if (g >= 0x15) {
        g = (g - 0x14);
    }
    if (b >= 0x15) {
        b = (b - 0x14);
    }
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(arg0, arg2, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0 + arg4, arg2 + arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0 + arg4, arg3 - arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0, arg3, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtxEndPoly();
    if (r >= 0x15) {
        r = (r - 0x14);
    }
    if (g >= 0x15) {
        g = (g - 0x14);
    }
    if (b >= 0x15) {
        b = (b - 0x14);
    }
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(arg0, arg2, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1, arg2, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1 - arg4, arg2 + arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg0 + arg4, arg2 + arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtxEndPoly();
    if (r >= 0x15) {
        r = (r - 0x14);
    }
    if (g >= 0x15) {
        g = (g - 0x14);
    }
    if (b >= 0x15) {
        b = (b - 0x14);
    }
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(arg1, arg2, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1, arg3, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1 - arg4, arg3 - arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtx(arg1 - arg4, arg2 + arg4, 0, 0, 0, r, g, b, a);
    sUvDGeomExports->uvVtxEndPoly();
}

void uvGuiPrintCentered(s16 x0, s16 x1, s16 y0, s16 y1, u8 *str, u8 r, u8 g, u8 b, u8 a) {
    s16 pad[2];
    s16 width;
    s16 pad20;
    s16 sp1D;
    s16 y;
    s32 height;

    width = sUvFontExports->uvFontWidth(str);
    height = (s16) sUvFontExports->uvFontHeight();
    y = (y0 + ((s32) ((s16) (y1 - y0) - height) / 2)) - 1;
    sUvFontExports->uvFontColor(r, g, b, a);
    sUvFontExports->uvFontPrintStr((s16) ((x0 + ((s32) ((s16) (x1 - x0) - width) / 2)) - 1), y, str);
}

void uvGuiDrawCursor(s16 x, s16 y) {
    u8 r;
    u8 g;
    u8 b;
    static s32 sCursorFlash = 0;

    sCursorFlash = !sCursorFlash;
    if (sCursorFlash) {
        b = 255;
        g = 255;
        r = 255;
    } else {
        b = 0;
        g = 0;
        r = 0;
    }
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(x, y, 0, 0, 0, r, g, b, 127);
    sUvDGeomExports->uvVtx(x + 6, y - 13, 0, 0, 0, r, g, b, 127);
    sUvDGeomExports->uvVtx(x + 6, y - 6, 0, 0, 0, r, g, b, 127);
    sUvDGeomExports->uvVtxEndPoly();
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(x, y, 0, 0, 0, r, g, b, 127);
    sUvDGeomExports->uvVtx(x + 6, y - 6, 0, 0, 0, r, g, b, 127);
    sUvDGeomExports->uvVtx(x + 13, y - 6, 0, 0, 0, r, g, b, 127);
    sUvDGeomExports->uvVtxEndPoly();
}

void func_uvgui_rom_0040126C(uvGui *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk54 = arg1;
    arg0->unk56 = arg2;
    arg0->unk58 = arg3;
    arg0->unk5A = arg4;
}

s32 func_uvgui_rom_00401290(uvGui *arg0) {
    f32 temp_fv0_2;
    s32 i;
    s32 v0;

    if ((u8) arg0->unk8B != 0) {
        func_uvgui_rom_004016F0(arg0);
        arg0->unk8B = 0U;
    }
    arg0->unk5C = 0;
    if (sUvContExports->uvControllerButtonPress((u8) arg0->contNo, arg0->unk74) != 0) {
        arg0->unk5C = 1;
    }
    if (sUvContExports->uvControllerButtonPress((u8) arg0->contNo, arg0->unk78) != 0) {
        arg0->unk5C = 2;
    }
    arg0->unk60 = sUvContExports->uvControllerGetStick((u8) arg0->contNo, arg0->unk7C);
    arg0->unk64 = sUvContExports->uvControllerGetStick((u8) arg0->contNo, arg0->unk80);
    if (arg0->unk60 >= 0.0f) {
        v0 = 1;
    } else {
        v0 = -1;
    }
    arg0->unk60 = arg0->unk60 * (v0 * arg0->unk60);
    if (arg0->unk64 >= 0.0f) {
        v0 = 1;
    } else {
        v0 = -1;
    }
    arg0->unk64 = arg0->unk64 * (v0 * arg0->unk64);
    if (sUvContExports->uvControllerButtonPress((u8) arg0->contNo, L_JPAD) != 0) {
        arg0->unk60 -= 0.25f;
    }
    if (sUvContExports->uvControllerButtonPress((u8) arg0->contNo, R_JPAD) != 0) {
        arg0->unk60 += 0.25f;
    }
    if (D_uvgui_rom_00406F00 == 0) {
        temp_fv0_2 = sUvGfxMgrExports->func_uvgfxmgr_rom_00401004();
        arg0->unk68 = arg0->unk68 + (240.0f * arg0->unk60 * temp_fv0_2);
        arg0->unk6C = arg0->unk6C + (240.0f * arg0->unk64 * temp_fv0_2);
        if (arg0->unk68 < (arg0->unk54 + 1)) {
            arg0->unk68 = (arg0->unk54 + 1);
        } else {
            if ((arg0->unk56 - 1) < arg0->unk68) {
                arg0->unk68 = (arg0->unk56 - 1);
            }
        }
        if (arg0->unk6C < (arg0->unk58 + 1)) {
            arg0->unk6C = (arg0->unk58 + 1);
        } else {
            if ((arg0->unk5A - 1) < arg0->unk6C) {
                arg0->unk6C = (arg0->unk5A - 1);
            }
        }
        arg0->cursorX = arg0->unk68;
        arg0->cursorY = arg0->unk6C;
    }

    for (i = 0; i < arg0->activeMenuCount; i++) {
        func_uvgui_rom_0040293C(arg0->menus[i], arg0->contNo, arg0->cursorX, arg0->cursorY, arg0->unk5C,
                                arg0->unk60, arg0->unk64);
    }
    return 1;
}

void func_uvgui_rom_004015B8(uvGui *arg0, s16 arg1, s32 arg2) {
    switch (arg1) {
        case 1:
            arg0->unk74 = arg2;
            break;
        case 2:
            // FAKE
            arg1++;
            arg1--;

            arg0->unk78 = arg2;
            break;
        case 17:
            arg0->unk7C = arg2;
            break;
        case 18:
            arg0->unk80 = arg2;
            break;
        case 16:
            arg0->contNo = arg2;
            break;
        default:
            break;
    }
}

void func_uvgui_rom_00401614(uvGui *arg0, s16 uvds, s16 font) {
    arg0->uvds = uvds;
    arg0->fontId = font;
    if (uvds != -1) {
        uvLoadFile('UVDS', uvds);
    }
    sUvFontExports->uvSetFont(font);
    arg0->unk8B = 1;
}

void func_uvgui_rom_004016A0(uvGui *arg0, s8 arg1) {
    arg0->unk8A = arg1;
}

void func_uvgui_rom_004016AC(uvGui *arg0, s16 arg1, s16 arg2) {
    arg0->cursorX = arg1;
    arg0->cursorY = arg2;
    arg0->unk68 = (f32) arg0->cursorX;
    arg0->unk6C = (f32) arg0->cursorY;
}

void func_uvgui_rom_004016E0(s16 arg0) {
    D_uvgui_rom_00406F00 = arg0;
}

void func_uvgui_rom_004016F0(uvGui *arg0) {
    GuiMenu *menu;
    s16 var_s2;
    s16 two;
    s32 temp_s3;
    s32 i;
    s32 j;
    s32 k;
    s32 temp_t8;
    s32 temp_v0_2;
    s32 sp8C;
    s32 var_fp;
    s32 sp5C;
    s32 temp;
    s32 temp_t2;
    GuiMenuOption *menuOption;
    GuiMenuItem *menuItem;

    sUvFontExports->uvSetFont(arg0->fontId);
    for (i = 0; i < arg0->activeMenuCount; i++) {
        menu = arg0->menus[i];
        sp8C = menu->x0;
        for (j = 0; j < menu->unk58; j++) {
            var_fp = 0;
            menuOption = menu->options[j];
            menuOption->unk16C = sUvFontExports->uvFontWidth(menuOption->name);
            menuOption->unk20 = (s16) (sp8C - 2);
            menuOption->unk22 = (s16) (menuOption->unk20 + menuOption->unk16C + 8);
            sp8C = menuOption->unk22 + 3;
            uvGuiSetMenuOptionPosition(menuOption, menuOption->unk20, menuOption->unk22, menuOption->unk24,
                                    (s32) menuOption->unk26);

            two = 2;
            for (k = 0; k < menuOption->activeMenuItems; k++) {
                menuItem = menuOption->items[k];
                temp_v0_2 = sUvFontExports->uvFontWidth(menuItem->name);
                if (var_fp < temp_v0_2) {
                    var_fp = temp_v0_2;
                }
            }

            sp5C = var_fp / two;
            for (k = 0; k < menuOption->activeMenuItems; k++) {
                menuItem = menuOption->items[k];

                temp_v0_2 = ((menu->x1 - menu->x0) + 1); // t1
                temp_t2 = ((menu->x1 + menu->x0) / 2);
                temp_t8 = ((menuOption->unk20 + menuOption->unk22) / 2);

                temp = ((var_fp * ((temp_t8 - temp_t2) / (f32) temp_v0_2)) / 2);
                menuItem->unkE = (((temp_t8 - sp5C) - temp) - 2);
                menuItem->unk10 = (menuItem->unkE + var_fp + 4);
                func_uvgui_rom_00401D80(menuItem, menuItem->unkE, menuItem->unk10, menuItem->unk12,
                                        menuItem->unk14);
                if (menuItem->unk30 != 0) {
                    if (menuOption->unk22 < (sUvGfxMgrExports->uvGetScreenWidth() / 2)) {
                        var_s2 = (arg0->unk56 - menuItem->unk10) - 0x14;
                        if (var_s2 < 0x28) {
                            var_s2 = 0x28;
                        } else if (var_s2 >= 0xA1) {
                            var_s2 = 0xA0;
                        }
                        temp_s3 = sUvGfxMgrExports->uvGetScreenHeight();
                        func_uvgui_rom_00403F08(
                            menuItem->unk30, (s16) (menuItem->unk10 + 0xA),
                            (s16) (menuItem->unk10 + var_s2 + 0xA), (s16) ((temp_s3 / 2) - (var_s2 / 2)),
                            (sUvGfxMgrExports->uvGetScreenHeight() / 2) + (var_s2 / 2));
                    } else {
                        var_s2 = (menuItem->unkE - arg0->unk54) - 0x14;
                        if (var_s2 < 0x28) {
                            var_s2 = 0x28;
                        } else if (var_s2 >= 0xA1) {
                            var_s2 = 0xA0;
                        }

                        temp_s3 = sUvGfxMgrExports->uvGetScreenHeight();
                        func_uvgui_rom_00403F08(
                            menuItem->unk30, (s16) ((menuItem->unkE - var_s2) - 0xA),
                            (s16) (menuItem->unkE - 0xA), (s16) ((temp_s3 / 2) - (var_s2 / 2)),
                            (sUvGfxMgrExports->uvGetScreenHeight() / 2) + (var_s2 / 2));
                    }
                }
            }
        }
    }
}

void uvGuiInitializeMenuItems(void) {
    s32 i;

    for (i = 0; i < 120; i++) {
        sGuiMenuItems[i].unkC = 0;
        sGuiMenuItems[i].unkE = 0;
        sGuiMenuItems[i].unk10 = 0x41;
        sGuiMenuItems[i].unk12 = 0;
        sGuiMenuItems[i].unk14 = 0xC;
        sGuiMenuItems[i].unk1C = 0;
        sGuiMenuItems[i].unk20 = 0;
        sGuiMenuItems[i].unk24 = 0;
        sGuiMenuItems[i].slider = NULL;
        sGuiMenuItems[i].unk2C = 0;
        sGuiMenuItems[i].unk30 = 0;
    }
}

s16 uvGuiNewMenuItem(void) {
    s32 i;

    for (i = 0; i < 120; i++) {
        if (sGuiMenuItems[i].unkC == 0) {
            break;
        }
    }

    sGuiMenuItems[i].unkC = 1;
    return i;
}

GuiMenuItem *uvGuiGetMenuItem(s16 item) {
    return &sGuiMenuItems[item];
}

void uvGuiSetMenuItemName(GuiMenuItem *menuItem, u8 *name) {
    u8 menuName[12];
    u8 pad;
    s32 i;

    for (i = 0; i < 12; i++) {
        if (name[i] >= 'a') {
            menuName[i] = name[i] - ' ';
        } else {
            menuName[i] = name[i];
        }
    }
    _uvMediaCopy(menuItem->name, menuName, 12);
}

void func_uvgui_rom_00401D74(GuiMenuItem *arg0, s16 arg1) {
    arg0->unkC = arg1;
}

void func_uvgui_rom_00401D80(GuiMenuItem *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unkE = arg1;
    arg0->unk10 = arg2;
    arg0->unk12 = arg3;
    arg0->unk14 = arg4;
    arg0->unk18 = arg0->unk14 - arg0->unk12;
    arg0->unk16 = arg0->unk10 - arg0->unkE;
}

void func_uvgui_rom_00401DC4(GuiMenuItem *arg0) {
    u8 var_t1;
    u8 var_t0;
    u8 var_v1;
    u8 var_t2;
    s16 temp_v0;
    int s;
    GuiSlider *v1;

    temp_v0 = arg0->unkC;
    switch (temp_v0) {
        case 1:
            var_v1 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0x50;
            break;
        case 2:
            var_v1 = 0xFF;
            var_t0 = 0xFF;
            var_t1 = 0xFF;
            var_t2 = 0xFF;
            break;
        case 3:
            var_v1 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0xFF;
            break;
        case 4:
            var_v1 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0x40;
            break;
        default:
            return;
    }

    uvGuiDrawRect(arg0->unkE, arg0->unk10, arg0->unk12, arg0->unk14, 2, var_t1, var_t0,
                            var_v1, var_t2);

    temp_v0 = arg0->unkC;
    switch (temp_v0) { /* irregular */
        case 1:
            var_t1 = 0xFF;
            var_t0 = 0xFF;
            var_v1 = 0xFF;
            var_t2 = 0xC8;
            break;
        case 2:
            var_t1 = 0;
            var_t0 = 0;
            var_v1 = 0;
            var_t2 = 0xFF;
            break;
        case 3:
            var_t1 = 0;
            var_t0 = 0xFF;
            var_v1 = 0;
            var_t2 = 0xFF;
            break;
        case 4:
            var_t1 = 0xFF;
            var_t0 = 0;
            var_v1 = 0;
            var_t2 = 0xFF;
            break;
    }
    uvGuiPrintCentered(arg0->unkE, arg0->unk10, arg0->unk12, arg0->unk14, arg0->name, var_t1,
                            var_t0, var_v1, var_t2);

    if (arg0->slider != NULL) {
        v1 = arg0->slider;
        if (arg0->unkC == 3) {
            if (v1->state == 1) {
                func_uvgui_rom_00403C50(v1, 2);
                func_uvgui_rom_004016E0(1);
            } else {
                func_uvgui_rom_00403C50(v1, 1);
                func_uvgui_rom_004016E0(0);
            }
        }
        if (arg0->unkC == 2) {
            uvGuiDrawSlider(arg0->slider);
        }
    }

    if (arg0->unk2C != NULL) {
        Inner2C *v1 = arg0->unk2C;
        if (arg0->unkC == 3) {
            if (v1->unk1E == 1) {
                func_uvgui_rom_00406E28(v1, 2);
                func_uvgui_rom_004016E0(1);
            } else {
                func_uvgui_rom_00406E28(v1, 1);
                func_uvgui_rom_004016E0(0);
            }
        }
        if (arg0->unkC == 2) {
            func_uvgui_rom_00406048(arg0->unk2C);
        }
    }

    if (arg0->unk30 != NULL) {
        Inner30 *v1 = arg0->unk30;
        if (arg0->unkC == 3) {
            if (arg0->unk30->unk5E == 1) {
                func_uvgui_rom_00405CEC(v1, 2);
                func_uvgui_rom_004016E0(1);
            } else {
                func_uvgui_rom_00405CEC(v1, 1);
                func_uvgui_rom_004016E0(0);
            }
        }
        if (arg0->unkC == 2) {
            func_uvgui_rom_004046B4(arg0->unk30);
        }
    }
}

s32 func_uvgui_rom_004020A0(GuiMenuItem *arg0, u8 arg1, s16 arg2, s16 arg3, s32 arg4,
                            f32 arg5, f32 arg6) {
    if (arg0->slider != NULL) {
        func_uvgui_rom_004038E4(arg0->slider, arg1, arg5);
    }
    if (arg0->unk30 != NULL) {
        func_uvgui_rom_00404054(arg0->unk30, arg1, arg5);
    }
    if (arg0->unk2C != NULL) {
        func_uvgui_rom_00406B88(arg0->unk2C, arg1, arg5);
    }
    if (arg2 < arg0->unkE) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg0->unk10 < arg2) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg3 < arg0->unk12) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg0->unk14 < arg3) {
        arg0->unkC = 1;
        return 0;
    }
    if (arg4 & 1) {
        arg0->unkC = 3;
        if (arg0->unk20 != NULL) {
            arg0->unk20(arg0);
        }
    } else if (arg4 & 2) {
        arg0->unkC = 4;
        if (arg0->unk24 != NULL) {
            arg0->unk24(arg0);
        }
    } else {
        arg0->unkC = 2;
        if (arg0->unk1C != NULL) {
            arg0->unk1C(arg0);
        }
    }
    return 1;
}

void func_uvgui_rom_0040221C(GuiMenuItem *arg0, s16 arg1, UvGuiCallback routine) {
    switch (arg1) { /* irregular */
        case 2:
            arg0->unk1C = routine;
            return;
        case 3:
            arg0->unk20 = routine;
            return;
        case 4:
            arg0->unk24 = routine;
            return;
    }
}

void func_uvgui_rom_00402268(GuiMenuItem *item, GuiSlider *itemSlider) {
    item->slider = itemSlider;
    uvGuiSliderSetRect(itemSlider, (s16) ((sUvGfxMgrExports->uvGetScreenWidth() / 2) - 0x5A),
                            (s16) ((sUvGfxMgrExports->uvGetScreenWidth() / 2) + 0x5A), 0x16, 0x30);
}

void func_uvgui_rom_00402308(GuiMenuItem *item, Inner2C *arg1) {
    item->unk2C = arg1;
    func_uvgui_rom_00406024(arg1, (s16) ((sUvGfxMgrExports->uvGetScreenWidth() / 2) - 0x5A),
                            (s16) ((sUvGfxMgrExports->uvGetScreenWidth() / 2) + 0x5A), 0x16, 0x52);
}

void func_uvgui_rom_004023A8(GuiMenuItem *arg0, Inner30 *arg1) {
    arg0->unk30 = arg1;
    if (arg0->unk10 < (sUvGfxMgrExports->uvGetScreenWidth() / 2)) {
        func_uvgui_rom_00403F08(arg1, (arg0->unk10 + 0xA), (arg0->unk10 + 0xAA),
                                ((sUvGfxMgrExports->uvGetScreenHeight() / 2) - 0x50),
                                (sUvGfxMgrExports->uvGetScreenHeight() / 2) + 0x50);
        return;
    }
    if ((sUvGfxMgrExports->uvGetScreenWidth() / 2) < arg0->unkE) {
        func_uvgui_rom_00403F08(arg1, (arg0->unkE - 0xAA), (arg0->unkE - 0xA),
                                ((sUvGfxMgrExports->uvGetScreenHeight() / 2) - 0x50),
                                (sUvGfxMgrExports->uvGetScreenHeight() / 2) + 0x50);
        return;
    }
    func_uvgui_rom_00403F08(arg1, ((sUvGfxMgrExports->uvGetScreenWidth() / 2) - 0x50),
                            ((sUvGfxMgrExports->uvGetScreenWidth() / 2) + 0x50),
                            ((sUvGfxMgrExports->uvGetScreenHeight() / 2) - 0x50),
                            (sUvGfxMgrExports->uvGetScreenHeight() / 2) + 0x50);
}

void uvGuiInitMenus(void) {
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(sGuiMenus); i++) {
        sGuiMenus[i].unk1E = 0;
        for (j = 0; j < MAX_MENU_OPTIONS; j++) {
            sGuiMenus[i].options[j] = NULL;
        }
        sGuiMenus[i].unk58 = 0;
        sGuiMenus[i].unk5A = -1;
    }
}

s16 uvGuiNewMenu(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (sGuiMenus[i].unk1E == 0) {
            break;
        }
    }

    if (i == 8) {
        return -1;
    }

    sGuiMenus[i].unk1E = 1;
    return i;
}

GuiMenu *uvGuiGetMenu(s16 id) {
    return &sGuiMenus[id];
}

void uvGuiSetMenuTitle(GuiMenu *menu, u8 *title) {
    u8 menuTitle[30];
    s32 i;

    for (i = 0; i < 30; i++) {
        if (title[i] >= 'a') {
            menuTitle[i] = title[i] - ' ';
        } else {
            menuTitle[i] = title[i];
        }
    }
    _uvMediaCopy(menu->title, menuTitle, 30);
}

void func_uvgui_rom_0040277C(GuiMenu *arg0, s16 arg1) {
    arg0->unk1E = arg1;
}

void uvGuiSetMenuPosition(GuiMenu *menu, s16 x0, s16 x1, s16 y0, s16 y1) {
    menu->x0 = x0;
    menu->x1 = x1;
    menu->y0 = y0;
    menu->y1 = y1;
}

void uvGuiAddMenuOption(GuiMenu *menu, GuiMenuOption *menuOption) {
    s16 temp_a1;
    s32 i;
    s16 a3;
    s16 a2;

    for (i = 0; i < 12; i++) {
        if (menu->options[i] == NULL) {
            break;
        }
    }
    if (i == 12) {
        return;
    }

    menu->options[i] = menuOption;
    menu->unk58++;
    a3 = menu->y1;
    a2 = menu->y0;
    temp_a1 = (menu->x0 + (i * 0x44) + 6);
    uvGuiSetMenuOptionPosition(menuOption, temp_a1, temp_a1 + 0x41, a2, a3);
}

void uvGuiRenderMenu(GuiMenu *menu) {
    s32 i;

    uvGuiDrawRect(menu->x0, menu->x1, menu->y0, menu->y1, 3, 0x2C, 0x94, 0xFF, 0xFF);
    if (menu->unk1E != 2) {
        uvGuiPrintCentered(menu->x0, menu->x1, menu->y0, menu->y1, menu->title, 0xFF, 0xFF, 0xFF, 0xFF);
        return;
    }

    for (i = 0; i < menu->unk58; i++) {
        uvGuiRenderMenuOption(menu->options[i]);
    }
}

s32 func_uvgui_rom_0040293C(GuiMenu *arg0, u8 arg1, s16 arg2, s16 arg3, s32 arg4, f32 arg5,
                            f32 arg6) {
    GuiMenu *var_s0;
    s32 i;
    s32 matchFound;

    if (arg0->unk1E == 2) {
        matchFound = -1;
        for (i = 0; i < arg0->unk58; i++) {
            if (func_uvgui_rom_00402E48(arg0->options[i], arg1, arg2, arg3, arg4, arg5, arg6) != 0) {
                matchFound = i;
            }
        }
        if (i == arg0->unk58) {
            arg0->unk5A = matchFound;
        }
    } else {
        arg0->unk5A = -1;
    }
    if (arg0->unk5A >= 0) {
        return 1;
    }
    if (arg2 < arg0->x0) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg0->x1 < arg2) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg3 < arg0->y0) {
        arg0->unk1E = 1;
        return 0;
    }
    if (arg0->y1 < arg3) {
        arg0->unk1E = 1;
        return 0;
    }
    arg0->unk1E = 2;
    return 1;
}

void uvGuiInitMenuOptions(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 50; i++) {
        sGuiMenuOptions[i].unk1E = 0;
        for (j = 0; j < 80; j++) {
            sGuiMenuOptions[i].items[j] = NULL;
        }
        sGuiMenuOptions[i].activeMenuItems = 0;
        sGuiMenuOptions[i].unk16A = -1;
    }
}

s16 uvGuiNewMenuOption(void) {
    s32 i;

    for (i = 0; i < 50; i++) {
        if (sGuiMenuOptions[i].unk1E == 0) {
            break;
        }
    }

    sGuiMenuOptions[i].unk1E = 1;
    return i;
}

GuiMenuOption *uvGuiGetMenuOption(s16 option) {
    return &sGuiMenuOptions[option];
}

void uvGuiSetMenuOptionName(GuiMenuOption *option, u8 *name) {
    u8 menuOptionName[MAX_MENU_OPTION_NAME_LEN];
    s32 i;

    for (i = 0; i < MAX_MENU_OPTION_NAME_LEN; i++) {
        if (name[i] >= 'a') {
            menuOptionName[i] = name[i] - ' ';
        } else {
            menuOptionName[i] = name[i];
        }
    }
    _uvMediaCopy(option->name, menuOptionName, MAX_MENU_OPTION_NAME_LEN);
}

void func_uvgui_rom_00402C34(GuiMenuOption *arg0, s16 arg1) {
    arg0->unk1E = arg1;
}

void uvGuiSetMenuOptionPosition(GuiMenuOption *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk20 = arg1;
    arg0->unk22 = arg2;
    arg0->unk24 = arg3;
    arg0->unk26 = arg4;
    arg0->unk16C = arg0->unk22 - arg0->unk20;
}

void uvGuiAddMenuItem(GuiMenuOption *menuOption, GuiMenuItem *menuItem) {
    s16 temp_t0;
    s32 i;

    for (i = 0; i < 80; i++) {
        if (menuOption->items[i] == NULL) {
            break;
        }
    }

    if (i == 80) {
        return;
    }

    menuOption->items[i] = menuItem;
    menuOption->activeMenuItems++;
    temp_t0 = menuOption->unk24 - (i * 0xC);
    func_uvgui_rom_00401D80(menuItem, menuOption->unk20, (s16) (menuOption->unk20 + 0x40), (temp_t0 - 0xB), temp_t0);
}

void uvGuiRenderMenuOption(GuiMenuOption *menuOption) {
    s32 i;
    s32 color;

    switch (menuOption->unk1E) {
        case 1:
            color = 0x7F;
            break;
        case 2:
            color = 0xFF;
            break;
        default:
            return;
    }
    
    uvGuiDrawRect(menuOption->unk20, menuOption->unk22, menuOption->unk24, menuOption->unk26, 2, 0xD5, 0xD7, 0x25, color);
    switch (menuOption->unk1E) {
        case 1:
            color = 0xFF;
            break;
        case 2:
            color = 0;
            break;
        default:
            return;
    }
    uvGuiPrintCentered(menuOption->unk20, menuOption->unk22, menuOption->unk24, menuOption->unk26, menuOption->name, color, 0, 0, 0xFF);
    if (menuOption->unk1E != 1) {
        for (i = 0; i < menuOption->activeMenuItems; i++) {
            func_uvgui_rom_00401DC4(menuOption->items[i]);
        }
    }
}

s32 func_uvgui_rom_00402E48(GuiMenuOption *menuOption, u8 arg1, s16 arg2, s16 arg3, s32 arg4, f32 arg5,
                            f32 arg6) {
    s32 i;
    s32 var_s3;
    s16 var_v0;

    if (menuOption->unk1E == 2) {
        var_s3 = -1;
        for (i = 0; i < menuOption->activeMenuItems; i++) {
            if (func_uvgui_rom_004020A0(menuOption->items[i], arg1, arg2, arg3, arg4, arg5, arg6) != 0) {
                var_s3 = i;
            }
        }
        if (i == menuOption->activeMenuItems) {
            menuOption->unk16A = var_s3;
        }
    } else {
        menuOption->unk16A = -1;
    }
    if (menuOption->unk16A >= 0) {
        return 1;
    }
    if (arg2 < menuOption->unk20) {
        menuOption->unk1E = 1;
        return 0;
    }
    if (menuOption->unk22 < arg2) {
        menuOption->unk1E = 1;
        return 0;
    }
    if (arg3 < menuOption->unk24) {
        menuOption->unk1E = 1;
        return 0;
    }
    if (menuOption->unk26 < arg3) {
        menuOption->unk1E = 1;
        return 0;
    }
    menuOption->unk1E = 2;
    return 1;
}

void uvGuiSliderInit(void) {
    GuiSlider *slider;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sGuiSliders); i++) {
        slider = &sGuiSliders[i];
        slider->state = 0;
        slider->mode = 0x11;
        slider->unk30 = 1.0f;
        slider->unk34 = -1.0f;
        slider->unk28 = 0.0f;
        slider->unk24 = 0.0f;
        slider->unk2C = 0;
        slider->unk44 = 0;
        uvGuiSliderSetRect(slider, (s16) ((s32) (sUvGfxMgrExports->uvGetScreenWidth() - 0xB4) / 2),
                                (s16) ((s32) (sUvGfxMgrExports->uvGetScreenWidth() + 0xB4) / 2),
                                (s16) ((sUvGfxMgrExports->uvGetScreenHeight() - 0x28) / 2),
                                (sUvGfxMgrExports->uvGetScreenHeight() + 0x28) / 2);
        slider->callback = NULL;
    }
}

s16 uvGuiSliderNew(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sGuiSliders); i++) {
        if (sGuiSliders[i].state == 0) {
            break;
        }
    }
    sGuiSliders[i].state = 1;
    return i;
}

void uvGuiSliderFree(s16 slider) {
    sGuiSliders[slider].state = 0;
}

GuiSlider *uvGuiGetSlider(s16 slider) {
    return &sGuiSliders[slider];
}

void uvGuiSliderSetLabel(GuiSlider *slider, u8 *label) {
    u8 sliderLabel[30];
    s32 i;

    for (i = 0; i < 30; i++) {
        if (label[i] >= 'a') {
            sliderLabel[i] = label[i] - ' ';
        } else {
            sliderLabel[i] = label[i];
        }
    }
    _uvMediaCopy(slider->label, sliderLabel, 30);
}

void uvGuiSliderSetRect(GuiSlider *slider, s16 x0, s16 x1, s16 y0, s16 y1) {
    slider->x0 = x0;
    slider->x1 = x1;
    slider->y0 = y0;
    slider->y1 = y1;
}

void uvGuiDrawSlider(GuiSlider *slider) {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s16 sliderX0;
    s16 sliderX1;
    s16 sliderY0;
    s16 sliderY1;
    s16 temp_a0;
    f32 var_fa0;
    s16 pad6A;
    s16 width;
    u8 sliderText[24];
    s32 temp_v0_4;

    if (slider->unk2C != 0) {
        if (slider->mode & 2) {
            if ((*slider->unk2C) < slider->unk28) {
                var_fa0 = slider->unk28 - (*slider->unk2C);
            } else {
                var_fa0 = -(slider->unk28 - (*slider->unk2C));
            }
            if (var_fa0 > 1.0f) {
                if (slider->unk28 >= 0.0f) {
                    slider->unk28 = *slider->unk2C;
                } else {
                    slider->unk28 = *slider->unk2C;
                }
            }
        } else {
            slider->unk28 = *((f32 *) slider->unk2C);
        }
        if (slider->unk28 >= 0.0f) {
            slider->unk24 = (f32) ((s32) (slider->unk28 + 0.5f));
        } else {
            slider->unk24 = (f32) ((s32) (slider->unk28 - 0.5f));
        }
    }
    switch (slider->state) {
        case SLIDER_STATE_RENDER:
            r = 0xD5;
            g = 0xD7;
            b = 0x25;
            a = 0xFF;
            break;
        case SLIDER_STATE_ACTIVE:
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
            a = 0xFF;
            break;
        default:
            break;
    }
    uvGuiDrawRect(slider->x0, slider->x1, slider->y0, slider->y1, 2, r, g, b, a);
    sliderX0 = slider->x0 + 5;
    sliderX1 = slider->x1 - 5;
    sliderY0 = (slider->y0 + (((s32) (slider->y1 - slider->y0)) / 5)) + 5;
    sliderY1 = slider->y1 - 5;
    if (slider->state == 2) {
        uvGuiDrawRect(sliderX0, sliderX1, sliderY0, sliderY1, 2, 50, 50, 50, 255);
    }
    if (slider->unk34 != slider->unk30) {
        var_fa0 = (slider->unk28 - slider->unk30) / (slider->unk34 - slider->unk30);
    } else {
        var_fa0 = 0.5f;
    }
    if (slider->mode & 2) {
        temp_v0_4 = ((s32) slider->unk34) - ((s32) slider->unk30);
        if (temp_v0_4 > 0) {
            var_fa0 = ((f32) ((s32) ((temp_v0_4 * var_fa0) + 0.5f))) / temp_v0_4;
        } else {
            var_fa0 = 0.5f;
        }
    }
    if (slider->state == 2) {
        b = 0xFF;
        g = 0xFF;
        r = 0xFF;
        a = 0xFF;
        // FAKE
        if (1) {
        }
    } else {
        b = 0;
        g = 0;
        r = 0;
        a = 0x50;
    }
    temp_a0 = (s32) (((f32) ((s16) ((sliderX1 - sliderX0) - 0xC))) * var_fa0);
    temp_a0 = (sliderX0 + temp_a0) + 3;
    uvGuiDrawRect(temp_a0, temp_a0 + 6, sliderY0 + 2, sliderY1 - 2, 2, r, g, b,
                            a);
    if ((slider->unk44 != 0) && (slider->mode & 2)) {
        uvGuiSliderSetLabel(slider, slider->unk44[(s32) slider->unk24]);
    }
    sUvFontExports->uvFontWidth(slider->label);
    sUvFontExports->uvFontColor(0, 0, 0, 255);
    sUvFontExports->uvFontPrintStr(slider->x0 + 7, slider->y0 + 2, slider->label);
    if (slider->mode & 0x10) {
        if (slider->mode & 1) {
            sUvStringExports->uvSprintf(sliderText, "%f", slider->unk28);
        }
        if (slider->mode & 2) {
            sUvStringExports->uvSprintf(sliderText, "%d", (s32) slider->unk24);
        }
        width = sUvFontExports->uvFontWidth(sliderText);
        sUvFontExports->uvFontColor(0, 0, 0, 255);
        sUvFontExports->uvFontPrintStr((slider->x1 - width) - 7, slider->y0 + 2, sliderText);
    }
}

void func_uvgui_rom_004037D8(GuiSlider *arg0, s32 arg1) {
    arg0->callback = arg1;
}

void func_uvgui_rom_004037E0(GuiSlider *arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4);

void func_uvgui_rom_004037E0(GuiSlider *arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4) {
    f32 temp_fv0;

    arg0->unk30 = arg1;
    arg0->unk2C = arg4;
    arg0->unk34 = arg2;
    if (arg0->unk2C != NULL) {
        if (arg0->mode & 2) {
            arg0->unk28 = *arg0->unk2C;
        } else {
            arg0->unk28 = *(f32 *) arg0->unk2C;
        }
    } else {
        arg0->unk28 = arg3;
    }

    if (arg0->mode & 2) {
        if (arg0->unk28 >= 0.0f) {
            arg0->unk24 = (s32) (arg0->unk28 + 0.5f);
        } else {
            arg0->unk24 = (s32) (arg0->unk28 - 0.5f);
        }
    } else {
        arg0->unk24 = arg0->unk28;
    }
}

void func_uvgui_rom_004038D8(GuiSlider *arg0, s16 arg1) {
    arg0->mode = arg1;
}

void func_uvgui_rom_004038E4(GuiSlider *arg0, u8 arg1, f32 arg2) {
    f32 temp_ft4;
    f32 var_fv1;
    f32 var_fv0;

    if (arg0->state != 2) {
        return;
    }
    if ((arg0->unk2C != 0) && (!(arg0->mode & 2))) {
        arg0->unk28 = *((f32 *) arg0->unk2C);
    }
    temp_ft4 = (arg0->unk34 - arg0->unk30) * 0.5f;
    var_fv1 = sUvGfxMgrExports->func_uvgfxmgr_rom_00401004();
    if (arg2 > 0.0f) {
        arg2 *= arg2;
    } else {
        arg2 *= -arg2;
    }
    if (arg0->mode == 0x11) {
        arg0->unk28 += ((0.5f * arg2) * temp_ft4) * var_fv1;
        if (arg0->unk28 < arg0->unk30) {
            arg0->unk28 = arg0->unk30;
        } else if (arg0->unk28 > arg0->unk34) {
            arg0->unk28 = arg0->unk34;
        }
        arg0->unk24 = arg0->unk28;
    } else {
        var_fv0 = 20.0f / (arg0->unk34 - arg0->unk30);
        if (var_fv0 < 1.0f) {
            var_fv0 = 1.0f;
        } else if (var_fv0 > 100.0f) {
            var_fv0 = 100.0f;
        }
        var_fv0 = (((var_fv0 * 0.5f) * arg2) * temp_ft4) * var_fv1;
        if (sUvContExports->uvControllerButtonPress(arg1, L_JPAD) != 0) {
            var_fv0 = -1.0f;
        }
        if (sUvContExports->uvControllerButtonPress(arg1, R_JPAD) != 0) {
            var_fv0 = 1.0f;
        }
        arg0->unk28 += var_fv0;
        if (arg0->unk28 < arg0->unk30) {
            arg0->unk28 = arg0->unk30;
        } else if (arg0->unk28 > arg0->unk34) {
            arg0->unk28 = arg0->unk34;
        }
        arg0->unk24 = ROUNDF(arg0->unk28);
    }
    if (arg0->unk2C != 0) {
        if (arg0->mode & 2) {
            *arg0->unk2C = ROUNDF(arg0->unk28);
        } else {
            *((f32 *) arg0->unk2C) = arg0->unk28;
        }
    }
    if (arg0->callback != NULL) {
        arg0->callback(arg0);
    }
}

void func_uvgui_rom_00403C50(GuiSlider *arg0, s16 arg1) {
    if (arg1 != arg0->state) {
        if (arg0->callback != NULL) {
            arg0->callback(arg0);
        }
    }
    arg0->state = arg1;
}

void func_uvgui_rom_00403CA4(GuiSlider *arg0, s32 arg1) {
    arg0->unk44 = arg1;
}

void func_uvgui_rom_00403CAC(void) {
    Inner30 *var_s0;
    s32 i;

    for (i = 0; i < 20; i++) {
        var_s0 = &D_uvgui_rom_0040FB50[i];
        var_s0->unk5E = 0;
        var_s0->unk68 = 0.0f;
        var_s0->unk6C = -1.0f;
        var_s0->unk70 = 1.0f;
        var_s0->unk80 = 0;
        var_s0->unk74 = 0.0f;
        var_s0->unk78 = -1.0f;
        var_s0->unk7C = 1.0f;
        var_s0->unk60 = -1;
        var_s0->unk62 = 1;
        func_uvgui_rom_00403F08(var_s0, ((sUvGfxMgrExports->uvGetScreenWidth() / 2) - 0x50),
                                ((sUvGfxMgrExports->uvGetScreenWidth() / 2) + 0x50),
                                ((sUvGfxMgrExports->uvGetScreenHeight() / 2) - 0x50),
                                (sUvGfxMgrExports->uvGetScreenHeight() / 2) + 0x50);
        var_s0->unk8C = 0;
        func_uvgui_rom_00403F2C(var_s0, "INPUT", "OUTPUT");
    }
}

s16 func_uvgui_rom_00403E78(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (D_uvgui_rom_0040FB50[i].unk5E == 0) {
            break;
        }
    }
    D_uvgui_rom_0040FB50[i].unk5E = 1;
    return i;
}

void func_uvgui_rom_00403EB8(s16 arg0) {
    D_uvgui_rom_0040FB50[arg0].unk5E = 0;
}

Inner30 *func_uvgui_rom_00403EE0(s16 arg0) {
    return &D_uvgui_rom_0040FB50[arg0];
}

void func_uvgui_rom_00403F08(Inner30 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk84 = arg1;
    arg0->unk86 = arg2;
    arg0->unk88 = arg3;
    arg0->unk8A = arg4;
}

void func_uvgui_rom_00403F2C(Inner30 *arg0, u8 *arg1, u8 *arg2) {
    u8 sp30[0x1E];
    s32 i;

    sUvStringExports->uvSprintf(arg0->unk40, "%s_vs_%s", arg1, arg2);
    for (i = 0; i < 0x1E; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }
    _uvMediaCopy(arg0->unk4, sp30, 0x1EU);
    for (i = 0; i < 0x1E; i++) {
        if (arg2[i] >= 'a') {
            sp30[i] = arg2[i] - ' ';
        } else {
            sp30[i] = arg2[i];
        }
    }
    _uvMediaCopy(arg0->unk22, sp30, 0x1EU);
}

void func_uvgui_rom_00404010(Inner30 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5) {
    arg0->unk0 = arg1;
    arg0->unk6C = arg2;
    arg0->unk80 = arg5;
    arg0->unk70 = arg3;
    if (arg5 != NULL) {
        arg0->unk68 = *arg5;
        return;
    }
    arg0->unk68 = arg4;
}

void func_uvgui_rom_0040404C(Inner30 *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}

void func_uvgui_rom_00404054(Inner30 *arg0, u8 button, f32 arg2) {
    UvGrphInnerStruct *temp_t1;
    UvGrphInnerStruct *var_t2;
    UvGrphInnerStruct *var_t0;
    UvGrphStruct *sp38;
    f32 var_fa0_2;
    f32 temp_fv1;
    f32 var_fa1;
    f32 sp28;
    f32 sp24;
    s32 i;

    if ((arg0->unk0 == NULL) || (arg0->unk5E != 2)) {
        arg0->unk60 = -1;
        return;
    }
    sp38 = arg0->unk0;
    // FAKE: Increase compiler stack for arg1
    if (button) {
    }

    if (sUvContExports->uvControllerButtonPress(button, START_BUTTON) != 0) {
        sUvGrphExports->func_uvgrph_rom_00400148(arg0->unk40, &sp38->count);
        arg0->unk64 = 0x3C;
    }
    sp28 = (arg0->unk70 - arg0->unk6C) * 0.5f;
    sp24 = sUvGfxMgrExports->func_uvgfxmgr_rom_00401004();
    if (arg0->unk80 != NULL) {
        arg0->unk68 = *arg0->unk80;
    }
    if (arg2 > 0.0f) {
        arg2 *= arg2;
    } else {
        arg2 *= -arg2;
    }
    if (arg0->unk62) {
        arg0->unk68 += 0.5f * arg2 * sp28 * sp24;
        if (arg0->unk68 < arg0->unk6C) {
            arg0->unk68 = arg0->unk6C;
        } else {
            if (arg0->unk70 < arg0->unk68) {
                arg0->unk68 = arg0->unk70;
            }
        }

        // FAKE
        if (1) {
        }
    }

    if (arg0->unk80 != NULL) {
        *arg0->unk80 = arg0->unk68;
    }
    if (sUvContExports->uvControllerButtonHeld(button, Z_TRIG) != 0) {
        if (sUvContExports->uvControllerButtonPress(button, L_CBUTTONS) != 0) {
            arg0->unk60 -= 1;
            if (arg0->unk60 < 0) {
                arg0->unk60 = sp38->count - 1;
            }
        }
        if (sUvContExports->uvControllerButtonPress(button, R_CBUTTONS) != 0) {
            arg0->unk60 += 1;
            if (arg0->unk60 >= sp38->count) {
                arg0->unk60 = 0;
            }
        }
        if (sUvContExports->uvControllerButtonPress(button, U_CBUTTONS) != 0) {
            arg0->unk60 = sUvGrphExports->func_uvgrph_rom_00400194(sp38, (s32) arg0->unk60);
        }
        if (sUvContExports->uvControllerButtonPress(button, D_CBUTTONS) != 0) {
            arg0->unk60 = sUvGrphExports->func_uvgrph_rom_004002AC(sp38, (s32) arg0->unk60);
        }
        if (arg0->unk60 == -1) {
            return;
        }
    }

    temp_t1 = &sp38->arr[arg0->unk60];
    if (arg0->unk60 < (sp38->count - 1)) {
        var_t2 = &sp38->arr[arg0->unk60 + 1];
    } else {
        var_t2 = NULL;
    }
    if (arg0->unk60 >= 2) {
        var_t0 = &sp38->arr[arg0->unk60 - 1];
    } else {
        var_t0 = NULL;
    }

    var_fa0_2 = sp38->arr->x;
    temp_fv1 = sp38->arr[sp38->count - 1].x;
    if (sUvContExports->uvControllerButtonHeld(button, Z_TRIG) == 0) {
        if (sUvContExports->uvControllerButtonHeld(button, L_CBUTTONS) != 0) {
            temp_t1->x -= (temp_fv1 - var_fa0_2) * 0.0025f;
            if (var_t0 != NULL) {
                if (temp_t1->x < var_t0->x) {
                    temp_t1->x = var_t0->x;
                }
            }
        }
        if (sUvContExports->uvControllerButtonHeld(button, R_CBUTTONS) != 0) {
            temp_t1->x += (temp_fv1 - var_fa0_2) * 0.0025f;
            if (var_t2 != NULL) {
                if (var_t2->x < temp_t1->x) {
                    temp_t1->x = var_t2->x;
                }
            }
        }
        var_fa0_2 = 1000000.0f;
        for (i = 0; i < sp38->count; i++) {
            if (sp38->arr[i].y < var_fa0_2) {
                var_fa0_2 = sp38->arr[i].y;
            }
        }
        temp_fv1 = -1000000.0f;
        for (i = 0; i < sp38->count; i++) {
            if (temp_fv1 < sp38->arr[i].y) {
                temp_fv1 = sp38->arr[i].y;
            }
        }

        var_fa1 = (temp_fv1 - var_fa0_2) * 0.15f * sp24;
        if (var_fa1 < 0.005f) {
            var_fa1 = 0.005f;
        } else if (var_fa1 > 10.0f) {
            var_fa1 = 10.0f;
        }
        if (sUvContExports->uvControllerButtonHeld(button, D_CBUTTONS) != 0) {
            temp_t1->y -= var_fa1;
        }
        if (sUvContExports->uvControllerButtonHeld(button, U_CBUTTONS) != 0) {
            temp_t1->y += var_fa1;
        }
    }

    if (arg0->unk8C != NULL) {
        arg0->unk8C(arg0);
    }
}

void func_uvgui_rom_004046B4(Inner30 *arg0) {
    UvGrphStruct *sp1D4;
    f32 spA4;
    f32 temp_fa1;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs3;
    f32 temp_fs5;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    UvGrphInnerStruct *s0;
    f32 sp194;
    u8 var_s6;
    u8 sp192;
    u8 var_s5;
    u8 sp190;
    Mtx4F sp150;
    Mtx4F sp110;
    u8 spD4[0x3C];
    s32 i;
    UvGrphInnerStruct *var_v0;
    UvGrphInnerStruct *var_v1;
    static s32 D_uvgui_rom_00406F08 = 0;

    sp1D4 = arg0->unk0;
    if ((sp1D4 == NULL) || (sp1D4->count == 0)) {
        return;
    }

    if (arg0->unk80 != NULL) {
        arg0->unk68 = *arg0->unk80;
    }
    sUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, sUvGfxMgrExports->uvGetScreenWidth() - 1, 0,
                                                 sUvGfxMgrExports->uvGetScreenHeight() - 1);
    sUvFMtxExports->uvMat4SetOrtho(&sp150, 0.0f, (sUvGfxMgrExports->uvGetScreenWidth() - 1), 0.0f,
                                   (sUvGfxMgrExports->uvGetScreenHeight() - 1));
    sUvFMtxExports->uvGfxMtxProjPushF(&sp150);
    sUvFMtxExports->uvMat4SetIdentity(&sp110);
    sUvFMtxExports->func_uvfmtx_rom_004029DC(&sp110);
    sUvGfxStateExports->uvGfxStatePush();
    sUvGfxStateExports->uvGfxStateSetFlags(0x800FFF);
    sUvGfxStateExports->func_uvgfxstate_rom_00401354(0x600000);
    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(arg0->unk84 - 2, arg0->unk88 - 2, 0, 0, 0, 0, 0, 0, 0x7F);
    sUvDGeomExports->uvVtx(arg0->unk86 + 2, arg0->unk88 - 2, 0, 0, 0, 0, 0, 0, 0x7F);
    sUvDGeomExports->uvVtx(arg0->unk86 + 2, arg0->unk8A + 2, 0, 0, 0, 0, 0, 0, 0x7F);
    sUvDGeomExports->uvVtx(arg0->unk84 - 2, arg0->unk8A + 2, 0, 0, 0, 0, 0, 0, 0x7F);
    sUvDGeomExports->uvVtxEndPoly();
    sUvGfxStateExports->uvGfxStatePop();
    sp1A8 = sp1D4->arr->x;
    sp1A4 = sp1D4->arr[sp1D4->count - 1].x;

    sp1A0 = 1000000.0f;
    for (i = 0; i < sp1D4->count; i++) {
        if (sp1D4->arr[i].y < sp1A0) {
            sp1A0 = sp1D4->arr[i].y;
        }
    }
    sp19C = -1000000.0f;
    for (i = 0; i < sp1D4->count; i++) {
        if (sp19C < sp1D4->arr[i].y) {
            sp19C = sp1D4->arr[i].y;
        }
    }

    if (ABS_2(sp1A0 - sp19C) < 2.0f) {
        sp1A0 -= (0.01f * (sp1A4 - sp1A8));
        sp19C += (0.01f * (sp1A4 - sp1A8));
    }

    sp1C0 = (sp1A4 - sp1A8) * 0.02f;
    spA4 = ((sp19C - sp1A0) / (sp1A4 - sp1A8));
    temp_fs5 = (f32) (arg0->unk86 - arg0->unk84) / (sp1A4 - sp1A8);
    sp194 = (f32) (arg0->unk8A - arg0->unk88) / (sp19C - sp1A0);
    sUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(arg0->unk84, arg0->unk86, arg0->unk88, arg0->unk8A);
    sUvFMtxExports->uvMat4SetOrtho(
        &sp150, (sp1A8 - (2.0f * sp1C0)) * temp_fs5, ((2.0f * sp1C0) + sp1A4) * temp_fs5,
        (sp1A0 - ((2.0f * sp1C0) * spA4)) * sp194, (((2.0f * sp1C0) * spA4) + sp19C) * sp194);
    sUvFMtxExports->uvGfxMtxProjPushF(&sp150);
    sUvFMtxExports->uvMat4SetIdentity(&sp110);
    sUvFMtxExports->func_uvfmtx_rom_004029DC(&sp110);
    sUvGfxStateExports->uvGfxStatePush();
    sUvGfxStateExports->uvGfxStateSetFlags(0x800FFF);
    sUvGfxStateExports->func_uvgfxstate_rom_00401354(0x600000);
    for (i = 0; i < (sp1D4->count - 1); i++) {
        var_v0 = &sp1D4->arr[i];
        var_v1 = &sp1D4->arr[i + 1];
        sp1C8 = var_v0->x * temp_fs5;
        sp1C4 = var_v1->x * temp_fs5;
        var_fs2 = var_v0->y * sp194;
        var_fs0 = var_v1->y * sp194;
        if (arg0->unk5E == 2) {
            if (arg0->unk64 > 0) {
                arg0->unk64--;
                var_s6 = 0xFF;
                sp192 = 0;
                var_s5 = 0;
                sp190 = 0xFF;
            } else {
                if (i % 2) {
                    var_s6 = 0xFF;
                    sp192 = 0xFF;
                    var_s5 = 0xFF;
                    sp190 = 0x7F;
                } else {
                    var_s6 = 0xC8;
                    sp192 = 0xC8;
                    var_s5 = 0xC8;
                    sp190 = 0x7F;
                }
            }
        } else {
            var_s6 = 0xFF;
            sp192 = 0xFF;
            var_s5 = 0;
            sp190 = 0x7F;
        }
        if ((var_fs2 < 0) && (var_fs0 < 0)) {
            var_fs3 = var_fs2;
            var_fs1 = var_fs0;
            var_fs0 = 0;
            var_fs2 = 0;
        } else {
            var_fs1 = 0;
            var_fs3 = 0;
        }
        if ((var_fs2 >= 0) && (var_fs0 >= 0)) {
            sUvDGeomExports->uvVtxBeginPoly();
            sUvDGeomExports->uvVtx(sp1C8, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            sUvDGeomExports->uvVtx(sp1C4, var_fs1, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            sUvDGeomExports->uvVtx(sp1C4, var_fs0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            sUvDGeomExports->uvVtx(sp1C8, var_fs2, 0, 0, 0, var_s6, sp192, var_s5, sp190);
            sUvDGeomExports->uvVtxEndPoly();
        } else {
            f32 var_fs1 = var_v0->x * temp_fs5;
            f32 var_fs0 = var_v0->y * sp194;
            f32 var_fs2 = var_v1->x * temp_fs5;
            f32 var_fs3 = var_v1->y * sp194;
            if (var_fs3 < var_fs0) {
                sUvDGeomExports->uvVtxBeginPoly();
                sUvDGeomExports->uvVtx(var_fs1, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(var_fs1, var_fs0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtxEndPoly();
                sUvDGeomExports->uvVtxBeginPoly();
                sUvDGeomExports->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(var_fs2, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(var_fs2, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtxEndPoly();
            } else {
                sUvDGeomExports->uvVtxBeginPoly();
                sUvDGeomExports->uvVtx(var_fs1, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(var_fs1, var_fs0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtxEndPoly();
                sUvDGeomExports->uvVtxBeginPoly();
                sUvDGeomExports->uvVtx(
                    (var_fs2 - ((var_fs3 / (var_fs3 - var_fs0)) * (var_fs2 - var_fs1))), 0, 0, 0, 0,
                    var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(var_fs2, 0, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtx(var_fs2, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
                sUvDGeomExports->uvVtxEndPoly();
            }
        }
    }
    if ((sp1A8 < 0) && (sp1A4 > 0)) {
        sUvDGeomExports->uvVtxBeginPoly();
        sUvDGeomExports->uvVtx(-1, (sp1A0 * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtx(1, (sp1A0 * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtx(1, (sp19C * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtx(-1, (sp19C * sp194), 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtxEndPoly();
    }
    if ((sp1A0 < 0) && (sp19C > 0)) {
        sUvDGeomExports->uvVtxBeginPoly();
        sUvDGeomExports->uvVtx((sp1A8 * temp_fs5), -1, 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtx((sp1A4 * temp_fs5), -1, 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtx((sp1A4 * temp_fs5), 1, 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtx((sp1A8 * temp_fs5), 1, 0, 0, 0, 0, 0, 0, 0xFF);
        sUvDGeomExports->uvVtxEndPoly();
    }
    if ((arg0->unk60 != -1) && (arg0->unk60 < sp1D4->count)) {
        s0 = &sp1D4->arr[arg0->unk60];
        sp1C0 *= 0.5f;
        sp1C8 = (s0->x - sp1C0) * temp_fs5;
        sp1C4 = (s0->x + sp1C0) * temp_fs5;
        temp_fa1 = sp1C0 * spA4;
        var_fs3 = (s0->y - temp_fa1) * sp194;
        var_fs2 = (s0->y + temp_fa1) * sp194;
        sp1C0 *= 2.0f;
        D_uvgui_rom_00406F08 = !D_uvgui_rom_00406F08;
        if (D_uvgui_rom_00406F08) {
            var_s6 = 0xFF;
            sp192 = 0xFF;
            var_s5 = 0;
            sp190 = 0xFF;
        } else {
            var_s6 = 0;
            sp192 = 0;
            var_s5 = 0;
            sp190 = 0xFF;
        }

        sUvDGeomExports->uvVtxBeginPoly();
        sUvDGeomExports->uvVtx(sp1C8, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        sUvDGeomExports->uvVtx(sp1C4, var_fs3, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        sUvDGeomExports->uvVtx(sp1C4, var_fs2, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        sUvDGeomExports->uvVtx(sp1C8, var_fs2, 0, 0, 0, var_s6, sp192, var_s5, sp190);
        sUvDGeomExports->uvVtxEndPoly();
    }
    arg0->unk74 = sUvGrphExports->func_uvgrph_rom_00400080(sp1D4, arg0->unk68);
    temp_fa1 = (sp1C0 * spA4);
    sp1C8 = (arg0->unk68 - sp1C0) * temp_fs5;
    sp1C4 = (arg0->unk68 + sp1C0) * temp_fs5;
    var_fs3 = ((arg0->unk74 - temp_fa1) * sp194);
    var_fs2 = ((arg0->unk74 + temp_fa1) * sp194);

    sUvDGeomExports->uvVtxBeginPoly();
    sUvDGeomExports->uvVtx(sp1C8, (arg0->unk74 * sp194), 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    sUvDGeomExports->uvVtx((arg0->unk68 * temp_fs5), var_fs3, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    sUvDGeomExports->uvVtx(sp1C4, (arg0->unk74 * sp194), 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    sUvDGeomExports->uvVtx((arg0->unk68 * temp_fs5), var_fs2, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF);
    sUvDGeomExports->uvVtxEndPoly();
    if (arg0->unk5E != 2) {
        sUvFontExports->uvFontColor(0xFF, 0xFF, 0, 0xFF);
        sUvStringExports->uvSprintf(spD4, "%s * %s", arg0->unk4, arg0->unk22);
        sUvFontExports->uvFontPrintStr(
            (s32) ((arg0->unk84 + arg0->unk86) - sUvFontExports->uvFontWidth(spD4)) / 2,
            (arg0->unk8A - sUvFontExports->uvFontHeight()) - 2, spD4);
    }
    if (arg0->unk5E == 2) {
        var_s6 = 0;
    } else {
        var_s6 = 0xFF;
    }
    sUvFontExports->uvFontColor(var_s6, 0xFF, 0xFF, 0xFF);
    sUvStringExports->uvSprintf(spD4, "%f", arg0->unk68);
    sUvFontExports->uvFontPrintStr(arg0->unk84 + 4, arg0->unk88 - 2, spD4);
    sUvStringExports->uvSprintf(spD4, "%f", arg0->unk74);
    sUvFontExports->uvFontPrintStr((arg0->unk86 - sUvFontExports->uvFontWidth(spD4)) - 4,
                                   arg0->unk88 - 2, spD4);
    if ((arg0->unk5E == 2) && (arg0->unk60 != -1)) {
        sUvFontExports->uvFontColor(0xFF, 0xFF, 0, 0xFF);
        s0 = &sp1D4->arr[arg0->unk60];
        sUvStringExports->uvSprintf(spD4, "%f", s0->x);
        sUvFontExports->uvFontPrintStr(arg0->unk84 + 4,
                                       arg0->unk8A - (sUvFontExports->uvFontHeight() * 2), spD4);
        sUvStringExports->uvSprintf(spD4, "%f", s0->y);
        sUvFontExports->uvFontPrintStr((arg0->unk86 - sUvFontExports->uvFontWidth(spD4)) - 4,
                                       arg0->unk8A - (sUvFontExports->uvFontHeight() * 2), spD4);
    }
    sUvGfxStateExports->uvGfxStatePop();
    sUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, sUvGfxMgrExports->uvGetScreenWidth() - 1, 0,
                                                 sUvGfxMgrExports->uvGetScreenHeight() - 1);
    sUvFMtxExports->uvMat4SetOrtho(&sp150, -0.5f, sUvGfxMgrExports->uvGetScreenWidth() + 0.5f, -0.5f,
                                   sUvGfxMgrExports->uvGetScreenHeight() + 0.5f);
    sUvFMtxExports->uvGfxMtxProjPushF(&sp150);
}

void func_uvgui_rom_00405CEC(Inner30 *arg0, s16 arg1) {
    if ((arg1 == 2) && (arg0->unk5E != 2)) {
        arg0->unk60 = 0;
    }
    arg0->unk5E = arg1;
}

void uvGuiProps(Inner30 *arg0, ...) {
    s16 prop;
    va_list args;

    va_start(args, arg0);
    while (TRUE) {
        prop = va_arg(args, s32);
        if (prop == 0) {
            break;
        }
        if (prop != 1) {
            break;
        }
        arg0->unk62 = va_arg(args, s32);
    }
    va_end(args);
}

void func_uvgui_rom_00405D78(void) {
    Inner2C *var_s0;
    s32 i;

    for (i = 0; i < 10; i++) {
        var_s0 = &D_uvgui_rom_00406F20[i];
        var_s0->unk1E = 0;
        var_s0->unk20 = 1;
        var_s0->unk34 = 1.0f;
        var_s0->unk38 = -1.0f;
        var_s0->unk24 = 0.0f;
        var_s0->unk28 = 0.0f;
        var_s0->unk2C = 0.0f;
        var_s0->unk30 = 0;
        var_s0->unk44 = -1;
        func_uvgui_rom_00406024(var_s0, (s16) ((s32) (sUvGfxMgrExports->uvGetScreenWidth() - 0xB4) / 2),
                                ((sUvGfxMgrExports->uvGetScreenWidth() + 0xB4) / 2),
                                (s16) ((s32) (sUvGfxMgrExports->uvGetScreenHeight() - 0x50) / 2),
                                (s32) (sUvGfxMgrExports->uvGetScreenHeight() + 0x50) / 2);
        var_s0->unk48 = 0;
    }
}

s16 func_uvgui_rom_00405F20(void) {
    s32 i;

    i = 0;
    for (i = 0; i < 10; i++) {
        if (D_uvgui_rom_00406F20[i].unk1E == 0) {
            break;
        }
    }
    D_uvgui_rom_00406F20[i].unk1E = 1;
    return i;
}

void func_uvgui_rom_00405F60(s16 arg0) {
    D_uvgui_rom_00406F20[arg0].unk1E = 0;
}

Inner2C *func_uvgui_rom_00405F90(s16 arg0) {
    return &D_uvgui_rom_00406F20[arg0];
}

void func_uvgui_rom_00405FC0(Inner2C *arg0, u8 *arg1) {
    u8 sp30[0x1E];
    s32 i;

    for (i = 0; i < 0x1E; i++) {
        if (arg1[i] >= 'a') {
            sp30[i] = arg1[i] - ' ';
        } else {
            sp30[i] = arg1[i];
        }
    }

    _uvMediaCopy(arg0->unk0, sp30, 0x1EU);
}

void func_uvgui_rom_00406024(Inner2C *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk3C = arg1;
    arg0->unk3E = arg2;
    arg0->unk40 = arg3;
    arg0->unk42 = arg4;
}

void func_uvgui_rom_00406048(Inner2C *arg0) {
    u8 spAF;
    u8 spAE;
    u8 spAD;
    u8 spAC;
    s16 spAA;
    s16 spA8;
    s16 spA6;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    s16 sp9E;
    s16 sp9C;
    s16 sp9A;
    s16 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    u8 sp6C[0x18];
    f32 sp68;
    f32 temp_fa1;
    s32 pad;
    f32 sp5C;

    if (arg0->unk30 != 0) {
        arg0->unk24 = arg0->unk30->x;
        arg0->unk28 = arg0->unk30->y;
        arg0->unk2C = arg0->unk30->z;
    }

    // clang-format off
    switch (arg0->unk1E) {
        case 1:
            spAF = 0xD5;\
            spAE = 0xD7;\
            spAD = 0x25;\
            spAC = 0xFF;
            break;
        case 2:
            spAF = 0xFF;\
            spAE = 0xFF;\
            spAD = 0xFF;\
            spAC = 0xFF;
            break;
    }
    // clang-format on

    uvGuiDrawRect(arg0->unk3C, arg0->unk3E, arg0->unk40, arg0->unk42, 2, spAF, spAE, spAD,
                            spAC);
    if (arg0->unk20 == 1) {
        sp94 = arg0->unk3E - 5;
        sp92 = arg0->unk40 + 5;
        sp90 = arg0->unk42 - 5;
        sp96 = (sp94 - sp90) + sp92;
        spAF = arg0->unk24 * 255.0f;
        spAE = arg0->unk28 * 255.0f;
        spAD = arg0->unk2C * 255.0f;
        spAC = 0xFF;
        uvGuiDrawRect(sp96, sp94, sp92, sp90, 2, spAF, spAE, spAD, spAC);
    } else {
        sp96 = arg0->unk3E;
        sp94 = arg0->unk3E;
        sp92 = arg0->unk40;
        sp90 = arg0->unk42;
    }
    spAA = arg0->unk3C + 5;
    spA8 = sp96 - 5;
    spA6 = arg0->unk40 + ((arg0->unk42 - arg0->unk40) / 5) + 5;
    spA4 = arg0->unk42 - 5;
    if (arg0->unk1E == 2) {
        uvGuiDrawRect(spAA, spA8, spA6, spA4, 2, 0x32, 0x32, 0x32, 0xFF);
    }

    if (arg0->unk38 != arg0->unk34) {
        sp8C = (arg0->unk24 - arg0->unk34) / (arg0->unk38 - arg0->unk34);
        sp84 = (arg0->unk28 - arg0->unk34) / (arg0->unk38 - arg0->unk34);
        sp88 = (arg0->unk2C - arg0->unk34) / (arg0->unk38 - arg0->unk34);
    } else {
        sp8C = sp84 = sp88 = 0.5f;
    }
    sp98 = ((spA4 - spA6) - 8) / 3;
    sp9A = spA4 - 2;
    sp9C = sp9A - sp98;
    if (arg0->unk1E == 2) {
        if (arg0->unk44 == 0) {
            spAF = spAE = spAD = 0xFF;
            spAC = 0xFF;
        } else {
            spAF = spAE = spAD = 0x32;
            spAC = 0xFF;
        }
    } else {
        spAF = spAE = spAD = 0;
        spAC = 0x50;
    }
    spA2 = (spA8 - spAA) - 0xC;
    spA0 = spAA + (s16) (spA2 * sp8C) + 3;
    sp9E = spA0 + 6;
    uvGuiDrawRect(spA0, sp9E, sp9C, sp9A, 2, spAF, spAE, spAD, spAC);
    sp9A = sp9C - 2;
    sp9C = sp9A - sp98;
    if (arg0->unk1E == 2) {
        if (arg0->unk44 == 1) {
            spAF = spAE = spAD = 0xFF;
            spAC = 0xFF;
        } else {
            spAF = spAE = spAD = 0x32;
            spAC = 0xFF;
        }
    } else {
        spAF = spAE = spAD = 0;
        spAC = 0x50;
    }
    spA0 = spAA + (s16) (spA2 * sp84) + 3;
    sp9E = spA0 + 6;
    uvGuiDrawRect(spA0, sp9E, sp9C, sp9A, 2, spAF, spAE, spAD, spAC);
    sp9A = sp9C - 2;
    sp9C = sp9A - sp98;
    if (arg0->unk1E == 2) {
        if (arg0->unk44 == 2) {
            spAF = spAE = spAD = 0xFF;
            spAC = 0xFF;
        } else {
            spAF = spAE = spAD = 0x32;
            spAC = 0xFF;
        }
    } else {
        spAF = spAE = spAD = 0;
        spAC = 0x50;
    }
    spA0 = spAA + (s16) (spA2 * sp88) + 3;
    sp9E = spA0 + 6;
    uvGuiDrawRect(spA0, sp9E, sp9C, sp9A, 2, spAF, spAE, spAD, spAC);
    sUvFontExports->uvFontWidth(arg0->unk0);
    sUvFontExports->uvFontColor(0, 0, 0, 0xFF);
    sUvFontExports->uvFontPrintStr(arg0->unk3C + 7, arg0->unk40 + 2, arg0->unk0);
    if ((arg0->unk20 == 1) && (arg0->unk1E == 2)) {
        if (arg0->unk44 != -1) {
            switch (arg0->unk44) {
                case 0:
                    sp68 = arg0->unk24;
                    break;
                case 1:
                    sp68 = arg0->unk28;
                    break;
                case 2:
                    sp68 = arg0->unk2C;
                    break;
            }
            temp_fa1 = (arg0->unk24 + arg0->unk28 + arg0->unk2C) / 3.0f;
            if (temp_fa1 > 0.5f) {
                spAD = 0;
                spAE = 0;
                spAF = 0;
                spAC = 0xFF;
            } else {
                spAD = 0xFF;
                spAE = 0xFF;
                spAF = 0xFF;
                spAC = 0xFF;
            }
            sUvFontExports->uvFontColor(spAF, spAE, spAD, spAC);
            sUvStringExports->uvSprintf(sp6C, "%f", sp68);
            sUvFontExports->uvFontPrintStr(((sp94 + sp96) - (s16) sUvFontExports->uvFontWidth(sp6C))
                                               / 2,
                                           (s32) ((sp90 + sp92) + 0xC) / 2, sp6C);
            sUvStringExports->uvSprintf(sp6C, "%d", (s32) (sp68 * 255.0f));
            sUvFontExports->uvFontPrintStr(((sp94 + sp96) - (s16) sUvFontExports->uvFontWidth(sp6C))
                                               / 2,
                                           (s32) ((sp90 + sp92) - 0xC) / 2, sp6C);
            return;
        }
    }
    if ((arg0->unk20 == 2) && (arg0->unk1E == 2)) {
        if (arg0->unk44 != -1) {
            switch (arg0->unk44) {
                case 0:
                    sp5C = arg0->unk24;
                    break;
                case 1:
                    sp5C = arg0->unk28;
                    break;
                case 2:
                    sp5C = arg0->unk2C;
                    break;
            }
            sUvStringExports->uvSprintf(sp6C, "%f", sp5C);
            sUvFontExports->uvFontPrintStr((spA8 - (s16) sUvFontExports->uvFontWidth(sp6C)) - 2,
                                           arg0->unk40 + 2, sp6C);
        }
    }
}

void func_uvgui_rom_00406B00(Inner2C *arg0, s32 arg1) {
    arg0->unk48 = arg1;
}

void func_uvgui_rom_00406B08(Inner2C *arg0, f32 arg1, f32 arg2, Vec3F *arg3, Vec3F *arg4) {
    if (arg0->unk20 == 1) {
        arg1 = 0.0f, arg2 = 1.0f;
    }

    arg0->unk34 = arg1;
    arg0->unk38 = arg2;
    arg0->unk30 = arg4;
    if (arg4 != NULL) {
        arg0->unk24 = arg4->x;
        arg0->unk28 = arg4->y;
        arg0->unk2C = arg4->z;
        return;
    }
    arg0->unk24 = arg3->x;
    arg0->unk28 = arg3->y;
    arg0->unk2C = arg3->z;
}

void func_uvgui_rom_00406B7C(Inner2C *arg0, s16 arg1) {
    arg0->unk20 = arg1;
}

void func_uvgui_rom_00406B88(Inner2C *arg0, u8 arg1, f32 arg2) {
    f32 temp_ft4;
    f32 temp_fv0;

    if (arg0->unk1E != 2) {
        return;
    }

    if (arg0->unk44 == -1) {
        arg0->unk44 = 0;
    }
    if (sUvContExports->uvControllerButtonPress(arg1, Z_TRIG) != 0) {
        arg0->unk44 += 1;
        if (arg0->unk44 >= 3) {
            arg0->unk44 = 0;
        }
    }
    if (arg0->unk30 != NULL) {
        arg0->unk24 = arg0->unk30->x;
        arg0->unk28 = arg0->unk30->y;
        arg0->unk2C = arg0->unk30->z;
    }
    temp_ft4 = (arg0->unk38 - arg0->unk34) * 0.5f;
    temp_fv0 = sUvGfxMgrExports->func_uvgfxmgr_rom_00401004();
    if (arg2 > 0.0f) {
        arg2 *= arg2;
    } else {
        arg2 *= -arg2;
    }
    switch (arg0->unk44) { /* irregular */
        case 0:
            arg0->unk24 += 0.5f * arg2 * temp_ft4 * temp_fv0;
            if (arg0->unk24 < arg0->unk34) {
                arg0->unk24 = arg0->unk34;
            } else {
                if (arg0->unk38 < arg0->unk24) {
                    arg0->unk24 = arg0->unk38;
                }
            }
            break;
        case 1:
            arg0->unk28 += 0.5f * arg2 * temp_ft4 * temp_fv0;
            if (arg0->unk28 < arg0->unk34) {
                arg0->unk28 = arg0->unk34;
            } else {
                if (arg0->unk38 < arg0->unk28) {
                    arg0->unk28 = arg0->unk38;
                }
            }
            break;
        case 2:
            arg0->unk2C += 0.5f * arg2 * temp_ft4 * temp_fv0;
            if (arg0->unk2C < arg0->unk34) {
                arg0->unk2C = arg0->unk34;
            } else {
                if (arg0->unk38 < arg0->unk2C) {
                    arg0->unk2C = arg0->unk38;
                }
            }
            break;
    }
    if (arg0->unk30 != NULL) {
        arg0->unk30->x = arg0->unk24;
        arg0->unk30->y = arg0->unk28;
        arg0->unk30->z = arg0->unk2C;
    }
    if (arg0->unk48 != NULL) {
        arg0->unk48(arg0);
    }
}

void func_uvgui_rom_00406E28(Inner2C *arg0, s16 arg1) {
    arg0->unk1E = arg1;
}

s32 D_uvgui_rom_00406F0C[] = { 0x01480000, __entrypoint_func_uvgui_rom_400000, 0, 0 };
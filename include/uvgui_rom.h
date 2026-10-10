#ifndef UVGUI_ROM_H
#define UVGUI_ROM_H

#define MAX_MENU_ITEM_NAME 12
#define MAX_MENU_OPTION_NAME_LEN 30
#define MAX_MENU_TITLE_LEN 30
#define MAX_MENU_OPTIONS 12

typedef void (*UvGuiCallback)(void* arg0);

typedef enum GuiSliderState_e {
    SLIDER_STATE_FREE, // Unallocated
    SLIDER_STATE_RENDER,
    SLIDER_STATE_ACTIVE
} GuiSliderState;

typedef struct GuiSlider_s {
    /* 0x00 */ u8 label[0x1E];                             /* inferred */
    /* 0x1E */ s16 state;
    /* 0x20 */ s16 mode;
    /* 0x22 */ char pad22[2];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ s32* unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ s16 x0;
    /* 0x3A */ s16 x1;
    /* 0x3C */ s16 y0;
    /* 0x3E */ s16 y1;
    /* 0x40 */ UvGuiCallback callback;
    /* 0x44 */ s32* unk44;
} GuiSlider;                                          /* size = 0x48 */

typedef struct Inner2C_s {
    /* 0x00 */ u8 unk0[0x1E];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char pad22[2];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ Vec3F* unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s16 unk3C;                           /* inferred */
    /* 0x3E */ s16 unk3E;                           /* inferred */
    /* 0x40 */ s16 unk40;                           /* inferred */
    /* 0x42 */ s16 unk42;                           /* inferred */
    /* 0x44 */ s16 unk44;
    /* 0x46 */ char pad46[2];
    /* 0x48 */ void (*unk48)(void*);
} Inner2C;                                          /* size = 0x4C */

typedef struct Inner30_s {
    /* 0x00 */ UvGrphStruct* unk0;
    /* 0x04 */ s8 unk4[0x1E];
    /* 0x22 */ u8 unk22[0x1E];
    /* 0x40 */ u8 unk40[0x1E];
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ s16 unk62;
    /* 0x64 */ s16 unk64;
    /* 0x66 */ char pad66[2];
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;                           /* inferred */
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C; 
    /* 0x80 */ f32* unk80;
    /* 0x84 */ s16 unk84;
    /* 0x86 */ s16 unk86;
    /* 0x88 */ s16 unk88;
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ void (*unk8C)(void*);
} Inner30;                                          /* size = 0x90 */

// Item Entry?
typedef struct GuiMenuItem_s {
    /* 0x00 */ u8 name[MAX_MENU_ITEM_NAME];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ char pad1A[2];
    /* 0x1C */ UvGuiCallback unk1C; /* inferred */
    /* 0x20 */ UvGuiCallback unk20; /* inferred */
    /* 0x24 */ UvGuiCallback unk24; /* inferred */
    /* 0x28 */ GuiSlider* slider;
    /* 0x2C */ Inner2C* unk2C;
    /* 0x30 */ Inner30* unk30;
} GuiMenuItem;    /* size = 0x34 */

// MenuEntry?
typedef struct GuiMenuOption_s {
    /* 0x001 */ u8 name[MAX_MENU_OPTION_NAME_LEN];                    /* maybe part of unk0[0x20]? */
    /* 0x01E */ s16 unk1E;
    /* 0x020 */ s16 unk20;                          /* inferred */
    /* 0x022 */ s16 unk22;                          /* inferred */
    /* 0x024 */ s16 unk24;                          /* inferred */
    /* 0x026 */ s16 unk26;                          /* inferred */
    /* 0x028 */ GuiMenuItem* items[80]; // itemEntry?
    /* 0x168 */ s16 activeMenuItems;                         /* inferred */
    /* 0x16A */ s16 unk16A;
    /* 0x16C */ s16 unk16C;                         /* inferred */
    /* 0x16E */ char pad16E[2];
} GuiMenuOption;          /* size = 0x170 */

typedef struct GuiMenu_s {
    /* 0x00 */ u8 title[MAX_MENU_TITLE_LEN];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 x0;
    /* 0x22 */ s16 x1;
    /* 0x24 */ s16 y0;                           /* inferred */
    /* 0x26 */ s16 y1;                           /* inferred */
    /* 0x28 */ GuiMenuOption* options[MAX_MENU_OPTIONS];
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
} GuiMenu;                /* size = 0x5C */

typedef struct uvGui_s {
    /* 0x00 */ GuiMenu* menus[20];
    /* 0x50 */ s16 activeMenuCount;
    /* 0x52 */ char pad52[2];
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ s16 cursorX;
    /* 0x72 */ s16 cursorY;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 unk78;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s32 unk80;
    /* 0x84 */ s8 contNo;
    /* 0x85 */ char pad85[1];
    /* 0x86 */ s16 uvds;                           /* inferred */
    /* 0x88 */ s16 fontId;
    /* 0x8A */ s8 unk8A;
    /* 0x8B */ s8 unk8B;
} uvGui;                     /* size = 0x8C */

typedef struct UvGui_Exports_s {
    /* 0x000 */ void (*uvGuiDestroy)(void);
    /* 0x004 */ void (*uvGuiInit)(uvGui *);
    /* 0x008 */ void (*uvGuiAddMenu)(uvGui *, GuiMenu *);
    /* 0x00C */ void (*uvGuiRender)(uvGui *);
    /* 0x010 */ void (*uvGuiDrawRect)(s16, s16, s16, s16, s16, u8, u8, u8, u8);
    /* 0x014 */ void (*uvGuiPrintCentered)(s16, s16, s16, s16, u8 *, u8, u8, u8, u8);
    /* 0x018 */ void (*uvGuiDrawCursor)(s16, s16);
    /* 0x01C */ void (*func_uvgui_rom_0040126C)(uvGui *, s16, s16, s16, s16);
    /* 0x020 */ s32 (*func_uvgui_rom_00401290)(uvGui *);
    /* 0x024 */ void (*func_uvgui_rom_004015B8)(uvGui *, s16, s32);
    /* 0x028 */ void (*func_uvgui_rom_00401614)(uvGui *, s16, s16);
    /* 0x02C */ void (*func_uvgui_rom_004016A0)(uvGui *, s8);
    /* 0x030 */ void (*func_uvgui_rom_004016AC)(uvGui *, s16, s16);
    /* 0x034 */ void (*func_uvgui_rom_004016E0)(s16);
    /* 0x038 */ void (*func_uvgui_rom_004016F0)(uvGui *);
    /* 0x03C */ void (*uvGuiInitializeMenuItems)(void);
    /* 0x040 */ s16 (*uvGuiNewMenuItem)(void);
    /* 0x044 */ GuiMenuItem *(*uvGuiGetMenuItem)(s16);
    /* 0x048 */ void (*uvGuiSetMenuItemName)(GuiMenuItem *, u8 *);
    /* 0x04C */ void (*func_uvgui_rom_00401D74)(GuiMenuItem *, s16);
    /* 0x050 */ void (*func_uvgui_rom_00401D80)(GuiMenuItem *, s16, s16, s16, s16);
    /* 0x054 */ void (*func_uvgui_rom_00401DC4)(GuiMenuItem *);
    /* 0x058 */ s32 (*func_uvgui_rom_004020A0)(GuiMenuItem *, u8, s16, s16, s32, f32, f32);
    /* 0x05C */ void (*func_uvgui_rom_0040221C)(GuiMenuItem *, s16, void (*)(void *));
    /* 0x060 */ void (*func_uvgui_rom_00402268)(GuiMenuItem *, GuiSlider *);
    /* 0x064 */ void (*func_uvgui_rom_00402308)(GuiMenuItem *, Inner2C *);
    /* 0x068 */ void (*func_uvgui_rom_004023A8)(GuiMenuItem *, Inner30 *);
    /* 0x06C */ void (*uvGuiInitMenus)(void);
    /* 0x070 */ s16 (*uvGuiNewMenu)(void);
    /* 0x074 */ GuiMenu *(*uvGuiGetMenu)(s16);
    /* 0x078 */ void (*uvGuiSetMenuTitle)(GuiMenu *, u8 *);
    /* 0x07C */ void (*func_uvgui_rom_0040277C)(GuiMenu *, s16);
    /* 0x080 */ void (*uvGuiSetMenuPosition)(GuiMenu *, s16, s16, s16, s16);
    /* 0x084 */ void (*uvGuiAddMenuOption)(GuiMenu *, GuiMenuOption *);
    /* 0x088 */ void (*uvGuiRenderMenu)(GuiMenu *);
    /* 0x08C */ s32 (*func_uvgui_rom_0040293C)(GuiMenu *, u8, s16, s16, s32, f32, f32);
    /* 0x090 */ void (*uvGuiInitMenuOptions)(void);
    /* 0x094 */ s16 (*uvGuiNewMenuOption)(void);
    /* 0x098 */ GuiMenuOption *(*uvGuiGetMenuOption)(s16);
    /* 0x09C */ void (*uvGuiSetMenuOptionName)(GuiMenuOption *, u8 *);
    /* 0x0A0 */ void (*func_uvgui_rom_00402C34)(GuiMenuOption *, s16);
    /* 0x0A4 */ void (*uvGuiSetMenuOptionPosition)(GuiMenuOption *, s16, s16, s16, s16);
    /* 0x0A8 */ void (*uvGuiAddMenuItem)(GuiMenuOption *, GuiMenuItem *);
    /* 0x0AC */ void (*uvGuiRenderMenuOption)(GuiMenuOption *);
    /* 0x0B0 */ s32 (*func_uvgui_rom_00402E48)(GuiMenuOption *, u8, s16, s16, s32, f32, f32);
    /* 0x0B4 */ void (*uvGuiSliderInit)(void);
    /* 0x0B8 */ s16 (*uvGuiSliderNew)(void);
    /* 0x0BC */ void (*uvGuiSliderFree)(s16);
    /* 0x0C0 */ GuiSlider *(*uvGuiGetSlider)(s16);
    /* 0x0C4 */ void (*uvGuiSliderSetLabel)(GuiSlider *, u8 *);
    /* 0x0C8 */ void (*uvGuiSliderSetRect)(GuiSlider *, s16, s16, s16, s16);
    /* 0x0CC */ void (*uvGuiDrawSlider)(GuiSlider *);
    /* 0x0D0 */ void (*func_uvgui_rom_004037D8)(GuiSlider *, s32);
    /* 0x0D4 */ void (*func_uvgui_rom_004037E0)(GuiSlider *, f32, f32, f32, s32 *);
    /* 0x0D8 */ void (*func_uvgui_rom_004038D8)(GuiSlider *, s16);
    /* 0x0DC */ void (*func_uvgui_rom_004038E4)(GuiSlider *, u8, f32);
    /* 0x0E0 */ void (*func_uvgui_rom_00403C50)(GuiSlider *, s16);
    /* 0x0E4 */ void (*func_uvgui_rom_00403CA4)(GuiSlider *, s32);
    /* 0x0E8 */ void (*func_uvgui_rom_00403CAC)(void);
    /* 0x0EC */ s16 (*func_uvgui_rom_00403E78)(void);
    /* 0x0F0 */ void (*func_uvgui_rom_00403EB8)(s16);
    /* 0x0F4 */ Inner30 *(*func_uvgui_rom_00403EE0)(s16);
    /* 0x0F8 */ void (*func_uvgui_rom_00403F08)(Inner30 *, s16, s16, s16, s16);
    /* 0x0FC */ void (*func_uvgui_rom_00403F2C)(Inner30 *, u8 *, u8 *);
    /* 0x100 */ void (*func_uvgui_rom_00404010)(Inner30 *, s32, f32, f32, f32, f32 *);
    /* 0x104 */ void (*func_uvgui_rom_0040404C)(Inner30 *, s32);
    /* 0x108 */ void (*func_uvgui_rom_00404054)(Inner30 *, u8, f32);
    /* 0x10C */ void (*func_uvgui_rom_004046B4)(Inner30 *);
    /* 0x110 */ void (*func_uvgui_rom_00405CEC)(Inner30 *, s16);
    /* 0x114 */ void (*uvGuiProps)(Inner30 *, ...);
    /* 0x118 */ void (*func_uvgui_rom_00405D78)(void);
    /* 0x11C */ s16 (*func_uvgui_rom_00405F20)(void);
    /* 0x120 */ void (*func_uvgui_rom_00405F60)(s16);
    /* 0x124 */ Inner2C *(*func_uvgui_rom_00405F90)(s16);
    /* 0x128 */ void (*func_uvgui_rom_00405FC0)(Inner2C *, u8 *);
    /* 0x12C */ void (*func_uvgui_rom_00406024)(Inner2C *, s16, s16, s16, s16);
    /* 0x130 */ void (*func_uvgui_rom_00406048)(Inner2C *);
    /* 0x134 */ void (*func_uvgui_rom_00406B00)(Inner2C *, s32);
    /* 0x138 */ void (*func_uvgui_rom_00406B08)(Inner2C *, f32, f32, Vec3F *, Vec3F *);
    /* 0x13C */ void (*func_uvgui_rom_00406B7C)(Inner2C *, s16);
    /* 0x140 */ void (*func_uvgui_rom_00406B88)(Inner2C *, u8, f32);
    /* 0x144 */ void (*func_uvgui_rom_00406E28)(Inner2C *, s16);     /* inferred */
} UvGui_Exports;                                    /* size = 0x144 */
 


#endif /* UVGUI_ROM_H */

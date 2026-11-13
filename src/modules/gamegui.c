// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

typedef struct UnkSceneExports_s {
    char pad[0x20];
    void (*unk20)(GuiMenu *);
} UnkSceneExports;

typedef struct UnkPlyrExports_s {
    char pad[0x24];
    s32 unk24;
    s32 unk28;
} UnkPlyrExports;


void func_gamegui_004000A8(void);
void func_gamegui_004000B0(void);
void func_gamegui_00400194(GuiMenu *menu);
void func_gamegui_00400370(GuiMenu *menu);
void func_gamegui_004014F8(GuiMenu *menu);
void func_gamegui_00401748(void);
void func_gamegui_00401A7C(void);
void func_gamegui_00401AD8(s32 arg0);
void func_gamegui_00401AF8(GuiSlider *slider);
void func_gamegui_00401D34(GuiMenuItem *arg0);
void func_gamegui_00401D94(void *arg0);
void func_gamegui_00401DC4(void *arg0);
void func_gamegui_00401DF4(void *arg0);
void func_gamegui_00401E24(void *arg0);
void func_gamegui_00401E50(void *arg0);
void func_gamegui_00401E7C(void);
void func_gamegui_00401FE0(void);
void func_gamegui_00402030(void (*arg0)(void));
void func_gamegui_0040203C(void *arg0);
void func_gamegui_00402074(void *arg0);
void func_gamegui_00402088(void *arg0);
void func_gamegui_0040209C(void *arg0);
void func_gamegui_004020BC(void *arg0);
void func_gamegui_004020DC(void *arg0);
void func_gamegui_00402110(void *arg0);
void func_gamegui_00402130(void *arg0);
void func_gamegui_00402144(void *arg0);
void func_gamegui_00402158(void *arg0);
void func_gamegui_0040216C(void *arg0);
void func_gamegui_00402180(void *arg0);
void func_gamegui_00402194(void);
void func_gamegui_0040219C(void *arg0);
void func_gamegui_004021D4(void);
void func_gamegui_004021DC(s32 arg0);
void func_gamegui_00402358(s32 arg0);
u8 func_gamegui_004023B0(void);
void func_gamegui_004023BC(void *arg0);
void __entrypoint_func_gamegui_400000(GameGui_Exports *exports);



// .bss
s32 B_gamegui_00402C60[2]; // unreferenced padding
UnkStruct_gamegui_00402C68 D_gamegui_00402C68;
DlEdit_Exports *D_gamegui_00402D0C;
s32 D_gamegui_00402D10;
s32 D_gamegui_00402D14;
GuiMenuItem *D_gamegui_00402D18;
GuiMenuItem *D_gamegui_00402D1C;
GuiMenuItem *D_gamegui_00402D20;
GuiMenuItem *D_gamegui_00402D24;
GuiMenuItem *D_gamegui_00402D28;
s32 pad[2];

// external vars
extern s32 gDebugOptsCarSelect;
extern s32 gDebugOptsMinDt;
extern s32 gDebugProfilingState;
extern s32 gNumOpenCars;
extern s32 gNumOpenMtracks;
extern s32 gNumOpenTourns;
extern s32 gNumOpenTracks;
extern s32 gOptionsMusicVol;
extern s32 gOptionsSfxVol;
extern s32 gDebugEnable;
extern UnkSceneExports *gSceneExports;
extern UnkRainExports *gRainExports;
extern UnkFlagExports *gFlagExports;
extern s32 D_80025D7C;

void __entrypoint_func_gamegui_400000(GameGui_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_gamegui_004000A8 = func_gamegui_004000A8;
    exports->func_gamegui_004000B0 = func_gamegui_004000B0;
    exports->func_gamegui_00401748 = func_gamegui_00401748;
    exports->func_gamegui_00401A7C = func_gamegui_00401A7C;
    exports->func_gamegui_00401AD8 = func_gamegui_00401AD8;
    exports->func_gamegui_00401E7C = func_gamegui_00401E7C;
    exports->func_gamegui_00401FE0 = func_gamegui_00401FE0;
    exports->func_gamegui_00402030 = func_gamegui_00402030;
    exports->func_gamegui_00402358 = func_gamegui_00402358;
    exports->func_gamegui_004023B0 = func_gamegui_004023B0;
    exports->D_gamegui_00402C68 = &D_gamegui_00402C68;
}

void func_gamegui_004000A8(void) {
}

void func_gamegui_004000B0(void) {
    GuiMenu *menu;

    if (!gDebugEnable) {
        return;
    }
    D_gamegui_00402C68.unkC = 1;
    func_gamegui_00401E7C();
    menu = gUvGuiExports->uvGuiGetMenu(gUvGuiExports->uvGuiNewMenu());
    gUvGuiExports->uvGuiSetMenuTitle(menu, "N E E D   F O R   S P E E D");
    gUvGuiExports->uvGuiAddMenu(&D_gamegui_00402C68.gui, menu);
    func_gamegui_00400194(menu);
    func_gamegui_00400370(menu);
    func_gamegui_004014F8(menu);
    gSceneExports->unk20(menu);
}

void func_gamegui_00400194(GuiMenu *menu) {
    GuiMenuOption *menuOption;
    GuiSlider *slider;

    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, "race");
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    gMiscExports->func_misc_004038D8(menuOption, "num players", 0x12, 1.0f, 4.0f,
                                     &gGameSettings->numPlayers, &slider);
    gMiscExports->func_misc_004038D8(menuOption, "ai", 0x12, 0.0f, 7.0f,
                                     &gGameSettings->numAiCars, &slider);
    gMiscExports->func_misc_004038D8(menuOption, "ai record", 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgRaceAiRecord, &slider);
    gMiscExports->func_misc_004038D8(menuOption, "steer assist", 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgSteerAssist, &slider);
    gMiscExports->func_misc_00403BEC(menuOption, "* play *", func_gamegui_00401E24);
    gMiscExports->func_misc_00403BEC(menuOption, "* battle *", func_gamegui_00401E50);
}

// .rodata

// TODO: Need to figure out how to migrate these...
static const char D_gamegui_004024B8[] = "DEFAULT";
static const char D_gamegui_004024C0[] = "POINT";
static const char D_gamegui_004024C8[] = "AVERAGE";
static const char D_gamegui_004024D0[] = "BILERP";
static const char D_gamegui_004024D8[] = "DEFAULT";
static const char D_gamegui_004024E0[] = "NONE";
static const char D_gamegui_004024E8[] = "PERSP";
static const char D_gamegui_004024F0[] = "DEFAULT";
static const char D_gamegui_004024F8[] = "CLAMP";
static const char D_gamegui_00402500[] = "SHARPEN";
static const char D_gamegui_00402508[] = "DETAIL";
static const char D_gamegui_00402510[] = "DEFAULT";
static const char D_gamegui_00402518[] = "TRILINEAR";
static const char D_gamegui_00402524[] = "BILINEAR";
static const char D_gamegui_00402530[] = "NONE";
static const char D_gamegui_00402538[] = "60 Hz";
static const char D_gamegui_00402540[] = "30 Hz";
static const char D_gamegui_00402548[] = "20 Hz";
static const char D_gamegui_00402550[] = "15 Hz";
static const char D_gamegui_00402558[] = "12 Hz";
static const char D_gamegui_00402560[] = "NONE";
static const char D_gamegui_00402568[] = "FONTS";
static const char D_gamegui_00402570[] = "RECTS";
static const char D_gamegui_00402578[] = "BOTH";
static const char D_gamegui_00402580[] = "dbg";

static const char D_gamegui_00402584[] = "open cars";
static const char D_gamegui_00402590[] = "open tracks";
static const char D_gamegui_0040259C[] = "open mtracks";
static const char D_gamegui_004025AC[] = "open tourns";
static const char D_gamegui_004025B8[] = "play sfx";
static const char D_gamegui_004025C4[] = "play midi";
static const char D_gamegui_004025D0[] = "txtcount";
static const char D_gamegui_004025DC[] = "NONE";
static const char D_gamegui_004025E4[] = "PERF BRIEF";
static const char D_gamegui_004025F0[] = "PERF FONT";
static const char D_gamegui_004025FC[] = "PERF BARS";
static const char D_gamegui_00402608[] = "PERF TIMES";
static const char D_gamegui_00402614[] = "PERF BOTH";
static const char D_gamegui_00402620[] = "PERF PRINTF";
static const char D_gamegui_0040262C[] = "MEM DEBUG";
static const char D_gamegui_00402638[] = "MEM VIEWER";
static const char D_gamegui_00402644[] = "ZBUFFER";
static const char D_gamegui_0040264C[] = "CHAN TIMES";
static const char D_gamegui_00402658[] = "CULL DEBUG";
static const char D_gamegui_00402664[] = "FREE MEM";
static const char D_gamegui_00402670[] = "ANTIALIAS";
static const char D_gamegui_0040267C[] = "SFX DEBUG";
static const char D_gamegui_00402688[] = "SFX DEBUG2";
static const char D_gamegui_00402694[] = "debug";
static const char D_gamegui_0040269C[] = "NONE";
static const char D_gamegui_004026A4[] = "HZ";
static const char D_gamegui_004026A8[] = "ALL";
static const char D_gamegui_004026AC[] = "frate disp";
static const char D_gamegui_004026B8[] = "defaultmaterial";
static const char D_gamegui_004026C8[] = "abort mode";
static const char D_gamegui_004026D4[] = "plyr lead";
static const char D_gamegui_004026E0[] = "dbg mx speed";
static const char D_gamegui_004026F0[] = "hud";
static const char D_gamegui_004026F4[] = "NONE";
static const char D_gamegui_004026FC[] = "CUR CAR";
static const char D_gamegui_00402704[] = "ALL CARS";
static const char D_gamegui_00402710[] = "ai dbg";
static const char D_gamegui_00402718[] = "NONE";
static const char D_gamegui_00402720[] = "INT";
static const char D_gamegui_00402724[] = "NON INT";
static const char D_gamegui_0040272C[] = "profiling";
static const char D_gamegui_00402738[] = "opts";
static const char D_gamegui_00402740[] = "speed scale";
static const char D_gamegui_0040274C[] = "mindt";
static const char D_gamegui_00402754[] = "inf laps";
static const char D_gamegui_00402760[] = "max txts";
static const char D_gamegui_0040276C[] = "music";
static const char D_gamegui_00402774[] = "sfx";
static const char D_gamegui_00402778[] = "suspension";
static const char D_gamegui_00402784[] = "NONE";
static const char D_gamegui_0040278C[] = "TRANSPARENT";
static const char D_gamegui_00402798[] = "OPAQUE";
static const char D_gamegui_004027A0[] = "tile sort";
static const char D_gamegui_004027AC[] = "replay";
static const char D_gamegui_004027B4[] = "RECORDER OFF";
static const char D_gamegui_004027C4[] = "RECORDER ON";
static const char D_gamegui_004027D0[] = "recordintro";
static const char D_gamegui_004027DC[] = "CAR CLASS C 1";
static const char D_gamegui_004027EC[] = "CAR CLASS C 2";
static const char D_gamegui_004027FC[] = "CAR CLASS C 3";
static const char D_gamegui_0040280C[] = "CAR CLASS B 4";
static const char D_gamegui_0040281C[] = "CAR CLASS B 5";
static const char D_gamegui_0040282C[] = "CAR CLASS B 6";
static const char D_gamegui_0040283C[] = "CAR CLASS A 7";
static const char D_gamegui_0040284C[] = "CAR CLASS A 8";
static const char D_gamegui_0040285C[] = "CAR CLASS A 9";
static const char D_gamegui_0040286C[] = "CAR BONUS 10";
static const char D_gamegui_0040287C[] = "CAR BONUS 11";
static const char D_gamegui_0040288C[] = "BATTLE CAR";
static const char D_gamegui_00402898[] = "car";
static const char D_gamegui_0040289C[] = "shadow";
static const char D_gamegui_004028A4[] = "loscheckoff";
static const char D_gamegui_004028B0[] = "vel cam";
static const char D_gamegui_004028B8[] = "drawingoff";
static const char D_gamegui_004028C4[] = "glare";
static const char D_gamegui_004028CC[] = "framerate";
static const char D_gamegui_004028D8[] = "disp";
static const char D_gamegui_004028E0[] = "masks";
static const char D_gamegui_004028E8[] = "vi gamma";
static const char D_gamegui_004028F4[] = "vi gamdith";
static const char D_gamegui_00402900[] = "vi divot";
static const char D_gamegui_0040290C[] = "vi dither";
static const char D_gamegui_00402918[] = "antialias";
static const char D_gamegui_00402924[] = "txtfilter";
static const char D_gamegui_00402930[] = "txtpersp";
static const char D_gamegui_0040293C[] = "txtdetail";
static const char D_gamegui_00402948[] = "mipmap";
static const char D_gamegui_00402950[] = "x scale";
static const char D_gamegui_00402958[] = "y scale";
static const char D_gamegui_00402960[] = "brightness";
static const char D_gamegui_0040296C[] = "dsbl";
static const char D_gamegui_00402974[] = "good framerate";
static const char D_gamegui_00402984[] = "no midi";
static const char D_gamegui_0040298C[] = "no sfx";
static const char D_gamegui_00402994[] = "no snd";
static const char D_gamegui_0040299C[] = "no particles";
static const char D_gamegui_004029AC[] = "no dobjs";
static const char D_gamegui_004029B8[] = "no fog";
static const char D_gamegui_004029C0[] = "no envdraw";
static const char D_gamegui_004029CC[] = "no sobjs";
static const char D_gamegui_004029D8[] = "no tobjs";
static const char D_gamegui_004029E4[] = "no transp";
static const char D_gamegui_004029F0[] = "no skid";
static const char D_gamegui_004029F8[] = "no rain";
static const char D_gamegui_00402A00[] = "no brdr";
static const char D_gamegui_00402A08[] = "no hud";
static const char D_gamegui_00402A10[] = "no flag";
static const char D_gamegui_00402A18[] = "tools";
static const char D_gamegui_00402A20[] = "models";
static const char D_gamegui_00402A28[] = "cars";
static const char D_gamegui_00402A30[] = "ufo";
static const char D_gamegui_00402A34[] = "intro";
static const char D_gamegui_00402A3C[] = "demo";
static const char D_gamegui_00402A44[] = "credits";
static const char D_gamegui_00402A4C[] = "victory";
static const char D_gamegui_00402A54[] = "taskedit";
static const char D_gamegui_00402A60[] = "aiedit";
static const char D_gamegui_00402A68[] = "texture view";
static const char D_gamegui_00402A78[] = "color bars";
static const char D_gamegui_00402A84[] = "selection";
static const char D_gamegui_00402A90[] = "prof car";

// .data
s32 D_gamegui_00402AB0[1] = { 1 };
s32 D_gamegui_00402AB4[2] = { 1, 0 };
s32 D_gamegui_00402ABC[1] = { 0 };

char *D_gamegui_00402AC0[] = { (char *) D_gamegui_004024B8, (char *) D_gamegui_004024C0,
                               (char *) D_gamegui_004024C8, (char *) D_gamegui_004024D0 };

char *D_gamegui_00402AD0[] = { (char *) D_gamegui_004024D8, (char *) D_gamegui_004024E0,
                               (char *) D_gamegui_004024E8 };

char *D_gamegui_00402ADC[] = { (char *) D_gamegui_004024F0, (char *) D_gamegui_004024F8,
                               (char *) D_gamegui_00402500, (char *) D_gamegui_00402508 };

char *D_gamegui_00402AEC[] = { (char *) D_gamegui_00402510, (char *) D_gamegui_00402518,
                               (char *) D_gamegui_00402524, (char *) D_gamegui_00402530 };

char *D_gamegui_00402AFC[] = { (char *) D_gamegui_00402538, (char *) D_gamegui_00402540,
                               (char *) D_gamegui_00402548, (char *) D_gamegui_00402550,
                               (char *) D_gamegui_00402558 };

char *D_gamegui_00402B10[] = { (char *) D_gamegui_00402560, (char *) D_gamegui_00402568,
                               (char *) D_gamegui_00402570, (char *) D_gamegui_00402578 };

char *D_gamegui_00402B20[] = { (char *) D_gamegui_004025DC, (char *) D_gamegui_004025E4,
                               (char *) D_gamegui_004025F0, (char *) D_gamegui_004025FC,
                               (char *) D_gamegui_00402608, (char *) D_gamegui_00402614,
                               (char *) D_gamegui_00402620, (char *) D_gamegui_0040262C,
                               (char *) D_gamegui_00402638, (char *) D_gamegui_00402644,
                               (char *) D_gamegui_0040264C, (char *) D_gamegui_00402658,
                               (char *) D_gamegui_00402664, (char *) D_gamegui_00402670,
                               (char *) D_gamegui_0040267C, (char *) D_gamegui_00402688 };

char *D_gamegui_00402B60[] = { (char *) D_gamegui_0040269C, (char *) D_gamegui_004026A4,
                               (char *) D_gamegui_004026A8 };

char *D_gamegui_00402B6C[] = { (char *) D_gamegui_004026F4, (char *) D_gamegui_004026FC,
                               (char *) D_gamegui_00402704 };

char *D_gamegui_00402B78[] = { (char *) D_gamegui_00402718, (char *) D_gamegui_00402720,
                               (char *) D_gamegui_00402724 };

char *D_gamegui_00402B84[] = { (char *) D_gamegui_00402784, (char *) D_gamegui_0040278C,
                               (char *) D_gamegui_00402798 };

char *D_gamegui_00402B90[] = { (char *) D_gamegui_004027B4, (char *) D_gamegui_004027C4 };

char *D_gamegui_00402B98[] = { (char *) D_gamegui_004027DC, (char *) D_gamegui_004027EC,
                               (char *) D_gamegui_004027FC, (char *) D_gamegui_0040280C,
                               (char *) D_gamegui_0040281C, (char *) D_gamegui_0040282C,
                               (char *) D_gamegui_0040283C, (char *) D_gamegui_0040284C,
                               (char *) D_gamegui_0040285C, (char *) D_gamegui_0040286C,
                               (char *) D_gamegui_0040287C, (char *) D_gamegui_0040288C };


void func_gamegui_00400370(GuiMenu *menu) {
    GuiMenuOption *menuOption;
    GuiSlider *slider;
    char pad[0x4];
    UnkPlyrExports *player;

    player = uvGetLoadedModule('plyr');
    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, D_gamegui_00402580);
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402584, 0x12, 1.0f, 12.0f, &gNumOpenCars,
                                     &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402590, 0x12, 1.0f, 7.0f, &gNumOpenTracks,
                                     &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040259C, 0x12, 1.0f, 9.0f, &gNumOpenMtracks,
                                     &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004025AC, 0x12, 1.0f, 4.0f, &gNumOpenTourns,
                                     &slider);
    D_gamegui_00402D20 = gMiscExports->func_misc_004038D8(
        menuOption, D_gamegui_004025B8, 0x12, 0.0f,
        (f32) (gUvEmitterExports->func_uvemitter_rom_004027E4() - 1), &D_gamegui_00402D10, &slider);
    gUvGuiExports->uvGuiSliderSetCallback(slider, (s32) &func_gamegui_00401AF8);
    gUvGuiExports->func_uvgui_rom_0040221C(
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004025C4, 0x12, 0.0f,
                                         (f32) (gUvCmidiExports->uvaGetSeqCount() - 1),
                                         &D_gamegui_00402D14, &slider),
        3, func_gamegui_00401D34);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_004025D0, func_gamegui_004023BC);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402694, 2, 0, 15.0f,
                                     &gGameSettings->debugState, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B20);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004026AC, 0x12, 0.0f, 2.0f,
                                     &gGameSettings->dbgFrateDisp, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B60);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004026B8, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDefaultMaterialFlag, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004026C8, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgAbortMode, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004026D4, 0x11, 0.0f, 25000.0f,
                                     &gGameSettings->dbgPlayerLead, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004026E0, 0x11, 0.1f, 300.0f,
                                     &gGameSettings->dbgMxSpeed, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004026F0, 0x12, 0.0f, 3.0f,
                                     &gGameSettings->dbgHudState, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B10);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402710, 0x12, 0.0f, 2.0f,
                                     &gGameSettings->dbgAiDbgState, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B6C);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040272C, 0x12, 0.0f, 2.0f,
                                     &gDebugProfilingState, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B78);
    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, D_gamegui_00402738);
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    if (player != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402740, 0x11, 0.0f, 1.0f,
                                         player->unk28, &slider);
    }
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040274C, 0x11, 0.01f, 1.0f,
                                     &gDebugOptsMinDt, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402754, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgInfLapsFlag, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402760, 0x12, 1.0f, 500.0f,
                                     &gGameSettings->dbgNumMaxTxts, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040276C, 2, 0, 8.0f, &gOptionsMusicVol,
                                     &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402774, 2, 0, 8.0f, &gOptionsSfxVol,
                                     &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402778, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgSuspensionFlag, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004027A0, 0x12, 0.0f, 2.0f,
                                     &gGameSettings->dbgTileSort, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B84);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_004027AC, func_gamegui_0040219C);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004027D0, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgOptsRecordIntro, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B90);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402898, 0x12, 0.0f, 11.0f,
                                     &gDebugOptsCarSelect, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402B98);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040289C, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgOptsCarShadow, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028A4, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgOptsLosCheckOff, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028B0, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgOptsVelCam, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028B8, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgOptsDrawingOff, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028C4, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgOptsGlare, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028CC, 0x12, 0.0f, 4.0f,
                                     &gGameSettings->dbgOptsFrameRate, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402AFC);
    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, D_gamegui_004028D8);
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028E0, 0x12, 0, 1,
                                     &gGameSettings->dbgDispMasks, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028E8, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDispViGamma, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004028F4, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDispViGamDith, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402900, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDispViDivot, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040290C, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDispViDither, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402918, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDispAntialias, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402924, 0x12, 0.0f, 3.0f,
                                     &gGameSettings->dbgDispTxtFilter, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402AC0);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402930, 0x12, 0.0f, 2.0f,
                                     &gGameSettings->dbgDispTxtPersp, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402AD0);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040293C, 0x12, 0.0f, 3.0f,
                                     &gGameSettings->dbgDispTxtDetail, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402ADC);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402948, 0x12, 0.0f, 3.0f,
                                     &gGameSettings->dbgDispMipmap, &slider);
    gUvGuiExports->func_uvgui_rom_00403CA4(slider, (s32) &D_gamegui_00402AEC);
    D_gamegui_00402D18 = gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402950, 2, 0.0f, 2.0f,
                                                          &D_gamegui_00402AB0, &slider);
    D_gamegui_00402D1C = gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402958, 2, 0.0f, 2.0f,
                                                          &D_gamegui_00402AB4, &slider);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402960, 0x11, -1.0f, 1.0f,
                                     &D_gamegui_00402ABC, &slider);
    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, D_gamegui_0040296C);
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402974, 0x12, 0.0f, 1.0f,
                                     &gGameSettings->dbgDisableGoodFramera, &slider);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402984, func_gamegui_00401D94);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_0040298C, func_gamegui_00401DC4);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402994, func_gamegui_00401DF4);
    if (gUvPfxExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_0040299C, 0x12, 0.0f, 1.0f,
                                         gUvPfxExports->sNoParticlesFlag, &slider);
    }
    if (gUvDobjExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029AC, 0x12, 0.0f, 1.0f,
                                         gUvDobjExports->sNoDobjsFlag, &slider);
    }
    if (gUvEnvExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029B8, 0x12, 0.0f, 1.0f,
                                         gUvEnvExports->unk28, &slider);
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029C0, 0x12, 0.0f, 1.0f,
                                         gUvEnvExports->unk2C, &slider);
    }
    if (gUvTerraExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029CC, 0x12, 0.0f, 1.0f,
                                         gUvTerraExports->sNoSobjsFlag, &slider);
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029D8, 0x12, 0.0f, 1.0f,
                                         gUvTerraExports->sNoTobjsFlag, &slider);
    }
    if (gUvGfxStateExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029E4, 0x12, 0.0f, 1.0f,
                                         gUvGfxStateExports->unk78, &slider);
    }
    if (gSkidExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029F0, 0x12, 0.0f, 1.0f,
                                         gSkidExports->unk14, &slider);
    }
    if (gRainExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_004029F8, 0x12, 0.0f, 1.0f,
                                         gRainExports->unk24, &slider);
    }
    if (gScrnExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402A00, 0x12, 0.0f, 1.0f,
                                         gScrnExports->unk1C, &slider);
    }
    if (player != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402A08, 0x12, 0.0f, 1.0f,
                                         player->unk24, &slider);
    }
    if (gFlagExports != NULL) {
        gMiscExports->func_misc_004038D8(menuOption, D_gamegui_00402A10, 0x12, 0.0f, 1.0f,
                                         gFlagExports->unk18, &slider);
    }
}

void func_gamegui_004014F8(GuiMenu *menu) {
    GuiMenuOption *menuOption;

    menuOption = gUvGuiExports->uvGuiGetMenuOption(gUvGuiExports->uvGuiNewMenuOption());
    gUvGuiExports->uvGuiSetMenuOptionName(menuOption, D_gamegui_00402A18);
    gUvGuiExports->uvGuiAddMenuOption(menu, menuOption);
    D_gamegui_00402D24 =
        gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A20, func_gamegui_0040203C);
    D_gamegui_00402D28 =
        gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A28, func_gamegui_0040203C);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A30, func_gamegui_00402074);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A34, func_gamegui_004020DC);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A3C, func_gamegui_0040209C);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A44, func_gamegui_004020BC);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A4C, func_gamegui_00402110);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A54, func_gamegui_00402130);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A60, func_gamegui_00402088);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A68, func_gamegui_00402144);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A78, func_gamegui_00402158);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A84, func_gamegui_0040216C);
    gMiscExports->func_misc_00403BEC(menuOption, D_gamegui_00402A90, func_gamegui_00402180);
}

void func_gamegui_00401748(void) {
    UvGui_Exports *temp_v1;
    s32 i;

    if (gDebugEnable == 0) {
        return;
    }

    for (i = 0; i < 4; i++) {
        if ((gUvContExports->uvControllerButtonHeld(i, 0x20) != 0)
            && (gUvContExports->uvControllerButtonHeld(i, 0x10) != 0)) {
            if (gUvGuiExports == NULL) {
                if ((u32) _uvMemGetBlocksSize() < 150000) {
                    return;
                }
                gUvGuiExports = uvLoadModule('ugui');
                D_gamegui_00402D0C = uvLoadModule('dled');
                uvLoadFile('UVFT', 3);
            }
            if (gUvGuiExports != NULL) {
                gUvGuiExports->func_uvgui_rom_004015B8(&D_gamegui_00402C68.gui, 0x10, i);
                D_80025D7C = i;
            }
            break;
        }
    }
    if ((gUvContExports->uvControllerButtonPress((u8) D_gamegui_00402C68.gui.contNo, 0x800) != 0)
        && (D_gamegui_00402C68.unk9C != NULL)) {
        switch (D_gamegui_00402C68.unkC) {
            case 0:
                D_gamegui_00402C68.unk0 = 1;
                break;
            case 1:
                D_gamegui_00402C68.unk0 = 1;
                break;
            case 2:
                D_gamegui_00402C68.unk0 = 0;
                break;
        }
        if (D_gamegui_00402C68.unk0 != 0) {
            if ((gUvGuiExports == NULL) && ((u32) _uvMemGetBlocksSize() < 0x249F0)) {
                D_gamegui_00402C68.unk0 = 0;
                return;
            }
            func_gamegui_00401E7C();
            D_gamegui_00402C68.unk9C();
            D_gamegui_00402C68.unk0 = 1;
            gUvGuiExports->func_uvgui_rom_004016E0(0);
            D_gamegui_00402C68.unkC = 2;
        } else {
            D_gamegui_00402C68.unkC = 0;
        }
    }
    if (gUvContExports->uvControllerButtonPress((u8) D_gamegui_00402C68.gui.contNo, 0x400) != 0) {
        switch (D_gamegui_00402C68.unkC) {
            case 0:
                D_gamegui_00402C68.unk0 = 1;
                break;
            case 1:
                D_gamegui_00402C68.unk0 = 0;
                break;
            case 2:
                D_gamegui_00402C68.unk0 = 1;
                break;
        }
        if (D_gamegui_00402C68.unk0 != 0) {
            if ((gUvGuiExports == NULL) && ((u32) _uvMemGetBlocksSize() < 0x249F0)) {
                D_gamegui_00402C68.unk0 = 0;
                return;
            }
            func_gamegui_00401E7C();
            func_gamegui_004000B0();
            gUvGuiExports->func_uvgui_rom_004016E0(0);
            D_gamegui_00402C68.unkC = 1;
            D_gamegui_00402C68.unk0 = 1;
        } else {
            D_gamegui_00402C68.unkC = 0;
        }
    }
    if (D_gamegui_00402C68.unk0 != 0) {
            gUvGuiExports->func_uvgui_rom_004016A0(&D_gamegui_00402C68.gui, 1);
            gUvGuiExports->func_uvgui_rom_00401290(&D_gamegui_00402C68.gui);
    }
}

void func_gamegui_00401A7C(void) {
    if (D_gamegui_00402C68.unk0 != 0) {
        gUvGuiExports->uvGuiRender(&D_gamegui_00402C68.gui);
        return;
    }
    gUvFontExports->uvFontGenDList();
}

void func_gamegui_00401AD8(s32 arg0) {
    if (gDebugEnable) {
        D_gamegui_00402C68.unk0 = arg0;
    }
}

void func_gamegui_00401AF8(GuiSlider *slider) {
    f32 var_fv0;
    static s32 D_gamegui_00402BC8 = -1;
    static s32 D_gamegui_00402BCC = -1;

    if (D_gamegui_00402D20->unkC == 3) {
        if (D_gamegui_00402BC8 != -1) {
            gUvEmitterExports->func_uvemitter_rom_0040075C(D_gamegui_00402BC8);
        }
        D_gamegui_00402BCC = -1;
        D_gamegui_00402BC8 = -1;
        return;
    }
    if (D_gamegui_00402D10 != D_gamegui_00402BCC) {
        if (D_gamegui_00402BC8 != -1) {
            gUvEmitterExports->func_uvemitter_rom_0040075C(D_gamegui_00402BC8);
        }
        gUvGuiExports->uvGuiSliderSetLabel(slider, gSndExports->func_snd_004023F4(D_gamegui_00402D10));
        D_gamegui_00402BC8 = gUvEmitterExports->uvGetEmitter();
        if (D_gamegui_00402BC8 != -1) {
            D_gamegui_00402BCC = D_gamegui_00402D10;
            gUvEmitterExports->func_uvemitter_rom_004007B4(D_gamegui_00402BC8, D_gamegui_00402D10);
            gUvEmitterExports->uvEmitterProps(D_gamegui_00402BC8, 5, 0, 0);
            var_fv0 = gSndExports->func_snd_004023A8(D_gamegui_00402D10) / 22050.0f;
            if (var_fv0 < 0.0001f) {
                var_fv0 = 0.0001f;
            } else if (var_fv0 > 2.0f) {
                var_fv0 = 2.0f;
            }
            gUvEmitterExports->func_uvemitter_rom_00400D48(D_gamegui_00402BC8, var_fv0);
            gUvEmitterExports->func_uvemitter_rom_00401010(D_gamegui_00402BC8);
        }
    }
}

u32 sColorDitherTypeTable[4] = { 0, 0x40, 0x80, 0xC0 };
u32 sAlphaDitherTypeTable[4] = { G_AD_NOTPATTERN, G_AD_PATTERN, G_AD_NOISE, G_AD_DISABLE };

s32 s[] = { 0xFFFFFFFF, 0,          0x3000,     0x2000,     0xFFFFFFFF, 0,
            0x80000,    0xFFFFFFFF, 0,          0x20000,    0x40000,    0xFFFFFFFF,
            0xFC26A004, 0xFC887E04, 0xFC887E04, 0xFFFFFFFF, 0x1F1093FF, 0x8810F3FF,
            0x8810F3FF, 0xFFFFFFFF, 0x10000,    0x10000, 0 };

s32 D_gamegui_00402C50[] = { 0x002C0000, __entrypoint_func_gamegui_400000 };

void func_gamegui_00401D34(GuiMenuItem* arg0) {
    GuiSlider* slider = arg0->slider;
    if (slider->state != 1) {
        gSndExports->sndSetMusic((u16)D_gamegui_00402D14);
        gSndExports->sndSetMusicState(0U);
    }
}


void func_gamegui_00401D94(void *arg0) {
    gUvCmidiExports->uvaSeqStop();
}

void func_gamegui_00401DC4(void *arg0) {
    gUvEmitterExports->func_uvemitter_rom_0040290C();
}

void func_gamegui_00401DF4(void *arg0) {
    gUvAudiomgrExports->func_uvaudiomgr_rom_004012E4();
}

void func_gamegui_00401E24(void *arg0) {
    if (gGameSettings->numPlayers >= 2) {
        gGameSettings->numAiCars = 0;
    }
    gGameSettings->newGameState = GAME_STATE_RACE;
}

void func_gamegui_00401E50(void *arg0) {
    if (gGameSettings->numPlayers < 2) {
        gGameSettings->numPlayers = 2;
    }
    gGameSettings->newGameState = GAME_STATE_BATTLE;
}

void func_gamegui_00401FE0(void);

void func_gamegui_00401E7C(void) {
    s32 sp2C;

    sp2C = gGameSettings->unk8C;
    if (gGameSettings->unk18C != 0) {
        if (gUvGuiExports == NULL) {
            gUvGuiExports = uvLoadModule('ugui');
            D_gamegui_00402D0C = uvLoadModule('dled');
            uvLoadFile('UVFT', 3);
        }
        gUvGuiExports->uvGuiInit(&D_gamegui_00402C68.gui);
        gUvGuiExports->func_uvgui_rom_0040126C(&D_gamegui_00402C68.gui, 0x17, 0x128, 0x11, 0xDE);
        gUvGuiExports->func_uvgui_rom_004015B8(&D_gamegui_00402C68.gui, 1, 0x8000);
        gUvGuiExports->func_uvgui_rom_004015B8(&D_gamegui_00402C68.gui, 2, 0x4000);
        gUvGuiExports->func_uvgui_rom_004015B8(&D_gamegui_00402C68.gui, 0x11, 0);
        gUvGuiExports->func_uvgui_rom_004015B8(&D_gamegui_00402C68.gui, 0x12, 1);
        gUvGuiExports->func_uvgui_rom_004015B8(&D_gamegui_00402C68.gui, 0x10, sp2C);
        func_gamegui_00401FE0();
        D_gamegui_00402C68.unk0 = 0;
        D_gamegui_00402C68.unkC = 0;
    }
}

void func_gamegui_00401FE0(void) {
    gUvGuiExports->func_uvgui_rom_00401614(&D_gamegui_00402C68.gui, -1, 3);
    gUvDebugExports->func_uvdbg_rom_004029D4(3);
}

void func_gamegui_00402030(void (*arg0)(void)) {
    D_gamegui_00402C68.unk9C = arg0;
}

void func_gamegui_0040203C(void *arg0) {
    if (arg0 == D_gamegui_00402D28) {
        gGameSettings->sceneEditorMode = MODE_CAR_EDITOR;
    } else {
        gGameSettings->sceneEditorMode = MODE_SCENE_EDITOR;
    }
    gGameSettings->newGameState = GAME_STATE_SCENE_EDITOR;
}

void func_gamegui_00402074(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_UFO_CAMERA;
}

void func_gamegui_00402088(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_AI_EDIT;
}

void func_gamegui_0040209C(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_DEMO;
    gGameSettings->replayCam = DEMO_REPLAY_CAM_ON;
}

void func_gamegui_004020BC(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_CREDITS;
    gGameSettings->replayCam = DEMO_REPLAY_CAM_ON;
}

void func_gamegui_004020DC(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_INTRO;
    gGameSettings->currentTrack = TRACK_INTRO1;
    gGameSettings->finishedIntroCount = 0;
    gGameSettings->replayCam = INTRO_REPLAY_CAM_ON;
    gGameSettings->playIntroFlag = 1;
}

void func_gamegui_00402110(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_VICTORY;
    gGameSettings->currentTrack = TRACK_FINISH;
}

void func_gamegui_00402130(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_TASK_EDITOR;
}

void func_gamegui_00402144(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_TEXTURE_VIEWER;
}

void func_gamegui_00402158(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_COLOR_BARS;
}

void func_gamegui_0040216C(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_SELECTION;
}

void func_gamegui_00402180(void *arg0) {
    gGameSettings->newGameState = GAME_STATE_PROFILE_CAR;
}

void func_gamegui_00402194(void) {
}

void func_gamegui_0040219C(void *arg0) {
    if (gGameSettings->introReplayState != 0) {
        gGameSettings->introReplayState = 0;
    } else {
        gGameSettings->introReplayState = 1;
        gGameSettings->newGameState = gGameSettings->currentGameState;
    }
}

void func_gamegui_004021D4(void) {
}

void func_gamegui_004021DC(s32 arg0) {
    Gfx **gdl;
    s32 features;

    gdl = gUvGfxMgrExports->uvGetDisplayListHead();
    gDPPipeSync(gdl[0]++);
    gDPSetColorDither(gdl[0]++, sColorDitherTypeTable[gGameSettings->colorDither]);
    gDPSetAlphaDither(gdl[0]++, sAlphaDitherTypeTable[gGameSettings->alphaDither]);
    gUvGfxStateExports->func_uvgfxstate_rom_0040146C(-1);
    if (!gGameSettings->dbgDispAntialias) {
        gUvGfxStateExports->func_uvgfxstate_rom_00401460(0x400000);
    }
    if (gGameSettings->dbgDispViGamma) {
        features = OS_VI_GAMMA_ON;
    } else {
        features = OS_VI_GAMMA_OFF;
    }
    if (gGameSettings->dbgDispViGamDith) {
        features |= OS_VI_GAMMA_DITHER_ON;
    } else {
        features |= OS_VI_GAMMA_DITHER_OFF;
    }
    if (gGameSettings->dbgDispViDither) {
        features |= OS_VI_DITHER_FILTER_ON;
    } else {
        features |= OS_VI_DITHER_FILTER_OFF;
    }
    if (gGameSettings->dbgDispViDivot) {
        features |= OS_VI_DIVOT_ON;
    } else {
        features |= OS_VI_DIVOT_OFF;
    }
    osViSetSpecialFeatures(features);
}

void func_gamegui_00402358(s32 arg0) {
    CallbackList *callbackList;

    gUvChanExports->func_uvchannel_rom_00400288(arg0, 6, &callbackList, 0);
    gUvCbckExports->uvAddCallback(callbackList, func_gamegui_004021DC, NULL, 0x21);
}

u8 func_gamegui_004023B0(void) {
    return D_gamegui_00402C68.unk0;
}

void func_gamegui_004023BC(void *arg0) {
    s32 count;
    s32 i;
    int s1;
    ParsedUVTX *v0 = NULL;
    u16 v1;
    s1 = 0;

    count = uvGetFilesCount('UVTX');
    for (i = 0; i < count; i++) {
        if (uvGetFileInstanceCount('UVTX', i) > 0) {
            v0 = uvGetLoadedFile('UVTX', i);
            v1 = v0->unk1A;
            s1 += v1;
        }
    }
}
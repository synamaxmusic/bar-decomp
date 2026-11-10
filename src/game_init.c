// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void uvUnloadModule(s32);
void _uvScInitClientList(void);
void uvSysInit(void);
void uvSetGameState(s32);                     /* extern */
void uvShowNoController(void);

extern s32 D_8001F7D4;
extern s32 D_8001F7D8;
extern s32 D_80020F90;
extern s32 D_80020FA0;
extern f32 D_80020FF8;
extern f32 D_80020FFC;
extern UnkStruct_8002D1A4* gGameExports;

// .data
s32 D_8001F630 = 0x3000;

#ifdef NON_MATCHING
extern s32 gDebugEnable;
#endif

void uvGameInit(void) {
    s16 i;

    gGameSettings->unk6EAA = 0;
    gGameSettings->playerNameBuffer = 0;
    gGameSettings->playerNameLength = 0;
    gGameSettings->unk6FA0 = 0.009999999776f;
    gGameSettings->unk7C = 0.0f;
    gGameSettings->currentGameState = INIT;
    gGameSettings->pauseFlag = 0;
    gGameSettings->debugState = 0;
    gGameSettings->unk18C = 1;
    gGameSettings->dbgNumMaxTxts = 0x1F4;
    gGameSettings->dbgTileSort = 1;
    gGameSettings->unk80 = 0.1f;
    gGameSettings->optionsSfxVol = 8;
    gGameSettings->optionsMusicVol = 8;
    gGameSettings->optionsSpeechVol = 8;
    gGameSettings->numPlayers = 1;
    gGameSettings->currentTrack = TRACK_NONE;
    gGameSettings->introReplayState = 0;
    gGameSettings->dbgOptsRecordIntro = 0;
    gGameSettings->dbgOptsGlare = 1;
    gGameSettings->dbgOptsFrameRate = 0;
    gGameSettings->unk94 = 0;
    gGameSettings->dbgAbortMode = 0;
    gGameSettings->unk6E9C = 0;
    gGameSettings->colorDither = 0;
    gGameSettings->alphaDither = 3;
    gGameSettings->dbgDispViGamma = 0;
    gGameSettings->dbgDispViGamDith = 0;
    gGameSettings->dbgDispViDither = 1;
    gGameSettings->dbgDispViDivot = 1;
    gGameSettings->dbgDispAntialias = 1;
    gGameSettings->dbgOptsCarShadow = 1;
    gGameSettings->numAiCars = 7;
    gGameSettings->dbgSuspensionFlag = 1;
    gGameSettings->dbgTrackWeather = 0;
    gGameSettings->dbgFrateDisp = 1;
    gGameSettings->unk50 = 0;
    gGameSettings->dbgMxSpeed = 300.0f;

    for (i = 0; i < 4; i++) {
        gGameSettings->playerCarInfo[i].currentColor = i;
        gGameSettings->playerCarInfo[i].currentCar = (i % 3) + 1;
        gGameSettings->playerCarInfo[i].transmissionType = 1;

    }

    for (i = 0; i < 16; i++) {
        gGameSettings->playerName[i] = ' ';
        gGameSettings->unk6EB0[i] = ' ';
    }

    gGameSettings->playerName[15] = '\0';
    gGameSettings->unk6EB0[15] = '\0';
    gGameSettings->currentLanguage = LANGUAGE_EN;
    gGameSettings->currentTournament = TOURN_NOVICE;
    gGameSettings->numTournRaces = TOURN_NOVICE_RACE_COUNT;
    gGameSettings->initFlag = 1;
    gGameSettings->optionsStereoMono = OPTIONS_SOUND_STEREO;
    gGameSettings->optionsSpeed = OPTIONS_SPEED_MPH;
    gGameSettings->unk17A = 1;
    gGameSettings->optionsMap = OPTIONS_MAP_ZOOM;
    gGameSettings->optionsDisplay = OPTIONS_DISPLAY_ON;
    gGameSettings->unk17E = 0;
    gGameSettings->unk17F = 0;
    gGameSettings->unk6F74 = 1;
    gGameSettings->unk6EAC = 0;
    gGameSettings->unk6EAE = 0;
    gGameSettings->replayCam = 0;
    gGameSettings->finishedIntroCount = 0;
    gGameSettings->unk10 = 0;
    gGameSettings->unk704C[0] = 0;
    gGameSettings->unk704C[1] = 0;
    gGameSettings->unk7058 = 0;
    gGameSettings->unk705C = 0;
    gGameSettings->unk7060 = 1;
    gGameSettings->unk6FB8 = 0x3639;
    gGameSettings->unk6FBC = 'NNSE';
    gGameSettings->unk6FB0 = "BEETLE RACING";
    gGameSettings->unk6FB4 = "\0";

    for (i = 0; i < 4; i++) {
        gGameSettings->unk6F78[i] = (i * 0x19) + 0x19;
    }

    for (i = 0; i < 8; i++) {
        gGameSettings->unk6EC0[i] = 0;
    }

    gGameSettings->playIntroFlag = 1; // zero goes immediately to main menu
    gGameSettings->currentTrack = TRACK_COVENTRY_COVE;
    uvSetGameState(SELECTION);
    if (!gUvContExports->uvControllerPlugged(0)) {
        uvShowNoController();
    }
    gUvGfxMgrExports->uvGfxEnableGamma(gGameSettings->dbgDispViGamma);
    for (i = 0; i < 8; i++) {
        gGameSettings->unk7084[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        gGameSettings->unk7064[i] = 0;
        gGameSettings->unk7074[i] = 0;
    }

    gGameSettings->dbgFrateDisp = 0;
    gGameSettings->dbgHudState = 0;
    gGameSettings->unk18C = 0;
    while (gUvContExports->uvIOUpdate() != 0) {
        #ifdef NON_MATCHING
        gDebugEnable = 1;
        #endif
        gGameExports->unk4();
        if (D_8001F7D4 != 0) {
            D_8001F7D4 = 0;
            D_8001F7D8 = 0;
            gGameSettings->newGameState = gGameSettings->currentGameState;
        }
        if (gGameSettings->newGameState != INIT) {
            uvSetGameState(gGameSettings->newGameState);
        }
    }
}

void uvSetGameState(s32 gameStateId) {
    s32 timesLoaded;
    s32 i;
    s32 pad;
    f32 sec;

    if (gUvGfxMgrExports != NULL) {
        gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
        if (gGameSettings->currentGameState != INIT) {
            gGameExports->unkC(gGameSettings->currentGameState);
        }
        timesLoaded = uvGetFileInstanceCount('UVMO', uvGetModuleFileId('MIDI'));
        for (i = 0; i < timesLoaded; i++) {
            uvUnloadModule('MIDI');
        }

        timesLoaded = uvGetFileInstanceCount('UVMO', uvGetModuleFileId('EMIT'));
        for (i = 0; i < timesLoaded; i++) {
            uvUnloadModule('EMIT');
        }

        timesLoaded = uvGetFileInstanceCount('UVMO', uvGetModuleFileId('AMGR'));
        for (i = 0; i < timesLoaded; i++) {
            uvUnloadModule('AMGR');
        }
        gUvContExports->func_uvcont_rom_00401720();
        _uvScInitClientList();

        sec = uvClkGetSec(0x6A);

        while (sec + 0.2f < uvClkGetSec(0x6A)) {
        }

    }
    gGameSettings->currentGameState = gameStateId;
    gGameSettings->newGameState = INIT;
    uvSysInit();
    gSkidExports = 0;
    gSprayExports = 0;
    gGlareExports = 0;
    gAiExports = 0;
    gFlagExports = 0;
    gTdataExports = 0;
    gVolTestExports = 0;
    gBattleExports = 0;
    gPowerupExports = 0;
    gLetterExports = 0; // Ladybug pickups
    gWeaponExports = 0;
    gRainExports = 0;   // Snow effect in Mount Mayhem
    gRumbleExports = 0;
    gGameExports = uvLoadModule('game');
    gGameExports->unk8(gameStateId);
}

char* gNoControllerStrings[] = {"NO CONTROLLER IN", "CONTROLLER SOCKET 1", "PLEASE POWER OFF AND", "ATTACH A CONTROLLER"};

// Displays error message and loops forever when no controllers are connected
void uvShowNoController(void) {
    s32 i;
    s32 line;
    s32 s4;
    s32 s3;

    // This font load is overriden by the uvSetFont call below
    uvLoadFile('UVFT', 1);
    while (1) {
        gUvFontExports->uvSetFont(5); // font ID
        gUvFontExports->uvFontColor(0, 100, 200, 255); // RGBA color
        gUvGfxMgrExports->uvGfxBegin();
        gUvGfxMgrExports->func_uvgfxmgr_rom_00401BD4(0, 0x13F, 0, 0xEF);  // bg size?
        gUvGfxMgrExports->uvGfxFillRect(0, 0, 0);            // black BG color

        for (line = 0; line < 4; line++) {
            // clang-format off
            gUvFontExports->uvFontPrintStr(160 - (gUvFontExports->uvFontWidth(gNoControllerStrings[line]) / 2), 150 - line * 20,
                              gNoControllerStrings[line]);
            // clang-format on
        }

        gUvFontExports->uvFontGenDList();
        gUvGfxMgrExports->uvGfxEnd();
    }
}

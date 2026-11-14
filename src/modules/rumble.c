// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void func_rumble_00400048(void);
void func_rumble_00400050(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_rumble_00400138(void);

// .bss
s32 D_unused_rumble_00400450[2];
f32 D_rumble_00400458[4][8];
f32 D_rumble_004004D8[4][8];
s32 D_rumble_00400558[4];
u8 D_rumble_00400568[4];

// .data
u8 D_rumble_004003E0[8][12] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 },
    { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

void __entrypoint_func_rumble_400000(Rumble_Exports *exports);

void __entrypoint_func_rumble_400000(Rumble_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_rumble_00400048 = func_rumble_00400048;
    exports->func_rumble_00400050 = func_rumble_00400050;
    exports->func_rumble_00400138 = func_rumble_00400138;
}

void func_rumble_00400048(void) {
}

void func_rumble_00400050(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 idx;

    arg1 *= 7.0f;
    idx = arg1;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 8) {
        idx = 7;
    }
    if (D_rumble_00400458[arg0][idx] > 0.0f) {
        if (D_rumble_004004D8[arg0][idx] < arg3) {
            D_rumble_004004D8[arg0][idx] = D_rumble_004004D8[arg0][idx];
        } else {
            D_rumble_004004D8[arg0][idx] = arg3;
        }
    } else {
        D_rumble_004004D8[arg0][idx] = arg3;
    }
    if (arg2 < D_rumble_00400458[arg0][idx]) {
        D_rumble_00400458[arg0][idx] = D_rumble_00400458[arg0][idx];
        return;
    }
    D_rumble_00400458[arg0][idx] = arg2;
}

void func_rumble_00400138(void) {
    s32 stopRumble;
    s32 idx;
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        D_rumble_00400558[i]--;
    }

    stopRumble = gGameSettings->pauseFlag || gGameSettings->unk6E9C || gGameSettings->introReplayState
                 || ((gGameSettings->currentGameState != GAME_STATE_RACE) && (gGameSettings->currentGameState != GAME_STATE_BATTLE));

    for (i = 0; i < 4; i++) {
        if ((stopRumble) || ((gGameSettings->unk98[i] == 0))) {
            for (j = 0; j < 8; j++) {
                D_rumble_00400458[i][j] = 0.0f;
                D_rumble_004004D8[i][j] = 0.0f;
            }

            gUvContExports->uvControllerStopRumblePak(i);
            if (D_rumble_00400558[i] < 0) {
                gUvContExports->func_uvcont_rom_00401658(i);
                D_rumble_00400558[i] = 0x1E;
            }
            continue;
        }
        D_rumble_00400568[i] = ((s32) (D_rumble_00400568[i] + 1) % 12);
        idx = 0;
        for (j = 0; j < 8; j++) {
            D_rumble_004004D8[i][j] -= gGameSettings->unk80;
            if (D_rumble_004004D8[i][j] < 0.0f) {
                D_rumble_00400458[i][j] -= gGameSettings->unk80;
            }
            if ((D_rumble_00400458[i][j] > 0.0f) && (D_rumble_004004D8[i][j] < 0.0f)) {
                idx = j;
            }
        }
        if (D_rumble_004003E0[idx][D_rumble_00400568[i]] != 0) {
            gUvContExports->uvControllerStartRumblePak(i);
        } else {
            gUvContExports->uvControllerStopRumblePak(i);
        }
    }
}

s32 D_00400440[] = { 0x000C0000, __entrypoint_func_rumble_400000, 0, 0 };
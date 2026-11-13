// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void func_mult7_004000D4(void);
void func_mult7_004000DC(void);

void __entrypoint_func_mult7_400000(Mult7_Exports* arg0) {
    uvUpdateFileAllocPtr(arg0);
    arg0->func_mult7_004000D4 = func_mult7_004000D4;
    arg0->func_mult7_004000DC = func_mult7_004000DC;
#line 1
    gLetterExports = uvLoadModule('lttr');
    gPowerupExports = uvLoadModule('pwup');
    gWeaponExports = uvLoadModule('wpon');
    gBattleExports = uvLoadModule('batl');
    gTdataExports = uvLoadModule('tdta');
    if (gGameSettings->currentGameState != GAME_STATE_TASK_EDITOR) {
        gTdataExports->unk24();
    }
    uvUnloadModule('tdta');
    gTdataExports = NULL;
}

void func_mult7_004000D4(void) {

}

void func_mult7_004000DC(void) {

}

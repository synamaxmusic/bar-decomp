// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"

void func_mult6_0040011C(void);
void func_mult6_00400124(void);

void __entrypoint_func_mult6_400000(Mult6_Exports* arg0) {
    void* temp_v0;

    uvUpdateFileAllocPtr(arg0);
    arg0->func_mult6_0040011C = &func_mult6_0040011C;
    arg0->func_mult6_00400124 = &func_mult6_00400124;
    gLetterExports = uvLoadModule('lttr');
    gPowerupExports = uvLoadModule('pwup');
    gWeaponExports = uvLoadModule('wpon');
    gBattleExports = uvLoadModule('batl');
    gTdataExports = uvLoadModule('tdta');
    gVolTestExports = uvLoadModule('volt');
    gEnvExports->unk1C(gVolTestExports->unk4(0x27), 1);
    if (gGameSettings->currentGameState != GAME_STATE_TASK_EDITOR) {
        gTdataExports->unk24();
    }
    uvUnloadModule('tdta');
    gTdataExports = NULL;
}

void func_mult6_0040011C(void) {

}

void func_mult6_00400124(void) {

}

#include "common.h"
#include "module.h"
#include "global_exports.h"
#include "snd.h"

typedef struct UnkStruct_snd_004064C8_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;  /* inferred */
    /* 0x08 */ f32 sampleRate;  /* inferred */
    /* 0x0C */ f32 unkC;  /* inferred */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ char pad14[8];
    /* 0x1C */ s32 unk1C; /* inferred */
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s16 soundId; /* inferred */
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;  /* inferred */
} UnkStruct_snd_004064C8; /* size = 0x28 */

typedef struct ReplayExports_s {
    u8 pad[0x28];
    s32 (*unk28)(s32, s32);
    f32 (*unk2C)(s32, s32);
} ReplayExports;

typedef struct UnkStruct_snd_00406198_s {
    /* 0x00 */ u8 *soundName;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ f32 sampleRate;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u8 unk10; 
    /* 0x11 */ u8 unk11; 
    /* 0x12 */ u8 unk12; 
    /* 0x13 */ u8 unk13; 
    /* 0x14 */ u8 unk14; 
    /* 0x15 */ u8 unk15; 
    /* 0x16 */ u8 unk16; 
    /* 0x17 */ u8 unk17; 
    /* 0x18 */ u8 unk18;      /* inferred */
} UnkStruct_snd_00406198;     /* size = 0x1C */

typedef struct UnkStruct_0040619C_s {
    s32 data[8];
} UnkStruct_0040619C;

typedef enum SoundType_e {
    SOUND_TYPE_SFX,
    SOUND_TYPE_SPEECH,
    SOUND_TYPE_UI
} SoundType;


void func_snd_004004F8(void);
void func_snd_004005C8(void *arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                       UnkStruct_uvemitter_rom_004008CC *arg6);
s16 func_snd_00400750(UnkStruct_004005C8 *arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4);
void sndPlaySound(s16 arg0, s32 arg1);
s16 func_snd_00400A64(u8 arg0);
s32 func_snd_00400B0C(s16 arg0);
void func_snd_00400B54(s16 arg0, f32 arg1, f32 arg2, f32 arg3, UnkStruct_uvemitter_rom_004008CC *arg4);
s32 func_snd_00400CD8(s32 arg0);
s32 func_snd_00400DDC(s32 arg0);
void func_snd_00400E90(s32 arg0);
void func_snd_00400EA0(s32 arg0);
void func_snd_00400EB4(s32 arg0);
void func_snd_00400EC0(void);
void func_snd_00401038(void);
void sndSetMusic(u16 arg0);
void sndSetMusicState(u8 arg0);
void sndSetMusicVol(s32 arg0);
void sndSetSfxVol(s32 arg0);
void sndSetSpeechVol(s32 arg0);
f32 func_snd_004014B4(void);
f32 func_snd_004014C4(void);
void func_snd_004014D4(s32 arg0);
void func_snd_004014E0(s16 arg0);
void func_snd_00401564(u8 arg0);
void func_snd_00401650(void);
u8 func_snd_00401694(UnkStruct_004005C8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s16 func_snd_00401800(UnkStruct_004005C8 *arg0, s16 arg1, s32 arg2, f32 arg3);
u8 func_snd_00401914(UnkStruct_004005C8 *arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                     Vec3F* arg6);
s32 func_snd_00401A28(UnkStruct_004005C8 *arg0);
u8 func_snd_00401AA8(UnkStruct_004005C8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_snd_00401CDC(UnkStruct_004005C8 *arg0);
void func_snd_00401D14(UnkStruct_004005C8 *arg0);
void func_snd_00401D54(UnkStruct_004005C8 *arg0, u8 arg1);
void func_snd_00401DA0(UnkStruct_004005C8 *arg0, Vec3F* arg1);
void func_snd_00401E08(UnkStruct_004005C8 *arg0, UnkStruct_uvemitter_rom_004008CC *arg1);
void func_snd_00401E70(UnkStruct_004005C8 *arg0, f32 arg1);
void func_snd_00401EB8(UnkStruct_004005C8 *arg0, f32 arg1);
void func_snd_00401F48(UnkStruct_004005C8 *arg0, f32 arg1);
void func_snd_00401FD8(UnkStruct_004005C8 *arg0, u8 arg1);
s16 func_snd_00402020(UnkStruct_004005C8 *arg0);
f32 func_snd_00402084(UnkStruct_004005C8 *arg0);
f32 func_snd_004020D0(UnkStruct_004005C8 *arg0);
f32 func_snd_0040211C(UnkStruct_004005C8 *arg0);
void func_snd_0040216C(UnkStruct_004005C8 *arg0, f32 arg1);
void func_snd_0040221C(UnkStruct_004005C8 *arg0, f32 arg1);
void func_snd_004022D0(UnkStruct_004005C8 *arg0, f32 arg1);
void func_snd_0040231C(UnkStruct_004005C8 *arg0, f32 arg1);
f32 func_snd_00402368(s32 arg0);
s32 func_snd_00402388(s32 arg0);
s32 func_snd_004023A8(s32 arg0);
s32 func_snd_004023D4(s32 arg0);
u8 *func_snd_004023F4(s32 arg0);
void func_snd_00402424(void);
void func_snd_00402504(UnkStruct_004005C8 *arg0);
void func_snd_0040252C(s32 arg0);
u8 func_snd_004025EC(s32 arg0);
void func_snd_004025FC(s32 arg0);
void func_snd_0040264C(s32 arg0);
void func_snd_00402660(s32 arg0);
s32 func_snd_004027E8(UnkStruct_004005C8 *arg0);
void func_snd_0040284C(s32 arg0);
void func_snd_00402B40(s32 arg0, f32 arg1);
void func_snd_00402DC0(u8 arg0);
void func_snd_00402E1C(void);
void func_snd_0040260C(void);
s32 func_snd_00400854(s16 arg0, s32 arg1, f32 arg2, s32 arg3);

// .bss
s32 B_snd_004063B0[2]; // unreferenced padding
u8 D_snd_004063B8[0x100];
u8 D_snd_004064B8[4];
s32 D_snd_004064BC;
s32 D_snd_004064C0;
s32 D_snd_004064C4; // UNUSED
UnkStruct_snd_004064C8 D_snd_004064C8[40];
UnkStruct_uvemitter_rom_004008CC D_snd_00406B08;
s32 D_snd_00406B44;
u8 D_snd_00406B48[0x10];
s32 D_snd_00406B58;
void *D_snd_00406B5C;
UnkStruct_004005C8 D_snd_00406B60;
s32 sStopUiSfxUpDownFlag;
s32 sStopUiSfxLeftRightFlag;
s32 sStopUiSfxConfirmFlag;
s32 sStopUiSfxCancelFlag;

// .data
#include "snd_info.h"

u8 D_snd_00406168 = 1;
f32 sVolScale[9] = { 0.0f, 0.125f, 0.25f, 0.375f, 0.5f, 0.625f, 0.75f, 0.875f, 1.0f };
u16 sCurrentMusicId = 0xFF;
u8 sMusicPlaying = FALSE;
UnkStruct_snd_00406198 *D_snd_00406198 = D_snd_00404610;

UnkStruct_0040619C D_snd_0040619C[8] = {
    { { 0, 0x640, 0x2666, -0x2666, 0x960, 0, 0, 0 } },
    { { 0x40, 0xE10, 0x2666, -0x2666, 0xE10, 0, 0, 0x5000 } },
    { { 0x290, 0x800, 0x4000, -0x4000, 0x960, 0, 0, 0 } },
    { { 0x2D0, 0x670, 0x2000, -0x2000, 0x1130, 0, 0, 0 } },
    { { 0xA20, 0x11A0, 0x4000, -0x4000, 0x12D4, 0, 0, 0x6000 } },
    { { 0xA60, 0xEE0, 0x2000, -0x2000, 0x1680, 0, 0, 0 } },
    { { 0xEE0, 0x10C0, 0x2000, -0x2000, 0x1770, 0, 0, 0 } },
    { { 0, 0x12B0, 0, 0, 0x1900, 0, 0, 0 } },
};
UnkStruct_0040619C D_snd_0040629C[8] = {
    { { 0, 0x640, 0x2666, -0x2666, 0x2EE0, 0, 0, 0 } },
    { { 0x40, 0xE10, 0x2666, -0x2666, 0x4650, 0, 0, 0x5000 } },
    { { 0x290, 0x800, 0x4000, -0x4000, 0x53FC, 0, 0, 0 } },
    { { 0x2D0, 0x670, 0x2000, -0x2000, 0x55F0, 0, 0, 0 } },
    { { 0xA20, 0x11A0, 0x4000, -0x4000, 0x5DCA, 0, 0, 0x6000 } },
    { { 0xA60, 0xEE0, 0x2000, -0x2000, 0x6DB0, 0, 0, 0 } },
    { { 0xEE0, 0x10C0, 0x2000, -0x2000, 0x7530, 0, 0, 0 } },
    { { 0, 0x12B0, 0, 0, 0x7D00, 0, 0, 0 } },
};

// extra rodata
const char sSndDebugString[] = { "UNUSED" };
const char sSndDebugString1[] = { "ACTIVE BUT NO MODEL" };
const char sSndDebugString2[] = { "UNUSED" };

// global exports
//extern UnkScrnExports *gScrnExports;
extern ReplayExports *gReplayExports;

void __entrypoint_func_snd_400000(Snd_Exports *exports);

void __entrypoint_func_snd_400000(Snd_Exports *arg0) {
    s32 soundType;
    s32 sfxCount;
    u8 *temp_v0;
    u8 i;
    s32 j;

    uvUpdateFileAllocPtr(arg0);
    arg0->func_snd_004027E8 = func_snd_004027E8;
    arg0->func_snd_0040284C = func_snd_0040284C;
    arg0->func_snd_004005C8 = func_snd_004005C8;
    arg0->func_snd_00400750 = func_snd_00400750;
    arg0->func_snd_00400854 = func_snd_00400854;
    arg0->sndPlaySound = sndPlaySound;
    arg0->func_snd_00400A64 = func_snd_00400A64;
    arg0->func_snd_00400B0C = func_snd_00400B0C;
    arg0->func_snd_00400B54 = func_snd_00400B54;
    arg0->func_snd_00400E90 = func_snd_00400E90;
    arg0->func_snd_00400EA0 = func_snd_00400EA0;
    arg0->func_snd_004004F8 = func_snd_004004F8;
    arg0->func_snd_004014D4 = func_snd_004014D4;
    arg0->func_snd_00401564 = func_snd_00401564;
    arg0->func_snd_0040211C = func_snd_0040211C;
    arg0->func_snd_00401650 = func_snd_00401650;
    arg0->func_snd_0040216C = func_snd_0040216C;
    arg0->func_snd_00401694 = func_snd_00401694;
    arg0->func_snd_00402B40 = func_snd_00402B40;
    arg0->func_snd_0040221C = func_snd_0040221C;
    arg0->func_snd_00401800 = func_snd_00401800;
    arg0->func_snd_00402DC0 = func_snd_00402DC0;
    arg0->func_snd_004022D0 = func_snd_004022D0;
    arg0->func_snd_00401914 = func_snd_00401914;
    arg0->func_snd_00402E1C = func_snd_00402E1C;
    arg0->func_snd_0040231C = func_snd_0040231C;
    arg0->func_snd_00401A28 = func_snd_00401A28;
    arg0->func_snd_00402368 = func_snd_00402368;
    arg0->func_snd_00401AA8 = func_snd_00401AA8;
    arg0->func_snd_00402388 = func_snd_00402388;
    arg0->func_snd_00401CDC = func_snd_00401CDC;
    arg0->func_snd_004023A8 = func_snd_004023A8;
    arg0->func_snd_00401D14 = func_snd_00401D14;
    arg0->func_snd_004023D4 = func_snd_004023D4;
    arg0->func_snd_004023F4 = func_snd_004023F4;
    arg0->func_snd_00400EB4 = func_snd_00400EB4;
    arg0->func_snd_00400EC0 = func_snd_00400EC0;
    arg0->func_snd_00401038 = func_snd_00401038;
    arg0->func_snd_00401D54 = func_snd_00401D54;
    arg0->sndSetMusic = sndSetMusic;
    arg0->func_snd_00401DA0 = func_snd_00401DA0;
    arg0->func_snd_00402424 = func_snd_00402424;
    arg0->sndSetMusicState = sndSetMusicState;
    arg0->func_snd_00401E08 = func_snd_00401E08;
    arg0->func_snd_00402504 = func_snd_00402504;
    arg0->sndSetMusicVol = sndSetMusicVol;
    arg0->func_snd_00401E70 = func_snd_00401E70;
    arg0->func_snd_0040252C = func_snd_0040252C;
    arg0->sndSetSfxVol = sndSetSfxVol;
    arg0->func_snd_00401EB8 = func_snd_00401EB8;
    arg0->func_snd_004025EC = func_snd_004025EC;
    arg0->sndSetSpeechVol = sndSetSpeechVol;
    arg0->func_snd_00401F48 = func_snd_00401F48;
    arg0->func_snd_004025FC = func_snd_004025FC;
    arg0->func_snd_004014B4 = func_snd_004014B4;
    arg0->func_snd_00401FD8 = func_snd_00401FD8;
    arg0->func_snd_0040260C = func_snd_0040260C;
    arg0->func_snd_004014C4 = func_snd_004014C4;
    arg0->func_snd_00402020 = func_snd_00402020;
    arg0->func_snd_0040264C = func_snd_0040264C;
    arg0->func_snd_00402084 = func_snd_00402084;
    arg0->func_snd_00402660 = func_snd_00402660;
    arg0->func_snd_004020D0 = func_snd_004020D0;

    for (i = 1; i < 40; i++) {
        func_snd_004014E0(i);
    }
    D_snd_00406B48[0] = -1;
    gUvFmtxExports->uvMat4SetIdentity((Mtx4F *) &D_snd_00406B08);
    gUvEmitterExports->func_uvemitter_rom_004023B0(0);
    gUvCmidiExports->uvaLoadBank(0);
    sndSetMusicVol(gGameSettings->optionsMusicVol);
    sndSetSfxVol(gGameSettings->optionsSfxVol);
    sndSetSpeechVol(gGameSettings->optionsSpeechVol);
    gUvEmitterExports->func_uvemitter_rom_004029D8(2U, 1.0f);
    sfxCount = SFX_TOTAL;
    for (j = 0; j < sfxCount; j++) {
        temp_v0 = func_snd_004023F4(j);
        if ((temp_v0[0] == 'V') && (temp_v0[1] == '_')) {
            soundType = SOUND_TYPE_SPEECH;
        } else if ((temp_v0[0] == 'S') && (temp_v0[1] == '_')) {
            soundType = SOUND_TYPE_UI;
        } else {
            soundType = SOUND_TYPE_SFX;
        }
        // S_DRIVE is the NPC horn honk.  This reroutes the sound to the proper
        // audio bus. It seems like these patches were added because there was 
        // no time left to update the soundName strings.
        if (j == S_DRIVE) {
            soundType = SOUND_TYPE_SFX;
        }
        // Patch for routing mislabeled Beetle Battle speech sounds
        if ((j == STEALERHIT) || (j == HEALTH_GOOD1) || (j == HEALTH_GOOD2) 
            || (j == HEALTH_BAD_B1) || (j == HEALTH_BAD_B2) 
            || (j == LASTLADYBUG) || (j == FOGWEAPON) || (j == SLOWDOWN) 
            || (j == INVERT) || (j == BATTLEEXPLODE1) 
            // !@bug: They forgot to add BATTLEEXPLODE2 and BATTLEEXPLODE3
            || (j == BATTLEEXPLODE1) || (j == BATTLEEXPLODE1)) {
            soundType = SOUND_TYPE_SPEECH;
        }
        gUvEmitterExports->func_uvemitter_rom_004029A4(j, soundType);
    }
}

void func_snd_004004F8(void) {
    u8 i;

    for (i = 1; i < 0x28; i++) {
        if (D_snd_004064C8[i].unk0 >= 0.0f) {
            gUvEmitterExports->func_uvemitter_rom_004010CC(i);
            gUvEmitterExports->func_uvemitter_rom_0040075C(i);
        }
        func_snd_004014E0(i);
    }
}

void func_snd_004005C8(void *arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                       UnkStruct_uvemitter_rom_004008CC *arg6) {
    u8 temp_v0;

    temp_v0 = func_snd_00401AA8(arg0, (s32) arg1, arg2, 0x30);
    if (temp_v0 == 0xFF) {
        return;
    }

    gUvEmitterExports->uvEmitterProps(temp_v0, 1, 1.0f, 2, 250.0f, 0);
    if (arg3 < 0.0f) {
        arg3 = 0.0f;
    } else if (arg3 > 1.0f) {
        arg3 = 1.0f;
    }
    func_snd_00401E70(arg0, arg3);
    if (arg4 < 0.0001f) {
        arg4 = 0.0001f;
    } else if (arg4 > 2.0f) {
        arg4 = 2.0f;
    }
    func_snd_00401EB8(arg0, arg4);
    if (arg5 < -1.0f) {
        arg5 = -1.0f;
    } else if (arg5 > 1.0f) {
        arg5 = 1.0f;
    }
    func_snd_00401F48(arg0, arg5);
    func_snd_00401E08(arg0, arg6);
    func_snd_00401D14(arg0);
}

s16 func_snd_00400750(UnkStruct_004005C8 *arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4) {
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv1;
    u8 temp_v0;

    temp_v0 = func_snd_00401AA8(arg0, (s32) arg1, arg2, 0x30);
    if (temp_v0 == 0xFF) {
        return temp_v0;
    }
    if (arg3 < 0.0f) {
        arg3 = 0.0f;
    } else if (arg3 > 1.0f) {
        arg3 = 1.0f;
    }
    func_snd_00401E70(arg0, arg3);
    if (arg4 < 0.0001f) {
        arg4 = 0.0001f;
    } else if (arg4 > 2.0f) {
        arg4 = 2.0f;
    }

    func_snd_00401EB8(arg0, arg4);
    func_snd_00401D14(arg0);
    return arg0->unk4;
}

s32 func_snd_00400854(s16 arg0, s32 arg1, f32 arg2, s32 arg3) {
    u8 temp_s0;

    gSndExports->func_snd_00402504(&D_snd_00406B60); // Why use the global export to call this function?
    temp_s0 = func_snd_00401AA8(&D_snd_00406B60, (s32) arg0, arg1, 0x30);
    if (temp_s0 == 0xFF) {
        return temp_s0;
    }
    gUvEmitterExports->func_uvemitter_rom_00400D48(temp_s0,
                                                   (f32) func_snd_004023A8((s32) arg0) / 22050.0f);
    gUvEmitterExports->func_uvemitter_rom_00400BE8(temp_s0, func_snd_004014C4() * arg2);
    gUvEmitterExports->func_uvemitter_rom_00401070(temp_s0, arg3);

    return temp_s0;
}

void sndPlaySound(s16 soundId, s32 vol) {
    u8 emitterId;

    emitterId = gUvEmitterExports->uvGetEmitter();
    gUvEmitterExports->uvEmitterSetVol(emitterId, vol);
    if (emitterId != 0xFF) {
        gUvEmitterExports->func_uvemitter_rom_004007B4(emitterId, soundId);
        gUvEmitterExports->func_uvemitter_rom_00400D48(emitterId,
                                                       (f32) func_snd_004023A8(soundId) / 22050.0f);
        gUvEmitterExports->uvEmitterProps(emitterId, 5, 0x30, 0);
        gUvEmitterExports->func_uvemitter_rom_00400BE8(emitterId, func_snd_004014B4() * 0.6f);
        gUvEmitterExports->func_uvemitter_rom_00401010(emitterId);
    }
}

s16 func_snd_00400A64(u8 arg0) {
    u8 temp_s0;
    s32 temp_v0;

    temp_v0 = gUvEmitterExports->uvGetEmitter();
    temp_s0 = temp_v0;
    if (temp_v0 == 0xFF) {
        return 0xFF;
    }
    gUvEmitterExports->func_uvemitter_rom_004007B4(temp_s0, arg0);
    gUvEmitterExports->func_uvemitter_rom_00400BE8(temp_s0, 0.0f);
    gUvEmitterExports->func_uvemitter_rom_00401010(temp_s0);
    return temp_s0;
}

s32 func_snd_00400B0C(s16 arg0) {
    if (arg0 != 0xFF) {
        gUvEmitterExports->func_uvemitter_rom_0040075C(arg0);
    }
    return 0xFF;
}

void func_snd_00400B54(s16 arg0, f32 arg1, f32 arg2, f32 arg3, UnkStruct_uvemitter_rom_004008CC *arg4) {
    if (arg0 == 0xFF) {
        return;
    }

    gUvEmitterExports->func_uvemitter_rom_004008CC((u8) arg0, arg4);
    if (arg2 < 0.0f) {
        arg2 = 0.0f;
    } else if (arg2 > 1.0f) {
        arg2 = 1.0f;
    }
    gUvEmitterExports->func_uvemitter_rom_00400BE8((u8) arg0, arg2);
    if (arg1 < 0.0001f) {
        arg1 = 0.0001f;
    } else if (arg1 > 2.0f) {
        arg1 = 2.0f;
    }
    gUvEmitterExports->func_uvemitter_rom_00400D48((u8) arg0, arg1);
    if (arg3 < -1.0f) {
        arg3 = -1.0f;
    } else if (arg3 > 1.0f) {
        arg3 = 1.0f;
    }
    gUvEmitterExports->func_uvemitter_rom_00400CA8((u8) arg0, arg3);
}

s32 func_snd_00400CD8(s32 arg0) {
    s32 i;

    // Needs rodata migrated
    for (i = 0; i < D_snd_00406168; i++) {
        if ((D_snd_004064B8[i] == 0)
            && ((0.7f < gReplayExports->unk2C(i, arg0)) || (gReplayExports->unk2C(i, arg0) < -0.7f))) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_snd_00400DDC(s32 arg0) {
    s32 i;

    for (i = 0; i < D_snd_00406168; i++) {
        if ((D_snd_004064B8[i] == 0) && (gReplayExports->unk28(i, arg0))) {
            return TRUE;
        }
    }

    return FALSE;
}

void func_snd_00400E90(s32 arg0) {
    D_snd_004064B8[arg0] = 0;
}

void func_snd_00400EA0(s32 arg0) {
    D_snd_004064B8[arg0] = 1;
}

void func_snd_00400EB4(s32 arg0) {
    D_snd_00406168 = arg0;
}

void func_snd_00400EC0(void) {
    if ((func_snd_00400CD8(1) != 0) || (func_snd_00400DDC(U_JPAD | D_JPAD) != 0)) {
        if (sStopUiSfxUpDownFlag == 0) {
            if (D_snd_004063B8[S_HORN] == 0) {
                // original "S_HORN" soundName is incorrect
                // this is actually S_UP (UI select xylophone)
                sndPlaySound(S_HORN, 0x7FFF);
            }
            sStopUiSfxUpDownFlag = 1;
        }
    } else {
        sStopUiSfxUpDownFlag = 0;
    }
    if ((func_snd_00400CD8(0) != 0) || (func_snd_00400DDC(L_JPAD | R_JPAD) != 0)) {
        if (sStopUiSfxLeftRightFlag == 0) {
            if (D_snd_004063B8[S_JOY_LR] == 0) {
                sndPlaySound(S_JOY_LR, 0x7FFF);
            }
            sStopUiSfxLeftRightFlag = 1;
        }
    } else {
        sStopUiSfxLeftRightFlag = 0;
    }
    if (func_snd_00400DDC(A_BUTTON | START_BUTTON) != 0) {
        if (sStopUiSfxConfirmFlag == 0) {
            if (D_snd_004063B8[S_CONFIRM] == 0) {
                sndPlaySound(S_CONFIRM, 0x7FFF);
            }
            sStopUiSfxConfirmFlag = 1;
        }
    } else {
        sStopUiSfxConfirmFlag = 0;
    }
    if (func_snd_00400DDC(B_BUTTON) != 0) {
        if (sStopUiSfxCancelFlag == 0) {
            if (D_snd_004063B8[S_UP] == 0) {
                // original "S_UP" soundName is incorrect
                // this is actually the "Cancel" SFX
                sndPlaySound(S_UP, 0x7FFF);
            }
            sStopUiSfxCancelFlag = 1;
        }
    } else {
        sStopUiSfxCancelFlag = 0;
    }
}

void func_snd_00401038(void) {
    UnkStruct_snd_004064C8 *temp_s1;
    u8 i;
    s32 sp38[6];
    s32 sp34;

    sp34 = gScrnExports->unk14(sp38);
    gUvChanExports->func_uvchannel_rom_00400288(0, 3, &D_snd_00406B08, 0);

    for (i = 1; i < 0x28; i++) {
        temp_s1 = &D_snd_004064C8[i];
        if (temp_s1->unk0 < 0.0f) {
            continue;
        }
        if (gUvEmitterExports->func_uvemitter_rom_004026EC(i) == 0) {
            if (temp_s1->unk0 >= 0.0f) {
                func_snd_00401564(i);
            }
        } else {
            if (temp_s1->unk26 != 0) {
                gUvEmitterExports->func_uvemitter_rom_004008CC(i, &D_snd_00406B08);
            }
            if (temp_s1->unk20 < D_snd_00406B48[0]) {
                D_snd_00406B48[0] = i;
            }
        }
    }
    if ((gGameSettings->pauseFlag != 0) || (gGameSettings->unk6E9C > 0)) {
        if (gGameSettings->pauseFlag != 0) {
            if (gGameSettings->optionsMusicVol >= 2) {
                sndSetMusicVol(1);
            }
            gUvEmitterExports->func_uvemitter_rom_004029D8(0U, 0.0f);
            gUvEmitterExports->func_uvemitter_rom_004029D8(1U, 0.0f);
        }
        func_snd_00400EC0();
    } else {
        sndSetMusicVol(gGameSettings->optionsMusicVol);
        sndSetSpeechVol(gGameSettings->optionsSpeechVol);
        if (gGameSettings->introReplayState != 0) {
            sndSetSfxVol(0);
        } else {
            sndSetSfxVol(gGameSettings->optionsSfxVol);
        }
        D_snd_00406B5C = uvGetLoadedModule('slct');
        if (D_snd_00406B5C != NULL) {
            func_snd_00400EC0();
        }
    }

    for (i = 0; i < sp34; i++) {
        if (sp38[i] != 0) {
            gUvEarExports->func_uvear_rom_00400390(i, sp38[i] + 0x1A8);
            gUvEarExports->func_uvear_rom_004004E4(i);
        }
    }

    gUvEmitterExports->func_uvemitter_rom_0040120C(sp34);
    gUvEmitterExports->func_uvemitter_rom_00401DCC();
}

void sndSetMusic(u16 musicId) {
    sCurrentMusicId = musicId;
}

void sndSetMusicState(u8 state) {
    switch (state) {
        case 0:
        case 3:
            func_snd_0040252C(0);
            if (sMusicPlaying) {
                gUvCmidiExports->uvaSeqStop();
            }

            gUvCmidiExports->uvaSetSeq(sCurrentMusicId);
            gUvCmidiExports->uvaSeqPlay();
            sMusicPlaying = TRUE;
            break;
        case 2:
        case 1:
            if (sMusicPlaying) {
                gUvCmidiExports->uvaSeqStop();
                sMusicPlaying = FALSE;
            }
    }
}

void sndSetMusicVol(s32 volLevel) {
    f32 scaledVolume;

    scaledVolume = sVolScale[volLevel];
    gUvCmidiExports->uvaSeqSetVol(scaledVolume);
    gUvAudiomgrExports->func_uvaudiomgr_rom_004011C4(scaledVolume);
}

void sndSetSfxVol(s32 volLevel) {
    gUvEmitterExports->func_uvemitter_rom_004029D8(0U, sVolScale[volLevel]);
}

void sndSetSpeechVol(s32 volLevel) {
    gUvEmitterExports->func_uvemitter_rom_004029D8(1U, sVolScale[volLevel]);
}

f32 func_snd_004014B4(void) {
    return 1.0f;
}

f32 func_snd_004014C4(void) {
    return 1.0f;
}

void func_snd_004014D4(s32 arg0) {
    D_snd_004064BC = arg0;
}

void func_snd_004014E0(s16 arg0) {
    UnkStruct_snd_004064C8 *temp_v0;

    if ((arg0 <= 0) || (arg0 >= 0x28)) {
        *(s32 *) 0 = 0;
    }
    temp_v0 = &D_snd_004064C8[arg0];
    temp_v0->unk20 = 0;
    temp_v0->soundId = 0;
    temp_v0->unk1C = 0x18;
    temp_v0->unk26 = 1;
    temp_v0->unk27 = 1;
    temp_v0->sampleRate = 1.0f;
    temp_v0->unk10 = 1.0f;
    temp_v0->unk4 = 1.0f;
    temp_v0->unk0 = -1.0f;
    temp_v0->unkC = 0.0f;
}

void func_snd_00401564(u8 arg0) {
    u8 i;

    if (gUvEmitterExports->func_uvemitter_rom_004026EC(arg0) != 0) {
        gUvEmitterExports->func_uvemitter_rom_004010CC(arg0);
        gUvEmitterExports->func_uvemitter_rom_0040075C(arg0);
    }
    i = 1;
    if (D_snd_00406B48[0] == 0xFF) {
        return;
    }

    while (i < 0x28) {
        if ((D_snd_004064C8[i].unk20 >= 0) && (D_snd_004064C8[i].unk20 < 99999.0f)) {
            D_snd_00406B48[0] = i;
            return;
        }
        i++;
    }

    D_snd_00406B48[0] = 0xFF;
}

void func_snd_00401650(void) {
    s16 i;

    for (i = 1; i < 0x28; i++) {
        func_snd_00401564(i);
    }
}

u8 func_snd_00401694(UnkStruct_004005C8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 var_s0;

    var_s0 = gUvEmitterExports->uvGetEmitter();
    if (var_s0 == 0) {
        var_s0 = gUvEmitterExports->uvGetEmitter();
        ;
    }

    if (var_s0 == 0xFF) {
        if (D_snd_00406B48[0] == 0xFF) {
            return 0xFF;
        }
        if (D_snd_004064C8[D_snd_00406B48[0]].unk20 >= arg2) {
            arg0->unk4 = var_s0;
            return 0xFF;
        }
        var_s0 = D_snd_00406B48[0];
    }

    func_snd_004014E0(var_s0);
    D_snd_004064C8[var_s0].unk0 = D_snd_004064C0++;
    D_snd_004064C8[var_s0].soundId = arg1;
    D_snd_004064C8[var_s0].unk20 = arg2;
    D_snd_004064C8[var_s0].sampleRate = func_snd_004023A8(arg1) / 22050.0f;
    D_snd_004064C8[var_s0].unk4 = func_snd_00402368(arg1);
    D_snd_004064C8[var_s0].unk1C = arg3;
    arg0->unk4 = var_s0;
    arg0->unk0 = D_snd_004064C8[var_s0].unk0;

    return var_s0;
}

s16 func_snd_00401800(UnkStruct_004005C8 *arg0, s16 arg1, s32 arg2, f32 arg3) {
    f32 temp_fv1;
    f32 var_fv0;
    u8 temp_v0;

    temp_v0 = func_snd_00401AA8(arg0, (s32) arg1, arg2, 0);
    if (temp_v0 == 0xFF) {
        return temp_v0;
    }

    gUvEmitterExports->uvEmitterProps((u8) temp_v0, 1, 0.0f, 2, 2000.0f, 0);

    func_snd_00401E70(arg0, arg3);
    var_fv0 *= 0; // FAKE
    temp_fv1 = func_snd_004023A8(arg1) / 22050.0f;
    var_fv0 = temp_fv1;
    if (var_fv0 < 0.0001f) {
        var_fv0 = 0.0001f;
    } else if (var_fv0 > 2.0f) {
        var_fv0 = 2.0f;
    }
    func_snd_00401EB8(arg0, var_fv0);
    func_snd_00401D14(arg0);
    return arg0->unk4;
}

u8 func_snd_00401914(UnkStruct_004005C8 *arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                     Vec3F* arg6) {
    f32 temp_fv1;
    f32 var_fv0;
    u8 temp_v0;

    temp_v0 = func_snd_00401AA8(arg0, (s32) arg1, arg2, 8);
    if (temp_v0 == 0xFF) {
        return temp_v0;
    }
    gUvEmitterExports->uvEmitterProps(temp_v0, 2, arg5, 1, arg4, 0);
    func_snd_00401DA0(arg0, arg6);
    func_snd_00401E70(arg0, arg3);

    var_fv0 *= 0; // FAKE
    temp_fv1 = func_snd_004023A8(arg1) / 22050.0f;
    var_fv0 = temp_fv1;
    if (temp_fv1 < 0.0001f) {
        var_fv0 = 0.0001f;
    } else if (temp_fv1 > 2.0f) {
        var_fv0 = 2.0f;
    }
    func_snd_00401EB8(arg0, var_fv0);
    func_snd_00401D14(arg0);
    return arg0->unk4;
}

s32 func_snd_00401A28(UnkStruct_004005C8 *arg0) {
    if (arg0->unk4 == 0xFF) {
        return 0;
    }
    if (arg0->unk4 >= 0xFF) {
        func_snd_00402424();
        return 0;
    }
    if (arg0->unk0 == D_snd_004064C8[arg0->unk4].unk0) {
        return 1;
    }

    return 0;
}

u8 func_snd_00401AA8(UnkStruct_004005C8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 == NULL) {
        return 0U;
    }
    if (arg0->unk4 == 0) {
        *(s32 *) 0 = 0; // fault
    }
    if (func_snd_00401A28(arg0) == 0) {
        if (func_snd_00401694(arg0, arg1, arg2, arg3) == 0xFF) {
            return 0xFFU;
        }
    } else if (D_snd_004064C8[arg0->unk4].unk27 == 0) {
        return arg0->unk4;
    } else if (func_snd_004023D4(arg1) != 0) {
        return arg0->unk4;
    }

    if (arg1 >= 0xFF) {
        return 0xFFU;
    }

    gUvEmitterExports->func_uvemitter_rom_004007B4(arg0->unk4, (u8) D_snd_004064C8[arg0->unk4].soundId);
    gUvEmitterExports->uvEmitterProps(arg0->unk4, 5, D_snd_004064C8[arg0->unk4].unk1C, 2,
                                                   1000.0f, 1, 0.0f, 0);
    gUvEmitterExports->func_uvemitter_rom_00400BE8(arg0->unk4, D_snd_004064C8[arg0->unk4].unk10);
    gUvEmitterExports->func_uvemitter_rom_00400CA8(arg0->unk4, D_snd_004064C8[arg0->unk4].unkC);
    gUvEmitterExports->func_uvemitter_rom_00400D48(arg0->unk4, D_snd_004064C8[arg0->unk4].sampleRate);
    gUvEmitterExports->uvEmitterSetVol(arg0->unk4, D_snd_004064C8[arg0->unk4].unk20);

    return arg0->unk4;
}

void func_snd_00401CDC(UnkStruct_004005C8 *arg0) {
    if (func_snd_00401A28(arg0) != 0) {
        func_snd_00401564(arg0->unk4);
        func_snd_00402504(arg0);
    }
}

void func_snd_00401D14(UnkStruct_004005C8 *arg0) {
    if (func_snd_00401A28(arg0) != 0) {
        gUvEmitterExports->func_uvemitter_rom_00401010(arg0->unk4);
    }
}

void func_snd_00401D54(UnkStruct_004005C8 *arg0, u8 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        D_snd_004064C8[arg0->unk4].unk27 = arg1;
    }
}

void func_snd_00401DA0(UnkStruct_004005C8 *arg0, Vec3F* arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        gUvEmitterExports->func_uvemitter_rom_0040087C(arg0->unk4, arg1);
        D_snd_004064C8[arg0->unk4].unk26 = 0;
    }
}

void func_snd_00401E08(UnkStruct_004005C8 *arg0, UnkStruct_uvemitter_rom_004008CC *arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        gUvEmitterExports->func_uvemitter_rom_004008CC(arg0->unk4, arg1);
        D_snd_004064C8[arg0->unk4].unk26 = 0;
    }
}

void func_snd_00401E70(UnkStruct_004005C8 *arg0, f32 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        gUvEmitterExports->func_uvemitter_rom_00400BE8(arg0->unk4, arg1);
    }
}

void func_snd_00401EB8(UnkStruct_004005C8 *arg0, f32 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        if (arg1 < 0.0001f) {
            arg1 = 0.0001f;
        } else if (arg1 > 2.0f) {
            arg1 = 2.0f;
        }
        gUvEmitterExports->func_uvemitter_rom_00400D48(arg0->unk4, arg1);
    }
}

void func_snd_00401F48(UnkStruct_004005C8 *arg0, f32 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        if (arg1 < -1.0f) {
            arg1 = -1.0f;
        } else if (arg1 > 1.0f) {
            arg1 = 1.0f;
        }
        gUvEmitterExports->func_uvemitter_rom_00400CA8(arg0->unk4, arg1);
    }
}

void func_snd_00401FD8(UnkStruct_004005C8 *arg0, u8 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        gUvEmitterExports->func_uvemitter_rom_004007B4(arg0->unk4, arg1);
    }
}

s16 func_snd_00402020(UnkStruct_004005C8 *arg0) {
    if ((arg0 == (UnkStruct_004005C8 *) -1) || (arg0 == NULL)) {
        return -1;
    }
    if (func_snd_00401A28(arg0) != 0) {
        return D_snd_004064C8[arg0->unk4].soundId;
    }
    return 0;
}

f32 func_snd_00402084(UnkStruct_004005C8 *arg0) {
    if (func_snd_00401A28(arg0) != 0) {
        return D_snd_004064C8[arg0->unk4].unk10;
    }
    return 0.0f;
}

f32 func_snd_004020D0(UnkStruct_004005C8 *arg0) {
    if (func_snd_00401A28(arg0) != 0) {
        return D_snd_004064C8[arg0->unk4].sampleRate;
    }
    return 0.0f;
}

f32 func_snd_0040211C(UnkStruct_004005C8 *arg0) {
    if (func_snd_00401A28(arg0) != 0) {
        return D_snd_004064C8[arg0->unk4].unkC;
    }
    return -1.0f;
}

void func_snd_0040216C(UnkStruct_004005C8 *arg0, f32 arg1) {
    UnkStruct_snd_004064C8 *temp_v0;
    f32 var_fv0;

    if (func_snd_00401A28(arg0) != 0) {
        var_fv0 = D_snd_004064C8[arg0->unk4].unk10 * arg1;
        if (var_fv0 < 0.0f) {
            var_fv0 = 0.0f;
        } else if (var_fv0 > 1.0f) {
            var_fv0 = 1.0f;
        }
        D_snd_004064C8[arg0->unk4].unk10 = var_fv0;
        gUvEmitterExports->func_uvemitter_rom_00400BE8(arg0->unk4, var_fv0);
    }
}

void func_snd_0040221C(UnkStruct_004005C8 *arg0, f32 arg1) {
    UnkStruct_snd_004064C8 *temp_v0;
    f32 var_fv0;
    f32 var_fv1;

    if (func_snd_00401A28(arg0) != 0) {
        temp_v0 = &D_snd_004064C8[arg0->unk4];
        var_fv0 = temp_v0->sampleRate * arg1;
        if (var_fv0 < 0.0001f) {
            var_fv0 = 0.0001f;
        } else if (var_fv0 > 2.0f) {
            var_fv0 = 2.0f;
        }
        temp_v0->sampleRate = var_fv0;
        gUvEmitterExports->func_uvemitter_rom_00400D48(arg0->unk4, var_fv0);
    }
}

void func_snd_004022D0(UnkStruct_004005C8 *arg0, f32 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        gUvEmitterExports->uvEmitterSetVol(arg0->unk4, (s32) arg1);
    }
}

void func_snd_0040231C(UnkStruct_004005C8 *arg0, f32 arg1) {
    if (func_snd_00401A28(arg0) != 0) {
        D_snd_004064C8[arg0->unk4].unk4 = arg1;
    }
}

f32 func_snd_00402368(s32 arg0) {
    return D_snd_00406198[arg0].unkC;
}

s32 func_snd_00402388(s32 arg0) {
    return D_snd_00406198[arg0].unk4;
}

s32 func_snd_004023A8(s32 arg0) {
    return D_snd_00406198[arg0].sampleRate;
}

s32 func_snd_004023D4(s32 arg0) {
    return (s32) D_snd_00406198[arg0].unk18;
}

u8 *func_snd_004023F4(s32 soundId) {
    if (soundId >= 0) {
        return D_snd_00406198[soundId].soundName;
    }
    return NULL;
}

void func_snd_00402424(void) {
    u8 i;
    u8 temp_v0_2;

    for (i = 1; i < 0x28; i++) {
        if (D_snd_004064C8[i].unk0 >= 0.0f) {
            func_snd_004023F4((s32) D_snd_004064C8[i].soundId);
        }
        if (gUvEmitterExports->func_uvemitter_rom_004026EC(i) != 0) {
            temp_v0_2 = gUvEmitterExports->func_uvemitter_rom_00400834(i);
            if (temp_v0_2 != 0xFF) {
                func_snd_004023F4(temp_v0_2);
            }
        }
    }
}

void func_snd_00402504(UnkStruct_004005C8 *arg0) {
    if (arg0 == NULL) {
        *(s32 *) 0 = 0;
        return;
    }
    arg0->unk4 = 0xFF;
    arg0->unk0 = -1.0f;
}

void func_snd_0040252C(s32 arg0) {
    s32 i;
    s32 j;
    UnkStruct_0040619C *var_v0;

    if (arg0 == 1) {
        D_snd_00406B58 = arg0;
        var_v0 = D_snd_0040629C;
    } else {
        D_snd_00406B58 = arg0;
        var_v0 = D_snd_0040619C;
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            gUvAudiomgrExports->func_uvaudiomgr_rom_00401228(i, j, var_v0[i].data[j]);
        }
    }
}

u8 func_snd_004025EC(s32 arg0) {
    return D_snd_004063B8[arg0];
}

void func_snd_004025FC(s32 arg0) {
    D_snd_004063B8[arg0] = 0;
}

void func_snd_0040260C(void) {
    s32 i;

    for (i = 0; i < 0xFF; i++) {
        D_snd_004063B8[i] = 0;
    }
}

void func_snd_0040264C(s32 arg0) {
    D_snd_004063B8[arg0] = 1;
}

void func_snd_00402660(s32 arg0) {
    s32 count;
    s32 i;
    s32 j;
    s32 spDC[32];
    s32 sp5C[32];

    func_snd_0040264C(arg0);
    count = gUvEmitterExports->func_uvemitter_rom_00402754(spDC, sp5C);

    for (i = 0; i < count; i++) {
        if (arg0 == spDC[i]) {
            for (j = 1; j < 40; j++) {
                if (D_snd_004064C8[j].soundId == spDC[i]) {
                    gUvEmitterExports->func_uvemitter_rom_00400BE8(j, 0.0f);
                    gUvEmitterExports->func_uvemitter_rom_004010CC(j);
                    func_snd_00401564(j);
                } else {
                    if (gUvEmitterExports->func_uvemitter_rom_00400834(j) == spDC[i]) {
                        gUvEmitterExports->func_uvemitter_rom_00400BE8(j, 0.0f);
                        gUvEmitterExports->func_uvemitter_rom_004010CC(j);
                        gUvEmitterExports->func_uvemitter_rom_0040075C(j);
                    }
                }
            }
        }
    }
}

s32 func_snd_004027E8(UnkStruct_004005C8 *arg0) {
    if ((arg0 == (UnkStruct_004005C8 *) -1) || (arg0 == NULL)) {
        return 0x18;
    }
    if (func_snd_00401A28(arg0) != 0) {
        return D_snd_004064C8[arg0->unk4].unk1C;
    }
    return 0x18;
}

void func_snd_0040284C(s32 arg0) {
    s32 i;
    s32 j;
    s32 sp164;
    s32 spE4[32];
    s32 sp64[32];
    f32 temp_fv0;
    sp164 = gUvEmitterExports->func_uvemitter_rom_00402754(spE4, sp64);
    for (i = 0; i < sp164; i++) {
        if (arg0 == spE4[i]) {
            for (j = 1; j < 40; j++) {
                if (D_snd_004064C8[j].soundId == spE4[i]) {
                    while (gUvEmitterExports->func_uvemitter_rom_00400C5C(j) > 0.0f) {
                        temp_fv0 = gUvEmitterExports->func_uvemitter_rom_00400C5C(j) - 0.1f;
                        if (temp_fv0 < 0.0f) {
                            temp_fv0 = 0.0f;
                        } else if (temp_fv0 > 1.0f) {
                            temp_fv0 = 1.0f;
                        }
                        gUvEmitterExports->func_uvemitter_rom_00400BE8(j, temp_fv0);
                    }

                    if (gUvEmitterExports->func_uvemitter_rom_00400C5C(j) == 0.0f) {
                        gUvEmitterExports->func_uvemitter_rom_004010CC(j);
                        func_snd_00401564(j);
                    }
                } else {
                    if (gUvEmitterExports->func_uvemitter_rom_00400834(j) == spE4[i]) {
                        while (gUvEmitterExports->func_uvemitter_rom_00400C5C(j) > 0.0f) {
                            temp_fv0 = gUvEmitterExports->func_uvemitter_rom_00400C5C(j) - 0.1f;
                            if (temp_fv0 < 0.0f) {
                                temp_fv0 = 0.0f;
                            } else if (temp_fv0 > 1.0f) {
                                temp_fv0 = 1.0f;
                            }
                            gUvEmitterExports->func_uvemitter_rom_00400BE8(j, temp_fv0);
                        }
                        if (gUvEmitterExports->func_uvemitter_rom_00400C5C(j) == 0.0f) {
                            gUvEmitterExports->func_uvemitter_rom_004010CC(j);
                            gUvEmitterExports->func_uvemitter_rom_0040075C(j);
                        }
                    }
                }
            }
        }
    }
}

void func_snd_00402B40(s32 arg0, f32 arg1) {

    s32 temp_v0;
    f32 var_fa0;
    s32 i;
    s32 spFC[32];
    s32 sp7C[32];
    s32 j;

    temp_v0 = gUvEmitterExports->func_uvemitter_rom_00402754(&spFC, &sp7C);
    for (i = 0; i < temp_v0; i++) {
        if (arg0 == spFC[i]) {
            for (j = 1; j < 40; j++) {
                if (D_snd_004064C8[j].soundId == spFC[i]) {
                    while (gUvEmitterExports->func_uvemitter_rom_00400C5C(j) < arg1) {
                        var_fa0 = gUvEmitterExports->func_uvemitter_rom_00400C5C(j) + 0.001f;
                        if (var_fa0 < 0.0f) {
                            var_fa0 = 0.0f;
                        } else if (var_fa0 > 1.0f) {
                            var_fa0 = 1.0f;
                        }
                        gUvEmitterExports->func_uvemitter_rom_00400BE8(j, var_fa0);
                    }
                } else {
                    if (gUvEmitterExports->func_uvemitter_rom_00400834(j) == spFC[i]) {
                        while (gUvEmitterExports->func_uvemitter_rom_00400C5C(j) < arg1) {
                            var_fa0 = gUvEmitterExports->func_uvemitter_rom_00400C5C(j) + 0.001f;
                            if (var_fa0 < 0.0f) {
                                var_fa0 = 0.0f;
                            } else if (var_fa0 > 1.0f) {
                                var_fa0 = 1.0f;
                            }
                            gUvEmitterExports->func_uvemitter_rom_00400BE8(j, var_fa0);
                        }
                    }
                }
            }
        }
    }
}

void func_snd_00402DC0(u8 arg0) {
    if (arg0) {
        gUvAudiomgrExports->func_uvaudiomgr_rom_004011E0(1);
    } else {
        gUvAudiomgrExports->func_uvaudiomgr_rom_004011E0(2);
    }
}

void func_snd_00402E1C(void) {
}

s32 D_0040639C[] = { 0x00FC0000, __entrypoint_func_snd_400000, 0, 0, 0 };
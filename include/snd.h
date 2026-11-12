#ifndef SND_H
#define SND_H

typedef struct UnkStruct_004005C8_s {
    f32 unk0;
    u8 unk4;
} UnkStruct_004005C8;

typedef struct Snd_Exports_s {
    /* 0x00 */ void (*func_snd_004004F8)(void);
    /* 0x04 */ void (*func_snd_004005C8)(void *, s16, s32, f32, f32, f32,
                                         UnkStruct_uvemitter_rom_004008CC *);
    /* 0x08 */ s16 (*func_snd_00400750)(UnkStruct_004005C8 *, s16, s32, f32, f32);
    /* 0x0C */ s32 (*func_snd_00400854)(s16, s32, f32, s32);
    /* 0x10 */ void (*sndPlaySound)(s16, s32);
    /* 0x14 */ s16 (*func_snd_00400A64)(u8);
    /* 0x18 */ s32 (*func_snd_00400B0C)(s16);
    /* 0x1C */ void (*func_snd_00400B54)(s16, f32, f32, f32, UnkStruct_uvemitter_rom_004008CC *);
    /* 0x20 */ void (*func_snd_00400E90)(s32);
    /* 0x24 */ void (*func_snd_00400EA0)(s32);
    /* 0x28 */ void (*func_snd_00400EB4)(s32);
    /* 0x2C */ void (*func_snd_00400EC0)(void);
    /* 0x30 */ void (*func_snd_00401038)(void);
    /* 0x34 */ void (*sndSetMusic)(u16);
    /* 0x38 */ void (*sndSetMusicState)(u8);
    /* 0x3C */ void (*sndSetMusicVol)(s32);
    /* 0x40 */ void (*sndSetSfxVol)(s32);
    /* 0x44 */ void (*sndSetSpeechVol)(s32);
    /* 0x48 */ f32 (*func_snd_004014B4)(void);
    /* 0x4C */ f32 (*func_snd_004014C4)(void);
    /* 0x50 */ void (*func_snd_004014D4)(s32);
    /* 0x54 */ void (*func_snd_00401564)(u8);
    /* 0x58 */ void (*func_snd_00401650)(void);
    /* 0x5C */ u8 (*func_snd_00401694)(UnkStruct_004005C8 *, s32, s32, s32);
    /* 0x60 */ s16 (*func_snd_00401800)(UnkStruct_004005C8 *, s16, s32, f32);
    /* 0x64 */ u8 (*func_snd_00401914)(UnkStruct_004005C8 *, s16, s32, f32, f32, f32, Vec3F*);
    /* 0x68 */ s32 (*func_snd_00401A28)(UnkStruct_004005C8 *);
    /* 0x6C */ u8 (*func_snd_00401AA8)(UnkStruct_004005C8 *, s32, s32, s32);
    /* 0x70 */ void (*func_snd_00401CDC)(UnkStruct_004005C8 *);
    /* 0x74 */ void (*func_snd_00401D14)(UnkStruct_004005C8 *);
    /* 0x78 */ void (*func_snd_00401D54)(UnkStruct_004005C8 *, u8);
    /* 0x7C */ void (*func_snd_00401DA0)(UnkStruct_004005C8 *, Vec3F*);
    /* 0x80 */ void (*func_snd_00401E08)(UnkStruct_004005C8 *, UnkStruct_uvemitter_rom_004008CC *);
    /* 0x84 */ void (*func_snd_00401E70)(UnkStruct_004005C8 *, f32);
    /* 0x88 */ void (*func_snd_00401EB8)(UnkStruct_004005C8 *, f32);
    /* 0x8C */ void (*func_snd_00401F48)(UnkStruct_004005C8 *, f32);
    /* 0x90 */ void (*func_snd_00401FD8)(UnkStruct_004005C8 *, u8);
    /* 0x94 */ s16 (*func_snd_00402020)(UnkStruct_004005C8 *);
    /* 0x98 */ f32 (*func_snd_00402084)(UnkStruct_004005C8 *);
    /* 0x9C */ f32 (*func_snd_004020D0)(UnkStruct_004005C8 *);
    /* 0xA0 */ f32 (*func_snd_0040211C)(UnkStruct_004005C8 *);
    /* 0xA4 */ void (*func_snd_0040216C)(UnkStruct_004005C8 *, f32);
    /* 0xA8 */ void (*func_snd_0040221C)(UnkStruct_004005C8 *, f32);
    /* 0xAC */ void (*func_snd_004022D0)(UnkStruct_004005C8 *, f32);
    /* 0xB0 */ void (*func_snd_0040231C)(UnkStruct_004005C8 *, f32);
    /* 0xB4 */ f32 (*func_snd_00402368)(s32);
    /* 0xB8 */ s32 (*func_snd_00402388)(s32);
    /* 0xBC */ s32 (*func_snd_004023A8)(s32);
    /* 0xC0 */ s32 (*func_snd_004023D4)(s32);
    /* 0xC4 */ u8 *(*func_snd_004023F4)(s32);
    /* 0xC8 */ void (*func_snd_00402424)(void);
    /* 0xCC */ void (*func_snd_00402504)(UnkStruct_004005C8 *);
    /* 0xD0 */ void (*func_snd_0040252C)(s32);
    /* 0xD4 */ u8 (*func_snd_004025EC)(s32);
    /* 0xD8 */ void (*func_snd_004025FC)(s32);
    /* 0xDC */ void (*func_snd_0040260C)(void);
    /* 0xE0 */ void (*func_snd_0040264C)(s32);
    /* 0xE4 */ void (*func_snd_00402660)(s32);
    /* 0xE8 */ s32 (*func_snd_004027E8)(UnkStruct_004005C8 *);
    /* 0xEC */ void (*func_snd_0040284C)(s32);
    /* 0xF0 */ void (*func_snd_00402B40)(s32, f32);
    /* 0xF4 */ void (*func_snd_00402DC0)(u8);
    /* 0xF8 */ void (*func_snd_00402E1C)(void);
} Snd_Exports; /* size = 0xFC */

enum SfxId {
        /* 0x00 */ BIGWTRFALL8,
        /* 0x01 */ WATER5,
        /* 0x02 */ SKID11,                 // tire skid (surprisingly bad loop)
        /* 0x03 */ CHEROKEECRUZ1L1,
        /* 0x04 */ CAMAROLOAD_PS22MB_L1,
        /* 0x05 */ CAMARO_CRUZ_L1,
        /* 0x06 */ BUMP15,
        /* 0x07 */ GRAVELSKID,
        /* 0x08 */ WETROADNOISE2,
        /* 0x09 */ BUMP12,
        /* 0x0A */ SPLASH,
        // It appears at some point during development, the soundNames were
        // locked down and no further edits were made.  As a result,
        // the next four strings don't match up with the actual audio
        /* 0x0B */ S_DRIVE,                // this is actually the NPC horn honk
        /* 0x0C */ S_HORN,                 // S_UP? (UI select)
        /* 0x0D */ S_KLUNK,                // gear shift sfx (reused for CAMERA)
        /* 0x0E */ S_UP,                   // (UI cancel) (no matching soundName)
        //
        /* 0x0F */ PHONEGAG,               // "We're sorry, your call..."
        /* 0x10 */ ICECRYSTALBREAK,
        /* 0x11 */ WOODSLAT,               // Sunset Sands wooden bridge?
        /* 0x12 */ AH1,                    // helicopter (fast)
        /* 0x13 */ CHINOOK,                // helicopter (slow)
        /* 0x14 */ UFO1,                   // UFO drone (far -growling)
        /* 0x15 */ UFO2,                   // UFO drone (close - harsh synth loop)
        /* 0x16 */ CROWDSKIJUMP,           // cheering crowd
        /* 0x17 */ MOBSKIJUMP,             // booing crowd after failed jump
        /* 0x18 */ GONDOLAS,               // squeaky cable car
        /* 0x19 */ FRZH2OFALL,             // frozen waterfall impact
        /* 0x1A */ STALACTITES,            // repurposed for Wicked Woods bridge breakable
        /* 0x1B */ RUSHINGH2O,             // rushing water
        /* 0x1C */ ID_UNKNOWN,             // (original ID string was "NULL")
        /* 0x1D */ ICECRACK1,              // Mount Mayhem frozen waterfall shortcut
        /* 0x1E */ STAINEDGLASS,           // Coventry / Wicked church glass impact
        /* 0x1F */ DIRTROAD,
        /* 0x20 */ GRAVELROAD,
        /* 0x21 */ METALSCRAPE,
        /* 0x22 */ PAVEDROAD,
        /* 0x23 */ SNOWROAD,
        /* 0x24 */ CRANEENGINE,            // Coventry Cove crane
        /* 0x25 */ CRANEWINCH,
        /* 0x26 */ TREE,                   // not sure where this is used
        /* 0x27 */ MINEENTER,              // Coventry mineshaft
        /* 0x28 */ TOLLBOOTH,              // Coventry bridge bar gate impact
        /* 0x29 */ PHONEBOOTH,
        /* 0x2A */ SAWHORSE,               // very similar to TOLLBOOTH
        /* 0x2B */ CARLDGSUSP,             // suspension squeak
        /* 0x2C */ BARRELEXPLODE,
        /* 0x2D */ SIGNHIT,                // road sign impact
        /* 0x2E */ ELEVATORDN,             // Sunset Sands elevator (with slam at end)
        /* 0x2F */ ELEVATORUP,             // shorter stone elevator scrape
        /* 0x30 */ H2OFALLECHO,            // Coventry Cove mineshaft waterfall?
        /* 0x31 */ FIRE,                   // generic fire sfx
        /* 0x32 */ WOODCREAK,
        /* 0x33 */ PILLARSTOPPLE,          // Sunset Sands pillars collapsing
        /* 0x34 */ POTTERYSMASH,
        /* 0x35 */ GARAGEDOOR,             // Mount Mayhem glass door impact
        /* 0x36 */ SNOWMAN5,               // snowman impact
        /* 0x37 */ SNOWSLIDE,
        /* 0x38 */ ICECRYSTALSMASH,        // final in-game version of ICECRYSTALBREAK
        /* 0x39 */ WICKERBASKET,           // Sunset Sands prop?
        /* 0x3A */ ELEVATORBELL,           // Sunset Sands elevator bell ding
        /* 0x3B */ SCAFFOLDCREAK,          // Sunset / Wicked wooden bridge
        /* 0x3C */ SCAFFOLDGROAN,
        /* 0x3D */ WIDESIGNHIT,            // another road sign impact
        /* 0x3E */ CAREXPLODE,
        /* 0x3F */ CTRAINTRACKS,           // Metro Madness city train
        /* 0x40 */ MOVIESCREEN,            // movie screen impact
        /* 0x41 */ GASPUMPEXPLODE,         // Metro Madness gas pump
        /* 0x42 */ BOARDEDTEMPLE,
        /* 0x43 */ WATERFOUNTAIN,
        /* 0x44 */ CARPUDDLESPLASH2,
        /* 0x45 */ CHAINLINKFENCE,
        /* 0x46 */ CONCRETESCRAPE,
        /* 0x47 */ CURBBUMP,
        /* 0x48 */ SLOTCOINSPULL,          // Metro Madness casino slot machine sfx
        /* 0x49 */ SLOTHANDLEPULL,
        /* 0x4A */ SLOTWINNER1,
        /* 0x4B */ SLOTWINNER2,
        /* 0x4C */ STANDSSKIJUMP,          // ski jump crowd screaming
        /* 0x4D */ CRATEEXPLODE,
        /* 0x4E */ TREXROAR,
        /* 0x4F */ LAVABUBBLES,
        /* 0x50 */ LOWRUMBLE,
        /* 0x51 */ JTRAINTRACKS,           // Inferno Isle train
        /* 0x52 */ CAMERA,                 // UI camera view change (same as S_KLUNK)
        /* 0x53 */ SNOW,
        /* 0x54 */ ICESKID,
        /* 0x55 */ MONKEYS,
        /* 0x56 */ ICETIRESPIN,
        /* 0x57 */ CONSTRUCTBARREL,
        /* 0x58 */ COBBLESTONEROAD,
        /* 0x59 */ MOVIEPROJECTOR,
        /* 0x5A */ TREXSTEP,               // t-rex footsteps
        /* 0x5B */ CANNONBALLSHOT,         // pirate ship shortcut
        /* 0x5C */ BULLFROG,
        /* 0x5D */ BUSH,
        /* 0x5E */ CRICKETS,
        /* 0x5F */ JUNGLEAMBIENT1,
        /* 0x60 */ ENGINE1CRUZ,            // player car engine sfx
        /* 0x61 */ ENGINE1LOAD,
        /* 0x62 */ ENGINE2CRUZ,
        /* 0x63 */ ENGINE2LOAD,
        /* 0x64 */ XINGBELL,               // Coventry Cove bridge bell
        /* 0x65 */ ROCKSLIDE,
        /* 0x66 */ CHURCH,                 // possibly unused?
        /* 0x67 */ SURF,                   // Inferno Isle beach waves
        /* 0x68 */ ENGINE3CRUZ,
        /* 0x69 */ ENGINE3LOAD,
        /* 0x6A */ INVINCIBILITY,          // Chrome Beetle power up
        /* 0x6B */ PWRUPNITRO,             // Nitro Box impact (Ya-hoo!)
        /* 0x6C */ DIRTSKID,
        /* 0x6D */ V_GO,                   // "Go!"
        /* 0x6E */ V_ONE,                  // "One!"
        /* 0x6F */ V_THREE,                // "Three!"
        /* 0x70 */ V_TWO,                  // "Two!"
        /* 0x71 */ V_FINISH,               // "Finish!"
        /* 0x72 */ V_LAPTWO,               // "Lap two!"
        /* 0x73 */ V_COVE,                 // "Welcome to...Coventry Cove"
        /* 0x74 */ V_WOODS,                // "Welcome to...Wicked Woods"
        /* 0x75 */ V_MAYHEM,               // "Welcome to...Mount Mayhem"
        /* 0x76 */ V_SANDS,                // "Welcome to...Sunset Sands"
        /* 0x77 */ V_INFERNO,              // "Welcome to...Inferno Isle"
        /* 0x78 */ V_METRO,                // "Welcome to...Metro Madness"
        /* 0x79 */ V_FINALLAP,             // "It's the final lap!"
        /* 0x7A */ V_TITLE,                // "Adventure Racing!"
        /* 0x7B */ V_HOWDY,                // "Welcome!"
        /* 0x7C */ HORNLOOP,               // annoying horn loop
        /* 0x7D */ POINTS_1,               // 2 point box xylophone jingle
        /* 0x7E */ POINTS_5,               // 5 point box jingle
        /* 0x7F */ POINTS_10,              // 10 point box jingle
        /* 0x80 */ MINEPLANT,              // Beetle Battle mine drop
        /* 0x81 */ MISSILESHOT,            // Beetle Battle missile
        /* 0x82 */ MISSILEHIT,             // unused?
        /* 0x83 */ MISSILEHIT1,
        /* 0x84 */ LADYBUG,                // Beetle Battle ladybug pickup
        /* 0x85 */ FORCEFIELD,             // Inferno Isle electric fence
        /* 0x86 */ HEALTH_GOOD1,           // "Now ya kickin'!"
        /* 0x87 */ HEALTH_BAD,             // "Oh no!" (Inferno Isle hut impact)
        /* 0x88 */ DRIVEWATER,
        /* 0x89 */ LAVAFALL,
        /* 0x8A */ V_SPLIT_30_1,           // "You're falling behind!"
        /* 0x8B */ V_SPLIT_30_2,           // "Pick up the pace!"
        /* 0x8C */ V_SPLIT_50_1,           // "Hurry up!"
        /* 0x8D */ V_SPLIT_50_2,           // "Pedal to the metal!"
        /* 0x8E */ V_SPLIT_60,             // "Disqualified!"
        /* 0x8F */ WATERWHEEL,             // Coventry Cove prop
        /* 0x90 */ JACK,                   // Wicked Woods jack-o-lantern laugh
        /* 0x91 */ PURPWIND,               // Wicked Woods wind howling and chimes
        /* 0x92 */ OWL,
        /* 0x93 */ SPOOKY,                 // haunted house ghostsooooh
        /* 0x94 */ SCREAM,                 // Wicked Woods dungeon shortcut
        /* 0x95 */ CHAINS,
        /* 0x96 */ BATS,
        /* 0x97 */ LASTLADYBUG,            // "Head for the exit!"
        /* 0x98 */ WOLVES,                 // spooky wolves howling
        /* 0x99 */ COPSIREN,
        /* 0x9A */ TORCHBREAK,             // fire torch snap
        /* 0x9B */ CHROMECAR,              // Chrome Beetle drone
        /* 0x9C */ PLYRHORN,
        /* 0x9D */ CARLDGLITE,             // car jump landing
        /* 0x9E */ WWCLKCHIME,             // Wicked Woods clock tower chime
        /* 0x9F */ INVERT,                 // "Trip out"
        /* 0xA0 */ FOGWEAPON,              // "Get funky"
        /* 0xA1 */ V_WINNER,               // "Winner, winner, winner!"
        /* 0xA2 */ V_BATTLE1,              // "Let's get it on"
        /* 0xA3 */ V_BATTLE2,              // "Get down!"
        /* 0xA4 */ V_BATTLE3,              // "Here we go!"
        /* 0xA5 */ V_BATTLE4,              // "Let's get busy!"
        /* 0xA6 */ V_BONUS_50,             // "You got it!"
        /* 0xA7 */ V_BONUS_100,            // "You got them all!"
        /* 0xA8 */ V_GAME_OVER,            // "Game over!"
        /* 0xA9 */ V_READY,                // "Get ready!"
        /* 0xAA */ STEALERHIT,             // Beetle Battle stealer hit laugh
        /* 0xAB */ S_CONFIRM,              // UI confirm
        /* 0xAC */ HEALTH_GOOD2,           // "Baby!"
        /* 0xAD */ HEALTH_BAD_B1,          // "Nasty!"
        /* 0xAE */ HEALTH_BAD_B2,          // "That's cold, baby!"
        /* 0xAF */ BATTLEEXPLODE1,         // "Dyno-mite!"
        /* 0xB0 */ BATTLEEXPLODE2,         // "That's gotta hurt!" (Blu V.O.)
        /* 0xB1 */ BATTLEEXPLODE3,         // "You bad!"
        /* 0xB2 */ V_WINNER_A,             // "Awwww, yeaaaah!"
        /* 0xB3 */ V_WINNER_B,             // "Hail to the king, baby!"
        /* 0xB4 */ V_WINNER_C,             // "You're bumpin' with the flava now!"
        /* 0xB5 */ V_GROOVY,               // "Grrrrrooovy!"
        /* 0xB6 */ V_NICEWHL,              // "Nice wheels!"
        /* 0xB7 */ V_BEETLEBAT,            // "Beetle Battle"
        /* 0xB8 */ V_DUEL,                 // "Duel"
        /* 0xB9 */ V_ONE_PLAYER,           // "One Player"
        /* 0xBA */ V_OPTIONS,              // "Options"
        /* 0xBB */ V_RECORDS,              // "Records"
        /* 0xBC */ V_OK,                   // "Ok!"
        /* 0xBD */ DRAGON,                 // Dragon growling (unused)
        /* 0xBE */ SLAMDOOR,               // Haunted door slamming loop (infamous glitch)
        /* 0xBF */ V_NOVICE,               // "Novice circuit"
        /* 0xC0 */ V_ADVANCED,             // "Advanced circuit"
        /* 0xC1 */ V_PRO,                  // "Pro circuit"
        /* 0xC2 */ V_BONUS,                // "Bonus circuit"
        /* 0xC3 */ DRAGONFIRE,             // Dragon roaring and flames
        /* 0xC4 */ UFOMOVIE,               // Metro Madness movie theater sfx
        /* 0xC5 */ V_RECORDSET,            // "Record!"
        /* 0xC6 */ V_PLACE1,               // "First place!"
        /* 0xC7 */ V_PLACE2,               // "Second place!"
        /* 0xC8 */ V_PLACE3,               // "Third place!"
        /* 0xC9 */ V_PLACE4,               // "Fourth place!"
        /* 0xCA */ V_PLACE5,               // "Fifth"
        /* 0xCB */ V_PLACE6,               // "Sixth"
        /* 0xCC */ V_PLACE7,               // "Seventh"
        /* 0xCD */ V_PLACE8,               // "Eigth"
        /* 0xCE */ V_YOU_PLACED,           // "You placed..."
        /* 0xCF */ V_PLACE1A,              // "Congratulations!"
        /* 0xD0 */ V_PLACE1B,              // "Way to go!"
        /* 0xD1 */ V_PLACE1C,              // "You got first!"
        /* 0xD2 */ V_PLACE234A,            // "Great race!"
        /* 0xD3 */ V_PLACE5678A,           // "Nice try"
        /* 0xD4 */ V_PLACE8B,              // "Last place?!"
        /* 0xD5 */ V_PLACE8C,              // "You'll never win that way!"
        /* 0xD6 */ V_PLACE8D,              // "Dead last!"
        /* 0xD7 */ V_CONTINUE,             // "You're still in the game!"
        /* 0xD8 */ V_CHAMPSTOP1,           // "Better luck next time"
        /* 0xD9 */ V_CHAMPSTOP2,           // "Practice makes perfect!"
        /* 0xDA */ V_CHAMPSTOP3,           // "You can do better"
        /* 0xDB */ S_JOY_LR,               // UI select (left/right)
        /* 0xDC */ V_AWARD_A,              // "Well done, you cleared advanced..."
        /* 0xDD */ V_AWARD_N,              // "Congratulations, you won novice..."
        /* 0xDE */ V_AWARD_P,              // "Buckle up and hit the bonus circuit, baby!"
        /* 0xDF */ SLOWDOWN,               // "Funk-a-delic!"
        /* 0xE0 */ V_SINGLRACE,            // "Single race"
        /* 0xE1 */ V_CHAMPNSHIP,           // "Championship"
        /* 0xE2 */ V_FULL_GRID,            // "Full Grid"
        /* 0xE3 */ V_TIME_ATAK,            // "Time Attack"
        /* 0xE4 */ V_GOODCHOICE,           // "Good choice!"
        /* 0xE5 */ V_MULTIPLYR,            // "Two player"
        /* 0xE6 */ HORN2LOOP,
        /* 0xE7 */ HORN3LOOP,
        /* 0xE8 */ HORN4LOOP,
        /* 0xE9 */ ALIENHORN,              // "We come in peace"
        /* 0xEA */ V_HOTLAVA,              // "Hot lava!! Huuh!"
        /* 0xEB */ V_NEW_CONT,             // "You got a continue!"
        /* 0xEC */ V_NEW_ARENA,            // "A new arena!"
        /* 0xED */ V_ALLRIGHT,             // "Allright!" (10 point box hit)
        /* 0xEE */ V_THREEPLYR,            // "Three player"
        /* 0xEF */ V_FOURPLYR,             // "Four player"
        /* 0xF0 */ V_EXPLOSION,            // "Ooh! That's gotta hurt!" (David V.O.)
        /* 0xF1 */ CROWDCLAP,              // Championship win
        /* 0xF2 */ CROWDCHEER,             // Bonus championship win
        /* 0xF3 */ CROWDMOAN,              // unused?
        /* 0xF4 */ V_CHEATMENU,            // "Cheat menu activated!"
        /* 0xF5 */ V_GOTCHEAT,             // "New cheat activated!"
        /* 0xF6 */ V_TRYAGAIN,             // "Nice try, but you need to get first"
        /* 0xF7 */ S_TALLYBELL,            // finish tallying points
        /* 0xF8 */ S_TALLYCOUNT,           // tallying points for championship
        /* 0xF9 */ V_CHAMPION              // "You're the champion!"
};

enum MidiId {
        /* 0xFF */ MIDI_NONE = 0xFF,
        /* 0x00 */ MIDI_MAIN_MENU = 0,
        /* 0x01 */ MIDI_SUNSET_SANDS,
        /* 0x02 */ MIDI_MOUNT_MAYHEM,
        /* 0x03 */ MIDI_METRO_MADNESS,
        /* 0x04 */ MIDI_WICKED_WOODS,
        /* 0x05 */ MIDI_INFERNO_ISLE,
        /* 0x06 */ MIDI_INTRO_MEDLEY,
        /* 0x07 */ MIDI_BEETLE_BATTLE,
        /* 0x08 */ MIDI_TOURNAMENT_RESULTS,
        /* 0x09 */ MIDI_COVENTRY_COVE,
        /* 0x0A */ MIDI_CREDITS,
        /* 0x0B */ MIDI_INTRO_1,
        /* 0x0C */ MIDI_INTRO_2,
        /* 0x0D */ MIDI_INTRO_3,
        /* 0x0E */ MIDI_INTRO_4,
        /* 0x0F */ MIDI_INTRO_5
};

#define MAX_VOLUME 0x7FFF

#endif /* SND_H */

// SPDX-License-Identifier: AGPL-3.0-or-later
typedef enum GameState_e {
    /* -1 */ INIT = -1, // used during game init
    /* 0 */ NONE = 0,
    /* 1 */ UNUSED_PARADIGM_LOGO = 1,
    /* 2 */ INTRO,
    /* 3 */ DEMO,            // Attract demo while idling at main menu
    /* 4 */ CREDITS,         // Demo with staff roll
    /* 5 */ RACE,            // Single and Multiplayer
    /* 6 */ BATTLE,          // Beetle Battle
    /* 7 */ VICTORY,         // Championship win screen
    /* 8 */ UFO_CAMERA,      // Free look camera
    /* 9 */ SCENE_EDITOR,    // General model viewer
    /* 10 */ TASK_EDITOR,    // Track editor
    /* 11 */ AI_EDIT,        // AI Path editor
    /* 12 */ TEXTURE_VIEWER, // Broken in final build
    /* 13 */ COLOR_BARS,     // color bars test screen
    /* 14 */ SELECTION,      // Save file select and main menu (game starts here)
    /* 15 */ PROFILE_CAR     // Additional car model viewer
} GameState;

typedef enum GameLanguage_e {
    /* 0 */ LANGUAGE_EN,
    /* 1 */ LANGUAGE_DE,
    /* 2 */ LANGUAGE_FR
} GameLanguage;

typedef enum GameTournament_e {
    /* 0 */ TOURN_NOVICE,
    /* 1 */ TOURN_ADVANCED,
    /* 2 */ TOURN_PRO,
    /* 3 */ TOURN_BONUS,
} GameTournament;

typedef enum GameTournRaceCount_e {
    /* 3 */ TOURN_NOVICE_RACE_COUNT = 3,
    /* 4 */ TOURN_ADVANCED_RACE_COUNT,
    /* 5 */ TOURN_PRO_RACE_COUNT,
    /* 6 */ TOURN_BONUS_RACE_COUNT
} GameTournRaceCount;

typedef enum GameOptionsMap_e {
    /* 0 */ OPTIONS_MAP_OFF,
    /* 1 */ OPTIONS_MAP_ZOOM,
    /* 2 */ OPTIONS_MAP_FULL
} GameOptionsMap;

typedef enum GameOptionsSound_e {
    /* 0 */ OPTIONS_SOUND_STEREO,
    /* 1 */ OPTIONS_SOUND_MONO
} GameOptionsSound;

typedef enum GameOptionsSpeed_e {
    /* 0 */ OPTIONS_SPEED_KPH,
    /* 1 */ OPTIONS_SPEED_MPH
} GameOptionsSpeed;

typedef enum GameOptionsDisplay_e {
    /* 0 */ OPTIONS_DISPLAY_OFF,
    /* 1 */ OPTIONS_DISPLAY_ON
} GameOptionsDisplay;

typedef enum TrackIds_e {
    /* 0 */ NONE = 0,
    /* 1 */ TEST_ROAD,
    /* 2 */ TEST_GRID,
    /* 3 */ CHECKER_BOARD,
    /* 4 */ ROUND_TRACK,
    /* 5 */ COVENTRY_COVE,
    /* 6 */ WICKED_WOODS,
    /* 7 */ MOUNT_MAYHEM,
    /* 8 */ SUNSET_SANDS,
    /* 9 */ INFERNO_ISLE,
    /* 10 */ METRO_MADNESS,
    /* 11 */ STUNT_O_RAMA,
    /* 12 */ TRACK_8,  // unused
    /* 13 */ TRACK_9,  // unused
    /* 14 */ TRACK_10, // unused
    /* 15 */ DRAGSTRIP,
    /* 16 */ DERBY,
    /* 17 */ MULT_1,
    /* 18 */ MULT_2,
    /* 19 */ MULT_3,
    /* 20 */ MULT_4,
    /* 21 */ MULT_5,
    /* 22 */ MULT_6,
    /* 23 */ MULT_7,
    /* 24 */ MULT_8,
    /* 25 */ MULT_9,
    /* 26 */ MULT_10,  // unused
    /* 27 */ INTRO1,
    /* 28 */ INTRO2,
    /* 29 */ INTRO3,
    /* 30 */ INTRO4,
    /* 31 */ INTRO5,
    /* 32 */ INTRO6,  // unused
    /* 33 */ FINISH
} TrackIds;

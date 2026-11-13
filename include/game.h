#ifndef GAME_H
#define GAME_H
// SPDX-License-Identifier: AGPL-3.0-or-later
typedef enum GameState_e {
    /* -1 */ GAME_STATE_INIT = -1, // used during game init
    /* 0 */ GAME_STATE_NONE = 0,
    /* 1 */ GAME_STATE_UNUSED_PARADIGM_LOGO = 1,
    /* 2 */ GAME_STATE_INTRO,
    /* 3 */ GAME_STATE_DEMO,            // Attract demo while idling at main menu
    /* 4 */ GAME_STATE_CREDITS,         // Demo with staff roll
    /* 5 */ GAME_STATE_RACE,            // Single and Multiplayer
    /* 6 */ GAME_STATE_BATTLE,          // Beetle Battle
    /* 7 */ GAME_STATE_VICTORY,         // Championship win screen
    /* 8 */ GAME_STATE_UFO_CAMERA,      // Free look camera
    /* 9 */ GAME_STATE_SCENE_EDITOR,    // General model viewer
    /* 10 */ GAME_STATE_TASK_EDITOR,    // Track editor
    /* 11 */ GAME_STATE_AI_EDIT,        // AI Path editor
    /* 12 */ GAME_STATE_TEXTURE_VIEWER, // Broken in final build
    /* 13 */ GAME_STATE_COLOR_BARS,     // color bars test screen
    /* 14 */ GAME_STATE_SELECTION,      // Save file select and main menu (game starts here)
    /* 15 */ GAME_STATE_PROFILE_CAR     // Additional car model viewer
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
    /* 0 */ TRACK_NONE = 0,
    /* 1 */ TRACK_TEST_ROAD,
    /* 2 */ TRACK_TEST_GRID,
    /* 3 */ TRACK_CHECKER_BOARD,
    /* 4 */ TRACK_ROUND_TRACK,
    /* 5 */ TRACK_COVENTRY_COVE,
    /* 6 */ TRACK_WICKED_WOODS,
    /* 7 */ TRACK_MOUNT_MAYHEM,
    /* 8 */ TRACK_SUNSET_SANDS,
    /* 9 */ TRACK_INFERNO_ISLE,
    /* 10 */ TRACK_METRO_MADNESS,
    /* 11 */ TRACK_STUNT_O_RAMA,
    /* 12 */ TRACK_8,  // unused
    /* 13 */ TRACK_9,  // unused
    /* 14 */ TRACK_10, // unused
    /* 15 */ TRACK_DRAGSTRIP,
    /* 16 */ TRACK_DERBY,
    /* 17 */ TRACK_MULT_1,
    /* 18 */ TRACK_MULT_2,
    /* 19 */ TRACK_MULT_3,
    /* 20 */ TRACK_MULT_4,
    /* 21 */ TRACK_MULT_5,
    /* 22 */ TRACK_MULT_6,
    /* 23 */ TRACK_MULT_7,
    /* 24 */ TRACK_MULT_8,
    /* 25 */ TRACK_MULT_9,
    /* 26 */ TRACK_MULT_10, // unused
    /* 27 */ TRACK_INTRO1,
    /* 28 */ TRACK_INTRO2,
    /* 29 */ TRACK_INTRO3,
    /* 30 */ TRACK_INTRO4,
    /* 31 */ TRACK_INTRO5,
    /* 32 */ TRACK_INTRO6, // unused
    /* 33 */ TRACK_FINISH
} TrackIds;

typedef enum TrackWeather_e {
    TRACK_WEATHER_CLEAR,
    TRACK_WEATHER_SNOW,
    TRACK_WEATHER_RAIN,
    TRACK_WEATHER_NONE
} TrackWeather;
#endif /* GAME_H */

#ifndef BAR_REPLAY_H
#define BAR_REPLAY_H
typedef struct ReplayExports_s {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 (*unk10)(void);
    /* 0x18 */ char pad14[0xC];                       /* maybe part of unk20[3]? */
    /* 0x20 */ s32 (*unk20)(s32);                     /* inferred */
    /* 0x24 */ char pad24[0x8];                    /* maybe part of unk20[5]? */
    /* 0x2C */ f32 (*unk2C)(s32, s32);
               s32 pad30;
    /* 0x34 */ void (*unk34)(s32);
    /* 0x38 */ void (*unk38)(s32, s32);
    /* 0x3C */ void (*unk3C)(s32);
} ReplayExports;
#endif /* BAR_REPLAY_H */

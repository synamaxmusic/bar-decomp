#ifndef BAR_REPLAY_H
#define BAR_REPLAY_H
typedef struct ReplayExports_s {
    u8 pad[0x2C];
    f32 (*unk2C)(s32, s32);
} ReplayExports;
#endif /* BAR_REPLAY_H */

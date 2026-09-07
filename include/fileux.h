#ifndef FILEUX_H
#define FILEUX_H
typedef struct FileUx_Exports_s {
    /* 0x00 */ void (*func_fileux_00400060)(void);                      /* inferred */
    /* 0x04 */ s32 (*fileuxWrite)(s32, u8 *, s32);         /* inferred */
    /* 0x08 */ s32 (*fileuxRead)(s32, u8 *, s32);         /* inferred */
    /* 0x0C */ s32 (*fileuxOpen)(u8*, s32, s32);          /* inferred */
    /* 0x10 */ s32 (*fileuxClose)(s32);                   /* inferred */
} FileUx_Exports;                                   /* size = 0x14 */
#endif /* FILEUX_H */

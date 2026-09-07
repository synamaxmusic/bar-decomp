// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "stdarg.h"
#include "global_exports.h"

#define MAX_FILE_DESCRIPTORS 21

typedef struct FileDescriptorState_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char buf[0x100];
} FileDescriptorState;

void __entrypoint_func_fileux_400000(FileUx_Exports *exports);
void func_fileux_00400060(void);
void func_fileux_00400068(void);
s32 fileuxStrlen(u8 *s);
void fileuxStrcpy(u8 **d, u8 *s, s32 len);
void func_fileux_00400138(void *arg0, s32 arg1);
s32 func_fileux_00400144(void);
s32 fileuxHostRequest(s32 mode, ...);
s32 fileuxWrite(s32 arg0, u8 *arg1, s32 arg2);
s32 fileuxRead(s32 arg0, u8 *arg1, s32 arg2);
s32 fileuxOpen(char *arg0, s32 arg1, s32 arg2);
s32 fileuxClose(s32 arg0);

// .data
s32 D_fileux_00400CE0[] = { 0x140000, __entrypoint_func_fileux_400000, 0, 0 };

// .rodata
static const char sStubbedPrintf[] = { " %02x" };
static const char sStubbedPrintf1[] = { "\n" };
static const char sStubbedPrintf2[] = {
    "=================================================================\n"
};
static const char sStubbedPrintf3[] = { "all synced up\n" };
static const char sStubbedPrintf4[] = { "requesting open [%s] mask [0x%x] cmask [0x%x]\n" };
static const char sStubbedPrintf5[] = { "result fd = %d\n" };
static const char sStubbedPrintf6[] = { "requesting read fd: %d buf: 0x%x  nbytes: %d\n" };
static const char sStubbedPrintf7[] = { "number of bytes read by host: %d\n" };
static const char sStubbedPrintf8[] = { "send acknowledge to host\n" };
static const char sStubbedPrintf9[] = { "reading %d bytes at offset %d\n" };
static const char sStubbedPrintf10[] = { "requesting write of fd: %d  buf: 0x%x nbytes:%d\n" };
static const char sStubbedPrintf11[] = { "sending buffer with %d bytes\n" };
static const char sStubbedPrintf12[] = { "requesting close of fd: %d\n" };
static const char sStubbedPrintf13[] = { "requesting lseek fd: %d  offs: %d  whence: %d\n" };

// .bss
s32 B_fileux_00400CF0[2]; // unreferenced padding
u8 D_fileux_00400CF8[0x200];
FileDescriptorState *sFileDescriptorsState[MAX_FILE_DESCRIPTORS];

void __entrypoint_func_fileux_400000(FileUx_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_fileux_00400060 = func_fileux_00400060;
    exports->fileuxWrite = fileuxWrite;
    exports->fileuxRead = fileuxRead;
    exports->fileuxOpen = fileuxOpen;
    exports->fileuxClose = fileuxClose;
}

void func_fileux_00400060(void) {
}

void func_fileux_00400068(void) {
}

s32 fileuxStrlen(u8 *s) {
    s32 len;
    u8 *str;

    len = 0;
    str = s;
    while (*str != '\0') {
        len++;
        str++;
    }

    return len;
}

void fileuxStrcpy(u8 **d, u8 *s, s32 len) {
    s32 i;
    u8 *src = s;

    for (i = 0; i < len; i++) {
        *(*d + i) = src[i];
    }

    *d += len;
}

void func_fileux_00400138(void *arg0, s32 arg1) {
}

s32 func_fileux_00400144(void) {
    return 1;
}

s32 fileuxHostRequest(s32 mode, ...) {
    u8 sp60[0x100];
    u8 *sp5C;
    u8 *sp58;
    s32 sp54;
    s32 sp50;
    s32 i; // a3
    s32 temp_v0;
    s32 sp44;
    s32 var_s0;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    va_list args;
    s32 a0;

    gUvGfxMgrExports->func_uvgfxmgr_rom_00402090();
    sp5C = sp60;
    for (i = 0; i < 0x100; i++) {
        sp60[i] = i;
    }

    func_fileux_00400138(sp5C, 0x100);
    if (func_fileux_00400144() == 0) {
        return -1;
    }

    i = 0;
    do {
    } while ((D_fileux_00400CF8[i] == (0xFF - i)) && (++i < 0x100));
    if (i) {
    }

    _uvMediaCopy(sp60, &mode, sizeof(int));
    sp5C += 4;
    va_start(args, mode);
    switch (mode) {
        case 'O':
            sp58 = va_arg(args, u8 *);
            sp44 = va_arg(args, s32);
            fileuxStrcpy(&sp5C, sp58, fileuxStrlen(sp58));
            *sp5C = '\0';
            sp5C += 1;
            fileuxStrcpy(&sp5C, &sp44, 4);
            if (sp44 & 0x100) {
                i = va_arg(args, s32);
                fileuxStrcpy(&sp5C, (u8 *) &i, 4);
            } else {
                i = 0;
            }
            func_fileux_00400138(sp60, 0x100);
            func_fileux_00400144();
            a0 = ((s32 *) D_fileux_00400CF8)[0];
            return a0;
        case 'R':
            sp50 = va_arg(args, s32);
            sp54 = va_arg(args, s32);
            sp3C = va_arg(args, s32);
            sp30 = va_arg(args, s32);
            fileuxStrcpy(&sp5C, &sp50, 4);
            fileuxStrcpy(&sp5C, &sp3C, 4);
            func_fileux_00400138(sp60, 0x100);
            func_fileux_00400144();

            if (sp30 != 0) {
                // FAKE
                if (&sp30) {
                }
                if (&sp30) {
                }
            }
            sp60[0] = 6;
            func_fileux_00400138(sp60, 0x100);
            for (i = 0; i < sp3C;) {
                temp_v0 = sp3C - i;
                if (temp_v0 < 0x100) {
                    var_s0 = temp_v0;
                } else {
                    var_s0 = 0x100;
                }
                func_fileux_00400144();
                _uvMediaCopy(sp54 + i, D_fileux_00400CF8, var_s0);
                i += var_s0;
            }

            // FAKE
            if ((a0 && a0) && a0) {
            }
            return sp3C;
        case 'W':
            sp50 = va_arg(args, s32);
            sp54 = va_arg(args, s32);
            sp3C = va_arg(args, s32);
            fileuxStrcpy(&sp5C, (u8 *) &sp50, 4);
            fileuxStrcpy(&sp5C, (u8 *) &sp3C, 4);
            func_fileux_00400138(sp60, 0x100);
            func_fileux_00400144();
            i = sp3C;
            if (sp3C & 7) {
                i = (sp3C - (sp3C % 8)) + 8;
            }
            func_fileux_00400138(sp54, i);
            func_fileux_00400144();
            a0 = ((s32 *) D_fileux_00400CF8)[0];
            return a0;
        case 'C':
            sp50 = va_arg(args, s32);
            fileuxStrcpy(&sp5C, (u8 *) &sp50, 4);
            func_fileux_00400138(sp60, 0x100);
            func_fileux_00400144();
            a0 = ((s32 *) D_fileux_00400CF8)[0];
            return a0;
        case 'L':
            sp50 = va_arg(args, s32);
            sp38 = va_arg(args, s32);
            sp34 = va_arg(args, s32);
            fileuxStrcpy(&sp5C, &sp50, 4);
            fileuxStrcpy(&sp5C, &sp38, 4);
            fileuxStrcpy(&sp5C, &sp34, 4);
            func_fileux_00400138(sp60, 0x100);
            func_fileux_00400144();
            a0 = ((s32 *) D_fileux_00400CF8)[0];
            return a0;
        default:
            return -1;
    }
}

s32 fileuxWrite(s32 fd, u8 *buf, s32 nbytes) {
    s32 var_a3;
    s32 var_s1;
    FileDescriptorState *fileDescriptorState;

    var_s1 = 0;
    if ((fd < MAX_FILE_DESCRIPTORS - 1) && (fd >= 0)) {
        fileDescriptorState = sFileDescriptorsState[fd];
    } else {
        fileDescriptorState = NULL;
    }
    if ((fileDescriptorState != NULL)
        && (((fileDescriptorState->unk0 == 0)) || (fileDescriptorState->unk8 == 0))) {
        fileDescriptorState->unk8 = 0;
        if (fileDescriptorState->unk0 > 0) {
            if ((0x100 - fileDescriptorState->unk0) < nbytes) {
                var_s1 = (0x100 - fileDescriptorState->unk0);
            } else {
                var_s1 = nbytes;
            }
            _uvMediaCopy((u8 *) fileDescriptorState + fileDescriptorState->unk0 + 0xC, buf, var_s1);
            fileDescriptorState->unk0 += var_s1;
            if (fileDescriptorState->unk0 == 0x100) {
                fileuxHostRequest('W', fd, fileDescriptorState->buf, 0x100);
                fileDescriptorState->unk0 = 0;
            }
        }
        if (var_s1 == nbytes) {
            return 0;
        }
        if (fileDescriptorState->unk0 != 0) {
            return 1;
        }
        while (var_s1 < nbytes) {
            if ((nbytes - var_s1) >= 0x101) {
                var_s1 += fileuxHostRequest('W', fd, buf + var_s1, 0x100);
            } else {
                _uvMediaCopy(fileDescriptorState->buf, buf + var_s1, (u32) (nbytes - var_s1));
                fileDescriptorState->unk0 = (nbytes - var_s1);
                var_s1 = nbytes;
            }
        }
        goto ret;
    }

    while (var_s1 < nbytes) {
        if ((nbytes - var_s1) < 0x100) {
            var_a3 = (nbytes - var_s1);
        } else {
            var_a3 = 0x100;
        }
        var_s1 += fileuxHostRequest('W', fd, buf + var_s1, var_a3);
    }

    if (var_s1 != nbytes) {
        return 1;
    }
ret:
    return 0;
}

s32 fileuxRead(s32 fd, u8 *buf, s32 nbytes) {
    FileDescriptorState *fileDescriptorState;
    s32 var_a3;
    s32 var_s1;
    s32 temp_v0_3;

    var_s1 = 0;
    if ((fd < MAX_FILE_DESCRIPTORS - 1) && (fd >= 0)) {
        fileDescriptorState = sFileDescriptorsState[fd];
    } else {
        fileDescriptorState = NULL;
    }
    if ((fileDescriptorState != NULL)
        && (((fileDescriptorState->unk0 == 0)) || (fileDescriptorState->unk8 != 0))) {
        fileDescriptorState->unk8 = 1;
        if (fileDescriptorState->unk0 != 0) {
            if (nbytes < (fileDescriptorState->unk0 - fileDescriptorState->unk4)) {
                var_s1 = nbytes;
            } else {
                var_s1 = (fileDescriptorState->unk0 - fileDescriptorState->unk4);
            }
            _uvMediaCopy(buf, (u8 *) fileDescriptorState + fileDescriptorState->unk4 + 0xC,
                         (u32) var_s1);
            fileDescriptorState->unk4 += var_s1;
        }
        if (var_s1 == nbytes) {
            return 0;
        }
        if ((fileDescriptorState->unk0 != 0)
            && (fileDescriptorState->unk0 != fileDescriptorState->unk4)) {
            return 1;
        }
        while (var_s1 < nbytes) {
            if ((nbytes - var_s1) >= 0x101) {
                var_s1 += fileuxHostRequest('R', fd, buf + var_s1, 0x100, 1);
                continue;
            }
            temp_v0_3 = fileuxHostRequest('R', fd, fileDescriptorState->buf, 0x100, 0);
            fileDescriptorState->unk0 = temp_v0_3;
            fileDescriptorState->unk4 = (nbytes - var_s1);
            if (temp_v0_3 < (nbytes - var_s1)) {
                return 1;
            }
            _uvMediaCopy(buf + var_s1, fileDescriptorState->buf, (u32) fileDescriptorState->unk4);
            var_s1 += fileDescriptorState->unk4;
        }

        goto ret;
    }
    while (var_s1 < nbytes) {
        if ((nbytes - var_s1) < 0x100) {
            var_a3 = (nbytes - var_s1);
        } else {
            var_a3 = 0x100;
        }
        var_s1 += fileuxHostRequest('R', fd, buf + var_s1, var_a3, 1);
    }
    if (var_s1 != nbytes) {
        return 1;
    }
ret:
    return 0;
}

s32 fileuxOpen(char *path, s32 flags, s32 mode) {
    s32 fd;

    fd = fileuxHostRequest('O', path, flags, mode);
    if (fd < 0) {
        return fd;
    } else if (fd < MAX_FILE_DESCRIPTORS - 1) {
        sFileDescriptorsState[fd] = malloc8(0x10C);
        if (sFileDescriptorsState[fd] != NULL) {
            sFileDescriptorsState[fd]->unk0 = 0;
        }
    }
    return fd;
}

s32 fileuxClose(s32 fd) {
    FileDescriptorState *fileDescriptorState;

    if (fd < 0) {
        return -1;
    }
    if (fd < MAX_FILE_DESCRIPTORS - 1) {
        fileDescriptorState = sFileDescriptorsState[fd];
        if (fileDescriptorState != NULL) {
            if ((fileDescriptorState->unk0 != 0) && (fileDescriptorState->unk8 == 0)) {
                fileuxHostRequest('W', fd, fileDescriptorState->buf, fileDescriptorState->unk0);
            }
            _uvMemFree(fileDescriptorState);
            sFileDescriptorsState[fd] = NULL;
        }
    }
    if (fileuxHostRequest('C', fd) < 0) {
        return -1;
    }
    return 0;
}

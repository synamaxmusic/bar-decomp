// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"

#define MIPS_INSTR_OFFSET(insn) (((insn) & 0x003FFFFF) << 1)
#define MIPS_HI16(x) ((x & 0xFFFF) << 0x10)
#define MIPS_LO16(x) (x & 0xFFFF)
#define CURRENT_MIPS_OP (instructionBase + instructionOffset)

typedef struct {
    u32 exportsSize;
    s32 entryPointOffset;
    s32 textSize;
    s32 rodataSize;
    s32 dataSize;
    s32 bssSize;
    s32 relocCount;
    s32 nameTag;
    s32 *relaContents;
} ModuleCommInfo; // size = 0x24

typedef enum MipsRelocation_e {
    MIPS_RELOC_HI16 = 0,
    MIPS_RELOC_LO16 = 1,
    MIPS_RELOC_26 = 2,
    MIPS_UNK_RELOC_3 = 3,
    MIPS_UNK_RELOC_4 = 4,
    MIPS_RELOC_32 = 5,
    MIPS_UNK_RELOC_6 = 6,
} MipsRelocation;

typedef enum MipsInstructionSection_e {
    INSTRUCTION_SECTION_TEXT,
    INSTRUCTION_SECTION_DATA,
    INSTRUCTION_SECTION_RODATA,
} MipsInstructionSection;

typedef enum SymbolSection_e {
    SYM_SECTION_TEXT,
    SYM_SECTION_RODATA,
    SYM_SECTION_DATA,
    SYM_SECTION_BSS,
} SymbolSection;

s32 uvGetModuleFileId(s32);
void *_uvAllocModule(s32);
void uvUnloadFile(s32, s32);
void uvDoModuleRelocs(u8 *, ModuleCommInfo *);

s32 *gModuleNameTags;
s32 *gModuleExportsSize;
s16 gModuleCount;

void uvModuleInit(void) {
    s32 i;
    s32 fileId;
    u8 *fileData;
    u32 size;
    ModuleCommInfo info;

    gModuleCount = uvGetFilesCount('UVMO');
    gModuleNameTags = _uvMemAllocAlign8(gModuleCount * 4);
    gModuleExportsSize = _uvMemAllocAlign8(gModuleCount * 4);
    for (i = 0; i < gModuleCount; i++) {
        fileData = uvGetFileData('UVMO', i);
        if (fileData != NULL) {
            fileId = uvFileReadHeader(fileData);
            uvFileSearchTag(fileId, &size, (void **) &fileData, 'COMM', 0);
            _uvMediaCopy(&info, (void *) fileData, size);
            uvFileFree(fileId);
            gModuleNameTags[i] = info.nameTag;
            gModuleExportsSize[i] = info.exportsSize;
        } else {
            gModuleNameTags[i] = 0;
            gModuleExportsSize[i] = 0;
        }
    }
}

s32 uvGetModuleFileId(s32 tag) {
    s32 i;

    for (i = 0; i < gModuleCount; i++) {
        if (tag == gModuleNameTags[i]) {
            return i;
        }
    }

    return -1;
}

void *uvGetLoadedModule(s32 tag) {
    s32 ret;

    ret = uvGetModuleFileId(tag);
    if (ret == -1) {
        return 0;
    }
    return uvGetLoadedFile('UVMO', ret);
}

void *uvLoadModule(s32 tag) {
    s32 fileId;

    fileId = uvGetModuleFileId(tag);
    if (fileId == -1) {
        return 0;
    }
    return _uvAllocModule(fileId);
}

void *_uvAllocModule(s32 fileId) {
    return uvLoadFile('UVMO', fileId);
}

void *uvLoadModuleCode(u8 *data) {
    s32 fileId;
    u32 tag;
    u32 blockSize;
    void *fileBlock;
    u8 *ovlStartPtr;
    s32 overlaySize;
    s32 headeredStartPtr;
    ModuleCommInfo info;
    void (*entryPointFunction)(void *);
    ModuleCommInfo *infoPtr = &info;

    fileId = uvFileReadHeader(data);
    while ((tag = uvFileReadBlock(fileId, &blockSize, &fileBlock, 1)) != 0) {
        switch (tag) {
            case 'COMM':
                _uvMediaCopy(&info, fileBlock, sizeof(info));
                _uvMemFree(fileBlock);
                break;
            case 'CODE':
                headeredStartPtr =
                    _uvMemAllocAlign16(infoPtr->exportsSize + blockSize + infoPtr->bssSize);
                ovlStartPtr = headeredStartPtr + infoPtr->exportsSize;
                _uvMediaCopy(ovlStartPtr, fileBlock, blockSize);
                _uvMemFree(fileBlock);
                break;
            case 'RELA':
                infoPtr->relaContents = fileBlock;
                break;
            default:
                _uvMemFree(fileBlock);
                break;
        }
    }

#ifdef ISPRINT
    {
        char *ptr;
        ptr = (char *) &infoPtr->nameTag;
        osSyncPrintf("Loading module: %c%c%c%c\n", ptr[0], ptr[1], ptr[2], ptr[3]);
        osSyncPrintf("headeredStartPtr = %08X\n", headeredStartPtr);
        osSyncPrintf("ovlStartPtr      = %08X\n", ovlStartPtr);
        osSyncPrintf(".rodata         = %08X\n", (u32) (ovlStartPtr + infoPtr->textSize));
        osSyncPrintf(".data      = %08X\n",
                     (u32) (ovlStartPtr + infoPtr->textSize + infoPtr->rodataSize));
        osSyncPrintf(".bss      = %08X\n",
                     (u32) (ovlStartPtr + infoPtr->textSize + infoPtr->dataSize + infoPtr->rodataSize));
        osSyncPrintf("exportsSize          = %08X\n", infoPtr->exportsSize);
    }
#endif

    uvFileFree(fileId);
    overlaySize = infoPtr->textSize + infoPtr->rodataSize + infoPtr->dataSize;
    uvMemSet(ovlStartPtr + overlaySize, 0, infoPtr->bssSize); // zero bss
    uvDoModuleRelocs(ovlStartPtr, &info);
    osWritebackDCache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    osInvalDCache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    osInvalICache(ovlStartPtr, overlaySize + infoPtr->bssSize);
    entryPointFunction = ovlStartPtr + infoPtr->entryPointOffset;
    _uvMemFree(infoPtr->relaContents);
    entryPointFunction(headeredStartPtr);

    return headeredStartPtr;
}

void uvUnloadModule(s32 tag) {
    uvUnloadFile('UVMO', uvGetModuleFileId(tag));
}

void uvDoModuleRelocs(u8 *ovlStartPtr, ModuleCommInfo *info) {
    u32 symBase;
    s32 instructionOffset;
    s32 mipsLo16;
    u32 haveHi16;
    s32 i;
    u32 symbolSection;
    u8 *instructionBase;
    s32 *lui;
    union {
        u32 lui;
        u32 targetInstructionSection;
    } u;
    u32 relocType;
    u32 pairedHiLoImm;

    // Queue of pending HI16 instruction words waiting on a matching LO16
#ifdef FIX_MODULE_RELOCS
#define MAX_QUEUE_SIZE 64
    s32 *hi16Queue[MAX_QUEUE_SIZE];
    s32 hi16QueueCount = 0;
#endif

    haveHi16 = FALSE;
    for (i = 0; i < info->relocCount; i++) {
        symbolSection = (u32) info->relaContents[i] >> 0x1C;
        u.targetInstructionSection = (u32) (info->relaContents[i] & 0x0C000000) >> 0x1A;
        relocType = (u32) (info->relaContents[i] & 0x03C00000) >> 0x16;
        instructionOffset = MIPS_INSTR_OFFSET(info->relaContents[i]);

        switch (symbolSection) {
            case SYM_SECTION_TEXT:
                symBase = (u32) ovlStartPtr;
                break;
            case SYM_SECTION_RODATA:
                symBase = (u32) ovlStartPtr + info->textSize;
                break;
            case SYM_SECTION_DATA:
                symBase = (u32) ovlStartPtr + info->textSize + info->rodataSize;
                break;
            case SYM_SECTION_BSS:
                symBase = (u32) ovlStartPtr + info->textSize + info->rodataSize + info->dataSize;
                break;
        }

        switch (u.targetInstructionSection) {
            case INSTRUCTION_SECTION_TEXT:
                instructionBase = ovlStartPtr;
                break;
            case INSTRUCTION_SECTION_DATA:
                instructionBase = ovlStartPtr + info->textSize + info->rodataSize;
                break;
            case INSTRUCTION_SECTION_RODATA:
                instructionBase = ovlStartPtr + info->textSize;
                break;
        }

        switch (relocType) {
            case MIPS_RELOC_HI16:
                haveHi16 = TRUE;
#ifdef FIX_MODULE_RELOCS
                if (hi16QueueCount < MAX_QUEUE_SIZE) {
                    hi16Queue[hi16QueueCount++] = (s32 *) CURRENT_MIPS_OP;
                }
#else
                lui = (s32 *) CURRENT_MIPS_OP;
#endif
                break;

            case MIPS_RELOC_LO16:
#ifdef FIX_MODULE_RELOCS
                mipsLo16 = MIPS_LO16(*(s32 *) (CURRENT_MIPS_OP));

                if (haveHi16 == TRUE && hi16QueueCount > 0) {
                    s32 j;

                    // Use the first queued HI16 immediate to resolve the queued relocs
                    u.lui = *(u32 *) hi16Queue[0];
                    pairedHiLoImm = MIPS_HI16(u.lui) + mipsLo16 + symBase;

                    if (pairedHiLoImm & 0x8000) {
                        pairedHiLoImm += 0x10000;
                    }
                    if (mipsLo16 & 0x8000) {
                        pairedHiLoImm -= 0x10000;
                    }

                    // Patch every queued HI16 instruction
                    for (j = 0; j < hi16QueueCount; j++) {
                        u.lui = *(u32 *) hi16Queue[j];
                        u.lui = (u.lui & 0xFFFF0000) | ((pairedHiLoImm >> 0x10) & 0xFFFF);
                        *hi16Queue[j] = (s32) u.lui;
                    }
                } else {
                    // Handle unmatched LO16 relocs
                    pairedHiLoImm = mipsLo16 + symBase;

                    if (mipsLo16 & 0x8000) {
                        pairedHiLoImm -= 0x10000;
                    }
                }

                // Reset queue
                hi16QueueCount = 0;
#else
                u.lui = *lui;

                mipsLo16 = MIPS_LO16(*(s32 *) (CURRENT_MIPS_OP));
                pairedHiLoImm = MIPS_HI16(u.lui) + mipsLo16 + symBase;

                if (pairedHiLoImm & 0x8000) {
                    pairedHiLoImm += 0x10000;
                }
                if (mipsLo16 & 0x8000) {
                    pairedHiLoImm -= 0x10000;
                }

                u.lui = (u.lui & 0xFFFF0000) | ((pairedHiLoImm >> 0x10) & 0xFFFF);

                if (haveHi16 == TRUE) {
                    *lui = u.lui;
                }
#endif
                haveHi16 = FALSE;
                *((s16 *) (CURRENT_MIPS_OP) + 1) = (s16) (pairedHiLoImm & 0xFFFF);
                break;

            case MIPS_UNK_RELOC_3:
            case MIPS_UNK_RELOC_4:
                break;

            case MIPS_RELOC_26:
                *(s32 *) (CURRENT_MIPS_OP) += (u32) (symBase & 0x0FFFFFFF) >> 2;
                break;

            case MIPS_RELOC_32:
            case MIPS_UNK_RELOC_6:
                *(s32 *) (CURRENT_MIPS_OP) += symBase;
                break;

            default:
                break;
        }
    }
}

s32 func_80003A14(u32 addr, s32 *fileId) {
    s32 i;
    s32 currentFileId;
    u32 moduleAddr;
    u32 currentAddr;

    currentAddr = 0;
    currentFileId = -1;
    for (i = 0; i < uvGetFilesCount('UVMO'); i++) {
        moduleAddr = uvGetLoadedFile('UVMO', i);
        if ((moduleAddr < addr) && (currentAddr < moduleAddr)) {
            currentFileId = i;
            currentAddr = moduleAddr;
        }
    }
    if (fileId != NULL) {
        *fileId = currentFileId;
    }
    if (currentFileId == -1) {
        return 0;
    }
    return gModuleNameTags[currentFileId];
}

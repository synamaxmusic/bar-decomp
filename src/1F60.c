// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"

typedef struct formFileEntryStruct_s {
    s32 romPtr;
    s32 ovlPtr;
    s32 instanceCount;
    s32 pad; // always zero
} formFileEntryStruct;

typedef struct formTagLookUp_s {
    s32 tag;
    u16 moduleCount;
    u16 unk6; // size?
    formFileEntryStruct *structPtr;
} formTagLookUp;

typedef struct UnkStruct_8002D9BC_s {
    u16 unk0;
    u16 *unk4;
    u16 *unk8;
} UnkStruct_8002D9BC;

typedef struct UnkStruct_80001BC0_s  {
    void (*unk0)(void);
} UnkStruct_80001BC0;

typedef struct UnkStruct_80003520_s {
    s32 unk0;
    void *(*unk4)(s32);
    void *(*unk8)(UnkStruct_80001BC0*);
} UnkStruct_80003520;

void func_800032E4(UnkStruct_80001BC0* arg1);                          /* extern */
extern formTagLookUp *D_8002D9B4;
extern UnkStruct_8002D9BC *D_8002D9BC;
extern formFileEntryStruct *D_8002D9A4;
extern u16 sFormFilesCount;


s32 func_800019B8(s32, s32);            /* extern */
s32 uvCheckValidTag(s32 tag);                    /* extern */
UnkStruct_80003520 *func_80003520(s32); /* extern */
s32 uvLoadModuleCode(s32);                 /* extern */
void func_80003760(s32);                /* extern */
UnkStruct_8002D9BC *func_80001724(s32, s32);          /* extern */
s32 uvCheckValidFileId(s32 tag, s32 fileId);
void func_80001BC0(s32 arg0, UnkStruct_80001BC0* arg1);
void func_80001A68(s32 arg0, s32 arg1);

#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/formLoader.s")

u16 func_800015D4(s32 tag, s32 fileId) {
    s32 temp_v0;

    temp_v0 = uvCheckValidTag(tag);
    if (temp_v0 == -1) {
        return 0U;
    }
    if (uvCheckValidFileId(temp_v0, fileId) == -1) {
        return 0U;
    }
    return D_8002D9B4[temp_v0].structPtr[fileId].instanceCount;
}

u16 uvGetFilesCount(s32 tag) {
    s32 temp_v0;

    temp_v0 = uvCheckValidTag(tag);
    if (temp_v0 == -1) {
        return 0U;
    }
    return D_8002D9B4[temp_v0].moduleCount;
}

s32 uvGetFileData(s32 tag, s32 fileId) {
    s32 temp_v0;

    temp_v0 = uvCheckValidTag(tag);
    if (temp_v0 == -1) {
        return 0;
    }
    if (uvCheckValidFileId(temp_v0, fileId) == -1) {
        return 0;
    }
    return D_8002D9B4[temp_v0].structPtr[fileId].romPtr;
}

UnkStruct_8002D9BC *func_80001724(s32 tag, s32 fileId) {
    s32 temp_v0;

    temp_v0 = uvCheckValidTag(tag);
    if (temp_v0 == -1) {
        return NULL;
    }
    if (uvCheckValidFileId(temp_v0, fileId) == -1) {
        return NULL;
    }
    return (UnkStruct_8002D9BC *) D_8002D9B4[temp_v0].structPtr[fileId].ovlPtr;
}

// unused?
s32 func_800017A4(s32 tag, s32 fileId) {
    s32 temp_v0;

    temp_v0 = uvCheckValidTag(tag);
    if (temp_v0 == -1) {
        return 0;
    }
    if (uvCheckValidFileId(temp_v0, fileId) == -1) {
        return 0;
    }
    return D_8002D9B4[temp_v0].structPtr[fileId].pad;
}

s32 uvLoader(s32 tag, s32 fileId) {
    formFileEntryStruct *temp_s0;
    s32 temp_v0;
    s32 i;

    temp_v0 = uvCheckValidTag(tag);
    if (temp_v0 == -1) {
        return 0;
    }
    temp_s0 = &D_8002D9B4[temp_v0].structPtr[fileId];
    if (temp_s0->romPtr == 0) {
        temp_s0->ovlPtr = 0;
        return 0;
    }
    if ((tag == 'UVTX') && (D_8002D9BC != NULL)) {
        for (i = 0; i < D_8002D9BC->unk0; i++) {
            if (fileId == D_8002D9BC->unk4[i]) {
                temp_v0 = func_800019B8('UVTX', D_8002D9BC->unk8[i]);
                temp_s0->ovlPtr = temp_v0;
                return temp_v0;
            }
        }
    }
    if (tag == 'UVMO') {
        D_8002D9A4 = temp_s0;
        temp_s0->ovlPtr = uvLoadModuleCode(temp_s0->romPtr);
        D_8002D9A4 = NULL;
    } else if (D_8002D9B4[temp_v0].tag != 0xFFFF) {
        temp_s0->ovlPtr = func_80003520(D_8002D9B4[temp_v0].tag)->unk8(temp_s0->romPtr);
        func_80003760(D_8002D9B4[temp_v0].tag);
    } else {
        temp_s0->ovlPtr = temp_s0->romPtr;
    }
    return temp_s0->ovlPtr;
}

void func_800019A8(s32 arg0) {
    D_8002D9A4->ovlPtr = arg0;
}

s32 func_800019B8(s32 arg0, s32 fileId) {
    formFileEntryStruct* temp_v1;
    s32 ret;

    ret = uvCheckValidTag(arg0);
    if (ret == -1) {
        return 0;
    }
    if (uvCheckValidFileId(ret, fileId) == -1) {
        return 0;
    }
    temp_v1 = &D_8002D9B4[ret].structPtr[fileId];
    temp_v1->structPtr++;
    if (temp_v1->structPtr == 1) {
        temp_v1->ovlPtr = uvLoader(arg0, (s32) fileId);
    }
    return temp_v1->ovlPtr;
}

void func_80001A68(s32 arg0, s32 fileId) {
    formFileEntryStruct *ptr;
    s32 temp_v0;
    

    temp_v0 = uvCheckValidTag(arg0);
    if (temp_v0 == -1) {
        return;
    }

    if (uvCheckValidFileId(temp_v0, fileId) == -1) {
        return;
    }

    ptr = &D_8002D9B4[temp_v0].structPtr[fileId];
    if (ptr->structPtr == 0) {
        return;
    }

    if (--D_8002D9B4[temp_v0].structPtr[fileId].instanceCount) {
        return;
    }

    if ((arg0 == 'UVTX')) {
        if (D_8002D9BC != NULL) {
            s32 i;
            for (i = 0; i < D_8002D9BC->unk0; i++) {
                if (fileId == D_8002D9BC->unk4[i]) {
                    func_80001A68('UVTX', D_8002D9BC->unk8[i]);
                    ptr->ovlPtr = 0;
                    ptr->pad = 0;
                    return;
                }
            }
        }
    }

    fileId = ptr->ovlPtr;
    if (fileId != 0) {
        func_80001BC0(arg0, fileId);
    }
    ptr->ovlPtr = 0;
    ptr->pad = 0;
}

void func_80001BC0(s32 arg0, UnkStruct_80001BC0* arg1) {
    s32 temp_v0;
    

    temp_v0 = uvCheckValidTag(arg0);
    if (temp_v0 != -1) {
        if (arg0 == 'UVMO') {
            arg1->unk0();
            func_800032E4(arg1);
            return;
        }
        func_80003520(D_8002D9B4[temp_v0].tag)->unk8(arg1);
        func_80003760(D_8002D9B4[temp_v0].tag);
    }
}

void func_80001C6C(void) {
    s32 i;
    s32 j;
    
    for (i = 0; i < sFormFilesCount; i++) {
        for (j = 0; j < D_8002D9B4[i].moduleCount; j++) {
            D_8002D9B4[i].structPtr[j].instanceCount = 0;
        }
    }
}

u32 uvFileReadBlock(s32 fileId, u32 *sizeOut, void **data, s32 decodeFlag) {
    u32 tag;
    u8 *allocPtr;
    u32 size;
    u8 *dst;

    tag = uvFileGetEntryTag(fileId, sizeOut, data);
    if (tag != 0) {
        allocPtr = _uvMemAllocAlign8(*sizeOut);
        _uvMediaCopy(allocPtr, *data, *sizeOut);
        *data = allocPtr;
    }
    if (tag == 'GZIP') { // 0x475A4950
        tag = (u32) uvMemRead(allocPtr, 4);
        size = (u32) uvMemRead(allocPtr + 4, 4);
        if (!(decodeFlag & 2)) {
            dst = _uvMemAllocAlign8(size);
            mio0Decode(allocPtr + 8, dst);
            _uvMemFree(allocPtr);
            *data = dst;
        }
        *sizeOut = size;
    }
    return tag;
}

void uvConsumeBytes(void* dst, u8** ptr, u32 size) {
    u64 mem;

    if (size < sizeof(s64) + 1) {
        mem = uvMemRead(*ptr, size);
        *ptr += size;
        switch (size) {                             /* irregular */
        case sizeof(s8):
            *(s8*)dst = mem;
            return;
        case sizeof(s16):
            *(s16*)dst = mem;
            return;
        case sizeof(s32):
            *(s32*)dst = mem;
            return;
        case sizeof(s64):
            *(s64*)dst  = mem;
            return;
        }
    } else {
        _uvMediaCopy(dst, *ptr, size);
        *ptr += size;
    }
}


#ifdef NEEDS_BSS
s32 uvCheckValidTag(s32 tag) {
    formTagLookUp* ptr;
    static s32 i;
    

    if (tag == D_8002D9B4[i].tag) {
        return i;
    }

    for (i = 0; i < sFormFilesCount; i++) {
        if (tag == D_8002D9B4[i].tag) {
            return i;
        }
    }

    return -1;
    
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/uvCheckValidTag.s")
#endif

#ifdef NEEDS_BSS
s32 func_80001F38(s32 arg0) {
    static s32 D_8001F794;
    formTagLookUp* var_a1;
    s32 var_v1;

    if (arg0 == D_8002D9B4[D_8001F794].romPtr) {
        return D_8001F794;
    }
    
    for (D_8001F794 = 0; D_8001F794 < sFormFilesCount; D_8001F794++) {
        if (arg0 == D_8002D9B4[D_8001F794].romPtr) {
            return D_8001F794;
        }
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1F60/func_80001F38.s")
#endif

s32 uvCheckValidFileId(s32 tag, s32 fileId) {
    if ((fileId < 0) || (fileId >= D_8002D9B4[tag].moduleCount)) {
        return -1;
    }
    return 0;
}


u8* func_80002004(s32 arg0) {
    int temp;
    s32 i;
    s32 j;

    for (i = arg0; i < sFormFilesCount; i++) {
        for (j = 0; j < D_8002D9B4[i].moduleCount; j++) {
            int temp = D_8002D9B4[i].structPtr[j].romPtr;
            if (temp) {
                return temp;
            }
        }
    }

    return UVTS_10_ROM_END;
}

void func_80002088(s32* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < sFormFilesCount; i++) {
        if (i >= arg3) {
            *arg2 = arg3;
            return;
        }

        arg0[i] = D_8002D9B4[i].tag;
        arg1[i] = func_80002004(i + 1) - func_80002004(i);
    }

    *arg2 = i;
}

void func_8000218C(s32* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 j;
    s32 i;

    for (i = 0; i < sFormFilesCount; i++) {
        if (i >= arg3) {
            *arg2 = arg3;
            return;
        }
        
        arg0[i] = D_8002D9B4[i].tag;
        for (j = 0, arg1[i] = 0; j < D_8002D9B4[i].moduleCount; j++) {
            arg1[i] += D_8002D9B4[i].structPtr[j].pad;
        }
    }

    *arg2 = i;
}

void func_8000226C(s32* tagPtr, s32* arg1, s32* arg2, u32 arg3) {
    u32 var_v0;
    s32 var_a0;
    s32 var_v1;
    s32 temp_a3;   
    s32 var_t4;
    s32 var_t2;
    s32 var_t3;
    

    var_v0 = 0x80000000;
    for (var_v1 = 0; var_v1 < sFormFilesCount; var_v1++) {
        for (var_a0 = 0; var_a0 < D_8002D9B4[var_v1].moduleCount; var_a0++) {
            temp_a3 = D_8002D9B4[var_v1].structPtr[var_a0].ovlPtr;
            if ((temp_a3 < arg3) && (var_v0 < temp_a3)) {
                var_t2 = var_v1;
                var_t3 = var_a0;
                var_v0 = temp_a3;
                var_t4 = arg3 - temp_a3;
            }
        }
    }
 
    if (var_v0 != 0x80000000) {
        *tagPtr = D_8002D9B4[var_t2].tag;
        *arg1 = var_t3;
        *arg2 = var_t4;
        return;
    }
    
    *tagPtr = 'CODE';
    *arg1 = 0;
    *arg2 = arg3 - var_v0;
}

void func_80002390(s32 arg0) {
    if (arg0 == 0xFFFF) {
        D_8002D9BC = 0;
    } else {
        D_8002D9BC = func_80001724('UVTP', arg0);
    }
    if (D_8002D9BC); // FAKE
}

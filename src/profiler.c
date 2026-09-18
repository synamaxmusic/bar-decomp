// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "stdarg.h"

typedef enum ProfilerState_e {
    PROF_STATE_INT,
    PROF_STATE_NON_INT
} ProfilerState;

#define MAX_PROFILER_ENTRIES 40

typedef struct ProfilerEntry_s {
    /* 0x00 */ f64 unk0;                            /* inferred */
    /* 0x08 */ f64 unk8;
    /* 0x10 */ f64 unk10;
    /* 0x18 */ f64 unk18;                           /* inferred */
    /* 0x20 */ char* label;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;                            /* inferred */
    /* 0x2A */ char pad2A[6];                       /* maybe part of unk29[7]? */
} ProfilerEntry;                               /* size = 0x30 */

// .data
u32 D_8001F770 = 1;
UNUSED s32 D_8001F774 = 0;
UNUSED s32 D_8001F778 = 0;
UNUSED s32 D_8001F77C = 0;
s32 gDebugProfilingState = PROF_STATE_INT;

// .bss
ProfilerEntry sProfilerEntries[MAX_PROFILER_ENTRIES];
s32 D_8002D930;

void func_80001040(s32, s32);                          /* extern */
void uvProfilerResetEntry(s32);                               /* extern */
void func_80000EC8(s32, ...);

s32 uvProfilerCreate(char* label) {
    ProfilerEntry* profilerEntry;
    s32 var_v1;
    s32 i;

    for (i = 0; i < MAX_PROFILER_ENTRIES; i++) {
        profilerEntry = &sProfilerEntries[i];
        if (profilerEntry->unk29 == 0) {
            profilerEntry->unk29 = 1;
            profilerEntry->label = label;
            return i;
        }
    }
    return -1;
}

void uvProfilerReset(s32 id) {
    uvProfilerResetEntry(id);
}

void func_80000CA4(s32 id) {
    if (gDebugProfilingState == 0) {
        return;
    }

    if (sProfilerEntries[id].unk28 == 0) {
        sProfilerEntries[id].unk29 = 1;
        // if Profiling is set to 2 ("Non Int"), everything speeds up
        if (gDebugProfilingState == 2) {
            if (D_8001F770 == 1) {
                D_8001F770 = osSetIntMask(OS_IM_NONE);
                D_8002D930 = 0;
            } else {
                D_8002D930++;
            }
        }
        sProfilerEntries[id].unk8 = uvClkGetSec(0x6B);
    
    }
}

void func_80000D58(s32 id) {
    f64 temp_fa0;
    f64 temp_fv0;
    f64 temp_fv1;

    if (gDebugProfilingState == 0) {
        return;
    }

    temp_fa0 = uvClkGetSec(0x6B);
    if (D_8002D930 > 0) {
        D_8002D930 -= 1;
    } else if (D_8001F770 != 1) {
        osSetIntMask(D_8001F770);
        D_8001F770 = 1;
    }
    if (sProfilerEntries[id].unk28 == 0) {
        if (sProfilerEntries[id].unk8 == -1.0) {
            if (sProfilerEntries[id].label != NULL) {
            }
        } else {
            temp_fv0 = temp_fa0 - sProfilerEntries[id].unk8;
            sProfilerEntries[id].unk8 = -1.0;
            sProfilerEntries[id].unk0 = temp_fv0;
            sProfilerEntries[id].unk24 += 1;
            sProfilerEntries[id].unk18 += temp_fv0;
        }
    }
}

void func_80000E50(s32 id, s32 arg1) {
    sProfilerEntries[id].unk24 += arg1;
}

void uvProfilerResetEntry(s32 id) {
    sProfilerEntries[id].unk24 = 0;
    sProfilerEntries[id].unk28 = 0;
    sProfilerEntries[id].unk29 = 0;
    sProfilerEntries[id].label = NULL;
    sProfilerEntries[id].unk18 = 0.0;
    sProfilerEntries[id].unk0 = 0.0;
    sProfilerEntries[id].unk10 = 0.0;
    sProfilerEntries[id].unk8 = -1.0;
}

void func_80000EC8(s32 id, ...) {
    ProfilerEntry *profilerEntry;
    f64 *temp_a0_2;
    u32 prop;
    s32* ptr;
    va_list args;

    profilerEntry = &sProfilerEntries[id];
    va_start(args, id);
    while (TRUE) {
        prop = va_arg(args, int);
        switch (prop) {
            case 0:
                break;
            case 1:
                temp_a0_2 = va_arg(args, double*);
                if (profilerEntry->unk24 != 0) {
                    *temp_a0_2 = profilerEntry->unk18 / (f64) profilerEntry->unk24;
                } else {
                    *temp_a0_2  = 0.0;
                }
                continue;
            case 2:
                *va_arg(args, double*) = profilerEntry->unk18;
                continue;
            case 3:
                *va_arg(args, double*) = profilerEntry->unk0;
                continue;
            case 4:
                *va_arg(args, u32*) = profilerEntry->unk24;
               continue;
        }
        break;
    }
}

void uvProfilerInit(void) {
    s32 i;

    if (D_8001F770 != 1) {
        osSetIntMask(D_8001F770);
        D_8001F770 = 1;
        D_8002D930 = 0;
    }
    for (i = 0; i < MAX_PROFILER_ENTRIES; i++) {
        uvProfilerResetEntry(i);
    }
    uvClkReset(0x6B);
}

void func_80001038(s32 id) {

}

void func_80001040(s32 id, s32 arg1) {    
    f64 temp;
    s32 pad;

    if (sProfilerEntries[id].unk8 != -1.0) {        
        if ((arg1 != 0) && (sProfilerEntries[id].unk28 == 0)) {            
            temp = uvClkGetSec(0x6B);
            sProfilerEntries[id].unk10 = temp;
            
        }
        if ((arg1 == 0) && (sProfilerEntries[id].unk28 != 0)) {
            temp = uvClkGetSec(0x6B);
            sProfilerEntries[id].unk8 += temp - sProfilerEntries[id].unk10;
        }
    }
    sProfilerEntries[id].unk28 = arg1;
}

void func_80001104(void) {
}

void func_8000110C(s32 arg1) {
    s32 i;

    for (i = 0; i < MAX_PROFILER_ENTRIES; i++) {
        func_80001040(i, arg1);
    }
}

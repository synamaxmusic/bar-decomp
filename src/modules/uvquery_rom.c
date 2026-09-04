// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "stdarg.h"

#define QUERY_ARRAYS_COUNT 100

void __entrypoint_func_uvquery_rom_400000(UvQuery_Exports *exports);
void func_uvquery_rom_004001AC(void);
f32* uvQueryGetFloatValues(void);
s32* uvQueryGetIntValues(void);
Vec3F* uvQueryGetFloatVectors(void);
s32 func_uvquery_rom_00400224(void);
s32 *func_uvquery_rom_00400270(void);
s32 *func_uvquery_rom_0040027C(void);
s32 func_uvquery_rom_00400288(void);
void uvQueryDoSorting(void);
void *func_uvquery_rom_004004CC(void);
void func_uvquery_rom_004004F4(s32 id, ...);
void func_uvquery_rom_00400558(s32 id, ...);
void func_uvquery_rom_004005C0(f32 *arg0, s32 arg1);
void func_uvquery_rom_004005D4(s32 arg0, u16 arg1);
s32 func_uvquery_rom_004005EC(void);
s32 *func_uvquery_rom_004005F8(void);
s32 func_uvquery_rom_00400604(void);
u16 func_uvquery_rom_00400610(void);

s32 sQueryArraysCount = QUERY_ARRAYS_COUNT;

s32 D_uvquery_rom_00400624[] = {0x00480000, __entrypoint_func_uvquery_rom_400000, 0};

s32 *sQueryIntValues;
f32 *sQueryFloatValues;
Vec3F *sQueryFloatVectors;
s32 sQueryCount;
s32 D_uvquery_rom_00400640;
void *D_uvquery_rom_00400644;
s32 D_uvquery_rom_00400648;
void *D_uvquery_rom_0040064C;
s32 D_uvquery_rom_00400650;
s32 D_uvquery_rom_00400654;
s32 D_uvquery_rom_00400658;
s32 D_uvquery_rom_0040065C;
u16 D_uvquery_rom_00400660;

void __entrypoint_func_uvquery_rom_400000(UvQuery_Exports *exports) {
    uvUpdateFileAllocPtr(exports);
    exports->func_uvquery_rom_004001AC = func_uvquery_rom_004001AC;
    exports->func_uvquery_rom_004004F4 = func_uvquery_rom_004004F4;
    exports->uvQueryGetFloatValues = uvQueryGetFloatValues;
    exports->func_uvquery_rom_00400558 = func_uvquery_rom_00400558;
    exports->uvQueryGetIntValues = uvQueryGetIntValues;
    exports->func_uvquery_rom_004005C0 = func_uvquery_rom_004005C0;
    exports->uvQueryGetFloatVectors = uvQueryGetFloatVectors;
    exports->func_uvquery_rom_004005D4 = func_uvquery_rom_004005D4;
    exports->func_uvquery_rom_00400224 = func_uvquery_rom_00400224;
    exports->func_uvquery_rom_004005EC = func_uvquery_rom_004005EC;
    exports->func_uvquery_rom_00400270 = func_uvquery_rom_00400270;
    exports->func_uvquery_rom_004005F8 = func_uvquery_rom_004005F8;
    exports->func_uvquery_rom_0040027C = func_uvquery_rom_0040027C;
    exports->func_uvquery_rom_00400604 = func_uvquery_rom_00400604;
    exports->func_uvquery_rom_00400288 = func_uvquery_rom_00400288;
    exports->func_uvquery_rom_00400610 = func_uvquery_rom_00400610;
    exports->uvQueryDoSorting = uvQueryDoSorting;
    exports->func_uvquery_rom_004004CC = func_uvquery_rom_004004CC;
    sQueryIntValues = _uvMemAllocAlign8(sQueryArraysCount * sizeof(s32));
    sQueryFloatValues = _uvMemAllocAlign8(sQueryArraysCount * sizeof(f32));
    sQueryFloatVectors = _uvMemAllocAlign8(sQueryArraysCount * sizeof(Vec3F));
    D_uvquery_rom_00400644 = _uvMemAllocAlign8(sQueryArraysCount * sizeof(int));
    D_uvquery_rom_0040064C = _uvMemAllocAlign8(sQueryArraysCount * 0x78);
    D_uvquery_rom_00400650 = 0;
    D_uvquery_rom_00400654 = 0;
    D_uvquery_rom_0040065C = 0;
    D_uvquery_rom_00400660 = 0;
}

void func_uvquery_rom_004001AC(void) {
    _uvMemFree(sQueryIntValues);
    _uvMemFree(sQueryFloatValues);
    _uvMemFree(sQueryFloatVectors);
    _uvMemFree(D_uvquery_rom_00400644);
    _uvMemFree(D_uvquery_rom_0040064C);
}

f32* uvQueryGetFloatValues(void) {
    return sQueryFloatValues;
}

s32* uvQueryGetIntValues(void) {
    return sQueryIntValues;
}

Vec3F* uvQueryGetFloatVectors(void) {
    return sQueryFloatVectors;
}

s32 func_uvquery_rom_00400224(void) {
    if (D_uvquery_rom_00400650 != 0) {
        return (D_uvquery_rom_00400654 < sQueryArraysCount) ? D_uvquery_rom_00400654
                                                                 : sQueryArraysCount;
    }
    return sQueryArraysCount;
}

s32 *func_uvquery_rom_00400270(void) {
    return &sQueryCount;
}

s32 *func_uvquery_rom_0040027C(void) {
    return &D_uvquery_rom_00400640;
}

s32 func_uvquery_rom_00400288(void) {
    return D_uvquery_rom_00400644;
}

/*
* Sort values from the query arrays using a selection sort algorithm
* 
* original name: _uvDbSortHits  
*/
void uvQueryDoSorting(void) {
    s32 i;
    s32 j;
    f32 x;
    f32 y;
    f32 z;
    s32 intVal;
    f32 floatVal;

    if (sQueryCount >= sQueryArraysCount) {
        return;
    }

    for (i = 0; i < sQueryCount; i++) {
        if (sQueryFloatValues[i] == 2.0f) {
            continue;
        }
        for (j = i + 1; j < sQueryCount; j++) {
            #if UV_OLD
            if (FABS(sQueryFloatValues[i] - sQueryFloatValues[j]) < 0.001f) {
                sQueryFloatValues[i] = 2.0f;
                sQueryFloatValues[j] = 2.0f;
            }
            #endif
        }
    }

    // Sort values from smallest to largest
    for (i = 0; i < sQueryCount; i++) {
        for (j = i; j < sQueryCount; j++) {
            // Sort using the float values
            if (sQueryFloatValues[j] < sQueryFloatValues[i]) {
                intVal = sQueryIntValues[i];
                floatVal = sQueryFloatValues[i];
                x = sQueryFloatVectors[i].x;
                y = sQueryFloatVectors[i].y;
                z = sQueryFloatVectors[i].z;
                sQueryIntValues[i] = sQueryIntValues[j];
                sQueryFloatValues[i] = sQueryFloatValues[j];
                sQueryFloatVectors[i].x = sQueryFloatVectors[j].x;
                sQueryFloatVectors[i].y = sQueryFloatVectors[j].y;
                sQueryFloatVectors[i].z = sQueryFloatVectors[j].z;
                sQueryIntValues[j] = intVal;
                sQueryFloatValues[j] = floatVal;
                sQueryFloatVectors[j].x = x;
                sQueryFloatVectors[j].y = y;
                sQueryFloatVectors[j].z = z;
            }
        }
    }

    while (sQueryCount != 0) {
        if (sQueryFloatValues[sQueryCount - 1] != 2.0f) {
            break;
        }
        sQueryCount--;
    }
}

void *func_uvquery_rom_004004CC(void) {
    if (D_uvquery_rom_00400650 != 0) {
        return D_uvquery_rom_00400650;
    }
    return D_uvquery_rom_0040064C;
}

void func_uvquery_rom_004004F4(s32 id, ...) {
    s32 prop;
    va_list args;

    va_start(args, id);

    while (TRUE) {
        prop = va_arg(args, s32);
        if ((prop == 0) || (prop != 1)) {
            break;
        }
        D_uvquery_rom_00400648 = va_arg(args, s32);
    }
}

void func_uvquery_rom_00400558(s32 id, ...) {
    s32 prop;
    va_list args;

    va_start(args, id);

    while (TRUE) {
        prop = va_arg(args, s32);
        if ((prop == 0) || (prop != 1)) {
            break;
        }
        *va_arg(args, s32 *) = D_uvquery_rom_00400648;
    }
}

void func_uvquery_rom_004005C0(f32 *arg0, s32 arg1) {
    D_uvquery_rom_00400650 = arg0;
    D_uvquery_rom_00400654 = arg1;
}

void func_uvquery_rom_004005D4(s32 arg0, u16 arg1) {
    D_uvquery_rom_0040065C = arg0;
    D_uvquery_rom_00400660 = arg1;
}

s32 func_uvquery_rom_004005EC(void) {
    return D_uvquery_rom_0040065C;
}

s32 *func_uvquery_rom_004005F8(void) {
    return &D_uvquery_rom_00400658;
}

s32 func_uvquery_rom_00400604(void) {
    return D_uvquery_rom_00400658;
}

u16 func_uvquery_rom_00400610(void) {
    return D_uvquery_rom_00400660;
}

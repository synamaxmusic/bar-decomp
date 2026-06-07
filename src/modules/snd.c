// SPDX-License-Identifier: AGPL-3.0-or-later
#include "common.h"
#include "module.h"
#include "global_exports.h"
#include "snd.h"

typedef struct UnkStruct_snd_00406198_s {
    /* 0x00 */ u8 unk0;                             /* inferred */
    /* 0x01 */ u8 unk1;                             /* inferred */
    /* 0x02 */ u8 pad2[0x08-0x02];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ char pad[0x8];
    /* 0x18 */ u8 unk18;
} UnkStruct_snd_00406198;      

typedef struct UnkStruct_snd_00406198_2 {
    /* 0x00 */ UnkStruct_snd_00406198* unk0;
    /* 0x02 */ s32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ char pad[0x8];
    /* 0x18 */ u8 unk18;
} UnkStruct_snd_00406198_2;

typedef struct UnkSnd_004064F0_s {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0x1C];                     /* maybe part of unk0[8]? */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 unk26;                            /* inferred */
    /* 0x27 */ char pad27[1];
} UnkSnd_004064F0;  

typedef struct UnkSnd_00402504_s{
    f32 unk0;
    u8 unk4;
} UnkSnd_00402504;

extern f32 D_snd_00404604;
UnkStruct_snd_00406198* func_snd_004023F4(s32);
extern UnkStruct_snd_00406198_2* D_snd_00406198;
extern UnkSnd_004064F0 D_snd_004064F0[];
extern UnkSnd_004064F0 D_snd_004064C8[];

void __entrypoint_func_snd_400000(Snd_Exports *arg0);
void func_snd_004013DC(s32);                           /* extern */
void func_snd_00401434(s32);                           /* extern */
void func_snd_00401474(s32);                           /* extern */
void func_snd_004014E0(s16);                           /* extern */
//void* func_snd_004023F4(s32);                       /* extern */
extern s32 D_snd_00406B08;
extern u8 D_snd_00406B48;
extern void func_snd_004004F8(void);
extern void func_snd_004005C8(void);
extern void func_snd_00400750(void);
extern void func_snd_00400854(void);
extern void func_snd_0040094C(s16, s32);
extern void func_snd_00400A64(void);
extern void func_snd_00400B0C(void);
extern void func_snd_00400B54(void);
extern void func_snd_00400E90(s32);
extern void func_snd_00400EA0(s32);
extern void func_snd_00400EB4(s32);
extern void func_snd_00400EC0(void);
extern void func_snd_00401038(void);
extern void func_snd_004012F4(u16);
extern void func_snd_00401304(u8);
extern f32 func_snd_004014B4(void);
extern f32 func_snd_004014C4(void);
extern void func_snd_004014D4(s32);
extern void func_snd_00401564(u8);
extern void func_snd_00401650(void);
extern void func_snd_00401694(void);
extern void func_snd_00401800(void);
extern void func_snd_00401914(void);
extern void func_snd_00401A28(void);
extern void func_snd_00401AA8(void);
extern void func_snd_00401CDC(void);
extern void func_snd_00401D14(void);
extern void func_snd_00401D54(void);
extern void func_snd_00401DA0(void);
extern void func_snd_00401E08(void);
extern void func_snd_00401E70(void);
extern void func_snd_00401EB8(void);
extern void func_snd_00401F48(void);
extern void func_snd_00401FD8(void);
extern void func_snd_00402020(void);
extern void func_snd_00402084(void);
extern void func_snd_004020D0(void);
extern void func_snd_0040211C(void);
extern void func_snd_0040216C(void);
extern void func_snd_0040221C(void);
extern void func_snd_004022D0(void);
extern void func_snd_0040231C(void);
extern f32 func_snd_00402368(s32);
extern s32 func_snd_00402388(s32);
extern s32 func_snd_004023A8(s32);
extern UnkStruct_snd_00406198* func_snd_004023D4(s32);
extern void func_snd_00402424(void);
extern void func_snd_00402504(void);
extern void func_snd_0040252C(u8);
extern u8 func_snd_004025EC(s32);
extern void func_snd_004025FC(s32);
extern void func_snd_0040260C(void);
extern void func_snd_0040264C(void);
extern void func_snd_00402660(s32);
extern void func_snd_004027E8(void);
extern void func_snd_0040284C(void);
extern void func_snd_00402B40(void);
extern void func_snd_00402DC0(void);
extern void func_snd_00402E1C(void);

extern u8 D_snd_00406168;
extern u16 D_snd_00406190;
extern u8 D_snd_00406194;
extern u8 D_snd_004063B8;
extern u8 D_snd_004064B8;
extern s32 D_snd_004064BC;
extern f32 D_snd_004045D0;
extern f32 D_snd_004045D4;

void __entrypoint_func_snd_400000(Snd_Exports* arg0) {
    s32 var_v0;    
    s32 sp28;
    UnkStruct_snd_00406198* temp_v0;
    u8 i;
    s32 j;
    
    uvUpdateFileAllocPtr(arg0);
    arg0->func_snd_004027E8 = func_snd_004027E8;
    arg0->func_snd_0040284C = func_snd_0040284C;
    arg0->func_snd_004005C8 = func_snd_004005C8;
    arg0->func_snd_00400750 = func_snd_00400750;
    arg0->func_snd_00400854 = func_snd_00400854;
    arg0->func_snd_0040094C = func_snd_0040094C;
    arg0->func_snd_00400A64 = func_snd_00400A64;
    arg0->func_snd_00400B0C = func_snd_00400B0C;
    arg0->func_snd_00400B54 = func_snd_00400B54;
    arg0->func_snd_00400E90 = func_snd_00400E90;
    arg0->func_snd_00400EA0 = func_snd_00400EA0;
    arg0->func_snd_004004F8 = func_snd_004004F8;
    arg0->func_snd_004014D4 = func_snd_004014D4;
    arg0->func_snd_00401564 = func_snd_00401564;
    arg0->func_snd_0040211C = func_snd_0040211C;
    arg0->func_snd_00401650 = func_snd_00401650;
    arg0->func_snd_0040216C = func_snd_0040216C;
    arg0->func_snd_00401694 = func_snd_00401694;
    arg0->func_snd_00402B40 = func_snd_00402B40;
    arg0->func_snd_0040221C = func_snd_0040221C;
    arg0->func_snd_00401800 = func_snd_00401800;
    arg0->func_snd_00402DC0 = func_snd_00402DC0;
    arg0->func_snd_004022D0 = func_snd_004022D0;
    arg0->func_snd_00401914 = func_snd_00401914;
    arg0->func_snd_00402E1C = func_snd_00402E1C;
    arg0->func_snd_0040231C = func_snd_0040231C;
    arg0->func_snd_00401A28 = func_snd_00401A28;
    arg0->func_snd_00402368 = func_snd_00402368;
    arg0->func_snd_00401AA8 = func_snd_00401AA8;
    arg0->func_snd_00402388 = func_snd_00402388;
    arg0->func_snd_00401CDC = func_snd_00401CDC;
    arg0->func_snd_004023A8 = func_snd_004023A8;
    arg0->func_snd_00401D14 = func_snd_00401D14;
    arg0->func_snd_004023D4 = func_snd_004023D4;
    arg0->func_snd_004023F4 = func_snd_004023F4;
    arg0->func_snd_00400EB4 = func_snd_00400EB4;
    arg0->func_snd_00400EC0 = func_snd_00400EC0;
    arg0->func_snd_00401038 = func_snd_00401038;
    arg0->func_snd_00401D54 = func_snd_00401D54;
    arg0->func_snd_004012F4 = func_snd_004012F4;
    arg0->func_snd_00401DA0 = func_snd_00401DA0;
    arg0->func_snd_00402424 = func_snd_00402424;
    arg0->func_snd_00401304 = func_snd_00401304;
    arg0->func_snd_00401E08 = func_snd_00401E08;
    arg0->func_snd_00402504 = func_snd_00402504;
    arg0->func_snd_004013DC = func_snd_004013DC;
    arg0->func_snd_00401E70 = func_snd_00401E70;
    arg0->func_snd_0040252C = func_snd_0040252C;
    arg0->func_snd_00401434 = func_snd_00401434;
    arg0->func_snd_00401EB8 = func_snd_00401EB8;
    arg0->func_snd_004025EC = func_snd_004025EC;
    arg0->func_snd_00401474 = func_snd_00401474;
    arg0->func_snd_00401F48 = func_snd_00401F48;
    arg0->func_snd_004025FC = func_snd_004025FC;
    arg0->func_snd_004014B4 = func_snd_004014B4;
    arg0->func_snd_00401FD8 = func_snd_00401FD8;
    arg0->func_snd_0040260C = func_snd_0040260C;
    arg0->func_snd_004014C4 = func_snd_004014C4;
    arg0->func_snd_00402020 = func_snd_00402020;
    arg0->func_snd_0040264C = func_snd_0040264C;
    arg0->func_snd_00402084 = func_snd_00402084;
    arg0->func_snd_00402660 = func_snd_00402660;
    arg0->func_snd_004020D0 = func_snd_004020D0;
        
    for (i = 1; i < 40; i++) {
        func_snd_004014E0(i);
    } 
    D_snd_00406B48 = -1;
    gUvFmtxExports->func_00400B68((Mtx4F* ) &D_snd_00406B08);
    gUvEmitterExports->func_uvemitter_rom_004023B0(0);
    gUvCmidiExports->func_uvcmidi_rom_00400454(0);
    func_snd_004013DC(gGameSettings->optionsMusicVol);
    func_snd_00401434(gGameSettings->optionsSfxVol);
    func_snd_00401474(gGameSettings->optionsSpeechVol);
    gUvEmitterExports->func_uvemitter_rom_004029D8(2U, 1.0f);
    sp28 = 250;
    for (j = 0; j < sp28; j++) {
        temp_v0 = func_snd_004023F4(j);
        if ((temp_v0->unk0 == 0x56) && (temp_v0->unk1 == 0x5F)) {
            var_v0 = 1;
        } else if ((temp_v0->unk0 == 0x53) && (temp_v0->unk1 == 0x5F)) {
            var_v0 = 2;
        } else {
            var_v0 = 0;
        }
        if (j == 0xB) {
            var_v0 = 0;
        }
        if ((j == 0xAA) || (j == 0x86) || (j == 0xAC) || (j == 0xAD) || (j == 0xAE) || (j == 0x97) || (j == 0xA0) || (j == 0xDF) || (j == 0x9F) || (j == 0xAF) || (j == 0xAF) || (j == 0xAF)) {
            var_v0 = 1;
        }
        gUvEmitterExports->func_uvemitter_rom_004029A4(j, var_v0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004004F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004005C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400750.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400854.s")

void func_snd_0040094C(s16 arg0, s32 arg1) {
    u8 ret;

    ret = gUvEmitterExports->func_uvemitter_rom_004006FC();
    gUvEmitterExports->func_uvemitter_rom_00400E60(ret, arg1);
    if (ret == 0xFF) {
        return;
    }
        
    gUvEmitterExports->func_uvemitter_rom_004007B4(ret, arg0);
    gUvEmitterExports->func_uvemitter_rom_00400D48(ret, (f32) func_snd_004023A8(arg0) / D_snd_004045D0);
    gUvEmitterExports->func_uvemitter_rom_00400EBC(ret, 5, 0x30, 0);
    gUvEmitterExports->func_uvemitter_rom_00400BE8(ret, func_snd_004014B4() * D_snd_004045D4);
    gUvEmitterExports->func_uvemitter_rom_00401010(ret);
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400A64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400B0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400B54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400CD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400DDC.s")

void func_snd_00400E90(s32 arg0) {
    *(&D_snd_004064B8 + arg0) = 0;
}

void func_snd_00400EA0(s32 arg0) {
    *(&D_snd_004064B8 + arg0) = 1;
}

void func_snd_00400EB4(s32 arg0) {
    D_snd_00406168 = arg0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00400EC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401038.s")

void func_snd_004012F4(u16 arg0) {
    D_snd_00406190 = arg0;
}


void func_snd_00401304(u8 arg0) {
    switch (arg0) {
    case 0:
    case 3:
        func_snd_0040252C(0);
        if (D_snd_00406194 != 0) {
            gUvCmidiExports->func_uvcmidi_rom_00400940();
        }

        gUvCmidiExports->func_uvcmidi_rom_0040062C(D_snd_00406190);
        gUvCmidiExports->func_uvcmidi_rom_004006F4();
        D_snd_00406194 = 1;
        break;
    case 2:
    case 1:
        if (D_snd_00406194 != 0) {
            gUvCmidiExports->func_uvcmidi_rom_00400940();
            D_snd_00406194 = 0;
        }
    }
    
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004013DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401434.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401474.s")

f32 func_snd_004014B4(void) {
    return 1.0f;
}

f32 func_snd_004014C4(void) {
    return 1.0f;
}

void func_snd_004014D4(s32 arg0) {
    D_snd_004064BC = arg0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004014E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401564.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401650.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401694.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401800.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401914.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401A28.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401AA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401CDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401D14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401D54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401DA0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401E08.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401E70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401EB8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401F48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00401FD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00402020.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00402084.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004020D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040211C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040216C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040221C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004022D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040231C.s")

f32 func_snd_00402368(s32 arg0) {
    return D_snd_00406198[arg0].unkC;
}

s32 func_snd_00402388(s32 arg0) {
    return D_snd_00406198[arg0].unk4;
}

s32 func_snd_004023A8(s32 arg0) {
    return D_snd_00406198[arg0].unk8;
}

UnkStruct_snd_00406198* func_snd_004023D4(s32 arg0) {
    return D_snd_00406198[arg0].unk18;
}

UnkStruct_snd_00406198* func_snd_004023F4(s32 arg0) {
    if (arg0 >= 0) {
        return D_snd_00406198[arg0].unk0;
    }
    return 0;
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00402424.s")

void func_snd_00402504(UnkSnd_00402504* arg0) {
    if (arg0 == NULL) {
        *(s32*)0 = 0;
        return;
    }
    arg0->unk4 = 0xFF;
    arg0->unk0 = -1.0f;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040252C.s")

u8 func_snd_004025EC(s32 arg0) {
    return *(&D_snd_004063B8 + arg0);
}

void func_snd_004025FC(s32 arg0) {
    *(&D_snd_004063B8 + arg0) = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040260C.s")

void func_snd_0040264C(s32 arg0) {
    *(&D_snd_004063B8 + arg0) = 1;
}


void func_snd_00402660(s32 arg0) {
    s32 count;
    s32 i;
    s32 j;
    s32 spDC[32];
    s32 sp5C[32];

    func_snd_0040264C();
    count = gUvEmitterExports->func_uvemitter_rom_00402754(spDC, sp5C);
    
    for (i = 0; i < count; i++) {
        if (arg0 == spDC[i]) {
            for (j = 1; j < 40; j++) {
                if (D_snd_004064C8[j].unk24 == spDC[i]) {
                    gUvEmitterExports->func_uvemitter_rom_00400BE8(j, 0.0f);
                    gUvEmitterExports->func_uvemitter_rom_004010CC(j);
                    func_snd_00401564(j);
                } else {
                    if (gUvEmitterExports->func_uvemitter_rom_00400834(j) == spDC[i]) {
                        gUvEmitterExports->func_uvemitter_rom_00400BE8(j, 0.0f);
                        gUvEmitterExports->func_uvemitter_rom_004010CC(j);
                        gUvEmitterExports->func_uvemitter_rom_0040075C(j);
                    }
                }
            } 
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_004027E8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_0040284C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00402B40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/modules/snd/func_snd_00402DC0.s")

void func_snd_00402E1C(void) {
}



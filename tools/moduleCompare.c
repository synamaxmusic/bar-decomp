#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <argp.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "rabbitizer.h"

#define MODULE_FILES_SECTION_FAKE_VADDR 0x400000
#define MODULE_TEXT_START 0x50

typedef enum ModuleFileSection_e {
    MODULE_SECTION_TEXT,
    MODULE_SECTION_RODATA,
    MODULE_SECTION_DATA,
    MODULE_SECTION_BSS
} ModuleFileSection;

typedef struct ModuleCommInfo_s {
    uint32_t headerSize;
    int32_t entryPointOffset;
    int32_t textSize;
    int32_t rodataSize;
    int32_t dataSize;
    int32_t bssSize;
    int32_t relocCount; // Reloc count?
    int32_t nameTag;
    int32_t relaContents;
} ModuleCommInfo; // size = 0x24

typedef struct ModuleFileHeader_s {
    int32_t formTag;
    int32_t fileSize;
    int32_t moduTag;
    int32_t padTag;
    int32_t padSize;
    int32_t padContents; // Structure padding
    int32_t commTag;
    int32_t commSize;
    ModuleCommInfo commInfo;
} ModuleFileHeader; // size 0x44

typedef struct ModuleFileMdbgInfo_s {
    int32_t mdbgTag;
    int32_t mdbgSize;
    char mdbgInfo[0x20]; // Module debug info
} ModuleFileMdbgInfo;

typedef struct RelaInfo_s {
    int32_t relaTag;
    int32_t relaSize;
} RelaInfo;

typedef struct ModuleSection_s {
    uint8_t* start;
    uint32_t size;
} ModuleSection;

typedef struct ModuleToolArguments_s {
    char *input;
    char *output;
    bool printRelocs;
    bool applyRelocs;
    bool writeRelocsFile;
    bool writeSymsFile;
} ModuleToolArguments;

static char CurrentTagName[6];

int MaxWordsToPrint = 6;

size_t getFileSize(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    size_t fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

uint32_t Utils_ReadBe32(const uint8_t *p) {
    return ((uint32_t) p[0] << 24) | ((uint32_t) p[1] << 16) | ((uint32_t) p[2] << 8)
           | ((uint32_t) p[3]);
}

void byteSwapModuleFileHeader(ModuleFileHeader *header) {
    int *ptr = (int *) header;

    for (int32_t i = 0; i < sizeof(ModuleFileHeader); i += sizeof(int32_t), ptr++) {
        *ptr = __builtin_bswap32(*ptr);
    }
}

static char *tagToString(uint32_t tag) {
    tag = __builtin_bswap32(tag);
    char *tagPtr = (char *) &tag;
    for (int i = 0; i < 4; i++) {
        CurrentTagName[i] = tagPtr[i];
    }
    CurrentTagName[5] = '\0';
    return CurrentTagName;
}

uint8_t* readFile(char* path) {
    struct stat path_stat;
    stat(path, &path_stat);
    FILE *fp = fopen(path, "rb");

    if (fp == NULL) {
        printf("Couldn't open %s\n", path);
        perror("");
        exit(EXIT_FAILURE);
    }

    if (S_ISDIR(path_stat.st_mode)) {
        printf("Not a file %s\n", path);
        exit(EXIT_FAILURE);
    }

    size_t fileSize = getFileSize(fp);
    uint8_t *buf = malloc(fileSize);
    if (buf == NULL) {
        perror("Can't alloc memory for file");
        exit(EXIT_FAILURE);
    }

    fread(buf, fileSize, 1, fp);
    fclose(fp);
    return buf;
}

void printInstruction(int word, const char *immOverride) {
    char *buffer;
    size_t bufferSize;
    size_t immOverrideLength = 0;
    RabbitizerInstruction instr;

    RabbitizerInstruction_init(&instr, word, MODULE_FILES_SECTION_FAKE_VADDR);
    RabbitizerInstruction_processUniqueId(&instr);

    if (immOverride != NULL) {
        immOverrideLength = strlen(immOverride);
    }

    bufferSize = RabbitizerInstruction_getSizeForBuffer(&instr, immOverrideLength, 0);
    buffer = malloc(bufferSize + 1);
    if (buffer == NULL) {
        perror("Can't alloc memory for instruction buffer");
        abort();
    }

    RabbitizerInstruction_disassemble(&instr, buffer, immOverride, immOverrideLength, 0);

    printf("%s", buffer);

    free(buffer);

}

void compareTextSection(ModuleSection* target, ModuleSection* current) {
    bool diff = false;
    int differingWords = 0;
    if (target->size != current->size) {
        printf("section .text size mismatch current 0x%X != target 0x%X\n", target->size, current->size);
    }

    int32_t* targetWord = (void*)target->start;
    int32_t* currentWord = (void*)current->start;
    int size = target->size;


    printf("Instr diff in .text\n");
    for (int i = 0; i < size; i += sizeof(int32_t)) {
        int targetInstruction = __builtin_bswap32(*targetWord);
        int currentInstruction = __builtin_bswap32(*currentWord);  

        if (targetInstruction != currentInstruction) {
            if (differingWords < MaxWordsToPrint) {
                printf("Instruction difference: 0x%X != 0x%X\n", targetInstruction, currentInstruction);
                printInstruction(targetInstruction, NULL);
                printf(" vs ");
                printInstruction(currentInstruction, NULL);
                printf("\n");
            }

            diff = true;
            differingWords++;
        }

        targetWord++;
        currentWord++;
    }

    printf("%d words differing\n", differingWords);
    if ((size - current->size) > 0) {
        printf("Current .text has %d extra instructions\n", size - current->size);
    }

    if (!diff) {
        printf("No differences in .text!\n");
    }
}

void compareDataSection(ModuleSection* target, ModuleSection* current, char* name) {
    bool diff = false;
    int differingWords = 0;
    if (target->size != current->size) {
        printf("section %s size mismatch current %x != target %x\n", name, target->size, current->size);
    }

    int32_t* targetWordPtr = (void*)target->start;
    int32_t* currentWordPtr = (void*)current->start;
    int size = target->size;

    printf("Diffs in %s\n", name);
    for (int i = 0; i < size; i += sizeof(int32_t)) {
        int targetWord = __builtin_bswap32(*targetWordPtr);
        int currentWord = __builtin_bswap32(*currentWordPtr);  
        if (targetWord != currentWord) { 
            diff = true;

            if (differingWords < MaxWordsToPrint) {
                printf("current 0x%X vs target 0x%X\n", currentWord, targetWord);
            }
            differingWords++;
        }
        targetWordPtr++;
        currentWordPtr++;
    }

    printf("%d words differing in %s\n", differingWords, name);

    if (!diff) {
        printf("No differences in %s!\n", name);
    }
    printf("\n");
}

void diffSection(ModuleFileHeader* targetHeader, ModuleFileHeader* currentHeader, uint8_t* targetBuf, uint8_t* currentBuf, ModuleFileSection section) {
    ModuleSection targetSection;
    ModuleSection currentSection;

    switch (section) {
        case MODULE_SECTION_TEXT:
            targetSection.size = targetHeader->commInfo.textSize;
            currentSection.size = currentHeader->commInfo.textSize;
            targetSection.start = &targetBuf[MODULE_TEXT_START];
            currentSection.start = &currentBuf[MODULE_TEXT_START];

            compareTextSection(&targetSection, &currentSection);
            break;
        case MODULE_SECTION_RODATA:
            targetSection.size = targetHeader->commInfo.rodataSize;
            currentSection.size = currentHeader->commInfo.rodataSize;

            int32_t currentRodataStart = currentHeader->commInfo.textSize + MODULE_TEXT_START;
            int32_t targetRodataStart = targetHeader->commInfo.textSize + MODULE_TEXT_START;
            targetSection.start = &targetBuf[targetRodataStart];
            currentSection.start = &currentBuf[currentRodataStart];
            compareDataSection(&targetSection, &currentSection, ".rodata");
            break;
        case MODULE_SECTION_DATA:
            targetSection.size = targetHeader->commInfo.rodataSize;
            currentSection.size = currentHeader->commInfo.rodataSize;
            int32_t currentDataStart = currentHeader->commInfo.textSize + currentHeader->commInfo.dataSize + MODULE_TEXT_START;
            int32_t targetDataStart = targetHeader->commInfo.textSize + targetHeader->commInfo.dataSize + MODULE_TEXT_START;

            targetSection.start = &targetBuf[targetDataStart];
            currentSection.start = &currentBuf[currentDataStart];
            compareDataSection(&targetSection, &currentSection, ".data");
            break;
        case MODULE_SECTION_BSS:
            if (currentHeader->commInfo.bssSize != targetHeader->commInfo.bssSize) {
                printf(".bss section size mismatch %d != %d", currentHeader->commInfo.bssSize, targetHeader->commInfo.bssSize);
            } else {
                printf("No differences in .bss!\n");
            }
            break;
        default:
            break;
    }
}

void compareRela(int currentRelCount, int targetRelCount, RelaInfo* currentRelaInfo, RelaInfo* targetRelaInfo) {
    if (currentRelaInfo->relaSize != targetRelaInfo->relaSize) {
        printf("RELA size mismatch %d != %d\n", currentRelaInfo->relaSize, targetRelaInfo->relaSize);
    }

    bool diff = false;
    int differingWords = 0;
    uint32_t *currentRelocs = (uint32_t *) (currentRelaInfo + 1);
    uint32_t *targetRelocs = (uint32_t *) (targetRelaInfo + 1);

    for (int i = 0; i < targetRelCount; i++) {
        int currentWord = __builtin_bswap32(currentRelocs[i]);
        int targetWord = __builtin_bswap32(targetRelocs[i]);

        if (currentWord != targetWord) {
            diff = true;
            continue;
        }
    }

    if (!diff) {
        printf("No diff in RELA\n");
    } else {
        printf("%d differing words in RELA\n", differingWords);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("moduleCompare <target> <current>\n");
        exit(EXIT_FAILURE);
    }

    char* targetFilePath = argv[1];
    char* currentFilePath = argv[2];

    uint8_t* targetFileBuf = readFile(targetFilePath);
    uint8_t* currentFileBuf = readFile(currentFilePath);

    ModuleFileHeader targetFileHeader = *(ModuleFileHeader *) targetFileBuf;
    ModuleFileHeader currentFileHeader = *(ModuleFileHeader *) currentFileBuf;

    byteSwapModuleFileHeader(&targetFileHeader);
    byteSwapModuleFileHeader(&currentFileHeader);

    if (targetFileHeader.commInfo.nameTag != currentFileHeader.commInfo.nameTag) {
        printf("Not the same module ");
        printf("%s", tagToString(targetFileHeader.commInfo.nameTag));
        printf(" != ");
        printf("%s", tagToString(currentFileHeader.commInfo.nameTag));
        printf("\n");
        exit(EXIT_FAILURE);
    }

    diffSection(&targetFileHeader, &currentFileHeader, targetFileBuf, currentFileBuf, MODULE_SECTION_TEXT);
    diffSection(&targetFileHeader, &currentFileHeader, targetFileBuf, currentFileBuf, MODULE_SECTION_RODATA);
    diffSection(&targetFileHeader, &currentFileHeader, targetFileBuf, currentFileBuf, MODULE_SECTION_DATA);
    diffSection(&targetFileHeader, &currentFileHeader, targetFileBuf, currentFileBuf, MODULE_SECTION_BSS);

    // Compare RELA

    int currentMdbgEntry = MODULE_TEXT_START + currentFileHeader.commInfo.textSize
                           + currentFileHeader.commInfo.dataSize
                           + currentFileHeader.commInfo.rodataSize;

    int targetMdbgEntry = MODULE_TEXT_START + targetFileHeader.commInfo.textSize
                           + targetFileHeader.commInfo.dataSize
                           + targetFileHeader.commInfo.rodataSize;

    RelaInfo *currentRelaInfo = (RelaInfo *) &currentFileBuf[currentMdbgEntry + sizeof(ModuleFileMdbgInfo)];
    RelaInfo *targetRelaInfo = (RelaInfo *) &targetFileBuf[targetMdbgEntry + sizeof(ModuleFileMdbgInfo)];


    compareRela(currentFileHeader.commInfo.relocCount, targetFileHeader.commInfo.relocCount, currentRelaInfo, targetRelaInfo);
}
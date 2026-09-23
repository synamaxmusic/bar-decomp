
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <elf.h>
#include <stdint.h>
#include <assert.h>
#include <linux/swab.h>
#include "cjson/cJSON.h"
#define STB_LOG
#define STB_VECTOR
#include "stb_vc_vector.h"
#include "elf_parse.h"

// Small log library
#include "stb_log.h"

typedef struct CategoryInfo_s {
    int count;
    cJSON *files;
} CategoryInfo;

typedef struct Form0Header_s {
    int32_t formTag;
    int32_t form0Size;
    int32_t uvftTag;
} Form0Header;

typedef struct Form0Entry_s {
    int32_t tag;
    int32_t count;
    int32_t *offsets;
} Form0Entry;

#define UVMO_HEADER_SIZE 0x50
#define MDBG_SIZE 0x28
#define RELA_HEADER_SIZE 0x8

#define FORM_TAGS 20
#define IS_ALIGNED_16(x)  (((x) & 0xF) == 0)
#define IS_ALIGNED_8(ptr) (((uintptr_t) (ptr) & 0x7) == 0)
#define ALIGN16(x) (((x) + 0xF) & ~0xF)
#define ALIGN8(x) (8 - (x & 7)) & 7
#define ARRAY_COUNT(arr) (int) (sizeof(arr) / sizeof(arr[0]))

// TODO: This should be integrated in the JSON file
const char *TagOrder[] = { "UVTT", "UVDS", "UVTX", "UVTR", "UVCT", "UVVL", "UVMD", "UVAN", "UVEN",
                           "UVRW", "UVPX", "UVBT", "UVFT", "UVSX", "UVMS", "UVMB", "UVTS" };

Form0Entry Form0TableEntries[FORM_TAGS];
cJSON *Root;
static char CurrentTagName[6];
int CurrentRelativeOffset = 0;
bool NonMatchingFlag = false;
int TotalEntriesSize = 0;
int RomEndRelativeOffset;
int GeneratedForm0Size;

void initEntries(void) {
    memset(Form0TableEntries, 0, sizeof(Form0TableEntries));
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

size_t getFileSize(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    size_t fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

int getRelaSize(Section* section) {
    int relaSize = 0;

    vc_vector* relocTable = ElfParse_GetRelocTable();
    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable); i = vc_vector_next(relocTable, i)) {
        RelocTableEntry* rel = i;
        Symbol* sym = &rel->symbol;

        if (sym->section == SHN_UNDEF) {
            continue;
        }

        if (strcmp(rel->targetSection, section->name) != 0) {
            continue;
        }

        if (rel->relocType != R_MIPS_26 && rel->relocType != R_MIPS_LO16
            && rel->relocType != R_MIPS_HI16 && rel->relocType != R_MIPS_32) {
            continue;
        }

        relaSize += sizeof(int32_t);
    }

    return relaSize;
}

/*
 * Computes an approximated size for a UVMO file by
 * Adding the sections sizes of an input ELF and RELA 
 * which is calculated by counting all the Relocations
 * of an ELF file in words
 * 
 * @param path Path othe ELF file
 */
int computeUvmoSize(const char *path) {
    ElfParse_Init(path);

    int relaArraySize = 0;
    int sectionsSize = 0;
    Section *text = ElfParse_GetSection(".text");
    Section *rodata = ElfParse_GetSection(".rodata");
    Section *data = ElfParse_GetSection(".data");

    if (text != NULL) {
        relaArraySize += getRelaSize(text);
        sectionsSize += text->size;
    }

    if (rodata != NULL) {
        relaArraySize += getRelaSize(rodata);
        sectionsSize += rodata->size;
    }

    if (data != NULL) {
        relaArraySize += getRelaSize(data);
        sectionsSize += data->size;
    }

    int iffSpecificSize = UVMO_HEADER_SIZE + MDBG_SIZE + RELA_HEADER_SIZE;
    int uvmoSize = iffSpecificSize + sectionsSize + relaArraySize;

    if (!IS_ALIGNED_8(uvmoSize)) {
        uvmoSize += ALIGN8(uvmoSize);
    }

    log_info("Sections size in: %x", sectionsSize);
    log_info("RELA size: %x", relaArraySize);
    log_info("Calculated size for %s is: %x", path, uvmoSize);

    ElfParse_Destroy();
    return uvmoSize;
}

int stringToTag(const char *tag) {
    int convertedTag = ((uint32_t) tag[0] << 24) | ((uint32_t) tag[1] << 16) | ((uint32_t) tag[2] << 8)
                       | ((uint32_t) tag[3]);
    log_info("Converted tag %s -> %x", tag, convertedTag);
    return convertedTag;
}

void readForm0Json(char *fileName) {
    char *jsonFileData;
    size_t jsonFileSize;
    FILE *jsonFile;

    jsonFile = fopen(fileName, "rb");

    if (jsonFile == NULL) {
        perror(fileName);
        exit(EXIT_FAILURE);
    }

    jsonFileSize = getFileSize(jsonFile);
    jsonFileData = malloc(jsonFileSize);
    if (jsonFileData == NULL) {
        perror("Can't alloc memory for FORM0 JSON file!");
        fclose(jsonFile);
        exit(EXIT_FAILURE);
    }

    fread(jsonFileData, jsonFileSize, 1, jsonFile);

    Root = cJSON_Parse(jsonFileData);
    if (Root == NULL) {
        fclose(jsonFile);
        free(jsonFileData);
        log_info("Invalid JSON file");
        exit(EXIT_FAILURE);
    }

    fclose(jsonFile);
    free(jsonFileData);
}

void doUvmoEntries(const int count, cJSON *files) {
    cJSON *file;
    Form0Entry *entry = &Form0TableEntries[0];
    entry->tag = 'UVMO';
    entry->count = count;
    TotalEntriesSize += count * sizeof(int32_t);
    log_info("Entries size for UVMO: 0x%X\n", count * sizeof(int32_t));
    int i = 0;
    entry->offsets = malloc(sizeof(int) * count);
    assert(entry->offsets != NULL);

    cJSON_ArrayForEach(file, files) {
        char filePath[500];
        const char *name = cJSON_GetObjectItem(file, "name")->valuestring;
        cJSON *isNullEntry = cJSON_GetObjectItem(file, "nullEntry");
        snprintf(filePath, 500, "build/partial_%s.o", name);
        assert(name != NULL);
        assert(cJSON_IsBool(isNullEntry));

        if (cJSON_IsTrue(isNullEntry)) {
            log_info("Null entry in UVMO!");
            entry->offsets[i++] = -1;
            continue;
        }

        // Relative offset for ai should be zero
        if (i == 0) {
            entry->offsets[i++] = 0;
            // Even though compute the UVMO size, to use it for the next entry..
            CurrentRelativeOffset += computeUvmoSize(filePath);
            continue;
        }

        entry->offsets[i] = CurrentRelativeOffset;
        CurrentRelativeOffset += computeUvmoSize(filePath);
        i++;
    }
}

void doNonModableEntry(const char *category, const int count, cJSON *files, int pos) {
    cJSON *file;
    Form0Entry *entry = &Form0TableEntries[pos];
    TotalEntriesSize += count * sizeof(int32_t);
    int i = 0;
    entry->count = count;
    entry->tag = stringToTag(category);
    entry->offsets = malloc(sizeof(int) * count);
    log_info("Entries size 0x%X in %s\n", count * sizeof(int32_t), category);
    assert(entry->offsets != NULL);

    cJSON_ArrayForEach(file, files) {
        char filePath[500];
        const char *name = cJSON_GetObjectItem(file, "name")->valuestring;
        assert(name != NULL);
        cJSON *isNullEntry = cJSON_GetObjectItem(file, "nullEntry");
        // We haven't parsed the other form files format, so for now they are just no more than simple
        // binaries
        snprintf(filePath, 500, "bin/us/%s.bin", name);
        assert(name != NULL);
        assert(cJSON_IsBool(isNullEntry));

        if (cJSON_IsTrue(isNullEntry)) {
            log_info("Null entry: %s in %s!", name, category);
            entry->offsets[i++] = -1;
            continue;
        }

        FILE *categoryFile = fopen(filePath, "rb");
        if (categoryFile == NULL) {
            perror(filePath);
            entry->offsets[i] = -1;
        } else {
            entry->offsets[i] = CurrentRelativeOffset;
            CurrentRelativeOffset += getFileSize(categoryFile);

            if (strcmp(category, "UVTS") == 0 && i + 1 >= count) {
                RomEndRelativeOffset = CurrentRelativeOffset;
                log_info("ROM_END: %s size: %x\n", name, 0x25FD0 + RomEndRelativeOffset);
            }
            fclose(categoryFile);
        }
        i++;
    }
}

void parseFormFile(const char *category, const int count, cJSON *files, int pos) {
    assert(category != NULL && count > 0 && files != NULL);

    // Parse UVMO differently
    if (strcmp(category, "UVMO") == 0) {
        doUvmoEntries(count, files);
        return;
    }

    log_info("WARNING: Category %s is not moddable yet", category);
    doNonModableEntry(category, count, files, pos);
}

CategoryInfo *searchCategory(const char *category) {
    CategoryInfo *info = malloc(sizeof(CategoryInfo));

    info->count = 0;
    info->files = NULL;

    cJSON *formFiles = cJSON_GetObjectItem(Root, "FormFiles");
    cJSON *formFile;
    bool found = false;
    cJSON_ArrayForEach(formFile, formFiles) {
        assert(cJSON_IsString(cJSON_GetObjectItem(formFile, "category")));
        if (strcmp(cJSON_GetObjectItem(formFile, "category")->valuestring, category) == 0) {
            info->count = cJSON_GetObjectItem(formFile, "count")->valueint;
            info->files = cJSON_GetObjectItem(formFile, "files");
            found = true;
            break;
        }
    }

    if (!found) {
        log_info("Category not found: %s", category);
        return NULL;
    }

    return info;
}

void parseForm0Json(void) {
    cJSON *formFiles = cJSON_GetObjectItem(Root, "FormFiles"); 
    cJSON *formFile;

    CategoryInfo *info = searchCategory("UVMO");
    assert(info != NULL);
    parseFormFile("UVMO", info->count, info->files, 0);
    free(info);

    int pos = 1;
    for (int i = 0; i < ARRAY_COUNT(TagOrder); i++, pos++) {
        const char *category = TagOrder[i];
        info = searchCategory(TagOrder[i]);
        assert(info != NULL);
        parseFormFile(category, info->count, info->files, pos);
        free(info);
    }
}

void writeForm0(void) {
    Form0Header header;
    header.formTag = __builtin_bswap32('FORM');

    int uvftTagSize = sizeof(int32_t);
    int form0Size = TotalEntriesSize + uvftTagSize + (8 * 18);

    header.form0Size = __builtin_bswap32(form0Size);
    header.uvftTag = __builtin_bswap32('UVFT');

    FILE *form0 = fopen("build/FORM0.generated.uvft", "wb");
    if (form0 == NULL) {
        perror("FATAL: Can't write the FORM0 table!");
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(header), 1, form0);

    int byteswapTemp;
    // First get the size of all entries
    for (int i = 0; i < FORM_TAGS; i++) {
        if (Form0TableEntries[i].tag == 0) {
            log_info("Tag empty not converting more");
            break;
        }
        log_info("Writing entries for form %s", tagToString(Form0TableEntries[i].tag));

        byteswapTemp = __builtin_bswap32(Form0TableEntries[i].tag);
        fwrite(&byteswapTemp, sizeof(byteswapTemp), 1, form0);

        int size = Form0TableEntries[i].count * sizeof(int32_t);
        byteswapTemp = __builtin_bswap32(size);
        fwrite(&byteswapTemp, sizeof(byteswapTemp), 1, form0);

        // We have to do this manually because of the byteswap memes
        for (int j = 0; j < Form0TableEntries[i].count; j++) {
            byteswapTemp = __builtin_bswap32(Form0TableEntries[i].offsets[j]);
            fwrite(&byteswapTemp, sizeof(byteswapTemp), 1, form0);
        }
    }

    form0Size += 0x8; // Now include the first 0x8 bytes of FORM0

    if (!IS_ALIGNED_16(form0Size)) {
        int alignedForm0Size = ALIGN16(form0Size);
        int32_t padding = (alignedForm0Size - form0Size) / 4;

        for (int i = 0; i < padding; i++) {
            int word = 0;
            fwrite(&word, sizeof(word), 1, form0);
        }

        GeneratedForm0Size = alignedForm0Size;
    } else {
        GeneratedForm0Size = form0Size;
    }

    fclose(form0);
}

void writeForm0Vars(void) {
    char* form0VarsPath = "linker_scripts/us/form0_vars.txt";
    FILE* fp = fopen(form0VarsPath, "w");
    if (fp == NULL) {
        perror(form0VarsPath);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "RELATIVE_ROM_END = 0x%X\n", RomEndRelativeOffset);
    fprintf(fp, "FORM0_SIZE = 0x%X\n", GeneratedForm0Size);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        log_info("genForm0 form0.json");
        exit(EXIT_FAILURE);
    }
    initEntries();
    readForm0Json(argv[1]);
    parseForm0Json();
    writeForm0();
    writeForm0Vars();
}
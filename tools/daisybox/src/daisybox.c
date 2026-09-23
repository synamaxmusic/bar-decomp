#define STB_LOG
#define STB_VECTOR
#include "global.h"
#include "manager_types.h"
#include "symtab.h"
#include "reloc_sorts.h"
#include "load_reloc_sorts.h"
#include "load_map_symbols.h"
#include "module_types.h"
#include "utils.h"

#define IS_ALIGNED_8(ptr) (((uintptr_t) (ptr) & 0x7) == 0)
#define ALIGN8(x) (8 - (x & 7)) & 7
#define MODULE_FILES_CODE_BYTES_START 0x50
#define WORD_PAD_SIZE sizeof(int32_t)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

typedef struct RelocSortInfo_s {
    RelocTableEntry *reloc;
    int order; // Reloc order
} RelocSortInfo;

extern BarModuleFilesInfo BarModuleFiles[BAR_MODULE_FILES_COUNT];

static int RelocCount = 0;
static int *RelocEncodedWordsPtr = NULL;

static void growRelocs(int newReloc, bool incrementCount) {
    int newCount = RelocCount + 1;

    int *tmp = realloc(RelocEncodedWordsPtr, newCount * sizeof(*RelocEncodedWordsPtr));
    if (tmp == NULL) {
        perror("realloc failed");
        abort();
    }

    RelocEncodedWordsPtr = tmp;
    RelocEncodedWordsPtr[RelocCount] = newReloc;
    if (incrementCount) {

        RelocCount = newCount;
    }
}

static int cmp_info(const void *a, const void *b) {
    const RelocSortInfo *ia = a;
    const RelocSortInfo *ib = b;
    return ia->order - ib->order;
}

static int getMaxOrder(RelocSortInfo *info, int relCount) {
    int max = 0;
    for (int i = 0; i < relCount; i++) {
        max = MAX(i, info[i].order);
    }
    return max;
}

static void sortTextRelocs(vc_vector *localRelocs) {
    size_t relCount = vc_vector_count(localRelocs);
    log_info("sortTextRelocs vector count: %x\n", relCount);
    RelocSortInfo *info = malloc(relCount * sizeof(RelocSortInfo));

    if (info == NULL) {
        log_fatal("Can't alocate memory for reloc ordering!");
        perror("");
        abort();
    }

    int j = 0;
    // Copy relocations from localRelocs into *info*
    vc_vector *localRelocsCopy = vc_vector_create_copy(localRelocs);
    vc_vector_clear(localRelocs);
    for (void *i = vc_vector_begin(localRelocsCopy); i != vc_vector_end(localRelocsCopy);
         i = vc_vector_next(localRelocsCopy, i)) {
        RelocTableEntry *localReloc = i;
        info[j].reloc = i;
        info[j].order = RelocSort_GetRelocOrder(localReloc->offset);
        j++;
    }

    // Some relocations can have an unexpected order, put those at the end..
    for (size_t i = 0; i < relCount; i++) {
        if (info[i].order == -1) {
            info[i].order = getMaxOrder(info, relCount) + 1;
        }
    }

    // Sort relocations
    qsort(info, relCount, sizeof(RelocSortInfo), cmp_info);

    for (size_t i = 0; i < relCount; i++) {
#if DEBUG_MODULE_RELOCS
        log_info("Reloc type: %d Order: %d", info[i].reloc->relocType, info[i].order);
#endif
        vc_vector_push_back(localRelocs, info[i].reloc);
    }
    vc_vector_release(localRelocsCopy);
    free(info);
}

static void setCommEntryPointOffset(ModuleCommInfo *info) {
    vc_vector *relocTable = ElfParse_GetRelocTable();
    int32_t minFunctionSymValue = 0;
    Symbol *entrypointSymbol = NULL;

    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *relocEntry = i;
        Symbol *sym = &relocEntry->symbol;

        if (sym->name == NULL) {
            log_info("No symbol name!");
            continue;
        }

        if (sym->section == SHN_UNDEF) {
            continue;
        }

        if (strcmp(sym->sectionName, ".text") != 0) {
            continue;
        }

        if (sym->type != STT_FUNC) {
            continue;
        }

        if (strncmp(sym->name, "__entrypoint_func", 17) == 0) {
            entrypointSymbol = &relocEntry->symbol;
            break;
        }

        minFunctionSymValue = MIN(minFunctionSymValue, sym->value);
    }

    assert(entrypointSymbol != NULL);
    long int entrySymbolFunctionOffset = entrypointSymbol->value - minFunctionSymValue;
    log_info("Entrypoint offset: %x\n", entrySymbolFunctionOffset);
    info->entryPointOffset = entrySymbolFunctionOffset;
}

int encodeMips32Relocs(char *secName) {
    vc_vector *relocTable = ElfParse_GetRelocTable();
    int relaSize = 0;

    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *reloc = i;
        Symbol *sym = &reloc->symbol;

        if (strcmp(reloc->targetSection, secName) != 0) {
            continue;
        }

        int type = Utils_ConvertRelocType(reloc->relocType);
        if (type < 0) {
            continue;
        }

        uint32_t word = Utils_EncodeReloc(Utils_EncodeSymbolSection(sym->sectionName),
                                          Utils_EncodeInstructionSection(reloc->targetSection), type,
                                          reloc->offset);
        // log_info("Encoded word: %x", word);
        growRelocs(__builtin_bswap32(word), true);
        relaSize += 4;
    }
    return relaSize;
}

static int computeRela(void) {
    int relaSize = 0;

    vc_vector *relocTable = ElfParse_GetRelocTable();
    vc_vector *localRelocs = vc_vector_create(0, sizeof(RelocTableEntry), NULL);

    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *rel = i;
        Symbol *sym = &rel->symbol;

        if (strcmp(rel->targetSection, ".text") != 0) {
            continue;
        }

        if (sym->section == SHN_UNDEF) {
            continue;
        }

        vc_vector_push_back(localRelocs, rel);
    }

    sortTextRelocs(localRelocs);

    for (void *i = vc_vector_begin(localRelocs); i != vc_vector_end(localRelocs);
         i = vc_vector_next(localRelocs, i)) {
        RelocTableEntry *rel = i;
        Symbol *sym = &rel->symbol;
        int type = Utils_ConvertRelocType(rel->relocType);
        if (type < 0) {
            continue;
        }

        uint32_t word =
            Utils_EncodeReloc(Utils_EncodeSymbolSection(sym->sectionName),
                              Utils_EncodeInstructionSection(rel->targetSection), type, rel->offset);

        log_info("Encoded word: %x", word);
        growRelocs(__builtin_bswap32(word), true);
        relaSize += 4;
    }

    // TODO: Try to reduce this to a single call
    vc_vector_release(localRelocs);
    relaSize += encodeMips32Relocs(".data");
    relaSize += encodeMips32Relocs(".rodata");
    return relaSize;
}

static void setCommSectionsSizes(ModuleCommInfo *info) {
    vc_vector *sections = ElfParse_GetSections();
    for (void *i = vc_vector_begin(sections); i != vc_vector_end(sections);
         i = vc_vector_next(sections, i)) {
        Section *sec = i;
        const char *name = (const char *) sec->name;
        int32_t size = sec->size;

        if (strcmp(name, ".text") == 0) {
            info->textSize = size;
        } else if (strcmp(name, ".data") == 0) {
            info->dataSize = size;
        } else if (strcmp(name, ".rodata") == 0) {
            info->rodataSize = size;
        } else if (strcmp(name, ".bss") == 0) {
            info->bssSize = size;
        }
    }
}

static void resolveKernelRelocs(void) {
    vc_vector *hi16Queue = vc_vector_create(0, sizeof(MipsHi16), NULL);
    vc_vector *relocTable = ElfParse_GetRelocTable();
    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *rel = i;
        Symbol *sym = &rel->symbol;

        int type = Utils_ConvertRelocType(rel->relocType);
        if (type < 0) {
            continue;
        }

        if (strcmp(rel->targetSection, ".text") != 0) {
            log_info("Skiping %s rel", rel->targetSection);
            continue;
        }

        if (sym->section != SHN_UNDEF) {
            continue;
        }

        uint32_t symAddr = Symtab_ResolveSymbol(sym->name);
        if (symAddr == (uint32_t) -1) {
            log_error("Couldn't resolve sym: %s\n", sym->name);
            abort();
        }

        if (rel->relocType == R_MIPS_26) {
            Section *textSection = ElfParse_GetSection(".text");
            uint8_t *loc = textSection->data->d_buf + rel->offset;
            assert(rel->addend == 0);
            Reloc_DoMips26Reloc((void *) loc, (void *) loc, symAddr);
            continue;
        }

        // Handle hiLo relocs
        Section *textSection = ElfParse_GetSection(".text");
        uint8_t *loc = textSection->data->d_buf + rel->offset;
        Reloc_DoMipsHiLoRelocs(hi16Queue, rel->relocType, loc, symAddr, rel->addend);
    }
    vc_vector_release(hi16Queue);
}

static void resolveModuleRelocs(void) {
    vc_vector *hi16Queue = vc_vector_create(0, sizeof(MipsHi16), NULL);
    vc_vector *relocTable = ElfParse_GetRelocTable();
    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *rel = i;
        Symbol *sym = &rel->symbol;
        if (sym->section == SHN_UNDEF && Symtab_ResolveSymbol(sym->name) == -1) {
            log_error("ERROR: Undefined reference: %s", sym->name);
            abort();
        }

        if (rel->relocType == R_MIPS_32 && rel->relocType == R_MIPS_PC16) {
            continue;
        }

        if (rel->relocType == R_MIPS_26) {
            Section *textSection = ElfParse_GetSection(".text");
            uint8_t *loc = textSection->data->d_buf + rel->offset;
            assert(rel->addend == 0);
            Reloc_DoMips26Reloc((void *) loc, (void *) loc, sym->value);
            continue;
        }

        // Handle hiLo relocs
        Section *textSection = ElfParse_GetSection(".text");
        uint8_t *loc = textSection->data->d_buf + rel->offset;
        Reloc_DoMipsHiLoRelocs(hi16Queue, rel->relocType, loc, sym->value, rel->addend);
    }
    vc_vector_release(hi16Queue);
}

static void resolveMips32Relocs(void) {
    vc_vector *relocTable = ElfParse_GetRelocTable();
    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *rel = i;

        if (rel->relocType != R_MIPS_32) {
            continue;
        }

        Section *section = ElfParse_GetSection(rel->targetSection);
        Reloc_DoMips32Reloc(section, rel);
    }
}

static void resolvePc16Relocs(void) {
    Section *text = ElfParse_GetSection(".text");
    vc_vector *relocTable = ElfParse_GetRelocTable();
    for (void *i = vc_vector_begin(relocTable); i != vc_vector_end(relocTable);
         i = vc_vector_next(relocTable, i)) {
        RelocTableEntry *rel = i;
        Symbol *sym = &rel->symbol;

        if (rel->relocType != R_MIPS_PC16) {
            continue;
        }

        uint8_t *location = text->data->d_buf + rel->offset;
        Reloc_DoMipsPc16Reloc(location, rel->offset, sym->value, rel->addend);
    }
}

static void writeCommHeader(FILE *outputFile, char *moduleName) {
    assert(moduleName != NULL);
    bool foundModuleName = false;
    ModuleHardcodedInfo info = { 0 };
    ModuleFileHeader header = { 0 };
    CodeInfo codeInfo = { 0 };

    for (int i = 0; i < BAR_MODULE_FILES_COUNT; i++) {
        if (strcmp(moduleName, BarModuleFiles[i].moduleName) == 0) {
            foundModuleName = true;
            info = BarModuleFiles[i].info;
            break;
        }
    }

    assert(foundModuleName);

    // Initial comm heeader info
    header.formTag = 'FORM';
    header.moduTag = 'MODU';
    header.padTag = 'PAD ';
    header.commInfo.nameTag = __builtin_bswap32(Utils_StringToTag(moduleName));
    header.padSize = sizeof(int);
    header.padContents = 0; // Just padding
    header.commTag = 'COMM';
    header.commSize = 0x28;
    header.commInfo.headerSize = info.headeredSize;
    header.commInfo.relaContents = info.relocVal;

    setCommEntryPointOffset(&header.commInfo);
    setCommSectionsSizes(&header.commInfo);

    int32_t commPad = 0;
    int sectionsSize = header.commInfo.textSize + header.commInfo.dataSize + header.commInfo.rodataSize;
    int firstSize = sizeof(ModuleFileHeader) - 0x8; // don't count the first eight bytes
    int mdbgInfoSize = sizeof(ModuleFileMdbgInfo) + WORD_PAD_SIZE;
    int relaInfoSize = sizeof(RelaInfo);
    int relaSize = computeRela();
    header.commInfo.relocCount = RelocCount;
    // TODO: Organize this mess
    header.fileSize =
        firstSize + sizeof(CodeInfo) + relaInfoSize + sectionsSize + mdbgInfoSize + relaSize;

    // swap module file header
    int *ptr = (int *) &header;
    for (size_t i = 0; i < sizeof(ModuleFileHeader); i += 4) {
        *ptr++ = __builtin_bswap32(*ptr);
    }

    printf("Sections size: %x\n", sectionsSize);
    printf("RELA size: %x\n", relaSize);
    codeInfo.codeTag = __builtin_bswap32('CODE');
    codeInfo.codeSize = __builtin_bswap32(sectionsSize);

    fwrite(&header, sizeof(ModuleFileHeader), 1, outputFile);
    fwrite(&commPad, sizeof(int32_t), 1, outputFile);
    fwrite(&codeInfo, sizeof(CodeInfo), 1, outputFile);
}

static void writeCodeBlock(FILE *outFile) {
    Section *text = ElfParse_GetSection(".text");
    Section *rodata = ElfParse_GetSection(".rodata");
    Section *data = ElfParse_GetSection(".data");

    // Code starts at 0x50
    fseek(outFile, MODULE_FILES_CODE_BYTES_START, SEEK_SET);

    if (text != NULL) {
        // Before writting the text section we must resolve those undefined LO16/HI16 refs
        resolveKernelRelocs(); // Resolve kernel symbols
        resolveModuleRelocs();
        resolvePc16Relocs();
        fwrite(text->data->d_buf, text->data->d_size, 1, outFile);
    }

    if (data != NULL || rodata != NULL) {
        resolveMips32Relocs();
    }

    // Write the sections into the module file
    if (rodata != NULL) {
        fwrite(rodata->data->d_buf, rodata->data->d_size, 1, outFile);
    }

    if (data != NULL) {
        fwrite(data->data->d_buf, data->data->d_size, 1, outFile);
    }
}

static void writeMdbg(char *debugInfo, FILE *outFile) {
    ModuleFileMdbgInfo info = { 0 };

    size_t len = strlen(debugInfo);
    if (len >= sizeof(info.mdbgInfo)) {
        len = sizeof(info.mdbgInfo) - 1;
    }

    info.mdbgTag = __builtin_bswap32('MDBG');
    info.mdbgSize = __builtin_bswap32(sizeof(info.mdbgInfo));
    memcpy(info.mdbgInfo, debugInfo, len);
    fwrite(&info, sizeof(info), 1, outFile);
}

static void writeRela(FILE *outFile) {
    int relaSize = RelocCount * sizeof(int);
    ModuleFileHeader fileHeader;
    RelaInfo info;

    info.relaTag = __builtin_bswap32('RELA');
    info.relaSize = __builtin_bswap32(relaSize);

    long relaHeaderPos = ftell(outFile);

    fwrite(&info, sizeof(info), 1, outFile);
    fwrite(RelocEncodedWordsPtr, relaSize, 1, outFile);

    long eof = ftell(outFile);

    int pad = ALIGN8(eof);
    if (!IS_ALIGNED_8(eof)) {
        /* read header */
        fseek(outFile, 0, SEEK_SET);
        fread(&fileHeader, sizeof(fileHeader), 1, outFile);

        uint32_t size = __builtin_bswap32(fileHeader.fileSize);
        size += pad;
        fileHeader.fileSize = __builtin_bswap32(size);

        uint32_t relaSize = __builtin_bswap32(info.relaSize);
        relaSize += pad;
        info.relaSize = __builtin_bswap32(relaSize);

        /* Rewrite rela header */
        fseek(outFile, relaHeaderPos, SEEK_SET);
        fwrite(&info, sizeof(info), 1, outFile);

        /* Rewrite file header */
        fseek(outFile, 0, SEEK_SET);
        fwrite(&fileHeader, sizeof(fileHeader), 1, outFile);

        fseek(outFile, eof, SEEK_SET);

        for (int i = 0; i < pad; i++) {
            fputc(0, outFile);
        }
    }
}

int main(int argc, char *argv[]) {
    char maxFileName[200];
    if (argc < 6) {
        log_info("daisybox {input} {moduleName} {mapFile.json} {relocSorts} {debugInfo} -> "
                 "{input}.uvmo.bin");
        exit(EXIT_FAILURE);
    }

    char *inputFileName = argv[1];
    ElfParse_Init(inputFileName);

    snprintf(maxFileName, 200, "%s.generated.uvmo", inputFileName);
    FILE *outFile = fopen(maxFileName, "w+");
    if (outFile == NULL) {
        perror("Can't open output file!");
        exit(EXIT_FAILURE);
    }

    log_info("Converting: %s", argv[1]);
    log_info("Loading symbols from map file");
    MapSymbols_Init(argv[3]);
    MapSymbols_Load();
    LoadRelocOrder(argv[4]);

    log_info("Writing comm header");
    writeCommHeader(outFile, argv[2]);
    log_info("- Done");
    log_info("Writing CODE block");
    writeCodeBlock(outFile);
    log_info("- Done");
    log_info("Writing MDBG");
    writeMdbg(argv[5], outFile);
    log_info("- Done");
    log_info("Writing RELA");
    writeRela(outFile);
    log_info("- Done");

    ElfParse_Destroy();
}
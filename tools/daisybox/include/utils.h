#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
#include <stdbool.h>
#include "module_types.h"

//void Utils_Fwrite()
size_t Utils_GetFileSize(FILE *fp);
bool Utils_CompareFileHash(FILE *file1, char* hash) ;
void Utils_TrimPath(const char *path, char *out);
int Utils_EncodeInstructionSection(char *secName);
int Utils_EncodeSymbolSection(char *secName);
uint32_t Utils_EncodeReloc(uint32_t symbolSection, uint32_t targetSection, uint32_t relocType,
                            int32_t addend);
int Utils_ConvertRelocType(int relocType);
int Utils_StringToTag(char *tagStr);
uint16_t Utils_ReadBe16(const uint8_t *p);
uint32_t Utils_ReadBe32(const uint8_t *p);
void Utils_WriteBe16(uint8_t *p, uint16_t value);
void Utils_WriteBe32(uint8_t *p, uint32_t value);
#endif // UTILS_H

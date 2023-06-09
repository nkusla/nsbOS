#ifndef LIB_H
#define LIB_H

#include <stdint.h>
#include <stdarg.h>

void __attribute__((cdecl)) write(uint8_t* str, uint32_t size);
uint32_t __attribute__((cdecl)) read(uint8_t* str, uint32_t size);

int32_t atoi(uint8_t* str);
void itoa(int32_t value, uint8_t* str);
void strcpy(uint8_t* dst, uint8_t* src);
uint32_t strlen(uint8_t* str);
uint32_t strcmp(uint8_t* str1, uint8_t* str2);

void printf(uint8_t* str, ...);
void scanf(uint8_t* str, ...);

#endif

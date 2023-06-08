#ifndef LIB_H
#define LIB_H

#include <stdint.h>
#include <stdarg.h>

void __attribute__((cdecl)) write(uint8_t* str, uint32_t size);
void __attribute__((cdecl)) read(uint8_t* str, uint32_t size, uint8_t* enter_pressed);

int32_t atoi(uint8_t* str, uint32_t base);
void itoa(int32_t value, uint8_t* str, uint8_t base);
void strcpy(uint8_t* dst, uint8_t* src);
uint32_t strlen(uint8_t* str);
uint32_t strcmp(uint8_t* str1, uint8_t* str2);

void printf(uint8_t* str, ...);
void scanf(uint8_t* str, ...);

#endif

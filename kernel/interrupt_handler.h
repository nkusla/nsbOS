#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

#include <stdint.h>

extern uint8_t* exception_messages[];

typedef struct {
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_num, error_code;
	uint32_t eip, cs, eflags;
} __attribute__((packed)) interrupt_frame_t;

void __attribute__((cdecl)) interrupt_generic_handler(interrupt_frame_t frame);

#endif
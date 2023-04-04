#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

#include <stdint.h>
#include "../drivers/video.h"
#include "../drivers/keyboard.h"

#define IRQ0 32
#define IRQ1 33

typedef struct {
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_num, error_code;
	uint32_t eip, cs, eflags;
} __attribute__((packed)) interrupt_frame_t;

typedef void (*interrupt_handler_t)();

extern uint8_t* exception_messages[];

void __attribute__((cdecl)) isr_generic_handler(interrupt_frame_t frame);
void __attribute__((cdecl)) irq_generic_handler(interrupt_frame_t frame);
void __attribute__((cdecl)) interrupt_handlers_setup();

#endif
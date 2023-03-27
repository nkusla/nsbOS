#ifndef IDT_H
#define IDT_H
#include <stdint.h>

#define IDT_NUM_GATES 256

typedef struct {
	uint16_t low_offset;
	uint16_t selector;
	uint8_t zero_byte;
	uint8_t flags;
	uint16_t high_offset;
} __attribute__((packed)) idt_gate_t;

void register_idt_gate(uint8_t index, uint32_t handler);

#endif
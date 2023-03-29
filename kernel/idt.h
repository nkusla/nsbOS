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

typedef struct {
	uint16_t size;
	uint32_t offset;
} __attribute__((packed)) idt_descriptor_t;

void idt_gate_load(uint8_t index, uint32_t handler);
void idt_load();
void idt_setup();

#endif
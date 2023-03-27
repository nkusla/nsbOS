#include "idt.h"

idt_gate_t idt[IDT_NUM_GATES];

void register_idt_gate(uint8_t index, uint32_t handler_addr) {
	idt[index].low_offset = (uint16_t)(handler_addr & 0xffff);
	idt[index].zero_byte = 0;
	idt[index].flags = 0x8e;
	idt[index].high_offset = (uint16_t)(handler_addr >> 16);
}
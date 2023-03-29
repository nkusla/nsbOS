#include "idt.h"

idt_gate_t idt[IDT_NUM_GATES];

idt_descriptor_t idt_descriptor;

void idt_gate_load(uint8_t index, uint32_t handler_addr) {
	idt[index].low_offset = (uint16_t)(handler_addr & 0xffff);
	idt[index].zero_byte = 0;
	idt[index].flags = 0x8e;
	idt[index].high_offset = (uint16_t)(handler_addr >> 16);
}

void idt_load() {
	idt_descriptor.offset = (uint32_t) &idt;
	idt_descriptor.size = IDT_NUM_GATES * sizeof(idt_gate_t) - 1;
	__asm__ __volatile__ ("lidt (%0)" : : "r" (&idt_descriptor));
}

void idt_setup() {

}
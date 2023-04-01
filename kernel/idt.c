#include "idt.h"

idt_gate_t idt[IDT_NUM_GATES] = {0xf};

idt_descriptor_t idt_descriptor = {0xf};

void idt_gate_load(uint8_t index, uint32_t* handler_addr) {
	uint32_t addr = (uint32_t) handler_addr;
	idt[index].low_offset = (uint16_t)(addr & 0xffff);
	idt[index].selector = 0x08;
	idt[index].zero_byte = 0;
	idt[index].flags = 0x8e;
	idt[index].high_offset = (uint16_t)(addr >> 16);
}

void idt_load() {
	idt_descriptor.offset = (uint32_t) &idt;
	idt_descriptor.size = IDT_NUM_GATES * sizeof(idt_gate_t) - 1;
	__asm__ __volatile__ ("lidt (%0)" : : "r" (&idt_descriptor));
}

void idt_setup() {
	// Registering first 32 reserved interrupts
	idt_gate_load(0, &isr0);
	idt_gate_load(1, &isr1);
	idt_gate_load(2, &isr2);
	idt_gate_load(3, &isr3);
	idt_gate_load(4, &isr4);
	idt_gate_load(5, &isr5);
	idt_gate_load(6, &isr6);
	idt_gate_load(7, &isr7);
	idt_gate_load(8, &isr8);
	idt_gate_load(9, &isr9);
	idt_gate_load(10, &isr10);
	idt_gate_load(11, &isr11);
	idt_gate_load(12, &isr12);
	idt_gate_load(13, &isr13);
	idt_gate_load(14, &isr14);
	idt_gate_load(15, &isr15);
	idt_gate_load(16, &isr16);
	idt_gate_load(17, &isr17);
	idt_gate_load(18, &isr18);
	idt_gate_load(19, &isr19);
	idt_gate_load(20, &isr20);
	idt_gate_load(21, &isr21);
	idt_gate_load(22, &isr22);
	idt_gate_load(23, &isr23);
	idt_gate_load(24, &isr24);
	idt_gate_load(25, &isr25);
	idt_gate_load(26, &isr26);
	idt_gate_load(27, &isr27);
	idt_gate_load(28, &isr28);
	idt_gate_load(29, &isr29);
	idt_gate_load(30, &isr30);
	idt_gate_load(31, &isr31);

	idt_load();

	__asm__ __volatile__ ("sti");
}
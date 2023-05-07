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
	// Loading fisrt 32 internal interrupt routines (ISR)
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

	// Remmaping Programmable Interrupt Controller (PIC)
	port_byte_out(PRIMARY_PIC_COMMAND_PORT, ICW1_INIT);
	port_byte_out(SECONDARY_PIC_COMMAND_PORT, ICW1_INIT);

	port_byte_out(PRIMARY_PIC_DATA_PORT, ICW2_OFFSET_32);
	port_byte_out(SECONDARY_PIC_DATA_PORT, ICW2_OFFSET_40);

	port_byte_out(PRIMARY_PIC_DATA_PORT, ICW3_IRQ2);
	port_byte_out(SECONDARY_PIC_DATA_PORT, ICW3_SECONDARY);

	port_byte_out(PRIMARY_PIC_DATA_PORT, ICW4_8086_MODE);
	port_byte_out(SECONDARY_PIC_DATA_PORT, ICW4_8086_MODE);

	port_byte_out(PRIMARY_PIC_DATA_PORT, OCW1_ENABLE);
	port_byte_out(SECONDARY_PIC_DATA_PORT, OCW1_ENABLE);

	// Loading 15 interrupt request routines (IRQ)
	idt_gate_load(32, &irq0);
	idt_gate_load(33, &irq1);
	idt_gate_load(34, &irq2);
	idt_gate_load(35, &irq3);
	idt_gate_load(36, &irq4);
	idt_gate_load(37, &irq5);
	idt_gate_load(38, &irq6);
	idt_gate_load(39, &irq7);
	idt_gate_load(40, &irq8);
	idt_gate_load(41, &irq9);
	idt_gate_load(42, &irq10);
	idt_gate_load(43, &irq11);
	idt_gate_load(44, &irq12);
	idt_gate_load(45, &irq13);
	idt_gate_load(46, &irq14);
	idt_gate_load(47, &irq15);

	// Loading software interrupt routines
	idt_gate_load(128, &sir128);

	// Passing IDT descriptor to CPU
	idt_load();
}
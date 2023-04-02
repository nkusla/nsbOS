#ifndef IDT_H
#define IDT_H
#include <stdint.h>
#include "../drivers/io_ports.h"

#define IDT_NUM_GATES 256

// External visibility of Interrupt Service Routines
extern uint32_t isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7;
extern uint32_t isr8, isr9, isr10, isr11, isr12, isr13, isr14, isr15;
extern uint32_t isr16, isr17, isr18, isr19, isr20, isr21, isr22, isr23;
extern uint32_t isr24, isr25, isr26, isr27, isr28, isr29, isr30, isr31;

// External visibility of Interrupt Request Routines
extern uint32_t irq0, irq1, irq2, irq3, irq4, irq5, irq6, irq7;
extern uint32_t irq8, irq9, irq10, irq11, irq12, irq13, irq14, irq15;

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

void idt_gate_load(uint8_t index, uint32_t* handler_addr);
void idt_load();
void idt_setup();

#endif
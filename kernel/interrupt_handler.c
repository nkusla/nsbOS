#include "interrupt_handler.h"

uint8_t* exception_messages[] = {
	"Division By Zero",
	"Debug",
	"NMI",
	"Breakpoint",
	"Overflow",
	"Bound Range Exceeded",
	"Invalid Opcode",
	"Device Not Available",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Invalid TSS",
	"Segment Not Present",
	"Stack-Segment Fault",
	"General Protection Fault",
	"Page Fault",
	"Reserved",
	"x87 Floating Point Exception",
	"Alignment Check",
	"Machine Check",
	"SIMD Floating-Point Exception",
	"Virtualization Exception",
	"Control Protection Exception",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Hypervisor Injection Exception",
	"VMM Communication Exception",
	"Security Exception",
	"Reserved"
};

void __attribute__((cdecl)) isr_generic_handler(interrupt_frame_t frame) {
	print_string(exception_messages[frame.int_num], LIGHT_RED);
}

void __attribute__((cdecl)) irq_generic_handler(interrupt_frame_t frame) {
	port_byte_out(PRIMARY_PIC_COMMAND_PORT, PIC_EOI);
	if(frame.int_num < 40)
		port_byte_out(SECONDARY_PIC_COMMAND_PORT, PIC_EOI);
}

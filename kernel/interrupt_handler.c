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

interrupt_handler_t interrupt_handlers[256] = {0x0};

void __attribute__((cdecl)) isr_generic_handler(interrupt_frame_t frame) {
	print_string(exception_messages[frame.int_num], LIGHT_RED);
	print_string("\n", LIGHT_RED);
}

void __attribute__((cdecl)) irq_generic_handler(interrupt_frame_t frame) {
	interrupt_handlers[frame.int_num](frame);

	port_byte_out(PRIMARY_PIC_COMMAND_PORT, PIC_EOI);
	if(frame.int_num < 40)
		port_byte_out(SECONDARY_PIC_COMMAND_PORT, PIC_EOI);
}

void __attribute__((cdecl)) sys_call_handler(interrupt_frame_t frame) {
	uint8_t* str = (uint8_t*) frame.ecx;
	uint32_t size = frame.edx;
	uint32_t* ptr_read_size = (uint32_t*) frame.esi;
	uint32_t i = 0;

	if(frame.eax == 4) {
		print_string(str, WHITE);
	}
	else if(frame.eax == 3) {
		if(enter_pressed) {
			while(keyboard_buffer[i] != '\n' && i <= size) {
				str[i] = keyboard_buffer[i];
				i++;
			}
			*ptr_read_size = i;
			enter_pressed = 0;
			return;
		}
		*ptr_read_size = 0;
	}
	else {}
}

void __attribute__((cdecl)) system_clock_handler(interrupt_frame_t frame) {}

void __attribute__((cdecl)) interrupt_handlers_setup() {
	for(int i = 0; i <= 31; ++i)
		interrupt_handlers[i] = isr_generic_handler;

	interrupt_handlers[IRQ0] = system_clock_handler;
	interrupt_handlers[IRQ1] = keyboard_scancode_read;
	interrupt_handlers[128] = sys_call_handler;
}

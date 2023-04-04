#include "../drivers/video.h"
#include "idt.h"
#include "interrupt_handler.h"


void main() {
	clear_screen();
	print_string("Kernel started\n", LIGHT_GREEN);

	idt_setup();
	__asm__ __volatile__ ("sti");
	print_string("Interrupt descriptor table initiated\n", LIGHT_CYAN);

	interrupt_handlers_setup();
	print_string("Interrupt handlers initiated\n", LIGHT_CYAN);

	print_string("\n-> ", LIGHT_GREEN);
}
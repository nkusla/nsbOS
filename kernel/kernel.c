#include "../drivers/video.h"
#include "idt.h"
#include "interrupt_handler.h"


void main() {
	clear_screen();

	// Setting up Interrupt descriptor table and
	// array of interrupt handlers
	idt_setup();
	interrupt_handlers_setup();
	__asm__ __volatile__ ("sti");

	print_string("\n-> ", LIGHT_GREEN);

	// Calling shell program
	__asm__ __volatile__ ("call 0x9a00");
}
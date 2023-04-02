#include "../drivers/video.h"
#include "idt.h"
#include "interrupt_handler.h"

uint8_t str[] = "Kernel!";

void main() {
	clear_screen();
	print_string("Kernel started\n", LIGHT_GREEN);
	idt_setup();
	__asm__ __volatile__ ("sti");
	print_string("Interrupt descriptor table initiated\n", LIGHT_CYAN);
}
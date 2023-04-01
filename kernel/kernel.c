#include "../drivers/video.h"
#include "idt.h"
#include "interrupt_handler.h"

uint8_t str[] = "Kernel!";

void main() {
	clear_screen();
	print_string("Kernel");
}
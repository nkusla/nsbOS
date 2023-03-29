#include "../drivers/video.h"
#include "idt.h"
#include "interrupt_handler.h"

uint8_t str[] = "Kernel!";

void main() {
	clear_screen();
	for(int i = 0; i < 32; ++i)
		print_string(exception_messages[i]);
}
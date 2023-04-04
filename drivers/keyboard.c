#include "keyboard.h"

void keyboard_scancode_print(uint8_t scancode) {
	if(scancode == 0x1) {
		print_string("\nCPU halted!\n", LIGHT_RED);
		__asm__ __volatile__ ("hlt");
	}
	else if(scancode >= 0x2 && scancode < 0x0b) {
		print_int(scancode-1, WHITE);
	}
	else {

	}
}

uint8_t keyboard_scancode_read() {
	uint8_t scancode = port_byte_in(PS2_CONTROLLER_DATA_PORT);
	keyboard_scancode_print(scancode);
	return scancode;
}
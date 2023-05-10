#include "keyboard.h"

uint8_t scancode_to_char[] = {
	'?', '?', '1', '2', '3', '4', '5',
	'6', '7', '8', '9', '0', '-', '=',
	'?', '?', 'Q', 'W', 'E', 'R', 'T',
	'Y', 'U', 'I', 'O', 'P', '[', ']',
	'?', '?', 'A', 'S', 'D', 'F', 'G',
	'H', 'J', 'K', 'L', ';', '\'', '`',
	'?', '\\', 'Z', 'X', 'C', 'V', 'B',
	'N', 'M', ',', '.', '/', '?', '*',
	'?', ' ', '?', '?'
};

uint8_t keyboard_buffer[BUFFER_SIZE] = {0};
uint8_t input_finished = 0;
uint32_t buffer_index = 0;

void keyboard_scancode_print(uint8_t scancode) {
	if(scancode == ESC) {
		print_string("\nCPU halted!\n", LIGHT_RED);
		__asm__ __volatile__ ("hlt");
	}
	else if(scancode == ENTER) {
		print_string("\n-> ", LIGHT_GREEN);
		keyboard_buffer[buffer_index] = '\n';
		input_finished = 1;
		buffer_index = 0;
	}
	else if(scancode <= 0x3a && scancode_to_char[scancode] != '?') {
		print_char(scancode_to_char[scancode], WHITE);
	}
	else { }
}

uint8_t keyboard_scancode_read() {
	uint8_t scancode = port_byte_in(PS2_CONTROLLER_DATA_PORT);
	keyboard_buffer[buffer_index++] = scancode_to_char[scancode];
	keyboard_scancode_print(scancode);
	return scancode;
}
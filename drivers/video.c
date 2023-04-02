#include "video.h"

uint8_t set_color_byte(uint8_t foreground, uint8_t background) {
	return (background << 4) | foreground;
}

uint16_t new_line_offset(uint16_t offset) {
	uint16_t new_offset;
	new_offset = ( offset / VIDEO_WIDTH )*VIDEO_WIDTH + VIDEO_WIDTH;

	return new_offset;
}

uint16_t get_cursor_offset() {
	port_byte_out(VIDEO_CONTROL_PORT, VIDEO_CURSOR_OFFSET_LOW);
	uint16_t offset = (uint16_t) port_byte_in(VIDEO_DATA_PORT);

	port_byte_out(VIDEO_CONTROL_PORT, VIDEO_CURSOR_OFFSET_HIGH);
	offset += port_byte_in(VIDEO_DATA_PORT) << 8;
	return offset * 2;
}

void set_cursor_offset(uint16_t offset) {
	offset /= 2;

	port_byte_out(VIDEO_CONTROL_PORT, VIDEO_CURSOR_OFFSET_LOW);
	port_byte_out(VIDEO_DATA_PORT, (uint8_t)(offset & 0xff));

	port_byte_out(VIDEO_CONTROL_PORT, VIDEO_CURSOR_OFFSET_HIGH);
	port_byte_out(VIDEO_DATA_PORT, (uint8_t)(offset >> 8));
}

void clear_screen() {
	uint8_t* video_memory = (uint8_t*) VIDEO_MEMORY_ADDR;
	for(int i = 0; i < VIDEO_HEIGHT*VIDEO_WIDTH; i++)
		video_memory[i] = 0;
	set_cursor_offset(0);
}

void print_string(uint8_t* str, uint8_t foreground) {
	uint16_t cursor_offset = get_cursor_offset();
	uint8_t* video_memory = (uint8_t*) VIDEO_MEMORY_ADDR;
	uint8_t color = set_color_byte(foreground, BLACK);

	while(1) {
		while(*str == '\n') {
			cursor_offset = new_line_offset(cursor_offset);
			str++;
		}

		if(*str == '\0')
			break;

		video_memory[cursor_offset] = *str;
		video_memory[cursor_offset+1] = color;
		cursor_offset += 2;
		str++;
	}

	video_memory[cursor_offset] = ' ';
	video_memory[cursor_offset+1] = set_color_byte(WHITE, BLACK);;
	set_cursor_offset(cursor_offset);
}

void print_int(uint32_t num, uint8_t foreground) {
	uint8_t temp;
	uint8_t str[] = "\0\0\0\0\0\0\0\0\0";
	uint8_t i = 0, j = 0;

	while(num != 0) {
		temp = num % 10;
		str[i++] = temp + 48;
		num /= 10;
	}
	if(str[0] != 0) {
		str[i--] = 0;

		while(j < i) {
			temp = str[j];
			str[j] = str[i];
			str[i] = temp;
			++j; --i;
		}
	}
	else {
		str[0] = '0';
	}

	print_string(str, foreground);
}
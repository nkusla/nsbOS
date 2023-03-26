#include "video.h"

uint8_t set_color_byte(uint8_t foreground, uint8_t background) {
	return (background << 4) | foreground;
}

uint16_t get_cursor_offset() {
	port_byte_out(VIDEO_CONTROL_REG, VIDEO_CURSOR_OFFSET_LOW);
	uint16_t offset = (uint16_t) port_byte_in(VIDEO_DATA_REG);

	port_byte_out(VIDEO_CONTROL_REG, VIDEO_CURSOR_OFFSET_HIGH);
	offset += port_byte_in(VIDEO_DATA_REG) << 8;
	return offset * 2;
}

void set_cursor_offset(uint16_t offset) {
	offset /= 2;

	port_byte_out(VIDEO_CONTROL_REG, VIDEO_CURSOR_OFFSET_LOW);
	port_byte_out(VIDEO_DATA_REG, (uint8_t) (offset & 0xff));

	port_byte_out(VIDEO_CONTROL_REG, VIDEO_CURSOR_OFFSET_HIGH);
	port_byte_out(VIDEO_DATA_REG, (uint8_t) (offset >> 8));
}

void clear_screen() {
	uint8_t* video_memory = (uint8_t*) VIDEO_MEMORY_ADDR;
	for(int i = 0; i < VIDEO_HEIGHT*VIDEO_WIDTH; i++)
		video_memory[i] = 0;
	set_cursor_offset(0);
}

void print_string(uint8_t* str) {
	uint16_t cursor_offset = get_cursor_offset();
	uint8_t* video_memory = (uint8_t*) VIDEO_MEMORY_ADDR;
	uint8_t color = set_color_byte(LIGHT_GREEN, BLACK);

	while(*str != '\0') {
		video_memory[cursor_offset] = *str;
		video_memory[cursor_offset+1] = color;
		cursor_offset += 2;
		str++;
	}

	video_memory[cursor_offset] = ' ';
	video_memory[cursor_offset+1] = set_color_byte(WHITE, BLACK);;
	set_cursor_offset(cursor_offset);
}
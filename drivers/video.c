#include "video.h"

uint8_t set_color_byte(uint8_t foreground, uint8_t background) {
	return (background << 4) | foreground;
}

void clear_screen() {
	char* video_memory = (char*) VIDEO_MEMORY_ADDR;
	for(int i = 0; i < VIDEO_HEIGHT*VIDEO_WIDTH; i++) {
		*video_memory = 0;
		video_memory++;
	}
}

void print_string(uint8_t* str) {
	uint8_t* video_memory = (char*) VIDEO_MEMORY_ADDR;
	uint8_t color = set_color_byte(BLUE, LIGHT_GREEN);
	while(*str != '\0') {
		*video_memory = *str;
		*(video_memory+1) = color;
		video_memory += 2;
		str++;
	}
}
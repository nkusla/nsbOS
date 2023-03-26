#include "../drivers/video.h"

void main() {
	clear_screen();
	uint8_t str[] = "Hello kernel!";
	print_string(str);
}
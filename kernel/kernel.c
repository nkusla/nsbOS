#include "../drivers/video.h"

void main() {
	clear_screen();
	char str[] = "Hello world!";
	print_string(str);
}
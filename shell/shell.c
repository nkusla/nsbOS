#include "stdio.h"

int main() {
	uint8_t str[10] = {0};
	uint32_t a, b;
	printf("A = ");
	scanf("%d", &a);
	printf("B = ");
	scanf("%d", &b);
	printf("A + B = %d", a + b);
}
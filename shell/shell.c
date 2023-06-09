#include "stdio.h"

int main() {
	uint32_t num, operand, sum = 0;
	uint32_t i = 0;

	printf("NUMBER OF OPERANDS: ");
	scanf("%d", &num);

	for(; i < num; ++i) {
		printf("OPERAND %d: ", i+1);
		scanf("%d", &operand);
		sum += operand;
	}

	printf("SUM: %d", sum);

}
#include "stdio.h"

int32_t atoi(uint8_t* str) {
	int32_t result = 0;
	uint8_t digit;
	uint32_t i = 0;

	if(str[0] == '-')
		i++;

	for (; str[i] != '\0'; ++i) {
		digit = str[i] - '0';
		if(digit >= 0 && digit <= 9)
			result = 10 * result + digit;
		else
			return 0;
	}

	if(str[0] == '-')
		result *= -1;

	return result;
}

void itoa(int32_t value, uint8_t* str) {
	uint32_t i = 0, j = 0;
	int32_t digit;
	uint8_t temp;

	if(value == 0) {
		str[0] = '0';
		str[1] = '\0';
		return;
	}

	if(value < 0) {
		str[i++] = '-';
		value *= -1;
		j++;
	}

	while(value != 0) {
		digit = value % 10;
		str[i++] = digit + 48;
		value /= 10;
	}

	str[i--] = '\0';
	while(i > j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--; j++;
	}
}

void strcpy(uint8_t* dst, uint8_t* src) {
	uint32_t i = 0;

	while(src[i]) {
		dst[i] = src[i];
		i++;
	}
}

uint32_t strlen(uint8_t* str) {
	uint32_t i = 0;
	while(str[i])
		i++;
	return i;
}

uint32_t strcmp(uint8_t* str1, uint8_t* str2) {
	uint32_t i = 0;

	while(str1[i] != 0 || str2[i] != 0) {
		if(str1[i] > str2[i])
			return 1;
		else if(str1[i] < str2[i])
			return -1;
		else
			i++;
	}

	return 0;
}

void printf(uint8_t* str, ...) {
	uint32_t j = 0;
	uint8_t buffer[50] = {0};
	uint8_t temp[10] = {0};
	va_list vl;

	va_start(vl, str);

	for(uint32_t i = 0; str[i] != '\0'; ++i) {
		if(str[i] == '%') {
			switch(str[++i]) {
			case 'd': {
				itoa(va_arg(vl, uint32_t), temp);
				strcpy(&buffer[j], temp);
				j += strlen(temp);
			} break;
			}
		}
		else {
			buffer[j++] = str[i];
		}
	}
	va_end(vl);

	write(buffer, j);
}

void scanf(uint8_t* str, ...) {
	uint32_t j = 0;
	uint32_t read_size = 0;
	uint8_t buffer[50] = {0};
	va_list vl;

	while(!read_size)
		read_size = read(buffer, 50);

	va_start(vl, str);

	for(uint32_t i = 0; str[i] != '\0'; ++i)
		if(str[i] == '%')
			switch(str[++i]) {

				case 'd': {
					*va_arg(vl, uint32_t*) = atoi(&buffer[j]);
				} break;

				case 's': {
					uint8_t* ptr = va_arg(vl, uint8_t*);
					strcpy(ptr, buffer);
					ptr[strlen(buffer)] = 0;
				} break;
			}

	va_end(vl);
}
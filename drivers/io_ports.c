#include "io_ports.h"

uint8_t port_byte_in(uint16_t port) {
	uint8_t data;
	__asm__ __volatile__
	("in %%dx, %%ax" : "=a" (data) : "d" (port));
	return data;
}

void port_byte_out(uint16_t port, uint8_t data) {
	__asm__ __volatile__
	("out %%al, %%dx" : : "a" (data), "d" (port));
}
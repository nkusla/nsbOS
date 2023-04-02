#ifndef IO_PORTS_H
#define IO_PORTS_H

#include <stdint.h>

// I/O ports

// VIDEO
#define VIDEO_CONTROL_PORT			0x3d4
#define VIDEO_DATA_PORT				0x3d5
#define VIDEO_CURSOR_OFFSET_LOW		0x0f
#define VIDEO_CURSOR_OFFSET_HIGH	0x0e

// PIC
#define PRIMARY_PIC_COMMAND_PORT	0x20
#define PRIMARY_PIC_DATA_PORT		0x21
#define SECONDARY_PIC_COMMAND_PORT	0xa0
#define SECONDARY_PIC_DATA_PORT		0xa1

#define ICW1_INIT					0x11
#define ICW2_OFFSET_32				0x20
#define ICW2_OFFSET_40				0x28
#define ICW3_IRQ2					0x04
#define ICW3_SECONDARY				0x02
#define ICW4_8086_MODE				0x01
#define OCW1_ENABLE					0x00
#define PIC_EOI						0x20

uint8_t port_byte_in(uint16_t port);
void port_byte_out(uint16_t port, uint8_t data);

#endif
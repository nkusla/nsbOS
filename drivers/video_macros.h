#ifndef VIDEO_MACROS_H
#define VIDEO_MACROS_H

#define VIDEO_MEMORY_ADDR 	0xb8000
#define VIDEO_WIDTH 		80
#define VIDEO_HEIGHT 		25

#define VIDEO_CONTROL_REG			0x3d4
#define VIDEO_DATA_REG				0x3d5
#define VIDEO_CURSOR_OFFSET_LOW		0x0f
#define VIDEO_CURSOR_OFFSET_HIGH	0x0e

#define BLACK		0x0
#define WHITE		0xf
#define BLUE		0x1
#define GREEN		0x2
#define CYAN		0x3
#define RED			0x4
#define MAGENTA		0x5
#define BROWN		0x6
#define YELLOW		0xe

#define LIGHT_GREY		0x7
#define DARK_GREY		0x8
#define LIGHT_BLUE		0x9
#define LIGHT_GREEN		0xa
#define LIGHT_CYAN		0xb
#define LIGHT_RED		0xc
#define LIGHT_MAGENTA	0xd

#endif
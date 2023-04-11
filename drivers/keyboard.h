#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
#include "video.h"

#define ESC			0x01
#define BACKSPACE	0x0e
#define TAB			0x0f
#define ENTER		0x1c
#define LEFT_CTRL	0x1d
#define LEFT_SHIFT	0x2a
#define RIGHT_SHIFT	0x36
#define LEFT_ALT	0x38
#define CAPS_LOCK	0x3a

#define PS2_CONTROLLER_DATA_PORT 0x60

void keyboard_scancode_print(uint8_t scancode);
uint8_t keyboard_scancode_read();

#endif
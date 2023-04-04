#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
#include "video.h"

#define PS2_CONTROLLER_DATA_PORT 0x60

void keyboard_scancode_print(uint8_t scancode);
uint8_t keyboard_scancode_read();

#endif
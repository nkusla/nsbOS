#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>
#include "video_macros.h"
#include "io_ports.h"

uint16_t get_cursor_offset();
void set_cursor_offset(uint16_t offset);

uint8_t set_color_byte(uint8_t foreground, uint8_t background);
void clear_screen();
void print_string(uint8_t* str);

#endif
#ifndef VGA_H
#define VGA_H

#include <stdint.h>

static const uint8_t VGA_8_BIT_COLOR_ROTATION = 4;
static const uint8_t VGA_16_BIT_ENTRY_ROTATION = 8;

typedef enum vga VGAColor;

typedef unsigned char TTYChar;

enum vga {
  VGA_BLACK = 0,
  VGA_BLUE = 1,
  VGA_GREEN = 2,
  VGA_CYAN = 3,
  VGA_RED = 4,
  VGA_MAGENTA = 5,
  VGA_BROWN = 6,
  VGA_LIGHT_GREY = 7,
  VGA_DARK_GREY = 8,
  VGA_LIGHT_BLUE = 9,
  VGA_LIGHT_GREEN = 10,
  VGA_LIGHT_CYAN = 11,
  VGA_LIGHT_RED = 12,
  VGA_LIGHT_MAGENTA = 13,
  VGA_LIGHT_BROWN = 14,
  VGA_WHITE = 15,
};

static inline uint8_t buildVGAColor(
  VGAColor foreground,
  VGAColor background
);

static inline uint16_t buildVGAEntry(
  TTYChar termChar,
  uint8_t color
);

#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "vga.h"

uint8_t buildVGAColor(
  VGAColor foreground,
  VGAColor background
) {
  return (foreground | background) << VGA_8_BIT_COLOR_ROTATION;
}

uint16_t buildVGAEntry(
  TTYChar termChar,
  uint8_t color
){
  return ((uint16_t) termChar | (uint16_t) color) << VGA_16_BIT_ENTRY_ROTATION;
}

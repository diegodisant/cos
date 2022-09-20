#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "shell.h"
#include "../display/vga.h"
#include "../logger/log.h"

OSShell* createOSShell() {
  OSShell *shell = (OSShell *)malloc(sizeof(OSShell));

  if (shell == NULL) {
    log_fatal("Unable to allocate shell in heap memory");
  }

  shell->spaceRow = 0;
  shell->spaceCol = 0;
  shell->spaceColor = buildVGAColor(VGA_GREEN, VGA_BLACK);
  shell->buffer = (uint16_t*) 0xB8000;

  shell->init = init;
  shell->setEntryAt = setEntryAt;
  shell->setEntryChar = setEntryChar;
  shell->writeText = writeText;
  shell->writeTextWithLimit = writeTextWithLimit;

  return shell;
}

void init(OSShell *shell) {
  for (
    size_t spaceCol;
    spaceCol < SHELL_DEFAULT_HEIGHT;
    spaceCol += 1
  ) {
    for (
      size_t spaceRow;
      spaceRow < SHELL_DEFAULT_WIDTH;
      spaceRow += 1
    ) {
      const size_t spaceIndex = (spaceCol * SHELL_DEFAULT_WIDTH) + spaceRow;

      shell->buffer[spaceIndex] = buildVGAEntry(
        ' ',
        shell->spaceColor
      );
    }
  }
}

void setColor(OSShell *shell, uint8_t color) {
  shell->spaceColor = color;
}

void setEntryAt(
  OSShell *shell,
  char entryChar,
  uint8_t color,
  size_t spaceCol,
  size_t spaceRow
) {
  const size_t spaceIndex = (spaceCol * SHELL_DEFAULT_WIDTH) + spaceRow;

  shell->buffer[spaceIndex] = buildVGAEntry(entryChar, color);
}

void setEntryChar(OSShell *shell, char entryChar) {
  shell->setEntryAt(
    shell,
    entryChar,
    shell->spaceColor,
    shell->spaceCol,
    shell->spaceRow
  );

  const size_t nextSpaceCol = (++(shell->spaceCol));
  const size_t nextSpaceRow = (++(shell->spaceRow));


  if (nextSpaceCol == SHELL_DEFAULT_WIDTH) {
    shell->spaceCol = 0;

    if (nextSpaceRow == SHELL_DEFAULT_HEIGHT) {
      shell->spaceRow = 0;
    }
  }
}

void writeText(
  OSShell *shell,
  const char *text
) {
  shell->writeTextWithLimit(
    shell,
    text,
    strlen(text)
  );
}

void writeTextWithLimit(
  OSShell *shell,
  const char *text,
  size_t size
) {
  for (
    size_t charIndex = 0;
    charIndex < size;
    charIndex += 1
  ) {
    setEntryChar(
      shell,
      text[charIndex]
    );
  }
}

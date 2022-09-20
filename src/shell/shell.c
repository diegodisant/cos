#include <stdlib.h>
#include <stdint.h>

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

  shell->buffer = (uint16_t*) SHELL_DEFAULT_BUFFER_ADDRESS;

  return shell;
}

void init(OSShell *shell) {

}

void setColor(OSShell *shell, uint8_t color);

void setEntryAt(
  OSShell *shell,
  char entryChar,
  uint8_t color,
  size_t row,
  size_t col
);

void setEntryChar(OSShell *shell, char entryChar);

void writeText(
  OSShell *shell,
  const char *text
);

void writeTextWithLimit(
  OSShell *shell,
  const char *text,
  size_t size
);

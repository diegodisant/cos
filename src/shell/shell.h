#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdint.h>

static const size_t SHELL_DEFAULT_WIDTH = 80;
static const size_t SHELL_DEFAULT_HEIGHT = 25;

typedef struct Shell OSShell;

struct Shell {
  size_t    spaceRow;
  size_t    spaceCol;
  uint8_t   spaceColor;
  uint16_t  *buffer;

  void (*init)(OSShell *shell);

  void (*setColor)(OSShell *shell, uint8_t color);

  void (*setEntryAt)(
    OSShell *shell,
    char entryChar,
    uint8_t color,
    size_t spaceCol,
    size_t spaceRow
  );

  void (*setEntryChar)(OSShell *shell, char entryChar);

  void (*writeText)(
    OSShell *shell,
    const char *text
  );

  void (*writeTextWithLimit)(
    OSShell *shell,
    const char *text,
    size_t size
  );
};

OSShell* createOSShell();

void init(OSShell *shell);

void setColor(OSShell *shell, uint8_t color);

void setEntryAt(
  OSShell *shell,
  char entryChar,
  uint8_t color,
  size_t spaceCol,
  size_t spaceRow
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

#endif

#ifndef SHELL_H
#define SHELL_H

static const size_t SHELL_DEFAULT_WIDTH = 80;
static const size_t SHELL_DEFAULT_HEIGHT = 25;
static const uint8_t SHELL_DEFAULT_BUFFER_ADDRESS = 0xB8000;

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
    size_t row,
    size_t col
  );

  void (*setEntryChar)(OSShell *shell, char entryChar);

  void (*writeTextWithLimit)(
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

#endif

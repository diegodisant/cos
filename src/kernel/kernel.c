#include "../shell/shell.h"

void kernelMain() {
  OSShell *shell = createOSShell();

  shell->init(shell);
  shell->writeText(
    shell,
    "[+] COS Kernel Online"
  );
}

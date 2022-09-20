#include "../shell/shell.h"

int main() {
  OSShell *shell = createOSShell();

  shell->init(shell);
  shell->writeText(
    shell,
    "[+] COS Kernel Online"
  );

  return 0;
}

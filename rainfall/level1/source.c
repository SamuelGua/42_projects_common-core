#include <stdio.h>
#include <stdlib.h>

void run(void) {
  fwrite("Good... Wait what?\n", 1, 19, 1);
  system("/bin/sh");
  return;
}

int main() {
  char input[76];

  gets(input);
  return;
}

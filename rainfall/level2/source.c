#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void p(void) {
  char local_50[76];

  fflush(stdout);

  gets(local_50);

  // Simuler l'adresse de retour (non faisable proprement en C standard)
  // On utilise une valeur fictive ici
  unsigned int unaff_retaddr = (unsigned int)__builtin_return_address(0);

  if ((unaff_retaddr & 0xb0000000) == 0xb0000000) {
      printf("(%p)\n", (void *)unaff_retaddr);
      _exit(1);
  }

  puts(local_50);
  strdup(local_50);

  return;
}

int main(void) {
  p();
  return;
}
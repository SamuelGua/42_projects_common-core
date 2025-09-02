#include <stdio.h>
#include <stdlib.h>

void m(void *param_1,int param_2,char *param_3,int param_4,int param_5) {
  puts("Nope");
  return;
}

void n(void) {
  system("/bin/cat /home/user/level7/.pass");
  return;
}


int main(int argc, char *argv[])
{
  char *buffer;
  int *func_ptr;

  buffer = malloc(0x40);
  func_ptr = malloc(4);

  *func_ptr = (int)m;
  strcpy(buffer, argv[1]);

  ((void (*)(void))(*func_ptr))();

  return 0;
}

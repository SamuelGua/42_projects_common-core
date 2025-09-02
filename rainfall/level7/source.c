#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char c[0x44];  // Variable globale (buffer de 68 octets)

void m(void *param_1, int param_2, char *param_3, int param_4, int param_5) {
    time_t tVar1;

    tVar1 = time(NULL);
    printf("%s - %ld\n", c, tVar1);
}

int main(int argc, char *argv[]) {
    int *ptr1;
    int *ptr2;
    int *ptr3;
    FILE *f;

    ptr1 = malloc(8);
    *ptr1 = 1;
    ptr1[1] = (int)malloc(8);

    ptr3 = malloc(8);
    *ptr3 = 2;
    ptr3[1] = (int)malloc(8);

    strcpy((char *)ptr1[1], argv[1]);
    strcpy((char *)ptr3[1], argv[2]);

    f = fopen("/home/user/level8/.pass", "r");
    fgets(c, 0x44, f);

    puts("~~");

    return 0;
}

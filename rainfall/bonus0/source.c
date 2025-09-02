#include <stdio.h>
#include <string.h>
#include <unistd.h>

void p(char *param_1, char *param_2) {
    char *newline;
    char inputs[4104];

    puts(param_2);
    read(0, inputs, 0x1000);
    newline = strchr(inputs, '\n');
    if (newline) {
        *newline = '\0';
    }
    strncpy(param_1, inputs, 0x14);
}

void pp(char *param_1) {
    char first[20];
    char second[20];
    unsigned int len = 0xffffffff;
    char *ptr;

    p(first, "-");
    p(second, "-");

    strcpy(param_1, first);

    ptr = param_1;
    do {
        if (len == 0) break;
        len--;
    } while (*ptr++ != '\0');

    param_1[~len] = ' ';
    param_1[~len + 1] = '\0';

    strcat(param_1, second);
}

int main(void) {
    char buffer[54];
    pp(buffer);
    puts(buffer);
    return 0;
}

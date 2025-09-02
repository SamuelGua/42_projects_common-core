#include <stdio.h>
#include <stdlib.h>

int m;

void p(char *user_input) {
    printf(user_input);
}

void n(void) {
    char buffer[520];

    fgets(buffer, 512, stdin);

    vulnerable_print(buffer);

    if (m == 0x1025544) {
        system("/bin/cat /home/user/level5/.pass");
    }
}

int main(void) {
    handle_input();
    return 0;
}

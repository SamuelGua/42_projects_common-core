#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buffer[40];
    int count
    int result = 1

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <count> <data>\n", argv[0]);
        return 1;
    }
    count = atoi(argv[1]);
    if (count < 10) {
        memcpy(buffer, argv[2], count * 4);
        if (count == 0x574f4c46) {
            execl("/bin/sh", "sh", NULL);
        }

        result = 0;
    }

    return result;
}

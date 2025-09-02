#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int param_1, int param_2) {
    FILE *local_14;
    char local_98[65];
    char local_56[66];
    char *user_input;
    int iVar2;
    
    local_14 = fopen("/home/user/end/.pass", "r");
    if (local_14 == NULL) {
        return 0xffffffff;
    }

    memset(local_98, 0, sizeof(local_98));

    fread(local_98, 1, 0x42, local_14);

    user_input = *(char **)(param_2 + 4);
    if (user_input == NULL) {
        fclose(local_14);
        return 0xffffffff;
    }

    iVar2 = atoi(user_input);

    local_98[iVar2] = '\0';
    fread(local_56, 1, 0x41, local_14);
    fclose(local_14);

    if (strcmp(local_98, user_input) == 0) {
        execl("/bin/sh", "sh", (char *)NULL);
    } else {
        puts(local_56);
    }

    return 0;
}

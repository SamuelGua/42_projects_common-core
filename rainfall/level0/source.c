#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int iVar1;
    char *local_20;
    uid_t local_18;
    gid_t local_14;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    iVar1 = atoi(argv[1]);

    if (iVar1 == 0x1a7) {  // 0x1a7 = 423
        local_20 = strdup("/bin/sh");
        local_14 = getegid();
        local_18 = geteuid();
        setresgid(local_14, local_14, local_14);
        setresuid(local_18, local_18, local_18);
        char *args[] = {local_20, NULL};
        execv("/bin/sh", args);
        perror("execv failed");
    } else {
        fwrite("No !\n", 1, 5, stderr);
    }

    return 0;
}

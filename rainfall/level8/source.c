#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *auth = NULL;
char *service = NULL;

int main(void) {
    char input[128];
    char local_8b[2];
    char acStack_89[125];

    while (1) {
        printf("%p, %p \n", auth, service);

        if (fgets(input, sizeof(input), stdin) == NULL)
            return 0;

        // AUTH
        if (strncmp(input, "auth ", 5) == 0) {
            auth = (char *)malloc(4);
            if (auth == NULL) continue;
            auth[0] = '\0';
            auth[1] = '\0';
            auth[2] = '\0';
            auth[3] = '\0';

            size_t len = strlen(local_8b);
            if (len < 0x1f) {
                strcpy(auth, local_8b);
            }
        } else if (strncmp(input, "reset", 5) == 0) {
            free(auth);
        }

        // SERVICE
        else if (strncmp(input, "service", 7) == 0) {
            service = strdup(acStack_89); 
        }

        // LOGIN
        else if (strncmp(input, "login", 5) == 0) {
            if (auth && *(int *)(auth + 32) != 0) {
                system("/bin/sh");
            } else {
                fwrite("Password:\n", 1, 10, stdout);
            }
        }
    }

    return 0;
}

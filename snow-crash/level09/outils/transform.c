#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Need one arg\n");
        return 1;
    }

    char *chaine = argv[1];
    int pos = 0;

    for (int i = 0; chaine[i] != '\0'; i++) {
        printf("%c", chaine[i] - pos);
        pos++;
    }
    printf("\n");
    return 0;
}

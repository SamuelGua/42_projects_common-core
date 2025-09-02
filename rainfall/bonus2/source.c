#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int language;  // Variable globale pour la langue

// Fonction de copie de chaîne avec une taille définie
void builtin_strncpy(char *dest, const char *src, size_t n) {
    strncpy(dest, src, n);
}

// Fonction de salutation en fonction de la langue
void greetuser(void) {
    char local_4c[4];        // Buffer pour le message de salutation
    unsigned int local_48;   // Structure pour stocker les valeurs associées
    char local_44[64];       // Buffer pour un autre message de salutation

    if (language == 1) {  // Si la langue est le finnois (1)
        local_4c[0] = 'H';
        local_4c[1] = 'y';
        local_4c[2] = 'v';
        local_4c[3] = -0x3d; // Valeur non valide ici, probabilité d'un bug de mémoire
        local_48 = 0x5c3d5c20; // Valeurs aléatoires dans les parties de la structure
        builtin_strncpy(local_44, "päivää ", 7); // "päivää " en finnois
    }
    else if (language == 2) {  // Si la langue est néerlandaise (2)
        builtin_strncpy(local_4c, "Goed", 4);
        local_48 = 'e' | ('m' << 8) | ('i' << 16) | ('d' << 24);
        builtin_strncpy(local_44, "dag!", 4);
        local_44[4] = ' ';
        local_44[5] = '\0';
    }
    else if (language == 0) {  // Langue par défaut (0)
        builtin_strncpy(local_4c, "Hell", 4);
        local_48 = 0x206f;  // Valeur étrange ici aussi
    }

    strcat(local_4c, &stack0x00000004);  // Potentiel overflow de pile (vulnérabilité)
    puts(local_4c);  // Affiche la salutation
}

// Fonction principale
int main(int param_1, int param_2) {
    unsigned int uVar1;
    int iVar2;
    char *pcVar3;
    unsigned int *puVar4;
    byte bVar5;
    char local_60[40];
    char acStack_38[36];
    char *local_14;

    bVar5 = 0;

    // Vérifie le nombre d'arguments passés
    if (param_1 == 3) {
        pcVar3 = local_60;

        // Initialisation de local_60 à zéro
        for (iVar2 = 0x13; iVar2 != 0; iVar2--) {
            memset(pcVar3, 0, 4);
            pcVar3 += 4;
        }

        // Copie des données dans local_60 et acStack_38
        strncpy(local_60, *(char **)(param_2 + 4), 0x28);
        strncpy(acStack_38, *(char **)(param_2 + 8), 0x20);

        // Récupère la langue du système
        local_14 = getenv("LANG");
        if (local_14 != NULL) {
            iVar2 = memcmp(local_14, "fi", 2);
            if (iVar2 == 0) {
                language = 1;  // Langue finnoise
            }
            else {
                iVar2 = memcmp(local_14, "nl", 2);
                if (iVar2 == 0) {
                    language = 2;  // Langue néerlandaise
                }
            }
        }

        pcVar3 = local_60;
        puVar4 = (unsigned int *)&stack0xffffff50;
        for (iVar2 = 0x13; iVar2 != 0; iVar2--) {
            *puVar4 = *(unsigned int *)pcVar3;
            pcVar3 += (bVar5 * -2 + 1) * 4;
            puVar4 += (bVar5 * -2 + 1);
        }

        uVar1 = greetuser();
    }
    else {
        uVar1 = 1; 
    }

    return uVar1;
}

#include "libasm.h"


int main() {
    char dst[10] = "samuel\0";  // Augmentation de la taille pour éviter les débordements
    char src[10] = "autre";   // Idem, augmentation de la taille

    // Affichage de la différence entre les deux chaînes
    printf("Différence entre \"%s\" et \"%s\" :\n", dst, src);
    printf("- strcmp : %d\n", strcmp(dst, src));
    printf("- ft_strcmp : %d\n", ft_strcmp(dst, src));

    // Calcul et affichage des longueurs
    int len_dst = ft_strlen(dst);  // Longueur de dst avec la fonction assembleur
    int len_src = ft_strlen(src);  // Longueur de src avec la fonction assembleur
    printf("La longueur de \"%s\" est %d (ft_strlen).\n", dst, len_dst);
    printf("La longueur de \"%s\" est %d (ft_strlen).\n", src, len_src);

    // Écriture du contenu de `dst` avec ft_write
    printf("Contenu de dst affiché avec ft_write : ");
    fflush(stdout);
    ft_write(1, dst, len_dst);
    printf("\n");

    // Copie de `src` dans `dst` avec ft_strcpy
    //char* new_dst = _ft_strdup(dst);
    //printf("new dst = %s\n", new_dst);
    ft_strcpy(dst, src);
    printf("Après copie, \"dst\" contient : \"%s\" (ft_strcpy).\n", dst);
    int fd = open("test.txt", O_RDONLY);
    char buffer[5];
    int i = read(fd, buffer, 5);
    //buffer[i] = '\0';
    printf("READ ->  %s\n", buffer);

    return i;
}

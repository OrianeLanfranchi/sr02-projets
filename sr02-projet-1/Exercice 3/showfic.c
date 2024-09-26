//mmap

#include "exercice3.h"

int main (int argc, char* argv[]){

    int *projection;
    int fichier;
    struct stat etat_fichier;
    long taille_fichier;
    int i = 0;

    if (argc != 2) {
        printf("Veuillez indiquer un nom de fichier.\n");
        exit(1);
    }

    if ((fichier = open(argv[1], O_RDWR)) < 0) {
        perror("Erreur dans l'ouverture du fichier.\n");
        exit(1);
    }

    //on récupère la taille du fichier
    stat(argv[1], &etat_fichier);
    taille_fichier = etat_fichier.st_size;

    //utilisation de mmap() et vérification
    projection = ( int *) mmap(NULL, taille_fichier, PROT_READ, MAP_SHARED, fichier, 0);
    if (projection == (int *) MAP_FAILED) {
        perror("Erreur dans la création de la projection !\n");
        exit(1);
    }
    close(fichier);

    //boucle sur while, lire i
    while(1){
      printf("Saisir un chiffre (entre 1 et 9).\n");
      printf("Pour sortir, saisir le nombre 99.\n");
      printf("Votre choix :");
      scanf("%d", &i);

      if (i == 99){
        printf("Fermeture du programme.\n");
        munmap((void *)projection, taille_fichier);
        exit(0);
      }

      for (int k = 0; k < taille_fichier / sizeof(int); k++) {
            printf("projection[%d] : %d\n", k, projection[k]);
      }

    }

    return 0;
}

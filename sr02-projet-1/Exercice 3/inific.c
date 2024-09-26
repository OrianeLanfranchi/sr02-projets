//initialisation du fichier
#include "exercice3.h"

int main(int argc, char* argv[]){
    //Création du fichier titi.dat
    int fichier;
    if (argc != 2) {
        printf("Veuillez indiquer un nom de fichier.\n");
        exit(1);
    }

    //ouverture du fichier et contrôle
    fichier = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    if ( fichier < 0) {
        perror("Erreur dans l'ouverture du fichier.\n");
        exit(1);
    }

    //création du tableau
    int tab1[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 1000 };
    //le fichier est initialisé avec les éléments du tableau :
    write(fichier, tab1, 10 * sizeof(int));
    close(fichier);
    return 0;
}

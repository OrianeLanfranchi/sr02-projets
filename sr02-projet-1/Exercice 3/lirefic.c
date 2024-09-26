//lire le fichier

#include "exercice3.h"

int main (int argc, char* argv[]){
  int fichier;

  if (argc != 2) {
      printf("Veuillez indiquer un nom de fichier.\n");
      exit(1);
  }

  //ouverture du fichier et contrôle
  fichier = open(argv[1], O_RDWR, 0666);
  if ( fichier < 0) {
      perror("Erreur dans l'ouverture du fichier.\n");
      exit(1);
  }

  //lecture du fichier
  int tab2[10];
  read(fichier, tab2, 10 * sizeof(int));
  close(fichier);

  //affichage sur la sortie standard :
  for (int i = 0; i < 10; i++) printf("tab2[%d]: %d\n", i, tab2[i]);

  return 0;
}

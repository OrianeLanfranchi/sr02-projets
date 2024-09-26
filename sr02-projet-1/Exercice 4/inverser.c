#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main (int argc, char *argv[]){
  char *projection;
  int fichier;
  struct stat etat_fichier;
  long taille_fichier;
  int i;
  char tmp;

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
  projection = ( char *) mmap(NULL, taille_fichier, PROT_READ | PROT_WRITE, MAP_SHARED, fichier, 0);
  if (projection == (char *) MAP_FAILED) {
      perror("Erreur dans la création de la projection !\n");
      exit(1);
  }
  close(fichier);

  //inversion du fichier
  for (i = 0; i < taille_fichier / 2; i++) {
  	tmp = projection[i];
  	projection[i] = projection[taille_fichier - 1 - i];
  	projection[taille_fichier - 1 - i] = tmp;
  }

  //affichage
  for (i = 0; i < taille_fichier; i++) printf("%c", projection[i]);
  printf("\n");

}

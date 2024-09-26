#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

int main() {
  int T[N]; // toutes les cases init à true (0)
  for (int i = 0; i < N; i++) {
    T[i] = 1;
  }
  int n = N;
  int sqrt_n = sqrt(n);


  for (int i = 2; i <= sqrt_n; i++) {
    if (T[i-2] == 1) { // T[i-2] car la première case du tableau représente la valeur 2
      for (int j = i*i; j <= n; j = j + i) {
        T[j-2] = 0;
      }
    }
  }

  for (int i = 0; i < N; i++){
    printf("Valeur : %d est %d\n", i+2, T[i]);
  }

  return 0;
}

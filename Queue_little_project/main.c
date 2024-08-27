// Copyright «2024» Gabriel Coelho Soares
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queuefn.h"

int main(int argc, char *argv[]) {
  int vetor_exemplo[TAMANHO] = {5, 2, 3, 9, 4};

  for (int i = 0; i < TAMANHO; i++) {
    printf("Inserindo o valor %d na fila", vetor_exemplo[i]);
    if (!push_queue(vetor_exemplo[i])) {
      printf("Fila cheia");
    }
  }
  return EXIT_SUCCESS;
}

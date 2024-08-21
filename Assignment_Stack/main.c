// Copyright [2024] <Gabriel Coelho Soares>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "functions.h"
#include "stacks.h"

int main() {
  // Copyright 2024 Marcos Nava
  char exp[100] = "";
  char vec[100][20] = {'\0'};

  strcpy(exp, "(((35 / 5) + (4 * 2)) * 5) / (3 * 5)");

  stringParaVetor(exp, vec, TAMANHO);

  for (int i = 0; i < 100 && (strcmp(vec[i], "") != 0); i++) {
    printf("%s\n", vec[i]);
  }

  // Copyright 2024 Gabriel Coelho Soares e Marcos Moreira Martins
  // Chamo a função que irá realizar toda a magia matemática
  matemagica(vec);

  // exibo o "topo" da pilha, restando somente o último resultado.
  printf("O resultado é %.2lf", pilhatopo_double());

  return 0;
}

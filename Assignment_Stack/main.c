// Copyright [2024] <Gabriel Coelho Soares>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "functions.h"
#include "stacks.h"

int main() {
  char exp[100] = "";
  char vec[100][20] = {'\0'};

  strcpy(exp, "(((35/5)+8)*5)/2");

  stringParaVetor(exp, vec, TAMANHO);

  // for (int i = 0; i < 100 && (strcmp(vec[i], "") != 0); i++) {
  //  printf("%s\n", vec[i]);
  //}
  matemagica(vec);

  printf("O resultado é %.2lf", pilhatopo_double());

  return 0;
}

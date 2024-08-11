// Copyright 2024 <Marcos Nava>
#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

// Constantes
enum { OP_NAO_SELECIONADA = 0, OP_PUSH, OP_POP, OP_SAIR };

// Protótipos
int menu();

int main(void) {
  int opcao = OP_NAO_SELECIONADA;
  int valor;
  while (opcao != OP_SAIR) {
    opcao = menu();

    switch (opcao) {
      case OP_PUSH:
        printf("Digite um numero: ");
        scanf("%d", &valor);
        if (!push(valor)) {
          printf("Estouro de pilha!\n");
        }
        break;
      case OP_POP:
        if (pop(&valor)) {
          printf("Retirado %d da pilha!\n", valor);
        } else {
          printf("Pilha vazia!\n");
        }
        break;
      case OP_SAIR:
        break;
      default:
        printf("Opcao invalida!\n");
    }
  }
  return EXIT_SUCCESS;
}

int menu() {
  int op = 0;
  printf("Menu\n");
  printf("%d - push\n", OP_PUSH);
  printf("%d - pop\n", OP_POP);
  printf("%d - sair\n", OP_SAIR);
  printf("Digite sua opcao: ");
  scanf("%d", &op);

  return op;
}

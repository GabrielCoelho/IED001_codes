// Copyright «2024» Gabriel Coelho Soares
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "circular_queue.h"
// #include "simple_queue.h"

// Constantes
enum {
  OPTION_DESELECT = 0,
  OPTION_PUSH,
  OPTION_REMOVE,
  OPTION_SHOW,
  OPTION_EXIT
};

// Protótipos
int menu();

int main(int argc, char *argv[]) {
  int removed_from_queue = 0;
  int option = OPTION_DESELECT;
  int inserted_number = 0;

  while (option != OPTION_EXIT) {
    option = menu();

    switch (option) {
      case OPTION_PUSH:
        printf("Digite um número: ");
        scanf("%d", &inserted_number);
        if (!push_queue(inserted_number)) printf("\n\n");
        break;
      case OPTION_REMOVE:
        if (!move_queue(&removed_from_queue)) printf("\n\n");
        break;
      case OPTION_SHOW:
        show_vec();
        break;
      case OPTION_EXIT:
        break;
      default:
        printf("Opção Inválida\n");
    }
  }

  return EXIT_SUCCESS;
}

int menu() {
  int op = OPTION_DESELECT;

  printf("Menu\n");
  printf("%d - Adicionar\n", OPTION_PUSH);
  printf("%d - Retirar\n", OPTION_REMOVE);
  printf("%d - Imprimir\n", OPTION_SHOW);
  printf("%d - Sair\n", OPTION_EXIT);
  printf("Digite sua opcao: ");
  scanf("%d", &op);

  return op;
}

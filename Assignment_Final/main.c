// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "config.h"
#include "linkedList.h"

enum {
  OPT_DESSELECT,
  OPT_ADD,
  OPT_SET,
  OPT_REMOVE,
  OPT_SEARCH,
  OPT_REPORT,
  OPT_EXIT,
};

int menu();

int main(int argc, char *argv[]) {
  system("clear");
  printf("\t### Clinique X - Medical Data Center ###\n\n");
  initializer();
  char name[40], address[100], email[60], phone[14], cpf[12];
  int aux;
  int op = 0;
  while (op != OPT_EXIT) {
    op = menu();
    scanf("%*c");
    switch (op) {
      case OPT_ADD:
        printf("Insira o valor dos dados abaixo\nCPF: ");
        read_line(cpf, 12);
        if (!addNewItem(cpf)) {
          printf("CPF já registrado\n");
        }
        break;
      case OPT_REMOVE:
        printf("Qual registro CPF você quer excluir?\nCPF: ");
        read_line(cpf, 12);
        if (!exclude_item(cpf)) {
          printf("CPF não encontrado\n");
        }
        break;
      case OPT_SET:
        printf("Insira o Registro CPF que você quer atualizar os dados\nCPF: ");
        read_line(cpf, 12);
        aux = list_search_value(cpf);
        if (aux != -1) {
          list_set(aux);
        } else {
          printf("CPF não encontrado\n");
        }
        break;
      case OPT_SEARCH:
        printf("\nCPF: ");
        read_line(cpf, 12);
        if (!search_cpf(cpf)) {
          printf("CPF não encontrado");
        }
        break;
      case OPT_REPORT:
        showFirstToLast();
        break;
      case OPT_EXIT:
        break;
    }
  }
  return EXIT_SUCCESS;
}

int menu() {
  int option = 0;
  printf("\nEscolha uma opção:\n");
  printf("%d - Adicionar um dado\n", OPT_ADD);
  printf("%d - Atualizar um Dado\n", OPT_SET);
  printf("%d - Remover um Dado\n", OPT_REMOVE);
  printf("%d - Procurar um Dado\n", OPT_SEARCH);
  printf("%d - Mostrar um Relatório\n", OPT_REPORT);
  printf("%d - Exit\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

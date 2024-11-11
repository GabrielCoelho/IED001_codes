// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "./config.h"

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
  initializer();
  struct Database removed_from_list;
  char name[40], address[100], email[60], phone[14], cpf[12];
  int aux;
  int op = 0;
  printf("Simple Lists inside an array");
  while (op != OPT_EXIT) {
    op = menu();
    scanf("%*c");
    switch (op) {
      case OPT_ADD:
        printf("Insert the value of the data below\nCPF: ");
        read_line(cpf, 12);
        if (!addNewItem(cpf)) {
          printf("CPF already registered\n");
        }
        break;
      case OPT_REMOVE:
        printf("Which CPF that was added you want to exclude?\nCPF: ");
        read_line(cpf, 12);
        break;
      case OPT_SET:
        printf("Insert below the CPF to update the data\nCPF: ");
        read_line(cpf, 12);
        aux = list_search_value(cpf);
        if (aux != -1) {
          list_set(aux);
        } else {
          printf("CPF wasn't found\n");
        }
        break;
      case OPT_SEARCH:
        break;
      case OPT_REPORT:
        break;
      case OPT_EXIT:
        break;
    }
  }
  return EXIT_SUCCESS;
}

int menu() {
  int option = 0;
  printf("\nChoose an option:\n");
  printf("%d - Add a Data\n", OPT_ADD);
  printf("%d - Update a Data value\n", OPT_SET);
  printf("%d - Remove a Data\n", OPT_REMOVE);
  printf("%d - Search a Data\n", OPT_SEARCH);
  printf("%d - Give a Report\n", OPT_REPORT);
  printf("%d - Exit\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

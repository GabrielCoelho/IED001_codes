// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "../Assignment_Lists/list.h"

enum {
  OPT_DESSELECT,
  OPT_ADD,
  OPT_REMOVE,
  OPT_SET,
  OPT_SHOWONE,
  OPT_SHOWALL,
  OPT_SORT,
  OPT_EXIT,
};

int menu();

int main(int argc, char *argv[]) {
  initialize();
  struct Data removed_from_list;
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
        fgets(cpf, 12, stdin);
        cpf[strcspn(cpf, "\n")] = '\0';
        scanf("%*c");
        if (list_search_value(cpf) == -1) {
          printf("Name: ");
          fgets(name, 39, stdin);
          name[strcspn(name, "\n")] = '\0';
          printf("Address: ");
          fgets(address, 99, stdin);
          address[strcspn(address, "\n")] = '\0';
          printf("Phone Number: ");
          fgets(phone, 14, stdin);
          phone[strcspn(phone, "\n")] = '\0';
          printf("Email: ");
          fgets(email, 59, stdin);
          email[strcspn(email, "\n")] = '\0';
          if (!list_add(name, address, cpf, phone, email)) {
            printf("Couldn't Add to the data\nTry Again\n\n ");
          }
        } else {
          printf("CPF already registered\n");
        }
        break;
      case OPT_REMOVE:
        printf("Which CPF that was added you want to exclude?\nCPF: ");
        scanf("%d", &cpf);
        if (!list_delete(&removed_from_list, cpf)) {
          printf("\n");
        }
        break;
      case OPT_SET:
        printf("Insert below the CPF to update the data\nCPF: ");
        scanf("%d", &cpf);
        aux = list_search_value(cpf);
        if (aux != -1) {
          list_set(aux);
        } else {
          printf("CPF wasn't found\n");
        }
        break;
      case OPT_SHOWONE:
        printf("Insert below the CPF to show the data relate to it: ");
        scanf("%d", &cpf);
        aux = list_search_value(cpf);
        if (aux != -1) {
          printf("%s\t%d\n%s\n%d\t%s\n\n", list_pointer[aux].name, cpf,
                 list_pointer[aux].address, list_pointer[aux].phone_number,
                 list_pointer[aux].email);
        }
        break;
      case OPT_SHOWALL:
        list_show();
        break;
      case OPT_SORT:
        list_sort();
        break;
      case OPT_EXIT:
        free(list_pointer);
        break;
      default:
    }
  }
  return EXIT_SUCCESS;
}

int menu() {
  int option = 0;
  printf("\nChoose an option:\n");
  printf("%d - Add a Data\n", OPT_ADD);
  printf("%d - Remove a Data\n", OPT_REMOVE);
  printf("%d - Update a Data value\n", OPT_SET);
  printf("%d - Show a single data\n", OPT_SHOWONE);
  printf("%d - Show all data\n", OPT_SHOWALL);
  printf("%d - Sort all data\n", OPT_SORT);
  printf("%d - Exit\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

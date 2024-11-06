// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
enum {
  OPT_DESSELECT,
  OPT_ADD,
  OPT_REMOVE,
  OPT_EXIT,
};

int menu();

int main(int argc, char *argv[]) {
  int op = OPT_DESSELECT;
  int data = 0;
  struct BTree *new = NULL;

  initialize();

  while (op != OPT_EXIT) {
    op = menu();
    switch (op) {
      case OPT_ADD:
        printf("Enter a number: ");
        scanf("%d", &data);
        new = newData(data);
        addNewData(new, start);
        break;
      case OPT_REMOVE:
        printf("Enter a number: ");
        scanf("%d", &data);
        removeData(data);
        break;
      case OPT_EXIT:
        break;
      default:
        printf("Option invalid\nTry again\n");
    }
  }

  finalize(start);

  return EXIT_SUCCESS;
}

int menu() {
  int option = 0;
  printf("\nChoose an option:\n");
  printf("%d - Add a Data\n", OPT_ADD);
  printf("%d - Remove a Data\n", OPT_REMOVE);
  printf("%d - Exit\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

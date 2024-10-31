// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
enum {
  OPT_DESSELECT,
  OPT_ADD,
  OPT_REMOVE,
  OPT_SHOW_FIRST_TO_LAST,
  OPT_SHOW_LAST_TO_FIRST,
  OPT_EXIT,
};

int menu();
void showFirstToLast();
void showLastToFirst();

int main(int argc, char *argv[]) {
  int op = OPT_DESSELECT;
  int data = 0;

  initialize();

  while (op != OPT_EXIT) {
    op = menu();
    switch (op) {
      case OPT_ADD:
        printf("Enter a number: ");
        scanf("%d", &data);
        addNewData(data);
        break;
      case OPT_REMOVE:
        printf("Enter a number: ");
        scanf("%d", &data);
        removeItem(data);
        break;
      case OPT_SHOW_FIRST_TO_LAST:
        showFirstToLast();
        break;
      case OPT_SHOW_LAST_TO_FIRST:
        showLastToFirst();
        break;
      case OPT_EXIT:
        break;
      default:
        printf("Option invalid\nTry again\n");
    }
  }

  terminator(start);

  return EXIT_SUCCESS;
}

int menu() {
  int option = 0;
  printf("\nChoose an option:\n");
  printf("%d - Add a Data\n", OPT_ADD);
  printf("%d - Remove a Data\n", OPT_REMOVE);
  printf("%d - Show ascendent data\n", OPT_SHOW_FIRST_TO_LAST);
  printf("%d - Show descendent data\n", OPT_SHOW_LAST_TO_FIRST);
  printf("%d - Exit\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

void showFirstToLast() {
  int data;
  toBeginning();
  do {
    if (getCurrent(&data)) {
      printf("%d ", data);
    }
  } while (toNext());
  printf("\n ");
}

void showLastToFirst() {
  int data;
  toEnd();
  do {
    if (getCurrent(&data)) {
      printf("%d ", data);
    }
  } while (toPrevious());
  printf("\n ");
}

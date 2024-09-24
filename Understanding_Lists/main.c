// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

enum {
  OPT_DESSELECT,
  OPT_ADD,
  OPT_REMOVE,
  OPT_SET,
  OPT_SORT,
  OPT_SEARCHINDEX,
  OPT_SEARCHVALUE,
  OPT_SHOWLIST,
  OPT_EXIT,
};

int menu();

int main(int argc, char *argv[]) {
  int removed_from_list = 0;
  int value, index;
  int op = 0;
  printf("Simple Lists inside an array");
  while (op != OPT_EXIT) {
    op = menu();
    switch (op) {
      case OPT_ADD:
        printf("Please, insert a number to add to the list: \n");
        scanf("%d", &value);
        list_add(value);
        break;
      case OPT_REMOVE:
        printf("Please, insert an index: \n");
        scanf("%d", &index);
        if (!list_delete(&removed_from_list, index)) {
          printf("Try again\n\n");
        }
        break;
      case OPT_SET:
        printf("Please, insert an index: \n");
        scanf("%d", &index);
        printf("Now, insert a new value for the chosen index\n");
        scanf("%d", &value);
        list_set(index, value);
        break;
      case OPT_SORT:
        list_sort();
        break;
      case OPT_SEARCHINDEX:
        printf("Please, insert an index: \n");
        scanf("%d", &index);
        if (!list_search_index(index)) {
          printf("Couldn't search \n");
        }
        break;
      case OPT_SEARCHVALUE:
        printf("Please, insert an value: \n");
        scanf("%d", &value);
        if (!list_search_value(value)) {
          printf("Couldn't find the value\n");
        }
        break;
      case OPT_SHOWLIST:
        list_show();
        break;
      case OPT_EXIT:
        break;
      default:
        printf("Option not found, please try again\n");
        break;
    }
  }

  return EXIT_SUCCESS;
}

int menu() {
  int option = 0;
  printf("\nChoose an option:\n");
  printf("%d - Add to List\n", OPT_ADD);
  printf("%d - Remove from List\n", OPT_REMOVE);
  printf("%d - Update a value\n", OPT_SET);
  printf("%d - Sort the list\n", OPT_SORT);
  printf("%d - Search via index\n", OPT_SEARCHINDEX);
  printf("%d - Search via value\n", OPT_SEARCHVALUE);
  printf("%d - Show list\n", OPT_SHOWLIST);
  printf("%d - Exit\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

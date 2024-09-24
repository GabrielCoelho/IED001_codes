// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "list.h"

#include <stdbool.h>
#include <stdio.h>

int my_list[HIGHEST];
int* list_pointer = &my_list[0];
int reference = 0;
bool is_empty = true;

int list_size() { return reference; }

bool list_add(int number) {
  if (reference == HIGHEST) {
    printf("Couldn't add due to list is full\n");
    return false;
  }
  *list_pointer = number;
  reference++;
  if (reference != HIGHEST) {
    list_pointer++;
  }
  is_empty = false;
  return true;
}

bool list_delete(int* remove) {
  if (is_empty) {
    printf("Couldn't remove due to list is empty \n");
    return false;
  }
  *remove = *list_pointer;
  reference--;
  if (reference == 0) {
    is_empty = true;
  } else {
    list_pointer--;
  }
  return true;
}

bool list_search_index(int index) {
  if (index > reference || index <= 0) {
    printf(
        "Couldn't search due: index provided doesn't match the number of "
        "elements\n");
    return false;
  }
  printf("Index: %d\nElement: %d\n\n", index, my_list[index - 1]);
  return true;
}
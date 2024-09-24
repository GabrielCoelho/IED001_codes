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

bool list_delete(int* remove, int index) {
  int aux;
  if (is_empty) {
    printf("Couldn't remove due to list is empty \n");
    return false;
  }
  if (index > reference || index <= 0) {
    printf(
        "Couldn't remove due: index provided doesn't match the number of "
        "elements\n");
    return false;
  }
  *remove = my_list[index - 1];
  for (int i = index - 1; i < reference - 1; i++) {
    aux = my_list[i];
    my_list[i] = my_list[i + 1];
    my_list[i + 1] = aux;
  }
  reference--;
  if (reference == 0) {
    is_empty = true;
  } else {
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

bool list_search_value(int value) {
  bool found = false;
  if (is_empty) {
    printf("Couldn't search because list is empty\n");
    return false;
  }
  for (int i = 0; i < reference; i++) {
    if (my_list[i] == value) {
      printf("Element: %d\nIndex: %d\n\n", value, i + 1);
      found = true;
    }
  }
  if (found) {
    return true;
  }
  return false;
}

bool list_set(int index, int value) {
  if (!list_search_index(index)) {
    printf("Couldn't set other value \n");
    return false;
  }
  my_list[index - 1] = value;
  return true;
}

void list_sort() {
  int aux = 0;
  for (int i = 0; i < reference - 1; i++) {
    for (int j = i + 1; j <= reference; j++) {
      if (my_list[i] > my_list[j]) {
        aux = my_list[i];
        my_list[i] = my_list[j];
        my_list[j] = aux;
      }
    }
  }
}

void list_show() {
  if (!is_empty) {
    for (int i = 0; i < reference; i++) {
      printf("| %d | ", my_list[i]);
    }
  }
}

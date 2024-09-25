// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "../Assignment_Lists/list.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// int list_pointer[HIGHEST];

int HIGHEST = 5;
struct Data *list_pointer;
int reference = 0;
bool is_empty = true;

bool initialize() {
  list_pointer = malloc(HIGHEST * sizeof(*list_pointer));
  if (!list_pointer) {
    return false;
  }
  return true;
}

bool check_doops_cpf(int cpf) {
  if (is_empty) {
    return false;
  }
  for (int i = 0; i < reference; i++) {
    if (list_pointer[i].cpf == cpf) {
      return false;
    }
  }
  return true;
}

int list_size() { return reference; }

bool list_add(char *data_name, char *data_address, int data_cpf, int data_phone,
              char *data_email) {
  if (reference == HIGHEST) {
    list_resize();
  }
  if (!check_doops_cpf(data_cpf)) {
    printf("CPF Already listed\n ");
    return false;
  }
  strcpy(list_pointer[reference].name, data_name);
  strcpy(list_pointer[reference].address, data_address);
  strcpy(list_pointer[reference].email, data_email);
  list_pointer[reference].cpf = data_cpf;
  list_pointer[reference].phone_number = data_phone;
  reference++;
  is_empty = false;
  return true;
}

bool list_delete(int *remove, int value) {
  int aux = list_search_value(value);
  if (is_empty) {
    printf("Couldn't remove due to list is empty \n");
    return false;
  }
  if (aux > reference || aux < 0) {
    printf(
        "Couldn't remove due: index provided doesn't match the number of "
        "elements\n");
    return false;
  }
  *remove = list_pointer[aux];
  for (int i = aux; i < reference - 1; i++) {
    list_pointer[i] = list_pointer[i + 1];
  }
  reference--;
  if (reference == 0) {
    is_empty = true;
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
  printf("Index: %d\nElement: %d\n\n", index, list_pointer[index - 1]);
  return true;
}

int list_search_value(int value) {
  if (!is_empty) {
    for (int i = 0; i < reference; i++) {
      if (list_pointer[i] == value) {
        // printf("Element: %d\nIndex: %d\n\n", value, i + 1);
        return i;
      }
    }
  }
  return -1;
}

bool list_set(char *data_name, char *data_address, int data_cpf, int data_phone,
              char *data_email) {
  if (!list_search_index(data_cpf)) {
    printf("Couldn't set other value \n");
    return false;
  }
  list_pointer[index - 1] = value;
  return true;
}

void list_sort() {
  int aux = 0;
  for (int i = 0; i < reference - 1; i++) {
    for (int j = i + 1; j < reference; j++) {
      if (list_pointer[i] > list_pointer[j]) {
        aux = list_pointer[i];
        list_pointer[i] = list_pointer[j];
        list_pointer[j] = aux;
      }
    }
  }
}

void list_show() {
  if (!is_empty) {
    for (int i = 0; i < reference; i++) {
      printf("| %d | ", list_pointer[i]);
    }
  } else {
    printf("List is empty\n");
  }
}

void list_resize() {
  HIGHEST += HIGHEST / 2;
  int *aux = malloc(HIGHEST * sizeof(struct Data));
  for (int i = 0; i < reference; i++) {
    aux[i] = list_pointer[i];
  }
  free(list_pointer);
  list_pointer = aux;
}

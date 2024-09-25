// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "../Assignment_Lists/list.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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

bool list_delete(struct Data *removed, int data_cpf) {
  int aux = list_search_value(data_cpf);
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
  *removed = list_pointer[aux];
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

// will only search CPF
int list_search_value(int data_cpf) {
  if (!is_empty) {
    for (int i = 0; i < reference; i++) {
      if (list_pointer[i].cpf == data_cpf) {
        // printf("Element: %d\nIndex: %d\n\n", value, i + 1);
        return i;
      }
    }
  }
  return -1;
}

void list_set(int index) {
  char name[40], address[100], email[60];
  int phone, cpf;
  bool not_name, not_address, not_phone, not_cpf, not_email;
  printf("Insert a new value or just press enter: \n");
  printf("Name: %s\nNew value: ", list_pointer[index].name);
  if (getchar() != '\n') {
    scanf("%s", name);
    fflush(stdin);
    not_name = true;
  }
  printf("CPF: %d\n", list_pointer[index].cpf);
  if (getchar() != '\n') {
    scanf("%d", &cpf);
    fflush(stdin);
    not_cpf = true;
  }
  printf("Address: %s\nInsert a new value or just press enter: ",
         list_pointer[index].address);
  if (getchar() != '\n') {
    scanf("%s", address);
    fflush(stdin);
    not_address = true;
  }
  printf("Phone Number: %d\nInsert a new value or just press enter: ",
         list_pointer[index].phone_number);
  if (getchar() != '\n') {
    scanf("%d", &phone);
    fflush(stdin);
    not_phone = true;
  }
  printf("Email: %s\nInsert a new value or just press enter: ",
         list_pointer[index].email);
  if (getchar() != '\n') {
    scanf("%s", email);
    fflush(stdin);
    not_email = true;
  }

  if (not_name) strcpy(list_pointer[index].name, name);
  if (not_address) strcpy(list_pointer[index].address, address);
  if (not_email) strcpy(list_pointer[index].email, email);
  if (not_phone) list_pointer[index].phone_number = phone;
  if (not_cpf) list_pointer[index].cpf = cpf;
}

void list_sort() {
  struct Data aux;
  for (int i = 0; i < reference - 1; i++) {
    for (int j = i + 1; j < reference; j++) {
      if (strcmp(list_pointer[i].name, list_pointer[j].name) > 0) {
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
      printf("Name: %s\t", list_pointer[i].name);
      printf("CPF: %d\n", list_pointer[i].cpf);
      printf("Address: %s\n", list_pointer[i].address);
      printf("Phone: %d\t", list_pointer[i].phone_number);
      printf("Email: %s\n", list_pointer[i].email);
    }
    printf("\n\n");
  } else {
    printf("List is empty\n");
  }
}

void list_resize() {
  HIGHEST += HIGHEST / 2;
  struct Data *aux = malloc(HIGHEST * sizeof(struct Data));
  for (int i = 0; i < reference; i++) {
    aux[i] = list_pointer[i];
  }
  free(list_pointer);
  list_pointer = aux;
}

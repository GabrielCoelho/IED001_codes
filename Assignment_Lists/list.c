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

bool check_doops_cpf(char cpf) {
  for (int i = 0; i < reference; i++) {
    printf("%s\n%s\n", list_pointer[i].cpf, &cpf);
    if (strcmp(list_pointer[i].cpf, &cpf) == 0) {
      return false;
    }
  }
  return true;
}

int list_size() { return reference; }

bool list_add(char *data_name, char *data_address, char *data_cpf,
              char *data_phone, char *data_email) {
  if (reference == HIGHEST) {
    list_resize();
  }
  if (!check_doops_cpf(*data_cpf)) {
    printf("CPF Already listed\n ");
    return false;
  }
  strcpy(list_pointer[reference].name, data_name);
  strcpy(list_pointer[reference].address, data_address);
  strcpy(list_pointer[reference].email, data_email);
  strcpy(list_pointer[reference].phone_number, data_phone);
  strcpy(list_pointer[reference].cpf, data_cpf);
  reference++;
  is_empty = false;
  return true;
}

bool list_delete(struct Data *removed, char *data_cpf) {
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
  printf("Index: %d\nElement: %s\n\n", index, list_pointer[index - 1]);
  return true;
}

// will only search CPF
int list_search_value(char *data_cpf) {
  if (!is_empty) {
    for (int i = 0; i < reference; i++) {
      if (strcmp(list_pointer[i].cpf, data_cpf) == 0) {
        printf("Element: %s\nIndex: %d\n\n", list_pointer[i].cpf, i + 1);
        return i;
      }
    }
  }
  return -1;
}

void list_set(int index) {
  char name[40], address[100], email[60], phone[14], check_cpf[12];
  int cpf;
  bool not_name, not_address, not_phone, not_cpf, not_email;
  printf("Insert a new value or just press enter: \n");
  printf("Name: %s\nNew value: ", list_pointer[index].name);
  read_line(name, 39);
  name[strcspn(name, "\n")] = '\0';
  if (strlen(name) > 0) {
    strcpy(list_pointer[index].name, name);
  }

  printf("CPF: %s\n", list_pointer[index].cpf);
  read_line(check_cpf, 12);
  check_cpf[strcspn(check_cpf, "\n")] = '\0';
  if (strlen(check_cpf) > 0) {
    strcpy(list_pointer[index].cpf, check_cpf);
  }
  printf("Address: %s\nInsert a new value or just press enter: ",
         list_pointer[index].address);
  read_line(address, 39);
  address[strcspn(address, "\n")] = '\0';
  if (strlen(address) > 0) {
    strcpy(list_pointer[index].address, address);
  }
  printf("Phone Number: %s\nInsert a new value or just press enter: ",
         list_pointer[index].phone_number);
  read_line(phone, 39);
  phone[strcspn(phone, "\n")] = '\0';
  if (strlen(phone) > 0) {
    strcpy(list_pointer[index].phone_number, phone);
  }
  printf("Email: %s\nInsert a new value or just press enter: ",
         list_pointer[index].email);
  read_line(email, 39);
  email[strcspn(email, "\n")] = '\0';
  if (strlen(email) > 0) {
    strcpy(list_pointer[index].email, email);
  }
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
      printf("CPF: %s\n", list_pointer[i].cpf);
      printf("Address: %s\n", list_pointer[i].address);
      printf("Phone: %s\t", list_pointer[i].phone_number);
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

void read_line(char *input_buffer, int length) {
  if (fgets(input_buffer, length, stdin) != NULL) {
    if (strlen(input_buffer) > 0 &&
        input_buffer[strlen(input_buffer) - 1] == '\n') {
      input_buffer[strlen(input_buffer) - 1] = '\0';
    } else {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }
  }
}

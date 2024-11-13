// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "config.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "btree.h"

int regi = 0;

void initializer() {
  initialize_btree();
  initialize_dlist();
  initialize_list();
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

bool addNewItem(char cpf[]) {
  char name[40], address[100], email[60], phone[14];
  if (localize_btree(*cpf, btree_start) != NULL || btree_start == NULL) {
    addNewData_btree(newData_btree(cpf), btree_start);
    regi = regi + 1;
    printf("Name: ");
    read_line(name, 40);
    printf("Address: ");
    read_line(address, 100);
    printf("Phone Number: ");
    read_line(phone, 14);
    printf("Email: ");
    read_line(email, 60);

    addNewData_dlist(*cpf);
    list_add(name, address, cpf, phone, email);

    return true;
  }
  return false;
}

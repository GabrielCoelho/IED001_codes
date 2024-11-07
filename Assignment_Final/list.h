// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Database {
  char cpf[11];
  char name[60];
  char address[100];
  char phone_number[13];
  char email[60];
  struct Database *next;
};

extern int HIGHEST;
extern struct Database *list_pointer;
extern int reference;
extern bool is_empty;

bool check_doops_cpf(char cpf);
bool initialize();
int list_size();
bool list_add(char *data_name, char *data_address, char *data_cpf,
              char *data_phone, char *data_email);
bool list_delete(struct Database *removed, char *data_cpf);
bool list_search_index(int index);
int list_search_value(char *data_cpf);
void list_sort();
void list_resize();
void list_set(int index);
void list_show();

#endif  // !LIST_H

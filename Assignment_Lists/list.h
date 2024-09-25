// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LIST_H
#define LIST_H

struct Data {
  char name[40];
  char address[100];
  int cpf;
  int phone_number;
  char email[60];
};

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern int HIGHEST;
extern struct Data *list_pointer;
extern int reference;
extern bool is_empty;

bool check_doops_cpf(int cpf);
bool initialize();
int list_size();
bool list_add(char *data_name, char *data_address, int data_cpf, int data_phone,
              char *data_email);
bool list_delete(struct Data *removed, int data_cpf);
bool list_search_index(int index);
int list_search_value(int data_cpf);
void list_sort();
void list_resize();
bool list_set(char *data_name, char *data_address, int data_cpf, int data_phone,
              char *data_email);
void list_show();

#endif  // !LIST_H

// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef BTREE_H
#define BTREE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PKey {
  int register_number;
  char cpf[11];
  struct PKey *left;
  struct PKey *right;
};

extern struct PKey *btree_start;
extern struct PKey *btree_newPointer;
extern struct PKey *btree_aux;
extern struct PKey *btree_prev;
extern struct PKey *btree_current;

void initialize_btree();
void finalize_btree(struct PKey *who);
struct PKey *localize_btree(char cpf_searched, struct PKey *where);
struct PKey *newData_btree(char cpf[]);
void addNewData_btree(struct PKey *who, struct PKey *where);
void removeData_btree(char cpf);

#endif  // BTREE_H!

// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef BTREE_H
#define BTREE_H

#include "config.h"

extern struct PKey *start;
extern struct PKey *newPointer;
extern struct PKey *aux;
extern struct PKey *prev;
extern struct PKey *current;

void initialize();
void finalize(struct PKey *who);
struct PKey *localize(char cpf_searched, struct PKey *where);
struct PKey *newData(char cpf);
void addNewData(struct PKey *who, struct PKey *where);
void removeData(char cpf);

#endif  // BTREE_H!

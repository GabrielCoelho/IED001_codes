// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef CONFIG_H
#define CONFIG_H

#include "btree.h"
#include "linkedList.h"
#include "list.h"

extern int regi;

void initializer();
void read_line(char *input_buffer, int length);
bool addNewItem(char cpf[]);

#endif  // !CONFIG_H

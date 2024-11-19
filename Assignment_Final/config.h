// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef CONFIG_H
#define CONFIG_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "btree.h"
#include "linkedList.h"
#include "list.h"

extern int regi;

void initializer();
void terminatorAll();
void read_line(char *input_buffer, int length);
bool addNewItem(char cpf[]);
bool search_cpf(char cpf[]);

#endif  // !CONFIG_H

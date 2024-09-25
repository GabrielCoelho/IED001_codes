// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern int HIGHEST;
extern int* list_pointer;
extern int reference;
extern bool is_empty;

bool initialize();
int list_size();
bool list_add(int number);
bool list_delete(int* remove, int index);
bool list_search_index(int index);
bool list_search_value(int value);
void list_sort();
void list_resize();
bool list_set(int index, int value);
void list_show();

#endif  // !LIST_H

// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum { HIGHEST = 5 };

int extern my_list[];
int extern reference;

int list_size();
bool list_add(int number);
bool list_delete(int* remove);
bool list_search_index(int index);
bool list_search_value(int value);
bool list_sort();
bool list_expand();
bool list_set();

#endif  // !LIST_H

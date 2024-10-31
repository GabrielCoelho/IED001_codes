// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct linkedList {
  int data;
  struct linkedList *next;
};

extern struct linkedList *start;
extern struct linkedList *end;
extern struct linkedList *newPointer;
extern struct linkedList *aux;
extern struct linkedList *prev;
extern struct linkedList *current;

struct linkedList *newData(int data);
void addNewData(int data);
void addAtStart();
void addAtEnd();
void addInTheMiddle();

#endif  // !LINKEDLIST_H

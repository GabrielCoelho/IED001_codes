// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>

struct linkedList *start = NULL;
struct linkedList *end = NULL;
struct linkedList *aux = NULL;
struct linkedList *prev = NULL;
struct linkedList *current = NULL;

struct linkedList *newData(int data) {
  struct linkedList *newNode = malloc(sizeof(struct linkedList));
  if (!newNode) {
    printf("Couldn't allocate any memory\nExiting...\n ");
    EXIT_FAILURE;
  }

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

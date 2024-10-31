// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>

struct linkedList *start = NULL;
struct linkedList *end = NULL;
struct linkedList *newPointer = NULL;
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

void addNewData(int data) {
  newPointer = newData(data);

  if (start == NULL) {
    start = newPointer;
    end = newPointer;
  } else {
    if (newPointer->data < start->data) {
      addAtStart();
    } else {
      aux = start;
      prev = start;
      while (aux->data < newPointer->data && aux->next != NULL) {
        prev = aux;
        aux = aux->next;
      }
      if (newPointer->data > aux->data) {
        addAtEnd();
      } else {
        addInTheMiddle();
      }
    }
  }
}

void addAtStart() {
  newPointer->next = start;
  start = newPointer;
}

void addAtEnd() {
  end->next = newPointer;
  end = newPointer;
}

void addInTheMiddle() {
  newPointer->next = aux;
  prev->next = newPointer;
}

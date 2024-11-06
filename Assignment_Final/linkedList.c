// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ordering *start = NULL;
struct Ordering *end = NULL;
struct Ordering *newPointer = NULL;
struct Ordering *aux = NULL;
struct Ordering *prev = NULL;
struct Ordering *current = NULL;

struct Ordering *newData(char data) {
  struct Ordering *newNode = malloc(sizeof(struct Ordering));
  if (!newNode) {
    printf("Couldn't allocate any memory\nExiting...\n ");
    EXIT_FAILURE;
  }

  newNode->prev = NULL;
  strcpy(newNode->name, &data);
  newNode->next = NULL;
  return newNode;
}

void addNewData(char data) {
  newPointer = newData(data);

  // If my start is NULL, the list is empty, so I just start the list by adding
  // the pointers of start and end at the same new data pointer.
  if (start == NULL) {
    start = newPointer;
    end = newPointer;
  } else {
    // Since lists are always in the ascendent order, if my new data is lesser
    // than the start data, I must add it at the start.
    if (strcmp(newPointer->name, start->name) < 0) {
      addAtStart();
    } else {
      // here, I need to set an auxiliar pointer and a "previous" pointer to the
      // start, and go thru my list, checking if the auxiliar data is greater
      // than my new data.
      aux = start;
      prev = start;
      while (strcmp(aux->name, newPointer->name) < 0 && aux->next != NULL) {
        prev = aux;
        aux = aux->next;
      }
      // once is done, we check again to see if we need to add the new data at
      // the end (so, if the new data is greater than the auxiliar data), or in
      // the middle.
      if (strcmp(newPointer->name, aux->name) > 0) {
        addAtEnd();
      } else {
        addInTheMiddle();
      }
    }
  }
}

void addAtStart() {
  newPointer->next = start;
  start->prev = newPointer;
  start = newPointer;
}

void addAtEnd() {
  end->next = newPointer;
  newPointer->prev = end;
  end = newPointer;
}

void addInTheMiddle() {
  newPointer->next = aux;
  newPointer->prev = prev;
  prev->next = newPointer;
  aux->prev = newPointer;
}

void initialize() {
  start = NULL;
  end = NULL;
}

void terminator(struct Ordering *who) {
  if (who == NULL) {
    return;
  }
  if (who->next != NULL) {
    terminator(who->next);
  }
  free(who);
}

char *peekFirst() { return start->name; }

char *peekLast() { return end->name; }

void toBeginning() { current = start; }

void toEnd() { current = end; }

bool toNext() {
  if (current == NULL || current->next == NULL) {
    return false;
  }
  current = current->next;
  return true;
}

bool toPrevious() {
  if (current == NULL || current->prev == NULL) {
    return false;
  }
  current = current->prev;
  return true;
}

bool getCurrent(char *ext_data) {
  if (current != NULL) {
    strcpy(ext_data, current->name);
    return true;
  }
  return false;
}

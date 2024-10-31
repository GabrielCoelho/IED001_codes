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

  // If my start is NULL, the list is empty, so I just start the list by adding
  // the pointers of start and end at the same new data pointer.
  if (start == NULL) {
    start = newPointer;
    end = newPointer;
  } else {
    // Since lists are always in the ascendent order, if my new data is lesser
    // than the start data, I must add it at the start.
    if (newPointer->data < start->data) {
      addAtStart();
    } else {
      // here, I need to set an auxiliar pointer and a "previous" pointer to the
      // start, and go thru my list, checking if the auxiliar data is greater
      // than my new data.
      aux = start;
      prev = start;
      while (aux->data < newPointer->data && aux->next != NULL) {
        prev = aux;
        aux = aux->next;
      }
      // once is done, we check again to see if we need to add the new data at
      // the end (so, if the new data is greater than the auxiliar data), or in
      // the middle.
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

void removeItem(int data) {
  if (start == NULL) {
    return;
  }
  if (start->data == data) {
    removeAtStart();
  } else {
    aux = start;
    prev = start;
    while (aux->data != data && aux->next != NULL) {
      prev = aux;
      aux = aux->next;
    }
    if (aux->data == data) {
      if (aux->next == NULL) {
        removeAtEnd();
      } else {
        removeInTheMiddle();
      }
    }
  }
}

void removeAtStart() {
  if (start->next == NULL) {
    free(start);
    start = NULL;
  } else {
    aux = start;
    start = start->next;
    free(aux);
  }
}

void removeAtEnd() {
  prev->next = NULL;
  free(end);
  end = prev;
}

void removeInTheMiddle() {
  prev->next = aux->next;
  free(aux);
}

void initialize() {
  start = NULL;
  end = NULL;
}

void terminator(struct linkedList *who) {
  if (who == NULL) {
    return;
  }
  if (who->next != NULL) {
    terminator(who->next);
  }
  free(who);
}

int peekFirst() { return start->data; }

int peekLast() { return end->data; }

void toBeginning() { current = start; }

bool toNext() {
  if (current == NULL || current->next == NULL) {
    return false;
  }
  current = current->next;
  return true;
}

bool getCurrent(int *ext_data) {
  if (current != NULL) {
    *ext_data = current->data;
    return true;
  }
  return false;
}

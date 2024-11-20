// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

struct Ordering *start_dlist = NULL;
struct Ordering *end_dlist = NULL;
struct Ordering *newPointer_dlist = NULL;
struct Ordering *aux_dlist = NULL;
struct Ordering *prev_dlist = NULL;
struct Ordering *current_dlist = NULL;

struct Ordering *newData(char data) {
  struct Ordering *newNode = malloc(sizeof(struct Ordering));
  if (!newNode) {
    printf("Couldn't allocate any memory\nExiting...\n ");
    EXIT_FAILURE;
  }

  newNode->prev = NULL;
  newNode->register_number = regi;
  strcpy(newNode->name, &data);
  newNode->next = NULL;
  return newNode;
}

void addNewData_dlist(char data) {
  newPointer_dlist = newData(data);

  // If my start is NULL, the list is empty, so I just start the list by adding
  // the pointers of start and end_dlist at the same new data pointer.
  if (start_dlist == NULL) {
    start_dlist = newPointer_dlist;
    end_dlist = newPointer_dlist;
  } else {
    // Since lists are always in the ascend_dlistent order, if my new data is
    // lesser than the start data, I must add it at the start.
    if (strcmp(newPointer_dlist->name, start_dlist->name) < 0) {
      addAtStart();
    } else {
      // here, I need to set an aux_dlistiliar pointer and a "previous" pointer
      // to the start, and go thru my list, checking if the aux_dlistiliar data
      // is greater than my new data.
      aux_dlist = start_dlist;
      prev_dlist = start_dlist;
      while (strcmp(aux_dlist->name, newPointer_dlist->name) < 0 &&
             aux_dlist->next != NULL) {
        prev_dlist = aux_dlist;
        aux_dlist = aux_dlist->next;
      }
      // once is done, we check again to see if we need to add the new data at
      // the end_dlist (so, if the new data is greater than the aux_dlistiliar
      // data), or in the middle.
      if (strcmp(newPointer_dlist->name, aux_dlist->name) > 0) {
        addAtEnd();
      } else {
        addInTheMiddle();
      }
    }
  }
}

void addAtStart() {
  newPointer_dlist->next = start_dlist;
  start_dlist->prev = newPointer_dlist;
  start_dlist = newPointer_dlist;
}

void addAtEnd() {
  end_dlist->next = newPointer_dlist;
  newPointer_dlist->prev = end_dlist;
  end_dlist = newPointer_dlist;
}

void addInTheMiddle() {
  newPointer_dlist->next = aux_dlist;
  newPointer_dlist->prev = prev_dlist;
  prev_dlist->next = newPointer_dlist;
  aux_dlist->prev = newPointer_dlist;
}

void initialize_dlist() {
  start_dlist = NULL;
  end_dlist = NULL;
}

void terminator_dlist(struct Ordering *who) {
  if (who == NULL) {
    return;
  }
  if (who->next != NULL) {
    terminator_dlist(who->next);
  }
  free(who);
}

char *peekFirst() { return start_dlist->name; }

char *peekLast() { return end_dlist->name; }

void toBeginning() { current_dlist = start_dlist; }

void toEnd() { current_dlist = end_dlist; }

bool toNext() {
  if (current_dlist == NULL || current_dlist->next == NULL) {
    return false;
  }
  current_dlist = current_dlist->next;
  return true;
}

bool toPrevious() {
  if (current_dlist == NULL || current_dlist->prev == NULL) {
    return false;
  }
  current_dlist = current_dlist->prev;
  return true;
}

bool getcurrent_dlist(char ext_data) {
  if (current_dlist != NULL) {
    strcpy(&ext_data, current_dlist->name);
    return true;
  }
  return false;
}

void showFirstToLast() {
  char data[100];
  toBeginning();
  do {
    if (getcurrent_dlist(*data)) {
      printf("%s\n", data);
    }
  } while (toNext());
  printf("\n ");
}

// Copyright 2024 Gabriel Coelho Soares

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct MY_STACK *top = NULL;
struct MY_STACK *aux;

void push(int number) {
  struct MY_STACK *new_item = malloc(sizeof(*new_item));
  new_item->num = number;
  new_item->next = top;
  top = new_item;
  printf("Inserted %d at the Stack\n", new_item->num);
}

bool pop(int *number) {
  if (top == NULL) {
    printf("Empty Stack!\n\n");
    return false;
  }
  aux = top;
  printf("%d Removed from Stack", top->num);
  *number = top->num;
  top = top->next;
  free(aux);
  return true;
}

void show() {
  if (top == NULL) {
    printf("Empty Stack!\n\n");
  } else {
    aux = top;
    printf("Consulting all the stack\n");
    while (aux != NULL) {
      printf("%d\n", aux->num);
      aux = aux->next;
    }
  }
}

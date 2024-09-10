// Copyright 2024 Gabriel Coelho Soares

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

struct MY_QUEUE *start = NULL;
struct MY_QUEUE *end = NULL;
struct MY_QUEUE *aux;

void push(int number) {
  struct MY_QUEUE *new_item = malloc(sizeof(*new_item));
  new_item->num = number;
  new_item->next = NULL;
  if (start == NULL) {
    start = new_item;
    end = new_item;
  } else {
    end->next = new_item;
    end = new_item;
  }
  printf("%d Inserted at the queue\n", new_item->num);
}

bool pop(int *number) {
  if (start == NULL) {
    printf("Empty Queue\n");
    return false;
  }
  aux = start;
  printf("Number %d removed from the queue\n", start->num);
  start = start->next;
  free(aux);
}

void show() {
  if (start == NULL) {
    printf("Empty Queue\n");
  } else {
    printf("Consulting all the queue\n");
    aux = start;
    while (aux != NULL) {
      printf("%d\n", aux->num);
      aux = aux->next;
    }
  }
}

// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "btree.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct BTree *start;
struct BTree *newPointer;
struct BTree *aux;
struct BTree *prev;
struct BTree *current;

void initialize() { start = NULL; }

void finalize(struct BTree *who) {
  if (start == NULL) {
    return;
  }
  if (who->left != NULL) {
    printf("Removing the left node from %d\n", who->data);
    finalize(who->left);
  }
  if (who->right != NULL) {
    printf("Removing the right node from %d\n", who->data);
    finalize(who->right);
  }
  printf("Removing node of data = %d\n", who->data);
  free(who);
}

struct BTree *localize(int data, struct BTree *where) {
  if (start == NULL) {
    return NULL;
  }

  if (data == where->data) {
    return where;
  } else {
    prev = where;
    if (data > where->data) {
      if (where->right == NULL) {
        return NULL;
      } else {
        printf("Going to the right of %d\n", where->data);
        return localize(data, where->right);
      }
    } else if (data < where->data) {
      if (where->left == NULL) {
        return NULL;
      } else {
        printf("Going to the left of %d\n", where->data);
        return localize(data, where->left);
      }
    }
  }
}

struct BTree *newData(int data) {
  struct BTree *new = malloc(sizeof(struct BTree));
  if (!new) {
    printf("Error in memory allocation\n");
    return EXIT_FAILURE;
  }

  new->right = NULL;
  new->left = NULL;
  new->data = data;

  return new;
}

void addNewData(struct BTree *who, struct BTree *where) {
  if (start == NULL) {
    printf("Adding at the start\n ");
    start = who;
  } else {
    if (who->data > where->data) {
      printf("Going right of node %d\n", where->data);
      // right
      if (where->right == NULL) {
        printf("Adding on the right of node %d\n", where->data);
        where->right = who;
      } else {
        printf("Going towards node %d\n", where->right->data);
        addNewData(who, where->right);
      }
    }

    if (who->data < where->data) {
      // left
      printf("Going left of node %d\n", where->data);
      if (where->left == NULL) {
        printf("Adding on the left of node %d\n", where->data);
        where->left = who;
      } else {
        printf("Going towards node %d\n", where->left->data);
        addNewData(who, where->left);
      }
    }
  }
}

void removeData(int data) {
  if (start == NULL) {
    return;
  }

  aux = localize(data, start);
  if (aux == NULL) {
    return;
  }

  if (aux == start) {
    start = NULL;
  } else {
    if (data > prev->data) {
      prev->right = NULL;
    } else {
      prev->left = NULL;
    }
  }
  if (aux->left != NULL) {
    addNewData(aux->left, start);
  }
  if (aux->right != NULL) {
    addNewData(aux->right, start);
  }

  printf("Removing %d", aux->data);
  free(aux);
}

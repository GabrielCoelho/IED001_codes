// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "btree.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PKey *start;
struct PKey *newPointer;
struct PKey *aux;
struct PKey *prev;
struct PKey *current;

void initialize() { start = NULL; }

void finalize(struct PKey *who) {
  if (start == NULL) {
    return;
  }
  if (who->left != NULL) {
    printf("Removing the left node from %s\n", who->cpf);
    finalize(who->left);
  }
  if (who->right != NULL) {
    printf("Removing the right node from %s\n", who->cpf);
    finalize(who->right);
  }
  printf("Removing node of data = %s\n", who->cpf);
  free(who);
}

struct PKey *localize(char cpf_searched, struct PKey *where) {
  if (start == NULL) {
    return NULL;
  }

  if (strcmp(&cpf_searched, where->cpf) == 0) {
    return where;
  } else {
    prev = where;
    if (strcmp(&cpf_searched, where->cpf) > 0) {
      if (where->right == NULL) {
        return NULL;
      } else {
        printf("Going to the right of %s\n", where->cpf);
        return localize(cpf_searched, where->right);
      }
    } else if (strcmp(&cpf_searched, where->cpf) < 0) {
      if (where->left == NULL) {
        return NULL;
      } else {
        printf("Going to the left of %s\n", where->cpf);
        return localize(cpf_searched, where->left);
      }
    }
  }
}

struct PKey *newData(char cpf) {
  struct PKey *new = malloc(sizeof(struct PKey));
  if (!new) {
    printf("Error in memory allocation\n");
    return EXIT_FAILURE;
  }

  new->right = NULL;
  new->left = NULL;
  strcpy(new->cpf, &cpf);

  return new;
}

void addNewData(struct PKey *who, struct PKey *where) {
  if (start == NULL) {
    printf("Adding at the start\n ");
    start = who;
  } else {
    if (strcmp(who->cpf, where->cpf) > 0) {
      printf("Going right of node %s\n", where->cpf);
      // right
      if (where->right == NULL) {
        printf("Adding on the right of node %s\n", where->cpf);
        where->right = who;
      } else {
        printf("Going towards node %s\n", where->right->cpf);
        addNewData(who, where->right);
      }
    }

    if (strcmp(who->cpf, where->cpf) < 0) {
      // left
      printf("Going left of node %s\n", where->cpf);
      if (where->left == NULL) {
        printf("Adding on the left of node %s\n", where->cpf);
        where->left = who;
      } else {
        printf("Going towards node %s\n", where->left->cpf);
        addNewData(who, where->left);
      }
    }
  }
}

void removeData(char cpf) {
  if (start == NULL) {
    return;
  }

  aux = localize(cpf, start);
  if (aux == NULL) {
    return;
  }

  if (aux == start) {
    start = NULL;
  } else {
    if (strcmp(&cpf, aux->cpf) > 0) {
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

  printf("Removing %s", aux->cpf);
  free(aux);
}

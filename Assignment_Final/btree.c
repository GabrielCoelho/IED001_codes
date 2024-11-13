// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "btree.h"

struct PKey *btree_start;
struct PKey *btree_newPointer;
struct PKey *btree_aux;
struct PKey *btree_prev;
struct PKey *btree_current;

void initialize_btree() { btree_start = NULL; }

void finalize_btree(struct PKey *who) {
  if (btree_start == NULL) {
    return;
  }
  if (who->left != NULL) {
    printf("Removing the left node from %s\n", who->cpf);
    finalize_btree(who->left);
  }
  if (who->right != NULL) {
    printf("Removing the right node from %s\n", who->cpf);
    finalize_btree(who->right);
  }
  printf("Removing node of data = %s\n", who->cpf);
  free(who);
}

struct PKey *localize_btree(char cpf_searched, struct PKey *where) {
  if (btree_start == NULL) {
    return NULL;
  }

  if (strcmp(&cpf_searched, where->cpf) == 0) {
    printf("found!");
    return where;
  } else {
    btree_prev = where;
    if (strcmp(&cpf_searched, where->cpf) > 0) {
      if (where->right == NULL) {
        return NULL;
      } else {
        printf("Going to the right of %s\n", where->cpf);
        return localize_btree(cpf_searched, where->right);
      }
    } else if (strcmp(&cpf_searched, where->cpf) < 0) {
      if (where->left == NULL) {
        return NULL;
      } else {
        printf("Going to the left of %s\n", where->cpf);
        return localize_btree(cpf_searched, where->left);
      }
    }
  }

  return NULL;
}

struct PKey *newData_btree(char cpf[]) {
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

void addNewData_btree(struct PKey *who, struct PKey *where) {
  if (btree_start == NULL) {
    printf("Adding at the btree_start\n ");
    btree_start = who;
  } else {
    if (strcmp(who->cpf, where->cpf) > 0) {
      printf("Going right of node %s\n", where->cpf);
      // right
      if (where->right == NULL) {
        printf("Adding on the right of node %s\n", where->cpf);
        where->right = who;
      } else {
        printf("Going towards node %s\n", where->right->cpf);
        addNewData_btree(who, where->right);
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
        addNewData_btree(who, where->left);
      }
    }
  }
}

void removeData_btree(char cpf) {
  if (btree_start == NULL) {
    return;
  }

  btree_aux = localize_btree(cpf, btree_start);
  if (btree_aux == NULL) {
    return;
  }

  if (btree_aux == btree_start) {
    btree_start = NULL;
  } else {
    if (strcmp(&cpf, btree_aux->cpf) > 0) {
      btree_prev->right = NULL;
    } else {
      btree_prev->left = NULL;
    }
  }
  if (btree_aux->left != NULL) {
    addNewData_btree(btree_aux->left, btree_start);
  }
  if (btree_aux->right != NULL) {
    addNewData_btree(btree_aux->right, btree_start);
  }

  printf("Removing %s", btree_aux->cpf);
  free(btree_aux);
}

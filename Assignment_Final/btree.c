// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "btree.h"

#include "config.h"

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
    finalize_btree(who->left);
  }
  if (who->right != NULL) {
    finalize_btree(who->right);
  }
  free(who);
}

struct PKey *localize_btree(char cpf_searched[], struct PKey *where) {
  if (btree_start == NULL) {
    return NULL;
  }

  if (strcmp(cpf_searched, where->cpf) == 0) {
    return where;
  } else {
    btree_prev = where;
    if (strcmp(cpf_searched, where->cpf) > 0) {
      if (where->right == NULL) {
        return NULL;
      } else {
        return localize_btree(cpf_searched, where->right);
      }
    } else if (strcmp(cpf_searched, where->cpf) < 0) {
      if (where->left == NULL) {
        return NULL;
      } else {
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
  strcpy(new->cpf, cpf);
  new->register_number = regi;

  return new;
}

void addNewData_btree(struct PKey *who, struct PKey *where) {
  if (btree_start == NULL) {
    btree_start = who;
  } else {
    if (strcmp(who->cpf, where->cpf) > 0) {
      // right
      if (where->right == NULL) {
        where->right = who;
      } else {
        addNewData_btree(who, where->right);
      }
    }

    if (strcmp(who->cpf, where->cpf) < 0) {
      // left
      if (where->left == NULL) {
        where->left = who;
      } else {
        addNewData_btree(who, where->left);
      }
    }
  }
}

void removeData_btree(char cpf[]) {
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
    if (strcmp(cpf, btree_aux->cpf) > 0) {
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
  free(btree_aux);
}

int localize_btree_int(char cpf_searched[], struct PKey *where) {
  if (btree_start == NULL) {
    return -1;
  }

  if (strcmp(cpf_searched, where->cpf) == 0) {
    return where->register_number;
  } else {
    btree_prev = where;
    if (strcmp(cpf_searched, where->cpf) > 0) {
      if (where->right == NULL) {
        return -1;
      } else {
        return localize_btree_int(cpf_searched, where->right);
      }
    } else if (strcmp(cpf_searched, where->cpf) < 0) {
      if (where->left == NULL) {
        return -1;
      } else {
        return localize_btree_int(cpf_searched, where->left);
      }
    }
  }

  return -1;
}

// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#ifndef CONFIG_H
#define CONFIG_H

// Binary Tree
struct PKey {
  int register_number;
  char cpf[11];
  struct PKey *left;
  struct PKey *right;
};

// Dinamic List
struct Database {
  char cpf[11];
  char nome[60];
  char address[100];
  char telephone[13];
  char email[60];
  struct Database *next;
};

// Linked List
struct Ordering {
  int register_number;
  char nome[60];
  struct Database *next;
  struct Database *prev;
};

#endif  // !CONFIG_H

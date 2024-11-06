// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef BTREE_H
#define BTREE_H

struct BTree {
  struct BTree *left;
  int data;
  struct BTree *right;
};

extern struct BTree *start;
extern struct BTree *newPointer;
extern struct BTree *aux;
extern struct BTree *prev;
extern struct BTree *current;

void initialize();
void finalize(struct BTree *who);
struct BTree *localize(int data, struct BTree *where);
struct BTree *newData(int data);
void addNewData(struct BTree *who, struct BTree *where);
void removeData(int data);

#endif  // BTREE_H!

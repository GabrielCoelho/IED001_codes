#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// my Stack
struct MY_STACK {
  int num;
  struct MY_STACK* next;
};

void push(int number);
bool pop(int* number);
void show();
void alter(int number);      // @TODO
void search(int number);     // @TODO
void find_prev(int number);  // @TODO
void find_next(int number);  // @TODO

#endif  // !STACK_H

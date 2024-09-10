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
void alter(int number);
void search(int number);
void find_prev(int number);
void find_next(int number);

#endif  // !STACK_H

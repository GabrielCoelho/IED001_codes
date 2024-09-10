#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// My QUEUE
struct MY_QUEUE {
  int num;
  struct MY_QUEUE* next;
};

void push(int number);
bool pop(int* number);
void show();

#endif  // !QUEUE_H

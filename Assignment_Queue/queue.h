// Copyright «2024» Gabriel Coelho Soares
#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

enum { END_QUEUE = 5, START_QUEUE = 0, EMPTY = true, NOT_EMPTY = false };

// Variáveis
extern int vec_queue[END_QUEUE];
extern int queue_end;
extern int queue_start;

int randomize();
bool duplicated(int value);
bool push_queue(int value);
bool move_queue(int* value);
void show_vec();

#endif  // !QUEUE_H

// Copyright «2024» Gabriel Coelho Soares
#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H

#include <stdbool.h>

enum { TAMANHO = 5, FIM_FILA = 5, INICIO_FILA = 0 };

// Variáveis
extern int vec_queue[TAMANHO];
extern int queue_end;
extern int queue_start;

bool push_queue(int value);
bool move_queue(int* value);
void show_vec();

#endif  // !SIMPLE_QUEUE_H

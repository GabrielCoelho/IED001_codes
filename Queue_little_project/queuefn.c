// Copyright «2024» Gabriel Coelho Soares
#include "queuefn.h"

#include <stdio.h>

// Variáveis
int vec_queue[TAMANHO];
int queue_end = INICIO_FILA;
int queue_start = INICIO_FILA;

bool push_queue(int value) {
  if (queue_end == FIM_FILA && queue_start == FIM_FILA) {
    return false;  // Fila cheia
  }
  vec_queue[queue_end] = value;
  queue_end++;
  return true;
}

bool move_queue(int* value) {
  if (queue_start == queue_end || queue_start == FIM_FILA) {
    return false;
  } else {
    *value = vec_queue[queue_start];
    queue_start++;
    return true;
  }
}

void show_vec() {
  for (int i = 0; i < FIM_FILA; i++) {
    printf("Fila[%d] = %d\n", i + 1, vec_queue[i]);
  }
}

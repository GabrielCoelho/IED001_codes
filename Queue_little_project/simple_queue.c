// Copyright «2024» Gabriel Coelho Soares
#include "simple_queue.h"

#include <stdio.h>

// Variáveis
int vec_queue[TAMANHO];
int queue_end = INICIO_FILA;
int queue_start = INICIO_FILA;

bool push_queue(int value) {
  if (queue_end == FIM_FILA || queue_start == FIM_FILA) {
    return false;  // Fila cheia
  }
  printf("Inserindo o valor %d na fila\n", value);
  vec_queue[queue_end] = value;
  queue_end++;
  return true;
}

bool move_queue(int* value) {
  if (queue_start == queue_end || queue_start == FIM_FILA) {
    return false;
  } else {
    printf("Retirando o valor %d da fila\n", vec_queue[queue_start]);
    *value = vec_queue[queue_start];
    queue_start++;
    return true;
  }
}

void show_vec() {
  if (!(queue_start == queue_end)) {
    for (int i = queue_start; i < queue_end; i++) {
      printf("Fila[%d] = %d\n", i + 1, vec_queue[i]);
    }
  } else {
    printf("Fila vazia");
  }
  printf("\n\n");
}

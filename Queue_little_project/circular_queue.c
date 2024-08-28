// Copyright «2024» Gabriel Coelho Soares
#include "circular_queue.h"

#include <stdio.h>

// Variáveis
int vec_queue[TAMANHO];
bool flag_queue[TAMANHO] = {VAZIA, VAZIA, VAZIA, VAZIA, VAZIA};
int queue_end = INICIO_FILA;
int queue_start = INICIO_FILA;

bool push_queue(int value) {
  if (!flag_queue[queue_end]) {
    printf("Fila cheia\n");
    return false;  // Fila cheia
  }
  printf("Inserindo o valor %d na fila\n", value);
  vec_queue[queue_end] = value;
  flag_queue[queue_end] = NAO_VAZIA;
  queue_end++;
  if (queue_end == FIM_FILA) {
    queue_end = INICIO_FILA;
  }
  return true;
}

bool move_queue(int* value) {
  if (flag_queue[queue_start]) {
    printf("Fila vazia");
    return false;
  }
  printf("Retirando o valor %d da fila\n", vec_queue[queue_start]);
  *value = vec_queue[queue_start];
  if (queue_start == FIM_FILA) queue_start = INICIO_FILA;
  if (queue_start == queue_end) flag_queue[queue_start] = VAZIA;
  queue_start++;
  return true;
}

void show_vec() {
  if (!flag_queue[queue_start]) {
    if (queue_start < queue_end) {
      for (int i = queue_start; i < queue_end; i++) {
        if (i == FIM_FILA) i = INICIO_FILA;
        printf("Fila[%d] = %d\n", i + 1, vec_queue[i]);
      }
    } else {
      // TODO(GabrielCoelho): create the print conditions if queue_start >
      // queue_end or equal queue_end
    }
  } else {
    printf("Fila vazia");
  }
  printf("\n\n");
}

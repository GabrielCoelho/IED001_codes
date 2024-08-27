// Copyright «2024» Gabriel Coelho Soares
#include "queuefn.h"

// Variáveis
double vec_queue[TAMANHO];
int vec_position = 0;

bool push_queue(int value) {
  if (vec_position == TAMANHO) {
    return false;  // Pilha de strings cheia
  }
  vec_queue[vec_position] = value;
  vec_position++;
  return true;
}

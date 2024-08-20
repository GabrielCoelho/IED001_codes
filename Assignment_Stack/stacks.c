// Gabriel Coelho Soares 2024

#include "stacks.h"

int pilha[TAMANHO];
int posicao = 0;

bool push(int dado) {
  if (posicao == TAMANHO) {
    return false;
  } else {
    pilha[posicao] = dado;
    posicao++;
    return true;
  }
}
bool pop(int *dado) {
  if (posicao == 0) {
    return false;
  }
  posicao--;
  *dado = pilha[posicao];
  return true;
}

// Copyright 2024 <Marcos Nava>
// Created by marcos-nava on 06/08/24.
//
#include "Pilha.h"

#include <stdio.h>

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

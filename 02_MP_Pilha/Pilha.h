// Copyright 2024 <Marcos Nava>
// Created by marcos-nava on 06/08/24.
//

#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H

#include <stdbool.h>

// Constantes
enum { TAMANHO = 5 };

// Variáveis
extern int pilha[TAMANHO];
extern int posicao;

// Protótipos
bool push(int dado);
bool pop(int *dado);

#endif  // PILHA_PILHA_H

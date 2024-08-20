
#ifndef ASSIGNMENT_STACKS_STACK_H
#define ASSIGNMENT_STACKS_STACK_H

#include <stdbool.h>

// Constantes
enum { TAMANHO = 5 };

// Variáveis
extern int pilha[TAMANHO];
extern int posicao;

// Protótipos
bool push(int dado);
bool pop(int *dado);

#endif  // ASSIGNMENT_STACKS_STACK_H

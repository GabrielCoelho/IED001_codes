#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
void stringParaVetor(char *line, char vec[][20], int tamanho);
int tamanhoString(char entrada[]);
bool precedencia(char op1);
bool find(char letra, char *str);
void matemagica(char entrada[][20]);
#endif  // FUNCTIONS_H

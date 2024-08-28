// Copyright «2024» Gabriel Coelho Soares
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "circular_queue.h"
// #include "simple_queue.h"

int main(int argc, char *argv[]) {
  int vetor_exemplo[TAMANHO] = {5, 2, 3, 9, 4};
  int retirado = 0;
  // Mostra pilha vazia
  show_vec();
  // Início da inserção
  if (!push_queue(5)) printf("");
  if (!push_queue(2)) printf("");
  if (!push_queue(3)) printf("");
  if (!push_queue(9)) printf("");
  // Mostra os valores atuais
  show_vec();
  if (!push_queue(4)) printf("");
  if (!push_queue(15)) printf("");  // vai mostrar fila cheia
  // mostra os valores da fila
  show_vec();

  // Início da remoção
  if (!move_queue(&retirado)) printf("ERRO DE FILA!!!\n");
  if (!push_queue(7))
    printf("Fila cheia\n");  // tem que inserir o 7 no lugar do 5
  show_vec();
  if (!move_queue(&retirado)) printf("ERRO DE FILA!!!\n");
  if (!move_queue(&retirado)) printf("ERRO DE FILA!!!\n");
  if (!move_queue(&retirado)) printf("ERRO DE FILA!!!\n");
  if (!move_queue(&retirado)) printf("ERRO DE FILA!!!\n");
  if (!move_queue(&retirado))
    printf("ERRO DE FILA!!!\n");  // mostra Erro de Fila
  show_vec();
  return EXIT_SUCCESS;
}

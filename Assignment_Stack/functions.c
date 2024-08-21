
#include "functions.h"

#include <stdio.h>

#include "stacks.h"

bool find(char letra, char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == letra) {
      return true;
    }
  }
  return false;
}
void stringParaVetor(char *line, char vec[][20], int tamanho) {
  char trab[tamanho];
  char operacoes[] = "+-*/()";
  char letra;
  bool numero = false;
  bool str = false;
  int vecI = 0;
  int aux = 0;
  strcpy(trab, "");

  for (int i = 0; i < tamanho; i++) {
    letra = line[i];
    if ((isdigit(letra) || letra == '.') && !str) {
      if (!numero) {
        if (strlen(trab) != 0) {
          strcpy(vec[vecI++], trab);
          strcpy(trab, "");
        }
        numero = true;
        str = false;
      }
      aux = strlen(trab);
      trab[aux] = letra;
      trab[aux + 1] = '\0';
    } else if (letra == ' ') {
      if (!str) {
        if (strlen(trab) != 0) {
          strcpy(vec[vecI++], trab);
          strcpy(trab, "");
          numero = false;
          str = false;
        }
      }
    } else if (find(letra, operacoes) != 0) {
      if (strlen(trab) != 0) {
        strcpy(vec[vecI++], trab);
        strcpy(trab, "");
      }
      aux = strlen(trab);
      trab[aux] = letra;
      trab[aux + 1] = '\0';
      strcpy(vec[vecI++], trab);
      strcpy(trab, "");
      numero = false;
      str = false;
    }
  }
  if (strlen(trab) != 0) {
    strcpy(vec[vecI++], trab);
  }
}

int tamanhoString(char vector[]) { return strlen(vector); }

/** @Function precedencia
 * Copyright 2024 Cleber Souza
 * Estou utilzando esta função de precedência pois é mais simples de realizar a
 *verificação com somente uma operação do que verificar duas, conforme o código
 *entregue pelo professor.
 **/
bool precedencia(char op1) {
  switch (op1) {
    case '*':
    case '/':
      return false;
      break;
    case '+':
    case '-':
      return true;
      break;
    default:
      return false;
  }
}

/** @Function matemagica
 * @params vector[][20] : char
 * @usage ao chamar passando o vetor da função completa, a matemagica realiza um
 * laço de repetição até que a primeira coluna de uma linha seja igual ao
 * término/quebra de linha (fim do vetor). Enquanto isso não acontece, vou
 * realizando as verificações.
 * */
void matemagica(char vector[][20]) {
  double numero;
  char caracter;
  double conta = 0;
  int i = 0;

  while (vector[i][0] != '\0') {
    // Se encontrar um abre parênteses...
    if (vector[i][0] == '(') {
      // inserir no vetor de operadores
      push_string(vector[i]);
      i++;
    }
    // Se não encontrar procedência e não for um fecha parênteses...
    else if (!precedencia(vector[i][0]) && vector[i][0] != ')') {
      // verifico se é um dígito
      if (isdigit(vector[i][0])) {
        // transformo em double com `atof`
        numero = atof(vector[i]);
        // e insiro na pilha de valores
        push_double(numero);
      }
      // Se for um operador de divisão...
      else if (vector[i][0] == '/') {
        // Verifico se a próxima posição é um dígito
        if (isdigit(vector[i + 1][0])) {
          pop_double(&numero);
          // e já executo a operação, retornando à pilha de valores somente o
          // resultado da divisão.
          numero /= atof(vector[i + 1]);
          push_double(numero);
          i++;  // Avança para o próximo operador
        }
        // Se não, insiro o operador na pilha correspondente.
        else {
          push_string(vector[i]);
        }
      }
      // Não sendo um divisor, pode ser que seja um multiplicador. Executo a
      // mesma verificação de dígito ou empurro para a pilha correspondente.
      else {
        if (isdigit(vector[i + 1][0])) {
          pop_double(&numero);
          numero *= atof(vector[i + 1]);
          push_double(numero);
          i++;  // Avança para o próximo operador
        } else {
          push_string(vector[i]);
        }
      }
      i++;  // Avança para o próximo operando ou parêntese
      // Agora, se tiver precedência, eu a verifico e já insiro no vetor de
      // operadores.
    } else if (precedencia(vector[i][0])) {
      push_string(vector[i]);
      i++;
      // No entanto, sendo um fecha parênteses, eu já executo a operação, até
      // encontrar o abre parênteses correspondente.
    } else if (vector[i][0] == ')') {
      while (!estaVazia_string() &&
             pl_pilha_string[pl_posicao_string - 1][0] != '(') {
        pop_string(&caracter);
        // Como já estou executando a divisão e multiplicação conforme
        // precedência, aqui eu só verifico se são os caracteres responsáveis
        // pela soma e subtração.
        if (caracter == '+') {
          pop_double(&numero);
          conta = numero;
          pop_double(&numero);
          conta += numero;
          push_double(conta);
        } else {
          pop_double(&numero);
          conta = 0;
          conta = numero;
          pop_double(&numero);
          conta = numero - conta;
          push_double(conta);
        }
      }
      // Removo o '(' da pilha de operadores
      pop_string(&caracter);
      i++;
    }
    // Aqui apenas uma gambiarra para pular o iterador em caso dele não
    // encontrar nenhuma das opções acima (no caso de espaços, por exemplo).
    else {
      i++;
    }
  }

  // Processo o restante da pilha para realizar as contas finais, até que a
  // pilha de operadores esteja vazia, devendo restar apenas um resultado final
  // na pilha de valores.
  while (!estaVazia_string()) {
    pop_string(&caracter);
    if (precedencia(caracter)) {
      if (caracter == '+') {
        pop_double(&numero);
        conta = numero;
        pop_double(&numero);
        conta += numero;
        push_double(conta);
      } else {
        pop_double(&numero);
        conta = numero;
        pop_double(&numero);
        conta = numero - conta;
        push_double(conta);
      }
    } else {
      if (caracter == '/') {
        pop_double(&numero);
        conta = numero;
        pop_double(&numero);
        conta = numero / conta;
        push_double(conta);
      } else if (caracter == '*') {
        pop_double(&numero);
        conta = numero;
        pop_double(&numero);
        conta = numero * conta;
        push_double(conta);
      }
    }
  }
}

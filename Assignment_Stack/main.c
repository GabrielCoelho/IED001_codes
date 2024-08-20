// Copyright [2024] <Gabriel Coelho Soares>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool mesmaOuMaiorPrecedencia(char op1, char op2) {
  if (op2 == '(' || op2 == ')') {
    return false;
  }
  if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
    return false;
  } else {
    return true;
  }
}

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

void limpaVetor(char v[][20], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    strcpy(v[i], "");
  }
}

int main() {
  char exp[100] = "";
  char vec[100][20] = {'\0'};

  limpaVetor(vec, 100);

  strcpy(exp, "((22 + 5) * 2) / 3");

  stringParaVetor(exp, vec, 100);

  for (int i = 0; i < 100 && (strcmp(vec[i], "") != 0); i++) {
    printf("%s\n", vec[i]);
  }

  return 0;
}

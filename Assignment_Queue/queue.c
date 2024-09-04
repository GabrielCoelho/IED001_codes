// Copyright «2024» Gabriel Coelho Soares
#include "../Assignment_Queue/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variáveis
int vec_queue[END_QUEUE];
bool flag_queue[END_QUEUE] = {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};
int queue_end = START_QUEUE;
int queue_start = START_QUEUE;

int randomize() {
  srand(time(NULL));
  int random_number = (random() % 20) + 1;
  if (duplicated(random_number)) return randomize();
  return random_number;
}

bool duplicated(int value) {
  int not_doops = true;
  for (int i = START_QUEUE; i < END_QUEUE; i++) {
    if (!flag_queue[i]) {
      if (value == vec_queue[i]) {
        not_doops = false;
      }
      if (!not_doops) return not_doops;
    }
  }
  return not_doops;
}

bool push_queue(int value) {
  if (!flag_queue[queue_end]) {
    printf("Fila cheia\n");
    return false;  // Fila cheia
  }
  printf("Inserindo o valor %d na fila\n", value);
  vec_queue[queue_end] = value;
  flag_queue[queue_end] = NOT_EMPTY;
  queue_end++;
  if (queue_end == END_QUEUE) {
    queue_end = START_QUEUE;
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
  flag_queue[queue_start] = EMPTY;
  queue_start++;
  if (queue_start == END_QUEUE) queue_start = START_QUEUE;
  return true;
}

void show_vec() {
  int round = false;
  if (!flag_queue[queue_start]) {
    if (queue_start < queue_end) {
      for (int i = queue_start; i < queue_end; i++) {
        if (i == END_QUEUE) i = START_QUEUE;
        printf("Fila[%d] = %d\n", i + 1, vec_queue[i]);
      }
    } else {
      for (int i = queue_end; i <= END_QUEUE; i++) {
        if (i == END_QUEUE && i != queue_end) {
          i = 0;
          round = true;
        }
        if (i == queue_end && round) break;
        if (!flag_queue[i]) printf("Fila[%d] = %d\n", i + 1, vec_queue[i]);
      }
    }
  } else {
    printf("Fila vazia");
  }
  printf("\n\n");
}

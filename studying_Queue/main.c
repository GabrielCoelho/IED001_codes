#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
enum {
  OPT_DESSELECT = 0,
  OPT_ADD,
  OPT_REMOVE,
  OPT_SHOW,
  OPT_EXIT,
};

int menu();

int main(int argc, char *argv[]) {
  printf("Potato's Queues");
  int removed_from_queue = 0;
  int op = OPT_DESSELECT;
  while (op != OPT_EXIT) {
    op = menu();
    switch (op) {
      case OPT_ADD:
        printf("Choose a number: ");
        scanf("%d", &removed_from_queue);
        push(removed_from_queue);
        break;
      case OPT_REMOVE:
        if (!pop(&removed_from_queue)) {
          printf("\nNothing was removed\n\n");
        }
        break;
      case OPT_SHOW:
        show();
        break;
      case OPT_EXIT:
        break;
      default:
        printf("Choose correctly\n ");
        op = OPT_DESSELECT;
        break;
    }
  }

  return EXIT_SUCCESS;
}

int menu() {
  int option;
  printf("\nChoose one action\n");
  printf("%d - Add in Queue\n", OPT_ADD);
  printf("%d - Remove from Queue\n", OPT_REMOVE);
  printf("%d - Show the Queue\n", OPT_SHOW);
  printf("%d - Exit\n\n", OPT_EXIT);
  scanf("%d", &option);
  return option;
}

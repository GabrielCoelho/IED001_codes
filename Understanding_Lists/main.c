// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[]) {
  int removed_from_list = 0;
  printf("Simple Lists inside an array\n");

  printf("%d", list_size());
  list_add(1);
  list_add(2);
  list_add(3);
  list_add(4);
  list_add(5);
  printf("\n");
  printf("%d", list_size());

  printf("\n");
  for (int i = 0; i < reference; i++) {
    printf("%d - ", my_list[i]);
  }
  printf("\n");

  list_search_index(5);
  list_search_index(-2);
  list_search_index(12);
  list_search_value(2);
  if (!list_search_value(18)) {
    printf("Didn't found eighteen\n");
  }

  return EXIT_SUCCESS;
}

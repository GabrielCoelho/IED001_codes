// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "config.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void read_line(char *input_buffer, int length) {
  if (fgets(input_buffer, length, stdin) != NULL) {
    if (strlen(input_buffer) > 0 &&
        input_buffer[strlen(input_buffer) - 1] == '\n') {
      input_buffer[strlen(input_buffer) - 1] = '\0';
    } else {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }
  }
}

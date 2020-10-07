// SPDX-License-Identifier: X11

#include "util.h"

void print_datum(struct datum *datum) {
  printf("Name: %50s\nX: %ld\nY: %ld\n", datum->name, datum->x, datum->y);
}

void clear_stdin() {
  for (; getchar() != '\n';);
}

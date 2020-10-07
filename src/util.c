// SPDX-License-Identifier: X11

#include "util.h"

/*!
 * Pretty-prints a datum.
 *
 * \param dp Pointer to the datum to print
 */
void print_datum(struct datum *dp) {
  dp == NULL ?
    fprintf(stderr, "print_datum: Null datum") :
    printf("{ Name: %50s, X: %ld, Y: %ld }\n", dp->name, dp->x, dp->y);
}

/*!
 * Reads to the end of the last input from stdin.
 */
void clear_stdin() {
  char c;
  for (; (c = getchar()) != '\n' && c != EOF;);
}

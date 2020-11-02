// SPDX-License-Identifier: X11

#include "util.h"

/*!
 * Pretty-prints a datum.
 *
 * \param dp Pointer to the datum to print
 */
void print_datum(datum *dp) {
  dp == NULL ?
    fprintf(stderr, "print_datum: Null datum") :
    printf("{ Name: %s, X: %d, Y: %d }\n",
           dp->name, dp->x, dp->y);
}

/*!
 * Reads a line from a stream, and parses it into a datum.
 *
 * \param fp Stream to read from
 * \return Pointer to parsed datum
 */
datum *read_datum(FILE *fp) {
  datum *dp = NEW_DATUMP;

  char fmt[(uint8) floor(log10(NAME_MAXLENGTH)) + 1 + 2 + 1];
  sprintf(fmt, "%%%ds", NAME_MAXLENGTH);

  scanf((const char *) fmt, dp->name);

  isspace(fpeek(stdin)) ?
    scanf(" %d %d", &(dp->x), &(dp->x)) :
    scanf("%*s %d %d", &(dp->x), &(dp->x));

  return dp;
}

/*!
 * Peek the first character in a stream.
 *
 * \param fp Stream to peek in
 * \return First character in stream
 */
int fpeek(FILE *fp) {
  int c = fgetc(fp);
  ungetc(c, fp);
  return c;
}

/*!
 * Reads to the end of the last input from stdin.
 */
void clear_stdin() {
  char c;
  for (; (c = getchar()) != '\n' && c != EOF;);
}

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
  if (fpeek(fp) == EOF) return NULL;

  datum *dp = (datum *) calloc(1, sizeof(datum));

  if (fscanf(fp, "%" STR(NAME_MAXLENGTH) "s", dp->name) != 1)
    return NULL;

  if (isspace(fpeek(fp))) {
    if (fscanf(fp, " %d %d", &(dp->x), &(dp->y)) != 2)
      return NULL;
  }
  else {
    if (fscanf(fp, "%*s %d %d", &(dp->x), &(dp->y)) != 2)
      return NULL;
  }

  clear_stream(fp);
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
 * Reads to the end of the last input from stream.
 *
 * \param fp Stream to clear
 */
void clear_stream(FILE *fp) {
  char c;
  for (; (c = fgetc(fp)) != '\n' && c != EOF;);
}

/*!
 * Swap two elements.
 *
 * \param x,y Elements to swap
 */
void swap(int64 x, int64 y) {
  int64 t = x;
  x = y;
  y = t;
}

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
    printf("{ Name: %s, X: %d, Y: %d , A: %d }\n",
           dp->name, dp->x, dp->y, dp->a);
}

/*!
 * Reads a line from a stream, and parses it into a datum.
 *
 * \param fp Stream to read from
 * \return Pointer to parsed datum
 */
struct datum *read_datum(FILE *fp) {
  char c;
  char name[NAME_MAXLENGTH + 1];
  int32 x,y;
  int8 i;
  uint8 a;

  for (i = -1; i < NAME_MAXLENGTH &&
       (c = fgetc(fp)) != '\n' && c != ':' && c != EOF;) {
    i++;
    name[i] = c;
  }
  name[i + 1] = '\0';
  if (name[0] == '\0') return NULL;

  for (; (c = fgetc(fp)) != '\n' && c != ':' && c != EOF;);
  if (c == '\n' || c == EOF) return NULL;

  scanf("%d:%d:%hhu\n", &x, &y, &a);

  struct datum *dp = NEW_DATUMP;
  strcpy(dp->name, name);
  dp->x = x;
  dp->y = y;
  dp->a = a;

  return dp;
}

/*!
 * Reads a string from stdin into a buffer.
 *
 * \param name Buffer to read into
 */
void readname(char name[]) {
  char c;
  int8 i;
  for (i = -1; i < NAME_MAXLENGTH &&
       (c = getchar()) != '\n' && c != EOF;) {
    i++;
    name[i] = c;
  }
  name[i + 1] = '\0';
  if (c != '\n') clear_stdin();
}

/*!
 * Reads to the end of the last input from stdin.
 */
void clear_stdin() {
  char c;
  for (; (c = getchar()) != '\n' && c != EOF;);
}

// SPDX-License-Identifier: X11

#include "main.h"

int main(int argc, char const *argv[]) {
  int16 opt;
  enum {INTERACTIVE, CONVHULL, DIJKSTRA} mode = INTERACTIVE;

  char *dijkstart = NULL;
  char *dijkend = NULL;
  while ((opt = getopt(argc, argv, "icd:")) != -1) {
    switch (opt) {
      case 'i':
        mode = INTERACTIVE;
        break;
      case 'c':
        mode = CONVHULL;
        break;
      case 'd':
        dijkstart = &optarg;
        mode = DIJKSTRA;
        break;
      case 'e':
        if (mode == DIJKSTRA) {
          dijkend = &optarg;
          break;
        }
        __attribute__ ((fallthrough));
      default:
        fprintf(stderr,
          "Usage: %s [-i | -c | -d start -e end] -- [<file>...]\n",
          argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  switch (mode) {
    case (INTERACTIVE):
      repl();
      exit(EXIT_SUCCESS);
    case (CONVHULL):
      fprintf(stderr, "Convex hull CLI not yet implemented.\n");
      exit(EXIT_SUCCESS);
    case (DIJKSTRA):
      fprintf(stderr, "Dijkstra CLI not yet implemented.\n");
      exit(EXIT_SUCCESS);
  }
}

void repl() {
  char opt;
  char *prompt =
    "\nEnter one digit 0-6.\n\n"
    "0. Add point\n"
    "1. Retrieve point\n"
    "2. Dijkstra (All)\n"
    "3. Dijkstra (Selected)\n"
    "4. Convex hull (All)\n"
    "5. Convex hull (Selected)\n"
    "6. Quit\n";

  do {
    fflush(stdin);
    printf("%s", prompt);

    if ((opt = getchar()) == EOF)
      exit(EXIT_SUCCESS);

    switch (opt) {
      case '0':
        fprintf(stderr, "\nAdd point option not yet implemented.\n");
        break;
      case '1':
        fprintf(stderr, "\nRetrieve point option not yet implemented.\n");
        break;
      case '2':
        fprintf(stderr, "\nDijkstra (All) option not yet implemented.\n");
        break;
      case '3':
        fprintf(stderr,
          "\nDijkstra (Selected) option not yet implemented.\n");
        break;
      case '4':
        fprintf(stderr,
          "\nConvex hull (All) option not yet implemented.\n");
        break;
      case '5':
        fprintf(stderr,
          "\nConvex hull (Selected) option not yet implemented.\n");
        break;
      case '6':
        exit(EXIT_SUCCESS);
      default:
        break;
    }
  } while (opt != EOF);
}

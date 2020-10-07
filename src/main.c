// SPDX-License-Identifier: X11

#include "main.h"

int main(int argc, char *const argv[]) {
  int16 opt;
  enum {INTERACTIVE, CONVHULL, DIJKSTRA} mode = INTERACTIVE;

  char *dijkstart = NULL;
  char *dijkend = NULL;
  while ((opt = getopt(argc, argv, "icd:e:")) != -1) {
    switch (opt) {
      case 'i':
        mode = INTERACTIVE;
        break;
      case 'c':
        mode = CONVHULL;
        break;
      case 'd':
        dijkstart = optarg;
        mode = DIJKSTRA;
        break;
      case 'e':
        if (mode == DIJKSTRA) {
          dijkend = optarg;
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
      repl(argc, argv, optind);
      exit(EXIT_SUCCESS);
    case (CONVHULL):
      fprintf(stderr, "Convex hull CLI not yet implemented.\n");
      exit(EXIT_SUCCESS);
    case (DIJKSTRA):
      fprintf(stderr, "Dijkstra CLI not yet implemented.\n");
      exit(EXIT_SUCCESS);
  }
}

void repl(int argc, char *const argv[], int optind) {
  srand((unsigned) time(NULL));
  const uint32 seed = (const uint32) rand();

  struct avl **frame = init_frame();

  for (int i = optind; i < argc; i++)
    parse_inf(frame, seed, argv[i]);

  char opt, c;
  char name[NAME_MAXLENGTH + 1];
  int64 x,y;
  int8 i;

  char *prompt =
    "\nEnter one digit 0-6.\n\n"
    "0. Quit\n"
    "1. Add point\n"
    "2. Retrieve point\n"
    "3. Dijkstra (All)\n"
    "4. Dijkstra (Selected)\n"
    "5. Convex hull (All)\n"
    "6. Convex hull (Selected)\n\n"
    "> ";

  do {
    printf("%s", prompt);

    opt = getchar();
    clear_stdin();

    switch (opt) {
      case '0':
        printf("\nQuitting...\n");
        exit(EXIT_SUCCESS);
      case '1':

        printf("Name (string): ");
        for (i = 0; i < NAME_MAXLENGTH && (c = getchar()) != '\n'; i++)
          name[i] = c;
        name[i + 1] = '\0';
        clear_stdin();

        printf("X coordinate (64-bit decimal integer): ");
        scanf("%ld", &x);
        clear_stdin();

        printf("Y coordinate (64-bit decimal integer): ");
        scanf("%ld", &y);
        clear_stdin();

        struct datum d = NEW_DATUM;
        strcpy(d.name, name);
        d.x = x;
        d.y = y;

        add_datum(frame, seed, d);

        break;
      case '2':
        printf("Name (string): ");
        i = 0;
        for (; i < NAME_MAXLENGTH && (c = getchar()) != '\n'; i++)
          name[i] = c;
        name[i + 1] = '\0';
        clear_stdin();

        struct datum *dp = get_by_name(frame, seed, name);
        print_datum(dp);

        break;
      case '3':
        fprintf(stderr, "\nDijkstra (All) option not yet implemented.\n");
        break;
      case '4':
        fprintf(stderr,
          "\nDijkstra (Selected) option not yet implemented.\n");
        break;
      case '5':
        fprintf(stderr,
          "\nConvex hull (All) option not yet implemented.\n");
        break;
      case '6':
        fprintf(stderr,
          "\nConvex hull (Selected) option not yet implemented.\n");
        break;
      default:
        break;
    }
  } while (opt != EOF);
}

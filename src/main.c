// SPDX-License-Identifier: X11

#include "main.h"

/*!
 * Main process of the program.
 *
 * \param argc Number of arguments
 * \param argv Array of argumet strings
 * \return `EXIT_SUCCESS` (0) if the process terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int main(int argc, char *const argv[]) {
  int16 opt;
  enum {INTERACTIVE, CONVHULL, DIJKSTRA} mode = INTERACTIVE;

  char *dijksrc = NULL;
  char *dijkdest = NULL;
  while ((opt = getopt(argc, argv, "icd:e:")) != -1) {
    switch (opt) {
      case 'i':
        mode = INTERACTIVE;
        break;
      case 'c':
        mode = CONVHULL;
        break;
      case 'd':
        dijksrc = optarg;
        mode = DIJKSTRA;
        break;
      case 'e':
        if (mode == DIJKSTRA) {
          dijkdest = optarg;
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

  if (optind >= argc) {
    fprintf(stderr,
      "Usage: %s [-i | -c | -d start -e end] -- [<file>...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct datum **idlist = NULL;
  switch (mode) {
    case (INTERACTIVE):
      exit(repl(argc, argv, optind));
    case (CONVHULL):
      fprintf(stderr, "Convex hull CLI not yet implemented.\n");
      exit(EXIT_SUCCESS);
    case (DIJKSTRA):
      idlist = parse_inf_graph(NULL, argv[optind], dijksrc, dijkdest);
      for (int i = optind + 1; i < argc; i++)
        parse_inf_graph(idlist, argv[i], dijksrc, dijkdest);

      if (idlist == NULL ||
          idlist[0]->name != dijksrc || idlist[1]->name != dijkdest) {
        fprintf(stderr,
          "Dijkstra source or destination not found in input files.\n");
        exit(EXIT_FAILURE);
      }

      exit(dijkstra_cli(idlist, dijksrc, dijkdest));
  }
}

/*!
 * Presents an interactive shell.
 *
 * \param argc Number of arguments of `main()`
 * \param argv Array of argumet strings of `main()`
 * \param optind Index of the first non-option argument of `main()`
 * \return `EXIT_SUCCESS` (0) if the function terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int repl(int argc, char *const argv[], int optind) {
  srand((unsigned) time(NULL));
  const uint32 seed[] = {(const uint32) rand() % NAME_MAXLENGTH,
                         (const uint32) rand() % NAME_MAXLENGTH,
                         (const uint32) rand()};

  struct avl **frame = init_frame();

  for (int i = optind; i < argc; i++)
    parse_inf_frame(frame, seed, argv[i]);

  char opt;
  char name[NAME_MAXLENGTH + 1];
  char named[NAME_MAXLENGTH + 1];
  int32 x,y;
  struct datum *dp;
  struct datum **idlist;

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
        return free_frame(frame);
      case '1':
        printf("Name (string): ");
        readname(name);
        if (name[0] == '\0') break;

        printf("X coordinate (64-bit decimal integer): ");
        scanf("%d", &x);
        clear_stdin();

        printf("Y coordinate (64-bit decimal integer): ");
        scanf("%d", &y);
        clear_stdin();

        dp = NEW_DATUMP;
        strcpy(dp->name, name);
        dp->x = x;
        dp->y = y;

        add_datum(frame, seed, *dp);
        free(dp);

        break;
      case '2':
        printf("Name (string): ");
        readname(name);
        if (name[0] == '\0') break;

        dp = get_by_name(frame, seed, name);
        print_datum(dp);

        break;
      case '3':
        printf("Source name (string): ");
        readname(name);
        if (name[0] == '\0') break;

        printf("Destination name (string): ");
        readname(named);
        if (named[0] == '\0') break;

        idlist = flatten(frame, name, named);

        if (idlist == NULL) {
          fprintf(stderr,
            "Dijkstra source or destination not found in data.\n");
          break;
        }
        else {
          dijkstra_repl(idlist, name, named);
        }

        break;
      case '4':
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

    clear_stdin();
  } while (opt != EOF);

  return(free_frame(frame));
}

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
  enum {INTERACTIVE, CONVHULL, MST} mode = INTERACTIVE;

  while ((opt = getopt(argc, argv, "icm")) != -1) {
    switch (opt) {
      case 'i':
        mode = INTERACTIVE;
        break;
      case 'c':
        mode = CONVHULL;
        break;
      case 'm':
        mode = MST;
        break;
      default:
        fprintf(stderr,
          "Usage: %s [-i | -c | -m] -- [<file>...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  if (optind >= argc) {
    fprintf(stderr,
      "Usage: %s [-i | -c | -m] -- [<file>...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  switch (mode) {
    case (INTERACTIVE):
      exit(repl(argc, argv, optind));
    case (CONVHULL):
      exit(convhull_repl(argc, argv, optind));
    case (MST):
      // !DO
      exit(EXIT_SUCCESS);
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
  const uint32 seed[3] = {(const uint32) rand() % NAME_MAXLENGTH,
                          (const uint32) rand() % NAME_MAXLENGTH,
                          (const uint32) rand()};

  avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH];
  for (int i = 0; i < FRAME_WIDTH; i++)
    for (int j = 0; j < FRAME_WIDTH; j++)
      frame[i][j] = NULL;

  for (int i = optind; i < argc; i++)
    parse_inf_frame(frame, seed, argv[i]);

  char opt;
  char name[NAME_MAXLENGTH + 1];
  datum *dp;
  uint64 n;
  linked_list *all;
  linked_list *hull;

  char *prompt =
    "\nEnter one digit 0-6.\n\n"
    "0. Quit\n"
    "1. Add point\n"
    "2. Retrieve point\n"
    "3. Minimum spanning tree (All)\n"
    "4. Minimum spanning tree (Selected)\n"
    "5. Convex hull (All)\n"
    "6. Convex hull (Selected)\n\n"
    "> ";

  do {
    printf("%s", prompt);

    opt = getchar();
    clear_stream(stdin);

    switch (opt) {
      case '0':
        printf("\nQuitting...\n");
        free_forest(frame);
        return EXIT_SUCCESS;
      case '1':
        printf(
          "Name (string), X, Y (32-bit signed int), space separated:\n");
        if ((dp = read_datum(stdin)) == NULL) {
          fprintf(stderr, "\nFailed to parse datum.\n");
          break;
        }

        add_datum(frame, seed, dp);

        break;
      case '2':
        printf("Name (string):\n");
        if (scanf("%" STR(NAME_MAXLENGTH) "s", name) != 1) {
          fprintf(stderr, "\nFailed to parse name.\n");
          break;
        }

        if ((dp = get_by_name(frame, seed, name)) == NULL)
          printf("%s not found.\n", name);
        else
          print_datum(dp);

        break;
      case '3':
        break;
      case '4':
        break;
      case '5':
        printf("Constructing convex hull from all points...\n");
        hull = construct_hull(flatten(frame));
        print_convex_hull(hull, stdout);

        break;
      case '6':
        printf("Number of points (64-bit unsigned int):\n");
        if (scanf("%lu", &n) != 1) {
          fprintf(stderr, "\nFailed to parse count.\n");
          break;
        }

        all = NULL;
        for (uint64 i = 0; i < n; i++) {
          printf("(%lu/%lu) Name (string):\n", i, n);
          if (scanf("%" STR(NAME_MAXLENGTH) "s", name) != 1) {
            fprintf(stderr, "\nFailed to parse name.\n");
            i--;
            continue;
          }
          if ((dp = get_by_name(frame, seed, name)) == NULL)
            printf("%s not found.\n", name);
          else
            all = cons(all, dp);
        }

        printf("Constructing convex hull from selected points...\n");
        hull = construct_hull(all);
        print_convex_hull(hull, stdout);
        free_list_shallow(all);

        break;
      default:
        break;
    }
  } while (opt != EOF);

  free_forest(frame);
  return EXIT_SUCCESS;
}

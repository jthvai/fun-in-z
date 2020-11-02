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

  // if (optind >= argc) {
  //   fprintf(stderr,
  //     "Usage: %s [-i | -c | -d start -e end] -- [<file>...]\n", argv[0]);
  //   exit(EXIT_FAILURE);
  // }

  switch (mode) {
    case (INTERACTIVE):
      exit(repl(argc, argv, optind));
    case (CONVHULL):
      fprintf(stderr, "Convex hull CLI not yet implemented.\n");
      exit(EXIT_SUCCESS);
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
  const uint32 seed[] = {(const uint32) rand() % NAME_MAXLENGTH,
                         (const uint32) rand() % NAME_MAXLENGTH,
                         (const uint32) rand()};

  avl_tree **frame = init_frame();

  for (int i = optind; i < argc; i++)
    parse_inf_frame(frame, seed, argv[i]);

  char opt;
  char fmt[(uint8) floor(log10(NAME_MAXLENGTH)) + 1 + 2 + 1];
  sprintf(fmt, "%%%ds", NAME_MAXLENGTH);
  char name[NAME_MAXLENGTH + 1];
  datum *dp;

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
    clear_stdin();

    switch (opt) {
      case '0':
        printf("\nQuitting...\n");
        return free_frame(frame);
      case '1':
        printf(
          "Name (string), X, Y (32-bit signed int), space separated:\n");
        dp = read_datum(stdin);
        clear_stdin();

        add_datum(frame, seed, dp);
        free(dp);

        break;
      case '2':
        printf("Name (string):\n");
        scanf((const char *) fmt, name);
        clear_stdin();
        if (name[0] == '\0') break;

        dp = get_by_name(frame, seed, name);
        if (dp == NULL)
          printf("%s not found.\n", name);
        else
          print_datum(dp);

        break;
      case '3':
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
  } while (opt != EOF);

  return(free_frame(frame));
}

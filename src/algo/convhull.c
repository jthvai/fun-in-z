// SPDX-License-Identifier: X11

#include "convhull.h"

static linked_list *parse_inf_ll(linked_list *list, const char *fn);
void print_convex_hull(linked_list *hull, FILE *fp);

static linked_list *right_chain(linked_list *all, linked_list *hull,
                                datum* src, datum *target);
static linked_list *left_chain(linked_list *all, linked_list *hull,
                               datum* src, datum *target);

static long double right_chain_angle(datum *src, datum *dest);
static long double left_chain_angle(datum *src, datum *dest);

/*!
 * Computes the convex hull from input files.
 *
 * \param argc Number of arguments of `main()`
 * \param argv Array of argumet strings of `main()`
 * \param optind Index of the first non-option argument of `main()`
 * \return `EXIT_SUCCESS` (0) if the function terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int convhull_repl(int argc, char *const argv[], int optind) {
  linked_list *all = NULL;
  for (int i = optind; i < argc; i++)
    all = parse_inf_ll(all, argv[i]);

  linked_list *hull = construct_hull(all);

  FILE *outfp = fopen(OUTPUT_FILENAME, "w+");
  if (outfp == NULL) {
    fprintf(stderr, "Failed to open " OUTPUT_FILENAME "\n"
                    "Dumping results to stdout...\n");
    print_convex_hull(hull, stdout);

    free_list(all);

    return EXIT_FAILURE;
  }
  else {
    print_convex_hull(hull, outfp);

    fclose(outfp);
    free_list(all);

    return EXIT_SUCCESS;
  }
}

/*!
 * Construct a convex hull.
 *
 * \param all List of points to consider
 * \return Linked list of convex hull
 */
linked_list *construct_hull(linked_list *all) {
  datum *top = NULL;
  datum *bot = NULL;
  for (linked_list *p = all; p != NULL; p = p->n) {
    if (top == NULL) top = p->dp;
    if (bot == NULL) bot = p->dp;

    if (p->dp->y > top->y || (p->dp->y == top->y && p->dp->x < top->x))
      top = p->dp;
    if (p->dp->y < bot->y || (p->dp->y == bot->y && p->dp->x < bot->x))
      bot = p->dp;
  }

  return left_chain(all, right_chain(all, NULL, bot, top), top, bot);
}

/*!
 * Parse the contents of a file, storing into a linked list.
 *
 * \param list List to attach data to
 * \param fn Name of file to parse
 */
static linked_list *parse_inf_ll(linked_list *list, const char *fn) {
  FILE *fp = fopen(fn, "r");
  if (fp == NULL) {
    fprintf(stderr, "Failed to open %s\n", fn);
    return list;
  }

  datum *dp;
  while ((dp = read_datum(fp)) != NULL)
    list = cons(list, dp);

  fclose(fp);
  return list;
}

/*!
 * Print the convex hull to a stream. Free memory after.
 *
 * \param hull List of points to print
 * \param fp Stream to print to
 */
void print_convex_hull(linked_list *hull, FILE *fp) {
  for (linked_list *p = hull; p != NULL; p = p->n)
    fprintf(fp, "%s %d %d\n", p->dp->name, p->dp->x, p->dp->y);
  free_list_shallow(hull);
}

/*!
 * Construct the right chain of a convex hull.
 *
 * \param all List of points to consider
 * \param hull List of points currently in convex hull
 * \param src Starting point for this chain
 * \param target Point at which to seal the chain
 * \return Linked list of convex hull
 */
static linked_list *right_chain(linked_list *all, linked_list *hull,
                                datum* src, datum *target) {
  if (src == target)
    return hull;

  datum *min = NULL;
  long double minangle = 100;
  long double angle;
  for (linked_list *p = hull; p != NULL; p = p->n) {
    if (min == NULL) min = p->dp;

    angle = right_chain_angle(src, p->dp);
    if (angle < minangle) {
      minangle = angle;
      min = p->dp;
    }
  }

  hull = cons(hull, min);
  return right_chain(all, hull, min, target);
}

/*!
 * Construct the left chain of a convex hull.
 *
 * \param all List of points to consider
 * \param hull List of points currently in convex hull
 * \param src Starting point for this chain
 * \param target Point at which to seal the chain
 * \return Linked list of convex hull
 */
static linked_list *left_chain(linked_list *all, linked_list *hull,
                               datum* src, datum *target) {
  if (src == target)
    return hull;

  datum *min = NULL;
  long double minangle = 100;
  long double angle;
  for (linked_list *p = hull; p != NULL; p = p->n) {
    if (min == NULL) min = p->dp;

    angle = left_chain_angle(src, p->dp);
    if (angle < minangle) {
      minangle = angle;
      min = p->dp;
    }
  }

  hull = cons(hull, min);
  return left_chain(all, hull, min, target);
}

/*!
 * Compute the polar angle between two points on the right chain.
 *
 * \param src Point confirmed on the convex hull
 * \param dest Point to calculate angle to
 * \return Polar angle from the x-axis (quadrant 1), in radians
 */
static long double right_chain_angle(datum *src, datum *dest) {
  int32 y = dest->y - src->y;
  int32 x = dest->x - src->x;
  return atan2(y, x);
}

/*!
 * Compute the polar angle between two points on the left chain.
 *
 * \param src Point confirmed on the convex hull
 * \param dest Point to calculate angle to
 * \return Polar angle from the negative x-axis (quadrant 3), in radians
 */
static long double left_chain_angle(datum *src, datum *dest) {
  int32 y = dest->y - src->y;
  int32 x = dest->x - src->x;
  return M_PI - fabsl(atan2(y, x));
}

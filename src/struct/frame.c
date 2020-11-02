// SPDX-License-Identifier: X11

#include "frame.h"

static int8 hash(const uint32 s, char c);

/*!
 * Initialises the main data structure.
 *
 * \return Pointer to an AVL matrix -- the frame
 */
avl_tree **init_frame() {
  return NULL;
}

/*!
 * Hashes a single character to an integer 0-63.
 *
 * \param s XOR key
 * \param c Character to hash
 * \return Hashed value, an integer 0-63 inclusive
 */
static int8 hash(const uint32 s, char c) {
  return (int8) ((s ^ c) % FRAME_WIDTH);
}

/*!
 * Parses the contents of a file, and stores it in the frame after hashing
 * for its location.
 *
 * \param frame Frame to insert into
 * \param seed Hash key
 * \param fn Name of file to parse
 */
void parse_inf_frame(avl_tree **frame, const uint32 seed[],
                     const char *fn) {
  if (frame == NULL) return;
}

/*!
 * Frees memory in use by the frame.
 *
 * \param frame Frame to release
 * \return `EXIT_SUCCESS` (0) if the process terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int free_frame(avl_tree **frame) {
  return EXIT_SUCCESS;
}

/*!
 * Find a datum by its name and returns a pointer to it.
 *
 * \param frame Frame to search in
 * \param seed Hash key
 * \param name Name of datum to search for
 * \return Pointer to the datum with the same name if it exists, or NULL if
 *         it could not be found
 */
datum *get_by_name(avl_tree **frame, const uint32 seed[],
                          char name[]) {
  fprintf(stderr, "Retrieve point option not yet implemented.\n");
  if (frame == NULL) return NULL;

  return NULL;
}

/*!
 * Inserts a single datum into the frame.
 *
 * \param frame Frame to insert into
 * \param seed Hash key
 * \param datum Datum to insert
 * \return Pointer to the updated frame
 */
avl_tree **add_datum(avl_tree **frame, const uint32 seed[],
                       datum *dp) {
  fprintf(stderr, "Add point option not yet implemented.\n");
  if (frame == NULL) return NULL;

  return NULL;
}

/*!
 * Stores every datum in the frame into an array.
 *
 * \param frame Frame to flatten
 * \param src Source for Dijkstra
 * \param dest Destination for Dijkstra
 * \return Array of all data, terminated with a NULL, or NULL if `src` or
 *         `dest` could not be found.
 */
datum **flatten(avl_tree **frame, char *src, char *dest) {
  return NULL;
}

// SPDX-License-Identifier: X11

#include "frame.h"

static int8 hash(const uint32 s, char c);

/*!
 * Initialises the main data structure.
 *
 * \return Pointer to an AVL matrix -- the frame
 */
struct avl **init_frame() {
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
void parse_inf(struct avl **frame, const uint32 seed[], const char *fn) {
  if (frame == NULL) return;
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
struct datum *get_by_name(struct avl **frame, const uint32 seed[],
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
struct avl **add_datum(struct avl **frame, const uint32 seed[],
                       struct datum datum) {
  fprintf(stderr, "Add point option not yet implemented.\n");
  if (frame == NULL) return NULL;

  return NULL;
}

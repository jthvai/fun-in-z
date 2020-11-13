// SPDX-License-Identifier: X11

#include "frame.h"

static int8 hash(const uint32 s, char c);

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
void parse_inf_frame(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                     const uint32 seed[3], const char *fn) {
  FILE *fp = fopen(fn, "r");

  datum *dp;
  while ((dp = read_datum(fp)) != NULL) {
    add_datum(frame, seed, dp);
  }

  fclose(fp);
}

/*!
 * Frees memory in use by the frame on the heap.
 *
 * \param frame Frame containing forest to release
 */
void free_forest(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH]) {
  for (int8 i = 0; i < FRAME_WIDTH; i++)
    for (int8 j = 0; j < FRAME_WIDTH; j++)
      free_tree(frame[i][j]);
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
datum *get_by_name(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                   const uint32 seed[3], char name[]) {
  uint8 indx = hash(seed[2], name[seed[0]]);
  uint8 indy = hash(seed[2], name[seed[1]]);
  return search(frame[indx][indy], name);
}

/*!
 * Inserts a single datum into the frame.
 *
 * \param frame Frame to insert into
 * \param seed Hash key
 * \param datum Datum to insert
 */
void add_datum(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
               const uint32 seed[3], datum *dp) {
  uint8 indx = hash(seed[2], dp->name[seed[0]]);
  uint8 indy = hash(seed[2], dp->name[seed[1]]);
  insert(frame[indx][indy], dp);
}

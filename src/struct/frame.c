// SPDX-License-Identifier: X11

#include "frame.h"

static int8 hash(const uint32 seed, char c);

// Initialises the main data structure
struct avl **init_frame() {
  return NULL;
}

// Hashes a single character to an integer 0-63
static int8 hash(const uint32 seed, char c) {
  return 0;
}

// Parses the contents of fn, and stores it in frame, hashing against seed
// to find its location
int parse_inf(struct avl **frame, const uint32 seed, const char *fn) {
  if (frame == NULL) return 0;

  return 0;
}

// Finds a datum by its name and returns a pointer to it, or returns null if
// it does not exist
struct datum *get_by_name(struct avl **frame, const uint32 seed,
                          char name[]) {
  fprintf(stderr, "Retrieve point option not yet implemented.\n");
  if (frame == NULL) return NULL;

  return NULL;
}

// Adds a single datum into frame
int *add_datum(struct avl **frame, const uint32 seed, struct datum datum) {
  fprintf(stderr, "Add point option not yet implemented.\n");
  if (frame == NULL) return 0;

  return 0;
}

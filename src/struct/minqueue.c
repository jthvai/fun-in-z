// SPDX-License-Identifier: X11

#include "minqueue.h"

static struct datum *min_heapify(struct datum *data, int index);
static void deckey(struct datum *data, int index, int key);

// Build a min-heap from an unordered input
struct datum *build_minheap(struct datum *data) {
  return NULL;
}

// Maintain the min-heap
static struct datum *min_heapify(struct datum *data, int index) {
  return NULL;
}

// Inserts an element into the queue
struct datum *push(struct datum *data, int key) {
  return NULL;
}

// Returns the minimum of the queue without removing it
struct datum peek(struct datum *data) {
  return *data;
}

// Remove and return the minimum of the queue
struct datum pop(struct datum *data) {
  return *data;
}

// Set the key of a new node to the correct value
static void deckey(struct datum *data, int index, int key) {
  return;
}

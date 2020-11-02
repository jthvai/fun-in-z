// SPDX-License-Identifier: X11

#include "heap.h"

static datum *min_heapify(datum **data, uint64 index);
static void deckey(datum **data, uint64 index, uint64 key);
static uint64 parent(uint64 index);
static uint64 left(uint64 index);
static uint64 right(uint64 index);

/*!
 * Builds a min-heap from an unordered array of data.
 *
 * \param data Array to heapify
 */
datum *build_minheap(datum **data) {
  return NULL;
}

/*!
 * Maintains the min-heap property of a node.
 *
 * \param data Array to heapify
 * \param index Array index of the node to heapify
 * \return Updated array
 */
static datum *min_heapify(datum **data, uint64 index) {
  return NULL;
}

/*!
 * Computes the parent of the node at a given index.
 *
 * \param index Index of node to compute from
 * \return Index of the parent of the node
 */
static uint64 parent(uint64 index) {
  return index / 2;
}

/*!
 * Computes the left child of the node at a given index.
 *
 * \param index Index of node to compute from
 * \return Index of the left child of the node
 */
static uint64 left(uint64 index) {
  return 2 * index;
}

/*!
 * Computes the right child of the node at a given index.
 *
 * \param index Index of node to compute from
 * \return Index of the right child of the node
 */
static uint64 right(uint64 index) {
  return 2 * index + 1;
}

/*!
 * Inserts a datum into the heap.
 *
 * \param data Heap to insert into
 * \param datum Datum to insert
 * \param key Value of the datum
 * \return Updated array
 */
datum **push(datum **data, datum *dp, uint64 key) {
  return NULL;
}

/*!
 * Finds the minimum of the heap without removing it.
 *
 * \param data Heap to search in
 * \return Pointer to the minimum of the heap
 */
datum *peek(datum **data) {
  return *data;
}

/*!
 * Removes and returns the minimum of the heap.
 *
 * \param data Heap to search in
 * \return Pointer to the minimum of the heap
 */
datum *pop(datum **data) {
  return *data;
}

/*!
 * Sets the key of a new node to the correct value.
 *
 * \param data Heap traverse
 * \param index Current index of the node
 * \param key Value of the node
 */
static void deckey(datum **data, uint64 index, uint64 key) {
  return;
}

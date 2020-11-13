// SPDX-License-Identifier: X11

#include "heap.h"

static void min_heapify(int64 N, int64 *queue, int64 *tree,
                        datum **ids, uint64 **graph, int64 index);
static uint64 gen_key(int64 id, int64 *tree, uint64 **graph);

static int64 left(int64 index);
static int64 right(int64 index);

/*!
 * Builds a min-heap from an unordered array of data.
 *
 * \param N Amount of data in queue
 * \param queue Array to heapify
 * \param tree Current minimum spanning tree
 * \param ids Directory to match data to its graph entry
 * \param graph Graph of all points
 */
void build_minheap(int64 N, int64 *queue, int64 *tree,
                   datum **ids, uint64 **graph) {
  for (int64 i = N/2 - 1; i >= 0; i--)
    min_heapify(N, queue, tree, ids, graph, i);
}

/*!
 * Maintains the min-heap property of a node.
 *
 * \param N Amount of data in queue
 * \param queue Array to heapify
 * \param tree Current minimum spanning tree
 * \param ids Directory to match data to its graph entry
 * \param graph Graph of all points
 * \param index Array index of the node to heapify
 */
static void min_heapify(int64 N, int64 *queue, int64 *tree,
                        datum **ids, uint64 **graph, int64 index) {
  int64 l = left(index);
  int64 r = right(index);
  int64 larger = index;

  uint64 ikey = gen_key(queue[index], tree, graph);
  uint64 largekey = ikey;
  uint64 lkey, rkey;

  if (l < N) {
    lkey = gen_key(queue[l], tree, graph);
    larger = lkey > largekey ? l : larger;
    largekey = larger == l ? lkey : largekey;
  }
  if (r < N) {
    rkey = gen_key(queue[r], tree, graph);
    larger = rkey > largekey ? r : larger;
    largekey = larger == r ? rkey : largekey;
  }

  if (larger != index) {
    swap(queue[index], queue[larger]);
    min_heapify(N, queue, tree, ids, graph, larger);
  }
}

/*!
 * Generate queue key for a datum.
 *
 * \param id ID of datum for which to generate key
 * \param tree Current minimum spanning tree
 * \param graph Graph of all points
 */
static uint64 gen_key(int64 id, int64 *tree, uint64 **graph) {
  uint64 min = 0;

  if (tree[0] != CANARY)
    min = graph[id][tree[0]];
  for (int64 i = 1; tree[i] != CANARY; i++) {
    min = graph[id][tree[i]] < min ? graph[id][tree[i]] : min;
  }

  return min;
}

/*!
 * Computes the left child of the node at a given index.
 *
 * \param index Index of node to compute from
 * \return Index of the left child of the node
 */
static int64 left(int64 index) {
  return 2 * index;
}

/*!
 * Computes the right child of the node at a given index.
 *
 * \param index Index of node to compute from
 * \return Index of the right child of the node
 */
static int64 right(int64 index) {
  return 2 * index + 1;
}

/*!
 * Removes and returns the minimum of the heap.
 *
 * \param N Amount of data in queue
 * \param queue Array to heapify
 * \param tree Current minimum spanning tree
 * \param ids Directory to match data to its graph entry
 * \param graph Graph of all points
 * \return Pointer to the minimum of the heap
 */
int64 pop(int64 N, int64 *queue, int64 *tree,
           datum **ids, uint64 **graph) {
  if (N < 1)
    return CANARY;

  int64 min = queue[0];
  queue[0] = queue[N - 1];

  min_heapify(N - 1, queue, tree, ids, graph, 0);

  return min;
}

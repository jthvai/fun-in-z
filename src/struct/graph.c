// SPDX-License-Identifier: X11

#include "graph.h"

static uint64 weight(datum *src, datum *dest);

/*!
 * Initialise an undirected complete graph of squared Euclidean distances.
 *
 * \param N Size of array
 * \param idlist List of points
 * \return Adjacency matrix of edge weights
 */
uint64 **init_graph(int64 N, datum **idlist) {
  uint64 **m = (uint64 **) calloc(N, sizeof(uint64 *));
  for (int64 i = 0; i < N; i++)
    m[i] = (uint64 *) calloc(N, sizeof(uint64));

  for (int64 i = 0; i < N; i++)
    for (int64 j = 0; j < N; j++)
      m[i][j] = weight(idlist[i], idlist[j]);

  return m;
}

/*!
 * Calculates the squared Euclidean distance between two points.
 *
 * \param src Starting point
 * \param dest Finishing point
 * \return The squared Euclidean distance between the two points
 */
static uint64 weight(datum *src, datum *dest) {
  return (uint64) (llabs(src->x - dest->x) * llabs(src->x - dest->x) +
                   llabs(src->y - dest->y) * llabs(src->y - dest->y));
}

/*!
 * Free memory in use by a graph.
 * \param N Width of matrix
 * \param graph Graph to free
 */
void free_graph(uint64 N, uint64 **graph) {
  for (uint64 i = 0; i < N; i++)
    free(graph[i]);
  free(graph);
}

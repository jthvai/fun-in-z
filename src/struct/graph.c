// SPDX-License-Identifier: X11

#include "graph.h"

static uint64 weight(struct datum *src, struct datum *dest);

/*!
 * Parses the contents of a file, and stores it in an array.
 *
 * \param idlist Array to store into
 * \param fn Name of file to parse
 * \param src Source for Dijkstra
 * \param dest Destination for Dijkstra
 * \return Updated array, terminated with a NULL. The first element
 *         is the datum with name `src` if found, and the second is `dest`.
 */
struct datum **parse_inf_graph(struct datum **idlist, const char *fn,
                               char *src, char *dest) {
  return NULL;
}

/*!
 * Initialise an undirected graph with edges between a source and each
 * postential destination.
 *
 * \param src Source point
 * \param idlist List of destinations to consider, where the index of each
 *               datum in this array denotes its index in the adjacency
 *               matrix, terminated with a NULL.
 * \return Adjacency matrix of edge weights
 */
uint32 **init_graph(struct datum *src, struct datum **idlist) {
  return NULL;
}

/*!
 * Calculates the manhattan distance between two points.
 *
 * \param src Starting point
 * \param dest Finishing point
 * \return The manhattan distance between the two points
 */
static uint64 weight(struct datum *src, struct datum *dest) {
  return 0;
}

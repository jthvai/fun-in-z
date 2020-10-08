// SPDX-License-Identifier: X11

#include "dijkstra.h"

static void print_ans(struct datum **ans);
static struct datum **dijkstra(uint64 **graph, struct datum **idlist,
                               struct datum *src, struct datum *dest);
static uint64 **relax(uint64 **graph, struct datum **idlist,
                      struct datum*u, struct datum*v);

/*!
 * Interface to Dijkstra from the CLI.
 *
 * \param idlist Array of corresponding points
 * \param src Name of source point
 * \param dest Name of destination point
 * \return `EXIT_SUCCESS` (0) if the function terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int dijkstra_cli(struct datum **idlist, char *src, char *dest) {
  fprintf(stderr, "Dijkstra (CLI) not yet implemented.\n");
  return EXIT_SUCCESS;
}

/*!
 * Interface to Dijkstra from the REPL.
 *
 * \param idlist Array of corresponding points
 * \param src Name of source point
 * \param dest Name of destination point
 * \return `EXIT_SUCCESS` (0) if the function terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int dijkstra_repl(struct datum **idlist, char *src, char *dest) {
  fprintf(stderr, "Dijkstra (REPL) not yet implemented.\n");
  return EXIT_SUCCESS;
}

/*!
 * Pretty-print the output of Dijkstra's algorithm.
 *
 * \param ans Path to print
 */
static void print_ans(struct datum **ans) {
  return;
}

/*!
 * Calculate the path with the shortest squared Euclidean distance between
 * two points.
 *
 * \param graph Adjacency matrix of edge weights
 * \param idlist Array of corresponding points
 * \param src Source point
 * \param dest Destination point
 * \return Ordered array of data, representing the path
 */
static struct datum **dijkstra(uint64 **graph, struct datum **idlist,
                               struct datum *src, struct datum *dest) {
  return NULL;
}

/*!
 * Relaxes an edge between two points in the graph.
 *
 * \param graph Adjacency matrix of edge weights
 * \param idlist Array of corresponding points
 * \param u,v Vertices of the edge to relax
 * \return Updated graph
 */
static uint64 **relax(uint64 **graph, struct datum **idlist,
                      struct datum*u, struct datum*v) {
  return NULL;
}

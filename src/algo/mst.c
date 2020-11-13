// SPDX-License-Identifier: X11

#include "mst.h"

static int64 parse_inf_ids(int64 cnt, datum **ids, const char *fn);

static int64 find_edge(int64 id, int64 *tree, uint64 **graph);

/*!
 * Computes the minimum spanning tree from input files.
 *
 * \param argc Number of arguments of `main()`
 * \param argv Array of argumet strings of `main()`
 * \param optind Index of the first non-option argument of `main()`
 * \return `EXIT_SUCCESS` (0) if the function terminated without error,
 *         `EXIT_FAILURE` (1) otherwise
 */
int mst_cli(int argc, char *const argv[], int optind) {
  datum **ids = (datum **) calloc(MAX_N, sizeof(datum *));
  int64 cnt = 0;
  for (int i = optind; i < argc && cnt < MAX_N; i++)
    cnt = parse_inf_ids(cnt, ids, argv[i]);

  linked_list **mst = construct_mst(cnt, ids);

  FILE *outfp = fopen(OUTPUT_FILENAME, "w+");
  if (outfp == NULL) {
    fprintf(stderr, "Failed to open " OUTPUT_FILENAME "\n"
                    "Dumping results to stdout...\n");
    print_mst(cnt, mst, ids, stdout);

    for (int64 i = 0; i < cnt; i++)
      free(ids[i]);
    free(ids);

    return EXIT_FAILURE;
  }
  else {
    print_mst(cnt, mst, ids, stdout);

    fclose(outfp);
    for (int64 i = 0; ids[i] != NULL && i < cnt; i++)
      free(ids[i]);
    free(ids);

    return EXIT_SUCCESS;
  }
}

/*!
 * Parse the contents of a file, storing into an array.
 *
 * \param cnt Index of current open slot in array
 * \param ids Array to store into
 * \param fn Name of file to parse
 * \return Total number of data points read
 */
static int64 parse_inf_ids(int64 cnt, datum **ids, const char *fn) {
  FILE *fp = fopen(fn, "r");
  if (fp == NULL) {
    fprintf(stderr, "Failed to open %s\n", fn);
    return 0;
  }

  datum *dp;
  while ((dp = read_datum(fp)) != NULL) {
    ids[cnt] = dp;
    cnt++;
  }

  fclose(fp);
  return cnt;
}

/*!
 * Compute a minimum spanning tree.
 *
 * \param N Number of data points
 * \param ids Points to consider
 * \return Adjacency list representing a minimum spanning tree
 */
linked_list **construct_mst(int64 N, datum **ids) {
  uint64 **graph = init_graph(N, ids);

  int64 *queue = (int64 *) calloc(N, sizeof(int64));
  for (int64 i = 0; i < N; i++)
    queue[i] = i;

  int64 *tree = (int64 *) calloc(N, sizeof(int64));
  int64 canary = 0;
  tree[canary] = CANARY;

  build_minheap(N, queue, tree, ids, graph);

  linked_list **mst = (linked_list **) calloc(N, sizeof(linked_list **));

  int64 next, dest;
  for (int64 i = 0; i < N; i++) {
    next = pop(N, queue, tree, ids, graph);
    if (next == CANARY)
      break;

    dest = find_edge(next, tree, graph);

    mst[next] = cons(mst[next], ids[dest]);
    mst[dest] = cons(mst[dest], ids[next]);

    tree[canary] = next;
    canary++;
    tree[canary] = CANARY;
  }

  free_graph(N, graph);
  free(queue);
  free(tree);

  return mst;
}

/*!
 * Print the minimum spanning tree to a stream. Free memory after.
 *
 * \param N Number of vertices in tree
 * \param mst Minimum spanning tree to print
 * \param ids Array to store into
 * \param fp Stream to print to
 */
void print_mst(int64 N, linked_list **mst, datum **ids, FILE *fp) {
  for (int64 i = 0; i < N; i++) {
    datum *cur = ids[i];
    for (linked_list *p = mst[i]; p != NULL; p = p->n) {
      fprintf(fp, "%s %d %d -> %s %d %d\n",
              cur->name, cur->x, cur->y,
              p->dp->name, p->dp->x, p->dp->y);
    }
    free_list(mst[i]);
  }

  free(mst);
}

/*!
 * Find the edge associated with a vertex.
 *
 * \param id ID of datum for which to find the edge
 * \param tree Current minimum spanning tree
 * \param graph Graph of all points
 */
static int64 find_edge(int64 id, int64 *tree, uint64 **graph) {
  uint64 min = 0;
  int64 dest = 0;

  if (tree[0] != CANARY) {
    min = graph[id][tree[0]];
    dest = tree[0];
  }
  for (int64 i = 1; tree[i] != CANARY; i++) {
    if (graph[id][tree[i]] < min) {
      min = graph[id][tree[i]];
      dest = tree[i];
    }
  }

  return dest;
}

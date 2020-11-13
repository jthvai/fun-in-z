// SPDX-License-Identifier: X11

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../util.h"

/*!
 * An AVL tree node.
 *
 * \struct avl_tree
 * \typedef avl_tree
 */
typedef struct avl_tree {
  datum *dp;          /*!< Node value */
  int32 bal;          /*!< Balance factor */
  bool delta;         /*!< Whether height changed */
  struct avl_tree *l; /*!< Left child */
  struct avl_tree *r; /*!< Right child */
} avl_tree;

avl_tree *insert(avl_tree *node, datum *dp);
datum *search(avl_tree *node, char name[]);
void free_tree(avl_tree *root);

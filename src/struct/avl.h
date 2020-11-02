// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

/*!
 * An AVL tree node.
 *
 * \typedef avl_tree
 */
typedef struct avl_tree_t {
  datum d;              /*!< Node value */
  int32 bal;            /*!< Balance factor */
  struct avl_tree_t *l; /*!< Left child */
  struct avl_tree_t *r; /*!< Right child */
} avl_tree;

avl_tree *insert(avl_tree *node, datum *dp);
datum *search(avl_tree *node, char name[]);

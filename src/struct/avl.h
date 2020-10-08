// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

/*!
 * An AVL tree node.
 *
 * `bal` stores the balance value of this node, and `l`, `r` point to the
 * left and right subtrees respectively.
 */
struct avl {
  struct datum datum;
  int32 bal;
  struct avl *l;
  struct avl *r;
};

struct avl *insert(struct avl *node, struct datum *datum);
struct datum *search(struct avl *node, char name[]);

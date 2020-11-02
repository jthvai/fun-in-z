// SPDX-License-Identifier: X11

#include "avl.h"

static avl_tree *make_node(datum d);
static avl_tree *left_rot(avl_tree *node);
static avl_tree *right_rot(avl_tree *node);

/*!
 * Creates a single node out of a datum.
 *
 * \param datum Datum to wrap
 * \return Pointer to the created node
 */
static avl_tree *make_node(datum d) {
  return NULL;
}

/*!
 * Inserts a single datum into an AVL tree.
 *
 * \param root Tree to insert into
 * \param datum Datum to insert
 * \return Pointer to the updated tree
 */
avl_tree *insert(avl_tree *root, datum *dp) {
  return NULL;
}

/*!
 * Restores the AVL property of a binary tree after insertion.
 *
 * \param root Tree to restore
 * \param node New inserted node
 * \return Pointer to the restored tree
 */
static avl_tree *insert_fix(avl_tree *root, avl_tree *node) {
  return NULL;
}

/*!
 * Search for a datum by its name.
 *
 * \param root Tree to search in
 * \param name Name of datum to search for
 * \return Pointer to the datum with the same name if it exists, or NULL if
 *         it could not be found
 */
datum *search(avl_tree *root, char name[]) {
  return NULL;
}

/*!
 * Do a left rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static avl_tree *left_rot(avl_tree *root) {
  return NULL;
}

/*!
 * Do a right rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static avl_tree *right_rot(avl_tree *root) {
  return NULL;
}

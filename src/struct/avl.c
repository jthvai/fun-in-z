// SPDX-License-Identifier: X11

#include "avl.h"

static struct avl *make_node(struct datum datum);
static struct avl *left_rot(struct avl *node);
static struct avl *right_rot(struct avl *node);

/*!
 * Creates a single node out of a datum.
 *
 * \param datum Datum to wrap
 * \return Pointer to the created node
 */
static struct avl *make_node(struct datum datum) {
  return NULL;
}

/*!
 * Inserts a single datum into an AVL tree.
 *
 * \param root Tree to insert into
 * \param datum Datum to insert
 * \return Pointer to the updated tree
 */
struct avl *insert(struct avl *root, struct datum datum) {
  return NULL;
}

/*!
 * Restores the AVL property of a binary tree after insertion.
 *
 * \param root Tree to restore
 * \param node New inserted node
 * \return Pointer to the restored tree
 */
static struct avl *insert_fix(struct avl *root, struct avl *node) {
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
struct datum *search(struct avl *root, char name[]) {
  return NULL;
}

/*!
 * Do a left rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static struct avl *left_rot(struct avl *root) {
  return NULL;
}

/*!
 * Do a right rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static struct avl *right_rot(struct avl *root) {
  return NULL;
}

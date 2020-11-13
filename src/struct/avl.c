// SPDX-License-Identifier: X11

#include "avl.h"

static avl_tree *make_node(datum *dp);
static avl_tree *insert_leaf(avl_tree *root, avl_tree *leaf);

static avl_tree *left_rot(avl_tree *node);
static avl_tree *right_rot(avl_tree *node);
static avl_tree *left_right_rot(avl_tree *root);
static avl_tree *right_left_rot(avl_tree *root);

/*!
 * Inserts a single datum into an AVL tree.
 *
 * \param root Tree to insert into
 * \param datum Datum to insert
 * \return Pointer to the updated tree
 */
avl_tree *insert(avl_tree *root, datum *dp) {
  return insert_leaf(root, make_node(dp));
}

/*!
 * Creates a single node out of a datum.
 *
 * \param dp Pointer to datum to wrap
 * \return Pointer to the created node
 */
static avl_tree *make_node(datum *dp) {
  avl_tree *r = (avl_tree *) calloc(1, sizeof(avl_tree));
  r->dp = dp;
  r->bal = 0;
  r->delta = false;
  r->l = NULL;
  r->r = NULL;
  return r;
}

/*!
 * Inserts a single leaf into an AVL tree.
 *
 * \param root Tree to insert into
 * \param leaf Leaf to insert
 * \return Pointer to the updated tree
 */
static avl_tree *insert_leaf(avl_tree *root, avl_tree *leaf) {
  if (root == NULL)
    return leaf;

  int cmp = strcmp(leaf->dp->name, root->dp->name);

  if (cmp == 0) {
    fprintf(stderr, "Duplicate name in data, skipping...\n");
    free_tree(leaf);
  }
  else if (cmp < 0) { // Insert into left subtree
    if (root->l == NULL) { // Insert directly as root's child
      if (root->r == NULL) { // root has no right subtree
        root->bal = -1; // New node makes root left-heavy
        root->delta = true; // Height of this subtree has changed
      }
      else { // root->r != NULL
        root->bal = 0;
        root->delta = false;
      }
      root->l = leaf;
    }
    else { // root->l != NULL; Insert as root's grandchild
      insert_leaf(root->l, leaf);

      if (root->l->delta) { // Check if the height has changed
        root->bal--; // Adjust balance factor

        if (root->bal < -1) { // Tree is unbalanced
          if (root->l->bal < 0) // Left-left insertion
            root = right_rot(root);
          else // root->l->bal > 0; Left-right insertion
            root = left_right_rot(root);
        }
        else {
          root->delta = true; // Propagate change in height
        }

        root->l->delta = false;
      }
    }
  }
  else if (cmp > 0) { // Insert into right subtree
    if (root->r == NULL) { // Insert directly as root's child
      if (root->l == NULL) { // root has no left subtree
        root->bal = 1; // New node makes root right-heavy
        root->delta = true; // Height of this subtree has changed
      }
      else { // root->l != NULL
        root->bal = 0;
        root->delta = false;
      }
      root->r = leaf;
    }
    else { // root->r != NULL; Insert as root's grandchild
      insert_leaf(root->r, leaf);

      if (root->r->delta) { // Check if the height has changed
        root->bal++; // Adjust balance factor

        if (root->bal > 1) { // Tree is unbalanced
          if (root->r->bal > 0) // Right-right insertion
            root = left_rot(root);
          else // root->r->bal < 0; Right-left insertion
            root = right_left_rot(root);
        }
        else {
          root->delta = true; // Propagate change in height
        }

        root->r->delta = false;
      }
    }
  }

  return root;
}

/*!
 * Do a left rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static avl_tree *left_rot(avl_tree *root) {
  // Subjects
  avl_tree *x = root;
  avl_tree *y = root->r;
  avl_tree *z = root->r->r;

  // Children of subjects; may be NULL
  avl_tree *c = root->r->l;

  x->r = c;
  y->l = x;
  y->r = z;

  x->bal = 0;
  y->bal = 0;

  root = y;
  return root;
}

/*!
 * Do a right rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static avl_tree *right_rot(avl_tree *root) {
  // Subjects
  avl_tree *x = root;
  avl_tree *y = root->l;
  avl_tree *z = root->l->l;

  // Children of subjects; may be NULL
  avl_tree *c = root->l->r;

  x->l = c;
  y->l = z;
  y->r = x;

  x->bal = 0;
  y->bal = 0;

  root = y;
  return root;
}

/*!
 * Do a left-right rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static avl_tree *left_right_rot(avl_tree *root) {
  // Subjects
  avl_tree *y = root->l;
  avl_tree *z = root->l->r;

  // Children of subjects; may be NULL
  avl_tree *c = root->l->r->l;

  y->r = c;
  z->l = y;

  y->bal = 0;
  z->bal = 1;

  // Complete final rotation
  root = right_rot(root);

  return root;
}

/*!
 * Do a right-left rotation on a tree.
 *
 * \param root Node to rotate on
 * \return Pointer to the root after rotation
 */
static avl_tree *right_left_rot(avl_tree *root) {
  // Subjects
  avl_tree *y = root->r;
  avl_tree *z = root->r->l;

  // Children of subjects; may be NULL
  avl_tree *c = root->r->l->r;

  y->l = c;
  z->r = y;

  y->bal = 0;
  z->bal = 1;

  // Complete final rotation
  root = left_rot(root);

  return root;
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
  if (root == NULL)
    return NULL;

  int cmp = strcmp(name, root->dp->name);

  if (cmp == 0)
    return root->dp;
  else if (cmp < 0)
    return search(root->l, name);
  else // cmp > 0
    return search(root->r, name);
}

/*!
 * Flatten tree into a linked list.
 *
 * \param root Tree to flatten
 * \param list List to attach onto
 */
linked_list *flatten_tree(avl_tree *root, linked_list *list) {
  if (root == NULL)
    return list;
  return flatten_tree(root->r, cons(flatten_tree(root->l, list), root->dp));
}

/*!
 * Flatten tree into an array
 *
 * \param root Tree to flatten
 * \param list List to attach onto
 */
int64 flatten_tree_arr(datum **ids, int64 cnt, avl_tree *root) {
  if (root == NULL)
    return cnt;

  cnt = flatten_tree_arr(ids, flatten_tree_arr(ids, cnt, root->l), root->r);
  ids[cnt] = root->dp;

  return cnt + 1;
}

/*!
 * Free memory in use by a tree.
 *
 * \param root Root of tree to free
 */
void free_tree(avl_tree *root) {
  if (root == NULL)
    return;

  free_tree(root->l);
  free_tree(root->r);

  free(root->dp);
  free(root);
}

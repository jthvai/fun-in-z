// SPDX-License-Identifier: X11

#include "ll.h"

static linked_list *make_node(datum *dp);

/*!
 * Attach a new node to the head of a list.
 *
 * \param list List to attach to
 * \param dp Pointer to datum to attach
 * \return Head of new linked list
 */
linked_list *cons(linked_list *list, datum *dp) {
  linked_list *head = make_node(dp);
  head->n = list;
  return head;
}

/*!
 * Creates a single node out of a datum.
 *
 * \param dp Pointer to datum to wrap
 * \return Pointer to the created node
 */
static linked_list *make_node(datum *dp) {
  linked_list *l = (linked_list *) calloc(1, sizeof(linked_list));
  l->dp = dp;
  l->n = NULL;
  return l;
}

/*!
 * Free memory in use by a linked list.
 *
 * Note that the datum pointer is specifically not freed, as it still holds
 * relevance in an AVL tree.
 *
 * \param list List to free
 */
void free_list_shallow(linked_list *list) {
  if (list == NULL)
    return;

  free_list_shallow(list->n);
  free(list);
}

/*!
 * Free memory in use by a linked list.
 *
 * \param list List to free
 */
void free_list(linked_list *list) {
  if (list == NULL)
    return;

  free_list(list->n);
  free(list->dp);
  free(list);
}

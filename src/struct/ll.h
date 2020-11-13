// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

/*!
 * A linked list node.
 *
 * \struct linked_list
 * \typedef linked_list
 */
typedef struct linked_list {
  datum *dp;             /*!< Node value */
  struct linked_list *n; /*!< Next node */
} linked_list;

linked_list *cons(linked_list *list, datum *dp);

void free_list_shallow(linked_list *list);
void free_list(linked_list *list);

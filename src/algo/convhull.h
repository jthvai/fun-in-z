// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

#include "../struct/avl.h"
#include "../struct/frame.h"
#include "../struct/ll.h"

int convhull_repl(int argc, char *const argv[], int optind);
linked_list *construct_hull(linked_list *all);

void print_convex_hull(linked_list *hull, FILE *fp);

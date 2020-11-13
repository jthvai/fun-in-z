// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

#include "../struct/graph.h"
#include "../struct/heap.h"
#include "../struct/ll.h"

int mst_cli(int argc, char *const argv[], int optind);
linked_list **construct_mst(int64 N, datum **ids);

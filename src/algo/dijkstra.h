// SPDX-License-Identifier: X11

#pragma once

#include <stdio.h>

#include "../util.h"

#include "../struct/graph.h"
#include "../struct/heap.h"

int dijkstra_cli(struct datum **idlist, char *start, char *end);
int dijkstra_repl(struct datum **idlist, char *start, char *end);

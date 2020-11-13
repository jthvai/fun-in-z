// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

void build_minheap(int64 N, int64 *queue, int64 *tree,
                   datum **ids, uint64 **graph);

int64 pop(int64 N, int64 *queue, int64 *tree,
          datum **ids, uint64 **graph);

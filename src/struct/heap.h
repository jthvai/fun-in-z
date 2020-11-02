// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

datum *build_minheap(datum **data);

datum **push(datum **data, datum *dp, uint64 key);
datum *peek(datum **data);
datum *pop(datum **data);

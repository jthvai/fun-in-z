// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

struct datum *build_minheap(struct datum **data);

uint64 value(struct datum *src, struct datum *dest);
struct datum **push(struct datum **data, struct datum *datum, uint64 key);
struct datum *peek(struct datum **data);
struct datum *pop(struct datum **data);

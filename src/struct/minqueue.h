// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

struct datum *build_minheap(struct datum *data);

struct datum *push(struct datum *data, int key);
struct datum peek(struct datum *data);
struct datum pop(struct datum *data);

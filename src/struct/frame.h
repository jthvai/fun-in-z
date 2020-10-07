// SPDX-License-Identifier: X11

#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "avl.h"

struct avl **init_frame();
int parse_inf(struct avl **frame, const uint32 seed, const char *fn);

struct datum *get_by_name(struct avl **frame, const uint32 seed,
                          char name[]);
int *add_datum(struct avl **frame, const uint32 seed, struct datum datum);

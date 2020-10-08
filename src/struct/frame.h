// SPDX-License-Identifier: X11

#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "../util.h"

#include "avl.h"

/*!
 * Width of the frame, an AVL matrix.
 *
 * \def FRAME_WIDTH
 */
#define FRAME_WIDTH 64

struct avl **init_frame();
void parse_inf_frame(struct avl **frame, const uint32 seed[],
                     const char *fn);
int free_frame(struct avl **frame);

struct datum *get_by_name(struct avl **frame, const uint32 seed[],
                          char name[]);
struct avl **add_datum(struct avl **frame, const uint32 seed[],
                       struct datum datum);
struct datum **flatten(struct avl **frame, char *src, char *dest);

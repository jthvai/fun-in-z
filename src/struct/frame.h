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

avl_tree **init_frame();
void parse_inf_frame(avl_tree **frame, const uint32 seed[],
                     const char *fn);
int free_frame(avl_tree **frame);

datum *get_by_name(avl_tree **frame, const uint32 seed[],
                          char name[]);
avl_tree **add_datum(avl_tree **frame, const uint32 seed[],
                       datum *dp);
datum **flatten(avl_tree **frame, char *src, char *dest);

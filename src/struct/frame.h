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

// avl_tree ***init_frame();
void parse_inf_frame(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                     const uint32 seed[3], const char *fn);
void free_forest(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH]);

datum *get_by_name(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                   const uint32 seed[3], char name[]);
void add_datum(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                      const uint32 seed[3], datum *dp);
// datum **flatten(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH], char *src, char *dest);

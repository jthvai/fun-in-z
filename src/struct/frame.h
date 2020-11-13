// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

#include "avl.h"

/*!
 * Width of the frame, an AVL matrix.
 *
 * \def FRAME_WIDTH
 */
#define FRAME_WIDTH 64

void parse_inf_frame(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                     const uint32 seed[3], const char *fn);

datum *get_by_name(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                   const uint32 seed[3], char name[]);
void add_datum(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH],
                      const uint32 seed[3], datum *dp);

linked_list *flatten(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH]);
int64 flatten_arr(datum **ids, int64 cnt,
                  avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH]);

void free_forest(avl_tree *frame[FRAME_WIDTH][FRAME_WIDTH]);

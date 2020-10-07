// SPDX-License-Identifier: X11

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_MAXLENGTH 32

typedef int_least8_t   int8;
typedef int_least16_t  int16;
typedef int_least32_t  int32;
typedef int_least64_t  int64;
typedef uint_least8_t  uint8;
typedef uint_least16_t uint16;
typedef uint_least32_t uint32;
typedef uint_least64_t uint64;

struct datum {
  char name[NAME_MAXLENGTH + 1];
  int64 x;
  int64 y;
};
#define NEW_DATUM {"",0,0}
void print_datum(struct datum *datum);

void clear_stdin();

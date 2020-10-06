// SPDX-License-Identifier: X11

#include <stdint.h>
#include <stdlib.h>

typedef int_least8_t   int8;
typedef int_least16_t  int16;
typedef int_least32_t  int32;
typedef int_least64_t  int64;
typedef uint_least8_t  uint8;
typedef uint_least16_t uint16;
typedef uint_least32_t uint32;
typedef uint_least64_t uint64;

struct datum {
  const char *name;
  const int64 x;
  const int64 y;
};

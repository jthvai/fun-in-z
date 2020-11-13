// SPDX-License-Identifier: X11

#pragma once

#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * Maximum length for the name of a datum.
 *
 * \def NAME_MAXLENGTH
 */
#define NAME_MAXLENGTH 32

/*!
 * Convert to string.
 *
 * \def _STR(s)
 * \def STR(s)
 */
#define _STR(s) #s
#define STR(s) _STR(s)

/*!
 * Solution to \f$2^{64} > (x - (-x))^2 + (x - (-x))^2\f$.
 *
 * Defined such that the maximum possible squared Euclidean distance does
 * not cause an integer overflow.
 *
 * \def XY_MAX
 */
#define XY_MAX 379625062

/*!
 * Integer types of "known" sizes.
 *
 * \typedef int8
 * \typedef int16
 * \typedef int32
 * \typedef int64
 * \typedef uint8
 * \typedef uint16
 * \typedef uint32
 * \typedef uint64
 */
typedef int_least8_t   int8;
typedef int_least16_t  int16;
typedef int_least32_t  int32;
typedef int_least64_t  int64;
typedef uint_least8_t  uint8;
typedef uint_least16_t uint16;
typedef uint_least32_t uint32;
typedef uint_least64_t uint64;

/*!
 * A single point in the plane.
 *
 * \typedef datum
 */
typedef struct {
  char name[NAME_MAXLENGTH + 1]; /*!< Name of point, null-terminated */
  int32 x;                       /*!< X coordinate of point */
  int32 y;                       /*!< Y coordinate of point */
} datum;

datum *read_datum(FILE *fp);
void print_datum(datum *dp);

int fpeek(FILE *fp);
void clear_stream(FILE *fp);

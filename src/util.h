// SPDX-License-Identifier: X11

#pragma once

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
 * NEW_DATUMP is initialised to 0.
 *
 * `name` contains the name of the point as a null-terminated string. `x`,
 * `y` store the coordinates of the point, respectively.
 *
 * \struct datum
 * \def NEW_DATUM
 */
struct datum {
  char name[NAME_MAXLENGTH + 1];
  int32 x;
  int32 y;
};
#define NEW_DATUMP (struct datum *) calloc(1, sizeof(struct datum))
struct datum *read_datum(FILE *fp);
void print_datum(struct datum *datum);

void readname(char name[]);
void clear_stdin();

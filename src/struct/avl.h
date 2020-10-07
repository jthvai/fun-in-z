// SPDX-License-Identifier: X11

#pragma once

#include "../util.h"

struct avl {
  struct datum datum;
  int32 bal;
  struct avl *l;
  struct avl *r;
};

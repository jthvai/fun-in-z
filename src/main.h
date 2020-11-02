// SPDX-License-Identifier: X11

#pragma once

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "util.h"

#include "struct/frame.h"

#include "algo/convhull.h"
#include "algo/mst.h"

int repl(int argc, char *const argv[], int optind);

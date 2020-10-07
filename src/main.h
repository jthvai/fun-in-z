// SPDX-License-Identifier: X11

#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "struct/frame.h"

#include "algo/convhull.h"
#include "algo/dijkstra.h"

#include "util.h"

void repl(int argc, char *const argv[], int optind);

// SPDX-License-Identifier: X11

#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "util.h"

#include "struct/frame.h"

#include "algo/convhull.h"
#include "algo/dijkstra.h"

int repl(int argc, char *const argv[], int optind);

// SPDX-License-Identifier: X11

#include "../util.h"

struct datum **parse_inf_graph(struct datum **idlist, const char *fn,
                               char *src, char *dest);

uint32 **init_graph(struct datum *src, struct datum **idlist);

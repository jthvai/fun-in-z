# SPDX-License-Identifier: X11

src = $(wildcard src/*/*.c src/*.c)
obj = $(src:.c=.o)

CC = gcc
CFLAGS = -O2 -fsanitize=address,undefined -lm \
				 -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-function
LDFLAGS = -fuse-ld=gold -flto

zfun: $(obj)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(obj)

CLEAN:
	$(RM) zfun $(obj)

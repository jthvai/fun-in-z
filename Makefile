# SPDX-License-Identifier: X11

src = $(wildcard src/*/*.c src/*.c)
obj = $(src:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-function

zfun: $(obj)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(obj)

# SPDX-License-Identifier: X11

src = $(wildcard src/*/*.c src/*.c)
obj = $(src:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

zfun: $(obj)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(obj)

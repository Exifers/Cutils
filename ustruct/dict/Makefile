bin := main

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

debug : CFLAGS += -g

src := $(shell find -name '*.c')
obj := $(shell echo $(src) | sed 's/\.c/\.o/g')

all: $(obj)
	$(CC) $(CFLAGS) $(src) -o $(bin)

debug : $(obj)
	$(CC) $(CFLAGS) $^ -o $(bin)

clean:
	$(RM) $(obj) $(bin)

.PHONY: all debug clean

srcdir := src/
bin    := main

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

debug : CFLAGS += -g

src := $(shell find $(srcdir) -name *.c)
obj := $(src:%.c=%.o)

all: $(obj)
	$(CC) $(CFLAGS) $^ -o $(bin)

debug : $(obj)
	$(CC) $(CFLAGS) $^ -o $(bin)

clean:
	$(RM) $(obj) $(bin)

.PHONY: all debug clean

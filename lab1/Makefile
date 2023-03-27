CC := gcc
CFLAGS := -fopenmp -Wall -g -std=c99
TARGET := maxnum

# $(wildcard *.cpp /xxx/xxx/*.c): get all .c files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.c)
# $(patsubst %.c,%.o,$(SRCS)): substitute all ".c" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

maxnum: hr2378-code.c
	$(CC) $(CFLAGS) -o maxnum hr2378-code.c

random: random-char.c
	$(CC) $(CFLAGS) -o genfile random-char.c

clean:
	rm maxnum

clean-random:
	rm genfile
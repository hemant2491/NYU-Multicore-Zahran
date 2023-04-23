CC := gcc
# CFLAGS := -fopenmp -Wall -g -std=c99
CFLAGS := -O3 -std=c99 -Wall -fopenmp
LFLAGS := -lm

maxnum: genprime.c
	$(CC) $(CFLAGS) -o genprime genprime.c $(LFLAGS)

clean:
	rm genprime

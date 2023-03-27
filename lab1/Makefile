CC := gcc
CFLAGS := -fopenmp -Wall -g -std=c99

maxnum: hr2378-code.c
	$(CC) $(CFLAGS) -o maxnum hr2378-code.c

random: random-char.c
	$(CC) $(CFLAGS) -o genfile random-char.c

clean:
	rm maxnum

clean-random:
	rm genfile
CC = gcc
AOC_CFLAGS = $(CFLAGS) -std=c99 -pedantic -Wall -Werror -ggdb -I. -Ilib
AOC_LDFLAGS = ${LDFLAGS}
OUTPUTS = day1 #day2 day3 day4 day5 day6 day7 day8 day9 day10 day11 day12 day13 day14 day15 day16 day17 day18 day19 day20 day21 day22 day23 day24

NEEDED_FILES = lib/fmmap/fmmap.h lib/vstr/vstr.h utils.h

.PHONY: all
all: $(OUTPUTS)

day%: %/main.o %/input utils.o
	$(CC) $(AOC_LDFLAGS) -o $@ $< utils.o

.SECONDARY:
utils.o: utils.c utils.h
	$(CC) $(AOC_CFLAGS) -o $@ -c $<

.SECONDARY:
%.o: %.c 
	$(CC) $(AOC_CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f day* *.o */*.o

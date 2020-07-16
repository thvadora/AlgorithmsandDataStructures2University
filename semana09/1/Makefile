CC = gcc
CCFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
OBJECTS = string.o helpers.o dict_helpers.o dict.o main.o map.o

.PHONY: clean run_test

all: dictionary
%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $^

dictionary: string.o helpers.o dict_helpers.o dict.o main.o map.o
	$(CC) $(CCFLAGS) -o $@ $^

run: dictionary
	./dictionary

run-valgrind: dictionary
	valgrind --show-reachable=yes --leak-check=full  ./dictionary

clean:
	rm -f dictionary $(OBJECTS)
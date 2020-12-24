CC = gcc
FLAGS = -Wall 

all: main

main: isort.o txtfind.o
	$(CC) $(FLAGS) -o main.o isort.o txtfind.o

isort.o: isort.c
	$(CC) $(FLAGS)  -o isort.o isort.c 

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -o txtfind.o txtfind.c 

.PHONY: clean

clean:
	rm -rf *.o *.a *.gch *.so 
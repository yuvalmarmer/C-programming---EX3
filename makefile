CC = gcc
FLAGS = -Wall 

all: isort txtfind



isort: isort.c
	$(CC) $(FLAGS)  -o isort isort.c 

txtfind: txtfind.c
	$(CC) $(FLAGS) -o txtfind txtfind.c 

.PHONY: clean

clean:
	rm -rf *.o *.a *.gch *.so 

CC=gcc
CFLAGS=-c -Wall
all: hello
hello: home.o function1.o
	$(CC) home.o function1.o -o hello
home.o:	home.c
	$(CC) $(CFLAGS) home.c
function1:	function1.c
	$(CC) $(CFLAGS) function1.c
clean:
	rm -rf *o hello
CC=gcc
CFLAGS=-c -Wall
all: account
account: main.o user.o businessLayer.o
	$(CC) main.o user.o businessLayer.o -o account
main.o:	main.c
	$(CC) $(CFLAGS) main.c
businessLayer.o:	businessLayer.c
	$(CC) $(CFLAGS) businessLayer.c
user.o:	user.c
	$(CC) $(CFLAGS) user.c

clean:
	rm -rf *o account
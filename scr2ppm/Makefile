CC = gcc
CFLAGS = -Wall -pedantic -ggdb -Werror 
  
main:	scr2ppm.o 
	$(CC) $(CFLAGS) scr2ppm.o -o scr2ppm $(LDFLAGS)

scr2ppm.o: scr2ppm.c scr2ppm.h
	$(CC) $(CFLAGS) -c scr2ppm.c

.PHONY:	clean 

clean:
	/bin/rm -f scr2ppm.o scr2ppm *~





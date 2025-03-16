
CC = gcc
CFLAGS = -Wall -lrt 

testptp: testptp.c
	$(CC) $(CFLAGS) $^ -o $@ 
install: 
	cp testptp /usr/bin/
clean:
	-rm -f tes
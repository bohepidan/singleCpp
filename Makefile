CC=g++
CFLAGS=-Wall -c -g
LDFLAGS=-Wall -g
OFLAGS=-Wall -g -O3

.PHONY: clean 

all : a.out

opt : o.out

testopt : opt 
	./o.out

test : a.out
	./a.out

o.out : single.cc
	$(CC) $(OFLAGS) $^ -o $@

a.out: single.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

single.o : single.cc



clean: 
	rm -f *.o a.out

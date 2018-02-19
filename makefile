CC=g++
CFLAGS=-Wall -Werror -g -std=c++11
MAINDEBUG=main_debug.cpp
MAINDEBUGOBJ=$(addsuffix .o, $(basename $(MAINDEBUG)))
HEADER=include/BigInteger.h
OUTFILE=test.out

SRCDIR=src
SRCFILES=$(shell find $(SRCDIR) -type f -name "*.cpp")
SRCOBJS=$(addsuffix .o, $(basename $(SRCFILES)))

TESTDIRS=unit_tests
TESTFILES=$(foreach dir, $(TESTDIRS), $(shell find $(dir) -type f -name "*.cpp"))
TESTOBJS=$(addsuffix .o, $(basename $(TESTFILES)))

all: $(SRCOBJS) $(HEADER)

debug: all $(MAINDEBUGOBJ)
	$(CC) $(CFLAGS) $(SRCOBJS) $(MAINDEBUGOBJ) -o $(OUTFILE)
	./$(OUTFILE)

test: all $(TESTOBJS) $(MAINTESTOBJ)
	$(CC) $(CFLAGS) $(SRCOBJS) $(TESTOBJS) $(MAINTESTOBJ) -o $(OUTFILE)
	./$(OUTFILE)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCOBJS) 
	rm -f $(TESTOBJS) $(MAINTESTOBJ)
	rm -f $(OUTFILE)

CC=g++
CFLAGS=-Wall -Werror -g -std=c++14
TESTDIRS=test
MAINDEBUG=$(TESTDIRS)/main_debug.cpp
MAINDEBUGOBJ=$(addsuffix .o, $(basename $(MAINDEBUG)))
MAINTEST=$(TESTDIRS)/main_test.cpp
MAINTESTOBJ=$(addsuffix .o, $(basename $(MAINTEST)))
HEADER=include/BigInteger.h
OUTFILE=test.out

SRCDIR=src
SRCFILES=$(shell find $(SRCDIR) -type f -name "*.cpp")
SRCOBJS=$(addsuffix .o, $(basename $(SRCFILES)))

TESTFILES=$(foreach dir, $(TESTDIRS), $(shell find $(dir) -type f -name "*.cpp"))
TESTFILES:=$(filter-out $(MAINTEST), $(TESTFILES))
TESTFILES:=$(filter-out $(MAINDEBUG), $(TESTFILES))
TESTOBJS=$(addsuffix .o, $(basename $(TESTFILES)))

all: $(SRCOBJS) $(HEADER)

static: all
	ar rvs lib/libBigInteger.a $(SRCOBJS) $(HEADER)

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

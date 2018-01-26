CC=g++
CFLAGS=-Wall -Werror -g -std=c++11
MAINFILES=*.cpp
TESTFILE=test.out

SOURCEFILES=$(shell find . -type f -name "*.cpp")
OBJECTS=$(addsuffix .o, $(basename $(SOURCEFILES)))

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS) BigInteger.h
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TESTFILE)

clean:
	rm -f $(OBJECTS)
	rm -f $(TESTFILE)

CC=g++
CFLAGS=-Wall -Werror -g -std=c++11
TESTFILE=test.out
SOURCEFILES=$(shell find . -type f -name "*.cpp")
OBJECTS=$(addsuffix .o, $(basename $(SOURCEFILES)))

%.o: %.cpp BigInteger.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TESTFILE)

test: all
	./$(TESTFILE)

clean:
	rm -f $(OBJECTS)
	rm -f $(TESTFILE)

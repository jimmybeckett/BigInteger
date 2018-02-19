CC=g++
CFLAGS=-Wall -Werror -g -std=c++11
MAINFILE=main.cpp
MAINOBJECT=$(addsuffix .o, $(basename $(MAINFILE)))
HEADER=BigInteger.h
OUTFILE=test.out

SOURCEDIRS:=methods operators
SOURCEFILES=$(foreach dir, $(SOURCEDIRS), $(shell find $(dir) -type f -name "*.cpp"))
SOURCEOBJECTS=$(addsuffix .o, $(basename $(SOURCEFILES)))

TESTDIRS=unitTests
TESTFILES=$(foreach dir, $(TESTDIRS), $(shell find $(dir) -type f -name "*.cpp"))
TESTOBJECTS=$(addsuffix .o, $(basename $(TESTFILES)))


all: $(SOURCEOBJECTS) $(MAINOBJECT) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCEOBJECTS) $(MAINOBJECT) -o $(OUTFILE)
	./$(OUTFILE)

test: $(SOURCEOBJECTS) $(TESTOBJECTS) $(MAINOBJECT) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCEOBJECTS) $(TESTOBJECTS) $(MAINOBJECT) -o $(OUTFILE)
	./$(OUTFILE)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOURCEOBJECTS) $(TESTOBJECTS) $(MAINOBJECT)
	rm -f $(OUTFILE)

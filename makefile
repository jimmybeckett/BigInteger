CC=g++
CFLAGS=-Wall -Werror -g -std=c++11
MAINTEST=main_test.cpp
MAINTESTOBJ=$(addsuffix .o, $(basename $(MAINTEST)))
MAINDEBUG=main_debug.cpp
MAINDEBUGOBJ=$(addsuffix .o, $(basename $(MAINDEBUG)))
HEADER=BigInteger.h
OUTFILE=test.out

SOURCEDIRS:=methods operators
SOURCEFILES=$(foreach dir, $(SOURCEDIRS), $(shell find $(dir) -type f -name "*.cpp"))
SOURCEOBJECTS=$(addsuffix .o, $(basename $(SOURCEFILES)))

TESTDIRS=unitTests
TESTFILES=$(foreach dir, $(TESTDIRS), $(shell find $(dir) -type f -name "*.cpp"))
TESTOBJECTS=$(addsuffix .o, $(basename $(TESTFILES)))


debug: $(SOURCEOBJECTS) $(MAINDEBUGOBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCEOBJECTS) $(MAINDEBUGOBJ) -o $(OUTFILE)
	./$(OUTFILE)

test: $(SOURCEOBJECTS) $(TESTOBJECTS) $(MAINTESTOBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCEOBJECTS) $(TESTOBJECTS) $(MAINTESTOBJ) -o $(OUTFILE)
	./$(OUTFILE)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOURCEOBJECTS) $(TESTOBJECTS) $(MAINTESTOBJ) $(MAINDEBUGOBJ)
	rm -f $(OUTFILE)

CC=gcc
CFLAGS=-c -Wall

SOURCES_DIR=src/
EXECUTABLE_DIR=bin/

SOURCES=$(SOURCES_DIR)integral.c
EXECUTABLE=$(EXECUTABLE_DIR)integral

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE_DIR)integral.o
	$(CC) $(EXECUTABLE_DIR)integral.o -o $(EXECUTABLE)

$(EXECUTABLE_DIR)integral.o: makedir $(SOURCES_DIR)integral.c
	$(CC) $(CFLAGS) $(SOURCES_DIR)integral.c -o $(EXECUTABLE_DIR)integral.o


makedir:
	mkdir -p $(EXECUTABLE_DIR)

clean:
	rm -f $(EXECUTABLE_DIR)*.o $(EXECUTABLE)
	rmdir -p --ignore-fail-on-non-empty $(EXECUTABLE_DIR)
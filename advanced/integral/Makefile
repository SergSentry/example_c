CC=gcc
CFLAGS=-c -Wall

SOURCES_DIR=src/
EXECUTABLE_DIR=bin/

SOURCES=$(SOURCES_DIR)integral.c $(SOURCES_DIR)function.h $(SOURCES_DIR)preset_function.c
EXECUTABLE=$(EXECUTABLE_DIR)integral

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE_DIR)integral.o $(EXECUTABLE_DIR)preset_function.o
	$(CC) $(EXECUTABLE_DIR)integral.o $(EXECUTABLE_DIR)preset_function.o -o $(EXECUTABLE)

$(EXECUTABLE_DIR)preset_function.o: makedir $(SOURCES_DIR)preset_function.c $(SOURCES_DIR)preset_function.h
	$(CC) $(CFLAGS) $(SOURCES_DIR)preset_function.c -o $(EXECUTABLE_DIR)preset_function.o

$(EXECUTABLE_DIR)integral.o: makedir $(SOURCES_DIR)integral.c $(SOURCES_DIR)function.h 
	$(CC) $(CFLAGS) $(SOURCES_DIR)integral.c -o $(EXECUTABLE_DIR)integral.o


makedir:
	mkdir -p $(EXECUTABLE_DIR)

clean:
	rm -f $(EXECUTABLE_DIR)*.o $(EXECUTABLE)
	rmdir -p --ignore-fail-on-non-empty $(EXECUTABLE_DIR)
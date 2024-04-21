
CC := gcc

BIN_DIR := $(CURDIR)/bin
OBJ_DIR := $(CURDIR)/obj
SOURCE_DIR := $(CURDIR)/src
TARGET := statistica

all: preapre $(TARGET)

preapre:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	cd $(BIN_DIR)

$(TARGET): $(OBJ_DIR)/statistica.o $(OBJ_DIR)/temp_api.o
	$(CC) -o $(BIN_DIR)/$(TARGET) $(OBJ_DIR)/statistica.o $(OBJ_DIR)/temp_api.o 

$(OBJ_DIR)/statistica.o: $(SOURCE_DIR)/statistica.c
	$(CC) -c -o $(OBJ_DIR)/statistica.o $(SOURCE_DIR)/statistica.c

$(OBJ_DIR)/temp_api.o:
	$(CC) -c -o $(OBJ_DIR)/temp_api.o $(SOURCE_DIR)/temp_api.c

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)
	rmdir $(OBJ_DIR) $(BIN_DIR)
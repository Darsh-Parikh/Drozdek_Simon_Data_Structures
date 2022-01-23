
CC = gcc
CFLAGS = -g -Wall -Werror

SRC_DIR = src
OBJ_DIR = obj

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst %, $(OBJ_DIR)/%, $(notdir $(SOURCES:.c=.o)))
TARGET = lintTest.exe

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(SRC_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	del /f $(OBJ_DIR)\* $(TARGET)

help:
	@echo "src: $(SOURCES)"
	@echo "obj: $(OBJECTS)"

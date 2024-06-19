# Define compiler and flags
CC = gcc
CFLAGS = -g -Iinclude

# Define the executable name
TARGET = matrix_calc

# Define source directories
SRC_DIR = src
OPS_DIR = src/operations

# Find all source files in the defined directories
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(OPS_DIR)/*.c)

# Define object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean

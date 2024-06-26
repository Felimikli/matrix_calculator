
# Define compiler and flags
CC = gcc
CFLAGS = -g -Iinclude

# Define the executable name
TARGET = matrix_calc

# Define source directories
SRC_DIR = src
OPS_DIR = src/operations

# Define object directory
OBJ_DIR = .obj

# Find all source files in the defined directories
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(OPS_DIR)/*.c)

# Define object files with object directory
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)  # Create the directory for the object file
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_FILES) $(TARGET)

.PHONY: all clean

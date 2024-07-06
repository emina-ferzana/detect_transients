# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I. -I./examples -I./interface

# Source files
SRC = main.c

# Object files
OBJ = $(SRC:.c=.o)

# Static library
LIB = detect_transients.a

# Executable name
EXEC = myProgram

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ) $(LIB)
	$(CC) -o $@ $^ -lm -fopenmp -lsndfile

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean


# Compiler and assembler
CC = cc
ASM = nasm

# Flags
CFLAGS = -Wall -Wextra -Werror
ASMFLAGS = -f elf64

# Source files
ASM_SRC = srcs/mandatory/ft_strlen.asm \
		  srcs/mandatory/ft_write.asm
C_SRC = srcs/mandatory/main.c

# Object files
ASM_OBJ = $(ASM_SRC:.asm=.o)
C_OBJ = $(C_SRC:.c=.o)

# Static library
LIB_NAME = libasm.a

# Output executable for testing
TEST_NAME = main

# Default target
all: $(LIB_NAME)

# Create the static library
$(LIB_NAME): $(ASM_OBJ)
	ar rcs $@ $^

# Assemble the Assembly code
%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

# Compile the C code
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build and link the test executable
test: $(LIB_NAME) $(C_OBJ)
	$(CC) $(C_OBJ) -L. -lasm -o $(TEST_NAME)

# Clean up object files and library
clean:
	rm -f $(ASM_OBJ) $(C_OBJ)

fclean: clean
	rm -f $(LIB_NAME) $(TEST_NAME)

# Rebuild everything
re: fclean all
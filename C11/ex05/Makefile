# Name of the output file
NAME = do-op

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = do_op.c operations.c ft_atoi.c ft_putnbr.c
OBJ = $(SRC:.c=.o)
# Rules

# Default rule: build the library
all: $(NAME)

# Rule to compile .c files to .o files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to clean up object files
clean:
	rm -f $(OBJ)

# Rule to clean up object files
fclean: clean
	rm -f $(NAME)

#Rule to recompile the project
re: fclean all

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re
# Name of the output file
NAME = ft_cat

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_cat.c helper_functions.c
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
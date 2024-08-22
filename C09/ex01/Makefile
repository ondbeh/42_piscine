# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = srcs
INCLUDES_DIR = includes

# Source files and corresponding object files
SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_swap.c \
	   $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_strlen.c \
	   $(SRCS_DIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

# Include header files
INCLUDES = -I $(INCLUDES_DIR)

# Rules

# Default rule: build the library
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

# Rule to compile .c files to .o files
%.o: %.c $(INCLUDES_DIR)/ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to clean up object files
clean:
	rm -f $(OBJS)

# Rule to clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rule to rebuild everything from scratch
re: fclean all

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re
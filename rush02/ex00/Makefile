# Name of the library
NAME = rush-02

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = srcs
INCLUDES_DIR = includes

# Source files and corresponding object files
SRCS = $(SRCS_DIR)/ft_split.c $(SRCS_DIR)/ft_get_file_str.c \
		$(SRCS_DIR)/main.c  $(SRCS_DIR)/ft_build_dict.c \
		$(SRCS_DIR)/ft_utils.c $(SRCS_DIR)/ft_print_nbr.c \
		$(SRCS_DIR)/print_utils.c 

OBJS = $(SRCS:.c=.o)

# Include header files
INCLUDES = -I $(INCLUDES_DIR)

# Rules

# Default rule: build the project
all: $(NAME)

# Rule to create the project
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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
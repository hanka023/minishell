# Název výsledného programu
NAME = mini

# Překladač a příznaky
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft -I gnl -I utils -I fPie -g -fsanitize=address

LDFLAGS     = -Llibft -lft 
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a


# Seznam všech .c souborů
SRC = main.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		lexer/metachar.c \
		lexer/my_split_utils.c \
		lexer/my_split.c \
		lexer/quotes.c \
		lexer/t_list.c \
		lexer/word.c \
		src/checker.c \
		src/expander.c	\
		src/getenv.c

# Změna koncovek .c na .o pro objekty
OBJ = $(SRC:.c=.o)

# Hlavní pravidlo
all: $(NAME)

# Jak vytvořit výsledný program z objektů
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Pravidlo pro promazání objektových souborů
clean:
	rm -f $(OBJ)

# Pravidlo pro kompletní smazání (včetně programu)
fclean: clean
	rm -f $(NAME)

# Pravidlo pro "přestavbu" od nuly
re: fclean all

.PHONY: all clean fclean re
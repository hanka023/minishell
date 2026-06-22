# Název výsledného programu
NAME = mini

# Překladač a příznaky
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft -I gnl -I utils  -I fPie -g -fsanitize=address
 # CFLAGS = -Wall -Wextra -Werror -I libft -I gnl -I utils  -I fPie -g 

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
LDFLAGS     = -Llibft -lft 

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
		expander/expander_utils.c \
		expander/expander.c	\
		expander/getenv.c \
		expander/quotes_remove.c \
		checker/checker.c \
		checker/quotes.c \
		checker/pipes.c \
		checker/redirect.c 
		

# Změna koncovek .c na .o pro objekty
OBJ = $(SRC:.c=.o)

# Hlavní pravidlo
all: $(NAME)

# Jak vytvořit výsledný program z objektů
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)


$(LIBFT):
	make -C $(LIBFT_DIR)
# Pravidlo pro promazání objektových souborů
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

# Pravidlo pro kompletní smazání (včetně programu)
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Pravidlo pro "přestavbu" od nuly
re: fclean all

.PHONY: all clean fclean re
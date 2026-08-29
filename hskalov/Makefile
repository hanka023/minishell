# Název výsledného programu
NAME = mini


# Překladač a příznaky
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft -I gnl -I utils  -I fPie -g -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -I libft -I gnl -I utils  -I fPie -g
# DBGF = -g -fsanitize=address,leak

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
LDFLAGS     = -Llibft -lft

# Seznam všech .c souborů
SRC = main.c \
		expander/double_expander.c \
		expander/env_utils.c \
		expander/expander_utils.c \
		expander/expander_1.c	\
		expander/expander_2.c	\
		expander/getenv_1.c \
		expander/getenv_2.c \
		expander/string.c \
		expander/strlen.c \
		expander/utils.c \
		expander/names.c \
		expander/zero_one_two_handler.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		checker/checker.c \
		checker/quotes.c \
		checker/names.c \
		checker/pipes.c \
		checker/redirect_1.c \
		checker/redirect_2.c \
		lexer/my_split_utils.c \
		lexer/my_split.c \
		lexer/quotes.c \
		lexer/word.c \
		main_lst/main_utils_1.c \
		main_lst/main_utils_2.c \
		main_lst/t_list.c \
		main_lst/t_list_env.c \
		main_lst/change_env.c \
		main_lst/find_env.c

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

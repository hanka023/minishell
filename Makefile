NAME = mini

CC = cc
CFLAGS = -Wall -Werror -Wextra
DBGFLAGS = -g -fsanitize=leak,address,origin

SOURCES = \
	main.c			\
	setup_cleanup.c	\
	\
	map/map_add.c		\
	map/map_change.c	\
	map/map_dup.c		\
	map/map_free.c		\
	map/map_get.c		\
	map/map_print.c		\
	map/map_remove.c	\
	map/map_search.c	\
	map/map_utils.c		\
	\
	parser/expander/double_expander.c 		\
	parser/expander/env_utils.c 			\
	parser/expander/expander_utils.c 		\
	parser/expander/expander_1.c			\
	parser/expander/expander_2.c			\
	parser/expander/getenv_1.c 				\
	parser/expander/getenv_2.c 				\
	parser/expander/string.c 				\
	parser/expander/strlen.c 				\
	parser/expander/utils.c 				\
	parser/expander/names.c 				\
	parser/expander/zero_one_two_handler.c 	\
	parser/gnl/get_next_line_utils.c 		\
	parser/gnl/get_next_line.c 				\
	parser/checker/checker.c 				\
	parser/checker/quotes.c 				\
	parser/checker/names.c 					\
	parser/checker/pipes.c 					\
	parser/checker/redirect_1.c 			\
	parser/checker/redirect_2.c 			\
	parser/lexer/my_split_utils.c 			\
	parser/lexer/my_split.c 				\
	parser/lexer/quotes.c 					\
	parser/lexer/word.c 					\
	parser/main_lst/main_utils_1.c 			\
	parser/main_lst/main_utils_2.c 			\
	parser/main_lst/t_list.c 				\
	parser/main_lst/t_list_env.c 			\
	parser/main_lst/change_env.c 			\
	parser/main_lst/find_env.c				\


LIBRARIES = Lib42/lib42.a

.PHONY: all $(NAME) debug clean fclean gen clean_gen re

all: $(NAME)
$(NAME):
	@cd Lib42; make
	@$(CC) $(CFLAGS) $(SOURCES) $(LIBRARIES) -o $(NAME)

debug: CFLAGS += $(DBGFLAGS)
debug: re

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

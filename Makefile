NAME = mini

CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=leak,address

SOURCES = \
	main.c	\
	\
	jkralice/mini/setup.c	\
	jkralice/mini/cleanup.c	\
	jkralice/mini/input.c	\
	\
	jkralice/map/map_add.c		\
	jkralice/map/map_change.c	\
	jkralice/map/map_dup.c		\
	jkralice/map/map_free.c		\
	jkralice/map/map_get.c		\
	jkralice/map/map_print.c	\
	jkralice/map/map_remove.c	\
	jkralice/map/map_search.c	\
	jkralice/map/map_utils.c	\
	\
	hskalov/expander/double_expander.c	 	\
	hskalov/expander/env_utils.c	 		\
	hskalov/expander/expander_utils.c	 	\
	hskalov/expander/expander_1.c			\
	hskalov/expander/expander_2.c			\
	hskalov/expander/getenv_1.c	 			\
	hskalov/expander/getenv_2.c	 			\
	hskalov/expander/string.c	 			\
	hskalov/expander/strlen.c	 			\
	hskalov/expander/utils.c	 			\
	hskalov/expander/names.c	 			\
	hskalov/expander/zero_one_two_handler.c	\
	hskalov/gnl/get_next_line_utils.c	 	\
	hskalov/gnl/get_next_line.c	 			\
	hskalov/checker/checker.c	 			\
	hskalov/checker/quotes.c	 			\
	hskalov/checker/names.c	 				\
	hskalov/checker/pipes.c	 				\
	hskalov/checker/redirect_1.c	 		\
	hskalov/checker/redirect_2.c	 		\
	hskalov/lexer/my_split_utils.c	 		\
	hskalov/lexer/my_split.c	 			\
	hskalov/lexer/quotes.c	 				\
	hskalov/lexer/word.c	 				\
	hskalov/main_lst/main_utils_1.c	 		\
	hskalov/main_lst/main_utils_2.c	 		\
	hskalov/main_lst/t_list.c	 			\
	hskalov/main_lst/t_list_env.c	 		\
	hskalov/main_lst/change_env.c	 		\
	hskalov/main_lst/find_env.c				\

LIBRARIES = \
	jkralice/Lib42/lib42.a		\
	hskalov/gnl/get_next_line.a	\
	hskalov/libft/libft.a		\

.PHONY: all $(NAME) debug clean fclean gen clean_gen re

all: $(NAME)
$(NAME):
	@cd jkralice/Lib42; make
	@cd hskalov/libft; make
	@cd hskalov/gnl; make
	@$(CC) $(CFLAGS) $(SOURCES) $(LIBRARIES) -o $(NAME)

clean:
	@cd jkralice/Lib42; make clean
	@cd hskalov/libft; make clean
	@cd hskalov/gnl; make clean
	@rm -f $(OBJECTS)

fclean: clean
	@cd jkralice/Lib42; make fclean
	@cd hskalov/libft; make fclean
	@cd hskalov/gnl; make fclean
	@rm -f $(NAME)

re: fclean $(NAME)

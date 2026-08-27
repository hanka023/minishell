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

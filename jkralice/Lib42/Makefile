NAME = lib42.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
DBGFLAGS = -g -fsanitize=leak,address

SOURCES = \
	types/int.c		\
	types/size.c	\
	types/ssize.c	\
	\
	str/str_cat.c	\
	str/str_len.c	\
	str/str_eq.c	\
	str/str_sub.c	\
	str/str_split.c	\
	\
	memory/bytes.c			\
	memory/mem_compare.c	\
	memory/mem_copy.c		\
	memory/mem_move.c		\
	memory/mem_search.c		\
	memory/mem_set.c		\
	\
	arena/arena_advance.c			\
	arena/arena_clear.c				\
	arena/arena_create.c			\
	arena/arena_destroy.c			\
	arena/arena_pop.c				\
	arena/arena_pop_to.c			\
	arena/arena_push.c				\
	arena/arena_scratch_claim.c		\
	arena/arena_scratch_create.c	\
	arena/arena_scratch_destroy.c	\
	arena/arena_scratch_release.c	\
	arena/arena_temp_begin.c		\
	arena/arena_temp_end.c			\
	arena/_global_scratch.c			\
	\
	list/_list/_dllnode.c			\
	list/_list/_dllist_create.c		\
	list/_list/_dllist_add.c		\
	list/_list/_dlist_get.c			\
	list/_list/_dlist_remove.c		\
	list/_list/_dllist_clear.c		\
	list/_list/_dllist_copy.c		\
	list/_list/__dllnode_data.c		\
	list/_list/__dllnode_allocate.c	\
	\
	list/ppl/ppl_add.c				\
	list/ppl/ppl_clear.c			\
	list/ppl/ppl_copy.c				\
	list/ppl/ppl_create.c			\
	list/ppl/ppl_get.c				\
	list/ppl/ppl_node.c				\
	list/ppl/ppl_remove.c			\
	pipeline/ppl_create_function.c	\
	pipeline/ppl_create_process.c	\
	pipeline/ppl_run.c				\
	pipeline/_ppl_run.c				\
	pipeline/ppl_wait.c				\
	pipeline/ppl_signal.c			\
	pipeline/ppl_close.c			\
	pipeline/find_executable.c		\


OBJECTS = $(SOURCES:.c=.o)

.PHONY: all $(NAME) clean fclean gen clean_gen re

all: $(NAME)
$(NAME): $(OBJECTS)
	@ar rcs $@ $^

debug: CFLAGS += $(DBGFLAGS)
debug: clean $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

gen:
	@./list/generate.sh t_ppl_link ppl_chain ppl_node "../pipeline/pipeline_link.h"

clean_gen:
	@echo Removing generated lists...
	@mv list/generate.sh	list/.generate.sh
	@mv list/_list			list/._list
	@rm -fr list/*
	@mv list/.generate.sh 	list/generate.sh
	@mv list/._list 		list/_list

re: clean $(NAME)

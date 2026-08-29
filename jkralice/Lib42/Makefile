NAME = lib42.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
DBGFLAGS = -g -fsanitize=leak,address,origin

SOURCES = \
	types/size.c	\
	types/ssize.c	\
	\
	str/str_cat.c	\
	str/str_eq.c	\
	str/str_len.c	\
	str/str_split.c	\
	str/str_sub.c	\
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
	list/_dlist/_dlist_add.c		\
	list/_dlist/_dlist_clear.c		\
	list/_dlist/_dlist_copy.c		\
	list/_dlist/_dlist_create.c 	\
	list/_dlist/_dlist_get.c		\
	list/_dlist/_dlist_getters.c	\
	list/_dlist/_dlist_remove.c		\
	list/_dlist/_dnode.c			\
	\
	list/ppl_chain/ppl_node.c			\
	list/ppl_chain/ppl_chain_create.c	\
	list/ppl_chain/ppl_chain_add.c		\
	list/ppl_chain/ppl_chain_getters.c	\
	list/ppl_chain/ppl_chain_get.c		\
	list/ppl_chain/ppl_chain_remove.c	\
	list/ppl_chain/ppl_chain_clear.c	\
	list/ppl_chain/ppl_chain_copy.c		\
	\
	pipeline/find_executable.c					\
	pipeline/pipeline_create.c					\
	pipeline/pipeline_add_function.c			\
	pipeline/pipeline_add_process.c				\
	pipeline/pipeline_clear.c					\
	pipeline/pipeline_run.c						\
	pipeline/pipeline_wait.c					\
	pipeline/pipeline_stop.c					\
	pipeline/pipeline_kill.c					\
	pipeline/_pipeline_run_link.c				\


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
	@./list/generate.sh t_ppl_link t_ppl_chain ppl_chain t_ppl_node ppl_node "../pipeline/pipeline_link.h"

clean_gen:
	@echo Removing generated lists...
	@mv list/generate.sh	list/.generate.sh
	@mv list/_dlist			list/._dlist
	@rm -fr list/*
	@mv list/.generate.sh 	list/generate.sh
	@mv list/._dlist 		list/_dlist

re: clean $(NAME)

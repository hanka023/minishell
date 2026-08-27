#ifndef     MINISHELL_H
#define     MINISHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "expander/parser.h"
#include "checker/checker.h"
#include "lexer/lexer.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
	char			type;
}	t_list;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
	char			type;
}	t_list;

void line_to_lst(char *line, t_env *env, t_state *state);

#endif


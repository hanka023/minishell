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
#include "main_lst/lst.h"

typedef struct s_list t_list;
typedef struct s_env t_env;
typedef struct s_state t_state;

void line_to_lst(t_env *env, t_state *state);

#endif


#ifndef CHECKER_H
# define CHECKER_H

# include "../minishell.h" 

typedef struct s_env t_env;

/* * * * * * * checker.c  * * * * * * * * */

int check_line(char *str, t_env *env);

/* * * * * * * quotes.c  * * * * * * * * */

int check_quotes(char *str);
int check_double_quotes(char *str);

/* * * * * * *   check_names.c   * * * * * * * * */

int check_names(char *str, t_env *env);
int test_name(char *str, t_env *env);


/* * * * * * *   pipes.c   * * * * * * * * */

int check_pipes(char *str);


/* * * * * * *   redirect.c   * * * * * * * * */

int check_redirect(char *str);


#endif
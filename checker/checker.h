#ifndef CHECKER_H
# define CHECKER_H

# include "../minishell.h" 

/* * * * * * * checker.c  * * * * * * * * */

int check_line(char *str);

/* * * * * * * quotes.c  * * * * * * * * */

int check_quotes(char *str);
int check_double_quotes(char *str);
int check_line(char *str);



/* * * * * * *   pipes.c   * * * * * * * * */

int check_pipes(char *str);


/* * * * * * *   redirect.c   * * * * * * * * */

int check_redirect(char *str);


#endif
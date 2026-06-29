#ifndef     MINISHELL_H 
#define     MINISHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "expander/parser.h"
#include "checker/checker.h"


typedef struct s_list
{
	char			*str; 
	struct s_list	*prev;
	struct s_list	*next;
} t_list;


/* * * * * * * metachar * * * * * * * * */


int		metachar(char *str, t_list **head);
int		pipe_char(char *str, t_list **head);
int		red_in(char *str, t_list **head);
int		red_out(char *str, t_list **head);


/* * * * * * * word * * * * * * * * */


int		word(char *str, t_list **head);


/* * * * * * my_split_utils * * * * * */


int		is_in_set(char c, char *set);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);


/* * * * * * * my_split * * * * * * * * */


t_list	*my_split(char *s);
t_list	*my_str_to_lst(t_list **head, char *str);
char	*my_copy_word(char *start, char *end);


/* * * * * * * quotes * * * * * * * * */


int quotes(char *str);
int single_quote(char *str);
int double_quotes(char *str);


/* * * * * * * t_list.c * * * * * * * * */


t_list	*str_to_lst(int argc, char **argv);
t_list	*new_list(char *str);
void	add_back(t_list **head, t_list *new);
void	print_list(t_list *begin_list);
void	free_list(t_list *lst);


/* * * * * * * t_list.c * * * * * * * * */


int checker(t_list *lst);
// int expander(t_list *lst, t_env *env);
void expand(char *string);


int quotes_remove(t_list *lst);



// t_list **word_to_lst(char *str, t_list **head_w);
// int expander(t_list *lst, t_env *env);


#endif


#ifndef     MINISHELL_H 
#define     MINISHELL_H


#include <stdio.h>
#include <unistd.h>
#include "gnl/get_next_line.h"


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
int		print_word(char *str, t_list **head);


/* * * * * * my_split_utils * * * * * */


int		is_in_set(char c, char *set);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);


/* * * * * * * my_split * * * * * * * * */


t_list	*my_split(char *s);
t_list	*my_str_to_lst(t_list **head, char *str);
char	*my_copy_word(char *start, char *end);


/* * * * * * * quotes * * * * * * * * */


int quotes(char *str, t_list **head);
int single_quote(char *str, t_list **head);
int double_quotes(char *str, t_list **head);


/* * * * * * * t_list.c * * * * * * * * */


t_list	*str_to_lst(int argc, char **argv);
t_list	*new_list(char *str);
void	add_back(t_list **head, t_list *new);
void	print_list(t_list **begin_list);
void	free_list(t_list *lst);


#endif


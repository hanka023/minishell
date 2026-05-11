#ifndef     MINISHELL_H 
#define     MINISHELL_H


#include <stdio.h>
#include <unistd.h>

#include "gnl/get_next_line.h"

typedef struct s_list
{
	char			*str; // 1 token
	//int				type;
	struct s_list	*prev;
	struct s_list	*next;
} t_list;


char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*spaces(char *str, char *set);

/* * * * * * * linked list * * * * * * * * */


t_list *str_to_lst(int argc, char **argv);
t_list *new_list(int value);
void	add_back(t_list **head, t_list *new);
void print_list(t_list *begin_list);
void free_list(t_list *lst);



#endif


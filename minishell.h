#ifndef     MINISHELL_H 
#define     MINISHELL_H


#include <stdio.h>
#include <unistd.h>

#include "gnl/get_next_line.h"

typedef struct s_list
{
	char			*str; // 1 token
	//int 			type;
	struct s_list	*prev;
	struct s_list	*next;
} t_list;

typedef struct 


/* * * * * * * ft_split * * * * * * * * */


int		count_words(const char *s, char c);
int		world_len(char *s, char c);
void	free_split(char **result, int count);
int		copy_word(char **result, int i, char *s, char c);
char	**ft_split(char *s, char c);


/* * * * * * * ft_strtrim * * * * * * * * */

int		is_in_set(char c, char *set);
char	*ft_strtrim(char *s1, char *set);
char	*spaces( char *str, char *set); //?????



/* * * * * * * my_split * * * * * * * * */


int		is_in_set(char c, char *set);
t_list *my_split(char *s);
t_list *my_str_to_lst(t_list **head, char *str);
char	*my_copy_word(char *start, char *end);



/* * * * * * * my_split_utils * * * * * * * * */





/* * * * * * * main * * * * * * * * */


char	*ft_strtrim(char *s1, char  *set);
char	*spaces(char *str, char *set);


/* * * * * * * linked list * * * * * * * * */

t_list	*str_to_lst(int argc, char **argv);
t_list	*new_list(char *str);
void	add_back(t_list **head, t_list *new);
void	print_list(t_list *begin_list);
void	free_list(t_list *lst);


/* * * * * * split_utils * * * * * */


char	*z1(char *str);
char	*z2(char *str);


/* * * * * * my_split_utils * * * * * */

int is_in_set(char c, char *set);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);


/* * * * * * * metachar * * * * * * * * */


void	metachar(char *str);
void	pipe_char(char *str);
void	red_in(char *str);
void	red_out(char *str);





#endif


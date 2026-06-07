#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h" 

// typedef enum e_type
// {
// 	WORD,
// 	PIPE,
// 	RED_IN,
// 	RED_OUT, 
// 	APPEND, 
// 	HEREDOC
// }	t_type;



typedef struct s_env
{
	char			*str; 
	char 			*name;
	char 			*value;
	struct s_env	*prev;
	struct s_env	*next;
} t_env;

// typedef struct s_list
// {
// 	char			*str; 
// 	struct s_list	*prev;
// 	struct s_list	*next;
// } t_list;

/* * * * * * * checker.c  * * * * * * * * */



/* * * * * * * expander  * * * * * * * * */


int		my_strlen(char *str);
int		my_strlen2(char **str);
char	*f_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*get_env(char *str);
char	*find_$(char *str);



/* * * * * * * checker.c  * * * * * * * * */


//int checker(t_list *lst);
// void expander(t_list *lst);
//void expand(char *string);


/* * * * * * * getenv  * * * * * * * * */


t_env	*env_to_lst();
void	env_name(char *str, t_env *env);
void	env_value(char *str, t_env *env);
t_env	*new_env(char *str);
void	env_add_back(t_env **head, t_env *env);
void	print_env(t_env *env);
void	free_env(t_env *env);

/* * * * * * * getenv  * * * * * * * * */


#endif
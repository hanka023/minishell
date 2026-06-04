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

/* * * * * * * getenv  * * * * * * * * */


t_env	*env_to_lst();
void	env_name(char *str, t_env *env);
void	env_value(char *str, t_env *env);
t_env	*new_env(char *str);
void	env_add_back(t_env **head, t_env *env);
void	print_env(t_env **env);
void	free_env(t_env *env);




#endif
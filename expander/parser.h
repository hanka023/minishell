#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h" 


typedef struct s_list t_list;
// typedef struct s_env t_env;


// typedef enum e_type
// {
// 	WORD,
// 	PIPE,
// 	RED_IN,
// 	RED_OUT, 
// 	APPEND, 
// 	HEREDOC
// }	t_type;


// typedef struct s_line
// {
// 	char *str;
// 	char *name;
// 	char *value;
// 	char *prev;
// 	char *next;
// } t_line;


typedef struct s_env
{
	char			*str; 
	char 			*name;
	char 			*value;
	struct s_env	*prev;
	struct s_env	*next;
} t_env;



/* * * * * * * checker.c  * * * * * * * * */

/* * * * * * * expander - utils  * * * * * * * * */

int my_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
void check_last_qt(char *str);

/* * * * * * * expander  * * * * * * * * */


int		my_strlen(char *str);
int		my_strlen2(char **str);
char	*f_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*get_env(char *str);
char  	*find_$(char *str);




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

/* * * * * * * expander * * * * * * * * */
  


// int expander(t_list *lst, t_env *env);



/* * * * * * * double expander * * * * * * * * */


//t_list **word_to_lst(char *str, t_list **head_w);
//t_list *word_to_lst(char *str, t_list *head_w);
void	word_to_lst(char *str, t_list **head_w);
int		expander(t_list *lst, t_env *env);
int		strlen_word(char *str);
char	*two_trim(char *str);

/* * * * * * * env_utils.c * * * * * * */


char	env_cmp(char *copy, t_env *env);
int		env_len(char *str, t_env *env);
char	*copy_env(char *str, t_env *env);
char	*env_handler(t_list *lst);
char	*find_env(char *str, t_env *env);


/* * * * * * * string_utils.c * * * * * * * * */

char *copy_string_zero(char *str, char c);
char *copy_string(char *str, char c);

/* * * * * * * utils.c * * * * * * * * */


char	*find_$(char *str);
int		expand_len(t_list *lst, t_env *env);
int		strlen_zero(char *str);
int		strlen_one(char *str);
int		strlen_two(char *str);


/* * * * * * * utils2.c * * * * * * * */

char	*ft_strldup(const char *str, int len);
int		strlen_name(char *str);
int		test_name(char *str, t_env *env);
int		test_names(char *str, t_env *env);
char	*find_name(char *str, t_env *env);





#endif
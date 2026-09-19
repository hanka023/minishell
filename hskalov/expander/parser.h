/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 16:27:16 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

typedef struct s_list	t_list;
typedef struct s_env	t_env;
typedef struct s_state	t_state;

/* * * * * * * double expander * * * * * * * * */

char	*two_trim(char *str);
char	*one_trim(char *str);
char	*word_prepare(char *str);
void	word_to_lst(char *str, t_list **head_w);
int		strlen_word(char *str);

/* * * * * * * env_utils.c * * * * * * */

char	env_cmp(char *copy, t_env *env);
int		env_len(char *str, t_env *env);
char	*copy_env(char *str, t_env *env);
char	*env_handler(t_list *lst, char **envp);
char	*find_env(char *str, t_env *env);

/* * * * * * * expander_1 * * * * * * * * */

int		expand_status(char *str, t_state *state, t_list **head_w);
int		expand_name(char *str, t_env *env, t_list **head_w);
t_list	*two_lst(char *s, t_env *env, t_state *state);

/* * * * * * * expander_2 * * * * * * * * */

char	*expand_metachar(char *str);
char	*expand_str(char *str, t_env *env, int *len, t_state *state);
char	*expand_string(char *str, t_env *env, t_state *state);
char	*expand_lst(t_list *lst, t_env *env, t_state *state);
int		expander(t_list *lst, t_env *env, t_state *state);

/* * * * * * * expander - utils  * * * * * * * * */

int		is_in_set(char c, char *set);
int		my_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	check_last_qt(char *str);
char	*ft_strldup(const char *str, int len);

/* * * * * * * getenv_1  * * * * * * * * */

t_env	*env_to_lst(char **environ);
void	env_name(char *str, t_env *env);
void	env_value(char *str, t_env *env);
t_env	*new_env(char *str);
void	env_add_back(t_env **head, t_env *env);

/* * * * * * * getenv_2  * * * * * * * * */

void	print_env(t_env *env);
void	free_env(t_env *env);

/* * * * * * * names.c * * * * * * * */

int		strlen_name(char *str);
int		test_names(char *str, t_env *env);
int		name_len(char *str);
char	*copy_name(char *str);
char	*find_name(char *str, t_env *env);

/* * * * * * * string.c * * * * * * * * */

char	*copy_string_zero(char *str, char c);
char	*copy_string(char *str, char c);

/* * * * * * * strlen.c * * * * * * * * */

int		strlen_zero(char *str);
int		strlen_zero_zero(char *str);
int		strlen_one(char *str);
int		strlen_two(char *str);

/* * * * * * * utils.c * * * * * * * * */

char	*find_dollar(char *str);
int		expand_len(t_list *lst, t_env *env);

/* * * * zero_one_two_handler.c  * * * */

char	*zero_handler(char *str, t_env *env, t_state *state);
char	*one_handler(char *str);
char	*two_handler(char *s, t_env *env, t_state *state);

/* * * * * * * * * * * * * * * * * * * */

#endif

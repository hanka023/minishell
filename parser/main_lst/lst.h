/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/27 16:00:07 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "../minishell.h"

/* * * * * * * main_utils_1  * * * * * * * * */

int		quotes_remove(t_list *lst);
char	**lst_to_str(t_list *lst);
void	free_str(char **str);
void	print_str(char **str);

/* * * * * * * main_utils_2  * * * * * * * * */

int		ft_strlen_ac(char **str);
int		empty_line(char *line);
int		check_empty_line(char *line);
char	*read_line(t_env **env);
t_list	*make_lst(char *line, t_env *env, t_state *state);

/* * * * * * * t_list.c * * * * * * * * */

t_list	*str_to_lst(int argc, char **argv);
t_list	*new_list(char *str);
void	add_back(t_list **head, t_list *new);
void	print_list(t_list *begin_list);
void	free_list(t_list *lst);

/* * * * * * * change_env.c * * * * * * * * */

int		change_str(char **str, char *name, char *value);
int		change_env_value(t_env *env, char *old_value, char *new_value);
int		change_name(t_env *env, char *old_name, char *new_name);
char	*change_env_name(t_env *env, char *old_name, char *new_name);

/* * * * * * * * find_env.c * * * * * * * * */

char	**find_env_name(char *str, t_env *env);
char	*find_env_value(char *str, t_env *env);
t_env	*find_env_node(char *str, t_env *env);

/* * * * * * * t_list_env.c * * * * * * * * */

int		list_len(t_list *lst);
char	*copy_name_to_str(t_env *lst);
char	**env_to_str(t_env *lst);

/* * * * * * * * * * * * * * * * * * * * * */

#endif

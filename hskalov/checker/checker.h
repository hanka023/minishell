/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:28:59 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../minishell.h" 

typedef struct s_env	t_env;

/* * * * * * * checker.c  * * * * * * * * */

int	check_line(char *str, t_env *env);

/* * * * * * *   names.c   * * * * * * * * */

int	test_name(char *str, t_env *env);
int	check_names(char *str, t_env *env);

/* * * * * * * * *   pipes.c   * * * * * * * * */

int	check_pipes_str(char *str, int stav, int pipe, int last);
int	check_pipes(char *str);

/* * * * * * * * * quotes.c  * * * * * * * * * */

int	check_quotes(char *str);
int	check_double_quotes(char *str);

/* * * * * * *   redirect_1.c   * * * * * * * * */

int	multi_check_left(char *str);
int	multi_check_right(char *str);
int	last_check(char *str);
int	first_check(char *str);
int	pipe_check(char *str, int pipe);

/* * * * * * *   redirect_2.c   * * * * * * * * */

int	left_right_check(char *str, int left, int right);
int	left_right_pipe(char *str);
int	first_last_double(char *str);
int	check_redirect(char *str);

/* * * * * * * * * * * * * * * * * * * * * * * * */

#endif
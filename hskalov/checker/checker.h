/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 19:37:32 by haskalov         ###   ########.fr       */
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

int	check_pipes_str(char *str);
int	check_pipes(char *str);

/* * * * * * * * * quotes.c  * * * * * * * * * */

int	check_quotes(char *str);

/* * * * * * *   redirect.c   * * * * * * * * */

int is_rd(char c);
int is_space (char c);
int	check_redirect(char *str);
int check_redirect_error(char *str);

/* * * * * * * * * * * * * * * * * * * * * * * * */

#endif
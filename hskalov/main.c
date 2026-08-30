/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 17:10:44 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "expander/parser.h"
#include "minishell.h"
#include <sys/wait.h>

void	line_to_lst(t_env *env, t_state *state)
{
	t_list		*lst;
	char		*line;
	char		**str;
	char		**env_str;	

	while (1)
	{
		write(1, "minishell$ ", 11);
		line = read_line(&env);
		if (!line)
			break ;
		if (check_empty_line(line) == 1)
			continue ;
		lst = make_lst(line, env, state);
		str = lst_to_str(lst);
		env_str = env_to_str(env);
		print_list (lst);
		free_list(lst);
		free_str(str);
		free_str(env_str);
	}
}

int	main(int argc, char *argv[])
{
	t_env		*env;
	t_state		*state;

	state = setup (gib(1), 2, mib(32));
	(void)argc;
	(void)argv;
	env = env_to_lst (state);
	line_to_lst (env, state);
	free_env (env);
	return (0);
}

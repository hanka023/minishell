/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:11:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 21:22:37 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

#include <readline/readline.h>
#include <readline/history.h>

extern int g_signum;

t_list	*input(t_state *state)
{
	t_list	*out;
	char	*line;
	t_env	*env;

	out = NULL;
	if (g_signum == SIGINT)
		line = readline("");
	else
		line = readline(PROMPT);
	if (!line)
		return ((void *)1);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	add_history(line);
	env = env_to_lst(state->envp);
	if (!env)
		return (NULL);
	out = make_lst(line, env, state);
	free_env(env);
	return (out);
}

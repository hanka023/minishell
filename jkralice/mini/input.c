/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:11:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/18 00:35:19 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

t_list	*input(t_state *state, char *line)
{
	t_list	*out;
	t_env	*env;
	//char	*line;

	out = NULL;
	env = env_to_lst(state->envp);
//	line = read_line(&env);
	if (env && line)
		out = make_lst(line, env, state);
	free_env(env);
	return (out);
}

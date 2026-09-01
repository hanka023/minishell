/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:11:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/01 14:25:27 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

t_list	*input(t_state *state, char *line)
{
	t_list	*out;
	t_env	*env;
	//char	*line;

	write(1, PROMPT, sizeof(PROMPT));
	out = NULL;
	env = env_to_lst(state->envp);
//	line = read_line(&env);
	if (env && line)
		out = make_lst(line, env, state);
	free_env(env);
	return (out);
}

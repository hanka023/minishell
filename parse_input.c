/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:30:14 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/27 15:56:37 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"
#include "parser/minishell.h"
#include "minishell.h"

t_list	*parse_input(t_state *state)
{
	t_env	*env;
	char	*line;
	t_list	*list;

	line = read_line(&env);
	env = env_to_lst(state->envp);
	list = make_lst(line, env, state);
	free(line);
	free_env(env);
	return (list);
}

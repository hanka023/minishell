/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_add_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:58:19 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 19:06:19 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mini.h"

#include "../commands.h"
#include "../map.h"
#include "../Lib42/str.h"
#include "../Lib42/pipeline.h"

static inline
int	add_command(t_state *state, t_intvars *var)
{
	void	*command;
	void	*param;

	command = find_command(var->argv[0]);
	if (!command)
		return (0);
	param = arena_push(var->temp.arena, sizeof(t_command_args));
	if (command == cmd_exit)
		*(t_exit_args *)param = (t_exit_args){
			.argc = var->argc,
			.argv = var->argv,
			.state = state
		};
	else
		*(t_command_args *)param = (t_command_args){
			.argc = var->argc,
			.argv = var->argv,
			.envp = &state->envp
		};
	*ppl_add_back(state->ppl) = ppl_create_function(command, param, var->fd);
	return (1);
}

static inline
int	add_process(t_state *state, t_intvars *var)
{
	char	*path;

	path = find_executable(
			var->temp.arena,
			var->argv[0],
			map_get(state->envp, "PATH")
			);
	if (!path)
		return (0);
	*ppl_add_back(state->ppl) = ppl_create_process(
		path,
		var->argv,
		state->envp,
		var->fd
		);
	return (1);
}

int	interpret_add_link(t_state *state, t_intvars *var)
{
	int	out;

	argv_add(var, NULL);
	var->argc--;
	out = add_command(state, var);
	if (!out)
		out = add_process(state, var);
	if (!out)
	{
		write(1, ERR_MSG, sizeof(ERR_MSG));
		write(1, "found no command: ", 18);
		write(1, var->argv[0], str_len(var->argv[0]));
		write(1, "!\n", 2);
	}
	var->argc = 0;
	var->argv = NULL;
	var->fd[0] = 0;
	var->fd[1] = 1;
	return (out);
}

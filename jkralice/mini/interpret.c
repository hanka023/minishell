/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:37:22 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/30 17:01:45 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"
#include "../commands.h"
#include "../Lib42/str.h"
#include "../Lib42/list/ppl_chain.h"

char	**build_argv(t_arena *arena, t_list **list)
{
	char	**cmd;
	size_t	i;

	cmd = arena_push(arena, 0);
	i = 0;
	while (*list
		&& !str_eq((*list)->str, "|")
		&& !str_eq((*list)->str, ">")
		&& !str_eq((*list)->str, "<")
		&& !str_eq((*list)->str, ">>")
		&& !str_eq((*list)->str, "<<"))
	{
		arena_advance(arena, sizeof(char *));
		cmd[i++] = (*list)->str;
		*list = (*list)->next;
	}
	arena_advance(arena, sizeof(char *));
	cmd[i] = NULL;
	return (cmd);
}

int	add_command(t_pipeline *ppl, t_arena *arena, char **argv, char ***envp)
{
	t_command_args	*args;
	int				(*foo)(void *, int, int);
	int				argc;

	if (str_eq(argv[0], "echo"))
		foo = echo;
	else if (str_eq(argv[0], "cd"))
		foo = cd;
	else if (str_eq(argv[0], "pwd"))
		foo = pwd;
	else if (str_eq(argv[0], "export"))
		foo = export;
	else if (str_eq(argv[0], "unset"))
		foo = unset;
	else if (str_eq(argv[0], "env"))
		foo = env;
	else
		return (0);
	argc = 0;
	while (argv[argc])
		argc++;
	args = arena_push(arena, sizeof(t_command_args));
	*args = (t_command_args){.argc = argc, .argv = argv, .envp = envp};
	pipeline_add_function(ppl, foo, args);
	return (1);
}

int	add_process(t_pipeline *ppl, t_arena *arena, char **argv, char **envp)
{
	char	*path;

	path = find_executable(arena, argv[0], map_get(envp, "PATH"));
	if (!path)
		return (0);
	pipeline_add_process(ppl, path, argv, envp);
	return (1);
}

void	interpret(t_state *state, t_list *list)
{
	t_arena_temp	temp;
	t_pipeline		*ppl;
	char			**argv;

	temp = arena_scratch_claim(1, &state->arena);
	ppl = pipeline_create(temp.arena);

	while (list)
	{
		argv = build_argv(temp.arena, &list);
		if (add_command(ppl, temp.arena, argv, &state->envp) == 0)
			add_process(ppl, temp.arena, argv, state->envp);
		if (list && str_eq(list->str, "|"))
			list = list->next;
		else
			break ;
	}

	pipeline_run(ppl, 0, 1);
	state->exit_code = pipeline_wait(ppl);
	arena_scratch_release(temp);
}

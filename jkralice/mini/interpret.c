/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:37:22 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 17:31:16 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"
#include "../commands.h"
#include "../Lib42/str.h"
#include "../Lib42/list/ppl_chain.h"

char	**build_command(t_arena *arena, t_list **list)
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

void	interpret(t_state *state, t_list *list)
{
	t_arena_temp	temp;
	t_pipeline		*ppl;
	char			**cmd;

	temp = arena_scratch_claim(1, &state->arena);
	ppl = pipeline_create(temp.arena);
	while (list)
	{
		cmd = build_command(temp.arena, &list);
		pipeline_add_process(ppl,
			find_executable(temp.arena, cmd[0], map_get(state->envp, "PATH")),
			cmd,
			state->envp
		);
		if (list && str_eq(list->str, "|"))
			list = list->next;
		else
			break ;
	}
	pipeline_run(ppl, 0, 1);
	state->exit_code = pipeline_wait(ppl);
	pipeline_clear(ppl);
	arena_scratch_release(temp);
}

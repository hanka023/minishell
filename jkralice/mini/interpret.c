/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:37:22 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 23:51:37 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "_mini.h"

#include "../map.h"
#include "../commands.h"

#include "../Lib42/str.h"
#include "../Lib42/memory.h"
#include "../Lib42/pipeline.h"

static inline
int	interpret_loop(t_state *state, t_intvars *var)
{
	t_list	*list;

	var->running = 1;
	list = var->tokens;
	while (var->running && list)
	{
		if (list->type == 1)
			argv_add(var, list->str);
		else if (str_eq(list->str, "<"))
			var->running = interpret_handle_redir_in(var, &list);
		else if (str_eq(list->str, "<<"))
			var->running = interpret_handle_heredoc(var, &list);
		else if (str_eq(list->str, ">"))
			var->running = interpret_handle_redir_out(var, &list);
		else if (str_eq(list->str, ">>"))
			var->running = interpret_handle_redir_append(var, &list);
		else if (str_eq(list->str, "|"))
			var->running = interpret_add_link(state, var);
		else
			argv_add(var, list->str);
		list = list->next;
	}
	if (var->argv)
		interpret_add_link(state, var);
	return (var->running);
}

static inline
void	interpret_run(t_state *state)
{
	t_ppl_node	*node;

	node = state->ppl->start;
	if (state->ppl->size == 1 && node->type == PPL_TYPE_FUNCTION)
		state->exit_code = node->data.function.foo(node->data.function.param);
	else
	{
		ppl_run(state->ppl, (int [2]){0, 1});
		state->exit_code = ppl_wait(state->ppl);
	}
}

static inline
void	free_args(t_ppl *ppl)
{
	t_ppl_node	*node;

	node = ppl->start;
	while (node)
	{
		if (node->type == PPL_TYPE_FUNCTION)
		{
			if (node->data.function.foo == cmd_exit)
				free(((t_exit_args *)node->data.function.param)->argv);
			else
				free(((t_command_args *)node->data.function.param)->argv);
		}
		if (node->type == PPL_TYPE_PROCESS)
			free(node->data.process.argv);
		node = ppl_node_next(node);
	}
}

void	interpret(t_state *state, t_list *tokens)
{
	t_intvars	var;

	if (tokens == NULL)
		return ;
	var = (t_intvars){
		.temp = arena_scratch_claim(1, &state->arena),
		.running = 0,
		.argc = 0,
		.argv = NULL,
		.tokens = tokens,
		.fd[0] = 0,
		.fd[1] = 1
	};
	if (interpret_loop(state, &var))
		interpret_run(state);
	ppl_close(state->ppl);
	free_args(state->ppl);
	ppl_clear(state->ppl);
	free(var.argv);
	free_list(var.tokens);
	arena_scratch_release(var.temp);
}

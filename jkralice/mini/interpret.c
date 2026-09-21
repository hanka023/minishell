/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:37:22 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/21 16:56:39 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"
#include "../commands.h"
#include "../Lib42/str.h"
#include "../Lib42/memory.h"
#include "../Lib42/pipeline.h"

#include <stdio.h>

static
void	*get_command(char **argv)
{
	int	(*foo)(void *);

	if (str_eq(argv[0], "echo"))
		foo = cmd_echo;
	else if (str_eq(argv[0], "cd"))
		foo = cmd_cd;
	else if (str_eq(argv[0], "pwd"))
		foo = cmd_pwd;
	else if (str_eq(argv[0], "export"))
		foo = cmd_export;
	else if (str_eq(argv[0], "unset"))
		foo = cmd_unset;
	else if (str_eq(argv[0], "env"))
		foo = cmd_env;
	else if (str_eq(argv[0], "exit"))
		foo = cmd_exit;
	else
		return (NULL);
	return (foo);
}

static
int	heredoc(char *del)
{
	int		pipe_fd[2];
	size_t	del_len;
	size_t	line_len;
	char	*line;
	char	*found;

	pipe(pipe_fd);
	del_len = str_len(del);
	write(1, "> ", 2);
	line = get_next_line(0);
	while (line)
	{
		line_len = str_len(line);
		found = mem_search(line, line_len, del, del_len);
		if (found)
		{
			write(pipe_fd[1], line, (size_t)(found - line));
			break ;
		}
		write(pipe_fd[1], line, line_len);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

static
int	add_link(t_state *state, t_arena_temp temp, char **argv, int in_fd, int out_fd)
{
	void			*command;
	char			*path;

	*(char **)arena_advance(temp.arena, sizeof(char *)) = NULL;
	command = get_command(argv);
	if (command)
	{
		void	*param;
		int		argc;

		param = arena_push(temp.arena, sizeof(t_command_args));
		argc = 0;
		while (argv[argc])
			argc++;
		if (command == cmd_exit)
			*(t_exit_args *)param = (t_exit_args){
				.argc = argc,
				.argv = argv,
				.state = state
				};
		else
			*(t_command_args *)param = (t_command_args){
				.argc = argc,
				.argv = argv,
				.envp = &state->envp
				};
		*ppl_add_back(state->ppl) = ppl_create_function(
			command,
			param,
			(int [2]){in_fd, out_fd}
			);
		return (1);
	}
	path = find_executable(temp.arena, argv[0], map_get(state->envp, "PATH"));
	if (path)
	{
		*ppl_add_back(state->ppl) = ppl_create_process(
			path,
			argv,
			state->envp,
			(int [2]){in_fd, out_fd}
			);
		return (1);
	}
	return (0);
}

void	interpret(t_state *state)
{
	t_arena_temp	temp;
	t_ppl_node		*node;
	t_list			*list;
	char			**argv;
	int				in_fd;
	int				out_fd;

	temp = arena_scratch_claim(1, &state->arena);
	list = state->list;
	argv = arena_push(temp.arena, 0);
	argv[0] = NULL;
	in_fd = 0;
	out_fd = 1;
	while (list)
	{
		if (list->type == 1)
			*(char **)arena_advance(temp.arena, sizeof(char *)) = list->str;
		else if (str_eq(list->str, "|"))
		{
			add_link(state, temp, argv, in_fd, out_fd);
			argv = arena_push(temp.arena, 0);
			in_fd = 0;
			out_fd = 1;
		}
		else if (str_eq(list->str, ">"))
		{
			list = list->next;
			out_fd = open(list->str, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		}
		else if (str_eq(list->str, ">>"))
		{
			list = list->next;
			out_fd = open(list->str, O_WRONLY | O_CREAT | O_APPEND, 0666);
		}
		else if (str_eq(list->str, "<"))
		{
			list = list->next;
			in_fd = open(list->str, O_RDONLY);
		}
		else if (str_eq(list->str, "<<"))
		{
			list = list->next;
			in_fd = heredoc(list->str);
		}
		else
		 	*(char **)arena_advance(temp.arena, sizeof(char *)) = list->str;
		list = list->next;
	}
	if (argv[0])
	{
		*(char **)arena_advance(temp.arena, sizeof(char *)) = NULL;
		add_link(state, temp, argv, in_fd, out_fd);
	}

	node = state->ppl->start;

	if (state->ppl->size == 1 && node->type == PPL_TYPE_FUNCTION)
		state->exit_code = node->data.function.foo(node->data.function.param);
	else
	{
		ppl_run(state->ppl, (int [2]){0, 1});
		state->exit_code = ppl_wait(state->ppl);
		ppl_close(state->ppl);
	}
	ppl_clear(state->ppl);

	arena_scratch_release(temp);
	arena_scratch_release(temp);
}

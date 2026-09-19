/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:37:22 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/18 11:17:08 by pepcen           ###   ########.fr       */
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
int	add_link(t_ppl *ppl, t_arena_temp temp, t_arena_temp arg_temp, char **argv, int in_fd, int out_fd, t_state *state)
{
	void			*command;
	char			*path;

	*(char **)arena_advance(arg_temp.arena, sizeof(char *)) = NULL;
	command = get_command(argv);
	if (command)
	{
		t_command_args	*param;
		int				argc;

		param = arena_push(temp.arena, sizeof(t_command_args));
		argc = 0;
		while (argv[argc])
			argc++;
		*param = (t_command_args){
			.argc = argc,
			.argv = argv,
			.envp = &state->envp
			};
		*ppl_add_back(ppl) = ppl_create_function(
			command,
			param,
			(int [2]){in_fd, out_fd}
			);
		return (1);
	}
	path = find_executable(temp.arena, argv[0], map_get(state->envp, "PATH"));
	if (path)
	{
		*ppl_add_back(ppl) = ppl_create_process(
			path,
			argv,
			state->envp,
			(int [2]){in_fd, out_fd}
			);
		return (1);
	}
	return (0);
}

void	interpret(t_state *state, t_list *list)
{
	t_arena_temp	temp;
	t_arena_temp	arg_temp;
	t_ppl			*ppl;
	t_ppl_node		*node;
	char			**argv;
	int				in_fd;
	int				out_fd;

	temp = arena_scratch_claim(1, &state->arena);
	arg_temp = arena_scratch_claim(2, (t_arena *[]){state->arena, temp.arena});
	ppl = ppl_create(temp.arena);

	argv = arena_push(arg_temp.arena, 0);
	in_fd = 0;
	out_fd = 1;
	while (list)
	{
		if (str_eq(list->str, "|"))
		{
			add_link(ppl, temp, arg_temp, argv, in_fd, out_fd, state);
			argv = arena_push(arg_temp.arena, 0);
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
		 	*(char **)arena_advance(arg_temp.arena, sizeof(char *)) = list->str;
		list = list->next;
	}
 	*(char **)arena_advance(arg_temp.arena, sizeof(char *)) = NULL;
	if (argv[0])
		add_link(ppl, temp, arg_temp, argv, in_fd, out_fd, state);

	node = ppl->start;
	if (ppl->size == 1 && node->type == PPL_TYPE_FUNCTION)
		state->exit_code = node->data.function.foo(node->data.function.param);

	else
	{
		ppl_run(ppl, (int [2]){0, 1});
		state->exit_code = ppl_wait(ppl);
		ppl_close(ppl);
	}

	arena_scratch_release(temp);
	arena_scratch_release(arg_temp);
}

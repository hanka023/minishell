/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:07:30 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/18 11:15:15 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list/ppl.h"
#include <unistd.h>
#include <fcntl.h>

static
int	run_alone(t_ppl_node *node, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0, fd[0], node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1, fd[1], node->fd[1]), STDOUT_FILENO);
		if (node->type == PPL_TYPE_FUNCTION)
			_exit(node->data.function.foo(node->data.function.param));
		else if (node->type == PPL_TYPE_PROCESS)
			execve(
				node->data.process.path,
				node->data.process.argv,
				node->data.process.envp
				);
		_exit(127);
	}
	node->_pid = pid;
	return (0);
}

// int	run_first(t_ppl_node *node, int *pipe_fd[2], int *prev_fd)
// {
// 	pid_t	pid;

// 	pipe(*pipe_fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		dup2()
// 	}
// 	node->_pid = pid;
// 	close(*pipe_fd[1]);
// 	*prev_fd = *pipe_fd[0];
// 	return (0);
// }

// int	run_middle();
// int	run_last();

ssize_t		ppl_run(t_ppl *ppl, int fd[2])
{
	t_ppl_node	*node;
	int			pipe_fd[2];
	int			prev_fd;
	pid_t		pid;

	if (ppl->size == 0)
		return (-1);
	else if (ppl->size == 1)
		return (run_alone(ppl->start, fd));

	node = ppl->start;
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0, fd[0], node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1, pipe_fd[1], node->fd[1]), STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		//	EXECUTION START
		if (node->type == PPL_TYPE_FUNCTION)
			_exit(node->data.function.foo(node->data.function.param));
		else if (node->type == PPL_TYPE_PROCESS)
			execve(
				node->data.process.path,
				node->data.process.argv,
				node->data.process.envp
				);
		//	EXECUTION END
		_exit(127);
	}
	close(pipe_fd[1]);
	prev_fd = pipe_fd[0];
	node->_pid = pid;

	node = ppl_node_next(node);
	while (node != ppl->end)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(int_ternary(node->fd[0] == 0, prev_fd, node->fd[0]), STDIN_FILENO);
			dup2(int_ternary(node->fd[1] == 1, pipe_fd[1], node->fd[1]), STDOUT_FILENO);
			close(prev_fd);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			//	EXECUTION START
			if (node->type == PPL_TYPE_FUNCTION)
				_exit(node->data.function.foo(node->data.function.param));
			else if (node->type == PPL_TYPE_PROCESS)
				execve(
					node->data.process.path,
					node->data.process.argv,
					node->data.process.envp
					);
			//	EXECUTION END
			_exit(127);
		}
		close(prev_fd);
		close(pipe_fd[1]);
		prev_fd = pipe_fd[0];

		node->_pid = pid;
		node = ppl_node_next(node);
	}

	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0, prev_fd, node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1, fd[1], node->fd[1]), STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(prev_fd);
		//	EXECUTION START
		if (node->type == PPL_TYPE_FUNCTION)
			_exit(node->data.function.foo(node->data.function.param));
		else if (node->type == PPL_TYPE_PROCESS)
			execve(
				node->data.process.path,
				node->data.process.argv,
				node->data.process.envp
				);
		//	EXECUTION END
		_exit(127);
	}
	close(prev_fd);
	node->_pid = pid;
	return (0);
}

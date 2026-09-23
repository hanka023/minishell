/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ppl_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 22:32:37 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 18:35:47 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list/ppl.h"
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void	node_execute(t_ppl_node *node)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
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

int	run_alone(t_ppl_node *node, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0, fd[0], node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1, fd[1], node->fd[1]), STDOUT_FILENO);
		node_execute(node);
	}
	node->_pid = pid;
	return (0);
}

void	run_first(t_ppl_node *node, int *prev_fd, int in_fd)
{
	int		pipe_fd[2];
	pid_t	pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0,
				in_fd, node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1,
				pipe_fd[1], node->fd[1]), STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		node_execute(node);
	}
	close(pipe_fd[1]);
	*prev_fd = pipe_fd[0];
	node->_pid = pid;
}

void	run_middle(t_ppl_node *node, int *prev_fd)
{
	int		pipe_fd[2];
	pid_t	pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0,
				*prev_fd, node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1,
				pipe_fd[1], node->fd[1]), STDOUT_FILENO);
		close(*prev_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		node_execute(node);
	}
	close(*prev_fd);
	close(pipe_fd[1]);
	*prev_fd = pipe_fd[0];
	node->_pid = pid;
}

void	run_last(t_ppl_node *node, int *prev_fd, int out_fd)
{
	int		pipe_fd[2];
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(int_ternary(node->fd[0] == 0,
				*prev_fd, node->fd[0]), STDIN_FILENO);
		dup2(int_ternary(node->fd[1] == 1,
				out_fd, node->fd[1]), STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(*prev_fd);
		node_execute(node);
	}
	close(*prev_fd);
	node->_pid = pid;
}

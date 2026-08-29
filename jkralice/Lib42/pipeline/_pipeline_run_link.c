/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pipeline_run_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:12:39 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 17:03:50 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include <unistd.h>

static inline
void	run_child(t_ppl_link *link, int in_fd, int out_fd)
{
	int	exit_code;

	if (link->type == PPL_PROCESS)
	{
		dup2(in_fd, 0);
		dup2(out_fd, 1);
		if (in_fd != 0)
			close(in_fd);
		if (out_fd != 1)
			close(out_fd);
		execve(link->data.process.path, link->data.process.argv,
			link->data.process.envp);
		_exit(127);
	}
	if (link->type == PPL_FUNCTION)
	{
		exit_code = link->data.function.foo(link->data.function.param,
				in_fd, out_fd);
		close(in_fd);
		close(out_fd);
		_exit(exit_code);
	}
}

int	_ppl_run_link_alone(t_ppl_link *link, int in_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		run_child(link, in_fd, out_fd);
	if (link->type == PPL_PROCESS)
		link->data.process._pid = pid;
	if (link->type == PPL_FUNCTION)
		link->data.function._pid = pid;
	return (pid == -1);
}

inline
int	_ppl_run_link_first(t_ppl_link *link, int in_fd, int out_fd)
{
	int	out;

	out = _ppl_run_link_alone(link, in_fd, out_fd);
	close(out_fd);
	return (out);
}

inline
int	_ppl_run_link_middle(t_ppl_link *link, int in_fd, int out_fd)
{
	int	out;

	out = _ppl_run_link_alone(link, in_fd, out_fd);
	close(in_fd);
	close(out_fd);
	return (out);
}

inline
int	_ppl_run_link_last(t_ppl_link *link, int in_fd, int out_fd)
{
	int	out;

	out = _ppl_run_link_alone(link, in_fd, out_fd);
	close(in_fd);
	return (out);
}

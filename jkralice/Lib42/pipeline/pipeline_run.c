/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:07:30 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 17:03:45 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include "../memory.h"
#include <unistd.h>
#include <fcntl.h>

static
int	run_multiple_links(t_ppl_chain *chain, int in_fd, int out_fd)
{
	t_ppl_node	*node;
	int			pipe_fd[2];
	int			prev_fd;

	node = ppl_chain_start(chain);
	pipe(pipe_fd);
	_ppl_run_link_first(ppl_node_data(node), in_fd, pipe_fd[1]);
	prev_fd = pipe_fd[0];
	node = ppl_node_next(chain, node);
	while (node != ppl_chain_end(chain))
	{
		pipe(pipe_fd);
		_ppl_run_link_middle(ppl_node_data(node), prev_fd, pipe_fd[1]);
		prev_fd = pipe_fd[0];
		node = ppl_node_next(chain, node);
	}
	_ppl_run_link_last(ppl_node_data(node), prev_fd, out_fd);
	return (0);
}

int	pipeline_run(t_pipeline *ppl, int in_fd, int out_fd)
{
	t_ppl_chain	*chain;
	size_t		size;

	chain = (t_ppl_chain *)ppl;
	size = ppl_chain_size(chain);
	if (size == 0)
		return (-1);
	else if (size == 1)
		return (_ppl_run_link_alone(
				ppl_node_data(ppl_chain_start(chain)),
				in_fd,
				out_fd
			));
	else
		return (run_multiple_links(
				chain,
				in_fd,
				out_fd
			));
}

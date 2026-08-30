/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:10:49 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/30 16:55:06 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include <sys/wait.h>

static
void	link_wait(t_ppl_link *link)
{
	if (link->type == PPL_PROCESS)
		waitpid(link->data.process._pid, NULL, 0);
	else if (link->type == PPL_FUNCTION)
		waitpid(link->data.function._pid, NULL, 0);
}

#include <unistd.h>
static
int	link_wait_status(t_ppl_link *link)
{
	int	status;

	status = -1;
	if (link->type == PPL_PROCESS)
	{
		if (waitpid(link->data.process._pid, &status, 0) == -1)
			return (-1);
	}
	else if (link->type == PPL_FUNCTION)
	{
		if (waitpid(link->data.function._pid, &status, 0) == -1)
			return (-1);
	}
	return (WEXITSTATUS(status));
}

int	pipeline_wait(t_pipeline *ppl)
{
	t_ppl_chain	*chain;
	t_ppl_node	*node;
	t_ppl_node	*end;

	chain = (t_ppl_chain *)ppl;
	node = ppl_chain_start(chain);
	if (node)
	{
		end = ppl_chain_end(chain);
		while (node != end)
		{
			link_wait(ppl_node_data(node));
			node = ppl_node_next(chain, node);
		}
		return (link_wait_status(ppl_node_data(end)));
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_kill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:52:35 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 22:54:03 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"
#include <signal.h>
#include <unistd.h>

void	ppl_kill(t_ppl *ppl)
{
	t_ppl_node	*node;

	node = ppl->start;
	while (node)
	{
		if (node->_pid > 1)
			kill(node->_pid, SIGKILL);
		node->_pid = 0;
		node = ppl_node_next(node);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:52:35 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:39:56 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"
#include <signal.h>
#include <unistd.h>

void	ppl_signal(t_ppl *ppl, int sig)
{
	t_ppl_node	*node;

	node = ppl->start;
	while (node)
	{
		if (node->_pid > 1)
			kill(node->_pid, sig);
		node->_pid = 0;
		node = ppl_node_next(node);
	}
}

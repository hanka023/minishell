/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 23:19:19 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/17 23:21:00 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"
#include <unistd.h>

void	ppl_close(t_ppl *ppl)
{
	t_ppl_node	*node;

	node = ppl->start;
	while (node)
	{
		if (node->fd[0] != 0)
			close(node->fd[0]);
		if (node->fd[1] != 1)
			close(node->fd[1]);
		node = ppl_node_next(node);
	}
}

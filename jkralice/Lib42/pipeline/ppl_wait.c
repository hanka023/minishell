/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:10:49 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:11:09 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"
#include <sys/wait.h>

int	ppl_wait(t_ppl *ppl)
{
	int			status;
	t_ppl_node	*node;

	status = -1;
	node = ppl->start;
	while (node)
	{
		if (node->_pid > 0)
			waitpid(node->_pid, &status, 0);
		node->_pid = 0;
		node = ppl_node_next(node);
	}
	if (status >= 0)
		return (WEXITSTATUS(status));
	return (status);
}

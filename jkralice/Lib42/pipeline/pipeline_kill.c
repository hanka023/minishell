/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:52:35 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/24 12:14:06 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include <signal.h>
#include <unistd.h>

void	pipeline_kill(t_pipeline *ppl)
{
	t_ppl_node	*node;
	t_ppl_link	*link;

	node = ppl_chain_start((t_ppl_chain *)ppl);
	while (node)
	{
		link = ppl_node_data(node);
		if (link->type == PPL_FUNCTION && link->data.function._pid > 1)
			kill(link->data.function._pid, SIGKILL);
		if (link->type == PPL_PROCESS && link->data.process._pid > 1)
			kill(link->data.process._pid, SIGKILL);
		if (link->type == PPL_FILE && link->data.file._fd > 2)
			close(link->data.file._fd);
		node = ppl_node_next((t_ppl_chain *)ppl, node);
	}
}

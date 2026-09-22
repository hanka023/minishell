/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:07:30 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:44:10 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list/ppl.h"
#include <unistd.h>
#include <fcntl.h>

void	node_execute(t_ppl_node *node);
int		run_alone(t_ppl_node *node, int fd[2]);
void	run_first(t_ppl_node *node, int *prev_fd, int in_fd);
void	run_middle(t_ppl_node *node, int *prev_fd);
void	run_last(t_ppl_node *node, int *prev_fd, int out_fd);

ssize_t	ppl_run(t_ppl *ppl, int fd[2])
{
	t_ppl_node	*node;
	int			prev_fd;

	if (ppl->size == 0)
		return (-1);
	else if (ppl->size == 1)
		return (run_alone(ppl->start, fd));
	node = ppl->start;
	run_first(node, &prev_fd, fd[0]);
	node = ppl_node_next(node);
	while (node != ppl->end)
	{
		run_middle(node, &prev_fd);
		node = ppl_node_next(node);
	}
	run_last(node, &prev_fd, fd[1]);
	return (0);
}

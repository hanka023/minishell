/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:42:49 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 16:32:50 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"

void	_dlist_remove(struct s_dlist *list, size_t idx)
{
	struct s_dnode	*node;

	node = _dlist_get_node(list, idx);
	if (node)
		_dlist_remove_node(list, node);
}

void	_dlist_remove_back(struct s_dlist *list)
{
	if (list->size > 0)
	{
		if (list->size > 1)
			list->end = list->end->prev;
		list->size--;
	}
}

void	_dlist_remove_front(struct s_dlist *list)
{
	if (list->size > 0)
	{
		if (list->size > 1)
			list->start = list->start->next;
		list->size--;
	}
}

void	_dlist_remove_node(struct s_dlist *list, struct s_dnode *node)
{
	if (node == list->start)
		_dlist_remove_front(list);
	else if (node == list->end)
		_dlist_remove_back(list);
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = list->end->next;
		node->prev = list->end;
		list->end->next = node;
		if (node->next)
			node->next->prev = node;
		list->size--;
	}
}

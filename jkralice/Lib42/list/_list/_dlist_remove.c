/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:42:49 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:09:34 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

void	_dllist_remove(t_dllist *list, size_t idx)
{
	t_dllnode	*node;

	node = _dllist_get(list, idx);
	if (node)
		_dllist_remove_node(list, node);
}

void	_dllist_remove_back(t_dllist *list)
{
	if (list->size > 0)
	{
		__dllnode_data(list->end)->next = list->free;
		list->free = list->end;
		list->end = _dllnode_prev(list->end);
		if (list->end)
			__dllnode_data(list->end)->next = NULL;
		else
			list->start = NULL;
		list->size--;
	}
}

void	_dllist_remove_front(t_dllist *list)
{
	t_dllnode	*tmp;

	if (list->size > 0)
	{
		tmp = _dllnode_next(list->start);
		__dllnode_data(list->start)->next = list->free;
		list->free = list->start;
		list->start = tmp;
		if (list->start)
			__dllnode_data(list->start)->prev = NULL;
		else
			list->end = NULL;
		list->size--;
	}
}

void	_dllist_remove_node(t_dllist *list, t_dllnode *node)
{
	if (node == list->start)
		_dllist_remove_front(list);
	else if (node == list->end)
		_dllist_remove_back(list);
	else if (list->size > 0)
	{
		if (_dllnode_prev(node))
			__dllnode_data(_dllnode_prev(node))->next = _dllnode_next(node);
		if (_dllnode_next(node))
			__dllnode_data(_dllnode_next(node))->prev = _dllnode_prev(node);
		__dllnode_data(node)->next = list->free;
		list->free = node;
		list->size--;
	}
}

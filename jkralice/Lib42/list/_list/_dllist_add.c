/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dllist_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:34:46 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:10:03 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

t_dllnode	*_dllist_add(t_dllist *list, size_t idx, size_t size)
{
	t_dllnode	*node;

	if (idx == list->size)
		return (_dllist_add_back(list, size));
	if (idx == 0)
		return (_dllist_add_front(list, size));
	node = _dllist_get(list, idx);
	if (node)
		return (_dllist_add_before(list, node, size));
	return (NULL);
}

t_dllnode	*_dllist_add_back(t_dllist *list, size_t size)
{
	t_dllnode	**new_node;

	if (list->end)
		new_node = &__dllnode_data(list->end)->next;
	else
		new_node = &list->start;
	if (list->free)
	{
		*new_node = list->free;
		list->free = _dllnode_next(list->free);
	}
	else
		*new_node = __dllnode_allocate(list->arena, size);
	__dllnode_data(*new_node)->next = NULL;
	__dllnode_data(*new_node)->prev = list->end;
	list->end = *new_node;
	list->size++;
	return (*new_node);
}

t_dllnode	*_dllist_add_front(t_dllist *list, size_t size)
{
	t_dllnode	**new_node;

	if (list->start)
		new_node = &__dllnode_data(list->start)->prev;
	else
		new_node = &list->end;
	if (list->free)
	{
		*new_node = list->free;
		list->free = _dllnode_next(list->free);
	}
	else
		*new_node = __dllnode_allocate(list->arena, size);
	__dllnode_data(*new_node)->next = list->start;
	__dllnode_data(*new_node)->prev = NULL;
	list->start = *new_node;
	list->size++;
	return (*new_node);
}

t_dllnode	*_dllist_add_before(t_dllist *list, t_dllnode *node, size_t size)
{
	t_dllnode	*new_node;

	if (node == list->start)
		return (_dllist_add_front(list, size));
	if (list->free)
	{
		new_node = list->free;
		list->free = _dllnode_next(list->free);
	}
	else
		new_node = __dllnode_allocate(list->arena, size);
	__dllnode_data(new_node)->prev = _dllnode_prev(node);
	if (_dllnode_prev(node))
		__dllnode_data(_dllnode_prev(node))->next = new_node;
	__dllnode_data(new_node)->next = node;
	__dllnode_data(node)->prev = new_node;
	list->size++;
	return (new_node);
}

t_dllnode	*_dllist_add_after(t_dllist *list, t_dllnode *node, size_t size)
{
	t_dllnode	*new_node;

	if (node == list->end)
		return (_dllist_add_back(list, size));
	if (list->free)
	{
		new_node = list->free;
		list->free = _dllnode_next(list->free);
	}
	else
		new_node = __dllnode_allocate(list->arena, size);
	__dllnode_data(new_node)->next = _dllnode_next(node);
	if (_dllnode_next(node))
		__dllnode_data(_dllnode_next(node))->prev = new_node;
	__dllnode_data(new_node)->prev = node;
	__dllnode_data(node)->next = new_node;
	list->size++;
	return (new_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:34:46 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 16:32:32 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"

void	*_dlist_add(struct s_dlist *list, size_t idx, size_t data_size)
{
	struct s_dnode	*node;

	if (idx == list->size)
		return (_dlist_add_back(list, data_size));
	if (idx == 0)
		return (_dlist_add_front(list, data_size));
	node = _dlist_get_node(list, idx);
	if (node)
		return (_dlist_add_before(list, node, data_size));
	return (NULL);
}

void	*_dlist_add_back(struct s_dlist *list, size_t data_size)
{
	struct s_dnode	**new_node;

	if (list->end == NULL)
		new_node = &list->start;
	else
		new_node = &list->end->next;
	if (*new_node == NULL)
	{
		*new_node = __dnode_allocate(list->arena, data_size);
		**new_node = (struct s_dnode){
			.prev = list->end,
			.next = NULL
		};
	}
	list->end = *new_node;
	list->size++;
	return (_dnode_data(*new_node));
}

void	*_dlist_add_front(struct s_dlist *list, size_t data_size)
{
	struct s_dnode	**new_node;

	if (list->start == NULL)
		new_node = &list->end;
	else
		new_node = &list->start->prev;
	if (*new_node == NULL)
	{
		*new_node = __dnode_allocate(list->arena, data_size);
		**new_node = (struct s_dnode){
			.prev = NULL,
			.next = list->start
		};
	}
	list->start = *new_node;
	list->size++;
	return (_dnode_data(*new_node));
}

void	*_dlist_add_before(struct s_dlist *list,
	struct s_dnode *node, size_t data_size)
{
	struct s_dnode	*new_node;

	if (node == list->start)
		return (_dlist_add_front(list, data_size));
	new_node = __dnode_allocate(list->arena, data_size);
	new_node->prev = node->prev;
	new_node->next = node;
	node->prev = new_node;
	new_node->prev->next = new_node;
	list->size++;
	return (_dnode_data(new_node));
}

void	*_dlist_add_after(struct s_dlist *list,
	struct s_dnode *node, size_t data_size)
{
	struct s_dnode	*new_node;

	if (node == list->end)
		return (_dlist_add_back(list, data_size));
	new_node = __dnode_allocate(list->arena, data_size);
	new_node->next = node->next;
	new_node->prev = node;
	node->next = new_node;
	new_node->next->prev = new_node;
	list->size++;
	return (_dnode_data(new_node));
}

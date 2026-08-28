/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:03:45 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 16:39:01 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"

inline
void	*_dlist_get(struct s_dlist *list, size_t idx)
{
	struct s_dnode	*node;

	node = _dlist_get_node(list, idx);
	if (node == NULL)
		return (NULL);
	return (_dnode_data(node));
}

static inline
struct s_dnode	*_dlist_get_node_front(struct s_dlist *list, size_t idx)
{
	struct s_dnode	*out;
	size_t			i;

	out = list->start;
	i = 0;
	while (i++ < idx)
		out = out->next;
	return (out);
}

static inline
struct s_dnode	*_dlist_get_node_back(struct s_dlist *list, size_t idx)
{
	struct s_dnode	*out;
	size_t			i;

	out = list->end;
	i = list->size;
	while (--i > idx)
		out = out->prev;
	return (out);
}

struct s_dnode	*_dlist_get_node(struct s_dlist *list, size_t idx)
{
	struct s_dnode	*out;

	if (idx >= list->size)
		out = NULL;
	else if (idx <= list->size - idx)
		out = _dlist_get_node_front(list, idx);
	else
		out = _dlist_get_node_back(list, idx);
	return (out);
}

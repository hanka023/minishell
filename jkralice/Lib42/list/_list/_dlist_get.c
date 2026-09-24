/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:03:45 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:09:20 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

static inline
t_dllnode	*_dllist_get_node_front(t_dllist *list, size_t idx)
{
	t_dllnode	*out;
	size_t		i;

	out = list->start;
	i = 0;
	while (i++ < idx)
		out = _dllnode_next(out);
	return (out);
}

static inline
t_dllnode	*_dllist_get_node_back(t_dllist *list, size_t idx)
{
	t_dllnode	*out;
	size_t		i;

	out = list->end;
	i = list->size;
	while (--i > idx)
		out = _dllnode_prev(out);
	return (out);
}

t_dllnode	*_dllist_get(t_dllist *list, size_t idx)
{
	t_dllnode	*out;

	if (idx >= list->size)
		out = NULL;
	else if (idx <= list->size - idx)
		out = _dllist_get_node_front(list, idx);
	else
		out = _dllist_get_node_back(list, idx);
	return (out);
}

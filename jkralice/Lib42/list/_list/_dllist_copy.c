/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dllist_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:24:24 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 20:14:36 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"
#include "../../memory.h"

t_dllist	*_dllist_copy(t_arena *arena, t_dllist *list, size_t size)
{
	t_dllist	*out;
	t_dllnode	*node;

	out = _dllist_create(arena);
	node = list->start;
	while (node)
	{
		mem_copy(node, _dllist_add_back(out, size), size);
		node = _dllnode_next(node);
	}
	return (out);
}

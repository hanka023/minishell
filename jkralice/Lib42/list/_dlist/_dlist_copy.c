/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:24:24 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 16:40:14 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"
#include "../../memory.h"

struct s_dlist	*_dlist_copy(t_arena *arena, struct s_dlist *list,
								size_t data_size)
{
	struct s_dlist	*out;
	struct s_dnode	*tmp;

	out = _dlist_create(arena);
	tmp = _dlist_start(list);
	while (tmp)
	{
		mem_copy(_dnode_data(tmp), _dlist_add_back(list, data_size), data_size);
		tmp = _dnode_next(list, tmp);
	}
	return (out);
}

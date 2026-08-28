/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dnode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:54:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/10 15:14:38 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"

inline
void	*_dnode_data(struct s_dnode *node)
{
	return (node + 1);
}

inline
struct s_dnode	*_dnode_prev(struct s_dlist *list, struct s_dnode *node)
{
	if (node == list->start)
		return (NULL);
	return (node->prev);
}

inline
struct s_dnode	*_dnode_next(struct s_dlist *list, struct s_dnode *node)
{
	if (node == list->end)
		return (NULL);
	return (node->next);
}

inline
struct s_dnode	*__dnode_allocate(t_arena *arena, size_t data_size)
{
	return (arena_push(arena, sizeof(struct s_dnode) + data_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dllist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:34:45 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 19:06:19 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIST_H
# define _LIST_H

# include "../../arena.h"

//	List node exposed data.
typedef void	t_dllnode;

//	List node internal data.
typedef struct s_dllnode_data
{
	t_dllnode	*prev;
	t_dllnode	*next;
}	t_dllnode_data;

//	List header.
typedef struct s_dllist
{
	t_arena		*arena;
	t_dllnode	*start;
	t_dllnode	*end;
	t_dllnode	*free;
	size_t		size;
}	t_dllist;

t_dllnode		*__dllnode_allocate(t_arena *arena, size_t size);
t_dllnode_data	*__dllnode_data(t_dllnode *node);

t_dllnode		*_dllnode_prev(t_dllnode *node);
t_dllnode		*_dllnode_next(t_dllnode *node);

t_dllist		*_dllist_create(t_arena *arena);

t_dllnode		*_dllist_add(t_dllist *list, size_t idx, size_t size);
t_dllnode		*_dllist_add_back(t_dllist *list, size_t size);
t_dllnode		*_dllist_add_front(t_dllist *list, size_t size);
t_dllnode		*_dllist_add_before(t_dllist *list,
					t_dllnode *node, size_t size);
t_dllnode		*_dllist_add_after(t_dllist *list,
					t_dllnode *node, size_t size);

t_dllnode		*_dllist_get(t_dllist *list, size_t idx);

void			_dllist_remove(t_dllist *list, size_t idx);
void			_dllist_remove_back(t_dllist *list);
void			_dllist_remove_front(t_dllist *list);
void			_dllist_remove_node(t_dllist *list, t_dllnode *node);

void			_dllist_clear(t_dllist *list);

t_dllist		*_dllist_copy(t_arena *arena, t_dllist *list, size_t size);

#endif

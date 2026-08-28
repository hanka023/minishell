/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:34:45 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 19:04:41 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DLIST_H
# define _DLIST_H

# include "../../arena.h"

struct s_dnode
{
	struct s_dnode	*prev;
	struct s_dnode	*next;
};

struct s_dlist
{
	t_arena			*arena;
	struct s_dnode	*start;
	struct s_dnode	*end;
	size_t			size;
};

void			*_dnode_data(struct s_dnode *node);
struct s_dnode	*_dnode_prev(struct s_dlist *list, struct s_dnode *node);
struct s_dnode	*_dnode_next(struct s_dlist *list, struct s_dnode *node);
struct s_dnode	*__dnode_allocate(t_arena *arena, size_t data_size);

struct s_dlist	*_dlist_create(t_arena *arena);

void			*_dlist_add(struct s_dlist *list, size_t idx, size_t data_size);
void			*_dlist_add_back(struct s_dlist *list, size_t data_size);
void			*_dlist_add_front(struct s_dlist *list, size_t data_size);
void			*_dlist_add_before(struct s_dlist *list,
					struct s_dnode *node, size_t data_size);
void			*_dlist_add_after(struct s_dlist *list,
					struct s_dnode *node, size_t data_size);

struct s_dnode	*_dlist_start(struct s_dlist *list);
struct s_dnode	*_dlist_end(struct s_dlist *list);
size_t			_dlist_size(struct s_dlist *list);

void			*_dlist_get(struct s_dlist *list, size_t idx);
struct s_dnode	*_dlist_get_node(struct s_dlist *list, size_t idx);

void			_dlist_remove(struct s_dlist *list, size_t idx);
void			_dlist_remove_back(struct s_dlist *list);
void			_dlist_remove_front(struct s_dlist *list);
void			_dlist_remove_node(struct s_dlist *list, struct s_dnode *node);

void			_dlist_clear(struct s_dlist *list);
struct s_dlist	*_dlist_copy(t_arena *arena, struct s_dlist *list,
					size_t data_size);

#endif

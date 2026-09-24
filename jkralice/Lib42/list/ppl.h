/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:52:47 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:07:19 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPL_H
# define PPL_H

# include "../arena.h"
# include "_list/_dllist.h"

# include "../pipeline/ppl_link.h"

typedef const struct s_dllist	\
	t_ppl;

typedef t_ppl_link	\
	t_ppl_node;

t_ppl_node	*ppl_node_next(t_ppl_node *node);
t_ppl_node	*ppl_node_prev(t_ppl_node *node);

t_ppl		*ppl_create(t_arena *arena);

t_ppl_node	*ppl_add(t_ppl *list, size_t idx);
t_ppl_node	*ppl_add_back(t_ppl *list);
t_ppl_node	*ppl_add_front(t_ppl *list);
t_ppl_node	*ppl_add_before(t_ppl *list, t_ppl_node *node);
t_ppl_node	*ppl_add_after(t_ppl *list, t_ppl_node *node);

t_ppl_node	*ppl_get(t_ppl *list, size_t idx);

void		ppl_remove(t_ppl *list, size_t idx);
void		ppl_remove_back(t_ppl *list);
void		ppl_remove_front(t_ppl *list);
void		ppl_remove_node(t_ppl *list, t_ppl_node *node);

void		ppl_clear(t_ppl *list);

t_ppl		*ppl_copy(t_arena *arena, t_ppl *list);

#endif

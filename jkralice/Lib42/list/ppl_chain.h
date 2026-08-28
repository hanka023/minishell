/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_chain.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:52:47 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/24 16:26:32 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPL_CHAIN_H
# define PPL_CHAIN_H

# include "../arena.h"

# include "../pipeline/pipeline_link.h"

typedef struct s_dlist	t_ppl_chain;
typedef struct s_dnode	t_ppl_node;

t_ppl_link	*ppl_node_data(t_ppl_node *node);
t_ppl_node	*ppl_node_next(t_ppl_chain *list, t_ppl_node *node);
t_ppl_node	*ppl_node_prev(t_ppl_chain *list, t_ppl_node *node);

t_ppl_chain	*ppl_chain_create(t_arena *arena);

t_ppl_link	*ppl_chain_add(t_ppl_chain *list, size_t idx);
t_ppl_link	*ppl_chain_add_back(t_ppl_chain *list);
t_ppl_link	*ppl_chain_add_front(t_ppl_chain *list);
t_ppl_link	*ppl_chain_add_before(t_ppl_chain *list, t_ppl_node *node);
t_ppl_link	*ppl_chain_add_after(t_ppl_chain *list, t_ppl_node *node);

t_ppl_node	*ppl_chain_start(t_ppl_chain *list);
t_ppl_node	*ppl_chain_end(t_ppl_chain *list);
size_t		ppl_chain_size(t_ppl_chain *list);

t_ppl_link	*ppl_chain_get(t_ppl_chain *list, size_t idx);
t_ppl_node	*ppl_chain_get_node(t_ppl_chain *list, size_t idx);

void		ppl_chain_remove(t_ppl_chain *list, size_t idx);
void		ppl_chain_remove_back(t_ppl_chain *list);
void		ppl_chain_remove_front(t_ppl_chain *list);
void		ppl_chain_remove_node(t_ppl_chain *list, t_ppl_node *node);

void		ppl_chain_clear(t_ppl_chain *list);

t_ppl_chain	*ppl_chain_copy(t_arena *arena, t_ppl_chain *list);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_header                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:52:47 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 17:39:16 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ppl_chain.h"
#include "../_dlist/_dlist.h"

void	ppl_chain_remove(t_ppl_chain *list, size_t idx)
{
	_dlist_remove(list, idx);
}

void	ppl_chain_remove_back(t_ppl_chain *list)
{
	_dlist_remove_back(list);
}

void	ppl_chain_remove_front(t_ppl_chain *list)
{
	_dlist_remove_front(list);
}

void	ppl_chain_remove_node(t_ppl_chain *list, t_ppl_node *node)
{
	_dlist_remove_node(list, node);
}

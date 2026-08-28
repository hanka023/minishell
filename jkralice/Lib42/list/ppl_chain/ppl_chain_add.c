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

t_ppl_link	*ppl_chain_add(t_ppl_chain *list, size_t idx)
{
	return (_dlist_add(list, idx, sizeof(t_ppl_link)));
}

t_ppl_link	*ppl_chain_add_back(t_ppl_chain *list)
{
	return (_dlist_add_back(list, sizeof(t_ppl_link)));
}

t_ppl_link	*ppl_chain_add_front(t_ppl_chain *list)
{
	return (_dlist_add_front(list, sizeof(t_ppl_link)));
}

t_ppl_link	*ppl_chain_add_before(t_ppl_chain *list, t_ppl_node *node)
{
	return (_dlist_add_before(list, node, sizeof(t_ppl_link)));
}

t_ppl_link	*ppl_chain_add_after(t_ppl_chain *list, t_ppl_node *node)
{
	return (_dlist_add_after(list, node, sizeof(t_ppl_link)));
}

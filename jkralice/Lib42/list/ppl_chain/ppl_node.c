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

t_ppl_link	*ppl_node_data(t_ppl_node *node)
{
	return (_dnode_data(node));
}

t_ppl_node	*ppl_node_prev(t_ppl_chain *list, t_ppl_node *node)
{
	return (_dnode_prev(list, node));
}

t_ppl_node	*ppl_node_next(t_ppl_chain *list, t_ppl_node *node)
{
	return (_dnode_next(list, node));
}

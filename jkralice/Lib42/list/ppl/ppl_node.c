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

#include "../ppl.h"
#include "../_list/_dllist.h"

t_ppl_node	*ppl_node_prev(t_ppl_node *node)
{
	return (_dllnode_prev(node));
}

t_ppl_node	*ppl_node_next(t_ppl_node *node)
{
	return (_dllnode_next(node));
}

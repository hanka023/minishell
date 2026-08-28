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

t_ppl_node	*ppl_chain_start(t_ppl_chain *list)
{
	return (_dlist_start(list));
}

t_ppl_node	*ppl_chain_end(t_ppl_chain *list)
{
	return (_dlist_end(list));
}

size_t	ppl_chain_size(t_ppl_chain *list)
{
	return (_dlist_size(list));
}

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

t_ppl_link	*ppl_chain_get(t_ppl_chain *list, size_t idx)
{
	return (_dlist_get(list, idx));
}

t_ppl_node	*ppl_chain_get_node(t_ppl_chain *list, size_t idx)
{
	return (_dlist_add_back(list, idx));
}

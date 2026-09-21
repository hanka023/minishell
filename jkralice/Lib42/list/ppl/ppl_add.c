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

t_ppl_node	*ppl_add(t_ppl *list, size_t idx)
{
	return (_dllist_add((t_dllist *)list, idx, sizeof(t_ppl_link)));
}

t_ppl_node	*ppl_add_back(t_ppl *list)
{
	return (_dllist_add_back((t_dllist *)list, sizeof(t_ppl_link)));
}

t_ppl_node	*ppl_add_front(t_ppl *list)
{
	return (_dllist_add_front((t_dllist *)list, sizeof(t_ppl_link)));
}

t_ppl_node	*ppl_add_before(t_ppl *list, t_ppl_node *node)
{
	return (_dllist_add_before((t_dllist *)list, node, sizeof(t_ppl_link)));
}

t_ppl_node	*ppl_add_after(t_ppl *list, t_ppl_node *node)
{
	return (_dllist_add_after((t_dllist *)list, node, sizeof(t_ppl_link)));
}

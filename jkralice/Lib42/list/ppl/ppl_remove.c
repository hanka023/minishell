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

void	ppl_remove(t_ppl *list, size_t idx)
{
	_dllist_remove((t_dllist *)list, idx);
}

void	ppl_remove_back(t_ppl *list)
{
	_dllist_remove_back((t_dllist *)list);
}

void	ppl_remove_front(t_ppl *list)
{
	_dllist_remove_front((t_dllist *)list);
}

void	ppl_remove_node(t_ppl *list, t_ppl_node *node)
{
	_dllist_remove_node((t_dllist *)list, node);
}

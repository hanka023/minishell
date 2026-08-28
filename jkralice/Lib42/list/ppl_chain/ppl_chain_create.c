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

t_ppl_chain	*ppl_chain_create(t_arena *arena)
{
	return (_dlist_create(arena));
}

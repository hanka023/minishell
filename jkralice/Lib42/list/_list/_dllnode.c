/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dllnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:54:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 20:12:32 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

inline
t_dllnode	*_dllnode_next(t_dllnode *node)
{
	return (__dllnode_data(node)->next);
}

inline
t_dllnode	*_dllnode_prev(t_dllnode *node)
{
	return (__dllnode_data(node)->prev);
}

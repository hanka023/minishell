/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __dllnode_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:54:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 20:04:03 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

inline
t_dllnode_data	*__dllnode_data(t_dllnode *node)
{
	return ((t_dllnode_data *)node - 1);
}

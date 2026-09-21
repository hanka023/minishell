/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __dllnode_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:54:23 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 17:04:20 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

inline
t_dllnode	*__dllnode_allocate(t_arena *arena, size_t size)
{
	t_dllnode_data	*data;

	data = arena_push(arena, sizeof(t_dllnode_data) + size);
	return ((t_dllnode *)(data + 1));
}

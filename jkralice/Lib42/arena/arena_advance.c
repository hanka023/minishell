/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_advance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:39:29 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/17 22:56:14 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

void	*arena_advance(t_arena *arena, size_t n)
{
	size_t	old_pos;

	old_pos = arena->pos;
	arena->pos = size_min(arena->cap, arena->pos + n);
	return ((char *)arena + old_pos);
}

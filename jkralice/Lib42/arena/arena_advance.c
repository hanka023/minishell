/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_advance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:39:29 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/09 17:45:27 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

size_t	arena_advance(t_arena *arena, size_t n)
{
	size_t	old_pos;

	old_pos = arena->pos;
	arena->pos = size_min(arena->cap, arena->pos + n);
	return (arena->pos - old_pos);
}

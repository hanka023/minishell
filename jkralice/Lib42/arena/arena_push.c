/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:44:28 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/03 15:34:30 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

void	*arena_push(t_arena *arena, size_t n)
{
	size_t	pos_aligned;
	size_t	pos_new;

	pos_aligned = size_align_up_pow2(arena->pos, sizeof(void *));
	pos_new = pos_aligned + n;
	if (pos_new > arena->cap)
		return (NULL);
	arena->pos = pos_new;
	return ((char *)arena + pos_aligned);
}

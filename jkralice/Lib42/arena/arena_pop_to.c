/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_pop_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:12:32 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/10 00:17:20 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

void	arena_pop_to(t_arena *arena, size_t pos)
{
	pos = size_max(pos, sizeof(t_arena));
	arena->pos = pos;
}

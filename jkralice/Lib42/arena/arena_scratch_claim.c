/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_scratch_claim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:59:14 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/09 23:41:13 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"
#include "_arena.h"

t_arena_temp	arena_scratch_claim(size_t n, t_arena **conflicts)
{
	t_scratch_arenas	*scratch;
	size_t				s;
	size_t				c;

	scratch = _global_scratch();
	s = 0;
	while (s < scratch->count)
	{
		c = 0;
		while (c < n && conflicts[c] != scratch->arenas[s])
			c++;
		if (c == n)
			break ;
		s++;
	}
	if (c != n)
		return ((t_arena_temp){0});
	return (arena_temp_begin(scratch->arenas[s]));
}

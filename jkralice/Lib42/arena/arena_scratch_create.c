/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_scratch_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:43:00 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/10 00:02:57 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"
#include "_arena.h"

#include <stdlib.h>

size_t	arena_scratch_create(size_t n, size_t capacity)
{
	t_scratch_arenas	*scratch;
	size_t				i;

	scratch = _global_scratch();
	scratch->arenas = malloc(n * sizeof(t_arena *));
	i = 0;
	while (i < n)
	{
		scratch->arenas[i] = arena_create(capacity);
		if (!scratch->arenas[i])
			break ;
		i++;
	}
	scratch->count = i;
	return (i);
}

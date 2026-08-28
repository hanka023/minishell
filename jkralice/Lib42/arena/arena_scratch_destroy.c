/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_scratch_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:12:06 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/10 00:16:54 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"
#include "_arena.h"

#include <stdlib.h>

void	arena_scratch_destroy(void)
{
	t_scratch_arenas	*scratch;
	size_t				i;

	scratch = _global_scratch();
	i = 0;
	while (i < scratch->count)
		free(scratch->arenas[i++]);
	free(scratch->arenas);
	*scratch = (t_scratch_arenas){0};
}

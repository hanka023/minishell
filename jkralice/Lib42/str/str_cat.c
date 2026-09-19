/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:47:34 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/24 15:15:01 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str.h"
#include "../memory.h"

char	*str_cat(t_arena *arena, char **strs)
{
	char	*out;
	size_t	size;
	size_t	total;
	size_t	i;

	out = arena_push(arena, 0);
	total = 0;
	i = 0;
	while (strs[i])
	{
		size = str_len(strs[i]);
		arena_advance(arena, size);
		mem_copy(strs[i], out + total, size);
		total += size;
		i++;
	}
	arena_advance(arena, 1);
	out[total] = '\0';
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:20:20 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/28 14:29:32 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../Lib42/memory.h"
#include "../Lib42/str.h"

static inline
size_t	map_len(char **map)
{
	size_t	out;

	out = 0;
	while (map[out])
		out++;
	return (out);
}

char	**map_dup(char **map)
{
	char	**out;
	size_t	len;
	size_t	i;

	out = malloc(sizeof(char *) * (map_len(map) + 1));
	i = 0;
	while (map[i])
	{
		len = str_len(map[i]);
		out[i] = malloc(len + 1);
		mem_copy(map[i], out[i], len + 1);
		i++;
	}
	out[i] = NULL;
	return (out);
}

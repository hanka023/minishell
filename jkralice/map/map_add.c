/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:06:05 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/27 14:30:10 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "../Lib42/memory.h"

#include <stdlib.h>

size_t	str_len(char *str);
size_t	key_len(char *str);
size_t	map_size(char **map);
int		map_key_is_valid(char *key);
char	*map_combine(char *key, char *val);

char	**map_add(char **map, char *key, char *val)
{
	char	**out;
	size_t	size;

	if (!map_key_is_valid(key) || map_search(map, key))
		return (NULL);
	size = map_size(map);
	out = malloc(sizeof(char *) * (size + 1));
	mem_copy(map, out, size * sizeof(char *));
	out[size - 1] = map_combine(key, val);
	out[size] = NULL;
	free(map);
	return (out);
}

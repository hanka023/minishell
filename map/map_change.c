/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:21:29 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/20 18:27:30 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "../Lib42/memory.h"

#include <stdlib.h>

char	*map_combine(char *key, char *val);
size_t	str_len(char *str);
size_t	key_len(char *var);

static inline
size_t	map_search_idx(char **map, char *key)
{
	size_t	targert_len;
	size_t	current_len;
	size_t	i;

	targert_len = str_len(key);
	i = 0;
	while (map[i])
	{
		current_len = key_len(map[i]);
		if (targert_len == current_len)
			if (!mem_compare(key, map[i], targert_len))
				return (i);
		i++;
	}
	return (i);
}


int	map_change(char **map, char *key, char *val)
{
	size_t	i;

	i = map_search_idx(map, key);
	if (map[i] == NULL)
		return (0);
	free(map[i]);
	map[i] = map_combine(key, val);
	return (1);
}

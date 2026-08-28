/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:38:55 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/20 16:01:41 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "../Lib42/memory.h"

size_t	str_len(char *str);
size_t	key_len(char *var);

char	*map_search(char **map, char *key)
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
				return (map[i]);
		i++;
	}
	return (NULL);
}

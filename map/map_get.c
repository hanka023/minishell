/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:53:48 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/20 15:59:57 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"

char	*map_get(char **map, char *key)
{
	char	*var;
	size_t	i;

	var = map_search(map, key);
	if (var)
	{
		i = 0;
		while (var[i] != '=')
			i++;
		return (var + i + 1);
	}
	return (NULL);
}

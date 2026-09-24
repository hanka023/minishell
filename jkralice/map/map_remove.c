/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:08:51 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/20 18:18:38 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include <stdio.h>
#include <unistd.h>
// #include "../../hskalov/libft/libft.h"

#include <stdlib.h>

size_t	map_size(char **map);

// char	**map_remove(char **map, char *key)
// {
// 	char	**out;
// 	char	*var;
// 	size_t	i;

// 	var = map_search(map, key);
// 	if (!var)
// 		return (NULL);
// 	out = malloc(map_size(map) - 1);
// 	i = 0;
// 	while (map[i] != var)
// 	{
// 		out[i] = map[i];
// 		i++;
// 	}
// 	i++;
// 	while (map[i])
// 	{
// 		out[i - 1] = map[i];
// 		i++;
// 	}
// 	out[i] = NULL;
// 	free(var);
// 	free(map);
// 	return (out);
// }

static inline
char **map_compare(char **map, char **out, char *var)
{
	size_t	i;

	i = 0;
	while (map[i] && (map[i] != var))
	{
		out[i] = map[i];
		++i;
	}
	if (map[i] == var)
	{
		free(map[i]);
		i++;
	}
	while (map[i])
	{
		out[i - 1] = map[i];
		++i;
	}
	out[i - 1] = NULL;
	return (out);
}

char	**map_remove(char **map, char *key)
{
	char	**out;
	char	*var;

	var = map_search(map, key);
	if (!var)
		return (NULL);
	out = malloc(sizeof (char *) * map_size(map));
	if (!out)
		return(NULL);
	map_compare(map, out, var);
	free(map);
	return (out);
}

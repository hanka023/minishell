/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:59:27 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/28 14:29:34 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Lib42/memory.h"
#include "../Lib42/str.h"

#include "stdlib.h"

size_t	key_len(char *var)
{
	size_t	out;

	out = 0;
	while (var[out] != '=')
		out++;
	return (out);
}

size_t	map_size(char **map)
{
	size_t	out;

	out = 0;
	while (map[out])
		out++;
	return (out + 1);
}

int	map_key_is_valid(char *key)
{
	size_t	i;
	size_t	len;

	if ((key[0] < 'A' || 'Z' < key[0])
		&& (key[0] < 'a' || 'z' < key[0])
		&& key[0] != '_')
		return (0);
	i = 1;
	len = str_len(key);
	while (i < len)
	{
		if ((key[i] < 'A' || 'Z' < key[i])
			&& (key[i] < 'a' || 'z' < key[i])
			&& (key[i] < '0' || '9' < key[i])
			&& key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*map_combine(char *key, char *val)
{
	char	*out;
	size_t	key_len;
	size_t	val_len;

	key_len = str_len(key);
	if (val)
		val_len = str_len(val);
	else
		val_len = 0;
	out = malloc(key_len + val_len + 2);
	mem_copy(key, out, key_len);
	out[key_len] = '=';
	mem_copy(val, out + key_len + 1, val_len);
	out[key_len + val_len + 1] = '\0';
	return (out);
}

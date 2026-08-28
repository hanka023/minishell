/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:39:55 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/28 14:02:33 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

char	**export(char **map, char *key, char *val)
{
	char	**out;

	out = map_add(map, key, val);
	if (!out && !map_change(map, key, val))
			return (NULL);
	return (out);
}

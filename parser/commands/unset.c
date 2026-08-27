/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:36:44 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/28 14:02:31 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

char	**unset(char **map, char *key)
{
	char	**out;

	out = map_remove(map, key);
	if (!out)
		out = map;
	return (out);
}

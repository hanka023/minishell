/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:02:05 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/20 16:04:51 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "../Lib42/str.h"

#include <unistd.h>

void	map_print(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		write(1, map[i], str_len(map[i]));
		write(1, "\n", 1);
		i++;
	}
}

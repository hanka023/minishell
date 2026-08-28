/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:26:08 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/07 22:46:47 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory.h"

void	*mem_search(void *block, size_t n, void *target, size_t t)
{
	size_t	i;

	i = 0;
	while ((ssize_t)i <= (ssize_t)(n - t))
	{
		if (mem_compare((char *)block + i, target, t) == 0)
			return ((char *)block + i);
		i++;
	}
	return (0);
}

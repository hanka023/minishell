/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:46:28 by jkralice          #+#    #+#             */
/*   Updated: 2026/06/07 17:23:01 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory.h"

void	mem_set(void *block, size_t n, char byte)
{
	size_t	chunk;
	size_t	i;

	((char *)&chunk)[0] = byte;
	((char *)&chunk)[1] = byte;
	((char *)&chunk)[2] = byte;
	((char *)&chunk)[3] = byte;
	((char *)&chunk)[4] = byte;
	((char *)&chunk)[5] = byte;
	((char *)&chunk)[6] = byte;
	((char *)&chunk)[7] = byte;
	i = 0;
	while (i < n / 8)
	{
		((size_t *)block)[i] = chunk;
		i++;
	}
	i *= 8;
	while (i < n)
	{
		((char *)block)[i] = byte;
		i++;
	}
}

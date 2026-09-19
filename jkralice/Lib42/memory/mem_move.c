/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:29:45 by jkralice          #+#    #+#             */
/*   Updated: 2026/05/20 15:02:56 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory.h"

static
void	mem_copy_backwards(void *from, void *to, size_t n)
{
	size_t	i;

	i = n;
	while (i % 8)
	{
		i--;
		((unsigned char *)to)[i] = ((unsigned char *)from)[i];
	}
	i /= 8;
	while (i > 0)
	{
		i--;
		((size_t *)to)[i] = ((size_t *)from)[i];
	}
}

void	mem_move(void *from, void *to, size_t n)
{
	if ((size_t)from < (size_t)to && (size_t)from + n > (size_t)to)
		mem_copy_backwards(from, to, n);
	else
		mem_copy(from, to, n);
}

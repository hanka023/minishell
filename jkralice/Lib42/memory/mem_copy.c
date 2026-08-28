/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:52:53 by user              #+#    #+#             */
/*   Updated: 2026/07/02 16:35:14 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory.h"

void	mem_copy(const void *from, void *to, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n / 8)
	{
		((size_t *)to)[i] = ((size_t *)from)[i];
		i++;
	}
	i *= 8;
	while (i < n)
	{
		((unsigned char *)to)[i] = ((unsigned char *)from)[i];
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:59:29 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/20 18:14:53 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory.h"

ssize_t	mem_compare(void *a, void *b, size_t n)
{
	ssize_t			out;
	size_t			*a64;
	size_t			*b64;
	unsigned char	*a1;
	unsigned char	*b8;

	out = 0;
	a64 = (size_t *)a;
	b64 = (size_t *)b;
	while ((size_t)out < n / 8 && a64[out] == b64[out])
		out++;
	out *= 8;
	a1 = (unsigned char *)a;
	b8 = (unsigned char *)b;
	while ((size_t)out < n && a1[out] == b8[out])
		out++;
	if ((size_t)out == n)
		return (0);
	if (a1[out] > b8[out])
		return (out + 1);
	return (-out - 1);
}

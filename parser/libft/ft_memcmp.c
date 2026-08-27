/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/06/30 14:08:34 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compare memory areas
// The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
// The  memcmp()  function  returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is
// found, respectively, to be less than, to match, or be greater than the first n bytes of s2.
// (interpreted as unsigned char) that differ in s1 and s2.
// If n is zero, the return value is zero.


#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		++i;
	}
	return (0);
}

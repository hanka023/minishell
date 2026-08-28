/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/06/30 14:08:25 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// scan memory for a character
// The  memchr()  function  scans  the initial n bytes of the memory area pointed to by s for the first instance of c.
// Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;
	size_t				i;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
		{
			return ((void *)(ptr + i));
		}
		++i;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/06/30 14:08:43 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memcpy()  function  copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.  Use
// memmove(3) if the memory areas do overlap.
// The memcpy() function returns a pointer to dest

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}

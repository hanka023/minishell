/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/06/30 14:08:52 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memmove()  function  copies  n bytes from memory area src to memory area dest.  The memory areas may overlap: copying
// takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and  the
// bytes are then copied from the temporary array to dest.
// The memmove() function returns a pointer to dest.

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (d > s && d < s + n)
		while (n--)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			++i;
		}
	}
	return (dest);
}

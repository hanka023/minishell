/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 17:24:21 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	if (!haystack && len == 0)
		return (NULL);
	while (haystack[i] && (i < len))
	{
		if (haystack[i] == needle[j])
		{
			while ((i + j) < len && needle[j] && (haystack[i + j] == needle[j]))
				j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		j = 0;
		++i;
	}
	return (0);
}

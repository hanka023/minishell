/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/06/30 14:10:50 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//  The strchr() function returns a pointer to the first occurrence of the character c in the string s

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			x = (char *)(str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (x);
}

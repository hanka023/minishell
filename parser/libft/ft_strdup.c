/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/06/30 14:10:02 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// The  strdup()  function  returns a pointer to a new string which is a duplicate of the string s.  Memory for the
//       new string is obtained with malloc(3), and can be freed with free(3).

#include "libft.h"

char	*ft_strdup(const char *str)

{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (copy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 13:53:36 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	metachar(char *str)
{
	int	len;

	len = 0;
	if (*str == '|')
		len = 1;
	else if (*str == '<' && *(str + 1) != '<')
		len = 1;
	else if (*str == '<' && *(str + 1) == '<')
		len = 2;
	else if (*str == '>' && *(str + 1) != '>')
		len = 1;
	else if (*str == '>' && *(str + 1) == '>')
		len = 2;
	return (len);
}

int	stav_str(char c, int stav)
{
	if (stav == 0)
	{
		if (c == '\'')
			return (1);
		if (c == '"')
			return (2);
	}
	else if (stav == 1 && c == '\'')
		return (0);
	else if (stav == 2 && c == '"')
		return (0);
	return (stav);
}

int	strlen_split(char *str)
{
	int		len;
	char	*set;
	int		stav;

	len = 0;
	stav = 0;
	set = " \t\n|<>";
	while (str[len])
	{
		if (stav == 0 && is_in_set(str[len], set))
			break ;
		stav = stav_str(str[len], stav);
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while ((i < (n - 1)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	strlen_copy(char *str)
{
	int		len;
	char	*set;
	int		stav;

	len = 0;
	stav = 0;
	set = " \t\n|<>";
	while (str[len])
	{
		stav = stav_str(str[len], stav);
		if (stav == 0 && is_in_set(str[len], set))
			break ;
		len++;
	}
	return (len);
}

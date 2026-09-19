/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:42:25 by haskalov         ###   ########.fr       */
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

int	stav_str(char *str, int stav)
{
	if (*str == '\'' && stav == 0)
		stav = 1;
	else if (*str == '\'' && stav == 1)
		stav = 0;
	else if (*str == '\"' && stav == 0)
		stav = 2;
	else if (*str == '\"' && stav == 2)
		stav = 0;
	return (stav);
}

int	strlen_split(char *str)
{
	int		len;
	char	*set;

	len = 0;
	set = " \t\n|<>";
	while (*str && !is_in_set(*str, set))
	{
		++str;
		++len;
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
	if (*str == '\"')
		stav = 2;
	else if (*str == '\'')
		stav = 1;
	++str;
	++len;
	while (*str)
	{
		stav = stav_str(str, stav);
		if (is_in_set(*str, set) && stav == 0)
			return (len);
		else
		{
			++str;
			++len;
		}
	}
	return (len);
}

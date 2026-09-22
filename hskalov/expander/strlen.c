/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/22 14:03:05 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

int	strlen_zero(char *str)
{
	int	len;

	len = 0;
	while (*str && *str != '\'' && *str != '\"')
	{
		++str;
		++len;
	}
	return (len);
}

int	strlen_one(char *str)
{
	int	len;

	len = 0;
	if (*str == '\'')
	{
		++str;
		++len;
	}
	while (*str && *str != '\'')
	{
		++str;
		++len;
	}
	if (*str == '\'')
	{
		++str;
		++len;
	}
	return (len);
}

int	strlen_two(char *str)
{
	int	len;

	len = 0;
	if (*str == '\"')
	{
		++str;
		++len;
	}
	while (*str && *str != '\"')
	{
		++str;
		++len;
	}
	if (*str == '\"')
	{
		++str;
		++len;
	}
	return (len);
}

int	strlen_word_zero(char *s)
{
	int	l;

	if (!s || !*s)
		return (0);
	l = 0;
	if (s[l] == '$')
		++l;
	while (s[l] && s[l] != '\0' && s[l] != '$' && s[l] != '\'' && s[l] != '\"')
	{
		++l;
	}
	return (l);
}

int	strlen_word(char *s)
{
	int	l;

	if (!s || !*s)
		return (0);
	l = 0;
	if (s[l] == '$')
		++l;
	while (s[l] && s[l] != '\0' && s[l] != '$' && s[l] != '\"')
	{
		++l;
	}
	return (l);
}


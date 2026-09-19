/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/13 16:22:24 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

int	strlen_zero(char *str)
{
	int		len;
	char	*set;

	len = 0;
	set = " \t\n|<>\'\"";
	while (*str && !is_in_set(*str, set))
	{
		++str;
		++len;
	}
	return (len);
}

int	strlen_zero_zero(char *str)
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

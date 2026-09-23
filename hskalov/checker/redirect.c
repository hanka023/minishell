/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/23 20:02:24 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	is_rd(char c)
{
	if (c == '>' || c == '<')
		return (1);
	else
		return (0);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	check_redirect(char *str)
{
	int	stav;

	if (!str)
		return (0);
	stav = 0;
	while (*str)
	{
		stav = stav_str(*str, stav);
		if (stav == 0 && is_rd(*str) == 1)
		{
			if (*(str + 1) == *str)
				++str;
			if (is_rd(*(str + 1)) == 1)
				return (1);
			++str;
			while (*str && is_space(*str) == 1)
				++str;
			if (*str == '\0' || *str == '|' || is_rd(*str) == 1)
				return (1);
			continue ;
		}
		++str;
	}
	return (0);
}

int	check_redirect_error(char *str)
{
	int	redirect;

	redirect = check_redirect(str);
	if (redirect == 1)
	{
		perror ("Error redirect\n");
		return (1);
	}
	else if (redirect == 0)
		return (0);
	else
		return (-1);
}

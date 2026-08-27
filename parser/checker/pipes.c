/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:17:06 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	check_pipes_str(char *str, int stav, int pipe, int last)
{
	while (*str)
	{
		stav = stav_str(str, stav);
		if (stav != 0)
			++str;
		if (*str == '|' && pipe == 0)
			return (1);
		else if (*str == '|' && pipe == 1)
		{
			pipe = 0;
			last = 1;
			++str;
		}
		else if (ft_isalnum(*str) == 1)
		{
			pipe = 1;
			last = 0;
			++str;
		}
		else if ((*str == '<' || *str == '>') && last == 1)
			return (1);
		else
			++str;
	}
	return (last);
}

int	check_pipes(char *str)
{
	int	stav;
	int	pipe;
	int	last;

	stav = 0;
	pipe = 0;
	last = 0;
	if (*str == '\'')
		stav = 1;
	else if (*str == '\"')
		stav = 2;
	last = check_pipes_str(str, stav, pipe, last);
	return (last);
}

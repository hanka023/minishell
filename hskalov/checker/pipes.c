/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/22 22:32:57 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	check_pipes_str(char *str)
{
	int	stav;
	int	expecting_command;

	stav = 0;
	expecting_command = 1;
	while (*str)
	{
		stav = stav_str(*str, stav);
		if (stav == 0)
		{
			if (*str == '|')
			{
				if (expecting_command == 1)
					return (1);
				expecting_command = 1;
			}
			else if (!is_in_set(*str, " \t\n"))
				expecting_command = 0;
		}
		else
			expecting_command = 0;
		++str;
	}
	return (expecting_command);
}

int	check_pipes(char *str)
{
	if (!str)
		return (0);
	return (check_pipes_str(str));
}

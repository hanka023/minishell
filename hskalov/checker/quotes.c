/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 16:28:13 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../minishell.h"

int	check_quotes(char *str)
{
	int	quotes;

	quotes = 0;
	while (*str)
	{
		if (*str == '\'' && quotes == 0)
			quotes = 1;
		else if (*str == '\'' && quotes == 1)
			quotes = 0;
		++str;
	}
	return (quotes);
}

int	check_double_quotes(char *str)
{
	int	quotes;

	quotes = 0;
	while (*str)
	{
		if (*str == '\"' && quotes == 0)
			quotes = 1;
		else if (*str == '\"' && quotes == 1)
			quotes = 0;
		++str;
	}
	return (quotes);
}

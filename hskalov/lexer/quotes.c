/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 16:28:29 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	quotes(char *str)
{
	int	len;

	len = 0;
	if (*str == '\'')
		len = single_quote (str);
	else if (*str == '"')
		len = double_quotes (str);
	return (len);
}

int	single_quote(char *str)
{
	int		len;
	char	*start;

	start = str;
	len = 0;
	++str;
	while (*str && *str != '\'')
		++str;
	if (*str == '\'')
		++str;
	len = str - start;
	return (len);
}

int	double_quotes(char *str)
{
	int		len;
	char	*start;

	start = str;
	len = 0;
	++str;
	while (*str && *str != '\"')
		++str;
	if (*str == '\"')
		++str;
	len = str - start;
	return (len);
}

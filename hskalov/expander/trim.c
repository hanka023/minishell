/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/13 16:00:34 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../minishell.h"

char	*two_trim(char *str)
{
	char	*copy;
	char	*start;
	int		len;

	len = 0;
	if (*str == '\"')
		++str;
	while (str[len] != '\0' && str[len] != '\"')
		++len;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	start = copy;
	while (len > 0)
	{
		*copy = *str;
		++copy;
		++str;
		--len;
	}
	*copy = '\0';
	copy = start;
	return (start);
}

char	*one_trim(char *str)
{
	char	*copy;
	char	*start;
	int		len;

	len = 0;
	if (*str == '\'')
		++str;
	while (str[len] != '\0' && str[len] != '\'')
		++len;
	copy = malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	start = copy;
	while (len > 0)
	{
		*copy = *str;
		++copy;
		++str;
		--len;
	}
	*copy = '\0';
	copy = start;
	return (start);
}
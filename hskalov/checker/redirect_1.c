/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:22:00 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	multi_check_left(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<')
			++count;
		if (count > 2)
			return (1);
		if (str[i] != '<')
			count = 0;
		++i;
	}
	return (0);
}

int	multi_check_right(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>')
			++count;
		if (count > 2)
			return (1);
		if (str[i] != '>')
			count = 0;
		++i;
	}
	return (0);
}

int	last_check(char *str)
{
	int	last;

	last = 0;
	while (*str)
	{
		if ((*str == '<') && (*(str + 1) != '<'))
			last = 1;
		else if ((*str == '>') && (*(str + 1) != '>'))
			last = 1;
		else if (ft_isalnum(*str) == 1)
			last = 0;
		++str;
	}
	return (last);
}

int	first_check(char *str)
{
	int	first;

	first = 1;
	while (*str)
	{
		if (ft_isalnum (*str) == 1)
			first = 0;
		if ((*str == '<' || (*str) == '>' || (*str) == '|') && first == 1)
			return (1);
		++str;
	}
	return (0);
}

int	pipe_check(char *str, int pipe)
{
	int	redirect;

	redirect = 0;
	while (*str)
	{
		if (*str == '<' || *str == '>')
		{
			if (pipe == 1)
				return (1);
			redirect = 1;
		}
		else if (*str == '|')
		{
			if (redirect == 1)
				return (1);
			pipe = 1;
		}
		else if (ft_isalnum(*str) == 1)
		{
			redirect = 0;
			pipe = 0;
		}
		++str;
	}
	return (0);
}

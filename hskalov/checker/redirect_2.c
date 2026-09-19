/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:24:13 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	left_right_check(char *str, int left, int right)
{
	while (*str)
	{
		if (*str == '<')
		{
			if (right == 1)
				return (1);
			left = 1;
		}
		else if (*str == '>')
		{
			if (left == 1)
				return (1);
			right = 1;
		}
		if (ft_isalnum (*str) == 1)
		{
			left = 0;
			right = 0;
		}
		++str;
	}
	return (0);
}

int	left_right_pipe(char *str)
{
	int	left;
	int	right;
	int	pipe;
	int	redirect;
	int	all;

	left = 0;
	right = 0;
	pipe = 0;
	redirect = 0;
	all = 0;
	pipe = pipe_check(str, pipe);
	redirect = left_right_check(str, left, right);
	all = pipe + redirect;
	return (all);
}

int	first_last_double(char *str)
{
	int	multi_l;
	int	multi_r;
	int	last;
	int	first;
	int	all;

	multi_l = 0;
	multi_r = 0;
	last = 0;
	first = 0;
	all = 0;
	multi_l = multi_check_left(str);
	multi_r = multi_check_right(str);
	last = last_check(str);
	first = first_check(str);
	all = multi_l + multi_r + last + first;
	return (all);
}

int	check_redirect(char *str)
{
	int	multi;
	int	f_l_d;
	int	all;

	multi = 0;
	f_l_d = 0;
	all = 0;
	multi = left_right_pipe(str);
	f_l_d = first_last_double(str);
	all = multi + f_l_d;
	if (all > 0)
	{
		printf ("check KO :(\n");
		return (1);
	}
	else
		return (0);
}

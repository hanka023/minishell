/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/19 17:05:22 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	test_name(char *str, t_env *env)
{
	char	*name;
	size_t	len;
	int		cmp;

	if (*str == '$')
		++str;
	name = str;
	len = strlen_name (str);
	while (env != NULL)
	{
		cmp = ft_strncmp(name, env -> name, len);
		if (cmp == 0)
			return (0);
		env = env -> next;
	}
	return (1);
}

int	check_names(char *str, t_env *env)
{
	int	stav;
	int	test;

	stav = 0;
	test = 0;
	while (*str)
	{
		if (*str == '\'' && stav == 0)
			stav = 1;
		else if (*str == '\'' && stav == 1)
			stav = 0;
		else if (*str == '\"' && stav == 0)
			stav = 2;
		else if (*str == '\"' && stav == 2)
			stav = 0;
		if (*str == '$' && stav != 1)
			test = test_name (str, env);
		if (test == 1)
			return (1);
		++str;
	}
	return (0);
}

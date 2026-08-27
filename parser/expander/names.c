/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/27 16:00:57 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	strlen_name(char *str)
{
	int	len;

	len = 0;
	if (*str == '$')
	{
		++str;
		++len;
	}
	while (*str && (ft_isalnum(*str) || *str == '_'))
	{
		++str;
		++len;
	}
	return (len);
}

int	test_names(char *str, t_env *env)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '$')
		{
			len = strlen_name (str);
			if (test_name(str, env) == 1)
				return (1);
			str = str + len;
		}
		else
			++str;
	}
	return (0);
}

int	name_len(char *str)
{
	int	len;

	len = 0;
	while (*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		++str;
		++len;
	}
	return (len);
}

char	*copy_name(char *str)
{
	int		len;
	char	*name;
	char	*start;

	len = strlen_name(str);
	name = malloc (sizeof(char) * (len + 1));
	if (!name)
		return (NULL);
	start = name;
	while (len > 0)
	{
		*name = *str;
		++name;
		++str;
		--len;
	}
	*name = '\0';
	return (start);
}

char	*find_name(char *str, t_env *env)
{
	char	*name;
	int		test;

	test = 0;
	if (*str == '$')
		++str;
	name = copy_name(str);
	test = test_names(name, env);
	if (test != 0)
	{
		free(name);
		return (NULL);
	}
	return (name);
}

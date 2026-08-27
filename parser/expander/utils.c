/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/13 16:22:07 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char	*find_dollar(char *str)
{
	int	stav;

	stav = 0;
	while (*str)
	{
		if ((*str == '\'') && stav == 0)
			stav = 1;
		else if (*str == '\'' && stav == 1)
			stav = 0;
		if (stav == 0 && *str == '$' && *(str + 1) != '\0')
			return (NULL);
		else
			++str;
	}
	return (str);
}

int	expand_len(t_list *lst, t_env *env)
{
	char	*str;
	int		len;

	str = lst -> str;
	len = 0;
	while (*str)
	{
		while (*str != '$')
		{
			++str;
			++len;
		}
		if (*str == '$')
		{
			len = env_len(str, env);
			str = str + (len - 1);
		}
	}
	return (len);
}

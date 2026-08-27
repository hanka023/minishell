/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/19 16:57:13 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char	env_cmp(char *copy, t_env *env)
{
	int	len;

	len = 0;
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
			len = ft_strlen(env -> value);
		env = env -> next;
	}
	free (copy);
	return (len);
}

int	env_len(char *str, t_env *env)
{
	char	*copy;
	char	*start;
	int		len;

	if (!str || *str != '$')
	{
		perror("ve find_env neni str\n");
		return (0);
	}
	++str;
	start = str;
	while (*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		*copy = *str;
		++copy;
		++str;
	}
	copy = '\0';
	copy = start;
	len = env_cmp(copy, env);
	return (len);
}

char	*copy_env(char *str, t_env *env)
{
	char	*copy;
	char	*start;
	char	*env_value;

	if (!str || *str != '$')
	{
		perror("ve find_env neni str\n");
		return (NULL);
	}
	else if (*str == '$')
		++str;
	start = str;
	while (*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		*copy = *str;
		++copy;
		++str;
	}
	copy = '\0';
	copy = start;
	env_value = find_env(copy, env);
	return (env_value);
}

char	*env_handler(t_list *lst)
{
	t_env	*env;
	char	*is_env;

	env = env_to_lst();
	is_env = NULL;
	is_env = find_env(lst -> str, env);
	if (is_env != NULL)
	{
		free (lst ->str);
		lst -> str = ft_strdup(is_env);
	}
	return (is_env);
}

char	*find_env(char *str, t_env *env)
{
	char	*copy;
	char	*set;

	if (!str)
	{
		perror("ve find_env neni str\n");
		return (NULL);
	}
	set = " \n\t";
	copy = ft_strtrim(str, set);
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
		{
			free(copy);
			return (env -> value);
		}
		env = env -> next;
	}
	free (copy);
	return (NULL);
}

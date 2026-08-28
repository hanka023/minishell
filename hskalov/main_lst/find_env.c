/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/10 20:45:53 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "../minishell.h"

char	**find_env_name(char *str, t_env *env)
{
	char	*copy;
	char	*set;
	char	*start;

	if (!str)
		return (NULL);
	set = " \n\t";
	copy = ft_strtrim(str, set);
	if (!copy)
		return (NULL);
	start = copy;
	if (*copy == '$')
		++copy;
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
		{
			free (start);
			return &(env -> name);
		}
		env = env -> next;
	}
	free (start);
	return (NULL);
}

char	*find_env_value(char *str, t_env *env)
{
	char	*copy;
	char	*set;
	char	*start;

	if (!str)
		return (NULL);
	set = " \n\t";
	copy = ft_strtrim(str, set);
	if (!copy)
		return (NULL);
	start = copy;
	if (*copy == '$')
		++copy;
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
		{
			//if (env -> str != NULL)
			free (start);
			return (env -> value);
		}
		env = env -> next;
	}
	free (start);
	return (NULL);
}

// char	*find_env_str(char *str, t_env *env)
// {
// 	char	*copy;
// 	char	*set;
// 	char	*start;

// 	if (!str)
// 		return (NULL);
// 	set = " \n\t";
// 	copy = ft_strtrim(str, set);
// 	if (!copy)
// 		return (NULL);
// 	start = copy;
// 	if (*copy == '$')
// 		++copy;
// 	while (env != NULL)
// 	{
// 		if (ft_strcmp (copy, env -> name) == 0)
// 		{
// 			//if (env -> str != NULL)
// 			free (start);
// 			return (env -> str);
// 		}
// 		env = env -> next;
// 	}
// 	free (start);
// 	return (NULL);
// }

t_env	*find_env_node(char *str, t_env *env)
{
	char	*copy;
	char	*set;
	char	*start;

	if (!str)
		return (NULL);
	set = " \n\t";
	copy = ft_strtrim(str, set);
	if (!copy)
		return (NULL);
	start = copy;
	if (*copy == '$')
		++copy;
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
		{
			free (start);
			return (env);
		}
		env = env -> next;
	}
	free (start);
	return (NULL);
}

char *change_env_name(t_env *env, char *old_name, char *new_name)
{
	char	*copy;
	char	*set;
	char	*start;

	if (!old_name)
		return (NULL);
	set = " \n\t";
	copy = ft_strtrim(old_name, set);
	if (!copy)
		return (NULL);
	start = copy;
	if (*copy == '$')
		++copy;
	while (env != NULL)
	{
		if (ft_strcmp (old_name, env -> name) == 0)
		{
			printf(" ****** env -> name >>>%s<<< ****\n", env -> name);
			free (env -> name);
			(env -> name) = ft_strdup(new_name);
			free(start);
			printf(" ****** env -> name >>>%s<<< ****\n", env -> name);
			printf(" ****** env -> value >>>%s<<< ****\n", env -> value);
			return (env -> name);
		}
		env = env -> next;
	}
	free (start);
	return (NULL);
}

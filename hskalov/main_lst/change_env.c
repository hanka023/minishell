/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 17:28:46 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "../minishell.h"

int	change_env_value(t_env *env, char *old_value, char *new_value)
{
	char	*copy;
	char	*start;

	if (!old_value)
		return (1);
	copy = ft_strtrim(old_value, " \n\t");
	if (!copy)
		return (1);
	start = copy;
	if (*copy == '$')
		++copy;
	while (env != NULL)
	{
		if (ft_strcmp (copy, (env -> name)) == 0)
		{
			free (start);
			free ((env -> value));
			((env -> value)) = ft_strdup (new_value);
			return (0);
		}
		env = (env -> next);
	}
	free (start);
	return (1);
}

/* 
	check if new name is vaid 
	returns 0 if name is no valid
	returns 1 if name is valid
*/

int	check_env_name(char *name)
{
	if (!name)
		return (0);
	if (ft_isalpha(name[0]) == 1)
	{
		printf (" >>> %c  name OK", name[0]);
		return (1);
	}
	else
		printf ("name KO :(");
	return (0);
}

int	change_name(t_env *env, char *old_name, char *new_name)
{
	t_env	*find;
	char	*new;

	if (!env || !old_name || !new_name)
		return (-1);
	find = find_env_node (old_name, env);
	if (!find)
		return (-1);
	new = ft_strdup (new_name);
	if (!new)
		return (-1);
	free (find -> name);
	(find -> name) = new;
	return (0);
}

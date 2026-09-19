/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 16:27:57 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../minishell.h"

t_env	*env_to_lst(char **environ)
{
	t_env		*head;
	t_env		*env;
	char		**copy_environ;

	head = NULL;
	copy_environ = environ;
	while (*copy_environ)
	{
		env = new_env(*copy_environ);
		env_add_back(&head, env);
		++copy_environ;
	}
	return (head);
}

void	env_name(char *str, t_env *env)
{
	char	*name;
	int		len;

	len = 0;
	name = str;
	while (name[len] != '=' && name[len] != '\0')
		++len;
	if (len == 0)
	{
		env -> name = NULL;
		return ;
	}
	name[len] = '\0';
	env -> name = ft_strdup(name);
	if (len == 0)
		env -> name = NULL;
	return ;
}

void	env_value(char *str, t_env *env)
{
	while (*str != '=' && *str != '\0')
		++str;
	if (*str == '=' && *str != '\0')
		++str;
	env -> value = ft_strdup(str);
	return ;
}

t_env	*new_env(char *str)
{
	t_env	*env;
	char	*copy;

	env = malloc (sizeof (t_env));
	if (!env)
		return (NULL);
	copy = ft_strdup (str);
	env_name (copy, env);
	env_value (str, env);
	free(copy);
	env -> next = NULL;
	return (env);
}

void	env_add_back(t_env **head, t_env *env)
{
	t_env	*tmp;

	if (!head || !env)
		return ;
	if (*head == NULL)
	{
		*head = env;
		return ;
	}
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = env;
	return ;
}

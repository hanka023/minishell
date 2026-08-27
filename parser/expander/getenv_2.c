/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/19 16:58:29 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../minishell.h"

void	print_env(t_env *env)
{
	while (env != NULL)
	{
		printf("%s = %s\n", env -> name, env -> value);
		env = env -> next;
	}
	return ;
}

void	free_env(t_env *env)
{
	t_env	*free_env ;

	while (env != NULL)
	{
		free_env = (env)-> next;
		free(env -> name);
		free(env -> value);
		free(env);
		env = free_env;
	}
	return ;
}

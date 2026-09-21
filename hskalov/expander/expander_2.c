/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 13:46:37 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char	*expand_str(char *str, t_env *env, int *len, t_state *state)
{
	char	*copy;

	copy = "";
	*len = 0;
	if (*str != '\'' && *str != '\"')
	{
		copy = zero_handler(str, env, state);
		*len = strlen_zero(str);
	}
	else if (*str == '\'')
	{
		copy = one_handler(str);
		*len = strlen_one(str);
	}
	else if (*str == '\"' )
	{
		copy = two_handler(str, env, state);
		*len = strlen_two(str);
	}
	if (!copy)
		copy = ft_strdup("");
	return (copy);
}

char	*expand_string(char *str, t_env *env, t_state *state)
{
	char	*copy;
	char	*new_copy;
	char	*tmp;
	int		len;

	copy = "";
	new_copy = ft_strdup("");
	if (! new_copy)
		return (NULL);
	tmp = "";
	while (str && *str)
	{
		copy = expand_str(str, env, &len, state);
		if (len <= 0)
		{
			free(copy);
			break ;
		}
		str = str + len;
		tmp = ft_strjoin(new_copy, copy);
		free(new_copy);
		free (copy);
		new_copy = tmp;
	}
	return (new_copy);
}

int	expander(t_list *lst, t_env *env, t_state *state)
{
	char	*new_str;

	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (lst -> str)
		{
			new_str = expand_string(lst -> str, env, state);
			if (!new_str)
				return (1);
			free(lst -> str);
			lst -> str = new_str;
		}
		lst = lst -> next;
	}
	return (0);
}

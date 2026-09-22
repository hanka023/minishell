/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/22 20:35:24 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"


char	*expand_str(char *str, t_env *env, int *len, t_state *state)
{
	char	*copy;

	copy = NULL;
	*len = 0;
	if (str[0] != '\'' && str[0] != '\"')
	{
		copy = zero_handler(str, env, state);
		*len = strlen_zero(str);
		//type -> typ = 0;
	}
	else if (str[0] == '\'')
	{
		copy = one_handler(str);
		*len = strlen_one(str);
		//type -> typ = 1;
	}
	else if (str[0] == '\"' )
	{
		copy = two_handler(str, env, state);
		*len = strlen_two(str);
		//type -> typ = 1;
	}
	if (!copy)
		copy = ft_strdup("");
	return (copy);
}


int	expand_string(t_list *lst, t_env *env, t_state *state)
{
	char	*copy;
	char	*new_copy;
	char	*tmp;
	int		len;
	char	*str;

	if (!lst || !lst -> str)
		return (0);
	str = lst -> str;
	new_copy = ft_strdup("");
	if (! new_copy)
		return (0);
	tmp = "";
	while (*str)
	{
		copy = expand_str(str, env, &len, state);
		if (!copy || len <= 0)
		{
			if (copy)
				free(copy);
			break ;
		}
		str = str + len;
		tmp = ft_strjoin(new_copy, copy);
		free(new_copy);
		free (copy);
		if (!tmp)
			return(0);
		new_copy = tmp;
	}
	free(lst -> str);
	lst -> str = new_copy;
	return (1);
}

int	expander(t_list *lst, t_env *env, t_state *state )
{
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (lst -> str)
			if (!expand_string (lst, env, state))
				return (1);
		lst = lst -> next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 16:36:27 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char	*expand_str(t_list *lst, t_env *env, int *len, t_state *state)
{
	char	*copy;

	copy = "";
	*len = 0;
	if (lst->str[0] != '\'' && lst->str[0] != '\"')
	{
		copy = zero_handler(lst->str, env, state);
		*len = strlen_zero(lst->str);
		lst->type = 0;
	}
	else if (lst->str[0] == '\'')
	{
		copy = one_handler(lst->str);
		*len = strlen_one(lst->str);
		lst->type = 1;
	}
	else if (lst->str[0] == '\"' )
	{
		copy = two_handler(lst->str, env, state);
		*len = strlen_two(lst->str);
		lst->type = 1;
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

	copy = "";
	new_copy = ft_strdup("");
	if (! new_copy)
		return (0);
	tmp = "";
	while (lst->str && lst->str[0])
	{
		copy = expand_str(lst, env, &len, state);
		if (len <= 0)
		{
			free(copy);
			break ;
		}
		lst->str = lst->str + len;
		tmp = ft_strjoin(new_copy, copy);
		free(new_copy);
		free (copy);
		new_copy = tmp;
	}
	lst->str = new_copy;
	return (new_copy != 0);
}

int	expander(t_list *lst, t_env *env, t_state *state)
{
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (lst -> str)
			if (!expand_string(lst, env, state))
				return (1);
		lst = lst -> next;
	}
	return (0);
}

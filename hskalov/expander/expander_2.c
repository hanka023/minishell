/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 16:26:09 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char	*expand_metachar(char *str)
{
	int		len;
	char	*start;
	char	*copy;

	len = 0;
	len = metachar(str);
	copy = malloc (sizeof (char) * (len + 1));
	if (!copy)
		return (0);
	start = copy;
	while (len > 0)
	{
		*copy = *str;
		++copy;
		++str;
		--len;
	}
	*copy = '\0';
	copy = start;
	return (copy);
}

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
	while (*str)
	{
		copy = expand_str(str, env, &len, state);
		str = str + len;
		tmp = ft_strjoin(new_copy, copy);
		free(new_copy);
		new_copy = ft_strdup(tmp);
		free (tmp);
		free (copy);
	}
	return (new_copy);
}

char	*expand_lst(t_list *lst, t_env *env, t_state *state)
{
	char	*str;
	char	*new_copy;
	char	*metachar_set;

	metachar_set = "|<>";
	str = lst -> str;
	if (is_in_set(*str, metachar_set) || is_in_set(*(str +1), metachar_set))
		return (expand_metachar(str));
	else
	{
		new_copy = expand_string(str, env, state);
		if (!new_copy)
			return (NULL);
		return (new_copy);
	}
}

int	expander(t_list *lst, t_env *env, t_state *state)
{
	char	*new_lst;

	if (!lst)
		return (0);
	while (lst != NULL)
	{
		new_lst = expand_lst(lst, env, state);
		if (!new_lst)
			return (1);
		free(lst -> str);
		lst -> str = ft_strdup(new_lst);
		free(new_lst);
		lst = lst -> next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_one_two_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/22 18:40:23 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char *list_to_str(t_list *lst)
{
	char *tmp;
	char *copy;
	
	copy = ft_strdup ("");
	if (!copy)
		return (NULL);
	while (lst != NULL)
	{
		if (lst -> str)
		{
			tmp = ft_strjoin (copy, lst -> str);
			free(copy);
			copy = tmp;
		}
		lst = lst -> next;
	}
	return (copy);
}

char	*zero_handler(char *str, t_env *env, t_state *state)
{
	t_list	*zero;
	t_list	*start;
	char	*copy;

	if (test_names(str, env) == 1)
		return (ft_strdup(""));
	zero = zero_lst(str, env, state);
	if (!zero)
		return (ft_strdup(""));
	start = zero;
	copy = list_to_str(zero);
	if (!copy)
	{
		free_list(start);
		return (NULL);
	}	
	free_list(start);
	return (copy);
}

char	*one_handler(char *str)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (*str == '\'')
		++str;
	while (str[len] != '\0' && str[len] != '\'')
		++len;
	copy = malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (copy);
}

char	*two_handler(char *s, t_env *env, t_state *state)
{
	t_list	*lst;
	t_list	*start;
	char	*copy;

	lst = two_lst(s, env, state);
	if (!lst)
		return (ft_strdup(""));
	start = lst;
	copy = list_to_str(lst);
	if (!copy)
	{
		free_list(start);
		return (NULL);
	}
	free_list(start);
	return (copy);
}

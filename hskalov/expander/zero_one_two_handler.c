/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_one_two_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/26 19:32:23 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parser.h"

char	*zero_handler(char *str, t_env *env, t_state *state)
{
	t_list	*zero;
	t_list	*start;
	char	*copy;
	char	*tmp;

	copy = "";
	if (test_names(str, env) == 1)
		return (NULL);
	zero = zero_lst(str, env, state);
	start = zero;
	while (zero != NULL)
	{
		tmp = ft_strjoin (copy, zero -> str);
		copy = ft_strdup(tmp);
		free(tmp);
		zero = zero -> next;
	}
	zero = start;
	free_list(zero);
	return (copy);
}

char	*one_handler(char *str)
{
	char	*copy;
	char	*start;

	if (*str == '\'')
		++str;
	copy = copy_string (str, '\'');
	start = copy;
	if (*copy == '\'')
		*copy = '\0';
	return (start);
}

char	*two_handler(char *s, t_env *env, t_state *state)
{
	t_list	*lst;
	t_list	*start;
	char	*cp;
	char	*tmp;

	lst = two_lst(s, env, state);
	start = lst;
	cp = ft_strdup("");
	if (!cp)
		return (NULL);
	while (lst != NULL)
	{
		tmp = ft_strjoin(cp, lst -> str);
		free(cp);
		cp = ft_strdup(tmp);
		free(tmp);
		lst = lst -> next;
	}
	lst = start;
	free_list(lst);
	return (cp);
}
	

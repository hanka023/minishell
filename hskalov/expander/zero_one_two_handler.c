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
	t_list	*two;
	t_list	*start;
	char	*copy;
	char	*tmp;

	copy = "";
	if (test_names(str, env) == 1)
		return (NULL);
	two = two_lst(str, env, state);
	start = two;
	while (two != NULL)
	{
		tmp = ft_strjoin (copy, two -> str);
		copy = ft_strdup(tmp);
		free(tmp);
		two = two -> next;
	}
	two = start;
	free_list(two);
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
	char	*str;
	char	*cp;
	char	*tmp;

	str = two_trim(s);
	lst = two_lst(str, env, state);
	start = lst;
	free(str);
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

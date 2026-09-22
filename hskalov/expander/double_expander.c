/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/22 18:20:22 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../minishell.h"

char	*zero_prepare(char *s)
{
	char	*copy;
	char	*start;
	int		l;
	int		i;

	l = 0;
	i = 0;
	if(s[l] == '$')
		++l;
	while (s[l] != '\0' && s[l] != '$' &&  s[l] != '\'' && s[l] != '\"')
		++l;
	copy = malloc (sizeof (char) *(l + 1));
	if (!copy)
		return (NULL);
	start = copy;
	while (i < l)
	{
		copy[i] = s[i];
		++i;
	}
	copy [i] = '\0';
	return (start);
}

char	*word_prepare(char *str)
{
	char	*copy;
	char	*start;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if(str[len] == '$')
		++len;
	while (str[len] != '\0' && str[len] != '$' && str[len] != '\"')
		++len;
	copy = malloc (sizeof (char) *(len + 1));
	if (!copy)
		return (NULL);
	start = copy;
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy [i] = '\0';
	return (start);
}

void	zero_to_lst(char *str, t_list **head_w)
{
	t_list	*lst;
	char	*copy;
	
	copy = zero_prepare(str);
	lst = new_list(copy);
	add_back(head_w, lst);
	free (copy);
	return ;
}

void	word_to_lst(char *str, t_list **head_w)
{
	t_list	*lst;
	char	*copy;

	copy = word_prepare(str);
	lst = new_list(copy);
	add_back(head_w, lst);
	free (copy);
	return ;
}

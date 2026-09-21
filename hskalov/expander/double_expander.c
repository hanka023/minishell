/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 13:45:26 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../minishell.h"

char	*zero_prepare(char *s)
{
	char	*copy;
	char	*start;
	int		l;

	l = 0;
	while (s[l] != '$' && s[l] != '\0' && s[l] != '\'' && s[l] != '\"')
		++l;
	copy = malloc (sizeof (char) *(l + 1));
	if (!copy)
		return (NULL);
	start = copy;
	while (*s != '$' && *s != '\0' && *s != '\'' && *s != '\"')
	{
		*copy = *s;
		++copy;
		++s;
	}
	*copy = '\0';
	return (start);
}

char	*word_prepare(char *str)
{
	char	*copy;
	char	*start;
	int		len;

	len = 0;
	while (str[len] != '$' && str[len] != '\0' && str[len] != '\"')
		++len;
	copy = malloc (sizeof (char) *(len + 1));
	if (!copy)
		return (NULL);
	start = copy;
	while (*str != '$' && *str != '\0' && *str != '\"')
	{
		*copy = *str;
		++copy;
		++str;
	}
	*copy = '\0';
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

int	strlen_word(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str && *str != '\0' && *str != '$' && *str != '\"')
	{
		++len;
		++str;
	}
	return (len);
}

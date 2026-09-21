/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 13:51:52 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

char	*make_copy(char *str, int len)
{
	char	*copy;
	char	*start;

	copy = malloc (sizeof(char) * (len + 1));
	if (! copy)
		return (NULL);
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

char	*copy_metachar(char *str, int len)
{
	char	*copy;
	char	*start;

	copy = malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
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

int	no_set(char *str, t_list **head)
{
	int		len;

	len = strlen_copy (str);
	if (word_to_list (str, head, len) != 0)
		return (0);
	return (len);
}

int	m_set(char *str, t_list **head)
{
	int		len;

	len = metachar (str);
	if (word_to_list (str, head, len) != 0)
		return (0);
	return (len);
}

t_list	*my_split(char *str)
{
	t_list	*head;
	char	*set;
	char	*metachar_set;
	int		len;

	set = " \t\n";
	metachar_set = "|<>";
	head = NULL;
	while (*str && *str != '\0')
	{
		while (*str && is_in_set(*str, set))
			++str;
		if (*str == '\0')
			break ;
		if (is_in_set(*str, metachar_set))
			len = m_set(str, &head);
		else
			len = no_set(str, &head);
		if (len <= 0)
			break ;
		str = str + len;
	}
	return (head);
}

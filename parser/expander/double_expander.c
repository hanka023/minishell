/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/27 16:01:03 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*two_trim(char *str)
{
	char	*copy;
	char	*start;
	int		len;

	len = 0;
	if (*str == '\"')
		++str;
	while (str[len] != '\0' && str[len] != '\"')
		++len;
	copy = malloc(sizeof(char) * (len + 1));
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
	return (start);
}

char	*one_trim(char *str)
{
	char	*copy;
	char	*start;
	int		len;

	len = 0;
	if (*str == '\'')
		++str;
	while (str[len] != '\0' && str[len] != '\'')
		++len;
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

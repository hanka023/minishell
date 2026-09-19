/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:37:28 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	word_to_list(char *str, t_list **head, int len)
{
	int		i;
	char	*copy;
	t_list	*lst;

	i = 0;
	copy = malloc (sizeof (char) * (len + 1));
	if (!copy)
		return (1);
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[i] = '\0';
	lst = new_list (copy);
	free (copy);
	add_back (head, lst);
	return (0);
}

void	word_to_list2(char *str, t_list **head, int len)
{
	int		i;
	char	*copy;
	t_list	*lst;

	i = 0;
	copy = malloc (sizeof (char) * (len + 1));
	if (!copy)
		return ;
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[i] = '\0';
	lst = new_list (copy);
	free (copy);
	add_back (head, lst);
	return ;
}

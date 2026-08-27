/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/24 15:15:31 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "lst.h"
#include "../minishell.h"

int	quotes_remove(t_list *lst)
{
	while (lst != NULL)
		lst = lst -> next;
	return (0);
}

char	**lst_to_str(t_list *lst)
{
	char	**str;
	int		i;
	int		len;
	t_list	*start;

	i = 0;
	start = lst;
	len = list_len(start);
	str = malloc (sizeof (char *) * (len + 1));
	if (!str)
		return (NULL);
	lst = start;
	while (lst != NULL)
	{
		str[i] = ft_strdup(lst -> str);
		if (!str[i])
		{
			free_str(str);
			return (NULL);
		}
		++i;
		lst = lst -> next;
	}
	str[i] = (NULL);
	return (str);
}

void	free_str(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[count] != NULL)
		++count;
	while (i < count)
	{
		free (str[i]);
		++i;
	}
	free (str);
}

void	print_str(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[count] != NULL)
		++count;
	while (i < count)
	{
		printf("--- %s ---\n", str[i]);
		++i;
	}
	return ;
}


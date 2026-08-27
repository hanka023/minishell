/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/19 17:17:53 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "../minishell.h"

int	list_len(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst != NULL)
	{
		lst = (lst -> next);
		++len;
	}
	return (len);
}

char *copy_name_to_str(t_env *lst)
{
	char	*str;
	int		len;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	len = (ft_strlen(lst -> name) + ft_strlen(lst -> value) + 1);
	str = malloc(sizeof (char ) * (len + 1));
	if (!str)
		return (0);
	while ((lst->name) && (lst->name)[i] != '\0')
	{
		str[i] = (lst -> name)[i];
		++i;
	}
	str[i] = '=';
	++i;
	while ((lst -> value) && (lst -> value)[j] != '\0')
	{
		str[i + j] = (lst -> value)[j];
		++j;
	}
	str[i + j] = '\0';
	return(str);
}

char	**env_to_str(t_env *lst)
{
	char	**str;
	int		i;
	//int 	j;
	int		len;
	t_env	*start;

	str = NULL;
	i = 0;
//	j = 0;
	len = 0;
	start = lst;
	while (lst != NULL)
	{
		lst = (lst -> next);
		++len;
	}
	str = malloc (sizeof (char *) * (len + 1));
	if (!str)
		return (NULL);
	lst = start;
	while (lst != NULL)
	{
		str[i] = copy_name_to_str(lst);
		++i;
		lst = lst -> next;
	}
	str[i] = (NULL);
	return (str);
}

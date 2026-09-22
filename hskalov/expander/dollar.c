/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/22 23:04:43 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../../mini.h"
#include "parser.h"

int	ft_namelen(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	if (ft_isalpha(str[i]) == 0 && str[i] != '_')
		return (0);
	i++;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

int	expand_dollar(char *str, t_env *env, t_state *state, t_list **head_w)
{
	int	len;

	len = 0;
	if (*(str + 1) == '?')
		len = expand_status(str, state, head_w);
	else if (ft_isname(str + 1) == 1)
	{
		len = ft_namelen(str);
		expand_name(str, env, head_w);
	}
	else
	{
		len = strlen_word(str);
		if (len > 0)
			word_to_lst(str, head_w);
		else
			len = 1;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

int	expand_d_zero(char *str, t_env *env, t_state *state, t_list **head_w)
{
	int	len;

	len = 0;
	if (*(str + 1) == '?')
		len = expand_status(str, state, head_w);
	else if (ft_isname(str + 1) == 1)
	{
		len = ft_namelen(str);
		expand_name(str, env, head_w);
	}
	else
	{
		len = 1;
		word_to_lst("$", head_w);
	}
	if (len <= 0)
		len = 1;
	return (len);
}

int	expand_no_dollar(char *str, t_list **head_w)
{
	int	len;

	len = 0;
	len = strlen_word(str);
	if (len > 0)
		word_to_lst(str, head_w);
	else
		len = 1;
	return (len);
}

int	expand_no_d_zero(char *str, t_list **head_w)
{
	int	len;

	len = 0;
	len = strlen_zero(str);
	if (len > 0)
		zero_to_lst(str, head_w);
	else
		len = 1;
	return (len);
}

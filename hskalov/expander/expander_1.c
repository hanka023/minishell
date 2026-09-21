/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/09/21 21:07:02 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../../mini.h"
#include "parser.h"

int ft_isname (char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '$')
		++str;
	if (ft_isalpha(*str) == 0 && *str != '_')
		return (0);
	++str;
	while (*str && *str != '=')
	{
		if (ft_isalnum (*str) == 0 && *str != '_')
			return (0);
		++str;
	}
	return (1);
}

int	expand_status(char *str, t_state *state, t_list **head_w)
{
	char	*copy;
	char	*status_code;
	int		len;

	len = 0;
	copy = "";
	if (*str == '\"')
	{
		++str;
		++len;
	}
	if (*str == '$' && *(str + 1) == '?')
	{
		status_code = ft_itoa(state -> exit_code);
		if (!status_code)
			return (0);
		copy = ft_strdup(status_code);
		word_to_lst(copy, head_w);
		free (status_code);
		free (copy);
		return (len + 2);
	}
	return (0);
}

int	expand_name(char *str, t_env *env, t_list **head_w)
{
	char	*copy;
	char	*name;
	char	*env_value;
	int		len;

	len = 0;
	copy = "";
	if (*str == '\"')
		++str;
	if (*str == '$')
	{
		len = strlen_name(str);
		name = find_name(str, env);
		if (!name)
			return (0);
		env_value = find_env(name, env);
		copy = ft_strdup (env_value);
		word_to_lst(copy, head_w);
		free (name);
		free (copy);
		return (len);
	}
	return (0);
}

t_list	*two_lst(char *s, t_env *env, t_state *state)
{
	int		len;
	t_list	*head_w;
	char	*str;
	char	*start;

	if (!s)
        return (NULL);
	head_w = NULL;
	str = two_trim(s);
	if (!str)
        return (NULL);
	start = str;
	while (*str)
	{
		if (*str == '$' && *(str + 1) == '?')
			len = expand_status(str, state, &head_w);
		else if (*str == '$' && ft_isname(str) == 1)
			len = expand_name(str, env, &head_w);
		else
		{
			len = strlen_word(str);
			if (len > 0)
				word_to_lst(str, &head_w);
			else 
				len = 1;
		}
		str = str + len;
	}
	free(start);
	return (head_w);
}

t_list	*zero_lst(char *s, t_env *env, t_state *state)
{
	int		len;
	t_list	*head_w;
	char	*str;
	char	*start;

	head_w = NULL;
	str = two_trim(s);
	start = str;
	while (*str && *str != '\0' && *str != '\'' && *str != '\"')
	{
		if (*str == '$' && *(str + 1) == '?')
			len = expand_status(str, state, &head_w);
		else if (*str == '$' && (ft_isname(str) == 1))
			len = expand_name(str, env, &head_w);
		else
		{
			len = strlen_word_zero(str);
			zero_to_lst(str, &head_w);
		}
		str = str + len;
	}
	free(start);
	return (head_w);
}

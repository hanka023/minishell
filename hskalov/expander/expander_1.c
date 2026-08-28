/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 16:26:22 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../../mini.h"
#include "parser.h"

int	expand_status(char *str, t_state *state, t_list **head_w)
{
	char	*copy;
	char	*status_code;
	int		len;

	len = 0;
	copy = "";
	if (*str == '\"')
		++str;
	if (*str == '$')
	{
		status_code = ft_itoa(state -> exit_code);
		if (!status_code)
			return (0);
		copy = ft_strdup (status_code);
		word_to_lst(copy, head_w);
		free (status_code);
		free (copy);
		return (len);
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

	head_w = NULL;
	str = one_trim(s);
	start = str;
	while (*str && *str != '\0' && *str != '\"')
	{
		if (*str != '$')
		{
			len = strlen_word(str);
			word_to_lst(str, &head_w);
		}
		if (*str == '$' && *(str + 1) == '?')
			len = expand_status(str, state, &head_w);
		else if (*str == '$')
			len = expand_name(str, env, &head_w);
		str = str + len;
		if (*str == '\n')
			++str;
	}
	free(start);
	return (head_w);
}


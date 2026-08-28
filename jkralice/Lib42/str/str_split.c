/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:27:33 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/09 17:48:48 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str.h"

static inline
size_t	count_words(char *str, char del)
{
	size_t	i;
	size_t	count;
	char	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != del)
			word = 1;
		if (str[i] == del && word)
		{
			word = 0;
			count++;
		}
		i++;
	}
	if (word)
		count++;
	return (count);
}

char	**str_split(t_arena *arena, char *str, char c)
{
	char			**out;
	size_t			words;
	size_t			i;
	size_t			j;
	size_t			start;

	words = count_words(str, c);
	out = arena_push(arena, (words + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < words)
	{
		while (str[j] == c)
			j++;
		start = j;
		while (str[j] != c && str[j])
			j++;
		out[i] = str_sub(arena, str, start, j - start);
	}
	out[i] = NULL;
	return (out);
}

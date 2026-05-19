/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/05/12 17:27:27 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;
	char *start;
	

	count = 0;
	in_word = 0;
	
	start = str;
	while (*str)
	{
		
		if (*str == '\'')
			z1(str);
		if (*str == '\"' && *str != '\0')
		{
			++str;
			
			while (*str != '\"')
			{
				++str;
			}
			if (*str == '\"')
			{
				++str;
				++count;
				in_word = 0;
				//printf ("count druha zavorka %d\n",count);
			}
			else
				return (0);
		}
	
		
		// printf ("pocet slov uprostred %d\n", count);
		// printf ("string %s\n", str);
		// printf ("in_word %d\n", in_word);
		// printf ("c %c\n", c);


		if (*str != c && *str != '\''  && *str != '\n' && *str !='\t'  && *str != '\0')
		{
			if (in_word == 0)
			{
				
				in_word = 1;
				count++;
				//printf("druhy count >>> %d <<< \n", count);
			}
			//++str;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		++str;	
	}
	//printf ("pocet slov %d\n", count);
	return (count);
}

static int	world_len(const char *s, char c)
{
	int	len;
    

	len = 0;

    // while (*s == ' ' || *s == '\n' || *s =='\t')
    //     ++s;
    while (s[len] != '\0' && s[len] != c)
        ++len;
    return (len);
}

static int	world_len2(const char *s, char c)
{
	int	len;

	len = 0;
    while (s[len] != '\0' && s[len] != c  && s[len] != '\''  && s[len] != '\"' )
        ++len;
    return (len);
}

static void	free_split(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		++i;
	}
	free(result);
}

static int	copy_word(char **result, int i, const char *s, char c)
{
	int	j;
	int	len;
	char *str0;
	char *str;
	char *set;

	j = 0;
    set = " \n\t";
	str0 = ft_strtrim(s, set);
	str = spaces(str0, set);

	len = (world_len(str, c));
	result[i] = malloc(sizeof(char) * (len + 1));
	if (!result[i])
		return (0);
    
    while (j < len)
	{
		result[i][j] = s[j];
		j++;
	}
	result[i][len] = '\0';
	return (1);
}

static int	copy_word2(char **result, int i, const char *s, char c)
{
	int	j;
	int	len;

	j = 0;
    
	len = (world_len2(s, c));
	result[i] = malloc(sizeof(char) * (len + 1));
	if (!result[i])
		return (0);

    while (j < len)
	{
		result[i][j] = s[j];
		j++;
	}
	result[i][len] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int count;
	int copy;

	i = 0;
	count = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s || !words)
		return (NULL);
		
	while (*s && count > 0 )
	{
		if(*s == '\'')
		{
			++s;
			copy = copy_word2(words, i, s, '\'');
			if (!copy)
			{
				free_split(words, i);
				return (NULL);
			}
			--count;
			//printf ("%d\n", count);
			s = s + world_len(s, '\'');
			++i;
		}
		else if(*s == '\"')
		{
			++s;
			copy = copy_word2(words, i, s, '\"');
			//printf ("copy_word >>>>> %s\n", s);
			if (!copy)
			{
				free_split(words, i);
				return (NULL);
			}
			--count;
			//printf ("%d\n", count);
			//printf (">>>>>>>>>>>> >>>>> %s\n", s);
			s = s + world_len2(s, '\"');
			
			++i;
		}
		else if (*s != c && *s != '\'' && *s != '\"')
		{
			copy = copy_word(words, i, s, c);
			if (!copy)
			{
				free_split(words, i);
				return (NULL);
			}
			s = s + world_len(s, c);
			i++;
		}
		else
			s++;
	}
	words[i] = (NULL);
	return (words);
}
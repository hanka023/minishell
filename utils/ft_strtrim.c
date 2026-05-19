#include "../minishell.h"

static int	is_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}

char *spaces( char *str, char *set)
{
	size_t	start;
	size_t	i;
	char	*trimmed;
	int		space;
	int		len;

	space = 0;
	start = 0;
	i = 0;
	len = 0;

	while (str[start] != '\0')
	{
		if (is_in_set(str[start], set))
		{
			if (space == 0)
			{
				++start;
				++len;
				space = 1;
			}
			else if (space == 1)
			{
				++start;
			}
		}
		else 
		{		
			++start;
			++len;
			space = 0;
		}
	}
	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);

	start = 0;
	space = 0;
	
	while (str[start] != '\0')
	{
		if (is_in_set(str[start], set))
		{
			if (space == 0)
			{
				if (str[start] == '\n' || str[start] == '\t')
					trimmed[i] = ' ';
				else
					trimmed[i] = str[start];
				++start;
				++i;
				space = 1;
			}
			else if (space == 1)
			{
				++start;
			}
		}
		else 
		{
			space = 0;
			trimmed[i] = str[start];
			++i;
			++start;
		}
	}
	trimmed[i] = '\0';
	return (trimmed);
}
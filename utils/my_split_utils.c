#include "../minishell.h"

int is_in_set(char c, char *set)
{
	while (*set !='\0')
	{
		if (*set == c)
			return(1);
		set++;
	}
	return(0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while ((i < (n - 1)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}


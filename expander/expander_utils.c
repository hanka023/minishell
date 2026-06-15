

#include <string.h>
#include "parser.h"
#include "../minishell.h"




int my_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
		++len;
	return (len);
}


int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}

void check_last_qt(char *str)
{
	if (!str)
		return;
	while (*str != '\0')
	{
		if (*str == '"' && *(str + 1) == '\0')
			*str = '\0';
		++str;
	}
	return;
}
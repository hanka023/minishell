
#include <string.h>
#include "../minishell.h"
#include "parser.h"



char *copy_string_zero(char *str, char c)
{
	int		i;
	int		len;
	char	*copy;
	char 	*start;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c && str[len] != '\'' && str[len] != '\"')
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	start = copy;

	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (start);
}



char *copy_string(char *str, char c)
{
	int		i;
	int		len;
	char	*copy;
	char 	*start;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	start = copy;

	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (start);
}
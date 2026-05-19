
#include "../minishell.h"

char *z1(char *str)
{
	int count;
	// char *start;

	count = 0;
	++str;
	while (*str != '\'' && *str != '\0')
	{
		++str;
	}
	if (*str == '\'')
	{
		++str;
		++count;
		return (str);
	}
	else
		return (0);
	}

char *z2(char *str)
{
	int count;

	count = 0;
	++str;
			
	while (*str != '\"')
		++str;
			
	if (*str == '\"')
	{
		++str;
		++count;
		return (str);
				//printf ("count druha zavorka %d\n",count);
	}
	else
		return (0);
}
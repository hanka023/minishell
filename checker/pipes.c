
#include <string.h>
#include "../minishell.h"

int check_pipes(char *str)
{
	int pipe;
	int last;

	while (*str)
	{
		if (*str == '|' && pipe == 0)
			return (1);
		else if (*str == '|' && pipe == 1)
		{
			pipe = 0;
			last = 1;
			++str;
		}
		else if (ft_isalnum(*str) == 1)
		{
			pipe = 1;
			last = 0;
			++str;
		}
		else if ((*str == '<' || *str == '>') && last == 1)
			return(1);
		else
			++str;
	}
	return (last);
}
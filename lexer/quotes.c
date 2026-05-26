#include "../minishell.h"



int quotes(char *str)
{
	int len;

	if (*str == '\'')
		len = single_quote(str);
	else if (*str == '"')
		len = double_quotes(str);
	return(len);
}



int single_quote(char *str)
{
	int len;
	char *start;
	start = str;
	len = 0;
	++str;
	while (*str && *str != '\'')
		++str;
	if (*str == '\'')
		++str;
	len = str - start;
	return(len);
}

int double_quotes(char *str)
{
	int len;
	char *start;
	start = str;
	len = 0;
	++str;
	while (*str && *str != '\"')
		++str;
	if (*str == '\"')
		++str;
	len = str - start;
	return(len);
}



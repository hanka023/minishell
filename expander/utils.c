
#include <string.h>

#include "../minishell.h"
#include "parser.h"





char *find_$(char *str)  //hledam $USER 
{
	int stav;
	
	stav = 0;

	while (*str)
	{
		if ((*str == '\'') && stav == 0)
			stav = 1;
		else if (*str == '\'' && stav == 1)
			stav = 0;
		if (stav == 0 && *str == '$' && *(str + 1) != '\0')
			return (NULL);
		else
			++str;
	}
	return (str);
}



int expand_len(t_list *lst, t_env *env)
{
	char	*str;
	//char 	*copy;
	//char	*new_str;
	int		len;

	str = lst -> str;
	//len = expandlen(str);
	len = 0;

	while (*str)
	{
		while (*str != '$')
		{
			++str;
			++len;
		}
		if (*str == '$')
		{
			len = env_len(str, env);
			str = str + (len - 1);
		}
	}
	return (len);
}



int strlen_zero(char *str)
{
	int len;

	len = 0;
	while (*str && *str !='\'' && *str != '\"')
	{
		++str;
		++len;
	}
	return (len);
}





int strlen_one(char *str)
{

	int len;

	len = 0;
	if (*str == '\'')
	{
		++str;
		++len;
	}
	while (*str && *str != '\'')
	{
		++str;
		++len;
	}
		if (*str == '\'')
	{
		++str;
		++len;
	}
	return (len);
}





int strlen_two(char *str)
{

	int len;

	len = 0;
		if (*str == '\"')
	{
		++str;
		++len;
	}
	while (*str && *str != '\"')
	{
		++str;
		++len;
	}
		if (*str == '\"')
	{
		++str;
		++len;
	}
	return (len);
}



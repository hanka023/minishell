
#include <string.h>

#include "../minishell.h"
#include "parser.h"


char	*ft_strldup(const char *str, int len)

{
	int		i;
	char	*copy;

	i = 0;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (copy);
}


int strlen_name(char *str)
{
	int len;

	len = 0;
	if (*str == '$')
	{
		++str;
		++len;
	}
	while(*str && ( ft_isalnum(*str) || *str == '_'))
	{
		++str;
		++len;
	}
	return (len);
}

int test_name(char *str, t_env *env)
{
	char *name;
	size_t len;
	int cmp;
	char eq;

	if (*str == '$')
		++str;
	name = str;
	len = strlen_name (str);

	while(env != NULL)
	{
		cmp = ft_strncmp(name, env -> name, len);
		if (cmp == 0)
		{
			eq = env -> str[len];
			if (eq == '=')
				return(1);
		}
		env = env -> next;
	}
	return(0);
}

// int test_names(char *str, t_env *env)
// {
// 	int len;

// 	len = 0;
// 	while (*str)
// 	{
// 		if (*str == '$')
// 		{
// 			len = strlen_name (str);
// 			if(!test_name(str, env))
// 				return(0);
// 			str = str + len;
// 		}
// 		++str;
// 	}
// 	return(1);
// }


int test_names(char *str, t_env *env)
{
	int len;

	len = 0;
	
	while (*str)
	{
		if (*str == '$')
		{
			len = strlen_name (str);
			if(!test_name(str, env))
				return(0);
			str = str + len;
		}
		++str;
	}
	return(1);
}

char *find_name(char *str, t_env *env)
{
	char *start;
	char *start_name;
	char *name;
	int len;
	int test;

	test = 0;
	len = 0;
	if (*str == '$')
		++str;
	start = str;
	while(*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		++str;
		++len;
	}
	

	name = malloc (sizeof(char) * (len + 1));
	if (!name)
		return (NULL);
	start_name = name; 
	str = start;
	while(*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		*name = *str;
		++name;
		++str;
	}
	*name = '\0';
	name = start_name;
	test = test_name(name, env);
	if (!test)
	{
		printf (" test v test name KO :(\n");
		free(name);
		return (NULL);
	}
	return (name);
}

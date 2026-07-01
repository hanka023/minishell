
#include <string.h>
#include "checker.h"
#include "../minishell.h"



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
			{
				printf("jmeno nalezeno!!!\n");
				return(0);
			}
		}
		env = env -> next;
	}
	return(1);
}

int check_names(char *str, t_env *env)
{

	int stav;
	int test;

	stav = 0;
	test = 0;
	while(*str)
	{
		if (*str == '\'' && stav == 0)
			stav = 1;
		else if (*str == '\'' && stav == 1)
			stav = 0;
		else if (*str == '\"' && stav == 0)
			stav = 2;
		else if (*str == '\"' && stav == 2)
			stav = 0;
		if (*str == '$' && stav != 1)
			test = test_name(str, env);
		if (test == 1)
		{
			return(1);
			//printf("chyba name na vstupu\n");
		}
		++str;
	}
	//printf("name ok\n");
	return(0);
}
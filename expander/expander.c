

#include <string.h>
#include "parser.h"
#include "../minishell.h"

char *find_env(char *str, t_env *env)
{
	char *copy;
	char *set;

	if (!str)
	{
		perror("ve find_env neni str\n");
		return(NULL);
	}
	set = "\" $\n\t";
	copy = ft_strtrim(str, set);
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
		{	
			if (env -> str != NULL)
			free(copy);
			return (env -> value);
		}
		env = env -> next;
	}
	free(copy);
	return(NULL);
}



int find_$(char *str)  //hledam $USER 
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
			return (1);
		else
			++str;
	}
	return (0);
}




char *env_handler(t_list *lst)
{
	t_env *env;
	char *is_env;

	env = env_to_lst();
	is_env = NULL;
	is_env = find_env(lst -> str, env);  
	if (is_env != NULL)
	{
		free(lst ->str);
		lst -> str = ft_strdup(is_env);
	}
	return (is_env);
}

int expander(t_list *lst)  // *lst je hlavicka 
{
	char *name;
	char *is_env;
	int find; 


	name = NULL;
	find = 0;
	while (lst != NULL)
	{
		find = find_$(lst -> str); 
		if (find == 0)
			break;
		else if (find == 1)
		{
			is_env = env_handler(lst);
		}
		if(is_env == NULL)	
		 	return (-1);
		lst = lst -> next;
	}
	if(name)
		free(name);
	return(0);
}


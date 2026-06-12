

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

int my_strlen2(char **str)
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





// char *get_env(char *str)
// {
// 	t_env *env;
// 	char *argument;

// 	argument = NULL;
// 	env = env_to_lst();
// 	while (env != NULL)
// 	{
// 		if (ft_strcmp (str, env -> name) != 0)
// 		env = env -> next;
// 	}
// 	return(argument);
// }




// int find_env(char *str, t_env *env)
// {

// 	while (env != NULL)
// 	{
// 		if (ft_strcmp (str, env -> name) == 0)
// 		{
// 			return (1);
// 		}
// 		env = env -> next;
// 	}
// 	return(0);
// }

char *find_env(char *str, t_env *env)
{
	char *copy;
	char *set;

	set = "\"";
	copy = ft_strtrim(str, set);

	printf ("char *copy ve find_env %s \n", copy);

	while (env != NULL)
	{
		if (ft_strcmp (str, env -> name) == 0)
		{
			
			return (env -> value);
		}
		env = env -> next;
	}
	return(NULL);
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


int expander(t_list *lst)  // *lst je hlavicka 
{
	char *name;
	t_env *env;

	env = env_to_lst();
	name = NULL;


	int find; 
	char *is_env;

	find = 0;
	is_env = NULL;

	while (lst != NULL)
	{
		printf ("lst -> str %s \n", lst -> str);

		find = find_$(lst -> str); 
		if (find == 0)
			break;

		else if (find == 1)
			is_env = find_env(name, env);  
		if(is_env == NULL)	
		 	return (-1);
	
		lst = lst -> next;
	}
	if(name)
		free(name);
	return(0);
}




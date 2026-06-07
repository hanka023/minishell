

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






char *find_env(char *str, t_env *env)
{

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

char *find_$(char *str)  //hledam $USER 
{
	char *copy;
	int stav;
	
	stav = 0;

	while (*str)
	{
		if ((*str == '\'') && stav == 0)
			stav = 1;
		else if (*str == '\'' && stav == 1)
			stav = 0;
		if (stav == 0 && *str == '$' && *(str + 1) != '\0')
		{	
			++str;
			copy = ft_strdup (str); 
			if (!copy)
				return (NULL); //copy = USER (napr)
			check_last_qt(copy); //cut last " 
			return (copy);
		}
		else
			++str;
	}
	return (NULL);
}


void expander(t_list *lst)  // *lst je hlavicka 
{
	char *name;
	char *value;
	t_env *env;

	env = env_to_lst();
	name = NULL;


	while (lst != NULL)
	{
		if (find_$ (lst -> str) != NULL)
		{
			name = find_$(lst -> str);  // *char USER
			if (!name)
				return;
			//printf ("name %s\n", name);	
			value = find_env(name, env);  
			free (lst -> str);
			lst -> str = ft_strdup(value);
			//printf ("value %s\n", value);
		}
		lst = lst -> next;
	}
	if(name)
		free(name);
	return;
}




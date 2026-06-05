
#include "../minishell.h"
#include <string.h>


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
	
 //print_env(env);
	printf ("find env jede - hlredam  %s\n",  str);
	while (env != NULL)

	{
		//printf ("str %s\n", env -> str);
		//printf ("name  %s\n", env -> name);
		//printf ("value  %s\n", env -> value);

		if (ft_strcmp (str, env -> name) == 0)
		{
			printf ("strcmp jede  %s\n", env -> value);
			//return (env -> value);
			printf ("value  %s\n", env -> value);
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

char *check_str(char *str)  //hledam $USER 
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
			check_last_qt(copy);
			return (copy);
		}
		++str;
	}
	return (NULL);
}


void expander(t_list *lst)  // *lst je hlavicka 
{
	char *name;
	t_env *environ_head;

	environ_head = env_to_lst();

	//print_env(environ_head);

	while (lst != NULL)
	{
		if (check_str (lst -> str) != NULL)
		{
			name = check_str(lst -> str);  // *char USER
			if (!name)
				return;
			printf ("name %s\n", name);	
			name = find_env(name, environ_head);
			printf ("name %s\n", name);
		}
		lst = lst -> next;
	}
	free(name);
	return;
}




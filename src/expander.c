
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

char *f_strdup(char *str)
{
	int i;
	int len;
	char *copy;
	
	i = 0;
	len = 0;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return(0);
	while (i < len)
	{
		copy[i] = str [i];
		++i;
	}
	copy[len] = '\0';
	return (copy);
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
char *get_env(char *str)
{
	
	t_env *env;
	char *argument;

	//str = NULL;
	argument = NULL;
	env = env_to_lst();
// printf (".......get env jede.......\n");

// printf (".....*str ..%s.......\n",str);
//printf (".....value ..%s.......\n",env -> value);
	while (env != NULL)
	{

		//printf ("......while jede.......\n");
		if (ft_strcmp (str, env -> name) != 0)
			//printf (".......%s.......\n",env -> value);
		env = env -> next;
		
	}

	return(argument);
}


void check_str (char *str)
{
	char *copy;
	int stav;

	// copy = NULL;
	stav = 0;
	while (*str)
	{
		if (*str == '"' && stav == 0)
			stav = 1;
		else if (*str == '"' && stav == 1)
			stav = 0;
		else if (stav == 1 && *str == '$' && *(str +1) != '\0')
		{	
			++str;
			copy = get_env(str);
			printf ("copy v expander......... %s\n", copy);
			break;
		}
		++str;
	}
	return;
}


void expander(t_list *lst)  // *lst je hlavicka 
{
	char *str;
	
	str = NULL;
	//copy = NULL;
	while (lst != NULL)
	{

		str = lst -> str;
		check_str (str);
		lst = lst -> next;
		//printf("expander lst -----%s \n", lst -> str);
	
	}
	//printf("expander: str co posilam z input -----%s \n", str);

	return;
}
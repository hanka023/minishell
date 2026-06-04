#include "parser.h"


t_env *env_to_lst()
{
	//int i;
	t_env *head;
	t_env *env;
	extern char **environ;
	char **copy_environ = environ;

	head = NULL;
	//env = NULL;
	printf ("......en to lst jede......\n");


	while(*copy_environ)
	{
		printf ("......while jede......\n");
		env = new_env(*copy_environ);
		printf ("......env %s......\n", env -> str);
		// env_add_back(&head, env); 
		++copy_environ;
	}
	return(head);
}

void env_name(char *str, t_env *env)
{
	

	char *name;
	
	int len; 

	len = 0;

	name  = str;
	printf ("  ....env_name jede ....\n");

	while (name[len] != '=' && name[len] != '\0')
		++len;
	if (len == 0)
	{
		env -> name = NULL;
		return;
	}
	name[len] = '\0';

	env -> name = ft_strdup(name);

	printf ("  ....env_name: %s....\n", name);
	if (len == 0)
		env -> name = NULL;

	return;
}



void env_value(char *str, t_env *env)
{
	int stav;
	
	stav = 0;
	while (*str)
	{
		if ((*str) == '=')
			stav = 1;
		++str;
	}
	if (stav == 1)
	{
		printf ("env_value - kontrola znaku \n");
		env -> value = ft_strdup(str);
	}
	else
		env -> value = NULL;
	return;
} 


t_env *new_env(char *str)
{
	t_env *env;
	env = malloc (sizeof (t_env));
	if (!env)
		return (NULL);
	env -> str = ft_strdup(str);
	if (!env -> str)
	{
		free(env);
		return (NULL);
	}
	env_name (str, env);

	env -> next = NULL;
	return (env);
} 



void	env_add_back(t_env **head, t_env *env)
{
	t_env *tmp;

	if (!head || !env)
		return;
	if (*head == NULL)
	{
		*head = env;
		return;
	}
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = env;
	return;
}

void print_env(t_env **env)
{
	t_env *print;

 	print = *env;

    while (print != NULL)
    {
      	printf("%s\n", print -> str);
	   	print = print -> next;
    }
	return;
}

void free_env(t_env *env)
{
	t_env *free_env ;

	while (env != NULL)
	{
		free_env = (env) -> next;
		free(env);
		env = free_env;
	}
	return;
}
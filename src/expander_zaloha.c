// #include "../minishell.h"


// // char *read_env(char *str)
// // {
// // 	char user;

// // 	user = getenv("USER");
// // 	if (!s)
// // 		return (NULL);
// // 	return (s);
// // }


// void expand(char *string)
// {

// 	char *str;
// 	char *new_str;
// 	char *s;
// 	int stav;
	
// 	str = NULL;
// 	new_str = NULL;
// 	*s = NULL;
// 	stav = 0;
	

// 	while (*string)
// 	{
// 		if (*string == '$')
// 		{
// 			*s = *string;
// 			break;
// 		}
// 		++string;	
// 	}
// 	new_str = 
// }


// void expander(t_list *lst)
// {
	
// 	while (lst != NULL)
// 	{
// 		expand(lst -> str);
// 		lst = lst -> next;
// 	}
// 	return;
// }




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

char *my_strdup(char *str)
{
	int len;
	char *copy;
	char *start;
	
	len = ft_strlen(str);
	copy = malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	start = copy;

	while (*str)
	{
		*copy = *str;
		++copy;
		++str;
	}
	*copy = '\0';
	return (start);
}


char *print_env(char *str, char **environ)
{
	printf("print_env .........\nstr %s\n env %s\n", str, *environ);
	while (*str == **environ && **environ != '=')
	{
		++str;
		++*environ;
		if (**environ == '=')
		{
			++*environ;
			printf("%s\n", *environ);
			return (*environ);
		}
	}
	return (NULL);
}


char *get_env(char *str)
{
	extern char **environ;
	
	char *new_env;
	char *value;
	t_list *env;
	t_list *lst;
	int len; 

	len = 0;
	env = NULL;
	
	printf ("pocet radku v environ: %d\n %s\n", len, str);

	value = NULL;
	
	while(*environ)
	{
		//printf ("environ:  %s\n", *environ);

		lst = new_list(*environ);
		add_back(&env, lst);
		++environ;
	}
	print_list(&env);

	printf("copy_env ------ %s\n", value);
	new_env = my_strdup (value);
	return(new_env);
}

void expander(t_list *lst)
{
	char *str;
	char *copy;
	//char **copy_env;
	int stav;
	
	str = NULL;
	copy = NULL;
	str = lst -> str;
	stav = 0;

	while (*str)
	{
		if (*str == '"' && stav == 0)
			stav = 1;
		else if (*str == '"' && stav == 1)
			stav = 0;
		else if (stav == 1 && *str == '$' && *(str +1) != '\0')
		{	
			copy = get_env(str);
			printf ("copy......... %s\n", copy);
			break;
		}
		++str;
	}
	return;
}
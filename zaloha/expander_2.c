

#include <string.h>
#include "parser.h"
#include "../minishell.h"

// char *find_env(char *str, t_env *env)
// {
// 	char *copy;
// 	char *set;

// 	if (!str)
// 	{
// 		perror("ve find_env neni str\n");
// 		return(NULL);
// 	}
// 	set = "\" $\n\t";
// 	copy = ft_strtrim(str, set);
// 	while (env != NULL)
// 	{
// 		if (ft_strcmp (copy, env -> name) == 0)
// 		{	
// 			if (env -> str != NULL)
// 			free(copy);
// 			return (env -> value);
// 		}
// 		env = env -> next;
// 	}
// 	free(copy);
// 	return(NULL);
// }



// int find_$(char *str)  //hledam $USER 
// {
// 	int stav;
	
// 	stav = 0;

// 	while (*str)
// 	{
// 		if ((*str == '\'') && stav == 0)
// 			stav = 1;
// 		else if (*str == '\'' && stav == 1)
// 			stav = 0;
// 		if (stav == 0 && *str == '$' && *(str + 1) != '\0')
// 			return (1);
// 		else
// 			++str;
// 	}
// 	return (0);
// }


// char *env_handler(t_list *lst)
// {
// 	t_env *env;
// 	char *is_env;

// 	env = env_to_lst();
// 	is_env = NULL;
// 	is_env = find_env(lst -> str, env);  
// 	if (is_env != NULL)
// 	{
// 		free(lst ->str);
// 		lst -> str = ft_strdup(is_env);
// 	}
// 	return (is_env);
// }

// int expander(t_list *lst)  // *lst je hlavicka 
// {
// 	char *name;
// 	char *is_env;
// 	int find; 

// 	name = NULL;
// 	find = 0;
// 	while (lst != NULL)
// 	{
// 		find = find_$(lst -> str); 
// 		if (find == 0)
// 			break;
// 		else if (find == 1)
// 		{
// 			is_env = env_handler(lst);
// 		}
// 		if(is_env == NULL)	
// 		 	return (-1);
// 		lst = lst -> next;
// 	}
// 	if(name)
// 		free(name);
// 	return(0);
// }


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

// int expandlen(char *str)
// {
// 	int len = 0;
// 	char *copy;
// 	char *start;
	
// 	copy = NULL;
// 	start = copy;
// 	while (*str)
// 	{
// 		while (*str != '$')
// 			++len;
// 		if (*str == '$')
// 		{
// 			++str;
// 			++len; 
// 			while (*str == ft_isalpha || *str == '_')
// 			{
// 				++cop
// 			}

// 		}
// 	}
// }


char env_cmp(char *copy, t_env *env)
{
	int len;

	len = 0;
	while (env != NULL)
	{
		if (ft_strcmp (copy, env -> name) == 0)
			len = ft_strlen(env -> value);
		env = env -> next;
	}
	free(copy);
	return(len);
}


int env_len(char *str, t_env *env)
{
	char *copy;
	char *start;
	//char *set;
	int len;

	if (!str || *str != '$')
	{
		perror("ve find_env neni str\n");
		return(0);
	}
	++str;
	start = str;
	while (*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		*copy = *str;
		++copy;
		++str;
	}
	copy = '\0';
	copy = start;
	len = env_cmp(copy, env);
	return(len);
}


char *copy_env(char *str, t_env *env)
{
	char *copy;
	char *start;
	//char *set;
	//int 	len;
	char *env_value;

	if (!str || *str != '$')
	{
		perror("ve find_env neni str\n");
		return(NULL);
	}
	else if (*str == '$')
		++str;
	start = str;
	while (*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		*copy = *str;
		++copy;
		++str;
	}
	copy = '\0';
	copy = start;
	env_value = find_env(copy, env);
	return(env_value);
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
char *expand_str(t_list *lst, t_env *env)
{
	char	*str;
	//char 	*copy;
	char	*new_str;
	char	*env_value;
	int		len;

	str = lst -> str;
	len = expand_len(lst, env);
	new_str = malloc (sizeof (char) * (len + 1));
	while (*str)
	{
		while (*str != '$')
		{
			*new_str = *str;
			++str;
			++new_str;
		}
		if (*str == '$')
		{
			len = env_len(str, env);
			str = str + (len - 1);
			env_value = copy_env(str, env);
			////zkopirovat env_value do str 
		}
	}
	return (env_value);//opravit
}


int expander(t_list *lst)  // *lst je hlavicka 
{
	char *find; 
	char *new_lst;
	int len;
	t_env	*env;

	env_to_lst(env);
	find = 0;
	len = 0;
	while (lst != NULL)
	{
		find = find_$(lst -> str); 
		if (find != NULL)
		{
				len = expand_len(lst, env);
				//new_lst = malloc (sizeof (char) * (len + 1));
		}
		
		lst = lst -> next;
	}
	return(0);
}

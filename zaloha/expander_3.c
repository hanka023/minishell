

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
// char *expand_str(t_list *lst, t_env *env)
// {
// 	char	*str;
// 	//char 	*copy;
// 	char	*new_str;
// 	char	*env_value;
// 	int		len;

// 	str = lst -> str;
// 	len = expand_len(lst, env);
// 	new_str = malloc (sizeof (char) * (len + 1));
// 	while (*str)
// 	{
// 		while (*str != '$')
// 		{
// 			*new_str = *str;
// 			++str;
// 			++new_str;
// 		}
// 		if (*str == '$')
// 		{
// 			len = env_len(str, env);
// 			str = str + (len - 1);
// 			env_value = copy_env(str, env);
// 			////zkopirovat env_value do str 
// 		}
// 	}
// 	return (env_value);//opravit
// }



// char expand_lst(t_list *lst)
// {
// 	char *find; 
// 	char *new_lst;
// 	int len;
// 	t_env	*env;

// 	env_to_lst(env);
// 	find = 0;
// 	len = 0;

// 	find = find_$(lst -> str); 
// 	if (find != NULL)
// 	{
// 		len = expand_len(lst, env);
// 		//new_lst = malloc (sizeof (char) * (len + 1));
// 	}
	
// 	return(0);

// }



int strlen_zero(char *str)
{
	int len;

	len = 0;
	while (*str && *str !='\'' && *str != '\"')
	{
		++str;
		++len;
	}
	//printf ("len ve strlen zero >>>>>>>>>>>>>>>>%d<<<<<<<<<<<<<<<<<\n", len);
	return (len);
}

int strlen_one(char *str)
{

	int len;

	len = 0;
	while (*str && *str != '\'')
	{
		++str;
		++len;
	}
	return (len);
}

int strlen_two(char *str)
{

	int len;

	len = 0;
	while (*str && *str != '\"')
	{
		++str;
		++len;
	}
	return (len);
}

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


int strlen_name(char *str)
{
	int len;

	len = 0;
//	printf ("strlen_name jedeee!!!!!!! >>>%c<<<\n", *str);
	if (*str == '$')
	{
		//printf ("strlen_name $$$$$$$ .....>>>> %c\n", *str);
		++str;
		++len;
	}
	while(*str && ( ft_isalnum(*str) || *str == '_'))
	{
	//	printf ("strlen_name len %c\n", *str);
		++str;
		++len;
	}
	return (len);
	//printf ("strlen_name len %d\n", len);
}

char *find_name(char *str)
{
	char *start;
	char *name;
	int len;

	if (*str == '$')
		++str;
	name = str; ////potrebuju???
	start = name;
	len = strlen_name(name);
	name = malloc (sizeof(char) * len + 1);
	while(*str == ft_isalnum(*str) || *str == '_')
	{
		*name = *str;
		++name;
		++str;
	}
	name = '\0';
	//printf ("start ve find name %s\n", start);
	return (start);
}


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


char *copy_string(char *str, char c)
{
	int		i;
	int		len;
	char	*copy;
	char 	*start;

	len = 0;
	i = 0;

//	printf ("*str v copy_string %c\n", *str);
	while (str[len] && str[len] != c)
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	start = copy;

	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
//	printf ("start v copy_string %s\n", start);
	return (start);
}

char *zero_handler(char *str, t_env *env)
{
	int len;
	char *copy;
	char *name;
	char *env_value;
	char *tmp;
	char *final;
	//int env_len;
	//char *start;

	len = 0;
	final = "";
	copy = NULL;
	env_value = NULL;
	
	while (*str && *str != '\'' && *str != '\"' )
	{
		if (*str != '$')
		{
//			printf ("*str v zero handler - - - - - %c - - - - -  -\n", *str);
			copy = copy_string(str, '$');

			len = ft_strlen(copy);
//			printf("\ncopy string *****%s******  strlen *****%d******\n\n", copy, len );
			str = str + len;
		}
		else if (*str == '$')
		{
			
			name = find_name (str);
			//printf ("name:-> -> ->  %s <- <= <- \n", name);
			len = strlen_name(str);
			//printf ("name v zero handler >>>%s<<< len: %d\n", name, len);
			env_value = find_env(name, env);

			//env_len = ft_strlen(env_value);
		//	printf (" env value >>>%s<<<  env_len: %d\n", env_value, env_len);
			copy = ft_strdup (env_value);
			//printf ("len %d\n", len);
			str = str + len;
		}
		tmp = final;

		//printf ("copy  =======%s====== tmp ======%s======= \n", copy, tmp);
		final = ft_strjoin(tmp, copy);
		//printf ("zero handler ----za strjoin %s \n", final);
		free(copy);
	}
	//printf ("zero handler %s \n", final);
	return (final);
}

char *one_handler(char *str)
{
	int len;
	char *copy;

	len = 0;
	len = strlen_one(str);
	copy = ft_strldup(str, len);
	str = str + len;
	return (copy);
}
 char *two_handler(char *str)
 {
	int len;
	char *copy;

	len = strlen_one(str);
	copy = ft_strldup(str, len);
	str = str + len;
	return (copy);
 }

char *expand_lst(t_list *lst, t_env *env)
{
	char *str;
	char *copy;
	char *final;
//	char *start;
	char *tmp;
	int len;

	str = lst -> str;
	//makstart = "";
	final = NULL;
	len = 0;
	tmp = "";
	while (*str)
	{	

//		printf ("while v expand_lst jede\n");

		if (*str != '\'' && *str != '\"')
		{
			copy = zero_handler(str, env);
//			printf ("----- *copy>>>>>>%s<<<<<<<\n", copy);
			len = strlen_zero(str);
//			printf ("-----strlen zero >>>>>>%d<<<<<<<\n", len);
		}
		else if (*str == '\'')
		{
			copy = one_handler(str);
			len = strlen_one(str);
		}	
		else if (*str == '\"')
		{
			copy = two_handler(str);
			len = strlen_two(str);
		}
		str = str + len;
	
		if (final)
		{
			tmp = ft_strjoin(final, copy);
			free(final);
			final = ft_strdup (tmp);
			free(tmp);
		}
		else 
			final = ft_strdup (copy);
		free(copy);
	
	}
	return(final);
}


int expander(t_list *lst)  // *lst je hlavicka 
{


	//printf ("test %s \n", lst ->str);

	t_env *env;

	env = env_to_lst();
	if (!lst)
		return (0);
	char *new_lst;
	while (lst != NULL)
	{
		new_lst = expand_lst(lst, env);
		// ("while v expander %s \n", new_lst);
		free(lst -> str);
		lst -> str = ft_strdup(new_lst);
	//	free(new_lst);
		lst = lst -> next;
	}
	return(0);
}




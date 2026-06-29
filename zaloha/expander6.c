

#include <string.h>

#include "../minishell.h"
#include "parser.h"




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





int strlen_zero(char *str)
{
	int len;

	len = 0;
	while (*str && *str !='\'' && *str != '\"')
	{
		++str;
		++len;
	}
	return (len);
}

int strlen_one(char *str)
{

	int len;

	len = 0;
	if (*str == '\'')
	{
		++str;
		++len;
	}
	while (*str && *str != '\'')
	{
		++str;
		++len;
	}
		if (*str == '\'')
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
		if (*str == '\"')
	{
		++str;
		++len;
	}
	while (*str && *str != '\"')
	{
		++str;
		++len;
	}
		if (*str == '\"')
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
	if (*str == '$')
	{
		++str;
		++len;
	}
	while(*str && ( ft_isalnum(*str) || *str == '_'))
	{
		++str;
		++len;
	}
	return (len);
}

int test_name(char *str, t_env *env);

char *find_name(char *str, t_env *env)
{
	char *start;
	char *start_name;
	char *name;
	int len;
	int test;

	test = 0;
	len = 0;
	if (*str == '$')
		++str;
	start = str;
	while(*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		++str;
		++len;
	}
	
	// if (*str && (ft_isalnum(*str) == 0 && *str != '_' && *str !=' '))
	// {
	// 	printf(" find name - test >>>>>>%C<<<<<<\n", *str);
	// 	return(NULL);
	// }

	name = malloc (sizeof(char) * (len + 1));
	if (!name)
		return (NULL);
	start_name = name; 
	str = start;
	while(*str && (ft_isalnum(*str) == 1 || *str == '_'))
	{
		*name = *str;
		++name;
		++str;
	}
	*name = '\0';
	name = start_name;
	test = test_name(name, env);
	if (!test)
	{
		printf (" test v test name KO :(\n");
		free(name);
		return (NULL);
	}
	return (name);
}

int test_name(char *str, t_env *env)
{
	char *name;
	size_t len;
	int cmp;
	char eq;

	if (*str == '$')
		++str;
	name = str;
	len = ft_strlen (str);


	printf ("\nstr v test name ++++++----->>>>>>%s<<<<<<<-----++++++\n \n", str);
//	return(0);////vymazat po testech

	while(env != NULL)
	{
		cmp = ft_strncmp(name, env -> name, len);
		if (cmp == 0)
		{
			eq = env -> str[len];
			if (eq == '=')
				return(1);
		}
		env = env -> next;
	}
	return(0);
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

char *copy_string_zero(char *str, char c)
{
	int		i;
	int		len;
	char	*copy;
	char 	*start;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c && str[len] != '\'' && str[len] != '\"')
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
	return (start);
}

char *copy_string(char *str, char c)
{
	int		i;
	int		len;
	char	*copy;
	char 	*start;

	len = 0;
	i = 0;
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

	final = "";
	while (*str && *str != '\'' && *str != '\"' )
	{
		if (*str != '$')
		{
			copy = copy_string_zero(str, '$');
			len = ft_strlen(copy);
			str = str + len;
		}
		else if (*str == '$')
		{
			name = find_name (str, env);
			if (!name)
				return (NULL);
			len = strlen_name(str);
			env_value = find_env(name, env);
			copy = ft_strdup (env_value);
			str = str + len;
		}
		tmp = final;
		final = ft_strjoin(tmp, copy);
		free(copy);
	}
	return (final);
}

char *one_handler(char *str)
{
	char *copy;
	char *start;

	if (*str == '\'')
		++str;
	copy = copy_string (str, '\'');
	start = copy;
	if (*copy == '\'')
		*copy = '\0';
	return (start);
}



//  char *two_handler_zaloha(char *str,  t_env *env)
//  {
// 	int len;
// 	char *copy;
// 	char *name;
// 	char *env_value;
// 	char *tmp;
// 	char *final;

// 	final = "";
// 	if (*str =='\"')
// 		++str;
// 	while (*str && *str != '\"' )
// 	{
// 		if (*str != '$')
// 		{
// 			copy = copy_string(str, '$');
// 			len = ft_strlen(copy);
// 			str = str + len;
// 		}
// 		else if (*str == '$')
// 		{
// 			name = find_name (str, env);

// 			printf ("\n name v two handler >>>>>>>%s<<<<<<<<<<<<\n\n", name ),
// 			len = strlen_name(str);
// 			env_value = find_env(name, env);
// 			copy = ft_strdup (env_value);
// 			str = str + len;
// 		}
// 		tmp = final;
// 		final = ft_strjoin(tmp, copy);
// 		free(copy);
// 	}
// 	//printf ("final v two handler -----------------%c-------------\n", final[len - 1]);
// 	if (final[len -1] == '\"')
// 		(final[len - 1] ='\0');
// 	return (final);
//  }


/************************************************* 
 
 char *two_h_no_dollar(char *str, t_env *env)
 {
	
 }


****************************************** */



 char *expand_name(char *str,  t_env *env)
 {
	//int len;
	char *copy;
	char *name;
	char *env_value;
	

	copy = "";
	if (*str =='\"')
		++str;

	if (*str == '$')
	{
		name = find_name (str, env);
		if(!name)
			return(NULL);
		env_value = find_env(name, env);
		copy = ft_strdup (env_value);
		
	}
	else 
		return(NULL);

	printf ("\nfinal str v dollar expander -------->>>%s<<<-------------\n\n", copy);
	
	return (copy);
 }



// char *two_handler(char *str,  t_env *env)
// {
// 	int len;
// 	char *copy;
// 	char *name;
// 	char *env_value;
// 	char *tmp;
// 	char *final;

// 	final = "";
// 	if (*str =='\"')
// 		++str;
// 	while (*str != '\"')
// 		++len;
// 	while (*str && *str != '\"')
// 	{
// 		if (*str != '$')
// 		{
// 			copy = copy_string(str, '$');
// 			len = ft_strlen(copy);
// 			str = str + len;
// 		}
// 		else if (*str == '$')
// 		{
// 			name = find_name (str, env);

// 			printf ("\n name v two handler >>>>>>>%s<<<<<<<<<<<<\n\n", name ),
// 			len = strlen_name(str);
// 			env_value = find_env(name, env);
// 			copy = ft_strdup (env_value);
// 			str = str + len;
// 		}
// 		tmp = final;
// 		final = ft_strjoin(tmp, copy);
// 		free(copy);
// 	}
// 	//printf ("final v two handler -----------------%c-------------\n", final[len - 1]);
// 	if (final[len -1] == '\"')
// 		(final[len - 1] ='\0');
// 	return (final);
//  }





// int word_to_lst(char *str, t_list *head_w)
// {

// 	t_list *lst;
// 	char *copy;
// 	int len;

// 	len = 0;
// 	while (str[len] != '$' && str[len] != '\0' && str[len] !='\"')
// 		++len;
// 	copy = malloc (sizeof (char) *(len + 1));
// 	if (!copy)
// 		return (0);
// 	while(*str != '$' && *str != '\0' && *str !='\"')
// 	{
// 		*copy = *str;
// 		++copy;
// 		++str;
// 	}
// 	copy = '\0';
// 	head_w = NULL;
// 	lst= NULL;
// 	lst = new_list(copy);
// 	free(copy);
// 	add_back(&head_w, lst); ///??? head nebo &head ???
// 	len = ft_strlen(lst -> str);
// 	return(len);
// }

t_list *two_lst(char *str,  t_env *env)
{
	int len;
	char *name;
	//t_list *word;
	t_list *head_w;

	head_w = NULL;
	if (*str =='\"')
		++str;
	while (*str && *str != '\"')
	{
		if (*str != '$')
			word_to_lst(str, &head_w);



		else if (*str == '$')
		{
			name = expand_name(str, env); ///narvat do lst
			len = strlen_name(str);
			word_to_lst(name, &head_w);
		}
		str = str + len;
	}
	return (head_w);
 }
char *two_handler(char *str, t_env *env)
{
	t_list *two;
	char *copy;
	char *tmp;

	copy = "";
	two = two_lst(str, env);

	while(two != NULL)
	{
		str = (two -> str);
		tmp = ft_strjoin (copy, str);
		free(copy);
		copy = ft_strdup(tmp);
		free(tmp);

	}
	return (copy);
}

char *expand_lst(t_list *lst, t_env *env)
{
	char *str;
	char *copy;
	char *new_copy;
	char *tmp;
	int len;

	str = lst -> str;
	new_copy = "";
	tmp = "";
	while (*str)
	{	
		if (*str != '\'' && *str != '\"')
		{
			copy = zero_handler(str, env);
			len = strlen_zero(str); //du po mezeru
		}
		else if (*str == '\'')
		{
			copy = one_handler(str);
			len = strlen_one(str);  //du po '
		}	
		else if (*str == '\"' )
		{
			copy = two_handler(str, env);
			len = strlen_two(str);  //;du po " 
		}
		str = str + len;

		tmp = ft_strjoin (new_copy, copy);
		new_copy = NULL;
		new_copy = ft_strdup(tmp);
		free(tmp);
		free(copy);
	}
	return(new_copy);
}


int expander(t_list *lst, t_env *env) 
{

	if (!lst)
		return (0);
	char *new_lst;


	while (lst != NULL)
	{

		new_lst = expand_lst(lst, env);
		if (!new_lst)
		{
			return(1); ////chyba napr $picovina
		}
		free(lst -> str);
		lst -> str = ft_strdup(new_lst);
		free(new_lst);
		lst = lst -> next;
	}
	return(0);
}




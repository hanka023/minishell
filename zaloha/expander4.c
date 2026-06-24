

#include <string.h>
#include "parser.h"
#include "../minishell.h"






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

char *find_name(char *str)
{
	char *start;
	char *name;
	int len;

	if (*str == '$')
		++str;
	name = str;
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
			copy = copy_string(str, '$');
			len = ft_strlen(copy);
			str = str + len;
		}
		else if (*str == '$')
		{
			name = find_name (str);
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



 char *two_handler(char *str,  t_env *env)
 {
	int len;
	char *copy;
	char *name;
	char *env_value;
	char *tmp;
	char *final;

	final = "";
	if (*str =='\"')
		++str;
	while (*str && *str != '\"' )
	{
		if (*str != '$')
		{
			copy = copy_string(str, '$');
			len = ft_strlen(copy);
			str = str + len;
		}
		else if (*str == '$')
		{
			name = find_name (str);
			len = strlen_name(str);
			env_value = find_env(name, env);
			copy = ft_strdup (env_value);
			str = str + len;
		}
		tmp = final;
		final = ft_strjoin(tmp, copy);
		free(copy);
	}
	if (*final == '\"')
		(*final ='\0');
	return (final);
 }

char *expand_lst(t_list *lst, t_env *env)
{
	char *str;
	char *copy;
	char *final;
	char *tmp;
	int len;
	char *new_copy;

	str = lst -> str;
	final = NULL;
	len = 0;
	tmp = "";
	while (*str)
	{	
		if (*str != '\'' && *str != '\"')
		{
			copy = zero_handler(str, env);
			len = strlen_zero(str);
			printf ("copy: --->>>%s<<<--- len: ---->>>%d<<<----\n", copy, len);
		}
		else if (*str == '\'')
		{
			copy = one_handler(str);
			len = strlen_one(str);
			printf ("copy: --->>>%s<<<--- len: ---->>>%d<<<----\n", copy, len);
		}	
		else if (*str == '\"')
		{
			copy = two_handler(str, env);
			len = strlen_two(str);
			printf ("copy: --->>>%s<<<--- len: ---->>>%d<<<----\n", copy, len);
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
		//free(copy);
	
	}
	return(final);
}


int expander(t_list *lst) 
{
	t_env *env;

	env = env_to_lst();
	if (!lst)
		return (0);
	char *new_lst;
	while (lst != NULL)
	{
		new_lst = expand_lst(lst, env);
		free(lst -> str);
		lst -> str = ft_strdup(new_lst);
		lst = lst -> next;
	}
	return(0);
}






#include <string.h>

#include "../minishell.h"
#include "parser.h"


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
		name = find_name(str, env);
		if(!name)
			return(NULL);
		env_value = find_env(name, env);
		copy = ft_strdup (env_value);
		free(name);
	}
	else 
		return(NULL);
	return (copy);
 }


t_list *two_lst(char *str,  t_env *env)
{
	int		len;
	char	*name;
	t_list *head_w;

	head_w = NULL;
	if (*str =='\"')
		++str;
	while (*str && *str != '\0' && *str != '\"')
	{
		if (*str != '$')
		{
			len = strlen_word(str);
			word_to_lst(str, &head_w);
		}
		else if (*str == '$')
		{
			name = expand_name(str, env); //vrati env -> value
			len = strlen_name(str);
			word_to_lst(name, &head_w);
			free(name);
		}
		str = str + len;
		if (*str == '\n')
			++str;
	}
	return (head_w);
}


char *two_handler(char *str, t_env *env)
{
	t_list *two;
	t_list *start;
	char *s;
	char *copy;
	char *tmp;

	copy = "";
	s = two_trim(str);
	printf ("str v two handler > >%s< <\n", s);
	if (test_names(str, env)!=0)
	{
		printf("test bezi\n");
		free(s);
		return (NULL);
	}
//l	printf("> > > > test v two handler ok\n");
	two = two_lst(s, env); //narvu str do lst	
	start = two;
	while(two != NULL)
	{
		tmp = ft_strjoin (copy, two -> str);
		copy = ft_strdup(tmp);
		free(tmp);
		//free(two -> str);
		two = two -> next;
	}
	free(s);
	free_list(start);
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
			if (!copy)
			{
				printf ("neni copy v two handler\n");
				return(NULL);
			}
			len = strlen_two(str);  //du po " 
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
		//{
		//	free(new_lst);
		//	return(1); 
		// }
		free(lst -> str);
		lst -> str = ft_strdup(new_lst);
		free(new_lst);
		lst = lst -> next;
	}
	return(0);
}




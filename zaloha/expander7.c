

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


t_list *two_lst(char *str,  t_env *env)
{
	int len;
	char *name;
	//t_list *word;
	t_list *head_w;

	head_w = NULL;


	len = 0;
	printf ("two lst jede\n");
	if (*str =='\"')
		++str;
	printf ("ten str:   %s\n", str);
	while (*str && *str != '\0' && *str != '\"')
	{
		printf ("while jede \n");
		if (*str != '$')
		{
			printf ("if jede \n");

			len = strlen_word(str);
			printf("strlen word %d \n", len); 

			printf ("len v two_lst %d\n", len);
			word_to_lst(str, &head_w);
			printf ("word to lst neco dela\n\n");
		}

		else if (*str == '$')
		{
			name = expand_name(str, env); ///narvat do lst
			len = strlen_name(str);
			printf ("strlen name %d\n", len);
			word_to_lst(name, &head_w);
		}
		printf ("tady sem >>>%c<<<<\n", *str);
		str = str + len;
		if (*str == '\n')
			++str;
		printf ("tady sem >>>%c<<<<\n", *str);

	}
	printf ("while dobehlo \n");
	return (head_w);
}


char *two_handler(char *str, t_env *env)
{
	t_list *two;
	char *s;
	char *copy;
	char *tmp;

	copy = "";
	s = two_trim(str);

	printf ("\ns v two handler  > > >%s< < <\n\n", s);

	two = two_lst(str, env); //narvu str do lst
			
	while(two != NULL)
	{
		s = (two -> str);
		tmp = ft_strjoin (copy, s);
		copy = ft_strdup(tmp);
		free(tmp);
		two = two -> next;
	}
	free(s);
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



